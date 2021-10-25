
#include "casillero_inaccesible.h"
#include <iostream>

using namespace std;

Casillero_inaccesible::Casillero_inaccesible(char tipo_terreno, int pos_x, int pos_y) : Casillero(tipo_terreno, pos_x, pos_y){
}

Casillero_inaccesible::Casillero_inaccesible(): Casillero(){

}

/* Casillero_inaccesible::~Casillero_inaccesible(){

} */

void Casillero_inaccesible::mostrar(){
    cout << BGND_LIGHT_BLUE_68 << "  " << END_COLOR;
}