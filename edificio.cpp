#include "edificio.h"
#include <iostream>
#include <string>

using namespace std;

Edificio::Edificio(string nombre, string emoji, int piedra, int madera, int metal, int max_cant_permitidos){
    this->nombre_edificio = nombre;
    this->emoji = emoji;
    this->piedra = piedra;
    this->madera = madera;
    this->metal = metal;
    this->maxima_cantidad_permitidos = max_cant_permitidos;
}

string Edificio::devolver_nombre_edificio(){
    return this->nombre_edificio;
}

string Edificio::devolver_emoji(){
    return this->emoji;
}

int Edificio::devolver_piedra(){
    return this->piedra;
}

int Edificio::devolver_madera(){
    return this->madera;
}

int Edificio::devolver_metal(){
    return this->metal;
}

int Edificio::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}

void Edificio::mostrar(){
    cout << devolver_nombre_edificio() << " " << devolver_piedra() << " " << devolver_madera() << " " << devolver_metal() << " " << devolver_maxima_cantidad_permitidos() << endl;
}