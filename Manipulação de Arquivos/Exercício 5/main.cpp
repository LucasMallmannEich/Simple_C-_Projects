/*
Elabore um programa que é capaz de analisar um arquivo texto.
Ele deve apresentar um histograma de palavras presentes neste arquivo.
Em outras palavras, a análise consiste em contar a quantidade de ocorrências de cada palavra no texto.
O relatório é apresentado como outro arquivo texto (".txt").
*/

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>

using namespace std;

// Prototipagem da função que coloca a palavra em letras minúsculas.
void minimizar_string(int num_caract, string &str);

// Prototipagem da função que "exclui" a pontuação após a palavra.
void excluir_pontuacao(int num_carac, string &strg);

// Prototipagem da função que contabiliza o número de acentos em determinada palavra.
int numero_acentos(string &palavra, int tam);

int main()
{
    setlocale(LC_ALL,"");

    // Declaração da variável "arq", que armazena o nome do arquivo de texto.
    string arq;

    // Captação, por meio de inserção do usuário, do nome do arquivo de texto.
    cout << "Digite o nome do arquivo de texto, sem o '.txt': ";
    cin >> arq;

    // Declara o nome do arquivo de "relatorio".
    string relatorio = arq + "_relatorio";

    // Acrescenta a extensão ".txt".
    arq = arq + ".txt";
    relatorio = relatorio + ".txt";

    // Criação do objeto que lê as informações do arquivo de texto.
    ifstream leitura;

    // Abre o arquivo de texto informado no modo de leitura.
    leitura.open(arq, ios::in);

    // Verifica se o arquivo foi aberto ou encontrado.
    if (! leitura) {
        cerr << "Arquivo " << arq << " não pode ser aberto.";
        return -1;
    }

    // Declaração da variável que irá receber cada palavra do arquivo.
    string palavra;

    // Declaração e inicialização da variável que irá contabilizar o número de palavras no arquivo.
    int num_palavras = 0;

    // Contabiliza o número de palavras dentro do arquivo.
    while (leitura >> palavra) {
        num_palavras++;
    }

    // Fecha o arquivo.
    leitura.close();

    // Abre o arquivo de texto informado no modo de leitura.
    leitura.open(arq, ios::in);

    // Verifica se o arquivo foi aberto ou encontrado.
    if (! leitura) {
        cerr << "Arquivo " << arq << " não pode ser aberto.";
        return -1;
    }

    // Declaração do ponteiro que irá armazenar todas as palavras do arquivo.
    string *palavras;

    // Alocação de memória dinâmica.
    palavras = new string[num_palavras];

    // Caso não haja memória disponível para a alocação, o programa será encerrado.
    if(palavras == nullptr) {
        cerr << "Não há espaço na memória para realizar a alocação dinâmica." << endl;
        return -2;
    }

    // Declaração do ponteiro que irá armazenar as quantidades de vezes que cada palavra aparece.
    int *quantidades;

    // Alocação de memória dinâmica.
    quantidades = new int [num_palavras];

    // Caso não haja memória disponível para a alocação, o programa será encerrado.
    if(quantidades == nullptr) {
        cerr << "Não há espaço na memória para realizar a alocação dinâmica." << endl;
        return -2;
    }

    // Inicialização de todos os elementos do vetor com 1 (pois aparecem ao menos uma vez).
    for (int i=0; i<num_palavras; i++) {
        quantidades[i] = 1;
    }

    int cont = 0;

    // Vetor de strings que armazena os elementos que não serão considerados uma palavra.
    string inadequacoes[] = {"?", ",", ".", ";", "!", "...",
    "-", ":", "=", "+", "/", "^", "*", "@", "#", "(", ")", " ",
    "&", "&&", "|", "||", "%", "_", "$", "\'", "\"", "<", ">", "\\"};

    // A variável "adequado" irá dizer se determinado elemento é considerado uma palavra.
    bool adequado = true;

    // Declaração e inicialização da variável que contabiliza o número de caracteres de cada palavra.
    int num_caracteres = 0;

    // Laço de repetição utilizado para extrair cada palavra presente no arquivo.
    while (leitura >> palavra) {
        num_caracteres =  palavra.length();  // coloca o tamanho da palavra em "num_caracteres";
        minimizar_string(num_caracteres, palavra);  // coloca a palavra em letras minúsculas;
        excluir_pontuacao(num_caracteres, palavra);  // retira a pontuação ao final das palavras;
        for (int i=0; i < (sizeof(inadequacoes)/sizeof(string)); i++) {
            if (palavra == inadequacoes[i]) {  // verifica se a palavra está no vetor "inadequacoes";
                adequado = false;  // se está, não é uma palavra;
            }
        }
        if (adequado == true) {  // se for palavra, a coloca no vetor "palavras" e incrementa "cont";
            palavras[cont] = palavra;
            cont++;
        }
        else {  // se não for palavra, decrementa a variável que contabiliza o número de palavras;
            num_palavras --;
        }
        adequado = true;  // "adequado" torna-se true, para reiniciar a verificação com outra palavra;
    }

    // Laço de repetição que verifica o número de ocorrências de determinada palavra no vetor.
    for (int i=0; i<num_palavras; i++) {
        for (int j=0; j<num_palavras; j++){
            // Se a palavra for igual à outra palavra, incrementa o vetor "quantidades" na mesma
            // posição de índice em que a primeira palavra repetida se encontra no vetor de palavras.
            if ((j != i) && (palavras[i] == palavras[j]) && (palavras[i] != "w")) {
                quantidades[i]++;
                 // Coloca "w" na posição da palavra repetida,para não contabilizar novamente
                 // quando o "i" chegar no valor de sua posição.
                palavras[j] = "w";
            }
        }
    }

    // Fecha o arquivo.
    leitura.close();

    // Criação de um objeto que grava no arquivo de texto.
    ofstream escrita;

    // Abertura do arquivo no modo de escrita.
    escrita.open(relatorio, ios::out);

    // Se o arquivo não conseguir ter sido criado ou aberto, o programa se encerra.
    if (! escrita) {
        cerr << "Arquivo " << relatorio << " não pode ser aberto ou criado.";
        return -1;
    }

    int n_acentos;

    // Laço de repetição que escreve no arquivo o número de ocorrências de cada palavra.
    for (int i=0; i<num_palavras; i++) {
        num_caracteres = palavras[i].length();  // tamanho da palavra (em letras);
        n_acentos = numero_acentos(palavras[i], num_caracteres);  // descobre o número de acentos;
        // As condições abaixo servem apenas para a decoração do arquivo.
        if(n_acentos > 0) {
            n_acentos--;
        }
        if(palavras[i] != "w") {
            escrita << palavras[i];
            for(int i=0; i<(40-num_caracteres+n_acentos); i++) {
                escrita << " ";
            }
            escrita << quantidades[i] << endl;
        }
    }

    // Fecha o arquivo.
    escrita.close();

    // Libera a memória previamente alocada para "palavras" e para "quantidades".
    delete(palavras);
    delete(quantidades);

    return 0;
}

