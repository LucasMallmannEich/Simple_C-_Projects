/* DESAFIO:
Uma pesquisa visa levantar a quantidade de televisores presentes nos lares.
Para tanto, são realizadas consultas a pessoas em locais públicos.
Para auxiliar esta pesquisa, elabore um programa para gerar o relatório diário de cada pesquisador.
O programa consiste das seguintes tarefas:
- Identificação do número de questionários respondidos no dia.
- Registro individual do número de televisores de cada questionario
(em um vetor do exato tamanho da quantidade de questionários respondidos).
- Gere um relatorio (no console), informando:
    + A quantidade de respostas do dia;
    + A quantidade de residências sem televisor;
    + A média de televisores/residenciais, desconsiderando as residencias sem televisor.
*/

#include <iostream>

using namespace std;

enum Continuar {NAO=0, SIM};

int main()
{
    int resposta = SIM;
    int *num_televisores;
    int num_questionarios = 0;
    int televisores;

    // Captação dos dados dos questionários.
    while (resposta == SIM) {

        // Captar o número de televisores em uma casa.
        do {
            cout << endl << "Digite o numero de televisores do entrevistado " << num_questionarios+1 << ": ";
            cin >> televisores;
            if (televisores < 0) {
                cout << " NAO eh possivel digitar numeros negativos." << endl;
            }
        } while (televisores < 0);

        // Alocação de memória para o vetor.

        // Vetor auxiliar para guardar os resultados.
        int vet[num_questionarios+1];

        // Passa para o vetor auxiliar os valores de "num_televisores".
        for(int i=0; i!=num_questionarios; i++) {
            vet[i] = num_televisores[i];
        }

        // Aloca um novo espaço de memória para o vetor "num_televisores", fazendo com
        // que todos os antigos valores dele sejam "perdidos".
        num_televisores = new int[num_questionarios+1];

        // Adiciona um novo valor na nova posição.
        num_televisores[num_questionarios] = televisores;

        // Passa para o vetor "num_televisores" os seus valores antigos que estavam armazenados
        // no vetor auxiliar.
        for(int i=0; i!=num_questionarios; i++) {
            num_televisores[i] = vet[i];
        }

        // Perguntar ao usuário se ele deseja continuar coletando respostas.
        do{
            cout << "Tu desejas continuar captando respostas (0 para nao e 1 para sim)? ";
            cin >> resposta;
            if (resposta != SIM && resposta != NAO) {
                cout << "Tu deve digitar 0 ou 1." << endl;
            }
        } while (resposta != SIM && resposta != NAO);

        // Incremento do número de questionários realizados.
        num_questionarios = num_questionarios + 1;
    }

    for (int i=0; i!=num_questionarios; i++) {
        cout << "    " << num_televisores[i];
    }

    // Descobrindo o numero de residencias sem televisor.
    int sem_televisor = 0;

    for (int i=0; i!=num_questionarios; i++) {
        if (num_televisores[i] == 0) {
            sem_televisor = sem_televisor + 1;
        }
    }

    // Descobrindo a média de televisores por residência (desconsiderando residências sem televisor).
    float media;
    int soma = 0;
    int com_televisor = num_questionarios - sem_televisor;

    for (int i=0; i!=num_questionarios; i++) {
        if (num_televisores[i] != 0) {
            soma = soma + num_televisores[i];
        }
    }

    media = (float)soma/(float)com_televisor;

    cout.precision(2);

    // Geração do relatório.
    cout << endl << "RELATORIO: ";
    cout << endl << "Quantidade de respostas do dia: " << num_questionarios;
    cout << endl << "Quantidade de residencias sem televisor: " << sem_televisor;
    cout << endl << "Media de televisores por residencias (desconsiderando residencias sem televisor): " << fixed << media << endl;

    delete(num_televisores);

    return 0;
}
