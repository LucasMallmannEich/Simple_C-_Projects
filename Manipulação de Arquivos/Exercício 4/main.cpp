/*
Modifique o exercício 3 para gerar um arquivo de relatório.
Seu nome é o nome do arquivo aberto acrescido de _rel, mantendo a extensão ".txt".
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

    // Cria um objeto que lê informações do arquivo de texto.
    ifstream leitura;

    // Pede e captura o nome do arquivo de texto, sem o ".txt".
    string arq;

    cout << "Digite o nome do arquivo de texto, sem o '.txt': ";
    cin >> arq;

    // Cria a variável do nome do arquivo de relatório.
    string arq_rel = arq + "_rel";

    arq = arq + ".txt";
    arq_rel = arq_rel + ".txt";

    // Abre o arquivo de texto no modo de leitura.
    leitura.open(arq, ios::in);

    // Se o arquivo não for encontrado/aberto, o programa informará ao usuário.
    if (! leitura) {
        cerr << "Arquivo " << arq << " nao pode ser aberto." << endl;
        return -1;
     }

    // Declara uma variável do tipo char (caractere).
    char caractere;

    // Declara e inicializa uma variável cuja função é contar o número de espaços.
    int num_espacos = 0;

    // Declara e inicializa uma variável cuja função é contar o número de linhas.
    // Começa com 1, pois estou contando o número de "\n" (não tem na última linha).
    int num_linhas = 1;

    // Declara e inicializa uma variável cuja função é contar o número de vogais.
    int num_vogais = 0;

    // Vetor de caracteres que contém as vogais.
    char vogais[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U',
    'á', 'é', 'í', 'ó', 'ú', 'Á', 'É', 'Í', 'Ó', 'Ú',
    'â', 'ê', 'î', 'ô', 'û', 'Â', 'Ê', 'Î', 'Ô', 'Û',
    'ã', 'õ', 'Ã', 'Õ', 'à', 'À'};

    // Utiliza o método "get" no objeto "leitura".
    // Isso irá captar cada caractere do arquivo até ele se encerrar.
    // Ele irá pegar apenas um caractere por vez, pois o tipo da variável "caractere" é "char".
    while (leitura.get(caractere)) {
        // Se o caractere do arquivo for um espaço (" "), o contador é acrescentado.
        if (caractere == ' ') {
            num_espacos++;
        }
        // Se o caractere for uma quebra de linha, o contador é acrescentado.
        if (caractere == '\n') {
            num_linhas++;
        }
        // Um laço de repetição irá verificar se o caractere é uma vogal (se sim, incrementa o contador).
        for (int i=0; i<sizeof(vogais); i++) {
            if (caractere == vogais[i]) {
                num_vogais++;
            }
        }
    }

    // Fecha o arquivo.
    leitura.close();

    // Abre o arquivo de texto novamente no modo de leitura, pois o cursor chegou ao fim do arquivo anteriormente.
    leitura.open(arq, ios::in);

    // Se o arquivo não for encontrado/aberto, o programa informará ao usuário.
    if (! leitura) {
        cerr << "Arquivo " << arq << " nao pode ser aberto." << endl;
        return -1;
     }

    // Vetor de strings que contém os artigos definidos.
    string artigos_def[] = {"a", "o", "as", "os", "A", "O", "AS", "OS", "As", "Os"};

    // Declaração da variável que irá captar as palavras do arquivo.
    string palavra;

    // Declaração e incialização da variável que armazena o número de artigos definidos no arquivo.
    int num_artigos_def = 0;

    // Laço de repetição que se encerra quando todas as palavras do texto já tiverem sido passadas,
    // uma por vez, para a variável "palavra" (do tipo "string").
    while(leitura >> palavra) {
        for (int i=0; i < (sizeof(artigos_def)/sizeof(string)); i++) {
            // Caso a palavra esteja no vetor dos artigos definidos, o contador é acrescentado.
            if (palavra == artigos_def[i]) {
                num_artigos_def++;
            }
        }
    }

    // Fecha o arquivo.
    leitura.close();

    // Cria um objeto para gravar informações no arquivo de texto.
    ofstream escrita;

    // Abre o novo arquivo de texto gerado com o modo de escrita.
    escrita.open(arq_rel, ios::out);

    // Se o arquivo não for criado ou encontrado, o programa informará ao usuário.
    if (! escrita) {
        cerr << "Arquivo " << arq_rel << " nao pode ser criado." << endl;
        return -1;
     }

    // Grava no arquivo de relatório o número de espaços.
    escrita << "Número de espaços: " << num_espacos << endl;

    // Grava no arquivo de relatório o número de linhas.
    escrita << "Número de linhas: " << num_linhas << endl;

    // Grava no arquivo de relatório o número de vogais.
    escrita << "Número de vogais: " << num_vogais << endl;

    // Grava no arquivo de relatório o número de artigos definidos.
    escrita << "Número de artigos definidos: " << num_artigos_def;

    // Fecha o arquivo.
    escrita.close();

    return 0;
}
