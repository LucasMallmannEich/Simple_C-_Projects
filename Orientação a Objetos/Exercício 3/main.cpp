#include <iostream>
#include "diodo.hpp"
#include "fonte_ac.hpp"

using namespace std;

int main()
{
    diodo d1, d2;
    fonte_ac f1(12);

    f1.set_deltaT(1);

    for(int i=0; i < 100; i++) {
        f1.calculo_tensao(i * f1.get_deltaT());
        if(f1.get_V() > d1.get_vd()) {
            cout << endl << "Tensao apos D1: " << f1.get_V() - d1.get_vd() << " V";
        }
        else {
            cout << endl << "Tensao apos D1: 0 V";
        }
        if((f1.get_V()*(-1)) > d2.get_vd()) {
            cout << endl << "Tensao apos D2: " << (f1.get_V()*(-1)) - d2.get_vd() << " V" << endl;
        }
        else {
            cout << endl << "Tensao apos D2: 0 V" << endl;
        }
    }

    return 0;
}
