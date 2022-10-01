#include "capacitor.hpp"
#include <iomanip>

//! Construtor padrão - incializa todas as variaveis com 0 ou vazio
capacitor::capacitor()
{
    nominal=0;
    unidade="";
    tensao=0;
    corrente=0;
    dt=0.001;
}

capacitor::capacitor(double cap)
{
    if (cap < 0) {
        nominal = 0;
    }
    else {
        nominal = cap;
    }
}

capacitor::capacitor(double cap, string unidade_c = "")
{
    if (unidade_c == "m" || unidade_c == "u" || unidade_c == "n" || unidade_c == "p" ||
    unidade_c == "k" || unidade_c == "K" || unidade_c == "M" || unidade_c == "G") {
        unidade = unidade_c;
    }

    if (cap < 0) {
        nominal = 0;
    }
    else {
        nominal = cap;
    }
}

capacitor::capacitor(double cap, string unidade_c = "", double deltaT = 0.001)
{
    if (unidade_c == "m" || unidade_c == "u" || unidade_c == "n" || unidade_c == "p" ||
    unidade_c == "k" || unidade_c == "K" || unidade_c == "M" || unidade_c == "G") {
        unidade = unidade_c;
    }

    if (cap < 0) {
       nominal = 0;
    }
    else {
        nominal = cap;
    }

    if ((deltaT > 0) || (deltaT == 0)) {
        dt = deltaT;
    }
}

string capacitor::get_unidade(void) {
    return unidade;
}

string capacitor::get_unidade_fisica(void) {
    return "Farads";
}

double capacitor::get_C_sem_unidade(void) {
    return nominal;
}

double capacitor::get_C_com_unidade(void) {
    if (unidade == "m") {
        return (nominal * 0.001);
    }
    else if (unidade == "u") {
        return (nominal * 0.000001);
    }
    else if (unidade == "n") {
        return (nominal * 0.000000001);
    }
    else if (unidade == "p") {
        return (nominal * 0.000000000001);
    }
    else if (unidade == "k" || unidade == "K") {
        return (nominal * 1000);
    }
    else if (unidade == "M") {
        return (nominal * 1000000);
    }
    else if (unidade == "G") {
        return (nominal * 1000000000);
    }
    else {
        return nominal;
    }
}

double capacitor::get_deltaT(void) {
    return dt;
}

bool capacitor::set_C(double cap) {
    if (cap < 0) {
        return false;
    }
    nominal = cap;
    return true;
}

bool capacitor::set_C(double cap, string unidade_c) {
    if (cap < 0) {
        return false;
    }

    if (unidade_c == "m" || unidade_c == "u" || unidade_c == "n" || unidade_c == "p" ||
    unidade_c == "k" || unidade_c == "K" || unidade_c == "M" || unidade_c == "G") {
        unidade = unidade_c;
    }

    nominal = cap;
}

bool capacitor::set_I(double i)
{
    if(i < 0) {
        return false;
    }
    corrente = i;
    return true;
}

bool capacitor::set_V(double v)
{
    if(v < 0) {
        return false;
    }
    tensao = v;
    return true;
}

void capacitor::set_Ic(double vc)
{
    corrente = (get_C_com_unidade() / dt) * (vc - tensao);
    tensao = vc;
}

void capacitor::set_Vc(double ic)
{
    corrente = ic;
    tensao = ((corrente * dt) / get_C_com_unidade()) + tensao;
}

capacitor capacitor::operator+(capacitor &outro_C) {
    capacitor ceq;     //!< capacitor equivalente da associação em série
    ceq.nominal = (get_C_com_unidade() * outro_C.get_C_com_unidade()) / (get_C_com_unidade() + outro_C.get_C_com_unidade());
    return ceq;
}

capacitor capacitor::operator/(capacitor &outro_C) {
    capacitor ceq;     //!< capacitor equivalente da associação em paralelo
    ceq.nominal = get_C_com_unidade() + outro_C.get_C_com_unidade();
    return ceq;
}

ostream& operator << (ostream &saida, capacitor &c1) {
    saida.precision(10);
    saida << fixed << c1.get_C_com_unidade() << " " << c1.get_unidade_fisica();
    return saida;
}
