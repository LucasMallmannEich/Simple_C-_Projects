#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    // Declaração da variável que representa o número de pontos de um ciclo senoidal.
    int n;

    // O usuário informa o número de pontos da onda senoidal.
    cout << "Digite o numero de pontos: ";
    cin >> n;

    // Inicializa a variável que representa o número do PI.
    //Também declara a variável que representa o intervalo entre dois pontos da senóide.
    double PI = 3.14159265359;
    double intervalo, intervalo2;

    // Inicializa a variável que representa a distância entre dois pontos da onda senoidal.
    intervalo = (2*PI) / n;
    intervalo2 = intervalo;

    // Dá o nome de "senoide.txt" ao arquivo de texto em que as informações serão gravadas.
    string nome_arq = "senoide.txt";

    // Declara a stream de saída, que é responsável por gravar os dados no arquivo, como "outFile".
    ofstream outFile;

    // Abre o arquivo "senoide.txt" no método de escrita.
    outFile.open(nome_arq, ios::out);

    // Verifica se o arquivo foi criado ou aberto.
    if(! outFile) {
        cout << "O arquivo " << nome_arq << " nao pode ser aberto." << endl;
        return -1;
    }

    // Determina que os números serão inseridos no arquivo com três casas decimais.
    outFile.precision(3);

    // Laço de repetição que armazena, no arquivo, os valores dos n pontos da onda senoidal.
    for (int i=0; i<n; i++) {
        outFile << fixed << sin(intervalo) << '\n';
        intervalo = intervalo + intervalo2;
    }

    // Fecha o arquivo.
    outFile.close();

    return 0;
}
