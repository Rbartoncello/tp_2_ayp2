#ifndef MAPA_H
#define MAPA_H
#include <fstream>
#include "casillero.h"
#include "casillero_inaccesible.h"
#include "casillero_transitable.h"
#include "casillero_construible.h"
using namespace std;


class Mapa{
    private:
        int cantidad_filas;
        int cantidad_columnas;
        Casillero*** casilleros;

    public:
        /*
         * Constructor sin parametros:
         * Pre: -.
         * Post: Me va a crear el objeto Mapa con cantidad_filas = 0, cantidad_columnas = 0 y casilleros = nullptr.
         */
        Mapa();

        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto Mapa.
         */
        Mapa(int filas, int columnas);

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a destruir el objeto Mapa.
         */
        ~Mapa();

        /*
         * Pre: -
         * Post: Guarda todos los datos del archivo en un objeto Mapa
         */
        int procesar_archivo();

        /*
         * Pre: -
         * Post: Me muestra por pantalla el mapa.
         */
        void mostrar();

        /*
         * Pre: edificio bien hecho, fila y columna en indice de la matriz
         * Post: Agrega al casillero marcado el edificio pasado por parametro
         */
        void agregar_edificio_a_casillero(Edificio* edificio, int fila, int columna);

        /*
         * Pre: nombre de material,fila y columna en indice de la matriz
         * Post: Agrega al casillero marcado el material pasado por parametro
         */
        void agregar_material_a_casillero(string material, int fila, int columna);

        /*
         * Pre: Recibe coordenadas que pertenecen al dominio de la matriz y donde hay un edificio construido
         * Post: Desocupa el casillero
        */
        void quitar_edificio_de_casillero(int fila, int columna);

        /*
         * Pre: -
         * Post: Me muestra por pantalla el mapa.
         */
        void mostrar_edificios_construidos();

        /*
         * Pre: recibe un nombre.
         * Post: devuelve la cantidad de ese nombre en el mapa.
        */
        int cantidad_edificio_construido(string nombre);

        /*
         * Pre: Recibe coordenadas dentro del dominio de la matriz
         * Post: Devuelve verdadero si el casillero es construible y esta vacio, de lo contrario devuelve falso
        */
        bool se_puede_construir(int fila, int columna);

        /*
         * Pre: -
         * Post: Devuelve la cantidad de filas que tiene la matriz de casilleros
        */
        int devolver_cantidad_filas();

        /*
         * Pre: -
         * Post: Devuelve la cantidad de columnas que tiene la matriz de casilleros
        */
        int devolver_cantidad_columnas();

        /*
         * Pre: Recibe coordenads dentro del dominio de la matriz
         * Post: Devuelve el objeto casillero que se encuentra en ese lugar de la matriz
        */
        Casillero* devolver_casillero(int fila, int columna);
        
        /*
         * Pre: Recibe coordenadas dentro del dominio de la matriz
         * Post: Devuelve el tipo de casillero que se encuentra en ese lugar de la matriz
        */
        char devolver_tipo_casillero(int fila, int columna);
        
        /*
         * Pre: Recibe coordenadas dentro del dominio de la matriz
         * Post: Devuelve true si esta ocupado o false de lo contrario
        */
        bool casillero_ocupado(int fila, int columna);

        /*
         * Pre: Recibe coordenadas de la matriz en las que hay un edificio
         * Post: Devuelve el edificio que se encuentra en la posicion dada
        */
        Edificio* devolver_edificio(int fila, int columna);

        /*
         * Pre: Recibe coordenadas dentro del dominio de la matriz
         * Post: Imprime por pantalla un resumen del casillero pedido
        */
        void imprimir_resumen_casillero(int fila, int columna);

        /*
         * Pre: -
         * Post: Guarda materiales en casilleros transitables de manera aleatoria (con las probabilidades dadas por consigna)
        */
        void lluvia_recursos();

        /*
         * Pre: -
         * Post: Me devuelve TRUE si hay como minimo un edificio construido y FALSE en caso contrario.
        */
        bool hay_algun_edificio_construido();

        void cerrar_ubicaciones(string path);

    private:
        /*
         * Pre: El archivo tiene que estar abierto y de formato correcto.
         * Post: Me va agregar los datos de encuentra en el archivo en un determinado objeto dependiendo lo que lea del archivo.
         */
        void agregar_casillero(ifstream &archivo);

        /*
         * Pre: -
         * Post: Me crea una matriz del tipo casillero de forma dinamica.
         */
        void crear_matriz_casilleros();

        /*
         * Pre: Recibe 2 numeros
         * Post: Devuelve un numero aleatorio entre esos 2 numeros
        */
        int numero_aleatorio(int desde, int hasta);
        
        /*
         * Pre: Recibe coordenadas dentro del dominio de la matriz
         * Post: Devuelve true si el casillero es transitable y esta vacio, false de lo contrario
        */
        bool se_puede_generar_material(int fila, int columna);

        /*
         * Pre: Recibe un nombre de material y dos numeros minimo y maximo
         * Post: Crea una cantidad n ( siendo min < n <max ) de ese material y los agrega al mapa
        */
        void agregar_materiales(string material, int minimo, int maximo);

        /*
         * Pre: -
         * Post: Me muestra por pantalla la lista de objetos que parecen en el mapa.
         */
        void mostrar_objetos_mapa();

        /*
         * Pre: -
         * Post: Me devuleve TRUE si el si por lo menos hay como minimo 7 casilleros transitables no ocupados.
         */
        bool hay_lugar_minimo_material();
};

#endif