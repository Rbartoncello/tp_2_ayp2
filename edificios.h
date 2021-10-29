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
         * Pre: -.
         * Post: Me va a crear el objeto edificios con total_edificios = 0.
         */
        Edificios();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a descruir el objeto edificios.
         */
        ~Edificios();

        /*
         * Pre: -
         * Post: Guarda cada linea en un objeto Edificio
         */
        void procesar_archivo();

        /*
         * Pre: -
         * Post: Me muestra lista por pantalla toso los objetos del tipo Edificio.
         */
        void mostar();

        /*
         * Pre: Recibe un string (tiene que haber un edificio con el mismo nombre)
         * Post: Busca un edificio con tal nombre y lo devuelve
        */
        Edificio* buscar_edificio_por_nombre(string nombre);

        /*
         * Pre: recibe un string
         * Post: devuelve true si existe un edificio con ese nombre
        */
        bool existe_edificio_por_nombre(string nombre);
        
        private:

        /*
         * Pre: Recibe un objeto Edificio.
         * Post: Ingresa el objeto en un vector dinámico.
         */
        void agregar_edificio(Edificio* edificio);

        /*
         * Pre: Recibe un nombre existente
         * Post: devuelve el emoji de ese edificio
        */
        string buscar_tipo_emoji(string nombre_edificio); 

        
};

#endif