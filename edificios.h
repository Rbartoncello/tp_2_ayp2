#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <string>
#include "Edificio.h"

using namespace std;


class Edificios{
    private:
        Edificio** edificios;
        int total_edificios;
    public:

        /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto edificios con total_edificios = 0.
         */
        Edificios();

        /*
         * Destructor:
         * PRE: -.
         * POST: Me va a descruir el objeto edificios.
         */
        ~Edificios();

        /*
         * PRE: -
         * POST: Guarda cada linea en un objeto Edificio
         */
        void procesar_archivo();

        /*
         * PRE: -
         * POST: Me muestra lista por pantalla toso los objetos del tipo Edificio.
         */
        void mostar();

        /*
         * PRE: Recibe un objeto Edificio.
         * POST: Ingresa el objeto en un vector dinámico.
         */
        void agregar_edificio(Edificio* edificio);


        Edificio* buscar_edificio_por_nombre(string nombre);
};

#endif