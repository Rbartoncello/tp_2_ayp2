#include "edificios.h"
#include "menu.h"
#include "colors.h"
#include "materiales.h"
#include "emojis.h"
#include "mensajes_pantalla.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

void procesar_archivo_edificios(Edificio edificios[MAX_EDIFICIOS], int &tope){

    Edificio edificio_aux;
    string piedra;
    string madera;
    string metal;
    string cantidad_construidos;
    string maxima_cantidad_permitidos;

    tope = 0;

    ifstream archivo(PATH_ARCHIVO_EDIFICIO);

    if (!archivo.is_open()){
        imprimir_mensaje_error();
        cout << "No se puedo abrir el arcivo: " << PATH_ARCHIVO_EDIFICIO <<  endl;
        tope = ERROR;
    };
    while(archivo >> edificio_aux.nombre_edificio){
        archivo >> piedra;
        archivo >> madera;
        archivo >> metal;
        archivo >> cantidad_construidos;
        archivo >> maxima_cantidad_permitidos;

        edificio_aux.piedra = stoi(piedra);
        edificio_aux.madera = stoi(madera);
        edificio_aux.metal = stoi(metal);
        edificio_aux.cantidad_construidos = stoi(cantidad_construidos);
        edificio_aux.maxima_cantidad_permitidos = stoi(maxima_cantidad_permitidos);

        edificios[tope] = edificio_aux;
        tope++;
    }

    archivo.close();
}

void listar_edificios_construidos(Edificio edificios[MAX_EDIFICIOS], int tope){
    system("clear");

    cout << TXT_BOLD;
    cout << "\t\t╔═══════════════════════╦════════════╗" << endl;
    cout << "\t\t║ Edificios construidos ║  Cantidad  ║" << endl;
    cout << "\t\t╠═══════════════════════╬════════════╣" << endl;
    cout << END_COLOR;

    bool hay_edificio_construido = false;

    for (int i = 0; i < tope; i++){
        if (edificios[i].cantidad_construidos > 0){
            hay_edificio_construido = true;
            cout << "\t\t│" << setfill(' ') << setw(15) << edificios[i].nombre_edificio << setfill(' ') << setw(11);
            cout << "│" << setfill(' ') << setw(7) << edificios[i].cantidad_construidos << setfill(' ') << setw(8) << "│" << endl;
            if(i < tope - 1)
                cout << "\t\t╠───────────────────────┼────────────╣" << endl;
            else
                cout << "\t\t╚═══════════════════════╩════════════╝" << endl;
        }
    }
    if (!hay_edificio_construido){
        cout << TXT_BOLD;
        cout << "\t\t║ " << TXT_RED_196 << "NO HAY NINGUN EDIFICIO CONSTRUIDO " << END_COLOR << " ║" << endl;
        cout << "\t\t╚════════════════════════════════════╝" << endl;
    }
    
    cout << endl;
    sleep(2);
}

void listar_todos_edificios(Edificio edificios[MAX_EDIFICIOS], int tope){
    system("clear");

    cout << TXT_BOLD;
    cout << "\t╔════════════════════╦══════════════════════╦═════════════════════════════════════════╦══════════════════════════╗" << endl;
    cout << "\t║                    ║                      ║ Materiales necesarios para construirlos ║                          ║" << endl;
    cout << "\t║ Nombre de edificio ║ Cantidad construidos ╠═════════════╦═════════════╦═════════════╣ Max. cantidad permitidos ║" << endl;
    cout << "\t║\t\t     ║\t\t\t    ║   Piedra    ║   Madera    ║    Metal    ║\t\t\t\t ║" << endl;
    cout << "\t╠════════════════════╬══════════════════════╬═════════════╬═════════════╬═════════════╬══════════════════════════╣" << endl;
    cout << END_COLOR;

    for (int i = 0; i < tope; i++){
        cout << "\t║" << setfill(' ') << setw(14) << edificios[i].nombre_edificio << setfill(' ') << setw(9);
        cout << "│" << setfill(' ') << setw(12) << edificios[i].cantidad_construidos << setfill(' ') << setw(13);
        cout << "│" << setfill(' ') << setw(8) << edificios[i].piedra << setfill(' ') << setw(8);
        cout << "│" << setfill(' ') << setw(8) << edificios[i].madera << setfill(' ') << setw(8);
        cout << "│" << setfill(' ') << setw(8) << edificios[i].metal << setfill(' ') << setw(8);
        cout << "│" << setfill(' ') << setw(14) << edificios[i].maxima_cantidad_permitidos << setfill(' ') << setw(15) << "║" << endl;
        if(i < tope - 1)
            cout << "\t╠────────────────────┼──────────────────────┼─────────────┼─────────────┼─────────────┼──────────────────────────╣" << endl;
        else
            cout << "\t╚════════════════════╩══════════════════════╩═════════════╩═════════════╩═════════════╩══════════════════════════╝" << endl;
    }
    imprimir_mensaje_esperar(10);
}

