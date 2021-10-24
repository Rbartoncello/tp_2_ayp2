//
// Created by juan on 24/10/21.
//

#ifndef TP_2_AYP2_CASILLERO_NO_TRANSITABLE_H
#define TP_2_AYP2_CASILLERO_NO_TRANSITABLE_H


#include "casillero.h"

class Casillero_no_transitable : public Casillero {
public:
    Casillero_no_transitable(char tipo_terreno, int pos_x, int pos_y);

    Casillero_no_transitable();

    ~Casillero_no_transitable();

    void mostrar();

};


#endif //TP_2_AYP2_CASILLERO_NO_TRANSITABLE_H
