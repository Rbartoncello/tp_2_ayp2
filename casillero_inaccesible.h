#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H
#include "casillero.h"

class Casillero_inaccesible : public Casillero {
public:
    Casillero_inaccesible(char tipo_terreno, int pos_x, int pos_y);

    Casillero_inaccesible();

    //~Casillero_inaccesible();

    void mostrar();

};


#endif //TP_2_AYP2_Casillero_inaccesible_H
