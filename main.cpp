#include "juego.h"

int main() {
    Juego juego;

    if (juego.cargar_juego() != ERROR){
        juego.mensaje_bienvenida();
        juego.jugar();  
    }

    return 0;
}