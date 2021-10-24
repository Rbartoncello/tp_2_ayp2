#ifndef MAPA_H
#define MAPA_H
#include "casillero.h"
#include "casillero_contruible.h"
#include "casillero_transitable.h"
#include "casillero_no_transitable.h"

const char CAMINO = 'C', TERRENO = 'T', LAGO = 'L';

class Mapa{
    private:
        int cantidad_filas;
        int cantidad_columnas;
        Casillero*** casilleros;

    public:
        Mapa();

        Mapa(int filas, int columnas);

        ~Mapa();

        void procesar_archivo();

        void mostrar();

    private:
        void agregar_casillero(Casillero** casilleros);
};



#endif