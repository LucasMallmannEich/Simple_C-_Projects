/*
Elabore um programa que � capaz de analisar um arquivo texto.
Ele deve apresentar um histograma de palavras presentes neste arquivo.
Em outras palavras, a an�lise consiste em contar a quantidade de ocorr�ncias de cada palavra no texto.
O relat�rio � apresentado como outro arquivo texto (".txt").
*/

#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>

using namespace std;

// Prototipagem da fun��o que coloca a palavra em letras min�sculas.
void minimizar_string(int num_caract, string &str);

// Prototipagem da fun��o que "exclui" a pontua��o ap�s a palavra.
void excluir_pontuacao(int num_carac, string &strg);

// Prototipagem da fun��o que contabiliza o n�mero de acentos em determinada palavra.
int numero_acentos(string &palavra, int tam);

int main()
{
    setlocale(LC_ALL,"");

    // Declara��o da vari�vel "arq", que armazena o nome do arquivo de texto.
    string arq;

    // Capta��o, por meio de inser��o do usu�rio, do nome do arquivo de texto.
    cout << "Digite o nome do arquivo de texto, sem o '.txt': ";
    cin >> arq;

    // Declara o nome do arquivo de "relatorio".
    string relatorio = arq + "_relatorio";

    // Acrescenta a extens�o ".txt".
    arq = arq + ".txt";
    relatorio = relatorio + ".txt";

    // Cria��o do objeto que l� as informa��es do arquivo de texto.
    ifstream leitura;

    // Abre o arquivo de texto informado no modo de leitura.
    leitura.open(arq, ios::in);

    // Verifica se o arquivo foi aberto ou encontrado.
    if (! leitura) {
        cerr << "Arquivo " << arq << " n�o pode ser aberto.";
        return -1;
    }

    // Declara��o da vari�vel que ir� receber cada palavra do arquivo.
    string palavra;

    // Declara��o e inicializa��o da vari�vel que ir� contabilizar o n�mero de palavras no arquivo.
    int num_palavras = 0;

    // Contabiliza o n�mero de palavras dentro do arquivo.
    while (leitura >> palavra) {
        num_palavras++;
    }

    // Fecha o arquivo.
    leitura.close();

    // Abre o arquivo de texto informado no modo de leitura.
    leitura.open(arq, ios::in);

    // Verifica se o arquivo foi aberto ou encontrado.
    if (! leitura) {
        cerr << "Arquivo " << arq << " n�o pode ser aberto.";
        return -1;
    }

    // Declara��o do ponteiro que ir� armazenar todas as palavras do arquivo.
    string *palavras;

    // Aloca��o de mem�ria din�mica.
    palavras = new string[num_palavras];

    // Caso n�o haja mem�ria dispon�vel para a aloca��o, o programa ser� encerrado.
    if(palavras == nullptr) {
        cerr << "N�o h� espa�o na mem�ria para realizar a aloca��o din�mica." << endl;
        return -2;
    }

    // Declara��o do ponteiro que ir� armazenar as quantidades de vezes que cada palavra aparece.
    int *quantidades;

    // Aloca��o de mem�ria din�mica.
    quantidades = new int [num_palavras];

    // Caso n�o haja mem�ria dispon�vel para a aloca��o, o programa ser� encerrado.
    if(quantidades == nullptr) {
        cerr << "N�o h� espa�o na mem�ria para realizar a aloca��o din�mica." << endl;
        return -2;
    }

    // Inicializa��o de todos os elementos do vetor com 1 (pois aparecem ao menos uma vez).
    for (int i=0; i<num_palavras; i++) {
        quantidades[i] = 1;
    }

    int cont = 0;

    // Vetor de strings que armazena os elementos que n�o ser�o considerados uma palavra.
    string inadequacoes[] = {"?", ",", ".", ";", "!", "...",
    "-", ":", "=", "+", "/", "^", "*", "@", "#", "(", ")", " ",
    "&", "&&", "|", "||", "%", "_", "$", "\'", "\"", "<", ">", "\\"};

    // A vari�vel "adequado" ir� dizer se determinado elemento � considerado uma palavra.
    bool adequado = true;

    // Declara��o e inicializa��o da vari�vel que contabiliza o n�mero de caracteres de cada palavra.
    int num_caracteres = 0;

    // La�o de repeti��o utilizado para extrair cada palavra presente no arquivo.
    while (leitura >> palavra) {
        num_caracteres =  palavra.length();  // coloca o tamanho da palavra em "num_caracteres";
        minimizar_string(num_caracteres, palavra);  // coloca a palavra em letras min�sculas;
        excluir_pontuacao(num_caracteres, palavra);  // retira a pontua��o ao final das palavras;
        for (int i=0; i < (sizeof(inadequacoes)/sizeof(string)); i++) {
            if (palavra == inadequacoes[i]) {  // verifica se a palavra est� no vetor "inadequacoes";
                adequado = false;  // se est�, n�o � uma palavra;
            }
        }
        if (adequado == true) {  // se for palavra, a coloca no vetor "palavras" e incrementa "cont";
            palavras[cont] = palavra;
            cont++;
        }
        else {  // se n�o for palavra, decrementa a vari�vel que contabiliza o n�mero de palavras;
            num_palavras --;
        }
        adequado = true;  // "adequado" torna-se true, para reiniciar a verifica��o com outra palavra;
    }

    // La�o de repeti��o que verifica o n�mero de ocorr�ncias de determinada palavra no vetor.
    for (int i=0; i<num_palavras; i++) {
        for (int j=0; j<num_palavras; j++){
            // Se a palavra for igual � outra palavra, incrementa o vetor "quantidades" na mesma
            // posi��o de �ndice em que a primeira palavra repetida se encontra no vetor de palavras.
            if ((j != i) && (palavras[i] == palavras[j]) && (palavras[i] != "w")) {
                quantidades[i]++;
                 // Coloca "w" na posi��o da palavra repetida,para n�o contabilizar novamente
                 // quando o "i" chegar no valor de sua posi��o.
                palavras[j] = "w";
            }
        }
    }

    // Fecha o arquivo.
    leitura.close();

    // Cria��o de um objeto que grava no arquivo de texto.
    ofstream escrita;

    // Abertura do arquivo no modo de escrita.
    escrita.open(relatorio, ios::out);

    // Se o arquivo n�o conseguir ter sido criado ou aberto, o programa se encerra.
    if (! escrita) {
        cerr << "Arquivo " << relatorio << " n�o pode ser aberto ou criado.";
        return -1;
    }

    int n_acentos;

    // La�o de repeti��o que escreve no arquivo o n�mero de ocorr�ncias de cada palavra.
    for (int i=0; i<num_palavras; i++) {
        num_caracteres = palavras[i].length();  // tamanho da palavra (em letras);
        n_acentos = numero_acentos(palavras[i], num_caracteres);  // descobre o n�mero de acentos;
        // As condi��es abaixo servem apenas para a decora��o do arquivo.
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

    // Libera a mem�ria previamente alocada para "palavras" e para "quantidades".
    delete(palavras);
    delete(quantidades);

    return 0;
}

void minimizar_string(int num_caract, string &str) {
    char acentos[] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
     '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�'};

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
