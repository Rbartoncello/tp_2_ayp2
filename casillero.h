#ifndef TP2_CASILLERO_H
#define TP2_CASILLERO_H

#include "iostream"
#include <string>
#include "colors.h"


class Casillero{
    private:
        char tipo_terreno;
        int pos_x;
        int pos_y;

    public:
        Casillero(char tipo_terreno, int pos_x, int pos_y);
        
        Casillero();
        
        ~Casillero();

        virtual void mostrar() = 0;

        char devolver_tipo_terreno();

        void modificar_tipo_terreno(char tipo_terreno);

        void modificar_pos_x(int x);

        void modificar_pos_y(int y);

        int consultar_coordenada();
};


#endif //TP2_CASILLERO_H