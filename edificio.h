
#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <string>

using namespace std;

class Edificio {
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
        Edificio(string nombre_edificio, string emoji, int piedra, int madera, int metal, int   maxima_cantidad_permitidos);

        //~Edificio();

        /*
         * PRE: -
         * POST: Me muestra por pantalla el objeto tipo Edificio.
         */
        void mostrar();

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

        int devolver_cantidad_material(string material);

        /*
         * PRE: -
         * POST: Me devuelve el maxima_cantidad_permitidos.
         */
        int devolver_maxima_cantidad_permitidos();

};

#endif //TP_2_AYP2_EDIFICIO_H
