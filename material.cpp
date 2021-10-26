//
// Created by juan on 25/10/21.
//
#include "colors.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
#include "material.h"


Material::Material(string nombre, int cantidad){
    this->nombre_material = nombre;
    this->cantidad_material = cantidad;
}

void Material::mostrar(){
    cout << devolver_nombre_material() << " " << devolver_cantidad_material() <<  endl;
}

string Material::devolver_nombre_material(){
    return this->nombre_material;
}

int Material::devolver_cantidad_material(){
    return this->cantidad_material;
}