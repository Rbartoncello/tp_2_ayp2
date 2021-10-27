#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H
#include "casillero.h"

class Casillero_inaccesible : public Casillero {
    private:
        bool ocupado;
    public:
        /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto Casillero.
         */
        Casillero_inaccesible(char tipo_terreno, int pos_x, int pos_y);

        /*
         * Constructor sin parametros:
         * PRE: -.
         * POST: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_inaccesible();

        /*
        * PRE: -
        * POST: De devuleve TRUE si esta ocupado y FALSEen caso contrario.
        */
        bool esta_ocupado();

        /*
        * PRE: -
        * POST: Me muestra por pantalla.
        */
        void mostrar();

        void agregar_edificio(Edificio* edificio);

        void mostrar_casillero();
};


#endif //TP_2_AYP2_Casillero_inaccesible_H
