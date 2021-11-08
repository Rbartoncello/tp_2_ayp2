#include "juego.h"
#include "colors.h"
#include "emojis.h"
#include "materiales.h"
#include "constantes.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

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

int Juego::cargar_juego() {
    int ejecucion = 0;

    if( this->materiales->procesar_archivo() == ERROR )
        ejecucion = ERROR;
    else if( this->edificios->procesar_archivo() == ERROR )
        ejecucion = ERROR;
    else if ( this->mapa->procesar_archivo() == ERROR )
        ejecucion = ERROR;
    else if( this->procesar_archivo_ubicaciones() == ERROR )
        ejecucion = ERROR;

    return ejecucion;
}

int Juego::procesar_archivo_ubicaciones() {
    ifstream archivo(PATH_UBICACIONES);
    string nombre, fila, columna, basura, nombre_aux;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << PATH_UBICACIONES << endl;
        return ERROR;
    } else {
        while (getline(archivo, nombre, ' ')) {
            if (nombre == PLANTA){
                archivo >> nombre_aux;
                nombre +=  " " + nombre_aux;
            }
            getline(archivo, basura, '(');
            getline(archivo, fila, ',');
            getline(archivo, columna, ')');
            getline(archivo, basura);

            if(edificios->existe_edificio_por_nombre(nombre)){
                Edificio *edificio_auxiliar = this->edificios->buscar_edificio_por_nombre(nombre);
                this->mapa->agregar_edificio_a_casillero(edificio_auxiliar, stoi(fila), stoi(columna));
            }
            if(materiales->existe_material_por_nombre(nombre)){
                this->mapa->agregar_material_a_casillero(nombre, stoi(fila), stoi(columna));
            }
        }

        archivo.close();
    }
    return 0;
}

