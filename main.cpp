#include <iostream>
#include "juego.h"

int main() {

    Arsenal* arsenal = new Arsenal;
    Ciudad* ciudad = new Ciudad;

    int opcion = 0;

    cargar_arsenal(arsenal);
    cargar_ciudad(ciudad);


    mostrar_introduccion();
    mostrar_menu();
    opcion = pedir_opcion();
    validar_opcion_elegida(opcion);

    while(opcion != SALIR){
        procesar_opcion(arsenal, ciudad, opcion);

        mostrar_menu();
        opcion = pedir_opcion();
        validar_opcion_elegida(opcion);
    }

    cerrar_arsenal(arsenal);
    cerrar_ciudad(ciudad);

    delete arsenal;
    delete ciudad;

    cout << endl << endl <<"Hasta la proxima!!!!" << endl;

    return 0;
}
