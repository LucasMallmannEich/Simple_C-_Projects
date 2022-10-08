#include "fonte_ac.hpp"
#include <math.h>

#define PI 3.1415

//! Construtor padrão - incializa todas as variaveis com valores padrões.
fonte_ac::fonte_ac()
{
    nominal = 0;
    freq = 1000;
    freq_min = 0;
    freq_max = 10000000;
    tensao = 0;
    vrms = 0;
    tensao=0;
    corrente=0;
    dt=0.001;
}

fonte_ac::fonte_ac(double vpp) {
    if(vpp > 0) {
        nominal = vpp;
    }
    else {
        nominal = 0;
    }
    freq = 1000;
    freq_min = 0;
    freq_max = 10000000;
    tensao = 0;
    vrms = nominal / (1,414213);
    corrente=0;
    dt=0.001;
}

fonte_ac::fonte_ac(double vpp, double f) {
    if(vpp > 0) {
        nominal = vpp;
    }
    else {
        nominal = 0;
    }
    if (f > 0) {
        freq = f;
    }
    else {
        freq = 1000;
    }
    freq_min = 0;
    freq_max = freq * 2;
    tensao = 0;
    vrms = nominal / (1,414213);
    corrente=0;
    dt=0.001;
}

double fonte_ac::get_freq() {
    return freq;
}

double fonte_ac::get_freq_min() {
    return freq_min;
}

double fonte_ac::get_freq_max() {
    return freq_max;
}

double fonte_ac::get_deltaT() {
    return dt;
}

bool fonte_ac::set_freq(double f) {
    if((f > freq_max) || (f < freq_min)) {
        return false;
    }
    freq = f;
    return true;
}

bool fonte_ac::set_deltaT(double tempo) {
    if (tempo > 0) {
        dt=tempo;
        return true;
    }
    return false;
}

bool fonte_ac::set_freq_min(double fmin) {
    if (fmin > freq) {
        return false;
    }
    freq_min = fmin;
    return true;
}

bool fonte_ac::set_freq_max(double fmax) {
    if (fmax < freq) {
        return false;
    }
    freq_max = fmax;
    return true;
}

void fonte_ac::calculo_tensao(double seg) {
    // v(t) = vpp . sen (2pi . f . t)
    if(seg > 0) {
        tensao = nominal * (sin(2*PI*freq*seg));
    }
}
