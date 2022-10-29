#ifndef TABULEIRO_HPP_INCLUDED
#define TABULEIRO_HPP_INCLUDED

class tabuleiro
{
    public:
        tabuleiro();  // m�todo construtor padr�o;
        tabuleiro(int quadradinhos);  // construtor com o n�mero de quadradinhos;
        tabuleiro(int quadradinhos, int n_bombas);  // construtor com quadradinhos e bombas;
        bool set_num_bombas(int n_bombas);  // setar o n�mero de bombas;
        int get_num_bombas(void);  // pegar o n�mero de bombas;
        bool set_num_quadradinhos(int n_quadradinhos);  // setar o n�mero de quadradinhos;
        int get_num_quadradinhos(void);  // pegar o n�mero de quadradinhos;
        bool num_bombas(int dific);  // n�mero de bombas de acordo com dificuldade;

    private:
        int numero_quadradinhos;  // n�mero de quadradinhos do tabuleiro;
        int dificuldade;  // n�vel de dificuldade do jogo;
        int numero_bombas;  // n�mero de bombas no tabuleiro;
};

#endif // TABULEIRO_HPP_INCLUDED
