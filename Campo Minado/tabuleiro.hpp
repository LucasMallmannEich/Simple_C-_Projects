#ifndef TABULEIRO_HPP_INCLUDED
#define TABULEIRO_HPP_INCLUDED

class tabuleiro
{
    public:
        tabuleiro();  // método construtor padrão;
        tabuleiro(int quadradinhos);  // construtor com o número de quadradinhos;
        tabuleiro(int quadradinhos, int n_bombas);
        bool set_num_bombas(int n_bombas);
        int get_num_bombas(void);

    private:
        int numero_quadradinhos;  // número de quadradinhos do tabuleiro;
        int dificuldade;  // nível de dificuldade do jogo;
        int numero_bombas;  // número de bombas no tabuleiro;
};

#endif // TABULEIRO_HPP_INCLUDED
