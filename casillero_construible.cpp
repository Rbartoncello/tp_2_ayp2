#include "casillero_construible.h"
#include "mapa.h"
#include <iostream>
#include <iomanip>

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

void Casillero_construible::agregar_edificio(Edificio* edificio) {
    this->edificio = edificio;
    this->ocupado = true;
}

void Casillero_construible::quitar_edificio(){
    this->edificio = nullptr;
    this->ocupado = false;
}

void Casillero_construible::mostrar(){
    if (!this->esta_ocupado())
        cout << BGND_DARK_GREEN_28 << "  " << END_COLOR;
    else 
        cout << BGND_DARK_GREEN_28 << this->edificio->devolver_emoji() << END_COLOR;
}

void Casillero_construible::mostrar_casillero(){
    cout << "\t\t║" << setfill(' ') << setw(16) << devolver_nombre_edificio() << "( " << devolver_edificio()->devolver_emoji() << " )" << setfill(' ') << setw(4);
    cout << "│" << setfill(' ') << setw(4) << devolver_pos_y() << setfill(' ') << setw(5);
    cout << "│" << setfill(' ') << setw(5) << devolver_pos_x() << setfill(' ') << setw(7);
    cout << "│" << setfill(' ') << setw(11);
}

string Casillero_construible::devolver_nombre_edificio(){
    return this->edificio->devolver_nombre_edificio();
}

Edificio* Casillero_construible::devolver_edificio(){
    return this->edificio;
}

void Casillero_construible::imprimir_resumen(){
    if(this->esta_ocupado()){
        cout << "\tSoy un casillero construible y no me encuentro vacío" << endl;
        this->edificio->imprimir_resumen();
    }else{
        cout << "\tSoy un casillero construible y me encuentro vacío" << endl;
    }
}