#include "materiales.h"
#include "colors.h"
#include "edificios.h"
#include "emojis.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

const string PATH_MATERIALES = "materiales.txt";

Materiales::Materiales(){
    this->total_materiales = 0;
}

Materiales::~Materiales(){
    for (int i = 0; i < this->total_materiales; i++){
        delete this->materiales[i];
    }
    delete [] this->materiales;
}

void Materiales::agregar_material(Material* material){
    int tope_viejo = this->total_materiales;

    Material** nuevos_materiales = new Material* [ tope_viejo + 1 ];

    for ( int i = 0; i < tope_viejo; i++ )
        nuevos_materiales[i] = this->materiales[i];

    nuevos_materiales[tope_viejo] = material;

    if ( this->total_materiales != 0 )
        delete [] this->materiales;

    this->materiales = nuevos_materiales;
    this->total_materiales++;
}

void Materiales::procesar_archivo(){

    ifstream archivo(PATH_MATERIALES);
    string nombre, cantidad;

    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << PATH_MATERIALES << endl;
    } else {
        while ( archivo >> nombre ){
            archivo >> cantidad;
            agregar_material(new Material(nombre, stoi(cantidad)));
        }
        archivo.close();
    }
}

void Materiales::mostrar(){
    system("clear");

    cout << TXT_BOLD;
    cout << "\t\t╔══════════════╦════════════╗" << endl;
    cout << "\t\t║  Materiales  ║  Cantidad  ║" << endl;
    cout << "\t\t╠══════════════╬════════════╣" << endl;
    cout << END_COLOR;

    for (int i = 0; i < this->total_materiales; i++){
        cout << "\t\t║" << setfill(' ') << setw(10) << this->materiales[i]->devolver_nombre_material() << setfill(' ') << setw(7);
        cout << "│" << setfill(' ') << setw(8) << this->materiales[i]->devolver_cantidad_material() << setfill(' ') << setw(7) << "║" << endl;
        if(i < this->total_materiales - 1)
            cout << "\t\t╠──────────────┼────────────╣" << endl;
        else
            cout << "\t\t╚══════════════╩════════════╝" << endl;
    }  
    
    cout << "Presione [ENTER] para continuar"<< endl;
    cin.get();
    cin.get();
    system("clear");
}

int Materiales::buscar_material(string material_buscar){
    bool encontrado = false;
    int i = 0;

    while ((i < this->total_materiales) && !(encontrado)){
        if(this->materiales[i]->devolver_nombre_material() == material_buscar)
            encontrado = true;
        else
            i++;
    }
    return i;
}

void Materiales::recolectar_recursos_producidos(Mapa* mapa){
    system("clear");
    for (int i = 0; i < mapa->devolver_cantidad_filas(); i++){
        for (int j = 0; j < mapa->devolver_cantidad_columas(); j++){
            if( (mapa->devolver_casillero(i, j)->esta_ocupado()) ){
                if(mapa->devolver_casillero(i, j)->devolver_nombre() == EDIFICIO_MINA){
                    int posicion = this->buscar_material(PIEDRA);
                    materiales[posicion]->aumentar_cantidad_material(AUMENTAR_CANTIDAD_PIEDRA);
                } else if(mapa->devolver_casillero(i, j)->devolver_nombre() == EDIFICIO_ASERRADERO){
                    int posicion = this->buscar_material(MADERA);
                    materiales[posicion]->aumentar_cantidad_material(AUMENTAR_CANTIDAD_MADERA);
                } else if(mapa->devolver_casillero(i, j)->devolver_nombre() == EDIFICIO_FABRICA){
                    int posicion = this->buscar_material(METAL);
                    materiales[posicion]->aumentar_cantidad_material(AUMENTAR_CANTIDAD_METAL);
                }
            }
        }
    }
    imprimir_mensaje_recolectando_recursos_producidos();
}

void Materiales::imprimir_mensaje_recolectando_recursos_producidos() {
    cout << "Recolectando recursos producidos... " << EMOJI_BUSQUEDA << endl;

    sleep(2);
    system("clear");

    cout << TXT_BOLD;
    cout << "\t»Se han recolectado los recursos producidos con exito" << EMOJI_HECHO <<endl;
    cout << END_COLOR;
    
    sleep(2);
    system("clear");
}