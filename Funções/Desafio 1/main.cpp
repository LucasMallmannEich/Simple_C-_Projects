/* DESAFIO:
Elabore uma fun��o que receba 3 par�metros:
R1 - valor do resistor 1;
R2 - valor do resistor 2;
Req - resist�ncia equivalente.
Considerando que Req � a resistencia equivalente da associa��o R1 e R2, identifique
a associa��o utilizada, informando atrav�s do valor de retorno da fun��o.
*/

#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

// Enumerate contendo o satus da conexao entre os resistores.
enum conexao_t {ERRO=-1, SERIE=1, PARALELO=2};

// Prototipa��o da fun��o.
conexao_t conexao_resistiva(float R1, float R2, float Req);

int main()
{
    // Habilitando a l�ngua portuguesa no c�digo (para poder utilizar acentua��o).
    setlocale(LC_ALL, "Portuguese");

    // Declara��o das vari�veis.
    float r1, r2, req;

    // Capta��o do valor de R1.
    do {
        cout << "Digite o valor do primeiro resistor, em ohms: ";
        cin >> r1;
        if (r1 < 0) {
            cout << "O valor do primeiro resistor n�o pode ser negativo." << endl;
        }
    } while (r1 < 0);

    // Capta��o do valor de R2.
    do {
        cout << "Digite o valor do segundo resistor, em ohms: ";
        cin >> r2;
        if (r2 < 0) {
            cout << "O valor do segundo resistor n�o pode ser negativo." << endl;
        }
    } while (r2 < 0);

    // Capta��o do valor de Req.
    do {
        cout << "Digite o valor da resist�ncia equivalente entre os resistores, em ohms: ";
        cin >> req;
        if (req < 0) {
            cout << "O valor da resist�ncia equivalente n�o pode ser negativo." << endl;
        }
    } while (req < 0);

    // Teste da fun��o.
    int ligacao_resistiva;
    ligacao_resistiva = conexao_resistiva(r1, r2, req);

    switch(ligacao_resistiva) {
        case SERIE:
            cout << "Os resistores est�o ligados em s�rie.";
            break;
        case PARALELO:
            cout << "Os resistores est�o ligados em paralelo.";
            break;
        default:
            cout << "Houve um erro, pois os valores informados n�o fazem sentido.";
    }

    return 0;
}

conexao_t conexao_resistiva(float R1, float R2, float Req) {
    if (round(Req) == round(R1+R2)) {
        // Caso a liga��o esteja em s�rie.
        return SERIE;
    }
    else if (round(Req) == round((R1*R2)/(R1+R2))) {
        // Caso a liga��o esteja em paralelo.
        return PARALELO;
    }
    else {
        // Caso os valores n�o coincidam com nenhuma das duas op��es v�lidas.
        return ERRO;
    }
}
