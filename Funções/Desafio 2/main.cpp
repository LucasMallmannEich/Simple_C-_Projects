/* DESAFIO:
Elabore uma função que recebe três parâmetros, referentes a um sinal elétrico senoidal:
frequência -> frequência do sinal
fase -> fase do sinal
deltat -> atraso de tempo correspondente à fase

Um dos parâmetros deve ser zero. Calcule este parâmetro.
Se nenhum ou mais de um parâmetro for zero, retorne com ERR_PARAM.
*/

// T = 1/f
// T demora 2pi para acontecer
// (fase / 2pi) = (deltat / T)

#include <iostream>
#include <locale.h>

using namespace std;

#define PI 3.14159265359

// Enumerate contendo o status da passagem dos parâmetros feita pelo usuário.
enum validar_parametros {ERRO_PARAMETRO=-1, OK=0};

// Prototipação da função.
validar_parametros calcular(float &freq, float &fas, float &delta_t);

int main()
{
    // Habilitando a língua portuguesa no código (para poder utilizar acentuação).
    setlocale(LC_ALL, "Portuguese");

    // Declaração das variáveis.
    float frequencia, fase, t;

    // Captação do valor da frequência.
    do {
        cout << "Digite o valor da frequência, em Hz: ";
        cin >> frequencia;
        if (frequencia < 0) {
            cout << " A frequência não pode ser negativa." << endl;
        }
    } while (frequencia < 0);

    // Captação do valor da fase do sinal.
    do {
        cout << "Digite o valor da fase do sinal, em radianos: ";
        cin >> fase;
        if (fase < 0) {
            cout << " Não digite um valor menor do que zero." << endl;
        }
    } while (fase < 0);

    // Captação do valor do atraso de tempo do sinal.
    do {
        cout << "Digite o valor do atraso de tempo do sinal, em segundos: ";
        cin >> t;
        if (t < 0) {
            cout << " Não digite um valor negativo para o tempo." << endl;
        }
    } while (t < 0);

    // Teste da função.
    cout.precision(3);

    int status;
    status = calcular(frequencia, fase, t);

    if (status == OK) {
        cout << " Frequência: " << fixed << frequencia << " Hz" << endl;
        cout << " Fase: " << fixed << fase << " rad" << endl;
        cout << " Atraso do tempo da fase: " << fixed << t << " s" << endl;
    }
    else if (status == ERRO_PARAMETRO) {
        cout << " Voce deveria ter passado exatamente 1 parâmetro com valor zero.";
    }

    return 0;
}

validar_parametros calcular(float &freq, float &fas, float &delta_t) {
    if (freq == 0 && fas != 0 && delta_t != 0) {
        // (delta_t / T) = (fase / 2pi)
        // (T * fase) = (2pi * delta_t)
        // T = (2pi * delta_t) / fase

        // Cálculo do período.
        float T = ((2*PI) * delta_t) / fas;

        // Cálculo da frequência.
        freq = 1 / T;

        return OK;
    }
    else if (fas == 0 && freq != 0 && delta_t != 0) {
        // (delta_t / T) = (fase / 2pi)
        // (T * fase) = (2pi * delta_t)
        // fase = (2pi * delta_t) / T

        // Cálculo do período.
        float T = 1 / freq;

        // Cáluclo do ângulo de fase.
        fas = ((2*PI) * delta_t) / T;

        return OK;
    }
    else if (delta_t == 0 && freq != 0 && fas != 0) {
        // (delta_t / T) = (fase / 2pi)
        // (delta_t * 2pi) = (T * fase)
        // delta_t = (T * fase) / (2 * PI)

        // Cálculo do período.
        float T = 1 / freq;

        // Cálculo do tempo de atraso.
        delta_t = (T * fas) / (2*PI);

        return OK;
    }
    else {
        // Caso o usuário não passe nenhum parâmetro zerado ou mais de um parâmetro zerado.
        return ERRO_PARAMETRO;
    }
    return OK;
}
