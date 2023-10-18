#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "medidas.h"

#define NO_NUMERO -2			// Definimos una constante para manejo de errores de ingreso del jugador
#define SALIR -1			// y una constante para cuando el jugador quiere salir del juego.

// Esta funcion se encarga de mostrar en pantalla la matriz con las celulas, junto con el respectivo numero de generacion.
void mostrar (char m[ALTO][ANCHO], int gen);

// Esta funcion se encarga de validar que el jugador ingrese efectivamente un numero, ademas lo convierte de char a int. Tambien detecta cuando el jugador quiere salir.
int validar_num (void);

#endif //USER_INTERFACE_H
