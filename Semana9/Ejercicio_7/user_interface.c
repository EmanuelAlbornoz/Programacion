#include <stdio.h>
#include "user_interface.h"

/* 		La funcion de este modulo es encargarse de todo lo relacionado con interaccion con el usuario
	ya sea tomar datos del mismo o mostrar algo en pantalla. 
*/

// Esta funcion se encarga de tomar un numero del usuario.
static float get_num(int *, int * enter);

// Esta funcion se encarga de tomar un operador del usuario.
static char get_op(void);


// Esta funcion se encarga de tomar un numero del usuario.
static float get_num(int * error, int * enter){

	int c, neg = 0;
	float rta = 0.0, punto = 0.0;

	while((c = getchar()) == ' ');  // Este while se encarga de borrar todos los espacios que ponga el usuario.
	if(c == '\n'){			// Si entra a buscar un numero y se encuentra con una nueva linea, significa que el usuario
		*error = 1;		// no ingreso un numero que debia ingresar, por lo tanto hay un error, se devuelve 0.0
		return 0.0;		// para salir de la funcion.
	}

	do{
		if(c <= '9' && c >= '0'){				// Este bloque do-while es el que se encarga de recibir un numero
			if(punto == 0){					// tipo float del usuario. Por ello requiere variables que indican
				rta = rta * 10 + (c-'0');		// si el usuario ya puso un punto o un -. 
			} else {					// Si el usuario ya puso un punto el digito debe ser tratado distinto
				rta = rta + (c-'0')/punto;		// a si todavia no lo uso.
				punto *= 10;				// 
			}						//
		} else if ((c == '.' || c == ',') && punto == 0){	//
			punto = 10;					//
		} else if(c == '-' && neg == 0){			//
			neg = 1;					//
		} else {						//
			*error = 1;					//
		}							// El while termina cuando encuetnra un espacio o un enter, ya que el primer numero en xxxx op yyyy
	}while((c = getchar()) != ' ' && (c != '\n'));			// No termina con un enter sino con un espacio.
	
	if(c == '\n'){		// Si termino con un enter se pone en uno el flag de enter, ya que si se estaba buscando el primer numer
		*enter = 1;	// y se encuentra un enter hay un error ya que faltan el operador y el segundo numero.
	}			//
	
	if(neg == 0){		// Se devuelve el numero, ya sea positivo o negativo.
		return rta;	//
	} else {		//
		return -rta;	//
	}
}

// Esta funcion se encarga de tomar un operador del usuario.
static char get_op(void){
	int c;				// Esta funcion es muy simple, con el while quita cualquier espacio que el usuario
	while((c = getchar()) == ' ');	// coloque entre el primer numero y el operador. Y se queda en c al operador.
	return (char)c;			// Devuelve el operador, recordando que getchar devuelve un int, por eso el casteo.
}

// Esta funcion se encarga de convertir la exprecion xxxx op yyyy en 3 variables, 2 numeros y un operador.
int get_ecuation(float * x, char * op, float * y, int * err){ 
	int enter = 0;			
	*x = get_num(err, &enter);	// Esta funcion encuentra ordenadamente, primero el primer numero, luego  
	if(enter == 1){			// el operador y por el ultimo el segundo numero. Asegurandose que paso
		*err = 1;		// a paso no haya ningun error. Por ejemplo que no haya un enter antes del operador
		return 1;		// o que el operador mismo no sea un enter. 
	}				//
	*op = get_op();			// La funcion devuelve un 1 si encontro un error, sino devuelve un 0; 
	if(*op == '\n'){		// 
		*err = 1;		// Si bien el numero devuelto luego no es usado por el main para el manejo de errores, es 
		return 1;		// util devolver un 1 para detener el proceso de la funcion, y no realizar operacion extra
	}				// que no van a servir de nada. 
	*y = get_num(err, &enter);	//
					//
	return 0;			//
}

/*
		Las siguientes 3 funciones no tienen mucho para ser comentadas, simplemente son funciones que muestran distintos mensajes en pantalla.
	En 2 de ellas usamos un switch case para diferenciar mensajes, asi el main cuando llame a estas funciones, puede especificar con un numero cual
	es el mensaje que desea mostrar al usuario. 
*/



// Esta funcion se encarga de mostrar mensajes de error al usuario.
void print_error(int x){

	switch(x){
		case 1: 
			printf("Error al ingresar los numeros! Recuerde respetar el formato xxxx op yyyy\n\n");
			
			
			break;
		case 2:
			printf("Error!, el operador que esta intentando usar no existe actualmente.\nRecuerde: \n");
			printf("Lista de operaciones disponibles con sus operadores:\nsuma: '+'\nResta: '-'\n");
			printf("Multiplicacion: '*'\nDivision: '/'\nPotencia: '^', el exponente debe ser entero y positivo, sino sera redondeado para arriba.\n\n");
			break;
		default:
			printf("Error");
	}
}

// Esta funcion se encarga de mostrar el menu e instrucciones al usuario.
void prints(int x){

	switch(x){
		case 1: 
			printf("Bienvenido a la calculadora del grupo 3\n\n");
			printf("Lista de operaciones disponibles con sus operadores:\nsuma: '+'\nResta: '-'\n");
			printf("Multiplicacion: '*'\nDivision: '/'\nPotencia: '^', el exponente debe ser entero y positivo, sino sera redondeado para arriba.\n");
			printf("El formato debe ser xxxx op yyyy\n\nPresione enter para empezar");
			while(getchar() != '\n');
			break;
		case 2:
			printf("Ingrese la operacion a realizar: ");
			break;
	}

}

// Esta funcion se encarga de mostrar el resultado final al usuario.
void print_res(float x){
	printf("Resultado: %f\n", x);
}



