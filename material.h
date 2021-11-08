#ifndef TP_2_AYP2_MATERIAL_H
#define TP_2_AYP2_MATERIAL_H
#include "constantes.h"
#include <string>

using namespace std;

class Material{
    private:
        string nombre_material;
        string emoji;
        int cantidad_material;
    public:
        /*
        * Constructor:
        * Pre: -.
        * Post: Me va a crear el objeto Material.
        */
        Material(string nombre_material, int cantidad_material);

        /*
        * Constructor:
        * Pre: -.
        * Post: Me va a crear el objeto Material con nombre_material "NULL", emoji = "NULL" y cantidad = 0.
        */
        Material();

        /*
        * Pre: -.
        * Post: Me va agregar un emoji en el atributo emoji dependiendo si es piedra, madera o metal.
        */

        string agregar_emoji(string nombre_matertial);

        /*
        * Pre: -
        * Post: Me muestra por pantalla el objeto tipo Material.
        */
        void mostrar();

        /*
        * Pre: -
        * Post: Me devuelve el nombre_material.
        */
        string devolver_nombre_material();

        /*
        * Pre: -
        * Post: Me devuelve el emoji.
        */
        string devolver_emoji();

        /*
        * Pre: -
        * Post: Me devuelve el cantidad_material.
        */
        int devolver_cantidad_material();
        
        /*
         * Pre: Recibe un numero positivo o negativo()
         * Post: "Suma" ese numero a la cantidad del material 
        */
        void sumar_restar(int cantidad);

        /*
         * Pre: -
         * Post: Imprime un resumen escrito del material
        */
        void imprimir_resumen();
        
        /*
         * Pre: Recibe un emoji
         * Post: Cambia el emoji del material
        */
        void modificar_emoji(string emoji);
};


#endif //TP_2_AYP2_MATERIAL_H
