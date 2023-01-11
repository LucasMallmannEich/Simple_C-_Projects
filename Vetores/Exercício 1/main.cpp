/* DESAFIO:
Elabore uma função que identifique o maior valor em um vetor de inteiros.
parametros: vetor de dados, quantidade de elementos
retorno: maior valor contido neste vetor
*/

#include <iostream>

using namespace std;

// Prototipação da função.
int maior_valor(int vet[], int num);

int main()
{
    // Declaração das variáveis que armazenam o vetor e a quantidade de elementos.
    int *vetor, qtd;

    // Do while para captar a quantidade de elementos que o vetor tem.
    do {
        cout << "Digite a quantidade de elementos que o vetor tem: ";
        cin >> qtd;
        if (qtd < 0) {
            cout << endl << "A quantidade de elementos do vetor nao pode ser negativa." << endl;
        }
    } while (qtd < 0);

    // Alocação de memória dinamicamente.
    vetor = new int[qtd];

    // Teste da função que retorna o maior numero dentro de um vetor de inteiros.
    for (int j=0; j!=qtd; j++) {
        cout << "Digite um valor para ser acrescido na posicao " << j << " do vetor: ";
        cin >> vetor[j];
    }

    cout << "Valores do vetor: ";
    for (int j=0; j!=qtd; j++) {
        cout << "  " << vetor[j] << "  ";
    }

    int maior;
    maior = maior_valor(vetor, qtd);

    cout << endl << "Maior numero do vetor passado: " << maior;

    // Liberação da memória alocada previamente para o vetor.
    delete(vetor);

    return 0;
}

int maior_valor(int vet[], int num) {
    // Variável que armazena o maior numero do vetor.
    int maior_num;

    // Loop for utilizado para percorrer todos os elementos do vetor passado.
    for (int i=0; i!=num; i++) {
        if (i == 0) {
            // O primeiro numero do vetor sera o maior, inicialmente.
            maior_num = vet[i];
        }
        else {
            // Se algum numero do vetor for maior do que o maior numero atual,
            // este será o novo maior numero.
            if (vet[i] > maior_num) {
                maior_num = vet[i];
            }
        }
    }

    // Retorno do maior numero do vetor de inteiros.
    return maior_num;
}
