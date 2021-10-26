#include "juego.h"

int main() {
    Juego juego;

    juego.cargar_juego();

    juego.jugar();

    juego.~Juego();

    return 0;
}