#include "mensajes_pantalla.h"
#include "emojis.h"
#include "colors.h"
#include <iostream>
#include <unistd.h>

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
  ,,                                                                                                        ,,       ,,                   \n\
`7MM                                                        mm                                              db      ,,                   \n\
  MM                                                        MM                                                                       \n\
  MM    ,6Yb.       ,p6bo     ,pWWq.  `7MMpMMMb.  ,pPYbd  mmMMmm  `7Mb,od8 `7MM  `7MM   ,p6bo    ,p6bo    `7MM   ,pWWq.  `7MMpMMMb.  \n\
  MM   8    MM     6M'  OO  6W'   `Wb   MM    MM  8I   `    MM      MM' '    MM    MM  6M'  OO  6M'   OO    MM  6W'   `Wb   MM    MM  \n\
  MM    ,pm9MM     8M       8M     M8   MM    MM  `YMMMa.   MM      MM       MM    MM  8M       8M          MM  8M     M8   MM    MM  \n\
  MM   8M   MM     YM.    , YA.   ,A9   MM    MM  L.   I8   MM      MM       MM    MM  YM.    , YM.    ,    MM  YA.   ,A9   MM    MM  \n\
.JMML.`Moo9^Yo.     YMbmd'   `Ybmd9'  .JMML  JMML.M9mmmP'   `Mbmo .JMML.     `MbodYML.  YMbmd'   YMbmd'   .JMML. `Ybmd9'  .JMML  JMML. \n" 
    << END_COLOR << endl;
    cout << "\
    \t\t\tLuego de muchos años de espera Andy finalmente encontró el lugar perfecto para\n\
    \t\tasentarse y comenzar a armar su pequeño paraíso. Como primera medida decidió nombrar\n\
    \t\tsu nuevo hogar como Andypolis, la maravillosa ciudad de los programadores.\n\
    \t\t\tPoco a poco con el pasar de los días el rumor del surgimiento de una ciudad exclusiva para\n\
    \t\tprogramadores se fue difundiendo y la gente comenzó a llegar a ella y se armó un programa\n\
    \t\tque ayude a contabilizar los materiales y edificios de la ciudad.\n\
    \t\t\tFue tanta la popularidad de este programa que llegaron aún más programadores a ayudar y\n\
    \t\tpasar el diseño de Andypolis al programa, pero algunos de ellos, fanáticos de los\n\
    \t\tvideojuegos, decidieron darle una pequeña vuelta de tuerca…\n\
    \t\t\tPasaron unas semanas y los habitantes de Andypolis nos pidieron ayuda para generar una\n\
    \t\tnueva versión de nuestro programa. Como la dificultad del programa aumentó nos pidieron\n\
    \t\tque dos programadores se unan y desarrollen su programa en conjunto." << endl << endl;
    cout << "\t\t\t\t\t\tPresione [ENTER] para continuar"<< endl;
    cin.get();
    system("clear");
}

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
    cout << TXT_BOLD << TXT_GREEN_118 /* <<  AFIRMATIVO */ << END_COLOR <<" , en caso afirmativo, o ";
    cout << TXT_BOLD << TXT_LIGHT_RED_9 /* <<  NEGATIVO */ << END_COLOR <<" , en caso negativo." << endl;
}