#include "casillero_transitable.h"
#include <iostream>
#include <fstream>
#include <string>
#include "colors.h"

using namespace std;

Casillero_transitable::Casillero_transitable(char tipo_terreno, int pos_x, int pos_y) : Casillero(tipo_terreno, pos_x, pos_y){
    //    this->material = NULL;
    this->ocupado = false;
}

bool Casillero_transitable::esta_ocupado(){
    return this->ocupado;;
}

Casillero_transitable::~Casillero_transitable(){

}

void Casillero_transitable::mostrar(){
    Casillero::mostrar();
    cout << BGND_GRAY_243 << "  " << END_COLOR;
}

//void Casillero_transitable:: añadir_matrial(*Material material){
//    this->material = material;
//}

//void Casillero_transitable:: eliminar_material(){
//    this->material
//}il{l{