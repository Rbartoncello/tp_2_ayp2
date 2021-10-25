#include <iostream>
#include <fstream>
#include "mensajes_pantalla.h"
#include "menu.h"
#include "colors.h"
#include "edificios.h"
#include "materiales.h"
#include "mapa.h"

int main() {
    Edificios* edificios = new Edificios;
    Materiales* materieles = new Materiales;
    Mapa* mapa = new Mapa;

    edificios->procesar_archivo();
    materieles->procesar_archivo();
    mapa->procesar_archivo();

    mensaje_bienvenida();

    int opcion_elegida = 0;

    mostrar_opciones();

    opcion_elegida = pedir_opcion();

    validar_opcion_ingresada(opcion_elegida);

    while(opcion_elegida != GUARDA_SALIR){
        procesar_opcion(opcion_elegida, edificios, materieles, mapa);
        mostrar_opciones();
        opcion_elegida = pedir_opcion();
        validar_opcion_ingresada(opcion_elegida);

    }

    imprimir_mensaje_guardado();
    delete edificios;
    delete materieles;
    delete mapa;
    return 0;
}