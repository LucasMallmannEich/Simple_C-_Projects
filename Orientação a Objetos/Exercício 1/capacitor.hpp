#ifndef CAPACITOR_HPP_INCLUDED
#define CAPACITOR_HPP_INCLUDED

#include "componente.hpp"
#include <string>

using namespace std;

class capacitor : public componente
{
    public:
        capacitor();
        capacitor(double cap);
        capacitor(double cap, string unidade_c);
        capacitor(double cap, string unidade_c, double deltaT);
        string get_unidade(void);     //!< unidade do valor da capacit�ncia
        double get_C_sem_unidade(void);     //!< valor atual da capacit�ncia sem unidade
        double get_C_com_unidade(void);     //!< valor atual da capacit�ncia com unidade
        bool set_C(double cap);
        bool set_C(double cap, string unidade_c);
        bool set_I(double i);
        bool set_V(double v);
        void set_Ic(double vc);
        void set_Vc(double ic);
};

#endif // CAPACITOR_HPP_INCLUDED
