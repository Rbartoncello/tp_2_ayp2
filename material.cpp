#include "material.h"


Material::Material(std::string nombre, int cantidad){
    this->nombre = nombre;
    this->cantidad = cantidad;
}

void Material:: mostrar(){
	std::cout << std::endl << "Nombre: " <<  nombre << "; Cantidad: " << cantidad <<std::endl;

}

