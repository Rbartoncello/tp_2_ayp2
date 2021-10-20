//
// Created by juan on 28/9/21.
//

#ifndef ANDYPOLIS_JUEGO_H
#define ANDYPOLIS_JUEGO_H

#include <string>

using namespace std;

const int OPCIONES_VALIDAS = 6;
const int OPCIONES_VALIDAS_CONSTRUIR = 2;
const string PATH_MATERIALES = "materiales.txt";
const string PATH_EDIFICIOS = "edificios.txt";
const int SALIR = 6;

//Estructuras

struct Material{
    string nombre;
    int cantidad;
};

struct Arsenal{
    Material** materiales;
    int cantidad_de_materiales_distintos;
};

struct Edificio{
    string nombre;
    int piedra;
    int madera;
    int metal;
    int cantidad_construidos;
    int cantidad_maxima_construidos;
};

struct Ciudad{
    Edificio** edificios;
    int cantidad_de_edificios;
};


//Funciones


//Precondiciones: -
//Poscondiciones: Imprime la introduccion y pausa el programa hasta que el usuario quiera comenzar
void mostrar_introduccion();

//Precondiciones: -
//Postcondiciones: Carga el arsenal con los datos del archivo de materiales
void cargar_arsenal(Arsenal* arsenal);

//Precondiciones: -
//Postcondiciones: Carga la ciudad con los datos del archivo de edificios
void cargar_ciudad(Ciudad* ciudad);

//Precondiciones: -
//Postcondiciones: imprime por pantalla el menu
void mostrar_menu();

//Precondiciones: -
//Postcondiciones: Le solicita al usuario que ingrese el numero de la opcion que desea seleccionar
int pedir_opcion();

//Precondiciones: recibe la opcion elegida precargada
//Postcondiciones: Verifica que la opcion sea un numero entre 0 y el valor de OPCIONES_VALIDAS y si no lo es vuelve a solicitar los datos
void validar_opcion_elegida(int &opcion_elegida);

//Precondiciones: La opcion es valida.
//Postcondiciones: Realiza la opcion indicada.
void procesar_opcion(Arsenal* arsenal, Ciudad* ciudad, int opcion);

//Precondiciones: El material debe estar bien cargado
//Postcondiciones: Añade el material al arsenal
void agregar_material(Arsenal* arsenal, Material* material);

//Precondiciones: El edificio debe estar bien cargado
//Postcondiciones: Añade el edificio a la ciudad
void agregar_edificio(Ciudad* ciudad, Edificio* edificio);

//Precondiciones: -
//Postcondiciones: Guarda los materiales en el archivo materiales.txt y elimina el arsenal
void cerrar_arsenal(Arsenal* arsenal);

//Precondiciones: -
//Postcondiciones: Guarda los edificios en el archivo edificios.txt y elimina la ciudad
void cerrar_ciudad(Ciudad* ciudad);

//Precondiciones: -
//Postcondiciones: Imprime por pantalla los materiales y las cantidades de estos que contiene el arsenal o un mensaje si esta vacio
void mostrar_materiales(Arsenal* arsenal);

//Precondiciones: La posicion debe existir dentro del arsenal
//Postcondiciones: Muestra por pantalla los datos del material que se encuentra en la posicion indicada
void mostrar_material(Arsenal* arsenal, int posicion);

//Precondiciones: -
//Postcondiciones: Imprime por pantalla los edificios construidos en la ciudad o un mensaje si esta vacia
void mostrar_edificios_construidos(Ciudad* Ciudad);

//Precondiciones: La posicion debe existir dentro de la ciudad
//Postcondiciones: Muestra por pantalla el nombre y cuantos hay contruidos del edificio que se encuentra en la posicion indicada
void mostrar_edificio_corto(Ciudad* ciudad, int posicion);

//Precondiciones: -
//Postcondiciones: Imprime por pantalla los edificios posibles de la ciudad, su costo de contruccion, cuantos hay contruidos y cuantos se pueden contruir como maximo o un mensaje si esta vacia
void mostrar_edificios(Ciudad* ciudad);

//Precondiciones: La posicion debe existir dentro de la ciudad
//Postcondiciones: Muestra por pantalla todos los datos del edificio que se encuentra en la posicion indicada
void mostrar_edificio(Ciudad* ciudad);

//Precondiciones: El numero dado corresponde a la posicion de un edificio y es posible la construccion del mismo
//Postcondiciones: Suma a la cantidad del edificio "nombre" y resta los materiales del arsenal
void construir_edificio(Ciudad* ciudad, Arsenal* arsenal, int posicion_del_edificio);

//Precondiciones: El numero dado corresponde a la posicion de un edificio y es posible la demolicion del mismo
//Postcondiciones: Resta a la cantidad del edificio "nombre" y suma la mitad los materiales que costo construirlo al arsenal
void demoler_edificio(Ciudad* ciudad, Arsenal* arsenal, int posicion_del_edificio);

//Precondiciones: -
//Postcondiciones: Solicita al usuario el nombre del edificio
string pedir_nombre();

//Precondiciones: -
//Postcondiciones: Devuelve true si el nombre de edificio esta en la ciudad y false en caso contrario
bool existe_el_nombre(string nombre, Ciudad* ciudad);

//Precondiciones: -
//Postcondiciones: Devuelve la posicion en la que se encuentra el nombre recibido o -1 si no es encontrado
int obtener_posicion_del_edificio(string nombre, Ciudad* ciudad);

//Precondiciones: -
//Postcondiciones: Devuelve la posicion en la que se encuentra el nombre recibido o -1 si no es encontrado
int obtener_posicion_del_material(string nombre, Arsenal* arsenal);

//Precondiciones: El numero dado corresponde a la posicion de un edificio
//Postcondiciones: Devuelve verdadero si es posible construir y falso de lo contrario (imprime paso a paso cada validacion)
bool calcular_costos(Ciudad* ciudad, Arsenal* arsenal, int posicion_edificio);

//Precondiciones: Recibe la opcion elegida precargada
//Postcondiciones: Verifica que la opcion sea un numero entre 0 y el valor de OPCIONES_VALIDAS_CONSTRUIR y si no lo es vuelve a solicitar los datos
void validar_opcion_construir(int &opcion_elegida_construir);



#endif //ANDYPOLIS_JUEGO_H
