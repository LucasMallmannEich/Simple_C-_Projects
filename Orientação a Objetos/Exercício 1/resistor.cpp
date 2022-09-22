#include "resistor.hpp"

//! Construtor padrão - incializa todas as variaveis com 0 ou vazio
resistor::resistor()
{
    nominal=0;
    unidade="";
    tensao=0;
    corrente=0;
    dt=0.001;
}

resistor::resistor(double res)
{
    if(res < 0) {
        res = 0;
    }
    else {
        nominal = res;
    }
}

resistor::resistor(double res, string unidade_r = "")
{
    if (unidade_r == "m" || unidade_r == "u" || unidade_r == "n" || unidade_r == "p" ||
    unidade_r == "k" || unidade_r == "K" || unidade_r == "M" || unidade_r == "G") {
        unidade = unidade_r;
    }

    if(res < 0) {
        res = 0;
    }
    else {
        nominal = res;
    }
}

string resistor::get_unidade(void) {
    return unidade;
}

double resistor::get_R_sem_unidade(void) {
    return nominal;
}

double resistor::get_R_com_unidade(void) {
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

bool resistor::set_R(double r) {
    if (r < 0) {
        return false;
    }
    nominal = r;
    return true;
}

bool resistor::set_R(double r, string unidade_r) {
    if (r < 0) {
        return false;
    }

    if (unidade_r == "m" || unidade_r == "u" || unidade_r == "n" || unidade_r == "p" ||
    unidade_r == "k" || unidade_r == "K" || unidade_r == "M" || unidade_r == "G") {
        unidade = unidade_r;
    }

    nominal = r;
    return true;
}

bool resistor::set_I(double v)
{
    if(v < 0) {
        return false;
    }
    corrente = v / get_R_com_unidade();
    return true;
}

bool resistor::set_V(double i)
{
    if(i < 0) {
        return false;
    }
    tensao = i * get_R_com_unidade();
    return true;
}