/*
 * PRE: -
 * POST: Devolvera el string que ingrese por pantalla.
*/
string pedir_edificio(string accion){
    string edificio;
    cout << "Ingrese el nombre del edificio que desea " << accion <<": ";
    cin >> edificio;
    return edificio;
}

/*
 * PRE: Tope debe ser un numero positivo y valido, edificios[MAX_EDIFICIOS] debe estar cargado y respetar el tope.
 * POST: Devolvera un entero con la posicion donde se encontraba el edificio a buscar o en caso contrario devolvera ERROR.
*/
int buscar_edificio(Edificio edificios[MAX_EDIFICIOS], int tope, string edificio_a_buscar){
    bool encontrado = false;
    int posicion = ERROR;
    int i = 0;

    while( ( i < tope ) && !(encontrado) ){
        if(edificios[i].nombre_edificio == edificio_a_buscar){
            posicion = i;
            encontrado = true;
        }
        else
            i++;
    }

    return posicion;
}

/*
 * PRE: -
 * POST: Devolvera TRUE si el ingreso es igual a AFIRMATIVO o a NEGATIVO y FALSE en caso contrario.
*/
bool es_ingreso_valido(string ingreso){
    return (( ingreso == AFIRMATIVO ) || ( ingreso == NEGATIVO ) );
}

/*
 * PRE: -
 * POST: Devolvera TRUE si cantidad de edificios construidos es menor a la maxima permitida.y FALSE en caso contrario.
*/
bool esta_permitido_construir(Edificio edificio){
    return(edificio.cantidad_construidos < edificio.maxima_cantidad_permitidos);
}

/*
 * PRE: Tope debe ser un numero positivo y valido, materiales[MAX_MATERIALES] debe estar cargado y respetar el tope.
 * POST: Devolvera un entero con la posicion donde se encontraba el material a buscar o en caso contrario devolvera ERROR.
*/
int buscar_material(Material materiales[MAX_MATERIALES], int tope, string material_a_buscar){
    int posicion = ERROR;
    bool encontrado = false;
    int i = 0;

    while ((i < tope) && !(encontrado)){
        if(materiales[i].nombre_material == material_a_buscar){
            posicion = i;
            encontrado = true;
        }
        else
            i++;
    }

    return posicion;
}

/*
 * PRE: Topes debe ser un numero positivo y valido, materiales[MAX_MATERIALES] debe estar cargado y respetar el tope.
 * POST: Devolvera TRUE si cantidad de material es suficiente para el edificio y FALSE en caso contrario.
*/
bool hay_materia_suficiente(Edificio edificio, Material materiales[MAX_MATERIALES], int tope_materiales){

    int posicion_piedra = buscar_material(materiales, tope_materiales, PIEDRA);
    int posicion_madera = buscar_material(materiales, tope_materiales, MADERA);
    int posicion_metal = buscar_material(materiales, tope_materiales, METAL);

    bool hay_materia_suficiente = false;

    if ((posicion_piedra != ERROR) && (posicion_madera != ERROR) && (posicion_metal != ERROR)){
        if ((edificio.piedra <= materiales[posicion_piedra].cantidad_material) && (edificio.madera <= materiales[posicion_madera].cantidad_material) && (edificio.metal <= materiales[posicion_metal].cantidad_material))
            hay_materia_suficiente = true;
    }
    

    return hay_materia_suficiente;
}

