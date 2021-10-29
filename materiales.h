#ifndef Material_H
#define Material_H
#include <string>
#include "material.h"
#include "edificio.h"

using namespace std;

const string PIEDRA = "piedra";
const string MADERA = "metal";
const string METAL = "madera";

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
        void mostrar();

        //Pre: recibe el nombre de un material existente
        //Post: devuelve la cantidad del material
        int devolver_cantidad_material(string nombre);

        bool hay_suficiente_material(Edificio* edificio, string material);

        void sumar_cantidad_material(int cantidad, string nombre);

    private:
        /*
         * PRE: Recibe un objeto Material.
         * POST: Ingresa el objeto en un vector dinámico.
         */
        void agregar_material(Material* material);     
};

#endif