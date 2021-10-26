#include "materiales.h"
#include "colors.h"
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

            //Material* material  = new Material(nombre, stoi(cantidad));

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
