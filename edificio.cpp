#include "edificio.h"
#include <fstream>
#include <iostream>

const string PATH_EDIFICIO = "edificios.txt";

Edificios::Edificios(){
    this->total_edificios = 0;
}

Edificio::Edificio(string nombre, int piedra, int madera, int metal, int max_cant_permitidos){
    this->nombre = nombre;
    this->piedra = piedra;
    this->madera = madera;
    this->metal = metal;
    this->max_cant_permitidos = max_cant_permitidos;   
}


void Edificios::agregar_edificio(Edificio* edificio){
    int tope_viejo = this->total_edificios;

    Edificio** nuevos_edificios = new Edificio* [ tope_viejo + 1 ];

    for ( int i = 0; i < tope_viejo; i++ )
        nuevos_edificios[i] = this->edificios[i];

    nuevos_edificios[tope_viejo] = edificio;

    if ( this->total_edificios != 0 )
        delete [] this->edificios;
    
    this->edificios = nuevos_edificios;
    this->total_edificios++;
}

void Edificios::procesar_archivo(){

    ifstream archivo(PATH_EDIFICIO);
    string nombre, piedra, madera, metal, max_cant_permitidos;

    while ( archivo >> nombre ){
        archivo >> piedra;
        archivo >> madera;
        archivo >> metal;
        archivo >> max_cant_permitidos;

        Edificio* edificio  = new Edificio (nombre, stoi(piedra), stoi(madera), stoi(metal), stoi(max_cant_permitidos));

        agregar_edificio(edificio);
    }

    archivo.close();
}

void Edificios::mostar(){
    for (int i = 0; i < this->total_edificios; i++)
        this->edificios[i]->mostar();    
}

void Edificio::mostar(){
    cout << devolver_nombre() << " " << cant_piedra_necesaria() << " " << cant_madera_necesaria() << " " << cant_metal_necesaria() << " " << maximo_permitidos() << endl;
}

string Edificio::devolver_nombre(){
    return this->nombre;
}

int Edificio::cant_piedra_necesaria(){
    return this->piedra;
}

int Edificio::cant_madera_necesaria(){
    return this->madera;
}

int Edificio::cant_metal_necesaria(){
    return this->metal;
}

int Edificio::maximo_permitidos(){
    return this->max_cant_permitidos;
}
