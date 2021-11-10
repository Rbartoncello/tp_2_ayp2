#ifndef EDIFICIOS_H
#define EDIFICIOS_H
#include <string>
#include "edificio.h"
#include "mapa.h"

using namespace std;

class Edificios{
    private:
        Edificio** edificios;
        int total_edificios;
    public:
        /*
         * Constructor:
         * Pre: -.
         * Post: Me va a crear el objeto edificios con total_edificios = 0.
         */
        Edificios();

        /*
         * Destructor:
         * Pre: -.
         * Post: Me va a descruir el objeto edificios.
         */
        ~Edificios();

        /*
         * Pre: -
         * Post: Guarda cada linea en un objeto Edificio
         */
        int procesar_archivo();

        /*
         * Pre: -
         * Post: Me muestra lista por pantalla toso los objetos del tipo Edificio.
         */
        void mostar(Mapa* mapa);

        /*
         * Pre: Tiene que haber un edificio con nombre_edificio.
         * Post: Busca un edificio con nombre_edificio y lo devuelve.
        */
        Edificio* buscar_edificio(string nombre_edificio);

        /*
         * Pre: -
         * Post: Devuelve TRUE si existe un edificio con ese nombre y FALSE en caso contrario.
        */
        bool existe_edificio(string nombre_edificio);
        
    private:

        /*
         * Pre: Recibe un objeto Edificio.
         * Post: Ingresa el objeto en un vector dinámico.
         */
        void agregar_edificio(Edificio* edificio);

        /*
         * Pre: Recibe un nombre_edificio existente
         * Post: devuelve el emoji de ese edificio
        */
        string buscar_tipo_emoji(string nombre_edificio);

        /*
         * Pre: 
         * Post: Devuelve TRUE el nombre_edificio es mina, aserradero o fabrica y FALSE en caso contrario.
         */
        bool brinda_material(string nombre_edificio);

        
};

#endif