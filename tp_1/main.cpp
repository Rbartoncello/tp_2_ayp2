#include <iostream>
#include <fstream>
#include "menu.h"
#include "colors.h"
#include "materiales.h"
#include "edificios.h"

using namespace std;

void mensaje_bienvenida(){
    system("clear");
    cout << TXT_BOLD << TXT_DARK_YELLOW_3 << "\
\t\t     ___      .__   __.  _______  ____    ____ .______     ______    __       __       _______.             \n\
\t\t    /   \\     |  \\ |  | |       \\ \\   \\  /   / |   _  \\   /  __  \\  |  |     |  |     /       | _    \n\
\t\t   /  ^  \\    |   \\|  | |  .--.  | \\   \\/   /  |  |_)  | |  |  |  | |  |     |  |    |   (----`(_)      \n\
\t\t  /  /_\\  \\   |  . `  | |  |  |  |  \\_    _/   |   ___/  |  |  |  | |  |     |  |     \\   \\            \n\
\t\t /  _____  \\  |  |\\   | |  '--'  |    |  |     |  |      |  `--'  | |  `----.|  | .----)   |    _         \n\
\t\t/__/     \\__\\ |__| \\__| |_______/     |__|     |__|       \\______/  |_______||__| |_______/    (_)      \n\
                                                                                                              \n"
    << END_COLOR << endl;
    cout << TXT_BOLD << TXT_ORANGE_130 << "\
\t  ,,                                   ,,                      ,,                                                 \n\
\t`7MM                                   db                      db                         mm                      \n\
\t  MM                                                                                      MM                      \n\
\t  MM   ,pWWq.   ,pPYbd       ,p6bo   `7MM  `7MMpMMMb.pMMMb.  `7MM   .gPYa   `7MMpMMMb.  mmMMmm   ,pWWq.   ,pPYbd \n\
\t  MM  6W'   `Wb 8I   `      6M'  OO    MM    MM    MM    MM    MM  ,M'   Yb   MM    MM    MM    6W'   `Wb 8I   ` \n\
\t  MM  8M     M8 `YMMMa.     8M         MM    MM    MM    MM    MM  8M''''''   MM    MM    MM    8M     M8 `YMMMa. \n\
\t  MM  YA.   ,A9 L.   I8     YM.    ,   MM    MM    MM    MM    MM  YM.    ,   MM    MM    MM    YA.   ,A9 L.   I8 \n\
\t.JMML. `Ybmd9'  M9mmmP'      YMbmd'  .JMML..JMML  JMML  JMML..JMML. `Mbmmd' .JMML  JMML.  `Mbmo  `Ybmd9'  M9mmmP' \n" 
    << END_COLOR << endl;
}

int main() {
    Material materiales[MAX_MATERIALES];
    int tope_materiales;

    Edificio edificios[MAX_EDIFICIOS];
    int tope_edificios;

    procesar_archivo_materiales(materiales, tope_materiales);
    
    procesar_archivo_edificios(edificios, tope_edificios);

    if( ( tope_materiales != ERROR ) && ( tope_edificios != ERROR )){
        mensaje_bienvenida();

        int opcion_elegida = 0;
        
        mostrar_opciones();
        opcion_elegida = pedir_opcion();
        validar_opcion_ingresada(opcion_elegida);

        while(opcion_elegida != GUARDA_SALIR){
            procesar_opcion(opcion_elegida, materiales, tope_materiales, edificios, tope_edificios);

            mostrar_opciones();
            opcion_elegida = pedir_opcion();
            validar_opcion_ingresada(opcion_elegida);
            
        }
        
        guardar_cambios_materiales(materiales, tope_materiales);
        guardar_cambios_edificios(edificios, tope_edificios);
        
        imprimir_mensaje_guardado();
    };
    return 0;
}