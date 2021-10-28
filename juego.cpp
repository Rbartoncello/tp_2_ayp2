#include "juego.h"
#include "colors.h"
#include "emojis.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

Juego::Juego(){
    this->materiales = new Materiales;
    this->edificios = new Edificios;
    this->mapa = new Mapa;
}

Juego::~Juego(){
    delete this->materiales;
    delete this->edificios;
    delete this->mapa;
}

//Juego::Juego(Mapa* mapa, Edificios* edificios, Materiales* materiales){
//   this->mapa = mapa;
//    this->edificios = edificios;
//    this->materiales = materiales;
//}   


void Juego::cargar_juego() {
    this->materiales->procesar_archivo();
    this->edificios->procesar_archivo();
    this->mapa->procesar_archivo();
    this->procesar_archivo_ubicaciones();
}

void Juego::jugar(){

    int opcion_elegida = 0;

    this->mostrar_opciones();

    opcion_elegida = pedir_opcion();

    this->validar_opcion_ingresada(opcion_elegida);

    while(opcion_elegida != GUARDA_SALIR){
        this->procesar_opcion(opcion_elegida);
        this->mostrar_opciones();
        opcion_elegida = this->pedir_opcion();
        this->validar_opcion_ingresada(opcion_elegida);

    }

    this->imprimir_mensaje_guardado();
}

void Juego::procesar_archivo_ubicaciones() {
    ifstream archivo(PATH_UBICACIONES);
    string nombre, fila, columna, basura;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << PATH_UBICACIONES << endl;
    } else {
        while (getline(archivo, nombre, ' ')) {
            getline(archivo, basura, '(');
            getline(archivo, fila, ',');
            getline(archivo, columna, ')');
            getline(archivo, basura);

            Edificio *edificio_auxiliar = this->edificios->buscar_edificio_por_nombre(nombre);
            this->mapa->agregar_edificio_a_casillero(edificio_auxiliar, stoi(fila), stoi(columna));
        }

        archivo.close();
    }
}


void Juego::mensaje_bienvenida(){
    system("clear");
    cout << TXT_BOLD << TXT_DARK_YELLOW_3 << "\
\t\t     ___      .__   __.  _______  ____    ____ .______     ______    __       __       _______.             \n\
\t\t    /   \\     |  \\ |  | |       \\ \\   \\  /   / |   _  \\   /  __  \\  |  |     |  |     /       | _    \n\
\t\t   /  ^  \\    |   \\|  | |  .--.  | \\   \\/   /  |  |_)  | |  |  |  | |  |     |  |    |   (----`(_)      \n\
\t\t  /  /_\\  \\   |  . `  | |  |  |  |  \\_    _/   |   ___/  |  |  |  | |  |     |  |     \\   \\            \n\
\t\t /  _____  \\  |  |\\   | |  '--'  |    |  |     |  |      |  `--'  | |  `----.|  | .----)   |    _         \n\
\t\t/__/     \\__\\ |__| \\__| |_______/     |__|     |__|       \\______/  |_______||__| |_______/    (_)      \n\
                                                                                                              \n"
    << END_COLOR << endl;
    cout << TXT_BOLD << TXT_ORANGE_130 << "\
  ,,                                                                                                        ,,       ,,                   \n\
`7MM                                                        mm                                              db      ,,                   \n\
  MM                                                        MM                                                                       \n\
  MM    ,6Yb.       ,p6bo     ,pWWq.  `7MMpMMMb.  ,pPYbd  mmMMmm  `7Mb,od8 `7MM  `7MM   ,p6bo    ,p6bo    `7MM   ,pWWq.  `7MMpMMMb.  \n\
  MM   8    MM     6M'  OO  6W'   `Wb   MM    MM  8I   `    MM      MM' '    MM    MM  6M'  OO  6M'   OO    MM  6W'   `Wb   MM    MM  \n\
  MM    ,pm9MM     8M       8M     M8   MM    MM  `YMMMa.   MM      MM       MM    MM  8M       8M          MM  8M     M8   MM    MM  \n\
  MM   8M   MM     YM.    , YA.   ,A9   MM    MM  L.   I8   MM      MM       MM    MM  YM.    , YM.    ,    MM  YA.   ,A9   MM    MM  \n\
.JMML.`Moo9^Yo.     YMbmd'   `Ybmd9'  .JMML  JMML.M9mmmP'   `Mbmo .JMML.     `MbodYML.  YMbmd'   YMbmd'   .JMML. `Ybmd9'  .JMML  JMML. \n" 
    << END_COLOR << endl;
    cout << "\
    \t\t\tLuego de muchos años de espera Andy finalmente encontró el lugar perfecto para\n\
    \t\tasentarse y comenzar a armar su pequeño paraíso. Como primera medida decidió nombrar\n\
    \t\tsu nuevo hogar como Andypolis, la maravillosa ciudad de los programadores.\n\
    \t\t\tPoco a poco con el pasar de los días el rumor del surgimiento de una ciudad exclusiva para\n\
    \t\tprogramadores se fue difundiendo y la gente comenzó a llegar a ella y se armó un programa\n\
    \t\tque ayude a contabilizar los materiales y edificios de la ciudad.\n\
    \t\t\tFue tanta la popularidad de este programa que llegaron aún más programadores a ayudar y\n\
    \t\tpasar el diseño de Andypolis al programa, pero algunos de ellos, fanáticos de los\n\
    \t\tvideojuegos, decidieron darle una pequeña vuelta de tuerca…\n\
    \t\t\tPasaron unas semanas y los habitantes de Andypolis nos pidieron ayuda para generar una\n\
    \t\tnueva versión de nuestro programa. Como la dificultad del programa aumentó nos pidieron\n\
    \t\tque dos programadores se unan y desarrollen su programa en conjunto." << endl << endl;
    cout << "\t\t\t\t\t\tPresione [ENTER] para continuar"<< endl;
    cin.get();
    system("clear");
}


