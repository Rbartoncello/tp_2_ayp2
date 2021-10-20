//
// Created by Juan Martín Iglesias on 28/9/21.
//
#include <iostream>
#include "juego.h"
#include <fstream>

using namespace std;

const int LISTAR_MATERIALES = 1;
const int CONSTRUIR_EDIFICIO = 2;
const int LISTAR_EDIFICIOS_CONSTRUIDOS = 3;
const int LISTAR_EDIFICIOS = 4;
const int DEMOLER_EDIFICIO = 5;
const int ERROR = -1;

const string COLOR_ROJO  =  "\e[0;31m";
const string COLOR_VERDE  =  "\e[0;32m";
const string COLOR_POR_DEFECTO  =  "\e[0m";





void mostrar_introduccion(){


    cout <<endl << endl << "\n"
            "////////////////    ((((((            ((((    %%%%%%%%%%%%        &&&&            &&&&    @@@@@@@@@@@@@@      ????????????????    {{{{{{            <<<<<<   #################\n"
            "////////////////    ((((((((          ((((    %%%%      %%%%      &&&&&&        &&&&&&    @@@@@@      @@@@    ????????????????    {{{{{{            <<<<<<   #################\n"
            "////        ////    ((((  ((((        ((((    %%%%        %%%%      &&&&&&    &&&&&&      @@@@@@      @@@@    ????        ????    {{{{{{            <<<<<<   #####\n"
            "////        ////    ((((    ((((      ((((    %%%%        %%%%        &&&&&&&&&&&&        @@@@@@      @@@@    ????        ????    {{{{{{            <<<<<<   #################\n"
            "////////////////    ((((      ((((    ((((    %%%%        %%%%          &&&&&&&&          @@@@@@@@@@@@@@      ????        ????    {{{{{{            <<<<<<   #################\n"
            "////////////////    ((((        ((((  ((((    %%%%        %%%%            &&&&            @@@@@@              ????        ????    {{{{{{            <<<<<<               #####\n"
            "////        ////    ((((          ((((((((    %%%%      %%%%              &&&&            @@@@@@              ????????????????    {{{{{{{{{{{{{{    <<<<<<   #################\n"
            "////        ////    ((((            ((((((    %%%%%%%%%%%%                &&&&            @@@@@@              ????????????????    {{{{{{{{{{{{{{    <<<<<<   #################" << endl << endl<< endl;


    cout << "                                       Luego de muchos años de espera Andy finalmente encontró el lugar perfecto para asentarse y\n"
            "                                       comenzar a armar su pequeño paraíso. Como primera medida decidió nombrar su nuevo hogar como\n"
            "                                       Andypolis la maravillosa ciudad de los programadores.\n" << endl <<
            "                                       Poco a poco con el pasar de los días el rumor del surgimiento de una ciudad exclusiva para\n"
            "                                       programadores se fue difundiendo y la gente comenzó a llegar a ella.\n" << endl <<
            "                                       Tanta fue la popularidad de Andypolis que se debieron comenzar a juntar materiales y construir\n"
            "                                       edificios nuevos para que todos en la ciudad puedan tener un lugar donde estar. " << endl << endl;
    cout << "                                                                   Presione [ENTER] para continuar"<< endl;
    cin.get();

}


void mostrar_menu(){
    cout << endl << endl << endl
    << "---------------------------------------------------------------" << endl
    << "-----------------------------MENU------------------------------" << endl
    << "---------------------------------------------------------------" << endl
    << "||      1) Listar materiales de construccion                 ||" << endl
    << "||      2) Construir edificio por nombre                     ||" << endl
    << "||      3) Listar los edificios construidos                  ||" << endl
    << "||      4) Listar todos los edificios                        ||" << endl
    << "||      5) Demoler un edificio por nombre                    ||" << endl
    << "||      6) Guardar y salir                                   ||"<< endl
    << "---------------------------------------------------------------" << endl;
}

int pedir_opcion(){
    int opcion_elegida = ERROR;
    cout << "Ingrese el numero de la accion que desea realizar (solo el numero): ";
    cin >> opcion_elegida;

    return opcion_elegida;
}

string pedir_nombre(){
    string nombre_dado;
    cout << "Ingrese el nombre del edificio: ";
    cin >> nombre_dado;
    return nombre_dado;
}

