#include "mapa.h"
#include "juego.h"
#include "materiales.h"
#include "emojis.h"
#include "constantes.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>  
#include <unistd.h>
#include <iomanip>

using namespace std;

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
                        this->casilleros[i][j] = new Casillero_inaccesible(tipo_terreno, j, i);
                        break;
                    case CAMINO:
                        this->casilleros[i][j] = new Casillero_transitable(tipo_terreno, j, i);
                        break;
                    case TERRENO:
                        this->casilleros[i][j] = new Casillero_construible(tipo_terreno, j, i);
                        break;
                }
            }
        }
    }
}

int Mapa::procesar_archivo(){
    ifstream archivo(PATH_MAPA);
    
    if (!(archivo.is_open())){
        cout << "No se puedo abrir el archivo: " << PATH_MAPA << endl;
        return ERROR;
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

    return 0;
}

void Mapa::mostrar_objetos_mapa(){
    cout << endl;
    cout << TXT_LIGHT_PURPLE_104;
    cout <<"■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■" << endl;
    cout << END_COLOR;
    cout << TXT_LIGHT_PURPLE_104 << "║" << END_COLOR << "\t" << TXT_UNDERLINE << TXT_BOLD << "Edificio:\t\t\tMateriales" << END_COLOR << TXT_LIGHT_PURPLE_104 << "\t    ║" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "■" << END_COLOR << "\t-Mina ( " << EMOJI_MINA << " )\t\t\t-Piedra ( " << EMOJI_PIEDRA << "  )" << TXT_LIGHT_PURPLE_104 << "\t    ■" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "║" << END_COLOR << "\t-Aserradero ( " << EMOJI_ASERRADERO << " )\t\t-Madera ( " << EMOJI_MADERA << "  )" << TXT_LIGHT_PURPLE_104 << "\t    ║" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "■" << END_COLOR << "\t-Fabrica ( " << EMOJI_FABRICA << " )\t\t\t-Metal ( " << EMOJI_METAL << " )" << TXT_LIGHT_PURPLE_104 << "\t    ■" << END_COLOR <<endl;
    cout << TXT_LIGHT_PURPLE_104 << "║" << END_COLOR << "\t-Escuela ( " << EMOJI_ESCUELA << " )"  TXT_LIGHT_PURPLE_104 << "\t\t\t\t\t    ║" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "■" << END_COLOR << "\t-Obelisco ( " << EMOJI_OBELISCO << " )" << TXT_LIGHT_PURPLE_104 << "\t\t\t\t    ■" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104 << "║" << END_COLOR << "\t-Planta eléctrica ( " << EMOJI_PLANTA_ENERGIA << " )" << TXT_LIGHT_PURPLE_104 << "\t\t\t    ║" << END_COLOR << endl;
    cout << TXT_LIGHT_PURPLE_104;
    cout <<"■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■ ═ ■" << endl;
    cout << END_COLOR;
    cout << endl;
}

void Mapa::mostrar(){
    system("clear");

    for (int i = 0; i <= this->cantidad_columnas + 1; i++){
        if (i == 0)
            cout << "\t";
        cout << BGND_BROWN_94 << "  " << END_COLOR;
    }
    cout << endl;

    for (int i = 0; i < this->cantidad_filas; i++){
        cout << "\t" << BGND_BROWN_94 << "  " << END_COLOR;
        for (int j = 0; j < this->cantidad_columnas; j++){
            this->casilleros[i][j]->mostrar();
        }
        if ( i < 10 )
            cout << BGND_BROWN_94 << i << " " << END_COLOR;
        else
            cout << BGND_BROWN_94 << i << END_COLOR;
        cout << endl;
    }

    for (int i = 0; i <= this->cantidad_columnas; i++){
        if (i == 0)
            cout << "\t" << BGND_BROWN_94 << "  " << END_COLOR;
        if ( ( i < this->cantidad_columnas ) && ( i < 10 ) )
            cout << BGND_BROWN_94 << i << " " << END_COLOR;
        else if ( ( i < this->cantidad_columnas ))
            cout << BGND_BROWN_94 << i << END_COLOR;
        else if ( i == this->cantidad_columnas )
            cout << BGND_BROWN_94 << "  " << END_COLOR;
    }

    mostrar_objetos_mapa();
}

void Mapa::agregar_edificio_a_casillero(Edificio* edificio, int fila, int columna){
    this->casilleros[fila][columna]->agregar_edificio(edificio);
}

void Mapa::mostrar_edificios_construidos(){
    system("clear");

    cout << TXT_BOLD;
    cout << "\t\t╔═══════════════════════╦══════╦═════════╦══════════════════════╗" << endl;
    cout << "\t\t║ Edificios construidos ║ Fila ║ Columna ║ Cantidad construidos ║" << endl;
    cout << "\t\t╠═══════════════════════╬══════╬═════════╬══════════════════════╣" << endl;
    cout << END_COLOR;

    bool hay_edificios = false;

    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            if ( ( this->casilleros[i][j]->devolver_tipo_terreno() == TERRENO ) && ( this->casilleros[i][j]->esta_ocupado() ) ){
                hay_edificios = true;

                this->casilleros[i][j]->mostrar_casillero();
                cout << this->cantidad_edificio_construido(this->casilleros[i][j]->devolver_nombre_edificio()) << setfill(' ') << setw(14) << "║" << endl;
                if( ( i == this->cantidad_filas - 1 ) && ( j == this->cantidad_columnas - 1 ) )
                    cout << "\t\t╚═══════════════════════╩══════╩═════════╩══════════════════════╝" << endl;
                else
                    cout << "\t\t╠───────────────────────┼──────┼─────────┼──────────────────────╣" << endl;
            }
        }
    }

    if (!hay_edificios){
        cout << TXT_BOLD;
        cout << "\t\t║ " << TXT_RED_196 << setfill(' ') << setw(49) << "NO HAY NINGUN EDIFICIO CONSTRUIDO" << setfill(' ') << setw(16) << END_COLOR << " ║" << endl;
        cout << "\t\t╚═══════════════════════════════════════════════════════════════╝" << endl;
    }
    
}

