#include "casillero_construible.h"
#include "mapa.h"
#include <iostream>

using namespace std;

Casillero_construible::Casillero_construible(char tipo_terreno, int pos_x, int pos_y): Casillero(tipo_terreno, pos_x, pos_y){
    this->ocupado = false;
}

Casillero_construible::Casillero_construible(): Casillero() {
    this->ocupado = false;
}

bool Casillero_construible::esta_ocupado(){
    return this->ocupado;
}

void Casillero_construible::ocupar_casillero(Edificio* edificio) {
    this->edificio = edificio;
    this->ocupado = true;
}

void Casillero_construible::quitar_edificio(){
    this->edificio = nullptr;
    this->tipo_terreno = TERRENO;
    this->ocupado = false;
}

void Casillero_construible::mostrar(){
    if (!this->esta_ocupado())
        cout << BGND_DARK_GREEN_28 << "  " << END_COLOR;
    else 
        cout << BGND_DARK_GREEN_28 << this->edificio->devolver_emoji() << END_COLOR;
}

void Casillero_construible::mostrar_casillero(){
    cout << this->edificio->devolver_nombre_edificio() << "(" << this->devolver_pos_x() << ", " << this->devolver_pos_y() << ")" << endl;
}

string Casillero_construible::devolver_nombre_edificio(){
    return this->edificio->devolver_nombre_edificio();
}

Edificio* Casillero_construible::devolver_edificio(){
    return this->edificio;
}