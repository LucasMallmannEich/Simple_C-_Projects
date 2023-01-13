/* DESAFIO:
Elabore uma fun��o que ordena (ordem crescente) um vetor num�rico de inteiros.
parametros: vetor de dados, quantidade de elementos
retorno: nenhum
*/

#include <iostream>

using namespace std;

// Prototipa��o da fun��o.
void ordenar_vetor(int vet[], int num);

int main()
{
    // Declara��o das vari�veis que armazenam o vetor e a quantidade de elementos.
    int *vetor, qtd;

    // Do while para captar a quantidade de elementos que o vetor tem.
    do {
        cout << "Digite a quantidade de elementos que o vetor tem: ";
        cin >> qtd;
        if (qtd < 0) {
            cout << endl << "A quantidade de elementos do vetor nao pode ser negativa." << endl;
        }
    } while (qtd < 0);

    // Aloca��o de mem�ria dinamicamente.
    vetor = new int[qtd];

    // Teste da fun��o que ordena o vetor passado como par�metro.
    for (int j=0; j!=qtd; j++) {
        cout << "Digite um valor para ser acrescido na posicao " << j << " do vetor: ";
        cin >> vetor[j];
    }

    cout << "Valores do vetor: " << endl;
    for (int j=0; j!=qtd; j++) {
        cout << vetor[j] << endl;
    }

    ordenar_vetor(vetor, qtd);

    cout << endl << "Vetor ordenado: " << endl;
    for (int i=0; i!=qtd; i++) {
        cout << " " << vetor[i] << " ";
    }

    // Libera��o da mem�ria alocada previamente para o vetor.
    delete(vetor);

    return 0;
}

void ordenar_vetor(int vet[], int num) {

    // Declara��o das vari�veis auxiliares dessa fun��o.
    int menor_valor, maior_valor, posicao;
    int *vet_ordenado;

    // Aloca��o de mem�ria dinamicamente.
    vet_ordenado = new int[num];

    // Loop for utilizado para descobrir o maior valor do "vet[]" passado.
    for (int k=0; k!=num; k++) {
        if (k == 0) {
            maior_valor = vet[k];
        }
        else {
            if (vet[k] > maior_valor) {
                maior_valor = vet[k];
            }
        }
    }

    // Loop for utilizado para ordenar os valores de "vet[]" no "vet_ordenado[]".
    for (int j=0; j!=num; j++) {
        for (int i=0; i!=num; i++) {
            if (i==0) {
                menor_valor = vet[i];
                posicao = 0;
            }
            if (vet[i] < menor_valor) {
                menor_valor = vet[i];
                posicao = i;
            }
        }
        vet_ordenado[j] = menor_valor;
        vet[posicao] = maior_valor+1;
    }

    // Loop for que passa os valores do "vet_ordenado[]" para o "vet[]"
    for(int aux=0; aux!=num; aux++) {
        vet[aux] = vet_ordenado[aux];
    }

    // Libera a mem�ria previamente alocada para o "vet_ordenado[]".
    delete(vet_ordenado);
}
