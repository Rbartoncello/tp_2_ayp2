#ifndef CASILLERO_INACCESIBLE_H
#define CASILLERO_INACCESIBLE_H
#include "casillero.h"

class Casillero_inaccesible : public Casillero {
    private:
        bool ocupado;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero.
         */
        Casillero_inaccesible(char tipo_terreno, int pos_x, int pos_y);

        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_inaccesible();

        /*
        * Pre: -
        * Post: De devuleve TRUE si esta ocupado y FALSEen caso contrario.
        */
        bool esta_ocupado();

        /*
        * Pre: -
        * Post: Me muestra por pantalla.
        */
        void mostrar();

        /*
         * Pre: -
         * Post: -          Metodo vacio para la clase casillero_construible
        */
        void agregar_edificio(Edificio* edificio){};

        /*
         * Pre: -
         * Post: -          Metodo vacio para la clase casillero_construible
        */
        void quitar_edificio(){};
        
        /*
         * Pre: -
         * Post: -          Metodo vacio para la clase casillero_construible
        */
        string devolver_nombre_edificio(){return nullptr;};

        /*
         * Pre: -
         * Post: -          Metodo vacio para la clase casillero_construible
        */
        Edificio* devolver_edificio(){return nullptr;};

        /*
         * Pre: -
         * Post: Muestra graficamente el casillero por pantalla
        */
        void mostrar_casillero();

        /*
         * Pre: -
         * Post: Imprime un resumen escrito del casillero
        */
        void imprimir_resumen();
        
        /*
         * Pre: -
         * Post: -          Metodo vacio para la clase casillero_transitable
        */
        virtual void agregar_material(string nombre_material){};
};


#endif //TP_2_AYP2_Casillero_inaccesible_H
