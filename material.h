#ifndef TP_2_AYP2_MATERIAL_H
#define TP_2_AYP2_MATERIAL_H
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
        * PRE: -.
        * POST: Me va a crear el objeto Material.
        */
        Material(string nombre_material, int cantidad_material);

        /*
        * Constructor:
        * PRE: -.
        * POST: Me va a crear el objeto Material con nombre_material "NULL", emoji = "NULL" y cantidad = 0.
        */
        Material();

        string agregar_emoji(string nombre_matertial);

        /*
        * PRE: -
        * POST: Me muestra por pantalla el objeto tipo Material.
        */
        void mostrar();

        /*
        * PRE: -
        * POST: Me devuelve el nombre_material.
        */
        string devolver_nombre_material();

        /*
        * PRE: -
        * POST: Me devuelve el emoji.
        */
        string devolver_emoji();

        /*
        * PRE: -
        * POST: Me devuelve el cantidad_material.
        */
        int devolver_cantidad_material();

        void sumar_restar(int cantidad);

        void imprimir_resumen();

        void aumentar_cantidad_material(int aumentar);

        void modificar_emoji(string emoji);
};


#endif //TP_2_AYP2_MATERIAL_H
