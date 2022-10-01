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
        string get_unidade(void);     //!< unidade do valor da resist�ncia
        string get_unidade_fisica(void);     //!< unidade f�sica
        double get_R_sem_unidade(void);     //!< valor atual da resist�ncia sem unidade
        double get_R_com_unidade(void);     //!< valor atual da resist�ncia com unidade
        bool set_R(double r);     //!< altera o valor do resistor
        bool set_R(double r, string unidade_r);     //!< altera o valor do resistor
        bool set_I(double v);     //!< altera o valor da corrente
        bool set_V(double i);     //!< altera o valor da tens�o
        resistor operator + (resistor &outro_R);     //!< sobrecarga do operador + (associa��o em s�rie)
        resistor operator / (resistor &outro_R);     //!< sobrecarga do operador / (associa��o em paralelo)
};

ostream& operator << (ostream &saida, resistor &r1);     //!< sobrecarga do operador <<

#endif // RESISTOR_HPP_INCLUDED
