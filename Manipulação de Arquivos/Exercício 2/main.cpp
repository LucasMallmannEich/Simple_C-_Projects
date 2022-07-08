/*
Abra um arquivo no formato txt contendo um texto.
O nome do arquivo � fixo no c�digo.
Analise o conte�do e gere o seguinte relat�rio (na tela):
    - Quantidade de caracteres "espa�o";
    - Quantidade de linhas do texto;
    - Quantidade de vogais;
    - Quantidade de artigos definidos.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <locale>

using namespace std;

int main()
{
    setlocale(LC_ALL,"");

    // Cria um objeto que l� informa��es do arquivo de texto.
    ifstream leitura;

    // Abre o arquivo de texto no modo de leitura.
    leitura.open("bolo_de_banana.txt", ios::in);

    // Se o arquivo n�o for encontrado/aberto, o programa informar� ao usu�rio.
    if (! leitura) {
        cerr << "Arquivo bolo_de_banana.txt nao pode ser aberto." << endl;
        return -1;
     }

    // Declara uma vari�vel do tipo char (caractere).
    char caractere;

    // Declara e inicializa uma vari�vel cuja fun��o � contar o n�mero de espa�os.
    int num_espacos = 0;

    // Declara e inicializa uma vari�vel cuja fun��o � contar o n�mero de linhas.
    // Come�a com 1, pois estou contando o n�mero de "\n" (n�o tem na �ltima linha).
    int num_linhas = 1;

    // Declara e inicializa uma vari�vel cuja fun��o � contar o n�mero de vogais.
    int num_vogais = 0;

    // Vetor de caracteres que cont�m as vogais.
    char vogais[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U',
    '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
    '�', '�', '�', '�', '�', '�', '�', '�', '�', '�',
    '�', '�', '�', '�', '�', '�'};

    // Utiliza o m�todo "get" no objeto "leitura".
    // Isso ir� captar cada caractere do arquivo at� ele se encerrar.
    // Ele ir� pegar apenas um caractere por vez, pois o tipo da vari�vel "caractere" � "char".
    while (leitura.get(caractere)) {
        // Se o caractere do arquivo for um espa�o (" "), o contador � acrescentado.
        if (caractere == ' ') {
            num_espacos++;
        }
        // Se o caractere for uma quebra de linha, o contador � acrescentado.
        if (caractere == '\n') {
            num_linhas++;
        }
        // Um la�o de repeti��o ir� verificar se o caractere � uma vogal (se sim, incrementa o contador).
        for (int i=0; i<sizeof(vogais); i++) {
            if (caractere == vogais[i]) {
                num_vogais++;
            }
        }
    }

    // Imprime o n�mero de espa�os.
    cout << "N�mero de espa�os: " << num_espacos << endl;

    // Imprime o n�mero de linhas.
    cout << "N�mero de linhas: " << num_linhas << endl;

    // Imprime o n�mero de vogais.
    cout << "N�mero de vogais: " << num_vogais << endl;

    // Fecha o arquivo.
    leitura.close();

    // Abre o arquivo de texto novamente no modo de leitura, pois o cursor chegou ao fim do arquivo anteriormente.
    leitura.open("bolo_de_banana.txt", ios::in);

    // Se o arquivo n�o for encontrado/aberto, o programa informar� ao usu�rio.
    if (! leitura) {
        cerr << "Arquivo bolo_de_banana.txt nao pode ser aberto." << endl;
        return -1;
     }

    // Vetor de strings que cont�m os artigos definidos.
    string artigos_def[] = {"a", "o", "as", "os", "A", "O", "AS", "OS", "As", "Os"};

    // Declara��o da vari�vel que ir� captar as palavras do arquivo.
    string palavra;

    // Declara��o e incializa��o da vari�vel que armazena o n�mero de artigos definidos no arquivo.
    int num_artigos_def = 0;

    // La�o de repeti��o que se encerra quando todas as palavras do texto j� tiverem sido passadas,
    // uma por vez, para a vari�vel "palavra" (do tipo "string").
    while(leitura >> palavra) {
        for (int i=0; i < (sizeof(artigos_def)/sizeof(string)); i++) {
            // Caso a palavra esteja no vetor dos artigos definidos, o contador � acrescentado.
            if (palavra == artigos_def[i]) {
                num_artigos_def++;
            }
        }
    }

    // Imprime o n�mero de artigos definidos.
    cout << "Numero de artigos definidos: " << num_artigos_def;

    leitura.close();

    return 0;
}
