/* DESAFIO:
Elabore uma função que receba 3 parâmetros:
R1 - valor do resistor 1;
R2 - valor do resistor 2;
Req - resistência equivalente.
Considerando que Req é a resistencia equivalente da associação R1 e R2, identifique
a associação utilizada, informando através do valor de retorno da função.
*/

#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

// Enumerate contendo o satus da conexao entre os resistores.
enum conexao_t {ERRO=-1, SERIE=1, PARALELO=2};

// Prototipação da função.
conexao_t conexao_resistiva(float R1, float R2, float Req);

int main()
{
    // Habilitando a língua portuguesa no código (para poder utilizar acentuação).
    setlocale(LC_ALL, "Portuguese");

    // Declaração das variáveis.
    float r1, r2, req;

    // Captação do valor de R1.
    do {
        cout << "Digite o valor do primeiro resistor, em ohms: ";
        cin >> r1;
        if (r1 < 0) {
            cout << "O valor do primeiro resistor não pode ser negativo." << endl;
        }
    } while (r1 < 0);

    // Captação do valor de R2.
    do {
        cout << "Digite o valor do segundo resistor, em ohms: ";
        cin >> r2;
        if (r2 < 0) {
            cout << "O valor do segundo resistor não pode ser negativo." << endl;
        }
    } while (r2 < 0);

    // Captação do valor de Req.
    do {
        cout << "Digite o valor da resistência equivalente entre os resistores, em ohms: ";
        cin >> req;
        if (req < 0) {
            cout << "O valor da resistência equivalente não pode ser negativo." << endl;
        }
    } while (req < 0);

    // Teste da função.
    int ligacao_resistiva;
    ligacao_resistiva = conexao_resistiva(r1, r2, req);

    switch(ligacao_resistiva) {
        case SERIE:
            cout << "Os resistores estão ligados em série.";
            break;
        case PARALELO:
            cout << "Os resistores estão ligados em paralelo.";
            break;
        default:
            cout << "Houve um erro, pois os valores informados não fazem sentido.";
    }

    return 0;
}

conexao_t conexao_resistiva(float R1, float R2, float Req) {
    if (round(Req) == round(R1+R2)) {
        // Caso a ligação esteja em série.
        return SERIE;
    }
    else if (round(Req) == round((R1*R2)/(R1+R2))) {
        // Caso a ligação esteja em paralelo.
        return PARALELO;
    }
    else {
        // Caso os valores não coincidam com nenhuma das duas opções válidas.
        return ERRO;
    }
}
