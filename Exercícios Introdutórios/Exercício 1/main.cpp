#include <iostream>

/*
DESAFIO: Assumindo que R1 e R2 formam um divisor de tensão (R2 paralelo a Vout).
Dado valores de R1, R2 e Vin, calcule Vout.
*/

using namespace std;

int main()
{
    // Declaração das variáveis.
    float R1, R2, Vin, Vout;

    // Do while utilizado para captar, do usuário, o valor de R1.
    do {
        cout << "Digite um valor para o R1: ";
        cin >> R1;
        if (R1 < 0){
            cout << endl << "Tente novamente (com valores nao negativos)." << endl;
        }
    }
    while (R1 < 0);

    // Do while utilizado para captar, do usuário, o valor de R2.
    do {
        cout << "Digite um valor para o R2: ";
        cin >> R2;
        if (R2 < 0){
            cout << endl << "Tente novamente (com valores nao negativos)." << endl;
        }
    }
    while (R2 < 0);

    // Do while utilizado para captar, do usuário, o valor de Vin.
    do {
        cout << "Digite um valor para a Vin: ";
        cin >> Vin;
        if (Vin < 0){
            cout << endl << "Tente novamente (com valores nao negativos)." << endl;
        }
    }
    while (Vin < 0);

    /*
    Lógica matemática e eletrônica utilizada para a fórmula do Vout.

    Vout = VR2;
    Vout = I . R2;
    Vout = (Vin/(R1 + R2)) . R2;
    */

    // Cálculo do Vout.
    Vout = (Vin/(R1+R2)) * R2;

    /*
    O "cout.precision(2)" foi utilizado para garantir que os números impressos pelo
    cout mostrem apenas duas casas decimais, pois acredito que facilita a visualização.
    */

    cout.precision(2);

    /*
    Impressão do valor de "Vout".

    O "fixed" foi utilizado para garantir que os números impressos pelo cout não
    estejam em notação científica, pois acredito que facilita a sua visualização.
    */

    cout << endl << "Valor de Vout: " << fixed << Vout << " V" << endl;

    return 0;
}
