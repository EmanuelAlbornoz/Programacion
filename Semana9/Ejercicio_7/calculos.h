#ifndef CALCULOS_H
#define CALCULOS_H

#define MAX_OPERATORS 10 //definimos cual es el maximo de operadores que tiene la calculadora.

// Esta funcion se encarga de rellenar los arreglos de manera ordenada.
void add_operation(char, float(*a)(float, float));

// Esta funcion se encarga de calcular el resultado recibiendo el operador y usando los arreglos.
float calc_res(float, float, char, int*);

#endif // CALCULOS_H
