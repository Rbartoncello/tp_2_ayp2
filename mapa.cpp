#include "mapa.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string PATH_MAPA = "mapa.txt";

Mapa::Mapa(){
    this->cantidad_filas = 0;
    this->cantidad_columnas = 0;
    //this->casilleros = new Casillero*[this->cantidad_filas];
    //for (int i = 0; i < this->cantidad_filas+1; i++){
    //    casilleros[i] = new Casillero[this->cantidad_columnas];
    //}
}

Mapa::Mapa(int filas, int columnas){
    this->cantidad_filas = filas;
    this->cantidad_columnas = columnas;
    this->casilleros = new Casillero**[this->cantidad_filas];
    for (int i = 0; i < this->cantidad_filas; i++){
        casilleros[i] = new Casillero*[this->cantidad_columnas];
    }
}

Mapa::~Mapa(){
    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            delete [] casilleros[i][j];
        }
        delete [] this->casilleros[i];
    }
    delete [] this->casilleros;
    this->casilleros = nullptr;
}

void Mapa::procesar_archivo(){
    ifstream archivo(PATH_MAPA);

    string fila, columna;
    char tipo_terreno;

    archivo >> fila;
    archivo >> columna;

    this->cantidad_filas = stoi(fila);
    this->cantidad_columnas = stoi(columna);

    //Mapa mapa_aux(this->cantidad_filas, this->cantidad_columnas);
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
                        this->casilleros[i][j] = new Casillero_no_transitable(tipo_terreno, i, j);
                        break;
                    case CAMINO:
                        this->casilleros[i][j] = new Casillero_transitable(tipo_terreno, i, j);
                        break;
                    case TERRENO:
                        this->casilleros[i][j] = new Casillero_contruible(tipo_terreno, i, j);
                        break;
                }
                //this->casilleros[i][j].modificar_tipo_terreno(tipo_terreno);
                //this->casilleros[i][j].modificar_pos_x(i);
                //this->casilleros[i][j].modificar_pos_y(j);
            }
        }
    }

    //this->casilleros = mapa_aux.casilleros;

    //delete [] this->casilleros;
    //delete [] mapa_aux.casilleros;
    archivo.close();
}

void Mapa::mostrar(){
    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            this->casilleros[i][j]->mostrar();
        }
        cout << endl;
    }
}
