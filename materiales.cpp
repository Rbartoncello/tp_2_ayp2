#include "materiales.h"
#include "juego.h"
#include "colors.h"
#include "emojis.h"
#include "edificios.h"
#include "constantes.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

Materiales::Materiales(){
    this->total_materiales = 0;
}

Materiales::~Materiales(){
    for (int i = 0; i < this->total_materiales; i++){
        delete this->materiales[i];
    }
    delete [] this->materiales;
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

bool Materiales::hay_suficiente_material(Edificio* edificio, string material){
    bool material_suficiente = false;

    if(edificio->devolver_cantidad_material(material) <= devolver_cantidad_material(material))
        material_suficiente = true;

    return material_suficiente;
}

void Materiales::imprimir_materiales_necesarios(Edificio* edificio){

    cout << TXT_BOLD;
    cout << "\t╔═════════╦═══════════════════════╦══════════════════════════╦════════╗" << endl;
    cout << "\t║/////////║ Materiales necesarios ║ Materiales en inventario ║ Estado ║" << endl;
    cout << "\t╠═════════╬═══════════════════════╬══════════════════════════╬════════╣" << endl;
    cout << END_COLOR;

    int piedra_inventario = devolver_cantidad_material(PIEDRA);
    int piedra_edificio = edificio->devolver_cantidad_material(PIEDRA);
    
    string status = chequear_status(piedra_inventario, piedra_edificio);
    cout << "\t║ " << PIEDRA << "  │" << setfill(' ') << setw(12) << piedra_edificio << setfill(' ') << setw(14) << "│" << setfill(' ') << setw(14) << piedra_inventario << setfill(' ') << setw(18) << "│   " << status << "   ║" << endl;
    cout << "\t╠─────────┼───────────────────────┼──────────────────────────┼────────╣" << endl;
    
    int madera_inventario = devolver_cantidad_material(MADERA);
    int madera_edificio = edificio->devolver_cantidad_material(MADERA);

    status = chequear_status(madera_inventario, madera_edificio);
    cout << "\t║ " << MADERA << "  │" << setfill(' ') << setw(12) << madera_edificio << setfill(' ') << setw(14) << "│" << setfill(' ') << setw(14) << madera_inventario << setfill(' ') << setw(18) << "│   " << status << "   ║" << endl;
    cout << "\t╠─────────┼───────────────────────┼──────────────────────────┼────────╣" << endl;
    
    int metal_inventario = devolver_cantidad_material(METAL);
    int metal_edificio = edificio->devolver_cantidad_material(METAL);

    status = chequear_status(metal_inventario, metal_edificio);
    cout << "\t║  " << METAL << "  │" << setfill(' ') << setw(12) << metal_edificio << setfill(' ') << setw(14) << "│" << setfill(' ') << setw(14) << metal_inventario << setfill(' ') << setw(18) << "│   " << status << "   ║" << endl;
    cout << "\t╚═════════╩═══════════════════════╩══════════════════════════╩════════╝" << endl;
}

void Materiales::sumar_restar_cantidad_material(int cantidad, string nombre_material){
    int i = 0;

    while ( nombre_material != this->materiales[i]->devolver_nombre_material() )
        i++;

    this->materiales[i]->sumar_restar(cantidad);
}

void Materiales::recolectar_recursos_producidos(Mapa* mapa){    
    for (int i = 0; i < mapa->devolver_cantidad_filas(); i++){
        for (int j = 0; j < mapa->devolver_cantidad_columnas(); j++){
            if( ( mapa->devolver_casillero(i, j)->esta_ocupado() ) && (mapa->devolver_casillero(i, j)->devolver_tipo_terreno() == TERRENO )  ){
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

int Materiales::devolver_cantidad_material(string nombre){
    int i = 0;

    while (nombre != this->materiales[i]->devolver_nombre_material())
        i++;

    return this->materiales[i]->devolver_cantidad_material();
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

void Materiales::imprimir_mensaje_recolectando_recursos_producidos() {
    system("clear");
    cout << "\tRecolectando recursos producidos... " << EMOJI_BUSQUEDA << endl;

    sleep(2);
    system("clear");

    cout << TXT_BOLD;
    cout << "\t»Se han recolectado los recursos producidos con exito" << EMOJI_HECHO <<endl;
    cout << END_COLOR;
    
    sleep(2);
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

string Materiales::chequear_status(int cant_material_inventario, int cant_material_necesario){
    string status = EMOJI_MAL;

    if (cant_material_inventario >= cant_material_necesario)
        status = EMOJI_HECHO;

    return status;
}