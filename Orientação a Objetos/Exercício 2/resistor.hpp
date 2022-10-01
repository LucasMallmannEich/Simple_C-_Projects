#ifndef RESISTOR_HPP_INCLUDED
#define RESISTOR_HPP_INCLUDED

#include "componente.hpp"
#include <ostream>
#include <string>

using namespace std;

class resistor : public componente
{
    public:
        resistor();
        resistor(double res);
        resistor(double res, string unidade_r);
        string get_unidade(void);     //!< unidade do valor da resistência
        string get_unidade_fisica(void);     //!< unidade física
        double get_R_sem_unidade(void);     //!< valor atual da resistência sem unidade
        double get_R_com_unidade(void);     //!< valor atual da resistência com unidade
        bool set_R(double r);     //!< altera o valor do resistor
        bool set_R(double r, string unidade_r);     //!< altera o valor do resistor
        bool set_I(double v);     //!< altera o valor da corrente
        bool set_V(double i);     //!< altera o valor da tensão
        resistor operator + (resistor &outro_R);     //!< sobrecarga do operador + (associação em série)
        resistor operator / (resistor &outro_R);     //!< sobrecarga do operador / (associação em paralelo)
};

ostream& operator << (ostream &saida, resistor &r1);     //!< sobrecarga do operador <<

#endif // RESISTOR_HPP_INCLUDED
