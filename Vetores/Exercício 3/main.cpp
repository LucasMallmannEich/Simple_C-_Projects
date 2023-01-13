/* DESAFIO:
Elabore uma função que ordene um vetor numérico de inteiros.
parametros: vetor de dados, quantidade de elementos, ordem
retorno: nenhum
Para o parâmetro ordem, utilizar a enumeração abaixo:
enum VetOrdem_t  { V_CRESCE, V_DECRESCE};
*/

#include <iostream>

using namespace std;

// Enumeração da ordem do vetor.
enum VetOrdem_t {V_CRESCE=0, V_DECRESCE};

void ordenar_vetor(int vet[], int qtd, VetOrdem_t ordem);

int main()
{
    // Declaração das variaveis.
    int *vetor, qtd, ordem1;

    // Captação da quantidade de elementos que o vetor terá.
    do{
        cout << "Digite o numero de elementos que o vetor tem: ";
        cin >> qtd;
        if (qtd < 0) {
            cout << endl << "A quantidade de elementos do vetor nao pode ser negativa." << endl;
        }
    } while (qtd < 0);

    // Captação da ordem em que os números serão organizados.
    do{
      cout << "0 - crescente" << endl;
      cout << "1 - decrescente" << endl;
      cout << "Digite a ordem em que os elementos serao organizados (0 ou 1): ";
      cin >> ordem1;
      if (ordem1!=0 && ordem1!=1) {
            cout << "Voce deve digitar 0 para crescente ou 1 para decrescente." << endl;
      }
    } while (ordem1!=0 && ordem1!=1);

    // Alocação de memória dinamicamente para o vetor.
    vetor = new int[qtd];

    // Testando a função.
    for (int i=0; i!=qtd; i++) {
        cout << endl << "Digite um valor a ser acrescido na posicao " << i << " do vetor: ";
        cin >> vetor[i];
    }

    cout << endl << "Vetor original: " << endl;
    for (int i=0; i!=qtd; i++) {
        cout << " " << vetor[i] << " ";
    }

    if (ordem1 == V_CRESCE) {
        ordenar_vetor(vetor, qtd, V_CRESCE);
    }
    if (ordem1 == V_DECRESCE) {
        ordenar_vetor(vetor, qtd, V_DECRESCE);
    }

    cout << endl << "Vetor modificado: " << endl;
    for (int i=0; i!=qtd; i++) {
        cout << " " << vetor[i] << " ";
    }

    // Liberação da memória previamente reservada ao vetor.
    delete(vetor);

    return 0;
}

void ordenar_vetor(int vet[], int num, VetOrdem_t ordem){
    int maior, menor, posicao;
    int *vet_aux;

    vet_aux = new int[num];

    // Descobrindo o menor valor do vetor passado.
    for (int i=0; i!=num; i++) {
        if (i==0) {
            menor = vet[i];
        }
        if (vet[i] < menor) {
            menor = vet[i];
        }
    }

    // Descobrindo o maior valor do vetor passado.
    for (int i=0; i!=num; i++) {
        if (i==0) {
            maior = vet[i];
        }
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }

    switch (ordem)
    {
    // Ordenando o vetor em ordem crescente.
    case V_CRESCE:
        for (int j=0; j!=num; j++) {
            for (int k=0; k!=num; k++) {
                if (k==0) {
                    menor = vet[k];
                    posicao = k;
                }
                if (vet[k] < menor) {
                    menor = vet[k];
                    posicao = k;
                }
            }
            vet_aux[j] = menor;
            vet[posicao] = maior+1;
        }

        for (int k=0; k!=num; k++) {
            vet[k] = vet_aux[k];
        }
        break;

    // Ordenando o vetor em ordem decrescente.
    case V_DECRESCE:
        for (int j=0; j!=num; j++) {
            for (int k=0; k!=num; k++) {
                if (k==0) {
                    maior = vet[k];
                    posicao = k;
                }
                if (vet[k] > maior) {
                    maior = vet[k];
                    posicao = k;
                }
            }
            vet_aux[j] = maior;
            vet[posicao] = menor-1;
        }

        for (int k=0; k!=num; k++) {
            vet[k] = vet_aux[k];
        }
        break;

    // A resposta padrão caso o usuário não digite 0 (crescente) ou 1 (decrescente).
    default:
        cout << endl << "Voce nao digitou uma ordem valida." << endl;
    }

    delete(vet_aux);
}
