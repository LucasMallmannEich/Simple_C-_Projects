#include <iostream>
#include "bomba.hpp"
using namespace std;

bomba::bomba()
{
    num_quadradinho = 0;
}

bomba::bomba(int n_quadradinho)
{
    if(n_quadradinho > 0){
        num_quadradinho = n_quadradinho;
    }
}

double bomba::get_n_quadradinho(void)
{
    return num_quadradinho;
}

bool bomba::set_n_quadradinho(double n_quadradinho)
{
    if(n_quadradinho > 0) {
        num_quadradinho = n_quadradinho;
        return true;
    }
    return false;
}

void bomba::explosao(void)
{
    cout << "GAME OVER!" << endl;
}
