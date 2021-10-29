#include "edificio.h"
#include "materiales.h"
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

int Edificio::devolver_cantidad_material(string material){
    int cantidad_material = 0;

    if (material == PIEDRA)
        cantidad_material = devolver_piedra();
    else if (material == MADERA)
        cantidad_material = devolver_madera();
    else if (material == METAL)
        cantidad_material = devolver_metal();
    
    return cantidad_material;
}

int Edificio::devolver_maxima_cantidad_permitidos(){
    return this->maxima_cantidad_permitidos;
}

void Edificio::mostrar(){
    cout << devolver_nombre_edificio() << " " << devolver_piedra() << " " << devolver_madera() << " " << devolver_metal() << " " << devolver_maxima_cantidad_permitidos() << endl;
}

void Edificio::imprimir_resumen(){
    cout <<"Soy un edificio de nombre " << nombre_edificio << " y me encuentro en el casillero consultado."<< endl;
}