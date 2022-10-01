#include <iostream>
#include <locale>
#include "componente.hpp"
#include "resistor.hpp"
#include "capacitor.hpp"
#include "fonteV.hpp"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    resistor r1(270), r2(220);
    resistor req_serie, req_paralelo;

    req_serie = r1 + r2;
    cout << "Resist�ncia em S�rie: " << req_serie;

    req_paralelo = r1 / r2;
    cout << endl << "Resist�ncia em Paralelo: " << req_paralelo << endl;

    capacitor c1(27, "m"), c2(15, "m");
    capacitor ceq_serie, ceq_paralelo;

    ceq_serie = c1 + c2;
    cout << endl << "Capacit�ncia em S�rie: " << ceq_serie;

    ceq_paralelo = c1 / c2;
    cout << endl << "Capacit�ncia em Paralelo: " << ceq_paralelo << endl;
    return 0;
}
