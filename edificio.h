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
         * Pre: -.
         * Post: Me va a crear el objeto edificio.
         */
        Edificio(string nombre_edificio, string emoji, int piedra, int madera, int metal, int   maxima_cantidad_permitidos);

        /*
         * Pre: -
         * Post: Me muestra por pantalla el objeto tipo Edificio.
         */
        void mostrar();

        /*
         * Pre: -
         * Post: Me devuelve el nombre_edificio.
         */
        string devolver_nombre_edificio();

        /*
        * Pre: -
        * Post: Me devuelve el emoji.
        */
        string devolver_emoji();

        /*
         * Pre: -
         * Post: Me devuelve el piedra.
         */
        int devolver_piedra();

        /*
         * Pre: -
         * Post: Me devuelve el madera.
         */
        int devolver_madera();

        /*
         * Pre: -
         * Post: Me devuelve el metal.
         */
        int devolver_metal();

        /*
         * Pre: Recibe un nombre de un material
         * Post: Devuelve la cantidad de ese material que necesita el edificio para construirse
        */
        int devolver_cantidad_material(string material);

        /*
         * Pre: -
         * Post: Me devuelve el maxima_cantidad_permitidos.
         */
        int devolver_maxima_cantidad_permitidos();
        
        /*
         * Pre: -
         * Post: Imprime un resumen escrito del edificio.
        */
        void imprimir_resumen();

};

#endif //EDIFICIO_H