/*
 * PRE: -
 * POST: Devolvera un string, que representa un emoji, dependiendo si la cant_material_actual es suficiente para cant_material_necesario.
*/
string chequear_status(int cant_material_actual, int cant_material_necesario){
    string status;

    if (cant_material_actual > cant_material_necesario)
        status = EMOJI_HECHO;
    else
        status = EMOJI_MAL;

    return status;
}

/*
 * PRE: Tope debe ser un numero positivo y valido, materiales[MAX_MATERIALES] debe estar cargado y respetar el tope.
 * POST: Me imprimira por pantalla los materiales necesarios para el edificio, comparando con los disponibles.
*/
void imprimir_materiales_necesarios(Edificio edificio, Material materiales[MAX_MATERIALES], int tope_materiales){

    cout << TXT_BOLD;
    cout << "\t╔═════════╦═══════════════════════╦═══════════════════════╦════════╗" << endl;
    cout << "\t║/////////║ Materiales necesarios ║ Materiales en almacen ║ Estado ║" << endl;
    cout << "\t╠═════════╬═══════════════════════╬═══════════════════════╬════════╣" << endl;
    cout << END_COLOR;

    int posicion_piedra = buscar_material(materiales, tope_materiales, PIEDRA);

    int candidad = ERROR;

    if (posicion_piedra != ERROR)
        candidad = materiales[posicion_piedra].cantidad_material;
    string status = chequear_status(candidad, edificio.piedra);
    
    cout << "\t│ " << PIEDRA << "  │\t" << edificio.piedra << "\t\t  │\t" << candidad << "\t\t  │   " << status << "   │" << endl;
    cout << "\t├─────────┼───────────────────────┼───────────────────────┼────────┤" << endl;

    int posicion_madera = buscar_material(materiales, tope_materiales, MADERA);

    if (posicion_madera != ERROR)
        candidad = materiales[posicion_madera].cantidad_material;
    status = chequear_status(candidad, edificio.madera);
    cout << "\t│ " << MADERA << "  │ \t" << edificio.madera << "\t\t  │\t" << candidad << "\t\t  │   " << status << "   │" << endl;
    cout << "\t├─────────┼───────────────────────┼───────────────────────┼────────┤" << endl;

    int posicion_metal = buscar_material(materiales, tope_materiales, METAL);

    if (posicion_metal != ERROR)
        candidad = materiales[posicion_metal].cantidad_material;
    status = chequear_status(candidad, edificio.metal);

    cout << "\t│ " << METAL << "   │ \t" << edificio.metal << "\t\t  │\t" << candidad << "\t\t  │   " << status << "   │" << endl;
    cout << "\t└─────────┴───────────────────────┴───────────────────────┴────────┘" << endl << endl;
}

/*
 * PRE: Topes debe ser un numero positivo y valido, materiales[MAX_MATERIALES] debe estar cargado y respetar el tope.
 * POST: Me agregara un nuevo edificio y quitara los materiales que necesito de materiales[MAX_MATERIALES].
*/
void agregar_edificio(Edificio &edificio, Material materiales[MAX_MATERIALES], int tope_materiales){

    edificio.cantidad_construidos++;

    int posicion_piedra = buscar_material(materiales, tope_materiales, PIEDRA);
    int posicion_madera = buscar_material(materiales, tope_materiales, MADERA);
    int posicion_metal = buscar_material(materiales, tope_materiales, METAL);

    materiales[posicion_piedra].cantidad_material -= edificio.piedra;
    materiales[posicion_madera].cantidad_material -= edificio.madera;
    materiales[posicion_metal].cantidad_material -= edificio.metal;
}

