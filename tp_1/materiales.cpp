#include "materiales.h"
#include "menu.h"
#include "colors.h"
#include "mensajes_pantalla.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

void procesar_archivo_materiales(Material materiales[MAX_MATERIALES], int &tope){

    Material material;
    string cantidad;

    tope = 0;

    ifstream archivo(PATH_ARCHIVO_MATERIALES);

    if (!archivo.is_open()){
        imprimir_mensaje_error();
        cout << "No se ha pudido abrir el arcivo: " << PATH_ARCHIVO_MATERIALES <<  endl;
        tope = ERROR;
    };
    while(archivo >> material.nombre_material){
        archivo >> cantidad;
        material.cantidad_material = stoi(cantidad);
        materiales[tope] = material;
        tope++;
    }

    archivo.close();
}

void listar_materiales(Material materiales[MAX_MATERIALES], int tope){
    system("clear");
    
    cout << TXT_BOLD;
    cout << "\t\t╔══════════════╦════════════╗" << endl;
    cout << "\t\t║  Materiales  ║  Cantidad  ║" << endl;
    cout << "\t\t╠══════════════╬════════════╣" << endl;
    cout << END_COLOR;
                  
    for (int i = 0; i < tope; i++){
        
        cout << "\t\t║" << setfill(' ') << setw(10) << materiales[i].nombre_material << setfill(' ') << setw(7);
        cout << "│" << setfill(' ') << setw(8) << materiales[i].cantidad_material << setfill(' ') << setw(7) << "║" << endl;
        if(i < tope - 1)
            cout << "\t\t╠──────────────┼────────────╣" << endl;
        else
            cout << "\t\t╚══════════════╩════════════╝" << endl;

    }
    cout << endl;
    imprimir_mensaje_esperar(5);
}

void guardar_cambios_materiales(Material materiales[MAX_MATERIALES], int tope){
    ofstream archivo_salida(PATH_ARCHIVO_MATERIALES);

    if (!archivo_salida.is_open()){
        imprimir_mensaje_error();
        cout << "No se ha pudido abrir el arcivo: " << PATH_ARCHIVO_MATERIALES <<  endl;
        tope = ERROR;
    };

    for(int i = 0; i < tope; i++){
        archivo_salida << materiales[i].nombre_material << " " << materiales[i].cantidad_material << endl;
    }

    archivo_salida.close();
}