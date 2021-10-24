#include <iostream>
#include <fstream>
#include "mensajes_pantalla.h"
#include "menu.h"
#include "colors.h"
#include "edificio.h"

int main() {
    Edificios edificios;
    
    edificios.procesar_archivo();

    mensaje_bienvenida();

    int opcion_elegida = 0;
    
    mostrar_opciones();

    opcion_elegida = pedir_opcion();

    validar_opcion_ingresada(opcion_elegida);

    while(opcion_elegida != GUARDA_SALIR){
        procesar_opcion(opcion_elegida, edificios);
        mostrar_opciones();
        opcion_elegida = pedir_opcion();
        validar_opcion_ingresada(opcion_elegida);
        
    }
    
    imprimir_mensaje_guardado();
    return 0;
}