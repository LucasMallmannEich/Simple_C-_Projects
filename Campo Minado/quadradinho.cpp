#include "quadradinho.hpp"

quadradinho:quadradinho()
{
    num_quadradinho = 0;
}

quadradinho:quadradinho(int n_quadradinho)
{
    if(n_quadradinho > 0){
        num_quadradinho = n_quadradinho;
    }
}
