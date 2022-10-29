#ifndef QUADRADINHO_HPP_INCLUDED
#define QUADRADINHO_HPP_INCLUDED

class quadradinho
{
    public:
        quadradinho();  // m�todo construtor padr�o;
        quadradinho(int n_quadradinho);  // m�todo construtor com a posi��o do quadradinho;
        int cavar(void);  // retorna o quadradinho que foi cavado;

    private:
        int num_quadradinho;  // posi��o do tabuleiro em que o quadradinho est� localizada;
};

#endif // QUADRADINHO_HPP_INCLUDED
