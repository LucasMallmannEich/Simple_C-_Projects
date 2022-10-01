#ifndef CAPACITOR_HPP_INCLUDED
#define CAPACITOR_HPP_INCLUDED

#include "componente.hpp"
#include <ostream>
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
        string get_unidade_fisica(void);     //!< unidade f�sica
        double get_C_sem_unidade(void);     //!< valor atual da capacit�ncia sem unidade
        double get_C_com_unidade(void);     //!< valor atual da capacit�ncia com unidade
        double get_deltaT(void);
        bool set_C(double cap);
        bool set_C(double cap, string unidade_c);
        bool set_I(double i);
        bool set_V(double v);
        void set_Ic(double vc);
        void set_Vc(double ic);
        capacitor operator / (capacitor &outro_C);     //!< sobrecarga do operador / (associa��o em s�rie)
        capacitor operator + (capacitor &outro_C);     //!< sobrecarga do operador + (associa��o em paralelo)
};

ostream& operator << (ostream &saida, capacitor &c1);     //!< sobrecarga do operador <<

#endif // CAPACITOR_HPP_INCLUDED
