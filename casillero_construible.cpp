#include "casillero_construible.h"
#include <iostream>

using namespace std;

Casillero_construible::Casillero_construible(char tipo_terreno, int pos_x, int pos_y): Casillero(tipo_terreno, pos_x, pos_y){
    this->ocupado = false;
}

Casillero_construible::Casillero_construible(): Casillero() {
    this->ocupado = false;
}

Casillero_construible::~Casillero_construible(){

}


void Casillero_construible::mostrar(){
    cout << BGND_DARK_GREEN_28 << "  " << END_COLOR;
}

void Casillero_construible::agregar_edificio(Edificio* edificio) {
    this->edificio = edificio;
    this->ocupado = true;
}

void Casillero_construible::mostrar_edificio() {
    edificio->mostrar();
}