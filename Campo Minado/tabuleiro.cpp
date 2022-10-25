#include "tabuleiro.hpp"

tabuleiro:tabuleiro()
{
    numero_quadradinhos = 64;
}

tabuleiro:tabuleiro(int quadradinhos)
{
    if(quadradinhos > 0){
        numero_quadradinhos = quadradinhos;
    }
    else{
        numero_quadradinhos = 64;
    }
}

tabuleiro:tabuleiro(int quadradinhos, int n_bombas)
{
    if(quadradinhos > 0){
        numero_quadradinhos = quadradinhos;
    }
    else{
        numero_quadradinhos = 64;
    }
    if((n_bombas > 0) && (n_bombas < numero_quadradinhos)){
        numero_bombas = n_bombas;
    }
    else {
        numero_bombas = 0;
    }
}
