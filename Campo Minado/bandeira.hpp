#ifndef BANDEIRA_HPP_INCLUDED
#define BANDEIRA_HPP_INCLUDED

class bandeira
{
    public:
        bandeira();  // m�todo construtor padr�o;
        bandeira(int n_quadradinho);  // m�todo construtor com a posi��o da bandeira;

    private:
        int num_quadradinho;  // posi��o do tabuleiro em que a bandeira est� localizada;
};

#endif // BANDEIRA_HPP_INCLUDED