void validar_opcion_elegida(int &opcion_elegida) {
    bool es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= OPCIONES_VALIDAS;
    while (!es_opcion_valida) {
        cout << "Lo ingresado no es una opcion valida (recuerde ingresar un numero del 1 al 6), vuelva a intentar: ";
        cin >> opcion_elegida;
        es_opcion_valida = opcion_elegida > 0 && opcion_elegida <= OPCIONES_VALIDAS;
    }
}

void procesar_opcion(Arsenal* arsenal, Ciudad* ciudad, int opcion){

    string nombre_edificio;
    int desea_construir = ERROR;
    int posicion_del_edificio;


    switch (opcion){
        case LISTAR_MATERIALES :
            mostrar_materiales(arsenal);
            break;
        case CONSTRUIR_EDIFICIO:
            nombre_edificio = pedir_nombre();
            if(!existe_el_nombre(nombre_edificio, ciudad)){
                cout << "No existe edificio con tal nombre " << endl;
            }else{
                posicion_del_edificio = obtener_posicion_del_edificio(nombre_edificio, ciudad);
                if(calcular_costos(ciudad, arsenal, posicion_del_edificio)){
                    cout << endl << "La construccion es posible, desea realizarla? 1) SI 2) NO " << endl;
                    desea_construir = pedir_opcion();
                    validar_opcion_construir(desea_construir);
                    if (desea_construir == 1){
                        construir_edificio(ciudad,arsenal,posicion_del_edificio);
                    }
                    if(desea_construir== 2){
                        cout << endl << "El edificio no se construyo!" << endl;
                    }
                }else {
                    cout << endl << "No se pudo construir el edificio " << nombre_edificio << endl;
                }
            }
            break;
        case LISTAR_EDIFICIOS_CONSTRUIDOS:
            mostrar_edificios_construidos(ciudad);
            break;
        case LISTAR_EDIFICIOS:
            mostrar_edificios(ciudad);
            break;
        case DEMOLER_EDIFICIO:
            nombre_edificio = pedir_nombre();
            if(!existe_el_nombre(nombre_edificio, ciudad)){
                cout << "No existe edificio con tal nombre " << endl;
            }else{
                posicion_del_edificio = obtener_posicion_del_edificio(nombre_edificio, ciudad);
                if(ciudad -> edificios[posicion_del_edificio] -> cantidad_construidos > 0){
                    demoler_edificio(ciudad, arsenal, posicion_del_edificio);
                }else{
                    cout << endl << "No hay edificios de este tipo construidos" << endl;
                }
            }
            break;
    }
}

void cargar_arsenal(Arsenal* arsenal){
    arsenal -> cantidad_de_materiales_distintos = 0;

    fstream archivo_materiales(PATH_MATERIALES, ios::in);

    if(!archivo_materiales.is_open()){
        cout << "No se encontro un archivo con nombre \"" << PATH_MATERIALES << "\", se va a crear el archivo" << endl;
        archivo_materiales.open(PATH_MATERIALES, ios::out);
        archivo_materiales.close();
        archivo_materiales.open(PATH_MATERIALES, ios::in);
    }

    string nombre_material, cantidad;

    Material* material;

    while(archivo_materiales >> nombre_material){
        archivo_materiales >> cantidad;

        material = new Material;
        material -> nombre = nombre_material;
        material -> cantidad = stoi(cantidad);

        agregar_material(arsenal, material);
    }

    archivo_materiales.close();
}

void cargar_ciudad(Ciudad* ciudad){
    ciudad -> cantidad_de_edificios = 0;

    fstream archivo_edificios(PATH_EDIFICIOS, ios::in);

    if (!archivo_edificios.is_open()){
        cout << "No se encontro un archivo con nombre \"" << PATH_EDIFICIOS << "\", se va a crear el archivo" << endl;
        archivo_edificios.open(PATH_EDIFICIOS, ios::out);
        archivo_edificios.close();
        archivo_edificios.open(PATH_EDIFICIOS, ios::in);
    }

    string nombre_edificio, piedra, madera, metal, cantidad_construidos, maxima_cantidad_permitidos;

    Edificio* edificio;

    while(archivo_edificios >> nombre_edificio){
        archivo_edificios >> piedra;
        archivo_edificios >> madera;
        archivo_edificios >> metal;
        archivo_edificios >> cantidad_construidos;
        archivo_edificios >> maxima_cantidad_permitidos;

        edificio = new Edificio;
        edificio -> nombre = nombre_edificio;
        edificio -> piedra = stoi(piedra);
        edificio -> madera = stoi(madera);
        edificio -> metal = stoi(metal);
        edificio -> cantidad_construidos = stoi(cantidad_construidos);
        edificio -> cantidad_maxima_construidos = stoi(maxima_cantidad_permitidos);

        agregar_edificio(ciudad, edificio);
    }

    archivo_edificios.close();
}

