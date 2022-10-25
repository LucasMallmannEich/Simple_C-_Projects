#include "diodo.hpp"

//! Construtor padrão - incializa todas as variaveis com 0 ou vazio
diodo::diodo() {
    vd = 0.7;
    Imax = 1;
}

diodo::diodo(double v) {
    if(v > 0) {
        vd = v;
    }
    else {
        vd = 0.7;
    }
}

diodo::diodo(double v, double imax) {
    if(v > 0) {
        vd = v;
    }
    else {
        vd = 0.7;
    }
    if(imax > 0) {
        Imax = imax;
    }
    else {
        Imax = 1;
    }
}

bool diodo::set_vd(double v) {
    if(v > 0) {
        vd = v;
        return true;
    }
    return false;
}

bool diodo::set_Imax(double imax) {
    if(imax > 0) {
        Imax = imax;
        return true;
    }
    return false;
}

double diodo::get_vd(void) {
    return vd;
}

double diodo::get_Imax(void) {
    return Imax;
}
