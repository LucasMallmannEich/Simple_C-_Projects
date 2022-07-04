#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    // Declara��o da vari�vel que representa o n�mero de pontos de um ciclo senoidal.
    int n;

    // O usu�rio informa o n�mero de pontos da onda senoidal.
    cout << "Digite o numero de pontos: ";
    cin >> n;

    // Inicializa a vari�vel que representa o n�mero do PI.
    //Tamb�m declara a vari�vel que representa o intervalo entre dois pontos da sen�ide.
    double PI = 3.14159265359;
    double intervalo, intervalo2;

    // Inicializa a vari�vel que representa a dist�ncia entre dois pontos da onda senoidal.
    intervalo = (2*PI) / n;
    intervalo2 = intervalo;

    // D� o nome de "senoide.txt" ao arquivo de texto em que as informa��es ser�o gravadas.
    string nome_arq = "senoide.txt";

    // Declara a stream de sa�da, que � respons�vel por gravar os dados no arquivo, como "outFile".
    ofstream outFile;

    // Abre o arquivo "senoide.txt" no m�todo de escrita.
    outFile.open(nome_arq, ios::out);

    // Verifica se o arquivo foi criado ou aberto.
    if(! outFile) {
        cout << "O arquivo " << nome_arq << " nao pode ser aberto." << endl;
        return -1;
    }

    // Determina que os n�meros ser�o inseridos no arquivo com tr�s casas decimais.
    outFile.precision(3);

    // La�o de repeti��o que armazena, no arquivo, os valores dos n pontos da onda senoidal.
    for (int i=0; i<n; i++) {
        outFile << fixed << sin(intervalo) << '\n';
        intervalo = intervalo + intervalo2;
    }

    // Fecha o arquivo.
    outFile.close();

    return 0;
}