void agregar_material(Arsenal* arsenal, Material* material){
    int max_anterior = arsenal -> cantidad_de_materiales_distintos;
    Material** nuevo_vector_materiales = new Material*[max_anterior+1];

    for(int i = 0; i < arsenal->cantidad_de_materiales_distintos; i++){
        nuevo_vector_materiales[i] = arsenal -> materiales[i];
    }

    nuevo_vector_materiales[max_anterior] = material;

    if(arsenal -> cantidad_de_materiales_distintos != 0){
        delete[] arsenal-> materiales;
    }

    arsenal -> materiales = nuevo_vector_materiales;
    arsenal -> cantidad_de_materiales_distintos++;
}

void agregar_edificio(Ciudad* ciudad, Edificio* edificio){
    int max_anterior = ciudad -> cantidad_de_edificios;
    Edificio** nuevo_vector_edificios = new Edificio*[max_anterior+1];

    for(int i = 0; i < ciudad -> cantidad_de_edificios; i++){
        nuevo_vector_edificios[i] = ciudad -> edificios[i];
    }

    nuevo_vector_edificios[max_anterior] = edificio;

    if (ciudad -> cantidad_de_edificios != 0){
        delete[] ciudad -> edificios;
    }

    ciudad -> edificios = nuevo_vector_edificios;
    ciudad -> cantidad_de_edificios++;
}

void cerrar_arsenal(Arsenal* arsenal){
    ofstream archivo_materiales(PATH_MATERIALES);

    int cantidad_de_materiales = arsenal -> cantidad_de_materiales_distintos;

    for (int i = 0; i < cantidad_de_materiales; i++){
        archivo_materiales << arsenal -> materiales[i] -> nombre << " " << arsenal -> materiales[i] -> cantidad << "\n";
        delete arsenal -> materiales[i];
        arsenal -> cantidad_de_materiales_distintos--;
    }

    delete[] arsenal -> materiales;
    arsenal -> materiales = nullptr;
}

void cerrar_ciudad(Ciudad* ciudad){
    ofstream archivo_edificios(PATH_EDIFICIOS);

    int cantidad_de_edificios = ciudad -> cantidad_de_edificios;

    for (int i = 0; i < cantidad_de_edificios; i++){
        archivo_edificios << ciudad -> edificios[i] -> nombre << " " << ciudad -> edificios[i] -> piedra << " "
        << ciudad -> edificios[i] -> madera << " " << ciudad -> edificios[i] -> metal << " "
        << ciudad -> edificios[i] ->  cantidad_construidos << " " << ciudad -> edificios[i] -> cantidad_maxima_construidos << "\n";
        delete ciudad -> edificios[i];
        ciudad -> cantidad_de_edificios--;
    }

    delete[] ciudad -> edificios;
    ciudad -> edificios = nullptr;
}

void mostrar_material(Arsenal* arsenal, int posicion) {
    cout << "              Cantidad de " << arsenal -> materiales[posicion]-> nombre << ": " << arsenal -> materiales[posicion] -> cantidad<< endl;
}

void mostrar_materiales(Arsenal* arsenal){
    cout << endl << endl << endl << "                 LISTA DE MATERIALES" << endl;
    if(arsenal -> cantidad_de_materiales_distintos == 0){
        cout << "           -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
        cout << "           -.-EL ARSENAL DE MATERIALES ESTA VACIO-.-.-" << endl;
        cout << "           -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    }else{
        cout << "           //-.-.-.-.-.-.-.-.-.-.-.-.-//" << endl;
        for(int i = 0; i < arsenal -> cantidad_de_materiales_distintos; i++){
            mostrar_material(arsenal, i);
        }
        cout << "           //-.-.-.-.-.-.-.-.-.-.-.-.-//" << endl;
    }
}

void mostrar_edificio_corto(Ciudad* ciudad, int posicion){
    cout << "                 Hay " << ciudad -> edificios[posicion] -> cantidad_construidos <<" "<< ciudad -> edificios[posicion] -> nombre << " construidos" << endl;
}

