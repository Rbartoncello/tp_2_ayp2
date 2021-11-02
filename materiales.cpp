#include "materiales.h"
#include "juego.h"
#include "colors.h"
#include "emojis.h"
#include "edificios.h"
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

int Materiales::procesar_archivo(){

    ifstream archivo(PATH_MATERIALES);
    string nombre, cantidad;

    if (!archivo.is_open()){
        cout << "No se pudo abrir el archivo: " << PATH_MATERIALES << endl;
        return ERROR;
    } else {
        while ( archivo >> nombre ){
            archivo >> cantidad;

            agregar_material(new Material(nombre, stoi(cantidad)));
        }

        archivo.close();
    }

    return 0;
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
}


int Materiales::devolver_cantidad_material(string nombre){
    int i = 0;

    while (nombre != this->materiales[i]->devolver_nombre_material()){
        i++;
    }

    return this->materiales[i]->devolver_cantidad_material();
}

bool Materiales::hay_suficiente_material(Edificio* edificio, string material){
    bool material_suficiente = false;

    if(edificio->devolver_cantidad_material(material) <= devolver_cantidad_material(material)){
        cout << "\t»Cantidad de " << material <<": " << TXT_GREEN_34 << EMOJI_HECHO << END_COLOR << endl;
        material_suficiente = true;
    } else{
        cout << "\t»Cantidad de " << material <<": " << TXT_RED_124 << EMOJI_MAL <<" (falta :" << (edificio->devolver_cantidad_material(material) - devolver_cantidad_material(material)) << ")" << END_COLOR << endl;
    }

    return material_suficiente;
}

void Materiales::sumar_restar_cantidad_material(int cantidad, string nombre){
    int i = 0;

    while (nombre != this->materiales[i]->devolver_nombre_material()){
        i++;
    }

    this->materiales[i]->sumar_restar(cantidad);
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
        for (int j = 0; j < mapa->devolver_cantidad_columnas(); j++){
            if( (mapa->devolver_casillero(i, j)->esta_ocupado()) ){
                if(mapa->devolver_casillero(i, j)->devolver_nombre_edificio() == EDIFICIO_MINA){
                    int posicion = this->buscar_material(PIEDRA);
                    materiales[posicion]->sumar_restar(AUMENTAR_CANTIDAD_PIEDRA);

                } else if(mapa->devolver_casillero(i, j)->devolver_nombre_edificio() == EDIFICIO_ASERRADERO){
                    int posicion = this->buscar_material(MADERA);
                    materiales[posicion]->sumar_restar(AUMENTAR_CANTIDAD_MADERA);

                } else if(mapa->devolver_casillero(i, j)->devolver_nombre_edificio() == EDIFICIO_FABRICA){
                    int posicion = this->buscar_material(METAL);
                    materiales[posicion]->sumar_restar(AUMENTAR_CANTIDAD_METAL);
                }
            }
        }
    }
    imprimir_mensaje_recolectando_recursos_producidos();
}

void Materiales::imprimir_mensaje_recolectando_recursos_producidos() {
    cout << "\tRecolectando recursos producidos... " << EMOJI_BUSQUEDA << endl;

    sleep(2);
    system("clear");

    cout << TXT_BOLD;
    cout << "\t»Se han recolectado los recursos producidos con exito" << EMOJI_HECHO <<endl;
    cout << END_COLOR;
    
    sleep(2);
    system("clear");
}

bool Materiales::existe_material_por_nombre(string nombre){
    int i = 0;
    bool encontrado = false;

    while ( ( i < this->total_materiales ) && !(encontrado)){
        if(nombre == this->materiales[i]->devolver_nombre_material())
            encontrado = true;
        else
            i++;
    }
    return encontrado;
}

void Materiales::cerrar(){
    ofstream archivo_materiales(PATH_MATERIALES);

    int cantidad_de_materiales = this->total_materiales;

    for (int i = 0; i < cantidad_de_materiales; i++){
        archivo_materiales << this -> materiales[i] ->devolver_nombre_material() << " " << this -> materiales[i] ->devolver_cantidad_material() << "\n";
    }


}