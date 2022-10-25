#ifndef TABULEIRO_HPP_INCLUDED
#define TABULEIRO_HPP_INCLUDED

class tabuleiro
{
    public:
        tabuleiro();  // m�todo construtor padr�o;
        tabuleiro(int quadradinhos);  // construtor com o n�mero de quadradinhos;
        tabuleiro(int quadradinhos, int n_bombas);
        bool set_num_bombas(int n_bombas);
        int get_num_bombas(void);

    private:
        int numero_quadradinhos;  // n�mero de quadradinhos do tabuleiro;
        int dificuldade;  // n�vel de dificuldade do jogo;
        int numero_bombas;  // n�mero de bombas no tabuleiro;
};

#endif // TABULEIRO_HPP_INCLUDED
