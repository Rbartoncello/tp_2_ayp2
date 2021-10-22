#include "menu.h"
#include "emojis.h"
#include "colors.h"
#include "mensajes_pantalla.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>

void mostrar_opciones(){
    
    cout << TXT_LIGHT_AQUA_43;
    cout << "\t\t\t\t\t╔════╦═════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_UNO    << " ║ Construir edificio por nombre.      ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_DOS    << " ║ Listar los edificios construidos.   ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_TRES   << " ║ Listar todos los edificios.         ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_CUATRO << " ║ Demoler un edificio por coordenada. ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_CINCO  << " ║ Mostrar mapa.                       ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_SEIS  << " ║ Consultar coordenada.               ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_SIETE  << " ║ Consultar coordenada.               ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_OCHO  << " ║ Recolectar recursos producidos.     ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_NUEVE  << " ║ Lluvia de recursos.                 ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_DIEZ   << " ║ Guarda y salir                      ║" << endl;
    cout << "\t\t\t\t\t╚════╩═════════════════════════════════════╝" << endl;
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

void procesar_opcion(int opcion, Edificios edificios){

    switch (opcion){
        case CONSTRUIR_EDIFICIO_NOMBRE:
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            break;
        case LISTAR_TODOS_EDIFICIOS:
            edificios.mostar();
            break;
        case DEMOLER_EDIFICIO_COORDENADA:
            break;
        case MOSTAR_MAPA:
            break;
        case CONSULTAR_COORDENADA:
            break;
        case MOSTRAR_INVENTARIO:
            break;
        case RECOLECTAR_RECURSOS:
            break;
        case LLUVIA_RECURSOS:
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