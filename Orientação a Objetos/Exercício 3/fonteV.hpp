#ifndef FONTEV_HPP_INCLUDED
#define FONTEV_HPP_INCLUDED

#include "componente.hpp"

class fonteV : public componente
{
    public:
        fonteV();
        fonteV(double fv);
        fonteV(double vmin, double vmax, double fv);
        string get_unidade_fisica(void);     //!< unidade física
        double get_fv(void);
        double get_fvmin(void);
        double get_fvmax(void);
        bool set_fv(double fv);
        bool set_fvmin(double vmin);
        bool set_fvmax(double vmax);

    protected:
        double v_minimo;
        double v_maximo;
};

#endif // FONTEV_HPP_INCLUDED
