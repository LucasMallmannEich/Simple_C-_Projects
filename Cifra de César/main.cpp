#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

// Declara��o dos prot�tipos da fun��es.
void decodificador (string &msg, int chave);
int descobrir_chave (string msg);
float razao_vogais_string (string msg);

int main()
{
    // Cria��o do objeto que ir� ler o conte�do do arquivo.
    ifstream leitura;

    // Declara��o da vari�vel que armazena o nome do arquivo.
    string nome_arquivo;

    // Inser��o do nome do arquivo pelo usu�rio.
    cout << "Digite o nome do arquivo, sem o '.txt': " << endl;
    cin >> nome_arquivo;

    // T�tulo do arquivo que ser� gerado ap�s a decodifica��o.
    string nome_arquivo_dec = nome_arquivo + "_dec.txt";

    // Incremento da extens�o ".txt" ao final do nome do arquivo.
    nome_arquivo = nome_arquivo + ".txt";

    // Tentativa de abertura do arquivo informado no modo de leitura.
    leitura.open(nome_arquivo, ios::in);

    // Encerra o programa caso o arquivo informado n�o fora encontrado.
    if (! leitura) {
        cerr << "Arquivo nao foi encontrado.";
        return -1;
    }

    // Declara uma vari�vel do tipo "string" que recebe o conte�do do arquivo.
    string mensagem;
    leitura >> mensagem;

    // Fecha o arquivo ap�s j� termos extra�dos suas informa��es.
    leitura.close();

    // Pergunta ao usu�rio se ele ir� ou n�o informar a chave decodificadora.
    string resposta;
    cout << "Digite se voce deseja informar a chave decodificadora: " << endl;
    cout << "Digite 'sim' ou 'nao': ";
    cin >> resposta;

    // La�o de repeti��o que garante que a resposta seja "sim" ou "nao".
    while (resposta != "sim" && resposta != "nao") {
        cout << "Voce deve digitar 'sim' ou 'nao': ";
        cin >> resposta;
    }

    // Declara��o da vari�vel que armazena o valor da chave decodificadora.
    int chave;

    // Caso o usu�rio saiba a chave decodificadora.
    if (resposta == "sim") {
        // Pede ao usu�rio digitar a chave (tendo que ser maior do que zero).
        cout << "Digite o numero da chave decodificadora: ";
        cin >> chave;
        while (chave < 0) {
            cout << "Voce deve digitar um numero positivo ou zero." << endl;
            cout << "Tente novamente: ";
            cin >> chave;
        }
        // A fun��o abaixo decodifica a mensagem de acordo com a chave informada.
        decodificador(mensagem, chave);
    }
    // Caso o usu�rio n�o saiba a chave decodificadora.
    else if (resposta == "nao") {
        // A fun��o abaixo retorna a chave decodificadora.
        chave = descobrir_chave(mensagem);
        // A fun��o abaixo decodifica a mensagem de acordo com a chave descoberta.
        decodificador(mensagem, chave);
    }

    // Cria��o do objeto que ir� escrever no arquivo.
    ofstream escrita;

    // Tentativa de abertura do arquivo informado no modo de escrita.
    escrita.open(nome_arquivo_dec, ios::out);

    // Encerra o programa caso houve erro na abertura do arquivo.
    if (! leitura) {
        cerr << "Arquivo nao foi encontrado.";
        return -1;
    }

    // Escreve no arquivo a mensagem decodificada.
    escrita << mensagem;

    // Fecha o arquivo ap�s j� termos o utilizado.
    escrita.close();

    return 0;
}

// Fun��o que decodifica a mensagem de acordo com a chave informada.
void decodificador (string &msg, int chave) {
    // Declara��o da vari�vel que armazena o n�mero correspondente a cada caractere.
    int num;

    // Caso a chave informada seja maior do que 25.
    chave = chave % 26;

    // La�o de repeti��o que decodifica a mensagem utilizando a tabela ASCII.
    for (int i=0; i < msg.length(); i++) {
        // Transforma��o do caractere em um n�mero (de acordo com a tabela ASCII).
        num = int(msg[i]);
        // Subtra��o desse n�mero pelo valor da chave.
        num = num - chave;
        // Caso o n�mero tenha se tornado menor do que 65 (caractere "A"), somamos 26
        // a ele, com o intuito de "voltar" a contagem ao caractere "Z" (no m�ximo).
        if (num < 65) {
            num = num + 26;
        }
        // Transforma esse n�mero em seu respectivo caractere da tabela e substitui
        // o antigo caractere daquela mensagem pelo novo.
        msg[i] = char(num);
    }
}

// Fun��o que retorna o valor da chave decodificadora apenas sabendo a mensagem.
int descobrir_chave (string msg) {
    string msg_aux = msg;  // vari�vel auxiliar que � id�ntica � mensagem recebida;
    float razao;  // armazena a raz�o entre o n�mero de vogais e o de caracteres;
    int num;  // armazena o n�mero correspondente a cada caractere da string

    // Declara��o do vetor que armazena a diferen�a entre a vari�vel "razao" e o valor
    // 0.488 (que �, segundo estudos da l�ngua portuguesa, a m�dia de vogais a cada
    // letra, ou seja, a cada 10 letras, em m�dia, 4,88 letras s�o vogais.)
    float diferencas_entre_porcentagens[26];

    // La�o de repeti��o que verifica cada possibilidade de valor de chave at� o 25.
    for (int key=0; key < 26; key++) {
        // La�o de repeti��o que decodifica a mensagem com cada chave.
        for (int i=0; i < msg.length(); i++) {
            num = int(msg[i]);
            num = num - key;
            if (num < 65) {
                num = num + 26;
            }
            msg_aux[i] = char(num);
        }
        // Armazena a raz�o entre as vogais e os caracteres para cada mensagem.
        razao = razao_vogais_string(msg_aux);

        // Acrescenta no vetor a dist�ncia que essa raz�o est� do valor 0.488.
        if (razao < 0.488) {
            float diferenca = 0.488 - razao;
            diferencas_entre_porcentagens[key] = diferenca;
        }
        else {
            float diferenca = razao - 0.488;
            diferencas_entre_porcentagens[key] = diferenca;
        }
    }

    // Declara a vari�vel que armazena a menor dist�ncia para o valor 0.488.
    float menor = diferencas_entre_porcentagens[0];
    int chave = 0;  // declara e inicializa a chave a ser retornada;

    // La�o de repeti��o utilizado para descobrir a menor diferen�a para o 0.488.
    for (int j=0; j < 26; j++) {
        if (diferencas_entre_porcentagens[j] < menor) {
            menor = diferencas_entre_porcentagens[j];
            chave = j;  // atualiza a chave de acordo com a posi��o da menor diferen�a;
        }
    }

    return chave;
}

// Fun��o que descobre a raz�o entre o n�mero de vogais e de caracteres de uma string.
float razao_vogais_string (string msg) {
    float cont_vogais=0;  // armazena o n�mero de vogais numa string;
    float total=msg.length();  // armazena o n�mero de caracteres numa string;
    float razao;  // armazena a divis�o entre o n�mero de vogais e o de caracteres;

    // La�o de repeti��o que contabiliza o n�mero de vogais de uma string.
    for (int i=0; i < total; i++) {
        if (msg[i] == 'A' || msg[i] == 'E' || msg[i] == 'I' ||
            msg[i] == 'O' || msg[i] == 'U') {
                cont_vogais = cont_vogais + 1;
            }
    }

    // Calcula e retorna a raz�o entre o n�mero de vogais e de caracteres da string.
    razao = cont_vogais/total;

    return razao;
}