void minimizar_string(int num_caract, string &str) {
    char acentos[] = { 'á', 'é', 'í', 'ó', 'ú', 'Á', 'É', 'Í', 'Ó', 'Ú',
     'â', 'ê', 'î', 'ô', 'û', 'Â', 'Ê', 'Î', 'Ô', 'Û', 'ã', 'õ', 'Ã', 'Õ', 'à', 'À'};

    bool minimizar = true;

    for(int i=0; i<num_caract; i++) {
        for(int j=0; j<sizeof(acentos); j++) {
            if(str[i] == acentos[j]) {
                minimizar = false;
            }
        }
        if (minimizar == true) {
            str[i] = tolower(str[i]);
        }
        else {
            minimizar = true;
        }
    }
}

void excluir_pontuacao(int num_carac, string &strg) {
    char pontuacoes[] = {'?', ',', '.', ':', '!', ';'};

    for (int i=0; i<sizeof(pontuacoes); i++) {
        if (strg[(num_carac-1)] == pontuacoes[i]) {
            strg[(num_carac-1)] = ' ';
        }
    }
}

int numero_acentos(string &palavra, int tam) {
    char sem_acentos[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
    'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-', ' '};

    int num_acentos = tam;

    for (int x=0; x < tam; x++) {
        for (int y=0; y < sizeof(sem_acentos); y++) {
            if (palavra[x] == sem_acentos[y]) {
                num_acentos--;
            }
        }
    }
    return num_acentos;
}
