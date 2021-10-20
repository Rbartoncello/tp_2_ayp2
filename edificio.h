#ifndef EDIFICIO_H
#define EDIFICIO_H
#include <string>

using namespace std;

class Edificio{
    private:
        string nombre;
        int piedra;
        int madera;
        int metal;
        int max_cant_permitidos;
    public:
        Edificio(string nombre, int piedra, int madera, int metal, int max_cant_permitidos);
        /* ~Edificio(); */

        void mostar();

        string devolver_nombre();

        int cant_piedra_necesaria();

        int cant_madera_necesaria();

        int cant_metal_necesaria();

        int maximo_permitidos();
};

class Edificios{
    private:
        Edificio** edificios;
        int total_edificios;
    public:
        Edificios();
        /* ~Edificios(); */

        void procesar_archivo();

        void mostar();

    private:
    
        void agregar_edificio(Edificio* edificio);

        
};

#endif