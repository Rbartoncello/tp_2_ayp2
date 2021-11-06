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
         * Pre: -.
         * Post: Me va a crear el objeto Casillero.
         */
        Casillero(char tipo_terreno, int pos_x, int pos_y);
        
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Casillero con tipo_terreno = ' ',  pos_x = 0 y pos_y = 0.
         */
        Casillero();
        
        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Casillero.
         */
        virtual ~Casillero(){};

        /*
         * Pre: -
         * Post: Me muestra por pantalla.
         */
        virtual void mostrar() = 0;

        /*
         * Pre: -
         * Post: Me va devolver tipo_terreno.
         */
        char devolver_tipo_terreno();

        /*
         * Pre: -
         * Post: Me va devolver pos_x.
         */
        int devolver_pos_x();

        /*
         * Pre: -
         * Post: Me va devolver pos_y.
         */
        int devolver_pos_y();

        /*
         * Pre: -
         * Post: Me va modificar tipo_terreno.
         */
        void modificar_tipo_terreno(char tipo_terreno);

        /*
         * Pre: -
         * Post: Me va modificar pos_x.
         */
        void modificar_pos_x(int x);

        /*
         * Pre: -
         * Post: Me va modificar pos_y.
         */
        void modificar_pos_y(int y);
        
        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_construible
        */
        virtual void agregar_edificio(Edificio* edificio){};
        
        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_construible
        */
        virtual void quitar_edificio(){};
        
        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_construible
        */
        virtual string devolver_nombre_edificio(){return nullptr;};
        
        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_construible
        */
        virtual Edificio* devolver_edificio(){return nullptr;};
        
        /*
         * Pre: -
         * Post: Metodo virtual vacio para las clases hijas
        */
        virtual bool esta_ocupado() = 0;
        
        /*
         * Pre: -
         * Post: Metodo virtual vacio para las clases hijas
        */
        virtual void mostrar_casillero() = 0;
        
        /*
         * Pre: -
         * Post: Metodo virtual vacio para las clases hijas
        */
        virtual void imprimir_resumen(){};
        
        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_transitable
        */
        virtual void agregar_material(string nombre_material){};

        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_transferible
        */
        virtual string devolver_nombre_material(){return nullptr;};


        /*
         * Pre: -
         * Post: Metodo virtual vacio para la clase casillero_transferible
        */
        virtual Material* devolver_material(){return nullptr;};
};


#endif //CASILLERO_H
