/* DESAFIO:
Elabore uma fun��o que receba um valor de resistor e arredonde para o valor mais pr�ximo na s�rie E-12,
indicando o erro percentual deste arredondamento.
Retorne com ERRO_VALOR caso o valor informado seja inv�lido.
Siga o prot�tipo abaixo:
status resistorE12(float &resistor)
*/

#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

// Enumera��o do status dos parametros passados.
enum status {ERRO_VALOR=-1, OK=0};

// Prototipa��o da fun��o.
status resistorE12(float &resistor);

int main()
{
    // Habilitando a l�ngua portuguesa no c�digo (para poder utilizar acentua��o).
    setlocale(LC_ALL, "Portuguese");

    // Declara��o das vari�veis.
    float R1;
    int status_1;

    // Capta��o do valor de R1 informado pelo usu�rio.
    cout << "Digite o valor do resistor: ";
    cin >> R1;

    // Teste da fun��o.
    status_1 = resistorE12(R1);

    cout.precision(2);

    switch (status_1) {
        case ERRO_VALOR:
            cout << " O valor de um resistor n�o pode ser negativo ou zero.";
            break;
        case OK:
            cout << " Valor do resistor mais pr�ximo (s�rie E12): " << fixed << R1 << " ohms.";
            break;
    }

    return 0;
}

status resistorE12(float &resistor) {
    cout.precision(3);

    // Declara��o dos valores da s�rie E12 e do valor do resistor mais pr�ximo ao informado.
    int valores[12] = {10, 12, 15, 18, 22, 27, 33, 39, 47, 56, 68, 82}, valor;

    // Declara��o da dist�ncia entre o valor informado e o valor da s�rie E12.
    float distancia = 100;

    // Declara��o do percentual de erro no arredondamento do resistor para o da s�rie E12.
    float erro;

    // Declara��o da vari�vel que ir� ter o valor da terceira faixa colorida de um resistor.
    int num_zeros;

    // Descobrindo a quantidade de zeros ap�s o segundo n�mero do valor informado.
    if (resistor > 10 && resistor < 100) {
        num_zeros = 0;
    }
    else if ((resistor > 100 || resistor == 100) && resistor < 1000) {
        num_zeros = 1;
    }
    else if ((resistor > 1000 || resistor == 1000) && resistor < 10000) {
        num_zeros = 2;
    }
    else if ((resistor > 10000 || resistor == 10000) && resistor < 100000) {
        num_zeros = 3;
    }
    else if ((resistor > 100000 || resistor == 100000) && resistor < 1000000) {
        num_zeros = 4;
    }
    else if ((resistor > 1000000 || resistor == 1000000) && resistor < 10000000) {
        num_zeros = 5;
    }
    else if ((resistor > 10000000 || resistor == 10000000) && resistor < 100000000) {
        num_zeros = 6;
    }
    else if ((resistor > 100000000 || resistor == 100000000) && resistor < 1000000000) {
        num_zeros = 7;
    }

    // Substitui��o dos valores da s�rie E12 para se adequarem ao n�mero de zeros do valor informado.
    if (num_zeros != 0) {
        distancia = 100 * (pow(10, num_zeros));
        for(int i=0; i!=12; i++) {
            valores[i] = round(valores[i] * (pow(10, num_zeros)));
        }
    }

    if (resistor < 0 || resistor == 0) {
        // A fun��o ir� retornar um erro caso o usu�rio digite um valor negativo para o resistor.
        return ERRO_VALOR;
    }
    else if (resistor < 10 || resistor == 10) {
        // Caso o resistor for menor do que 10, seu valor mais pr�ximo ser� 10.
        erro = (10 - resistor) / resistor;
        erro = erro * 100;

        cout << " Erro percentual do arredondamento: " << fixed << erro << " %" << endl;
        resistor = 10;
        return OK;
    }
    else {
        // C�lculo do valor mais pr�ximo ao valor informado.
        for (int i=0; i!=12; i++) {
            if (valores[i] > resistor) {
                if ((valores[i] - resistor) < distancia) {
                    valor = valores[i];
                    distancia = valores[i] - resistor;
                }
            }
            else {
                if ((resistor - valores[i]) < distancia) {
                    valor = valores[i];
                    distancia = resistor - valores[i];
                }
            }
        }

        // C�lculo do percentual de erro.
        if (resistor > valor) {
            erro = (resistor - valor) / resistor;
            erro = erro * 100;
            cout << " Erro percentual do arredondamento: " << fixed << erro << " %" << endl;
        }
        else {
            erro = (valor - resistor) / resistor;
            erro = erro * 100;
            cout << " Erro percentual do arredondamento: " << fixed << erro << " %" << endl;
        }

        // Retorna que tudo ocorreu bem e substitui o valor informado por uma da s�rie E12.
        resistor = valor;
        return OK;
    }
}
