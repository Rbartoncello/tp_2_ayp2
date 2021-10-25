#ifndef MENSAJES_PANTALLA_H
#define MENSAJES_PANTALLA_H

/*
 * PRE: -
 * POST: Imprimira por pantalla el nombre del programa.
*/
void mensaje_bienvenida();

/*
 * PRE: -
 * POST: Imprimira por pantalla solamente "Error!!!".
*/
void imprimir_mensaje_error();

/*
 * PRE: -
 * POST: Imprimira por pantalla un mensaje con el tiempo en segundos que el usuario tiene que esperar.
*/
void imprimir_mensaje_esperar(int tiempo);

/*
 * PRE: -
 * POST: Imprimira por pantalla AFIRMATIVA y NEGATIVA.
*/
void imprimir_mensaje_opcion_afirmativa_negativa();

#endif //MENSAJES_PANTALLA_H