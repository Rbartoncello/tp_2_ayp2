#ifndef CASILLERO_TRANSITABLE_H
#define CASILLERO__RANSITABLEH

#include "iostream"
#include <string>
#include "casillero.h"



class Casillero_transitable : public Casillero{
    private:
        bool ocupado;
        Material* material;
    public:
        /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto Casillero.
         */
        Casillero_transitable(char tipo_terreno, int pos_x, int pos_y);

        /*
         * Constructor sin parametros:
         * PRE: -.
         * POST: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_transitable();

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

        void agregar_edificio(Edificio* edificio){};

        void quitar_edificio(){};

        string devolver_nombre_edificio(){return nullptr;};

        Edificio* devolver_edificio(){return nullptr;};

        void mostrar_casillero();

        void imprimir_resumen();
};

#endif //CASILLERO_TRANSITABLE_H