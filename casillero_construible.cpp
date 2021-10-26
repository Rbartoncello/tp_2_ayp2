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

bool Casillero_construible::esta_ocupado(){
    return this->ocupado;
}


void Casillero_construible::mostrar(){
    if (!this->esta_ocupado()){
        cout << BGND_DARK_GREEN_28 << "  " << END_COLOR;
    }
}