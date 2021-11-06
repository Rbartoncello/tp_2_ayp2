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
         * Pre: -.
         * Post: Me va a crear el objeto Casillero.
         */
        Casillero_transitable(char tipo_terreno, int pos_x, int pos_y);

        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_transitable();

        /*
         * Pre: -
         * Post: De devuleve TRUE si esta ocupado y FALSE en caso contrario.
         */
        bool esta_ocupado();

        /*
         * Pre: -
         * Post: Me muestra por pantalla.
         */
        void mostrar();
        
        /*
         * Pre: -
         * Post: Metodo vacio para la clase casillero_construible
        */
        void agregar_edificio(Edificio* edificio){};

        /*
         * Pre: -
         * Post: Metodo vacio para la clase casillero_construible
        */
        void quitar_edificio(){};

        /*
         * Pre: -
         * Post: Metodo vacio para la clase casillero_construible
        */
        string devolver_nombre_edificio(){return nullptr;};
        
        /*
         * Pre: -
         * Post: Metodo vacio para la clase casillero_construible
        */
        Edificio* devolver_edificio(){return nullptr;};
        
        /*
         * Pre: -
         * Post: Muestra graficamente el casillero
        */
        void mostrar_casillero();

        /*
         * Pre: -
         * Post: Imprime un resumen escrito del casillero
        */
        void imprimir_resumen();

        /*
         * Pre: Recibe un nombre para el nuevo material
         * Post: Crea un material con ese nombre y lo guarda en el atributo material
        */
        void agregar_material(string nombre_material);

        /*
         * Pre: Hay un material en esta posicion
         * Post: Devuelve un material
        */
        string devolver_nombre_material();

        /*
         * Pre: -
         * Post: Me devuelve material
         */
        Material* devolver_material();
};

#endif //CASILLERO_TRANSITABLE_H