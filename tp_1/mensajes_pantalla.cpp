#include "mensajes_pantalla.h"
#include "emojis.h"
#include "colors.h"
#include "edificios.h"
#include <iostream>
#include <unistd.h>

void imprimir_mensaje_error(){
    cout << TXT_BOLD << "\t" << EMOJI_WARNRING << TXT_DARK_RED_1  << TXT_UNDERLINE <<" ERROR!! " << END_COLOR << EMOJI_WARNRING << endl;
}

void imprimir_mensaje_esperar(int tiempo){
    cout << endl;
    cout << "»»Por favor espere que volverá al menu principal en ";
    cout << TXT_BOLD;
    cout << tiempo;
    cout << END_COLOR;
    cout <<" segundos..." << EMOJI_RELOJ << endl;
    sleep(tiempo);
    system("clear");
}

void imprimir_mensaje_opcion_afirmativa_negativa(){
    cout << TXT_BOLD << TXT_GREEN_118 <<  AFIRMATIVO << END_COLOR <<" , en caso afirmativo, o ";
    cout << TXT_BOLD << TXT_LIGHT_RED_9 <<  NEGATIVO << END_COLOR <<" , en caso negativo." << endl;
}