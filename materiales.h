#ifndef Material_H
#define Material_H
#include <string>
#include "material.h"
#include "edificio.h"
#include "mapa.h"

using namespace std;

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";

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
         * Pre: -.
         * Post: Me va a crear el objeto Materiales con total_materiales = 0.
         */
        Materiales();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a descruir el objeto Materiales.
         */
        ~Materiales();

        /*
         * Pre: -
         * Post: Guarda cada linea en un objeto Material
         */
        int procesar_archivo();

        /*
         * Pre: -
         * Post: Me muestra lista por pantalla toso los objetos del tipo Material.
         */
        void mostrar();

        /*
         * Pre: recibe el nombre de un material existente
         * Post: devuelve la cantidad del material
         */      
        int devolver_cantidad_material(string nombre);

        /*
         * Pre:
         * Post:
         */
        bool hay_suficiente_material(Edificio* edificio, string material);

        /*
         * Pre:
         * Post:
         */
        void sumar_restar_cantidad_material(int cantidad, string nombre);

        /*
         * Pre:
         * Post:
         */
        void recolectar_recursos_producidos(Mapa *mapa);

        /*
         * Pre:
         * Post:
         */
        int buscar_material(string material_buscar);

        /*
         * Pre: -
         * Post: devuelve true si existe un material con ese nombre
        */
        bool existe_material_por_nombre(string nombre);

        /*
         * Pre: -
         * Post: Guarda en materiales.txt los materiales que quedaron en el juego actual
        */
        void cerrar();
        
    private:
        /*
         * Pre: Recibe un objeto Material.
         * Post: Ingresa el objeto en un vector dinámico.
         */
        void agregar_material(Material* material);

        /*
         * Pre:
         * Post:
         */
        void imprimir_mensaje_recolectando_recursos_producidos();

        
};

#endif