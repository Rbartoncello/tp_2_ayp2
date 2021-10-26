#include "edificios.h"
#include "colors.h"
#include "mensajes_pantalla.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

const string PATH_EDIFICIO = "edificios.txt";


Edificios::Edificios(){
    this->total_edificios = 0;
}

Edificios::~Edificios(){
    for (int i = 0; i < this->total_edificios; i++){
        delete this->edificios[i];
    }
    delete [] this->edificios;
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

void Edificios::mostar(){
    system("clear");

    cout << TXT_BOLD;
    cout << "\t╔══════════════════════╦═════════════════════════════════════════╦══════════════════════════╗" << endl;
    cout << "\t║                      ║ Materiales necesarios para construirlos ║                          ║" << endl;
    cout << "\t║  Nombre de edificio  ╠═════════════╦═════════════╦═════════════╣ Max. cantidad permitidos ║" << endl;
    cout << "\t║                      ║   Piedra    ║   Madera    ║    Metal    ║                          ║" << endl;
    cout << "\t╠══════════════════════╬═════════════╬═════════════╬═════════════╬══════════════════════════╣" << endl;
    cout << END_COLOR;

    for (int i = 0; i < this->total_edificios; i++){
        cout << "\t║" << setfill(' ') << setw(16) << this->edificios[i]->devolver_nombre_edificio() << setfill(' ') << setw(9);
        cout << "│" << setfill(' ') << setw(8) << this->edificios[i]->devolver_piedra() << setfill(' ') << setw(8);
        cout << "│" << setfill(' ') << setw(8) << this->edificios[i]->devolver_madera() << setfill(' ') << setw(8);
        cout << "│" << setfill(' ') << setw(8) << this->edificios[i]->devolver_metal() << setfill(' ') << setw(8);
        cout << "│" << setfill(' ') << setw(14) << this->edificios[i]->devolver_maxima_cantidad_permitidos() << setfill(' ') << setw(15) << "║" << endl;
        if(i < this->total_edificios - 1)
            cout << "\t╠──────────────────────┼─────────────┼─────────────┼─────────────┼──────────────────────────╣" << endl;
        else
            cout << "\t╚══════════════════════╩═════════════╩═════════════╩═════════════╩══════════════════════════╝" << endl;
    }  
    cout << "Presione [ENTER] para continuar"<< endl;
    cin.get();
    cin.get();
    system("clear");
}

void Edificios::procesar_archivo(){

    ifstream archivo(PATH_EDIFICIO);
    string nombre, piedra, madera, metal, max_cant_permitidos;

    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << PATH_EDIFICIO << endl;
    } else {
        while ( archivo >> nombre ){
            archivo >> piedra;
            archivo >> madera;
            archivo >> metal;
            archivo >> max_cant_permitidos;

            Edificio* edificio  = new Edificio (nombre, stoi(piedra), stoi(madera), stoi(metal), stoi   (max_cant_permitidos));

            agregar_edificio(edificio);
        }

        archivo.close();
    }
}


Edificio* Edificios::buscar_edificio_por_nombre(string nombre){
    for(int i = 0; i < this->total_edificios; i++ ) {
        if (nombre == this->edificios[i]->devolver_nombre_edificio()) {
            return this->edificios[i];
        }
    }
};