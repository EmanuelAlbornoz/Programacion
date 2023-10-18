#ifndef PROGRAM_LOGIC_H
#define PROGRAM_LOGIC_H

#include "medidas.h"

// Esta funcion se encarga de contar cuantos vecinos vivos tiene una celula, viva o muerta. 
int contador_vecinos (char m[ALTO][ANCHO], int i, int j);

// Esta funcion se encarga de preparar la siguiente generacion, recibe la matriz con la generacion actual y guarda en la otra matriz la nueva.  
void sig_gen (char gen1[ALTO][ANCHO], char gen2[ALTO][ANCHO]);

#endif // PROGRAM_LOGIC_H
