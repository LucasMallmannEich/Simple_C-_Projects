/* DESAFIO:
Elabore uma função que identifique a quantide de elementos num vetor numérico de inteiros.
parametros: vetor de dados.
retorno: número de elementos.
*/

#include <iostream>

using namespace std;

// Prototipação da função.
int tamanho_vetor(int vet[]);

int main()
{
    // Vetor para teste.
    int vetor[] = {5, 7, 8, 99, 90, 9};

    // A alternativa abaixo funciona apenas quando não passamos o vetor
    // como parâmetro de uma determinada função, pois o "sizeof()" irá
    // captar o tamanho de "vet[]" e não o tamanho do vetor passado.
    cout << " Tamanho do vetor: " << sizeof(vetor) << endl;
    cout << " Numero de elementos: " << sizeof(vetor)/4 << endl << endl;

    // Variável que armazena o tamanho do vetor.
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
