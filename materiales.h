#ifndef Material_H
#define Material_H
#include <string>
#include "material.h"
#include "edificio.h"
#include "mapa.h"

using namespace std;

const string PIEDRA = "piedra";
const string MADERA = "metal";
const string METAL = "madera";

const int AUMENTAR_CANTIDAD_PIEDRA = 15;
const int AUMENTAR_CANTIDAD_MADERA = 25;
const int AUMENTAR_CANTIDAD_METAL = 40;

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

        /*
         * PRE: recibe el nombre de un material existente
         * POST: devuelve la cantidad del material
         */      
        int devolver_cantidad_material(string nombre);

        /*
         * PRE:
         * POST:
         */
        bool hay_suficiente_material(Edificio* edificio, string material);

        /*
         * PRE:
         * POST:
         */
        void sumar_cantidad_material(int cantidad, string nombre);

        /*
         * PRE:
         * POST:
         */
        void recolectar_recursos_producidos(Mapa *mapa);

        /*
         * PRE:
         * POST:
         */
        int buscar_material(string material_buscar);

    private:
        /*
         * PRE: Recibe un objeto Material.
         * POST: Ingresa el objeto en un vector dinámico.
         */
        void agregar_material(Material* material);

        /*
         * PRE:
         * POST:
         */
        void imprimir_mensaje_recolectando_recursos_producidos();   
};

#endif