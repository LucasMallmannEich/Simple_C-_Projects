#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

using namespace std;

// Declaração dos protótipos da funções.
void decodificador (string &msg, int chave);
int descobrir_chave (string msg);
float razao_vogais_string (string msg);

int main()
{
    // Criação do objeto que irá ler o conteúdo do arquivo.
    ifstream leitura;

    // Declaração da variável que armazena o nome do arquivo.
    string nome_arquivo;

    // Inserção do nome do arquivo pelo usuário.
    cout << "Digite o nome do arquivo, sem o '.txt': " << endl;
    cin >> nome_arquivo;

    // Título do arquivo que será gerado após a decodificação.
    string nome_arquivo_dec = nome_arquivo + "_dec.txt";

    // Incremento da extensão ".txt" ao final do nome do arquivo.
    nome_arquivo = nome_arquivo + ".txt";

    // Tentativa de abertura do arquivo informado no modo de leitura.
    leitura.open(nome_arquivo, ios::in);

    // Encerra o programa caso o arquivo informado não fora encontrado.
    if (! leitura) {
        cerr << "Arquivo nao foi encontrado.";
        return -1;
    }

    // Declara uma variável do tipo "string" que recebe o conteúdo do arquivo.
    string mensagem;
    leitura >> mensagem;

    // Fecha o arquivo após já termos extraídos suas informações.
    leitura.close();

    // Pergunta ao usuário se ele irá ou não informar a chave decodificadora.
    string resposta;
    cout << "Digite se voce deseja informar a chave decodificadora: " << endl;
    cout << "Digite 'sim' ou 'nao': ";
    cin >> resposta;

    // Laço de repetição que garante que a resposta seja "sim" ou "nao".
    while (resposta != "sim" && resposta != "nao") {
        cout << "Voce deve digitar 'sim' ou 'nao': ";
        cin >> resposta;
    }

    // Declaração da variável que armazena o valor da chave decodificadora.
    int chave;

    // Caso o usuário saiba a chave decodificadora.
    if (resposta == "sim") {
        // Pede ao usuário digitar a chave (tendo que ser maior do que zero).
        cout << "Digite o numero da chave decodificadora: ";
        cin >> chave;
        while (chave < 0) {
            cout << "Voce deve digitar um numero positivo ou zero." << endl;
            cout << "Tente novamente: ";
            cin >> chave;
        }
        // A função abaixo decodifica a mensagem de acordo com a chave informada.
        decodificador(mensagem, chave);
    }
    // Caso o usuário não saiba a chave decodificadora.
    else if (resposta == "nao") {
        // A função abaixo retorna a chave decodificadora.
        chave = descobrir_chave(mensagem);
        // A função abaixo decodifica a mensagem de acordo com a chave descoberta.
        decodificador(mensagem, chave);
    }

    // Criação do objeto que irá escrever no arquivo.
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

    // Fecha o arquivo após já termos o utilizado.
    escrita.close();

    return 0;
}

// Função que decodifica a mensagem de acordo com a chave informada.
void decodificador (string &msg, int chave) {
    // Declaração da variável que armazena o número correspondente a cada caractere.
    int num;

    // Caso a chave informada seja maior do que 25.
    chave = chave % 26;

    // Laço de repetição que decodifica a mensagem utilizando a tabela ASCII.
    for (int i=0; i < msg.length(); i++) {
        // Transformação do caractere em um número (de acordo com a tabela ASCII).
        num = int(msg[i]);
        // Subtração desse número pelo valor da chave.
        num = num - chave;
        // Caso o número tenha se tornado menor do que 65 (caractere "A"), somamos 26
        // a ele, com o intuito de "voltar" a contagem ao caractere "Z" (no máximo).
        if (num < 65) {
            num = num + 26;
        }
        // Transforma esse número em seu respectivo caractere da tabela e substitui
        // o antigo caractere daquela mensagem pelo novo.
        msg[i] = char(num);
    }
}

// Função que retorna o valor da chave decodificadora apenas sabendo a mensagem.
int descobrir_chave (string msg) {
    string msg_aux = msg;  // variável auxiliar que é idêntica à mensagem recebida;
    float razao;  // armazena a razão entre o número de vogais e o de caracteres;
    int num;  // armazena o número correspondente a cada caractere da string

    // Declaração do vetor que armazena a diferença entre a variável "razao" e o valor
    // 0.488 (que é, segundo estudos da língua portuguesa, a média de vogais a cada
    // letra, ou seja, a cada 10 letras, em média, 4,88 letras são vogais.)
    float diferencas_entre_porcentagens[26];

    // Laço de repetição que verifica cada possibilidade de valor de chave até o 25.
    for (int key=0; key < 26; key++) {
        // Laço de repetição que decodifica a mensagem com cada chave.
        for (int i=0; i < msg.length(); i++) {
            num = int(msg[i]);
            num = num - key;
            if (num < 65) {
                num = num + 26;
            }
            msg_aux[i] = char(num);
        }
        // Armazena a razão entre as vogais e os caracteres para cada mensagem.
        razao = razao_vogais_string(msg_aux);

        // Acrescenta no vetor a distância que essa razão está do valor 0.488.
        if (razao < 0.488) {
            float diferenca = 0.488 - razao;
            diferencas_entre_porcentagens[key] = diferenca;
        }
        else {
            float diferenca = razao - 0.488;
            diferencas_entre_porcentagens[key] = diferenca;
        }
    }

    // Declara a variável que armazena a menor distância para o valor 0.488.
    float menor = diferencas_entre_porcentagens[0];
    int chave = 0;  // declara e inicializa a chave a ser retornada;

    // Laço de repetição utilizado para descobrir a menor diferença para o 0.488.
    for (int j=0; j < 26; j++) {
        if (diferencas_entre_porcentagens[j] < menor) {
            menor = diferencas_entre_porcentagens[j];
            chave = j;  // atualiza a chave de acordo com a posição da menor diferença;
        }
    }

    return chave;
}

// Função que descobre a razão entre o número de vogais e de caracteres de uma string.
float razao_vogais_string (string msg) {
    float cont_vogais=0;  // armazena o número de vogais numa string;
    float total=msg.length();  // armazena o número de caracteres numa string;
    float razao;  // armazena a divisão entre o número de vogais e o de caracteres;

    // Laço de repetição que contabiliza o número de vogais de uma string.
    for (int i=0; i < total; i++) {
        if (msg[i] == 'A' || msg[i] == 'E' || msg[i] == 'I' ||
            msg[i] == 'O' || msg[i] == 'U') {
                cont_vogais = cont_vogais + 1;
            }
    }

    // Calcula e retorna a razão entre o número de vogais e de caracteres da string.
    razao = cont_vogais/total;

    return razao;
}
