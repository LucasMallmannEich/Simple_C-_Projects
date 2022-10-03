#include "fonteV.hpp"


//! Construtor padrão - incializa todas as variaveis com 0 ou vazio
fonteV::fonteV()
{
    nominal=0;
    v_minimo = -12;
    v_maximo = 12;
    unidade="";
    tensao=0;
    corrente=0;
    dt=0.001;
}

fonteV::fonteV(double fv)
{
    nominal = fv;
}

fonteV::fonteV(double vmin, double vmax, double fv) {
    if((vmin < vmax || vmin == vmax) && (vmin < fv || vmin == fv)) {
        v_minimo = vmin;
    }
    if((vmax > vmin || vmax == vmin) && (vmax > fv || vmax == fv)) {
        v_maximo = vmax;
    }
    if((fv > vmin || fv == vmin) && (fv < vmax || fv == vmax)) {
        nominal = fv;
    }
}

string fonteV::get_unidade_fisica(void) {
    return "Volts";
}

double fonteV::get_fv(void) {
    return nominal;
}

double fonteV::get_fvmin(void) {
    return v_minimo;
}

double fonteV::get_fvmax(void) {
    return v_maximo;
}

bool fonteV::set_fv(double fv) {
    if (fv < v_minimo || fv > v_maximo) {
        return false;
    }
    nominal = fv;
    return true;
}

bool fonteV::set_fvmin(double vmin) {
    if (vmin > nominal || vmin > v_maximo) {
        return false;
    }
    v_minimo = vmin;
    return true;
}

bool fonteV::set_fvmax(double vmax) {
    if (vmax < v_minimo || vmax < nominal) {
        return false;
    }
    v_maximo = vmax;
    return true;
}
