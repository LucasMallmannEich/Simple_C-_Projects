/*
Este c�digo visa inverter uma string informada pelo usu�rio (por exemplo: batata ---> atatab).
*/

#include <iostream>
#include <string>

using namespace std;

// Prot�tipo da fun��o que inverte uma string.
string inverter_string(string str1);

int main()
{
    // Declara��o da vari�vel onde ser� armazenada a string informada pelo usu�rio.
    string str;

    // Entrada de dados do usu�rio.
    cout << "Digite uma string: ";
    getline(cin, str);

    // Inverte a string informada pelo usu�rio na pr�pria vari�vel original.
    string str_original = str;
    str = inverter_string(str);

    // Exibe a string original e a string invertida.
    cout << "String Original: " << str_original << endl;
    cout << "String Invertida: " << str;

    return 0;
}

// Fun��o para inverter strings.
string inverter_string(string str1){
    string str_invertida = str1;
    int num = str1.length();  // capta o tamanho da string.
    for(int i=0; i<num; i++){
        str_invertida[i] = str1[num-i-1];
    }
    return str_invertida;  // retorna a string invertida.
}
