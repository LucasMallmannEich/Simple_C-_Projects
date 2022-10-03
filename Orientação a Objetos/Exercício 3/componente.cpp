#include "componente.hpp"

//! Construtor padrão - incializa todas as variaveis com 0 ou vazio
componente::componente()
{
    nominal=0;
    unidade="";
    tensao=0;
    corrente=0;
    dt=0.001;
}

double componente::get_V(void)
{
    return tensao;
}

double componente::get_I(void)
{
    return corrente;
}
