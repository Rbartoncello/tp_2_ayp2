#ifndef MAPA_H
#define MAPA_H
#include "casillero.h"

class Mapa{
    private:
        int cantidad_filas;
        int cantidad_columnas;
        Casillero** casilleros;

    public:
        Mapa();

        Mapa(int filas, int columnas);

        ~Mapa();

        void procesar_archivo();

        void mostar();

    private:
        void agregar_casillero(Casillero** casilleros);
};



#endif