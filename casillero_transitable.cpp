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
    else
        cout << BGND_GRAY_243 << this->material -> devolver_emoji() << " " << END_COLOR;
}

void Casillero_transitable::mostrar_casillero(){
}

void Casillero_transitable::imprimir_resumen(){
    if(this->esta_ocupado()){
        cout << "\tSoy un casillero transitable y no me encuentro vacío" << endl;
        this->material->imprimir_resumen();
    }else{
        cout << "\tSoy un casillero transitable y me encuentro vacío" << endl;
    }
}

void Casillero_transitable::agregar_material(string nombre_material){
    this->material = new Material(nombre_material, 1);
    this->ocupado = true;
}

string Casillero_transitable::devolver_nombre_material(){
    return this->material->devolver_nombre_material();
}

Material *Casillero_transitable::devolver_material(){
    return this->material;
}