void mostrar_edificios_construidos(Ciudad* ciudad){
    cout << endl << endl << endl << "               LISTA DE EDIFICIOS CONSTRUIDOS" << endl;
    if(ciudad -> cantidad_de_edificios == 0){
        cout << "           -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
        cout << "           -.-.-.-.-.-LA CIUDAD ESTA VACIA-.-.-.-.-.-." << endl;
        cout << "           -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    }else{
        int contador_edificios = 0;
        cout << "           //-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-//" << endl;
        for (int i = 0; i < ciudad -> cantidad_de_edificios; i++){
            if(ciudad ->edificios[i] -> cantidad_construidos > 0){
                mostrar_edificio_corto(ciudad, i);
                contador_edificios++;
            }
        }
        cout << "           //-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-//" << endl;

        if (contador_edificios == 0){
            cout << "           //-.-.-NO HAY EDIFICIOS CONSTRUIDOS-.-.-.//" << endl;
            cout << "           //-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-//" << endl;
            cout << "           //-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-//" << endl;
        }
    }
}

void mostrar_edificio(Ciudad* ciudad, int posicion){
    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    cout << "Nombre: " << ciudad -> edificios[posicion] -> nombre << " || ";
    cout << "Costo Piedra: " << ciudad -> edificios[posicion] -> piedra << " || ";
    cout << "Costo Madera: " << ciudad -> edificios[posicion] -> madera << " || ";
    cout << "Costo Metal: " << ciudad -> edificios[posicion] -> metal << " || ";
    cout << "Cantidad construidos: " << ciudad -> edificios[posicion] -> cantidad_construidos << " || ";
    cout << "Maximo permitido: " << ciudad -> edificios[posicion] -> cantidad_maxima_construidos << endl;
}

void mostrar_edificios(Ciudad* ciudad){
    cout << endl << endl << endl << "         LISTA DE EDIFICIOS" << endl;
    if(ciudad -> cantidad_de_edificios == 0){
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
        cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-LA CIUDAD ESTA VACIA.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
    }

    for(int i = 0; i < ciudad -> cantidad_de_edificios; i++){
        mostrar_edificio(ciudad, i);
    }
    cout << "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-" << endl;
}



void construir_edificio(Ciudad* ciudad, Arsenal* arsenal, int posicion_del_edificio){
    int posicion_piedra = obtener_posicion_del_material("piedra", arsenal);
    int posicion_madera = obtener_posicion_del_material("madera", arsenal);
    int posicion_metal = obtener_posicion_del_material("metal", arsenal);

    ciudad -> edificios[posicion_del_edificio] -> cantidad_construidos++;

    arsenal ->materiales[posicion_piedra] -> cantidad -= ciudad -> edificios[posicion_del_edificio] -> piedra;
    arsenal ->materiales[posicion_madera] -> cantidad -= ciudad -> edificios[posicion_del_edificio] -> madera;
    arsenal ->materiales[posicion_metal] -> cantidad -= ciudad -> edificios[posicion_del_edificio] -> metal;

    cout << endl << "El edificio " << ciudad -> edificios[posicion_del_edificio] -> nombre << " ha sido construido!" << endl;
}

void demoler_edificio(Ciudad* ciudad, Arsenal* arsenal, int posicion_del_edificio){
    int posicion_piedra = obtener_posicion_del_material("piedra", arsenal);
    int posicion_madera = obtener_posicion_del_material("madera", arsenal);
    int posicion_metal = obtener_posicion_del_material("metal", arsenal);

    ciudad -> edificios[posicion_del_edificio] -> cantidad_construidos--;

    arsenal ->materiales[posicion_piedra] -> cantidad += (ciudad -> edificios[posicion_del_edificio] -> piedra / 2);
    arsenal ->materiales[posicion_madera] -> cantidad += (ciudad -> edificios[posicion_del_edificio] -> madera / 2);
    arsenal ->materiales[posicion_metal] -> cantidad += (ciudad -> edificios[posicion_del_edificio] -> metal / 2);

    cout << endl << "Edificio demolido correctamente !!" << endl;
}

