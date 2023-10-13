#ifndef INTERFACE_H
#define INTERFACE_H

// Esta funcion se encarga de convertir la exprecion xxxx op yyyy en 3 variables, 2 numeros y un operador.
int get_ecuation(float *, char *, float *, int *);

// Esta funcion se encarga de mostrar mensajes de error al usuario.
void print_error(int);

// Esta funcion se encarga de mostrar el menu e instrucciones al usuario.
void prints(int);

// Esta funcion se encarga de mostrar el resultado final al usuario.
void print_res(float x);

#endif //INTERFACE_H
