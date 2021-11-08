#include "edificios.h"
#include "juego.h"
#include "colors.h"
#include "emojis.h"
#include "constantes.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

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

bool Edificios::brinda_material(string nombre_edificio){
    return ( ( nombre_edificio == EDIFICIO_MINA ) || ( nombre_edificio == EDIFICIO_ASERRADERO ) || ( nombre_edificio == EDIFICIO_FABRICA ) );
}

void Edificios::mostar(Mapa* mapa){
    system("clear");

    cout << TXT_BOLD;
    cout << "\t╔══════════════════════╦═════════════════════════════════════════╦═════════════╦═════════════╦═════════════════╗" << endl;
    cout << "\t║                      ║ Materiales necesarios para construirlos ║             ║             ║                 ║" << endl;
    cout << "\t║  Nombre de edificio  ╠═════════════╦═════════════╦═════════════╣ Construidos ║ Disponibles ║ Brinda material ║" << endl;
    cout << "\t║                      ║ Piedra ("<< EMOJI_PIEDRA << " ) ║ Madera ("<< EMOJI_MADERA << " ) ║  Metal ("<< EMOJI_METAL << ")  ║             ║             ║                 ║" << endl;
    cout << "\t╠══════════════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════╬═════════════════╣" << endl;
    cout << END_COLOR;

    for (int i = 0; i < this->total_edificios; i++){
        string brinda = EMOJI_MAL;
        if ( brinda_material(this->edificios[i]->devolver_nombre_edificio()) )
            brinda = EMOJI_HECHO;


        cout << "\t║" << setfill(' ') << setw(16) << this->edificios[i]->devolver_nombre_edificio() << "( " << this->edificios[i]->devolver_emoji() << " )" << setfill(' ') << setw(3);
        cout << "│" << setfill(' ') << setw(8) << this->edificios[i]->devolver_piedra() << setfill(' ') << setw(8);
        cout << "│" << setfill(' ') << setw(8) << this->edificios[i]->devolver_madera() << setfill(' ') << setw(8);
        cout << "│" << setfill(' ') << setw(8) << this->edificios[i]->devolver_metal() << setfill(' ') << setw(8);
        cout << "│" << setfill(' ') << setw(7) << mapa->cantidad_edificio_construido(this->edificios[i]->devolver_nombre_edificio()) << setfill(' ') << setw(9);
        cout << "│" << setfill(' ') << setw(7) << this->edificios[i]->devolver_maxima_cantidad_permitidos()- mapa->cantidad_edificio_construido(this->edificios[i]->devolver_nombre_edificio()) << setfill(' ') << setw(9);
        cout << "│" << setfill(' ') << setw(10) << brinda << setw(11) << "║" << endl;
        if(i < this->total_edificios - 1)
            cout << "\t╠──────────────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────┼─────────────────╣" << endl;
        else
            cout << "\t╚══════════════════════╩═════════════╩═════════════╩═════════════╩═════════════╩═════════════╩═════════════════╝" << endl;
    }    
}

int Edificios::procesar_archivo(){

    ifstream archivo(PATH_EDIFICIO);
    string nombre, piedra, madera, metal, max_cant_permitidos, nombre_aux;

    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << PATH_EDIFICIO << endl;
        return ERROR;
    } else {
        while ( archivo >> nombre ){
            if (nombre == PLANTA){
                archivo >> nombre_aux;
                nombre += " " + nombre_aux; 
            }
            
            string emoji = buscar_tipo_emoji(nombre);
            archivo >> piedra;
            archivo >> madera;
            archivo >> metal;
            archivo >> max_cant_permitidos;

            Edificio* edificio  = new Edificio (nombre, emoji, stoi(piedra), stoi(madera), stoi(metal), stoi   (max_cant_permitidos));

            agregar_edificio(edificio);
        }
        archivo.close();
    }

    return 0;
}

string Edificios::buscar_tipo_emoji(string nombre_edificio){
    string emoji;

    if (nombre_edificio == EDIFICIO_MINA){
        emoji = EMOJI_MINA;
    } else if (nombre_edificio == EDIFICIO_ASERRADERO){
        emoji = EMOJI_ASERRADERO;
    } else if (nombre_edificio == EDIFICIO_FABRICA){
        emoji = EMOJI_FABRICA;
    } else if (nombre_edificio == EDIFICIO_ESCUELA){
        emoji = EMOJI_ESCUELA;
    } else if (nombre_edificio == EDIFICIO_OBELISCO){
        emoji = EMOJI_OBELISCO;
    } else if (nombre_edificio == EDIFICIO_PLANTA_ELECTRICA){
        emoji = EMOJI_PLANTA_ENERGIA;
    }
    
    return emoji;  
}

bool Edificios::existe_edificio_por_nombre(string nombre){
    int i = 0;
    bool encontrado = false;

    while ( ( i < this->total_edificios ) && !(encontrado)){
        if(nombre == this->edificios[i]->devolver_nombre_edificio())
            encontrado = true;
        else
            i++;
    }
    return encontrado;
}

Edificio* Edificios::buscar_edificio_por_nombre(string nombre){
    int i = 0;

    while (nombre != this->edificios[i]->devolver_nombre_edificio()){
        i++;
    }

    return this->edificios[i];
}