bool calcular_costos(Ciudad* ciudad, Arsenal* arsenal, int posicion_del_edificio){
    bool madera_suficiente = false;
    bool metal_suficiente = false;
    bool piedra_suficiente = false;
    bool maximo_permitido = false;

    int posicion_piedra = obtener_posicion_del_material("piedra", arsenal);
    int posicion_madera = obtener_posicion_del_material("madera", arsenal);
    int posicion_metal = obtener_posicion_del_material("metal", arsenal);

    if(ciudad -> edificios[posicion_del_edificio] -> piedra <= arsenal -> materiales[posicion_piedra] -> cantidad){
        cout << endl << "Cantidad de Piedra: " << COLOR_VERDE << "✔" << COLOR_POR_DEFECTO << endl;
        piedra_suficiente = true;
    }else{
        cout << endl << "Cantidad de Piedra: " << COLOR_ROJO << "❌ (falta :" << (ciudad -> edificios[posicion_del_edificio] -> piedra - arsenal -> materiales[posicion_piedra] -> cantidad) << ")" << COLOR_POR_DEFECTO << endl;
    }

    if(ciudad -> edificios[posicion_del_edificio] -> madera <= arsenal -> materiales[posicion_madera] -> cantidad){
        cout << "Cantidad de Madera:" << COLOR_VERDE << " ✔" << COLOR_POR_DEFECTO << endl;
        madera_suficiente = true;
    }else{
        cout << "Cantidad de Madera: " << COLOR_ROJO << "❌ (falta :" << (ciudad -> edificios[posicion_del_edificio] -> madera - arsenal -> materiales[posicion_madera] -> cantidad) << ")" << COLOR_POR_DEFECTO << endl;
    }

    if(ciudad -> edificios[posicion_del_edificio] -> metal <= arsenal -> materiales[posicion_metal] -> cantidad){
        cout << "Cantidad de Metal:" << COLOR_VERDE << " ✔" << COLOR_POR_DEFECTO << endl;
        metal_suficiente = true;
    }else{
        cout << "Cantidad de Metal:" << COLOR_ROJO << " ❌ (falta :" << (ciudad -> edificios[posicion_del_edificio] -> metal - arsenal -> materiales[posicion_metal] -> cantidad) << ")" << COLOR_POR_DEFECTO << endl;
    }

    if(ciudad ->edificios[posicion_del_edificio] ->cantidad_construidos < ciudad -> edificios[posicion_del_edificio] ->cantidad_maxima_construidos){
        cout << "Cantidad de edificios Permitida:<" << COLOR_VERDE << " ✔️" << COLOR_POR_DEFECTO << endl;
        maximo_permitido = true;
    }else{
        cout << "Cantidad de edificios Permitida:" << COLOR_ROJO <<" ❌" << COLOR_POR_DEFECTO << endl;
    }

    return metal_suficiente && madera_suficiente && piedra_suficiente && maximo_permitido;
}

void validar_opcion_construir(int &opcion_elegida_construir){
    bool es_opcion_valida = opcion_elegida_construir > 0 && opcion_elegida_construir <= OPCIONES_VALIDAS_CONSTRUIR;
    while (!es_opcion_valida) {
        cout << "Lo ingresado no es una opcion valida (recuerde ingresar un numero del 1 al 2), vuelva a intentar: ";
        cin >> opcion_elegida_construir;
        es_opcion_valida = opcion_elegida_construir > 0 && opcion_elegida_construir <= OPCIONES_VALIDAS;
    }

}

bool existe_el_nombre(string nombre, Ciudad* ciudad){
    bool existe_el_nombre = false;
    int i = 0;

    while(!existe_el_nombre && i < ciudad -> cantidad_de_edificios){
        if(nombre == ciudad -> edificios[i] -> nombre){
            existe_el_nombre = true;
        }
        i++;
    }

    return existe_el_nombre;
}

int obtener_posicion_del_material(string nombre, Arsenal* arsenal){
    int posicion = ERROR;
    int i = 0;
    bool material_encontrado = false;

    while(i < arsenal -> cantidad_de_materiales_distintos && !material_encontrado){
        if(arsenal -> materiales[i] -> nombre == nombre){
            material_encontrado = true;
            posicion = i;
        }
        i++;
    }
    return posicion;
}

int obtener_posicion_del_edificio(string nombre, Ciudad* ciudad){
    int posicion = ERROR;
    int i = 0;
    bool edificio_encontrado = false;

    while(i < ciudad -> cantidad_de_edificios && !edificio_encontrado){
        if(ciudad -> edificios[i] -> nombre == nombre){
            edificio_encontrado = true;
            posicion = i;
        }
        i++;
    }
    return posicion;
}




