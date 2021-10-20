#include "menu.h"
#include "materiales.h"
#include "edificios.h"
#include "emojis.h"
#include "colors.h"
#include "mensajes_pantalla.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

void mostrar_opciones(){
    
    cout << TXT_LIGHT_AQUA_43;
    cout << "\t\t\t\t\t╔═══╦═══════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_UNO    << " ║ Listar materiales de construcción.║" << endl;
    cout << "\t\t\t\t\t╠───╬───────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_DOS    << " ║ Construir edificio por nombre.    ║" << endl;
    cout << "\t\t\t\t\t╠───╬───────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_TRES   << " ║ Listar los edificios construidos. ║" << endl;
    cout << "\t\t\t\t\t╠───╬───────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_CUATRO << " ║ Listar todos los edificios.       ║" << endl;
    cout << "\t\t\t\t\t╠───╬───────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_CINCO  << " ║ Demoler un edificio por nombre.   ║" << endl;
    cout << "\t\t\t\t\t╠───╬───────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_SEIS   << " ║ Guarda y salir                    ║" << endl;
    cout << "\t\t\t\t\t╚═══╩═══════════════════════════════════╝" << endl;
    cout << END_COLOR;
}               

int pedir_opcion(){
    int opcion_elegida = ERROR;
    cout << " Por favor ingrese una de las siguientes opciones: ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

/*
 * Pre: -
 * Post: Devuelve TRUE si MIN_OPCION <= opcion <= MAX_OPCION y FALSE en caso contrario.
*/
bool es_opcion_valida(int opcion){
    return( ( opcion >= MIN_OPCION ) && ( opcion <= MAX_OPCION ) );
}

/*
 * Pre: -
 * Post: Imprime por pantalla el error.
*/
void imprimir_mensaje_error_ingreso(){
    imprimir_mensaje_error();
    cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
}

void validar_opcion_ingresada(int &opcion_elegida){
    bool es_valida = es_opcion_valida(opcion_elegida);
    while(!es_valida){
        imprimir_mensaje_error_ingreso();
        
        cin >> opcion_elegida;
        es_valida = es_opcion_valida(opcion_elegida);
    }
}

void procesar_opcion(int opcion, Material materiales[MAX_MATERIALES], int &tope_materiales, Edificio edificios[MAX_EDIFICIOS], int tope_edificios){

    switch (opcion){
        case LISTAR_MATERIALES:
            listar_materiales(materiales, tope_materiales);
            break;
        case CONSTRUIR_EDIFICIO:
            construir_edificio(edificios, tope_edificios, materiales, tope_materiales);
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            listar_edificios_construidos(edificios, tope_edificios);
            break;
        case LISTAR_EDIFICIOS:
            listar_todos_edificios(edificios, tope_edificios);
            break;
        case DEMOLER_EDIFICIO:
            demoler_edificio(edificios, tope_edificios, materiales, tope_materiales);
            break;
    }
}

void imprimir_mensaje_guardado(){
    system("clear");
    cout << "Cargando... " << EMOJI_LOANDING << endl;

    sleep(2);
    system("clear");

    cout << "\t»Se ha guardado con exito " << EMOJI_HECHO << endl;
    cout << "\t»Adios«" << endl;
}