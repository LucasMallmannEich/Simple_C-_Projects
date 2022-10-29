#ifndef QUADRADINHO_HPP_INCLUDED
#define QUADRADINHO_HPP_INCLUDED

class quadradinho
{
    public:
        quadradinho();  // método construtor padrão;
        quadradinho(int n_quadradinho);  // método construtor com a posição do quadradinho;
        int cavar(void);  // retorna o quadradinho que foi cavado;

    private:
        int num_quadradinho;  // posição do tabuleiro em que o quadradinho está localizada;
};

#endif // QUADRADINHO_HPP_INCLUDED
