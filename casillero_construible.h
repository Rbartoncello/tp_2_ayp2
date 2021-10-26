#ifndef CASALLERO_CONSTRUIBLE_H
#define CASALLERO_CONSTRUIBLE_H
#include "casillero.h"
#include "edificios.h"

class Casillero_construible : public Casillero{
    private:
        bool ocupado;
    public:
        /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto Casillero.
         */
        Casillero_construible(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parametros:
         * PRE: -.
         * POST: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_construible();

        /*
         * PRE: -
         * POST: De devuleve TRUE si esta ocupado y FALSE en caso contrario.
         */
        bool esta_ocupado();

        /*
         * PRE: -
         * POST: Me muestra por pantalla.
         */
        void mostrar();
};

#endif