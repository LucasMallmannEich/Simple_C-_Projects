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
    cout << "Resistência em Série: " << req_serie;

    req_paralelo = r1 / r2;
    cout << endl << "Resistência em Paralelo: " << req_paralelo << endl;

    capacitor c1(27, "m"), c2(15, "m");
    capacitor ceq_serie, ceq_paralelo;

    ceq_serie = c1 + c2;
    cout << endl << "Capacitância em Série: " << ceq_serie;

    ceq_paralelo = c1 / c2;
    cout << endl << "Capacitância em Paralelo: " << ceq_paralelo << endl;
    return 0;
}
