#ifndef CASALLERO_CONSTRUIBLE_H
#define CASALLERO_CONSTRUIBLE_H
#include "casillero.h"

class Casillero_construible : public Casillero{
    private:
        bool ocupado;
    public:
        Casillero_construible(char tipo_terreno, int pos_x, int pos_y);
        
        Casillero_construible();
        
        //~Casillero_construible();

        void mostrar();

        bool esta_ocupado();
};

#endif