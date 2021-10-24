#ifndef TP2_CASILLERO_TRANSITABLE_H
#define TP2_CASILLERO__RANSITABLEH

#include "iostream"
#include <string>
#include "casillero.h"


class Casillero_transitable : public Casillero{
    private:
        bool ocupado;
        //*Material material;

    public:
        Casillero_transitable(char tipo_terreno, int pos_x, int pos_y);

        Casillero_transitable();

        bool esta_ocupado();

        //void añadir_matrial(s*Material material;

        //void eliminar_material();



};





#endif //TP2_CASILLERO_TRANSITABLE_H