Leitura de Arquivo de Texto (.txt)

Proposta:
 - Abra um arquivo no formato txt contendo um texto.
 - O nome do arquivo é fixo no código.
 - Analise o conteúdo e gere o seguinte relatório (na tela):
    - Quantidade de caracteres "espaço";
    - Quantidade de linhas do texto;
    - Quantidade de vogais;
    - Quantidade de artigos definidos.

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

void minimizar_string(int num_caract, string &str);
void excluir_pontuacao(int num_carac, string &strg);

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

    string palavra;
    int num_palavras = 0;

    while (leitura >> palavra) {
        num_palavras++;
    }

    leitura.close();

    // Abre o arquivo de texto informado no modo de leitura.
    leitura.open(arq, ios::in);

    // Verifica se o arquivo foi aberto ou encontrado.
    if (! leitura) {
        cerr << "Arquivo " << arq << " não pode ser aberto.";
        return -1;
    }

    string *palavras;
    palavras = new string[num_palavras];

    if(palavras == nullptr) {
        cerr << "Não há espaço na memória para realizar a alocação dinâmica." << endl;
        return -2;
    }

    int *quantidades;
    quantidades = new int [num_palavras];

    if(quantidades == nullptr) {
        cerr << "Não há espaço na memória para realizar a alocação dinâmica." << endl;
        return -2;
    }

    for (int i=0; i<num_palavras; i++) {
        quantidades[i] = 1;
    }

    int cont = 0;

    string inadequacoes[] = {"?", ",", ".", ";", "!", "...",
    "-", ":", "=", "+", "/", "^", "*", "@", "#", "(", ")", " ",
    "&", "&&", "|", "||", "%", "_", "$", "\'", "\"", "<", ">", "\\"};

    bool adequado = true;

    int num_caracteres = 0;

    while (leitura >> palavra) {
        num_caracteres =  palavra.length();
        minimizar_string(num_caracteres, palavra);
        excluir_pontuacao(num_caracteres, palavra);
        for (int i=0; i < (sizeof(inadequacoes)/sizeof(string)); i++) {
            if (palavra == inadequacoes[i]) {
                adequado = false;
            }
        }
        if (adequado == true) {
            palavras[cont] = palavra;
            cont++;
        }
        else {
            num_palavras --;
        }
        adequado = true;
    }

    for (int i=0; i<num_palavras; i++) {
        for (int j=0; j<num_palavras; j++){
            if ((j != i) && (palavras[i] == palavras[j]) && (palavras[i] != "w")) {
                quantidades[i]++;
                palavras[j] = "w";
            }
        }
    }

    leitura.close();

    ofstream escrita;

    escrita.open(relatorio, ios::out);

    if (! escrita) {
        cerr << "Arquivo " << relatorio << " não pode ser aberto ou criado.";
        return -1;
    }

    for (int i=0; i<num_palavras; i++) {
        if(palavras[i] != "w") {
            escrita << palavras[i] << ":    " << quantidades[i] << endl;
        }
    }

    escrita.close();

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
