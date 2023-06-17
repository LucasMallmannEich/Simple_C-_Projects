/* DESAFIO:
Elabore uma fun��o que recebe tr�s par�metros, referentes a um sinal el�trico senoidal:
frequ�ncia -> frequ�ncia do sinal
fase -> fase do sinal
deltat -> atraso de tempo correspondente � fase

Um dos par�metros deve ser zero. Calcule este par�metro.
Se nenhum ou mais de um par�metro for zero, retorne com ERR_PARAM.
*/

// T = 1/f
// T demora 2pi para acontecer
// (fase / 2pi) = (deltat / T)

#include <iostream>
#include <locale.h>

using namespace std;

#define PI 3.14159265359

// Enumerate contendo o status da passagem dos par�metros feita pelo usu�rio.
enum validar_parametros {ERRO_PARAMETRO=-1, OK=0};

// Prototipa��o da fun��o.
validar_parametros calcular(float &freq, float &fas, float &delta_t);

int main()
{
    // Habilitando a l�ngua portuguesa no c�digo (para poder utilizar acentua��o).
    setlocale(LC_ALL, "Portuguese");

    // Declara��o das vari�veis.
    float frequencia, fase, t;

    // Capta��o do valor da frequ�ncia.
    do {
        cout << "Digite o valor da frequ�ncia, em Hz: ";
        cin >> frequencia;
        if (frequencia < 0) {
            cout << " A frequ�ncia n�o pode ser negativa." << endl;
        }
    } while (frequencia < 0);

    // Capta��o do valor da fase do sinal.
    do {
        cout << "Digite o valor da fase do sinal, em radianos: ";
        cin >> fase;
        if (fase < 0) {
            cout << " N�o digite um valor menor do que zero." << endl;
        }
    } while (fase < 0);

    // Capta��o do valor do atraso de tempo do sinal.
    do {
        cout << "Digite o valor do atraso de tempo do sinal, em segundos: ";
        cin >> t;
        if (t < 0) {
            cout << " N�o digite um valor negativo para o tempo." << endl;
        }
    } while (t < 0);

    // Teste da fun��o.
    cout.precision(3);

    int status;
    status = calcular(frequencia, fase, t);

    if (status == OK) {
        cout << " Frequ�ncia: " << fixed << frequencia << " Hz" << endl;
        cout << " Fase: " << fixed << fase << " rad" << endl;
        cout << " Atraso do tempo da fase: " << fixed << t << " s" << endl;
    }
    else if (status == ERRO_PARAMETRO) {
        cout << " Voce deveria ter passado exatamente 1 par�metro com valor zero.";
    }

    return 0;
}

validar_parametros calcular(float &freq, float &fas, float &delta_t) {
    if (freq == 0 && fas != 0 && delta_t != 0) {
        // (delta_t / T) = (fase / 2pi)
        // (T * fase) = (2pi * delta_t)
        // T = (2pi * delta_t) / fase

        // C�lculo do per�odo.
        float T = ((2*PI) * delta_t) / fas;

        // C�lculo da frequ�ncia.
        freq = 1 / T;

        return OK;
    }
    else if (fas == 0 && freq != 0 && delta_t != 0) {
        // (delta_t / T) = (fase / 2pi)
        // (T * fase) = (2pi * delta_t)
        // fase = (2pi * delta_t) / T

        // C�lculo do per�odo.
        float T = 1 / freq;

        // C�luclo do �ngulo de fase.
        fas = ((2*PI) * delta_t) / T;

        return OK;
    }
    else if (delta_t == 0 && freq != 0 && fas != 0) {
        // (delta_t / T) = (fase / 2pi)
        // (delta_t * 2pi) = (T * fase)
        // delta_t = (T * fase) / (2 * PI)

        // C�lculo do per�odo.
        float T = 1 / freq;

        // C�lculo do tempo de atraso.
        delta_t = (T * fas) / (2*PI);

        return OK;
    }
    else {
        // Caso o usu�rio n�o passe nenhum par�metro zerado ou mais de um par�metro zerado.
        return ERRO_PARAMETRO;
    }
    return OK;
}
