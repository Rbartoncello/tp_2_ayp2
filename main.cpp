#include "juego.h"
#include "constantes.h"

int main() {
    Juego juego;

    if ( juego.cargar_juego() != ERROR ){
        juego.mensaje_bienvenida();
        juego.jugar();  
    }
    juego.cerrar();

    return 0;
}