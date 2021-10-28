#include "casillero_transitable.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Casillero_transitable::Casillero_transitable(char tipo_terreno, int pos_x, int pos_y) : Casillero(tipo_terreno, pos_x, pos_y){
    this->ocupado = false;
}

Casillero_transitable::Casillero_transitable() : Casillero(){
    this->ocupado = false;
}

bool Casillero_transitable::esta_ocupado(){
    return this->ocupado;;
}

void Casillero_transitable::mostrar(){
    if(!this->esta_ocupado())
        cout << BGND_GRAY_243 << "  " << END_COLOR;
}

void Casillero_transitable::mostrar_casillero(){
}

string Casillero_transitable::devolver_nombre(){
    return this->material->devolver_nombre_material();
}