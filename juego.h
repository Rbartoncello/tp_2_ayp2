
#ifndef JUEGO_H
#define JUEGO_H

#include <fstream>
#include "edificios.h"
#include "materiales.h"
#include "mapa.h"

class Juego {
    private:
        Edificios* edificios;
        Materiales* materiales;
        Mapa* mapa;
    public:
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el Juego vacio
         */
        Juego();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Mapa.
         */
        ~Juego();

        /*
        * Pre: -
        * Post: carga todos los archivos al juego
        */
        int cargar_juego();

        /*
        * Pre: -
        * Post: Comienza el loop pidiendo opciones como se hacia ante en main
        */
        void jugar();
        
        /*  
        * Pre: -
        * Post: Imprimira por pantalla el nombre del programa.
        */
        void mensaje_bienvenida();

        /*
         * Pre: -
         * Post: Guarda en los archivos todos los cambios hechos durante el juego
         */
        void cerrar();
    private:
        /*
        * Pre: -
        * Post: Imprimira por pantalla solamente "Error!!!".
        */
        void imprimir_mensaje_error();

        /*
        * Pre: -
        * Post: Imprimira por pantalla un mensaje con el tiempo en segundos que el usuario tiene que esperar.
        */
        void imprimir_mensaje_esperar(int tiempo);

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
         * Post: repite el input hasta que se cumpla la condicion pedida (MAX_OPCION y MIN_OPCION).
        */
        void validar_opcion_ingresada(int &opcion_elegida);

        /*
         * Pre: -
         * Post: repite el input hasta que se cumpla la condicion pedida (AFIRMATIVO y NEGATIVO).
        */
        void validar_opcion_construir(int &opcion_elegida);

        /*
         * Pre: -
         * Post: Me imprimira por pantalla la action_realizada.
        */
        void imprimir_procesamiento_accion(string action_realizada, string nombre_edificio, string emoji_edificio);

        /*
         * Pre: -
         * Post: Realiza la opcion pedida
        */
        void procesar_opcion(int opcion);

        /*
         * Pre: -
         * Post: Imprime por pantalla que se guardo correctamente.
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

        /*
         * Pre: -
         * Post: Solicita al usuario el nombre del edificio.
        */ 
        string pedir_nombre();

        /*
         * Pre: Recibe un edificio bien armado.
         * Post: Devuelve true si no hay ningun problema.
        */
        bool calcular_costos(Edificio* edificio);

        /*
         * Pre: -
         * Post: Pide al usaurio un nombre y ubicacion via input y, de ser confirmado y posible, lo construye.
        */
        void construir_edificio_nombre();

        /*
         * Pre: -
         * Post: Pide al usuario una ubicacion via input y si hay un edificio construido lo elimina.
        */
        void demoler_edificio_por_coordenada();

        /*
         * Pre: -
         * Post: Pide al usuario una ubicacion via input y le infroma sobre el contenido del mismo.
        */
        void mostrar_coordenada();
        /*
        * Pre: -
        * Post: Guarda todos edificios en los casilleros del mapa
        */
        int procesar_archivo_ubicaciones();

        /*
         * Pre: -
         * Post: Pausa la pantalla con un cin.
        */
        void mensaje_enter_continuar();

        /*
         * Pre: -
         * Post: Devuelve el entero ingresado por pantalla..
        */
        int pedir_fila();

        /*
         * Pre: -
         * Post: Devuelve el entero ingresado por pantalla..
        */
        int pedir_columna();

        /*
         * Pre: -
         * Post: repite el input hasta que se cumpla la condicion pedida (0 y n_fila).
        */
        void validar_fila(int &fila);

        /*
         * Pre: -
         * Post: repite el input hasta que se cumpla la condicion pedida (0 y n_columna).
        */
        void validar_columna(int &columna);
};


#endif //JUEGO_H
