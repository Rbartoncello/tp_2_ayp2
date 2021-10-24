
#include "casillero_no_transitable.h"
#include <iostream>
#include "colors.h"

using namespace std;

Casillero_no_transitable::Casillero_no_transitable(char tipo_terreno, int pos_x, int pos_y) : Casillero(tipo_terreno, pos_x, pos_y){
}

Casillero_no_transitable::~Casillero_no_transitable(){

}

void Casillero_no_transitable::mostrar(){
    Casillero::mostrar();
    cout << BGND_LIGHT_BLUE_68 << "  " << END_COLOR;
}