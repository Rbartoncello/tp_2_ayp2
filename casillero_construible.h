#ifndef CASALLERO_CONSTRUIBLE_H
#define CASALLERO_CONSTRUIBLE_H
#include "casillero.h"
#include "edificio.h"

class Casillero_construible : public Casillero{
    private:
        Edificio* edificio;
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

        void agregar_edificio(Edificio* edificio);

        void quitar_edificio();

        string devolver_nombre_edificio();

        Edificio* devolver_edificio();

        void mostrar_casillero();

        void imprimir_resumen();

        virtual void agregar_material(string nombre_material){};
};

#endif