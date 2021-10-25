#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO__RANSITABLEH

#include "iostream"
#include <string>
#include "casillero.h"


class Casillero_transitable : public Casillero{
    private:
        bool ocupado;

    public:
        Casillero_transitable(char tipo_terreno, int pos_x, int pos_y);

        Casillero_transitable();

        //~Casillero_transitable();

        bool esta_ocupado();

        void mostrar();
};

#endif //CASILLERO_TRANSITABLE_H