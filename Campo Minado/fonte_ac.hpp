#ifndef FONTE_AC_HPP_INCLUDED
#define FONTE_AC_HPP_INCLUDED

#include "fonteV.hpp"
// v(t) = vpp . sen (2pi . f . t)
class fonte_ac : public fonteV
{
    public:
        fonte_ac();
        fonte_ac(double vpp);
        fonte_ac(double vpp, double f);
        double get_freq(void);
        double get_freq_min(void);
        double get_freq_max(void);
        double get_deltaT(void);
        bool set_freq(double f);
        bool set_deltaT(double tempo);
        bool set_freq_min(double fmin);
        bool set_freq_max(double fmax);
        void calculo_tensao(double seg);

    protected:
        double freq;
        double freq_min;
        double freq_max;
        double vrms;
};

#endif // FONTE_AC_HPP_INCLUDED
