#include "fonte_ac.hpp"

//! Construtor padr�o - incializa todas as variaveis com valores padr�es.
fonte_ac::fonte_ac()
{
    nominal=0;
    freq = 1000;
    freq_min = 0;
    freq_max = 1000000;
    v_minimo = -12;
    v_maximo = 12;
    vpp = 0;
    vrms = 0;
    unidade="";
    tensao=0;
    corrente=0;
    dt=0.001;
}
