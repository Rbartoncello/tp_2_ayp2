#ifndef MENU_H
#define MENU_H
#include <string>
#include "materiales.h"
#include "edificios.h"

using namespace std;

const int MIN_OPCION = 1;
const int MAX_OPCION = 6;

const int ERROR = -1;
	
const int LISTAR_MATERIALES = 1;
const int CONSTRUIR_EDIFICIO = 2;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 3;
const int LISTAR_EDIFICIOS = 4;
const int DEMOLER_EDIFICIO = 5;
const int GUARDA_SALIR = 6;

const string VERSION_PGM = "1.0";

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
void procesar_opcion(int opcion, Material materiales[MAX_MATERIALES], int &tope_materiales, Edificio edificios[MAX_EDIFICIOS], int tope_edificios);

/*
 * PRE: -
 * POST: Imprime por pantalla que se guardo correctamente.
 */
void imprimir_mensaje_guardado();

#endif