void agregar_edificio_nuevo(){
    cout << "Disculpe las molestias pero esta opcion " << TXT_BOLD << TXT_LIGHT_RED_9 << NEGATIVO << END_COLOR << " esta disponible en la version " << VERSION_PGM << endl;
    imprimir_mensaje_esperar(5);
}

void construir_edificio(Edificio edificios[MAX_EDIFICIOS], int &tope_edificio, Material materiales[MAX_MATERIALES], int tope_materiales){
    system("clear");

    string edificio_construir = pedir_edificio(CONSTRUIR);
    int indice = buscar_edificio(edificios, tope_edificio, edificio_construir);

    if (indice == ERROR){
        cout << "No se ha encontrado el edificio: " << edificio_construir << endl;
        cout << "De todas formas usted desea construirlo ? ingrese ";
        imprimir_mensaje_opcion_afirmativa_negativa();
        
        string respuesta;
        cin >> respuesta;
        
        while (!es_ingreso_valido(respuesta)){
            system("clear");

            imprimir_mensaje_error();
            cout << "Ha ingresado una opcion no valida, por favor ingrese ";
            imprimir_mensaje_opcion_afirmativa_negativa();

            cin >> respuesta;
        }

        system("clear");

        if(respuesta == AFIRMATIVO){
            agregar_edificio_nuevo();
        }
    } else {
        if (esta_permitido_construir(edificios[indice])){
            if(hay_materia_suficiente(edificios[indice], materiales, tope_materiales)){
                agregar_edificio(edificios[indice], materiales, tope_materiales);
                system("clear");
                cout << "\tConstruyendo " << edificios[indice].nombre_edificio << "... " << EMOJI_EDIFICIO_CONSTRUCION << endl;

                sleep(2);
                system("clear");
                cout << TXT_BOLD;
                cout << "\tSe ha agregado con exito " << EMOJI_HECHO << endl << endl;
                cout << END_COLOR;

                sleep(2);
                system("clear");

            } else {
               cout << "No se ha podido construir un nuevo " << edificios[indice].nombre_edificio << " porque no contas con la cantidad necesaria de materiales " << endl << endl;
               
               imprimir_materiales_necesarios(edificios[indice], materiales, tope_materiales);
               imprimir_mensaje_esperar(8);
            }
        } else {
            cout << "No se ha podido construir un nuevo " << edificios[indice].nombre_edificio << " porque ya se ha construido la cantidad maxima posible: " << edificios[indice].maxima_cantidad_permitidos << endl;
            
            imprimir_mensaje_esperar(5);
        }
    }
}

/*
 * PRE: -
 * POST: Devolvera TRUE si hay por lo menos un edificio y FALSE en caso contrario.
*/
bool es_posible_demoler(Edificio edificio){
    return (edificio.cantidad_construidos > 0);
}

/*
 * PRE: tope_materiales debe ser un numero positivo y valido, materiales[MAX_MATERIALES] debe estar cargado y respetar el tope.
 * POST: Devolvera el edificio con una cantidad_construidos menos y se agregara la mitad de los materiales que tenia el edificio a materiales[MAX_MATERIALES].
*/
void demoler_edificio_ingresado(Edificio &edificio, Material materiales[MAX_MATERIALES], int tope_materiales){
    edificio.cantidad_construidos--;

    int posicion_piedra = buscar_material(materiales, tope_materiales, PIEDRA);
    int posicion_madera = buscar_material(materiales, tope_materiales, MADERA);
    int posicion_metal = buscar_material(materiales, tope_materiales, METAL);
    
    materiales[posicion_piedra].cantidad_material += (edificio.piedra / 2);
    materiales[posicion_madera].cantidad_material += (edificio.madera / 2);
    materiales[posicion_metal].cantidad_material += (edificio.metal / 2);
}

