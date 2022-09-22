#include <iostream>
#include "componente.hpp"
#include "resistor.hpp"
#include "capacitor.hpp"
#include "fonteV.hpp"

using namespace std;

int main()
{
    resistor r1;
    resistor r2(100);
    resistor r3(120, "k");

    cout << endl << "Resistor R1 (unidade): " << r1.get_unidade() << endl;
    cout << "Resistor R1 (sem unidade): " << r1.get_R_sem_unidade() << endl;
    cout << "Resistor R1 (com unidade): " << r1.get_R_com_unidade() << endl;
    cout << "Resistor R2 (unidade): " << r2.get_unidade() << endl;
    cout << "Resistor R2 (sem unidade): " << r2.get_R_sem_unidade() << endl;
    cout << "Resistor R2 (com unidade): " << r2.get_R_com_unidade() << endl;
    cout << "Resistor R3 (unidade): " << r3.get_unidade() << endl;
    cout << "Resistor R3 (sem unidade): " << r3.get_R_sem_unidade() << endl;
    cout << "Resistor R3 (com unidade): " << r3.get_R_com_unidade() << endl << endl;

    r1.set_R(120, "M");
    r2.set_R(10);
    r3.set_R(22, "k");

    cout << endl << "Resistor R1 (unidade): " << r1.get_unidade() << endl;
    cout << "Resistor R1 (sem unidade): " << fixed << r1.get_R_sem_unidade() << endl;
    cout << "Resistor R1 (com unidade): " << r1.get_R_com_unidade() << endl;
    cout << "Resistor R2 (unidade): " << r2.get_unidade() << endl;
    cout << "Resistor R2 (sem unidade): " << r2.get_R_sem_unidade() << endl;
    cout << "Resistor R2 (com unidade): " << r2.get_R_com_unidade() << endl;
    cout << "Resistor R3 (unidade): " << r3.get_unidade() << endl;
    cout << "Resistor R3 (sem unidade): " << r3.get_R_sem_unidade() << endl;
    cout << "Resistor R3 (com unidade): " << r3.get_R_com_unidade() << endl << endl;

    float VT = 7.5;
    float current = 0.030;

    r1.set_I(VT);
    r1.set_V(r1.get_I());

    r2.set_V(current);
    r2.set_I(r2.get_V());

    r3.set_V(1);
    r3.set_I(r3.get_V());

    cout << endl << "Resistor R1 (tensao): " << r1.get_V() << endl;
    cout << "Resistor R1 (corrente): " << r1.get_I() << endl;
    cout << "Resistor R2 (tensao): " << r2.get_V() << endl;
    cout << "Resistor R2 (corrente): " << r2.get_I() << endl;
    cout << "Resistor R3 (tensao): " << r3.get_V() << endl;
    cout << "Resistor R3 (corrente): " << r3.get_I() << endl << endl;

    capacitor c1;
    capacitor c2(0.0047);
    capacitor c3(3.3, "m");
    capacitor c4(100, "u", 0.05);

    cout << endl << "Capacitor C1 (unidade): " << c1.get_unidade() << endl;
    cout << "Capacitor C1 (sem unidade): " << fixed << c1.get_C_sem_unidade() << endl;
    cout << "Capacitor C1 (com unidade): " << c1.get_C_com_unidade() << endl;
    cout << "Capacitor C2 (unidade): " << c2.get_unidade() << endl;
    cout << "Capacitor C2 (sem unidade): " << c2.get_C_sem_unidade() << endl;
    cout << "Capacitor C2 (com unidade): " << c2.get_C_com_unidade() << endl;
    cout << "Capacitor C3 (unidade): " << c3.get_unidade() << endl;
    cout << "Capacitor C3 (sem unidade): " << c3.get_C_sem_unidade() << endl;
    cout << "Capacitor C3 (com unidade): " << c3.get_C_com_unidade() << endl;
    cout << "Capacitor C4 (unidade): " << c4.get_unidade() << endl;
    cout << "Capacitor C4 (sem unidade): " << c4.get_C_sem_unidade() << endl;
    cout << "Capacitor C4 (com unidade): " << c4.get_C_com_unidade() << endl << endl;

    c1.set_C(0.0033);
    c2.set_C(33, "sim");
    c3.set_C(47, "n");
    c4.set_C(1);

    cout << endl << "Capacitor C1 (unidade): " << c1.get_unidade() << endl;
    cout << "Capacitor C1 (sem unidade): " << fixed << c1.get_C_sem_unidade() << endl;
    cout << "Capacitor C1 (com unidade): " << c1.get_C_com_unidade() << endl;
    cout << "Capacitor C2 (unidade): " << c2.get_unidade() << endl;
    cout << "Capacitor C2 (sem unidade): " << c2.get_C_sem_unidade() << endl;
    cout << "Capacitor C2 (com unidade): " << c2.get_C_com_unidade() << endl;
    cout << "Capacitor C3 (unidade): " << c3.get_unidade() << endl;
    cout << "Capacitor C3 (sem unidade): " << c3.get_C_sem_unidade() << endl;
    cout << "Capacitor C3 (com unidade): " << c3.get_C_com_unidade() << endl;
    cout << "Capacitor C4 (unidade): " << c4.get_unidade() << endl;
    cout << "Capacitor C4 (sem unidade): " << c4.get_C_sem_unidade() << endl;
    cout << "Capacitor C4 (com unidade): " << c4.get_C_com_unidade() << endl << endl;

    fonteV v1(0, 36, 0);
    v1.set_fv(11);
    resistor r4(220);
    capacitor cap1(47, "n", 0.000001);

    double tempo, iCircuito=0, VF = v1.get_fv();
    for (int i=0; i < 100; i++) {
        tempo = i * cap1.get_deltaT();

        cout << endl << "Tempo: " << tempo << endl;
        cout << "Tensao VC = " << cap1.get_V() << endl;
        r4.set_I((VF-cap1.get_V()));
        iCircuito = r4.get_I();
        r4.set_V(iCircuito);
        cout << "Tensao VR = " << r4.get_V() << endl;
        cout << "Corrente: " << iCircuito << endl;
        cap1.set_Vc(iCircuito);
    }

    return 0;
}