int Mapa::cantidad_edificio_construido(string nombre){
    int cantidad = 0;
    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            if ( this->casilleros[i][j]->devolver_tipo_terreno() == TERRENO && this->casilleros[i][j]->esta_ocupado() && this->casilleros[i][j]->devolver_nombre_edificio()==nombre){
                cantidad ++;
            }
        }
    }
    return cantidad;
}

int Mapa::devolver_cantidad_columnas(){
    return this->cantidad_columnas;
}

int Mapa::devolver_cantidad_filas(){
    return this->cantidad_filas;
}

Casillero *Mapa::devolver_casillero(int fila, int columna){
    return this->casilleros[fila][columna];
}

bool Mapa::se_puede_construir(int fila, int columna){
    return( !( this->casilleros[fila][columna]->esta_ocupado() ) && ( this->casilleros[fila][columna]->devolver_tipo_terreno() == TERRENO ) );
}

char Mapa::devolver_tipo_casillero(int fila, int columna){
    return this->casilleros[fila][columna]->devolver_tipo_terreno();
}

bool Mapa::casillero_ocupado(int fila, int columna){
    return this->casilleros[fila][columna]->esta_ocupado();
}

Edificio* Mapa::devolver_edificio(int fila, int columna){
    return this->casilleros[fila][columna]->devolver_edificio();
}

void Mapa::quitar_edificio_de_casillero(int fila, int columna){
    this->casilleros[fila][columna]->quitar_edificio();
}

void Mapa::imprimir_resumen_casillero(int fila, int columna){
    this->casilleros[fila][columna]->imprimir_resumen();
}

int Mapa::numero_aleatorio(int desde, int hasta){
    srand (( unsigned)time(NULL));
    int numero = ( desde + rand() % hasta );
    
    while (numero > hasta)
        numero = ( desde + rand() % hasta );
    return numero;
}

