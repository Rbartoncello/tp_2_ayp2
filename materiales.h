#ifndef Material_H
#define Material_H
#include <string>
#include "material.h"
#include "edificio.h"
#include "mapa.h"

using namespace std;

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
         * Pre: Tiene que a ver un material con nombre_material si o si dentro de materiales.
         * Post: Me vevolvera TRUE si hay la cantidad suficiente de nombre_material para construir edificio y FALSE en caso contrario
         */
        bool hay_suficiente_material(Edificio* edificio, string nombre_material);

        /*
         * PRE: -
         * POST: Me imprimira por pantalla los materiales necesarios para el edificio, comparando con los disponibles.
        */
        void imprimir_materiales_necesarios(Edificio* edificio);

        /*
         * Pre: Tiene que a ver un material con nombre_material si o si dentro de materiales.
         * Post: Me sumara si cantidad es > 0  o me restara si cantidad < 0 el material de nombre_material del inventario
         */
        void sumar_restar_cantidad_material(int cantidad, string nombre_material);

        /*
         * Pre: El mapa tiene que tener cantidad_filas y cantidad_columnas majores que 0.
         * Post: Me incrementara el inventario de PIEDRA, MADERA o METAL dependiendo si encontro en el mapa MINA, ASERRADERO o FABRICA
         */
        void recolectar_recursos_producidos(Mapa *mapa);

        /*
         * Pre: -
         * Post: Devuelve true si existe un material con ese nombre
        */
        bool existe_material_por_nombre(string nombre_material);

        /*
         * Pre: -
         * Post: Guarda en materiales.txt los materiales que quedaron en el juego actual
        */
        void cerrar();
        
    private:
        /*
         * Pre: recibe el nombre de un material existente
         * Post: devuelve la cantidad del material
         */      
        int devolver_cantidad_material(string nombre_material);

        /*
         * Pre: Recibe un objeto Material.
         * Post: Ingresa el objeto en un vector dinámico.
         */
        void agregar_material(Material* material);

        /*
         * Pre: -
         * Post: Imprimira un mensaje por pantalla
         */
        void imprimir_mensaje_recolectando_recursos_producidos();

        /*
         * Pre: El material_buscar tiene que estar si o si dentro de materiales.
         * Post: Devuelve el indice donde esta el material_buscar
         */
        int buscar_material(string material_buscar);

        /*
         * PRE: -
         * POST: Devolvera un string, que representa un emoji, dependiendo si la cant_material_inventario es suficiente para cant_material_necesario.
        */
        string chequear_status(int cant_material_inventario, int cant_material_necesario);
};

#endif