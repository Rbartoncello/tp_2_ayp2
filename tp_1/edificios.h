#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include <string>
#include "materiales.h"

using namespace std;

const string PATH_ARCHIVO_EDIFICIO = "edificios.txt";
const string AFIRMATIVO = "si";
const string NEGATIVO = "no";

const string PIEDRA = "piedra";
const string MADERA = "madera";
const string METAL = "metal";

const string CONSTRUIR = "construir";
const string DEMOLER = "demoler";

const int MAX_EDIFICIOS = 100;

struct Edificio{
    string nombre_edificio;
    int piedra;
    int madera;
    int metal;
    int cantidad_construidos;
    int maxima_cantidad_permitidos;
};

/*
 * PRE: -
 * POST: Procesa el archivo y carga el vector de edificios.
 */
void procesar_archivo_edificios(Edificio edificios[MAX_EDIFICIOS], int &tope);

/*
 * PRE: Tope debe ser un numero positivo y valido, edificios[MAX_EDIFICIOS] debe estar cargado y respetar el tope.
 * POST: Se va a listar todos los edificios construidos, es decir, que haya por lo menos un edificio de este tipo indicando cuantos hay construidos de cada uno.
*/
void listar_edificios_construidos(Edificio edificios[MAX_EDIFICIOS], int tope);

/*
 * PRE: Tope debe ser un numero positivo y valido, edificios[MAX_EDIFICIOS] debe estar cargado y respetar el tope.
 * POST: Se va a listar todos los edificios.
*/
void listar_todos_edificios(Edificio edificios[MAX_EDIFICIOS], int tope);

/*
 * PRE: Los topes deben ser un numero positivo y validos, edificios[MAX_EDIFICIOS] y materiales[MAX_MATERIALES] deben estar cargados y respetar sus respectivos topes.
 * POST: Va a aumentar en 1 la cantidad_construidos de un edificio pedido por nombre, verificando que se pueda, ya sea por cantidad de materiales o por maximo de permitidos 
*/
void construir_edificio(Edificio edificios[MAX_EDIFICIOS], int &tope_edificio, Material materiales[MAX_MATERIALES], int tope_materiales);

/*
 * PRE: Los topes deben ser un numero positivo y valido, edificios[MAX_EDIFICIOS] y materiales[MAX_MATERIALES] deben estar cargados y respetar sus respectivos topes.
 * POST: Va a disminuir en 1 la cantidad_construidos de un edificio pedido por nombre, devolviendo la mitad de los materiales.
*/
void demoler_edificio(Edificio edificios[MAX_EDIFICIOS], int tope_edificio, Material materiales[MAX_MATERIALES], int tope_materiales);

/*
 * PRE: Tope debe ser un numero positivo y valido, edificios[MAX_EDIFICIOS] debe estar cargado y respetar el tope.
 * POST: Se van a guardar todos los cambios hecho en edificios[MAX_EDIFICIOS]. 
 */
void guardar_cambios_edificios(Edificio edificios[MAX_EDIFICIOS], int tope);

#endif