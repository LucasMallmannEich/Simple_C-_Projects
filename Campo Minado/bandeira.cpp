#include "bandeira.hpp"

bandeira:bandeira()
{
    num_quadradinho = 0;
}

bandeira:bandeira(int n_quadradinho)
{
    if(n_quadradinho > 0){
        num_quadradinho = n_quadradinho;
    }
}
