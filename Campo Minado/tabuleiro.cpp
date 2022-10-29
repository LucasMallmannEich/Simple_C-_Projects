#include "tabuleiro.hpp"

#include <string>
using namespace std;

tabuleiro::tabuleiro()
{
    numero_quadradinhos = 64;
}

tabuleiro::tabuleiro(int quadradinhos)
{
    if(quadradinhos > 0){
        numero_quadradinhos = quadradinhos;
    }
    else{
        numero_quadradinhos = 64;
    }
}

tabuleiro::tabuleiro(int quadradinhos, int n_bombas)
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

bool tabuleiro::set_num_bombas(int n_bombas)
{
    if (n_bombas < 0) {
        return false;
    }
    if (n_bombas > numero_quadradinhos) {
        return false;
    }
    else {
        numero_bombas = n_bombas;
        return true;
    }
}

int tabuleiro::get_num_bombas(void)
{
    return numero_bombas;
}

bool tabuleiro::set_num_quadradinhos(int n_quadradinhos)
{
    if (n_quadradinhos > numero_bombas && n_quadradinhos > 0) {
        numero_quadradinhos = n_quadradinhos;
        return true;
    }
    return false;
}

int tabuleiro::get_num_quadradinhos(void)
{
    return numero_quadradinhos;
}

bool tabuleiro::num_bombas(int dific)
{
    if(dific == 1) {
        numero_bombas = numero_quadradinhos/10;
        dificuldade = 1;
        return true;
    }
    if(dific == 2) {
        numero_bombas = numero_quadradinhos/7.5;
        dificuldade = 2;
        return true;
    }
    if(dific == 3) {
        numero_bombas = numero_quadradinhos/5;
        dificuldade = 3;
        return true;
    }
    return false;
}
