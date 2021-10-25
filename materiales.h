#ifndef Material_H
#define Material_H
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
        void mostar();

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
};

class Materiales{
    private:
        Material** materiales;
        int total_materiales;
    public:

        /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto Materiales con total_materiales = 0.
         */
        Materiales();

        /*
         * Destructor:
         * PRE: -.
         * POST: Me va a descruir el objeto Materiales.
         */
        ~Materiales();

        /*
         * PRE: -
         * POST: Guarda cada linea en un objeto Material
         */
        void procesar_archivo();

        /*
         * PRE: -
         * POST: Me muestra lista por pantalla toso los objetos del tipo Material.
         */
        void mostar();

    private:

        /*
         * PRE: Recibe un objeto Material.
         * POST: Ingresa el objeto en un vector dinámico.
         */
        void agregar_material(Material* material);     
};

#endif