void Juego::imprimir_mensaje_error() {
        cout << TXT_BOLD << "\t" << EMOJI_WARNRING << TXT_DARK_RED_1 << TXT_UNDERLINE << " ERROR!! " << END_COLOR
             << EMOJI_WARNRING << endl;
}

void Juego::imprimir_mensaje_esperar(int tiempo) {
        cout << endl;
        cout << "»»Por favor espere que volverá al menu principal en ";
        cout << TXT_BOLD;
        cout << tiempo;
        cout << END_COLOR;
        cout << " segundos..." << EMOJI_RELOJ << endl;
        sleep(tiempo);
        system("clear");
}

void Juego::imprimir_mensaje_opcion_afirmativa_negativa() {
        cout << TXT_BOLD << TXT_GREEN_118  <<  /*AFIRMATIVO  <<*/ END_COLOR << " , en caso afirmativo, o ";
        cout << TXT_BOLD << TXT_LIGHT_RED_9  <<  /*NEGATIVO  <<*/ END_COLOR << " , en caso negativo." << endl;
}

void Juego::mostrar_opciones(){

    cout << TXT_LIGHT_AQUA_43;
    cout << "\t\t\t\t\t╔════╦═════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_UNO    << " ║ Construir edificio por nombre.      ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_DOS    << " ║ Listar los edificios construidos.   ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_TRES   << " ║ Listar todos los edificios.         ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_CUATRO << " ║ Demoler un edificio por coordenada. ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_CINCO  << " ║ Mostrar mapa.                       ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_SEIS  << " ║ Consultar coordenada.               ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_SIETE  << " ║ Mostrar inventario.                 ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_OCHO  << " ║ Recolectar recursos producidos.     ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_NUEVE  << " ║ Lluvia de recursos.                 ║" << endl;
    cout << "\t\t\t\t\t╠────╬─────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_DIEZ   << " ║ Guarda y salir                      ║" << endl;
    cout << "\t\t\t\t\t╚════╩═════════════════════════════════════╝" << endl;
    cout << END_COLOR;
}

void Juego::construir_por_input(){
    string nombre_edificio;
    Edificio* edificio;
    int desea_construir;
    int fila, columna;
    nombre_edificio = this->pedir_nombre();
    if (!this->edificios->existe_edificio_por_nombre(nombre_edificio)){
        cout << "No existe edificio con tal nombre " << endl;
    }else{
        edificio=this->edificios->buscar_edificio_por_nombre(nombre_edificio);
        if (this->calcular_costos(edificio)){
            cout << endl << "La construccion es posible, desea realizarla? 1) SI 2) NO " << endl;
            desea_construir = pedir_opcion();
            validar_opcion_construir(desea_construir);
            if (desea_construir == 1){
                fila = pedir_fila();
                validar_fila(fila);
                columna = pedir_columna();
                validar_columna(columna);
                if (!mapa->se_puede_construir(fila-1,columna-1)){
                    cout << "no se puede construir en esa posicion"<< endl;
                }else{
                    mapa->agregar_edificio_a_casillero(edificio, fila-1, columna-1);
                    cout << "Se construyo el edificio con exito"<< endl;                        }
                }
            if(desea_construir== 2){
                cout << endl << "El edificio no se construyo!" << endl;
            }
        }
    }
}

