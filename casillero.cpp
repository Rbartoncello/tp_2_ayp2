#include "casillero.h"
#include "colors.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Casillero::Casillero(char tipo_terreno, int pos_x, int pos_y){
    this->tipo_terreno = tipo_terreno;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
}

Casillero::Casillero(){
    this->tipo_terreno = ' ';
    this->pos_x = 0;
    this->pos_y = 0;
}

Casillero::~Casillero(){
    
}

void Casillero::mostrar(){
}

char Casillero::devolver_tipo_terreno(){
    return this->tipo_terreno;
}

void Casillero::modificar_tipo_terreno(char tipo_terreno){
    this->tipo_terreno = tipo_terreno;
}

void Casillero::modificar_pos_x(int x){
    this->pos_x = x;
}

void Casillero::modificar_pos_y(int y){
    this->pos_y = y;
}