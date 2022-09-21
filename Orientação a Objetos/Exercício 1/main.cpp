#include <iostream>
#include "componente.hpp"
#include "resistor.hpp"
#include "capacitor.hpp"

using namespace std;

int main()
{
    resistor r1;
    resistor r2(100);
    resistor r3(120, "k");

    float VT = 7.5;

    cout << endl << "Resistor R1 (unidade): " << r1.get_unidade() << endl;
    cout << "Resistor R1 (sem unidade): " << r1.get_R_sem_unidade() << endl;
    cout << "Resistor R1 (com unidade): " << r1.get_R_com_unidade() << endl;
    cout << "Resistor R2 (unidade): " << r2.get_unidade() << endl;
    cout << "Resistor R2 (sem unidade): " << r2.get_R_sem_unidade() << endl;
    cout << "Resistor R2 (com unidade): " << r2.get_R_com_unidade() << endl;
    cout << "Resistor R3 (unidade): " << r3.get_unidade() << endl;
    cout << "Resistor R3 (sem unidade): " << r3.get_R_sem_unidade() << endl;
    cout << "Resistor R3 (com unidade): " << r3.get_R_com_unidade() << endl << endl;

    r1.set_R(-10);

    return 0;
}
