#ifndef BOMBA_HPP_INCLUDED
#define BOMBA_HPP_INCLUDED

class bomba
{
    public:
        bomba();  // método construtor padrão;
        bomba(int n_quadradinho);  // método construtor com a posição do bomba;
        double get_n_quadradinho(void);  // retorna a posição da bomba;
        bool set_n_quadradinho(double n_quadradinho);  // altera o valor da posição da bomba;
        void explosao(void);  // usuário perdeu o jogo;

    private:
        int num_quadradinho;  // posição do tabuleiro em que a bomba está localizada;
};

#endif // BOMBA_HPP_INCLUDED