void Juego::mensaje_bienvenida(){
    system("clear");
    cout << TXT_BOLD << TXT_DARK_YELLOW_3 << "\
\t\t     ___      .__   __.  _______  ____    ____ .______     ______    __       __       _______    \n\
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

void Juego::mostrar_opciones(){

    cout << TXT_LIGHT_AQUA_43;
    cout << "\t\t\t\t\t╔════╦═══════════════════════════════════════╗" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_UNO << " ║" << END_COLOR <<" Construir edificio por nombre " << EMOJI_EDIFICIO_CONSTRUCION << TXT_LIGHT_AQUA_43 << "       ║" << endl;
    cout << "\t\t\t\t\t╠────╬───────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_DOS << " ║" << END_COLOR <<" Listar los edificios construidos " << EMOJI_LISTA << TXT_LIGHT_AQUA_43 << "   ║" << endl;
    cout << "\t\t\t\t\t╠────╬───────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_TRES << " ║" << END_COLOR <<" Listar todos los edificios " << EMOJI_LISTA  << TXT_LIGHT_AQUA_43 << "         ║" << endl;
    cout << "\t\t\t\t\t╠────╬───────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_CUATRO << " ║" << END_COLOR <<" Demoler un edificio por coordenada " << EMOJI_MINA  << TXT_LIGHT_AQUA_43 <<" ║" << endl;
    cout << "\t\t\t\t\t╠────╬───────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_CINCO << " ║" << END_COLOR <<" Mostrar mapa " << EMOJI_MAPA  << TXT_LIGHT_AQUA_43 << "                        ║" << endl;
    cout << "\t\t\t\t\t╠────╬───────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_SEIS << " ║" << END_COLOR <<" Consultar coordenada " << EMOJI_BRUJULA << TXT_LIGHT_AQUA_43 << "               ║" << endl;
    cout << "\t\t\t\t\t╠────╬───────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_SIETE << " ║" << END_COLOR <<" Mostrar inventario " << EMOJI_INVENTARIO << TXT_LIGHT_AQUA_43 << "                 ║" << endl;
    cout << "\t\t\t\t\t╠────╬───────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_OCHO << " ║" << END_COLOR <<" Recolectar recursos producidos " << EMOJI_BUSQUEDA << TXT_LIGHT_AQUA_43 << "     ║" << endl;
    cout << "\t\t\t\t\t╠────╬───────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_NUEVE << " ║" << END_COLOR <<" Lluvia de recursos " << EMOJI_LLUVIA << TXT_LIGHT_AQUA_43 << "                  ║" << endl;
    cout << "\t\t\t\t\t╠────╬───────────────────────────────────────╣" << endl;
    cout << "\t\t\t\t\t║ " << EMOJI_DIEZ << " ║" << END_COLOR <<" Guarda y salir " << EMOJI_GUARDA_SALIR << TXT_LIGHT_AQUA_43 << "                     ║" << endl;
    cout << "\t\t\t\t\t╚════╩═══════════════════════════════════════╝" << endl;
    cout << END_COLOR;
}

void Juego::construir_edificio_nombre(){
    
    string nombre_edificio = this->pedir_nombre();

    if (!this->edificios->existe_edificio_por_nombre(nombre_edificio)){
        cout << "No se ha encontrado el edificio: " << nombre_edificio << endl;
        imprimir_mensaje_esperar(2);
    } else{
        Edificio* edificio=this->edificios->buscar_edificio_por_nombre(nombre_edificio);

        if (this->calcular_costos(edificio)){

            cout << endl << "\tLa construccion es posible, desea realizarla? ";
            cout << TXT_BOLD << TXT_GREEN_118 <<  AFIRMATIVO << ") SI ";
            cout << TXT_BOLD << TXT_LIGHT_RED_9 <<  NEGATIVO << ") NO " << END_COLOR << endl;

            int desea_construir = pedir_opcion();
            validar_opcion_construir(desea_construir);

            if (desea_construir == AFIRMATIVO){
                mapa->mostrar();

                int fila = pedir_fila();
                validar_fila(fila);

                int columna = pedir_columna();
                validar_columna(columna);

                if ( !(mapa->se_puede_construir(fila,columna) ) ){
                    cout << "No sera posible construir en la posicion ( " << fila << ", " << columna << " )" << endl;
                    
                    imprimir_mensaje_esperar(2);
                    system("clear"); 
                } else{
                    mapa->agregar_edificio_a_casillero(edificio, fila, columna);
                    
                    materiales->sumar_restar_cantidad_material( -( edificio->devolver_piedra() ),PIEDRA );
                    materiales->sumar_restar_cantidad_material( -( edificio->devolver_madera() ),MADERA );
                    materiales->sumar_restar_cantidad_material( -( edificio->devolver_metal() ),METAL );
                    
                    system("clear");
                    cout << "\tConstruyendo " << nombre_edificio << "( " << edificio->devolver_emoji() << " ) ... " << EMOJI_EDIFICIO_CONSTRUCION << endl;

                    sleep(2);
                    system("clear");
                    cout << TXT_BOLD;
                    cout << "\tSe ha agregado con exito " << EMOJI_HECHO << endl << endl;
                    cout << END_COLOR;
    
                    sleep(2);
                    system("clear");                        
                }
            } else {
                system("clear");
            }
        } else{
            cout << endl << "El edificio no se ha construido!" << endl;
            imprimir_mensaje_esperar(5);
        }
    }
}

int Juego::pedir_opcion(){
    int opcion_elegida = ERROR;
    cout << "\tPor favor ingrese una de las siguientes opciones: ";
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
    bool es_valida = (opcion_elegida == AFIRMATIVO || opcion_elegida == NEGATIVO);
    while(!es_valida){
        this->imprimir_mensaje_error_ingreso();

        cin >> opcion_elegida;
        es_valida = (opcion_elegida == AFIRMATIVO || opcion_elegida == NEGATIVO);
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
    bool es_valida = (fila >= 0 && fila < (this->mapa->devolver_cantidad_filas()));
    while(!es_valida){
        this->imprimir_mensaje_error_ingreso();

        cin >> fila;
        es_valida = (fila >= 0 && fila < this->mapa->devolver_cantidad_filas());
    }
}

void Juego::validar_columna(int &columna){
    bool es_valida = (columna >= 0 && columna < this->mapa->devolver_cantidad_columnas());
    while(!es_valida){
        this->imprimir_mensaje_error_ingreso();

        cin >> columna;
        es_valida = (columna >= 1 && columna < this->mapa->devolver_cantidad_columnas());
    }
}

void Juego::procesar_opcion(int opcion){

    switch (opcion){
        case CONSTRUIR_EDIFICIO_NOMBRE:
            this->construir_edificio_nombre();
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            this->mapa->mostrar_edificios_construidos();
            this->mensaje_enter_continuar();
            break;
        case LISTAR_TODOS_EDIFICIOS:
            this->edificios->mostar(this->mapa);
            this->mensaje_enter_continuar();
            break;
        case DEMOLER_EDIFICIO_COORDENADA:
            this->demoler_edificio_por_coordenada();
            break;
        case MOSTAR_MAPA:
            this->mapa->mostrar();
            this->mensaje_enter_continuar();
            break;
        case CONSULTAR_COORDENADA:
            this->mostrar_coordenada();
            this->mensaje_enter_continuar();
            break;
        case MOSTRAR_INVENTARIO:
            this->materiales->mostrar();
            this->mensaje_enter_continuar();
            break;
        case RECOLECTAR_RECURSOS:
            this->materiales->recolectar_recursos_producidos(mapa);
            break;
        case LLUVIA_RECURSOS:
            this->mapa->lluvia_recursos();
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
    system("clear");
    string nombre_dado;
    cout << "Ingrese el nombre del edificio: ";
    getline(cin, nombre_dado);
    getline(cin, nombre_dado);
    return nombre_dado;
}

bool Juego::calcular_costos(Edificio* edificio){
   
    bool piedra_suficiente = materiales->hay_suficiente_material(edificio, PIEDRA);
    bool madera_suficiente = materiales->hay_suficiente_material(edificio, MADERA);
    bool metal_suficiente = materiales->hay_suficiente_material(edificio, METAL);

    bool maximo_permitido = false;
    int cantidad_edificio = this->mapa->cantidad_edificio_construido(edificio->devolver_nombre_edificio());

    if(cantidad_edificio < edificio->devolver_maxima_cantidad_permitidos()){
        cout << endl << "\t»Cantidad de edificios Permitida: " << TXT_GREEN_34 << EMOJI_HECHO << END_COLOR << endl;
        maximo_permitido = true;
    } else{
        cout << endl << "\t»Cantidad de edificios Permitida: " << TXT_RED_124 << EMOJI_MAL << END_COLOR << endl;
    }

    return (metal_suficiente && madera_suficiente && piedra_suficiente && maximo_permitido);

}

void Juego::demoler_edificio_por_coordenada(){
    system("clear");

    if(this->mapa->hay_algun_edificio_construido()){
        mapa->mostrar();
        int fila = pedir_fila(); 
        validar_fila(fila);

        int columna = pedir_columna();
        validar_columna(columna);

        if ( ( this->mapa->devolver_tipo_casillero(fila, columna) == TERRENO ) && ( this->mapa->casillero_ocupado(fila, columna) ) ){
            Edificio* edificio = this->mapa->devolver_edificio(fila, columna);
            this->mapa->quitar_edificio_de_casillero(fila,columna);

            materiales->sumar_restar_cantidad_material( ( edificio->devolver_piedra())/2 ,PIEDRA );
            materiales->sumar_restar_cantidad_material( ( edificio->devolver_madera())/2 ,MADERA );
            materiales->sumar_restar_cantidad_material( ( edificio->devolver_metal())/2 ,METAL );

            system("clear");
            cout << "\tDemoliendo " << edificio->devolver_nombre_edificio() << "( " << edificio->devolver_emoji() << " ) ... " << EMOJI_PARED << " " << EMOJI_MARTILLO << endl;
            sleep(2);

            system("clear");
            cout << TXT_BOLD;
            cout << "\tSe ha demolido con exito " << EMOJI_HECHO << endl << endl;
            cout << END_COLOR;

            sleep(2);
            system("clear");
        } else{
            cout << endl << "No se puede demoler este casillero"<< endl;
            imprimir_mensaje_esperar(2);
        }
    } else {
        imprimir_mensaje_error();
        cout << "\tNo hay ningun edificio construido" << endl;
        imprimir_mensaje_esperar(5);
    }
}

void Juego::mensaje_enter_continuar(){
    cout << "Presione [ENTER] para continuar"<< endl;
    cin.get();
    cin.get();
    system("clear");
}

void Juego::mostrar_coordenada(){
    system("clear");

    int fila = this->pedir_fila();
    this->validar_fila(fila);

    int columna = this->pedir_columna();
    this->validar_columna(columna);

    system("clear");
    this->mapa->imprimir_resumen_casillero(fila, columna);    
}

void Juego::cerrar(){
    this->materiales->cerrar();
    this->mapa->cerrar_ubicaciones(PATH_UBICACIONES);
}