/*
 * PRE: Tope debe ser un numero positivo y valido, edificios[MAX_EDIFICIOS] debe estar cargado y respetar el tope.
 * POST: Devolvera TRUE si hay por lo menos un edificio con cantidad_construidos > 0 y FALSE en caso contrario.
*/
bool hay_edificios(Edificio edificios[MAX_EDIFICIOS], int tope){
    bool hay_edificios = false;
    int i = 0;

    while ((i < tope) && !(hay_edificios)){
        if (edificios[i].cantidad_construidos > 0){
            hay_edificios = true;
        } else {
            i++;
        }
    }

    return hay_edificios;
}

void demoler_edificio(Edificio edificios[MAX_EDIFICIOS], int tope_edificios, Material materiales[MAX_MATERIALES], int tope_materiales){
    system("clear");
    
    if(!hay_edificios(edificios, tope_edificios)){
        cout << "Lo siento pero " << TXT_BOLD << TXT_LIGHT_RED_9 <<  NEGATIVO << END_COLOR << " hay ningun edificio disponible para demoler" << endl;
        
        imprimir_mensaje_esperar(5);
    } else {
        string edificio_demoler = pedir_edificio(DEMOLER);
        int indice = buscar_edificio(edificios, tope_edificios, edificio_demoler);

        while(indice == ERROR){
            imprimir_mensaje_error();

            cout << "El edificio que usted ingreso no es valido." << endl;
            cout << "Si desea ver lo edificios disponibles para demoler, por favor ingrese ";
            imprimir_mensaje_opcion_afirmativa_negativa();

            string respuesta;
            cin >> respuesta;

            while (!es_ingreso_valido(respuesta)){
                system("clear");

                imprimir_mensaje_error();
                cout << "Ha ingresado una opcion no valida" << endl;
                cout << "Si usted desea puede ver lo edificios que hay disponibles para demoler, por favor ingrese ";
                imprimir_mensaje_opcion_afirmativa_negativa();

                cin >> respuesta;
            }

            if (respuesta == AFIRMATIVO)
                listar_edificios_construidos(edificios, tope_edificios);

            edificio_demoler = pedir_edificio(DEMOLER);
            system("clear");
            indice = buscar_edificio(edificios, tope_edificios, edificio_demoler);
        }

        system("clear");

        if (!(es_posible_demoler(edificios[indice]))){
            imprimir_mensaje_error();
            cout << "El edificio que usted ingreso "<< TXT_BOLD << TXT_LIGHT_RED_9 <<  NEGATIVO << END_COLOR <<" es posible demoler ya que no hay ninguno construido" << endl;
            imprimir_mensaje_esperar(5);
        } else {
            demoler_edificio_ingresado(edificios[indice], materiales, tope_materiales);

            system("clear");
            cout << "\tDemoliendo " << edificios[indice].nombre_edificio << "... " << EMOJI_PARED << EMOJI_MARTILLO << endl;
            sleep(2);

            system("clear");
            cout << TXT_BOLD;
            cout << "\tSe ha demolido con exito " << EMOJI_HECHO << endl << endl;
            cout << END_COLOR;

            sleep(2);
            system("clear");
        }
    }
}

void guardar_cambios_edificios(Edificio edificios[MAX_EDIFICIOS], int tope){
    ofstream archivo_salida(PATH_ARCHIVO_EDIFICIO);

    if (!archivo_salida.is_open()){
        imprimir_mensaje_error();
        cout << "No se ha pudido abrir el arcivo: " << PATH_ARCHIVO_MATERIALES <<  endl;
        tope = ERROR;
    };

    for(int i = 0; i < tope; i++){
        archivo_salida << edificios[i].nombre_edificio << " " << edificios[i].piedra << " " << edificios[i].madera << " " << edificios[i].metal << " " << edificios[i].cantidad_construidos << " " << edificios[i].maxima_cantidad_permitidos << endl;
    }

    archivo_salida.close();
}