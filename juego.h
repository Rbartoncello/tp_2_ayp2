
#ifndef TP_2_AYP2_JUEGO_H
#define TP_2_AYP2_JUEGO_H

#include <fstream>
#include "edificios.h"
#include "materiales.h"
#include "mapa.h"

const string PATH_UBICACIONES = "ubicaciones.txt";

const int MIN_OPCION = 1;
const int MAX_OPCION = 10;

const int ERROR = -1;

const int CONSTRUIR_EDIFICIO_NOMBRE = 1;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 2;
const int LISTAR_TODOS_EDIFICIOS = 3;
const int DEMOLER_EDIFICIO_COORDENADA = 4;
const int MOSTAR_MAPA = 5;
const int CONSULTAR_COORDENADA = 6;
const int MOSTRAR_INVENTARIO = 7;
const int RECOLECTAR_RECURSOS = 8;
const int LLUVIA_RECURSOS = 9;
const int GUARDA_SALIR = 10;

const string VERSION_PGM = "2.0";

class Juego {
    private:
        Edificios* edificios;
        Materiales* materiales;
        Mapa* mapa;
    public:
        /*
         * Constructor sin parametros:
         * PRE: -.
         * POST: Me va a crear el Juego vacio
         */
        Juego();

    /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto Juego.
        
    Juego(Mapa* mapa, Edificios* edificios, Materiales* materiales);

    */
        /*
         * Destructor:
         * PRE: -.
         * POST: Me va a destruir el objeto Mapa.
         */
        ~Juego();

        /*
        * PRE: -
        * POST: Guarda todos edificios en los casilleros del mapa
        */
        void procesar_archivo_ubicaciones();


        /*
        * PRE: -
        * POST: carga todos los archivos al juego
        */
        void cargar_juego();

        /*
        * PRE: -
        * POST: Comienza el loop pidiendo opciones como se hacia ante en main
        */
        void jugar();
        
        /*  
        * PRE: -
        * POST: Imprimira por pantalla el nombre del programa.
        */
        void mensaje_bienvenida();

        /*
        * PRE: -
        * POST: Imprimira por pantalla solamente "Error!!!".
        */
        void imprimir_mensaje_error();

        /*
        * PRE: -
        * POST: Imprimira por pantalla un mensaje con el tiempo en segundos que el usuario tiene que esperar.
        */
        void imprimir_mensaje_esperar(int tiempo);

        /*
        * PRE: -
        * POST: Imprimira por pantalla AFIRMATIVA y NEGATIVA.
        */
        void imprimir_mensaje_opcion_afirmativa_negativa();

        /*
         * Pre: -
         * Post: Imprime por pantalla las opciones.
        */
        void mostrar_opciones();

        /*
         * Pre: -
         * Post: Devuelve el entero ingresado por pantalla.
        */
        int pedir_opcion();

        /*
         * Pre: -
         * Post: Devuelve true si la opcion recibida esta entre MAX_OPCION y MIN_OPCION y sino devuelve false.
        */
        void validar_opcion_ingresada(int &opcion_elegida);

        /*
         * PRE: -
         * POST: Realiza la opcion pedida
        */
        void procesar_opcion(int opcion);

        /*
         * PRE: -
         * POST: Imprime por pantalla que se guardo correctamente.
        */ 
        void imprimir_mensaje_guardado();

        /*
         * Pre: -
         * Post: Imprime por pantalla el error.
        */
        void imprimir_mensaje_error_ingreso();

        /*        
         * Pre: -
         * Post: Devuelve TRUE si MIN_OPCION <= opcion <= MAX_OPCION y FALSE en caso contrario.
        */
        bool es_opcion_valida(int opcion);
};


#endif //TP_2_AYP2_JUEGO_H
