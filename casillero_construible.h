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
         * Pre: -.
         * Post: Me va a crear el objeto Casillero.
         */
        Casillero_construible(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0, pos_y = 0 y this->ocupado = false.
         */
        Casillero_construible();

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
         * Pre: Recibe un puntero a edificio
         * Post: Guarda el Edficio en atributo edificio
        */
        void agregar_edificio(Edificio* edificio);

        /*
         * Pre: -
         * Post: Guarda nullptr en el atributo edificio y guarda false en ocupado
        */
        void quitar_edificio();

        /*
         * Pre: Tiene que haber un edificio en el casillero
         * Post: Devuelve el nombre del edificio
        */
        string devolver_nombre_edificio();

        /*
         * Pre: Tiene que haber un edificio en el casillero
         * Post: Devuelve el edificio
        */
        Edificio* devolver_edificio();

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
         * Post: Metodo vacio para la clase casillero_transitable
        */
        void agregar_material(string nombre_material){};

        /*
         * Pre: -
         * Post: Metodo vacio para la clase casillero_transitable
        */
        string devolver_nombre_material(){return nullptr;};
};

#endif