#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <string>

using namespace std;

const string EDIFICIO_MINA = "mina";
const string EDIFICIO_ASERRADERO = "aserradero";
const string EDIFICIO_FABRICA = "fabrica";
const string EDIFICIO_ESCUELA = "escuela";
const string EDIFICIO_OBELISCO = "obelisco";
const string EDIFICIO_PLANTA_ELECTRICA = "planta_electrica";
class Edificio{
    private:
        string nombre_edificio;
        string emoji;
        int piedra;
        int madera;
        int metal;
        int maxima_cantidad_permitidos;
    public:
        /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto edificio.
         */
        Edificio(string nombre_edificio, string emoji, int piedra, int madera, int metal, int maxima_cantidad_permitidos);

        //~Edificio();

        /*
         * PRE: -
         * POST: Me muestra por pantalla el objeto tipo Edificio.
         */
        void mostar();

        /*
         * PRE: -
         * POST: Me devuelve el nombre_edificio.
         */
        string devolver_nombre_edificio();

        /*
         * PRE: -
         * POST: Me devuelve el emoji.
         */
        string devolver_emoji();

        /*
         * PRE: -
         * POST: Me devuelve el piedra.
         */
        int devolver_piedra();

        /*
         * PRE: -
         * POST: Me devuelve el madera.
         */
        int devolver_madera();

        /*
         * PRE: -
         * POST: Me devuelve el metal.
         */
        int devolver_metal();

        /*
         * PRE: -
         * POST: Me devuelve el maxima_cantidad_permitidos.
         */
        int devolver_maxima_cantidad_permitidos();
};

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

    private:

        /*
         * PRE: Recibe un objeto Edificio.
         * POST: Ingresa el objeto en un vector dinámico.
         */
        void agregar_edificio(Edificio* edificio);

        string buscar_tipo_emoji(string nombre_edificio);
};

#endif