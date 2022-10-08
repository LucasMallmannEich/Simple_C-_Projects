#ifndef DIODO_HPP_INCLUDED
#define DIODO_HPP_INCLUDED

#include "componente.hpp"

class diodo : public componente {
    public:
        diodo();
        diodo(double v);
        diodo(double v, double imax);
        bool set_vd(double v);
        bool set_Imax(double imax);
        double get_vd(void);
        double get_Imax(void);

    protected:
        double Imax;
        double vd;
};

#endif // DIODO_HPP_INCLUDED
