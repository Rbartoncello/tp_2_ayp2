#ifndef CASALLERO_CONSTRUIBLE_H
#define CASALLERO_CONSTRUIBLE_H
#include "casillero.h"

class Casillero_contruible : public Casillero{
    private:
        bool ocupado;
    public:
        Casillero_contruible(char tipo_terreno, int pos_x, int pos_y);
        Casillero_contruible();
        ~Casillero_contruible();

        void mostrar();

        bool esta_ocupado();
};

#endif