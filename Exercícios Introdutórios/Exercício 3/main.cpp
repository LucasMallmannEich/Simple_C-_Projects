#include <iostream>

/*
DESAFIO: Solicite um nome/substantivo.
Gere, a partir do nome dado, palavras com os prefixos sub e sob.
*/

using namespace std;

int main()
{
    // Declara��o das vari�veis.
    string substantivo, substantivo_sub, substantivo_sob;

    // Captura do substantivo informado pelo usu�rio.
    cout << "Digite um nome/substantivo: ";
    cin >> substantivo;

    // Forma��o das vari�veis "substantivo_sub" e "substantivo_sob".
    substantivo_sub = "sub" + substantivo;
    substantivo_sob = "sob" + substantivo;

    // Impress�o dos resultados (vari�veis "substantivo_sub" e "substantivo_sob")
    cout << "\"" << substantivo << "\"" << " com o prefixo \"sub\": " << substantivo_sub << endl;
    cout << "\"" << substantivo << "\" com o prefixo \"sob\": " << substantivo_sob << endl;

    return 0;
}
