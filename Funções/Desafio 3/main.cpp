/* DESAFIO:
Elabore uma função que receba 3 parâmetros: R1, R2 e a razão R1/R2.
Um dos parâmetros deve ser zero. Calcule este parâmetro.
Se nenhum ou mais de um parâmetro for zero, retorne com ERR_PARAM.
*/

#include <iostream>
#include <locale.h>

using namespace std;

// Enumerate com o status da passagem de parametros para a função.
enum status {ERRO_PARAMETRO=-1, OK=0};

// Prototipação da função.
status calcular_resistencia(float &R1, float &R2, float &razao);

int main()
{
    // Habilitando a língua portuguesa no código (para poder utilizar acentuação).
    setlocale(LC_ALL, "Portuguese");

    // Declaração das variáveis.
    float r1, r2, razao_r1_r2;

    // Captação do valor de R1.
    do {
        cout << "Digite o valor de R1: ";
        cin >> r1;
        if (r1 < 0) {
            cout << " O valor de R1 não pode ser negativo." << endl;
        }
    } while (r1 < 0);

    // Captação do valor de R2.
    do {
        cout << "Digite o valor de R2: ";
        cin >> r2;
        if (r2 < 0) {
            cout << " O valor de R2 não pode ser negativo." << endl;
        }
    } while (r2 < 0);

    // Captação da razão entre R1 e R2.
    do {
        cout << "Digite a razão entre R1 e R2 (R1/R2): ";
        cin >> razao_r1_r2;
        if (razao_r1_r2 < 0) {
            cout << " O valor da razão entre R1 e R2 não pode ser negativo." << endl;
        }
    } while (razao_r1_r2 < 0);

    // Teste da função.
    cout.precision(2);

    int status_1;
    status_1 = calcular_resistencia(r1, r2, razao_r1_r2);

    switch (status_1) {
        case OK:
            cout << " R1: " << fixed << r1 << " ohms" << endl;
            cout << " R2: " << fixed << r2 << " ohms" << endl;
            cout << " Razão entre R1 e R2: " << fixed << razao_r1_r2;
            break;
        case ERRO_PARAMETRO:
            cout << "Tu deverias ter deixado exatamente 1 valor informado como zero.";
            break;
    }

    return 0;
}

status calcular_resistencia(float &R1, float &R2, float &razao) {
    if (R1 == 0 && R2 != 0 && razao != 0) {
        // Cálculo de R1.
        // razao = R1 / R2
        // R1 = razao * R2
        R1 = razao * R2;

        return OK;
    }
    else if (R2 == 0 && R1 != 0 && razao != 0) {
        // Cálculo de R2.
        // razao = R1 / R2
        // R2 = R1 / razao
        R2 = R1 / razao;

        return OK;
    }
    else if (razao == 0 && R1 != 0 && R2 != 0) {
        // Cálculo da razão entre R1 e R2.
        // razao = R1 / R2
        razao = R1 / R2;

        return OK;
    }
    else {
        // Caso o usuário não digite exatamente 1 valor zerado dos 3 valores passados.
        return ERRO_PARAMETRO;
    }
}
