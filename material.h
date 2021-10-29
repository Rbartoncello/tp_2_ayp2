#ifndef TP_2_AYP2_MATERIAL_H
#define TP_2_AYP2_MATERIAL_H
#include <string>

using namespace std;

class Material{
    private:
        string nombre_material;
        int cantidad_material;
    public:
        /*
        * Constructor:
        * PRE: -.
        * POST: Me va a crear el objeto Material.
        */
        Material(string nombre_material, int cantidad_material);

        //~Material();

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
        * POST: Me devuelve el cantidad_material.
        */
        int devolver_cantidad_material();

        void sumar_restar(int cantidad);
};


#endif //TP_2_AYP2_MATERIAL_H
