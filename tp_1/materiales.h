#ifndef MATERIALES_H
#define MATERIALES_H
#include <string>

using namespace std;

const string PATH_ARCHIVO_MATERIALES = "materiales.txt";

const int MAX_MATERIALES = 100;

struct Material{
    string nombre_material;
    int cantidad_material;
};

/*
 * PRE: -
 * POST: Procesa el archivo y carga el vector de materiales.
 */
void procesar_archivo_materiales(Material materiales[MAX_MATERIALES], int &tope);

/*
 * PRE: Tope debe ser un numero positivo y valido, materiales[MAX_MATERIALES debe estar cargado y respetar el tope.
 * POST: Se deberán listar todos los materiales de construcción y la cantidad disponible de cada uno
*/
void listar_materiales(Material materiales[MAX_MATERIALES], int tope);

/*
 * PRE: Tope debe ser un numero positivo y valido, materiales[MAX_MATERIALES] debe estar cargado y respetar el tope.
 * POST: Se van a guarda todos los cambios hecho en materiales[MAX_MATERIALES]. 
 */
void guardar_cambios_materiales(Material materiales[MAX_MATERIALES], int tope);

#endif

