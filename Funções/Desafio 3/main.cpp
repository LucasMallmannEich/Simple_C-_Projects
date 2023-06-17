/* DESAFIO:
Elabore uma fun��o que receba 3 par�metros: R1, R2 e a raz�o R1/R2.
Um dos par�metros deve ser zero. Calcule este par�metro.
Se nenhum ou mais de um par�metro for zero, retorne com ERR_PARAM.
*/

#include <iostream>
#include <locale.h>

using namespace std;

// Enumerate com o status da passagem de parametros para a fun��o.
enum status {ERRO_PARAMETRO=-1, OK=0};

// Prototipa��o da fun��o.
status calcular_resistencia(float &R1, float &R2, float &razao);

int main()
{
    // Habilitando a l�ngua portuguesa no c�digo (para poder utilizar acentua��o).
    setlocale(LC_ALL, "Portuguese");

    // Declara��o das vari�veis.
    float r1, r2, razao_r1_r2;

    // Capta��o do valor de R1.
    do {
        cout << "Digite o valor de R1: ";
        cin >> r1;
        if (r1 < 0) {
            cout << " O valor de R1 n�o pode ser negativo." << endl;
        }
    } while (r1 < 0);

    // Capta��o do valor de R2.
    do {
        cout << "Digite o valor de R2: ";
        cin >> r2;
        if (r2 < 0) {
            cout << " O valor de R2 n�o pode ser negativo." << endl;
        }
    } while (r2 < 0);

    // Capta��o da raz�o entre R1 e R2.
    do {
        cout << "Digite a raz�o entre R1 e R2 (R1/R2): ";
        cin >> razao_r1_r2;
        if (razao_r1_r2 < 0) {
            cout << " O valor da raz�o entre R1 e R2 n�o pode ser negativo." << endl;
        }
    } while (razao_r1_r2 < 0);

    // Teste da fun��o.
    cout.precision(2);

    int status_1;
    status_1 = calcular_resistencia(r1, r2, razao_r1_r2);

    switch (status_1) {
        case OK:
            cout << " R1: " << fixed << r1 << " ohms" << endl;
            cout << " R2: " << fixed << r2 << " ohms" << endl;
            cout << " Raz�o entre R1 e R2: " << fixed << razao_r1_r2;
            break;
        case ERRO_PARAMETRO:
            cout << "Tu deverias ter deixado exatamente 1 valor informado como zero.";
            break;
    }

    return 0;
}

status calcular_resistencia(float &R1, float &R2, float &razao) {
    if (R1 == 0 && R2 != 0 && razao != 0) {
        // C�lculo de R1.
        // razao = R1 / R2
        // R1 = razao * R2
        R1 = razao * R2;

        return OK;
    }
    else if (R2 == 0 && R1 != 0 && razao != 0) {
        // C�lculo de R2.
        // razao = R1 / R2
        // R2 = R1 / razao
        R2 = R1 / razao;

        return OK;
    }
    else if (razao == 0 && R1 != 0 && R2 != 0) {
        // C�lculo da raz�o entre R1 e R2.
        // razao = R1 / R2
        razao = R1 / R2;

        return OK;
    }
    else {
        // Caso o usu�rio n�o digite exatamente 1 valor zerado dos 3 valores passados.
        return ERRO_PARAMETRO;
    }
}
