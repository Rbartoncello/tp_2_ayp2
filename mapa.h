#ifndef MAPA_H
#define MAPA_H
#include <fstream>
#include "casillero.h"
#include "casillero_inaccesible.h"
#include "casillero_transitable.h"
#include "casillero_construible.h"
using namespace std;

const int MIN_GENERAR_PIEDRA = 1;
const int MAX_GENERAR_PIEDRA = 2;

const int MIN_GENERAR_MADERA = 0;
const int MAX_GENERAR_MADERA = 1;

const int MIN_GENERAR_METAL = 2;
const int MAX_GENERAR_METAL = 4;

const char CAMINO = 'C', TERRENO = 'T', LAGO = 'L';

class Mapa{
    private:
        int cantidad_filas;
        int cantidad_columnas;
        Casillero*** casilleros;

    public:
        /*
         * Constructor sin parametros:
         * PRE: -.
         * POST: Me va a crear el objeto Mapa con cantidad_filas = 0, cantidad_columnas = 0 y casilleros = nullptr.
         */
        Mapa();

        /*
         * Constructor:
         * PRE: -.
         * POST: Me va a crear el objeto Mapa.
         */
        Mapa(int filas, int columnas);

        /*
         * Destructor:
         * PRE: -.
         * POST: Me va a destruir el objeto Mapa.
         */
        ~Mapa();

        /*
         * PRE: -
         * POST: Guarda todos los datos del archivo en un objeto Mapa
         */
        void procesar_archivo();

        /*
         * PRE: -
         * POST: Me muestra por pantalla el mapa.
         */
        void mostrar();

        /*
         * PRE: edificio bien hecho, fila y columna en indice de la matriz
         * POST: Agrega al casillero marcado el edificio pasado por parametro
         */
        void agregar_edificio_a_casillero(Edificio* edificio, int fila, int columna);
        
        //Pre: Hay un edificio en el indice de la matriz
        void quitar_edificio_de_casillero(int fila, int columna);

        /*
         * PRE: -
         * POST: Me muestra por pantalla el mapa.
         */
        void mostrar_edificios_construidos();

        //pre: recibe un nombre
        //post: devuelve la cantidad de ese nombre en el mapa
        int cantidad_edificio_construido(string nombre);

        bool se_puede_construir(int fila, int columna);

        int devolver_cantidad_filas();

        int devolver_cantidad_columnas();

        Casillero* devolver_casillero(int fila, int columna);

        char devolver_tipo_casillero(int fila, int columna);

        bool casillero_ocupado(int fila, int columna);

        //pre: hay un edificio en la posicion
        Edificio* devolver_edificio(int fila, int columna);

        void imprimir_resumen_casillero(int fila, int columna);

        void lluvia_recursos();

    private:
        /*
         * PRE: El archivo tiene que estar abierto y de formato correcto.
         * POST: Me va agregar los datos de encuentra en el archivo en un determinado objeto dependiendo lo que lea del archivo.
         */
        void agregar_casillero(ifstream &archivo);

        /*
         * PRE: -
         * POST: Me crea una matriz del tipo casillero de forma dinamica.
         */
        void crear_matriz_casilleros();

        int numero_aleatorio(int desde, int hasta);

        bool se_puede_generar_material(int fila, int columna);

        void agregar_materiales(string material, int minimo, int maximo);
};

#endif