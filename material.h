#ifndef TP2_MATERIAL_H
#define TP2_MATERIAL_H

#include "iostream"
#include <string>


class Material{
protected:
    std::string nombre;
    int cantidad;

public:

    Material(std::string nombre, int cantidad);

    //PRE: -
    //POST:Muestra informacion del material
    void mostrar();

};

#endif //TP2_MATERIAL_H