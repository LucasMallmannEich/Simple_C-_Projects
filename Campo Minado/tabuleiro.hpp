#ifndef TABULEIRO_HPP_INCLUDED
#define TABULEIRO_HPP_INCLUDED

class tabuleiro
{
    public:
        tabuleiro();  // método construtor padrão;
        tabuleiro(int quadradinhos);  // construtor com o número de quadradinhos;
        tabuleiro(int quadradinhos, int n_bombas);  // construtor com quadradinhos e bombas;
        bool set_num_bombas(int n_bombas);  // setar o número de bombas;
        int get_num_bombas(void);  // pegar o número de bombas;
        bool set_num_quadradinhos(int n_quadradinhos);  // setar o número de quadradinhos;
        int get_num_quadradinhos(void);  // pegar o número de quadradinhos;
        bool num_bombas(int dific);  // número de bombas de acordo com dificuldade;

    private:
        int numero_quadradinhos;  // número de quadradinhos do tabuleiro;
        int dificuldade;  // nível de dificuldade do jogo;
        int numero_bombas;  // número de bombas no tabuleiro;
};

#endif // TABULEIRO_HPP_INCLUDED
