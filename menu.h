#ifndef MENU_H
#define MENU_H
#include <string>

using namespace std;

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

#endif