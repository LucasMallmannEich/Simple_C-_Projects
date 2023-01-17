/* DESAFIO:
Elabore uma fun��o que identifique a quantide de elementos num vetor num�rico de inteiros.
parametros: vetor de dados.
retorno: n�mero de elementos.
*/

#include <iostream>

using namespace std;

// Prototipa��o da fun��o.
int tamanho_vetor(int vet[]);

int main()
{
    // Vetor para teste.
    int vetor[] = {5, 7, 8, 99, 90, 9};

    // A alternativa abaixo funciona apenas quando n�o passamos o vetor
    // como par�metro de uma determinada fun��o, pois o "sizeof()" ir�
    // captar o tamanho de "vet[]" e n�o o tamanho do vetor passado.
    cout << " Tamanho do vetor: " << sizeof(vetor) << endl;
    cout << " Numero de elementos: " << sizeof(vetor)/4 << endl << endl;

    // Vari�vel que armazena o tamanho do vetor.
    int tamanho;
    tamanho = tamanho_vetor(vetor);

    cout << " Tamanho do vetor (de acordo com a funcao): " << tamanho << endl;
    cout << " Numeros de elementos (de acordo com a funcao): " << (tamanho/4) << endl;

    return 0;
}

int tamanho_vetor(int vet[]) {
    int tam = 0;

    tam = sizeof(vet);

    return tam;
}
