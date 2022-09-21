#ifndef COMPONENTE_HPP_INCLUDED
#define COMPONENTE_HPP_INCLUDED

#include <string>

using namespace std;

class componente
{
    public:
        componente();
        double get_V(void);     //!< valor atual da tensão
        double get_I(void);     //!< valor atual da corrente

    protected:
        double nominal;
        string unidade;
        double tensao;       //!< Tensao presente nos terminais
        double corrente;    //!< corrente circulando pelo componente
        double dt;          //!< passo de tempo da simulação

    private:
};

#endif // COMPONENTE_HPP_INCLUDED
