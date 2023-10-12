#include "calculos.h"

static char operator[MAX_OPERATORS];
static float (* actions[MAX_OPERATORS])(float, float);

void add_operation(char op, float(*a)(float, float)){
	
	static int i = 0;
	operator[i] = op;
	actions[i] = a; 
	i++;
}

float calc_res(float x, float y, char op, int * error){
	
	float resultado;
	int i;
	for(i = 0; i < MAX_OPERATORS - 1; i++){
		if(op == operator[i]){
			resultado = actions[i](x, y);
			i = MAX_OPERATORS;
		}
	}
	
	if(i > MAX_OPERATORS){
		return resultado;
	} else {
		*error = 1;
		return 0;
	}	
}
