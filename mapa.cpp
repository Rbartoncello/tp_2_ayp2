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

void Mapa::crear_matriz_casilleros(){
    this->casilleros = new Casillero**[this->cantidad_filas];
    for (int i = 0; i < this->cantidad_filas; i++){
        casilleros[i] = new Casillero*[this->cantidad_columnas];
        for (int j = 0; j < this->cantidad_columnas; j++){
            casilleros[i][j] = nullptr;
        }
    }
}

void Mapa::agregar_casillero(ifstream &archivo){
    char tipo_terreno;

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
}
void Mapa::procesar_archivo(){
    ifstream archivo(PATH_MAPA);
    
    if (!(archivo.is_open())){
        cout << "No se puedo abrir el archivo: " << PATH_MAPA << endl;
    } else {
        string fila, columna;

        if(archivo >> fila){
            archivo >> columna;

            this->cantidad_filas = stoi(fila);
            this->cantidad_columnas = stoi(columna);

            crear_matriz_casilleros();

            agregar_casillero(archivo);
        }
        archivo.close();
    }
}

void Mapa::mostrar(){
    system("clear");
    for (int i = 0; i < this->cantidad_filas; i++){
        cout << "\t" << BGND_BROWN_94 << " " << END_COLOR;
        for (int j = 0; j < this->cantidad_columnas; j++){
            this->casilleros[i][j]->mostrar();
        }
        cout << BGND_BROWN_94 << " " << END_COLOR;
        cout << endl;
    }
    cout << "Presione [ENTER] para continuar"<< endl;
    cin.get();
    cin.get();
    system("clear");
}

void Mapa::agregar_edificio_a_casillero(Edificio* edificio, int fila, int columna){

    this->casilleros[fila][columna]->agregar_edificio(edificio);
}

void Mapa::mostrar_edificios_construidos() {
    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            if ( this->casilleros[i][j]->devolver_tipo_terreno() == TERRENO && this->casilleros[i][j]->esta_ocupado()){
                this->casilleros[i][j]->mostrar_edificio();
            }
        }
    }
}

