#ifndef CALCULOS_H
#define CALCULOS_H

#define MAX_OPERATORS 10
void add_operation(char, float(*a)(float, float));
float calc_res(float, float, char, int*);

#endif // CALCULOS_H
