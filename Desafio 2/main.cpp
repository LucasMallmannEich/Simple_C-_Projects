/*
Este código visa inverter uma string informada pelo usuário (por exemplo: batata ---> atatab).
*/

#include <iostream>
#include <string>

using namespace std;

// Protótipo da função que inverte uma string.
string inverter_string(string str1);

int main()
{
    // Declaração da variável onde será armazenada a string informada pelo usuário.
    string str;

    // Entrada de dados do usuário.
    cout << "Digite uma string: ";
    getline(cin, str);

    // Inverte a string informada pelo usuário na própria variável original.
    string str_original = str;
    str = inverter_string(str);

    // Exibe a string original e a string invertida.
    cout << "String Original: " << str_original << endl;
    cout << "String Invertida: " << str;

    return 0;
}

// Função para inverter strings.
string inverter_string(string str1){
    string str_invertida = str1;
    int num = str1.length();  // capta o tamanho da string.
    for(int i=0; i<num; i++){
        str_invertida[i] = str1[num-i-1];
    }
    return str_invertida;  // retorna a string invertida.
}