int Juego::pedir_opcion(){
    int opcion_elegida = ERROR;
    cout << " Por favor ingrese una de las siguientes opciones: ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

bool Juego::es_opcion_valida(int opcion){
    return( ( opcion >= MIN_OPCION ) && ( opcion <= MAX_OPCION ) );
}

void Juego::imprimir_mensaje_error_ingreso(){
    imprimir_mensaje_error();
    cout << "La opción elegida no es una opcion válida, por favor ingrese otra opción: ";
}

void Juego::validar_opcion_ingresada(int &opcion_elegida){
    bool es_valida = es_opcion_valida(opcion_elegida);
    while(!es_valida){
        this->imprimir_mensaje_error_ingreso();

        cin >> opcion_elegida;
        es_valida = es_opcion_valida(opcion_elegida);
    }
}

void Juego::validar_opcion_construir(int &opcion_elegida){
    bool es_valida = (opcion_elegida == 1 || opcion_elegida == 2);
    while(!es_valida){
        this->imprimir_mensaje_error_ingreso();

        cin >> opcion_elegida;
        es_valida = (opcion_elegida == 1 || opcion_elegida == 2);
    }
}

int Juego::pedir_fila(){
    int opcion_elegida = 0;
    cout << " Por favor ingrese la fila: ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

int Juego::pedir_columna(){
    int opcion_elegida = 0;
    cout << " Por favor ingrese la columna: ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

void Juego::validar_fila(int &fila){
    bool es_valida = (fila >= 1 && fila < (this->mapa->devolver_cantidad_filas()+1));
    while(!es_valida){
        this->imprimir_mensaje_error_ingreso();

        cin >> fila;
        es_valida = (fila >= 1 && fila < this->mapa->devolver_cantidad_filas()+1);
    }
}
void Juego::validar_columna(int &columna){
    bool es_valida = (columna >= 1 && columna < this->mapa->devolver_cantidad_columnas()+1);
    while(!es_valida){
        this->imprimir_mensaje_error_ingreso();

        cin >> columna;
        es_valida = (columna >= 1 && columna < this->mapa->devolver_cantidad_columnas()+1);
    }
}

void Juego::procesar_opcion(int opcion){

    switch (opcion){
        case CONSTRUIR_EDIFICIO_NOMBRE:
            this->construir_por_input();
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            this->mapa->mostrar_edificios_construidos();
            break;
        case LISTAR_TODOS_EDIFICIOS:
            this->edificios->mostar();
            break;
        case DEMOLER_EDIFICIO_COORDENADA:
            break;
        case MOSTAR_MAPA:
            this->mapa->mostrar();
            break;
        case CONSULTAR_COORDENADA:
            break;
        case MOSTRAR_INVENTARIO:
            this->materiales->mostrar();
            break;
        case RECOLECTAR_RECURSOS:
            break;
        case LLUVIA_RECURSOS:
            break;
    }
}

void Juego::imprimir_mensaje_guardado() {
    system("clear");
    cout << "Cargando... " << EMOJI_LOANDING << endl;

    sleep(2);
    system("clear");

    cout << "\t»Se ha guardado con exito " << EMOJI_HECHO << endl;
    cout << "\t»Adios«" << endl;


}

string Juego::pedir_nombre(){
    string nombre_dado;
    cout << "Ingrese el nombre del edificio: ";
    cin >> nombre_dado;
    return nombre_dado;
}

bool Juego::calcular_costos(Edificio* edificio){
    bool madera_suficiente = false;
    bool metal_suficiente = false;
    bool piedra_suficiente = false;
    bool maximo_permitido = false;
    int cantidad_edificio = this->mapa->cantidad_edificio_construido(edificio->devolver_nombre_edificio());


    
    if(edificio->devolver_piedra()  <= materiales->devolver_cantidad_material("piedra")){
        cout << endl << "Cantidad de Piedra: " << TXT_GREEN_34 << "✔" << END_COLOR << endl;
        piedra_suficiente = true;
    }else{
        cout << endl << "Cantidad de Piedra: " << TXT_RED_124 << "❌ (falta :" << (edificio->devolver_piedra() - materiales->devolver_cantidad_material("piedra")) << ")" << END_COLOR << endl;
    }

    if(edificio->devolver_madera()  <= materiales->devolver_cantidad_material("madera")){
        cout << "Cantidad de Madera:" << TXT_GREEN_34 << " ✔" << END_COLOR << endl;
        madera_suficiente = true;
    }else{
        cout << "Cantidad de Madera: " << TXT_RED_124 << "❌ (falta :" << (edificio->devolver_madera() - materiales->devolver_cantidad_material("madera")) << ")" << END_COLOR << endl;
    }

    if(edificio->devolver_metal()  <= materiales->devolver_cantidad_material("metal")){
        cout << "Cantidad de Metal:" << TXT_GREEN_34 << " ✔" << END_COLOR << endl;
        metal_suficiente = true;
    }else{
        cout << "Cantidad de Metal:" << TXT_RED_124 << " ❌ (falta :" << (edificio->devolver_metal() - materiales->devolver_cantidad_material("metal")) << ")" << END_COLOR << endl;
    }

    if(cantidad_edificio < edificio->devolver_maxima_cantidad_permitidos()){
        cout << "Cantidad de edificios Permitida:<" << TXT_GREEN_34 << " ✔️" << END_COLOR << endl;
        maximo_permitido = true;
    }else{
        cout << "Cantidad de edificios Permitida:" << TXT_RED_124 <<" ❌" << END_COLOR << endl;
    }

    return metal_suficiente && madera_suficiente && piedra_suficiente && maximo_permitido;

}

void Juego::demoler_edificio_por_coordenada(){
    int fila, columna;

    

}