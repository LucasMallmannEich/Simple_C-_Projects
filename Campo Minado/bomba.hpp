#ifndef BOMBA_HPP_INCLUDED
#define BOMBA_HPP_INCLUDED

class bomba
{
    public:
        bomba();  // m�todo construtor padr�o;
        bomba(int n_quadradinho);  // m�todo construtor com a posi��o do bomba;
        double get_n_quadradinho(void);  // retorna a posi��o da bomba;
        bool set_n_quadradinho(double n_quadradinho);  // altera o valor da posi��o da bomba;
        void explosao(void);  // usu�rio perdeu o jogo;

    private:
        int num_quadradinho;  // posi��o do tabuleiro em que a bomba est� localizada;
};

#endif // BOMBA_HPP_INCLUDED
