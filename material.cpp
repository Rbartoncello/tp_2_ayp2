#include "colors.h"
#include "emojis.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
#include "material.h"
#include "materiales.h"


Material::Material(string nombre, int cantidad){
    this->nombre_material = nombre;
    this->emoji = agregar_emoji(nombre_material);
    this->cantidad_material = cantidad;
}

Material::Material(){
    this->nombre_material = "NULL";
    this->emoji = "NULL";
    this->cantidad_material = 0;
}

string Material::agregar_emoji(string nombre_material){
    string emoji;

    if (nombre_material == PIEDRA){
        emoji = EMOJI_PIEDRA;
    } else if (nombre_material == MADERA){
        emoji = EMOJI_MADERA;
    } else if (nombre_material == METAL){
        emoji = EMOJI_METAL;
    } 

    return emoji;
}

void Material::mostrar(){
    cout << devolver_nombre_material() << " " << devolver_cantidad_material() <<  endl;
}

string Material::devolver_nombre_material(){
    return this->nombre_material;
}

string Material::devolver_emoji(){
    return this->emoji;
}

int Material::devolver_cantidad_material(){
    return this->cantidad_material;
}

void Material::sumar_restar(int cantidad){
    this->cantidad_material = (this->cantidad_material + cantidad);
}

void Material::imprimir_resumen(){
    cout <<"\tSoy un material de nombre " << nombre_material << " y me encuentro en el casillero consultado."<< endl;
}

void Material::modificar_emoji(string emoji){
    this->emoji = emoji;
}