#ifndef CASILLERO_H
#define CASILLERO_H

#include "iostream"
#include <string>
#include "colors.h"
#include "edificio.h"
#include "material.h"

class Casillero{
    protected:
        char tipo_terreno;
    private:
        int pos_x;
        int pos_y;

    public:
        /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto Casillero.
         */
        Casillero(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parametros:
         * PRE: -.
         * POST: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0 y pos_y = 0.
         */
        Casillero();
        
        /*
         * Destructor:
         * PRE: -.
         * POST: Me va a destruir el objeto Casillero.
         */
        virtual ~Casillero(){};

        /*
         * PRE: -
         * POST: Me muestra por pantalla.
         */
        virtual void mostrar() = 0;

        /*
         * PRE: -
         * POST: Me va devolver tipo_terreno.
         */
        char devolver_tipo_terreno();

        /*
         * PRE: -
         * POST: Me va devolver pos_x.
         */
        int devolver_pos_x();

        /*
         * PRE: -
         * POST: Me va devolver pos_y.
         */
        int devolver_pos_y();

        /*
         * PRE: -
         * POST: Me va modificar tipo_terreno.
         */
        void modificar_tipo_terreno(char tipo_terreno);

        /*
         * PRE: -
         * POST: Me va modificar pos_x.
         */
        void modificar_pos_x(int x);

        /*
         * PRE: -
         * POST: Me va modificar pos_y.
         */
        void modificar_pos_y(int y);

        virtual void agregar_edificio(Edificio* edificio){};

        virtual void quitar_edificio(){};

        virtual string devolver_nombre_edificio(){return nullptr;};

        virtual Edificio* devolver_edificio(){return nullptr;};

        virtual bool esta_ocupado() = 0;

        virtual void mostrar_casillero() = 0;

        virtual void imprimir_resumen(){};
};


#endif //CASILLERO_H
