 #include "calculos.h"
 #include "user_interface.h"

// Esta funcion hace una suma de floats.
static float sum(float, float);

// Esta funcion hace una resta de floats.
static float substract(float, float);

// Esta funcion hace una multiplicacion de floats.
static float multiply(float, float);

// Esta funcion hace una division de floats.
static float divide(float, float);

// Esta funcion hace una potencias de un float (exponente entero.)
static float power(float, float);

int main(void){

	add_operation('+', sum);		// Primero rellenamos los arreglos del archivo calculos (en tiempo de ejecucion).
	add_operation('-', substract);		// para ello llamamos a la funcion add_operation y le damos la relacion que tiene que establecer
	add_operation('*', multiply);		// entre operador y funcion.
	add_operation('/', divide);		//
	add_operation('^', power);		//
	
	int error = 0;			
	float num1, num2, resultado;	
	char op;
	
	prints(1); // menu
	
	do{								// Este do-while se encarga de recibir la operacion que quiere realizar el usuario
		if(error == 1){						// y realizarla. 
			error = 0;					// Error 1 es un error al ingresar los numeros. 
			print_error(1);					// Error 2 es un error por uso de operador no disponible.
		}							//
		if(error == 2){						//
			error = 0;					//
			print_error(2);					//
		}							//	
		prints(2);						//
		get_ecuation(&num1, &op, &num2, &error);		// Llamamos a get_ecuation para recibir los numeros y el operador.
		if(error != 1){						// Solo si no hubo error a la hora de recibir la operacion, se llama
			resultado = calc_res(num1, num2, op, &error);	// a calc_res que calcula el resultado, que se guarda en resultado.
		}							//
	} while (error != 0);						//
	
	print_res(resultado);	// imprime el resultado.

	return 0;
} 

// Esta funcion hace una suma de floats.
static float sum(float x, float y){
	return (x + y);		// Devuelve la suma de los argumentos.
}

// Esta funcion hace una resta de floats.
static float substract(float x, float y){
	return (x - y);		// Devuelve la resta de los argumentos.
}

// Esta funcion hace una multiplicacion de floats.
static float multiply(float x, float y){
	return (x * y);		// Devuelve la multiplicacion de los argumentos.
}

// Esta funcion hace una division de floats.
static float divide(float x, float y){
	return (x/y);		// Devuelve la division de los argumentos.
}

// Esta funcion hace una potencias de un float (exponente entero.)
static float power(float x, float y){
	int i = 0;			// Esta funcion si bien recibe 2 floats, calcula la potencia con
	float rta = 1;			// el exponente entero positivo, que va a ser redondeado siempre para arriba.
	for(i = 0; i < y; i++){		// Para ello se realiza un for que itere y(redondeado para arriba, entero) veces 
		rta *= x;		// y se va multiplicando por x a una variable que en principio estaba en 1.
	}				//
	return rta;			// Cualquier numero negativo es interpretado como 0;
}