bool Mapa::se_puede_generar_material(int fila, int columna){
    return ( !( casillero_ocupado(fila, columna) ) && ( this->casilleros[fila][columna]->devolver_tipo_terreno() == CAMINO) );
}

void Mapa::agregar_materiales(std::string material, int minimo, int maximo){
    int maximos_materiales = numero_aleatorio(minimo, maximo);

    for (int i = 0; i < maximos_materiales; i++){
        int fila_aleatoria = numero_aleatorio(0 , this->cantidad_filas);
        int columna_aleatoria = numero_aleatorio(0 , this->cantidad_columnas);

        while ( !( se_puede_generar_material(fila_aleatoria, columna_aleatoria) ) ){
            fila_aleatoria = numero_aleatorio(0 , this->cantidad_filas);
            columna_aleatoria = numero_aleatorio(0 , this->cantidad_columnas);
        }
        this->casilleros[fila_aleatoria][columna_aleatoria]->agregar_material(material);
    }
}
bool Mapa::hay_lugar_minimo_material(){
    bool hay_lugar = false;
    int sumatoria_lugares = 0;
    int i = 0;
    int j = 0;

    while( ( i < this->devolver_cantidad_filas() ) && !(hay_lugar) ){
        while( ( j < this->devolver_cantidad_columnas() ) && !(hay_lugar) ){
            if(se_puede_generar_material(i, j))
                sumatoria_lugares++;
            if (sumatoria_lugares == 7)
                hay_lugar = true;
            else
                j++;
            
        }
        j = 0;
        i++;
    }

    return hay_lugar;
}

void Mapa::lluvia_recursos(){
    system("clear");
    if (hay_lugar_minimo_material()){
        
        cout << "\tLluvia de recursos ... " << EMOJI_LLUVIA << " " << EMOJI_LLUVIA_CON_TRUENOS << " " << EMOJI_LLUVIA << endl;
        cout << "\t[Por favor espere]" << endl;

        agregar_materiales(PIEDRA, MIN_GENERAR_PIEDRA, MAX_GENERAR_PIEDRA);
        agregar_materiales(MADERA, MIN_GENERAR_MADERA, MAX_GENERAR_MADERA);
        agregar_materiales(METAL, MIN_GENERAR_METAL, MAX_GENERAR_METAL);

        system("clear");
        cout << TXT_BOLD;
        cout << "\tSe ha agregado recursos al mapa con exito " << EMOJI_HECHO << endl << endl;
        cout << END_COLOR;
        sleep(1);
    } else {
        cout << "No es posible agregar materiales en el mapa ya que no hay más lugar" << endl;
        sleep(2);
    }
    system("clear");
}

bool Mapa::hay_algun_edificio_construido(){
    bool hay_edificio = false;
    int i = 0;

    while ( ( i < this->devolver_cantidad_filas() ) && !(hay_edificio) ){
        int j = 0;
        while( ( j < this->devolver_cantidad_filas() ) && !(hay_edificio) ){
            if( this->devolver_casillero(i,j)->esta_ocupado() )
                hay_edificio = true;
            else{
                j++;
            }
        }
        i++;
    }

    return hay_edificio;
}

void Mapa::agregar_material_a_casillero(string material, int fila, int columna){
    this->casilleros[fila][columna]->agregar_material(material);
}

void Mapa::cerrar_ubicaciones(string path){
    ofstream archivo_ubicaciones(path);

    for (int i = 0; i < this->cantidad_filas; i++){
        for (int j = 0; j < this->cantidad_columnas; j++){
            if(casilleros[i][j]->esta_ocupado()){
                if(casilleros[i][j]->devolver_tipo_terreno() == TERRENO){
                    archivo_ubicaciones << this-> casilleros[i][j]->devolver_nombre_edificio() << " (" << i << ", " << j << ")" "\n";
                }
                if(casilleros[i][j]->devolver_tipo_terreno() == CAMINO){
                    archivo_ubicaciones << this-> casilleros[i][j]->devolver_nombre_material() << " (" << i << ", " << j << ")" "\n";
                    delete casilleros[i][j]->devolver_material();
                }
            }
            
        }
        
    }

}