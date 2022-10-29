#ifndef BANDEIRA_HPP_INCLUDED
#define BANDEIRA_HPP_INCLUDED

class bandeira
{
    public:
        bandeira();  // método construtor padrão;
        bandeira(int n_quadradinho);  // método construtor com a posição da bandeira;

    private:
        int num_quadradinho;  // posição do tabuleiro em que a bandeira está localizada;
};

#endif // BANDEIRA_HPP_INCLUDED
