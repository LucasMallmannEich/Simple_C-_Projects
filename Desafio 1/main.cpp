/*
Este c�digo visa poder informar se determinado ano
informado pelo usu�rio � um ano bissexto ou n�o.
*/

#include <iostream>

using namespace std;

// Enumera��o para simplificar a visualiza��o do retorno da fun��o.
enum bissextos{NAO=0, SIM};

// Prototipa��o da fun��o que realiza a verifica��o de ano bissextos.
bissextos verifica_ano_bissexto(int ano);

int main()
{
    // Declara��o da vari�vel "ano", para armazenar o ano informado pelo usu�rio.
    int ano;

    // Usu�rio informa o ano a ser verificado pela fun��o.
    cout << "Digite o ano: " << endl;
    cin >> ano;

    // Verifica��o do retorno da fun��o.
    if (verifica_ano_bissexto(ano) == SIM) {
        cout << "Ano " << ano << ": Bissexto";
    }
    else {
        cout << "Ano " << ano << ": Nao Bissexto";
    }

    return 0;
}

bissextos verifica_ano_bissexto(int ano) {
    // Verifica se o ano for divis�vel por 4.
    if ((ano%4) == 0) {
        // Verifica se o ano tamb�m � divis�vel por 400.
        if ((ano%400) == 0) {
            return SIM;
        }
        // Verifica se o ano � divis�vel, se n�o for por 400, por 100.
        if ((ano%100) == 0) {
            return NAO;
        }
        return SIM;
    }
    else {
        return NAO;
    }
}
