#include <iostream>

/*
DESAFIO: Assumindo que R1 e R2 formam um divisor de tensão (R2 paralelo a Vout).
Dado conjunto de valores iniciais, calcule o valor do elemento informado como zero,
ou diga que é impossivel calcular.
*/

using namespace std;

int main()
{
    // Declaração das variáveis.
    float R1, R2, Vin, Vout;
    int valores_zerados = 0;

    // Do while foi utilizado para captar o valor de R1, R2, Vin e Vout do usuário.
    do {
        cout << "Digite o valor de R1: " << endl;
        cin >> R1;
        if (R1 < 0) {
            cout << endl << "O valor de R1 nao pode ser negativo. Tente novamente." << endl;
        }
    }
    while (R1 < 0);

    do {
        cout << "Digite o valor de R2: " << endl;
        cin >> R2;
        if (R2 < 0) {
            cout << endl << "O valor de R2 nao pode ser negativo. Tente novamente." << endl;
        }
    }
    while (R2 < 0);

    do {
        cout << "Digite o valor de Vin: " << endl;
        cin >> Vin;
        if (Vin < 0) {
            cout << endl << "O valor de Vin nao pode ser negativo. Tente novamente." << endl;
        }
    }
    while (Vin < 0);

    do {
        cout << "Digite o valor de Vout: " << endl;
        cin >> Vout;
        if (Vout < 0) {
            cout << endl << "O valor de Vout nao pode ser negativo. Tente novamente." << endl;
        }
    }
    while (Vout < 0);

    // Os valores iguais a zero sao colocados dentro do vetor "valores_zerados".
    if (R1 == 0) {
        valores_zerados = valores_zerados + 1;
    }
    if (R2 == 0) {
        valores_zerados = valores_zerados + 1;
    }
    if (Vin == 0) {
        valores_zerados = valores_zerados + 1;
    }
    if (Vout == 0) {
        valores_zerados = valores_zerados + 1;
    }

    // Blocos condicionais para verificar quais variáveis estao com seu valor zerado.

    if (valores_zerados > 1) {
        cout << "Impossivel calcular mais de um valor zerado.";
    }
    else if (R1 == 0) {
        // R1 = VR1 / I
        // R1 = (Vin - VR2) / I
        // R1 = (Vin - Vout) / I
        // R1 = (Vin - Vout) / (Vout/R2)
        R1 = (Vin - Vout) / (Vout/R2);
        cout.precision(1);
        cout << "Valor de R1: " << fixed << R1 << " ohms";
    }
    else if (R2 == 0) {
        // R2 = VR2 / I
        // R2 = Vout / I
        // R2 = Vout / [(Vin-Vout)/R1]
        R2 = Vout / ((Vin-Vout)/R1);
        cout.precision(1);
        cout << "Valor de R2: " << fixed << R2 << " ohms";
    }
    else if (Vin == 0) {
        // Vin = VR1 + VR2
        // Vin = (R1*I) + Vout
        // Vin = [R1 * (Vout/R2)] + Vout
        Vin = R1 * (Vout/R2) + Vout;
        cout.precision(2);
        cout << "Valor de Vin: " << fixed << Vin << " V";
    }
    else if (Vout == 0) {
        // Vout = VR2
        // Vout = Vin - VR1
        // Vout = Vin - (R1*I)
        // Vout = Vin - {R1 * [Vin/(R1+R2)]}
        Vout = Vin - (R1 * (Vin/(R1+R2)));
        cout.precision(2);
        cout << endl << "Valor de Vout: " << fixed << Vout << " V";
    }

    return 0;
}
