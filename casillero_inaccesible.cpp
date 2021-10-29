
#include "casillero_inaccesible.h"
#include <iostream>

using namespace std;

Casillero_inaccesible::Casillero_inaccesible(char tipo_terreno, int pos_x, int pos_y) : Casillero(tipo_terreno, pos_x, pos_y){
    this->ocupado = false;
}

Casillero_inaccesible::Casillero_inaccesible(): Casillero(){

}

bool Casillero_inaccesible::esta_ocupado(){
    return this->ocupado;
}

void Casillero_inaccesible::mostrar(){
    cout << BGND_LIGHT_BLUE_68 << "  " << END_COLOR;
}

void Casillero_inaccesible::mostrar_casillero(){
}

void Casillero_inaccesible::imprimir_resumen(){
    cout << endl <<"Soy un casillero inaccesible y me encuentro vacío" << endl;
}