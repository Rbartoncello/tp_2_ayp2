#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include <string>
#include "edificio.h"

using namespace std;

const string EDIFICIO_MINA = "mina";
const string EDIFICIO_ASERRADERO = "aserradero";
const string EDIFICIO_FABRICA = "fabrica";
const string EDIFICIO_ESCUELA = "escuela";
const string EDIFICIO_OBELISCO = "obelisco";
const string EDIFICIO_PLANTA_ELECTRICA = "planta_electrica";

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

        Edificio* buscar_edificio_por_nombre(string nombre);

        int devolver_total_edificios();

        string devolver_nombre_edificio(int indice);

        private:

        /*
         * PRE: Recibe un objeto Edificio.
         * POST: Ingresa el objeto en un vector dinámico.
         */
        void agregar_edificio(Edificio* edificio);

        string buscar_tipo_emoji(string nombre_edificio); 
};

#endif