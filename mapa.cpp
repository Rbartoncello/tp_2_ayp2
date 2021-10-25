#include "mapa.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string PATH_MAPA = "mapa.txt";

Mapa::Mapa(){
    this->cantidad_filas = 0;
    this->cantidad_columnas = 0;
    this->casilleros = nullptr;
}

Mapa::~Mapa(){
    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            delete this->casilleros[i][j];
        }
        delete [] this->casilleros[i];
    }
    delete [] this->casilleros;
    this->casilleros = nullptr;
}

void Mapa::procesar_archivo(){
    ifstream archivo(PATH_MAPA);
    
    if (!(archivo.is_open())){
        cout << "No se puedo abrir el archivo: " << PATH_MAPA << endl;
    } else {
        string fila, columna;
        char tipo_terreno;

        archivo >> fila;
        archivo >> columna;

        this->cantidad_filas = stoi(fila);
        this->cantidad_columnas = stoi(columna);

        this->casilleros = new Casillero**[this->cantidad_filas];
        for (int i = 0; i < this->cantidad_filas; i++){
            casilleros[i] = new Casillero*[this->cantidad_columnas];
            for (int j = 0; j < this->cantidad_columnas; j++){
                casilleros[i][j] = nullptr;
            }
        }

        for (int i = 0; i < this->cantidad_filas; i++){
            for (int j = 0; j < this->cantidad_columnas; j++){
                if(archivo >> tipo_terreno){
                    switch (tipo_terreno){
                        case LAGO:
                            this->casilleros[i][j] = new Casillero_inaccesible(tipo_terreno, i, j);
                            break;
                        case CAMINO:
                            this->casilleros[i][j] = new Casillero_transitable(tipo_terreno, i, j);
                            break;
                        case TERRENO:
                            this->casilleros[i][j] = new Casillero_construible(tipo_terreno, i, j);
                            break;
                    }
                }
            }
        }
        archivo.close();
    }
}

void Mapa::mostrar(){
    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            this->casilleros[i][j]->mostrar();
        }
        cout << endl;
    }
}
