#include "casillero_contruible.h"
#include <iostream>

using namespace std;

Casillero_contruible::Casillero_contruible(char tipo_terreno, int pos_x, int pos_y): Casillero(tipo_terreno, pos_x, pos_y){
    this->ocupado = false;
}

Casillero_contruible::Casillero_contruible(){
    this->ocupado = false;
}

Casillero_contruible::~Casillero_contruible(){

}

void Casillero_contruible::mostrar(){
    cout << devolver_tipo_terreno();
}