#ifndef TP2_CASILLERO_H
#define TP2_CASILLERO_H

#include "iostream"
#include <string>

const char LAGO = 'L';
const char TERRENO = 'T';
const char CAMINO = 'C';

class Casillero{
    private:
        char tipo_terreno;
        int pos_x;
        int pos_y;

    public:
        Casillero(char tipo_terreno, int pos_x, int pos_y);
        Casillero();
        ~Casillero();

        void mostar_letra();

        char devolver_tipo_terreno();

        void modificar_tipo_terreno(char tipo_terreno);

        void modificar_pos_x(int x);

        void modificar_pos_y(int y);

        int consultar_coordenada();
};


#endif //TP2_CASILLERO_H