/*
Este código visa poder informar se determinado ano
informado pelo usuário é um ano bissexto ou não.
*/

#include <iostream>

using namespace std;

// Enumeração para simplificar a visualização do retorno da função.
enum bissextos{NAO=0, SIM};

// Prototipação da função que realiza a verificação de ano bissextos.
bissextos verifica_ano_bissexto(int ano);

int main()
{
    // Declaração da variável "ano", para armazenar o ano informado pelo usuário.
    int ano;

    // Usuário informa o ano a ser verificado pela função.
    cout << "Digite o ano: " << endl;
    cin >> ano;

    // Verificação do retorno da função.
    if (verifica_ano_bissexto(ano) == SIM) {
        cout << "Ano " << ano << ": Bissexto";
    }
    else {
        cout << "Ano " << ano << ": Nao Bissexto";
    }

    return 0;
}

bissextos verifica_ano_bissexto(int ano) {
    // Verifica se o ano for divisível por 4.
    if ((ano%4) == 0) {
        // Verifica se o ano também é divisível por 400.
        if ((ano%400) == 0) {
            return SIM;
        }
        // Verifica se o ano é divisível, se não for por 400, por 100.
        if ((ano%100) == 0) {
            return NAO;
        }
        return SIM;
    }
    else {
        return NAO;
    }
}
