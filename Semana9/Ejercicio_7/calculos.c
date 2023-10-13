#include "calculos.h"

/*
		Este modulo se encarga de relacionar operandos con funciones, para ello utiliza arreglos de operadores y punteros a funciones. 
	La idea es que el main complete estos arreglos en tiempo de ejecucion.

*/

static char operator[MAX_OPERATORS];				// Declaramos 2 arreglos globales asociados, uno contiene operadores, la otra
static float (* actions[MAX_OPERATORS])(float, float);		// contiene punteros a las funciones asociadas a cada operador.

// Esta funcion se encarga de rellenar los arreglos de manera ordenada.
void add_operation(char op, float(*a)(float, float)){
	
	static int i = 0;	// Primero declaramos una variable local que mantenga su valor.
	operator[i] = op;	// Luego guardamos el operador en su arreglo y el puntero a su arreglo de manera que ambos
	actions[i] = a; 	// guarden la misma posicion en su respectivo arreglo.
	i++;			// Luego incrementamos i para que el proximo operador quede en el siguiente lugar del arreglo.
}

// Esta funcion se encarga de calcular el resultado recibiendo el operador y usando los arreglos.
float calc_res(float x, float y, char op, int * error){
	
	float resultado;				// Esta funcion primero itera el arreglo de operadores, y los va comparando con el operador recibido	
	int i;						// en caso de que lo encuentre en el arreglo, entonces llama a la funcion correspondiente, utilizando
	for(i = 0; i < MAX_OPERATORS - 1; i++){		// el puntero a funcion que esta guardado en el otro arreglo en el mismo indice. 
		if(op == operator[i]){			// Y ademas se pone el indice en el valor maximo de operadores, esto, para salir del for 
			resultado = actions[i](x, y);	// y para ser usado luego como flag.
			i = MAX_OPERATORS;		//
		}					//
	}						//
							//
	if(i > MAX_OPERATORS){				// Este if se encarga de ver si el for termino sin encontrar al operador o enctontrando al operador. 
		return resultado;			// Para ello revisa si el iterador salio con un valor mayor al limite, que solo pasa si encontro el operador. 
	} else {					// En cuyo caso, devuelve el resultado. Caso contrario devuelve 0 e indica el error.
		*error = 2;				//
		return 0;				//
	}	
}
