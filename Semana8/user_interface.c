#include "user_interface.h"

// Esta funcion se encarga de mostrar en pantalla la matriz con las celulas, junto con el respectivo numero de generacion.
void mostrar(char m[ALTO][ANCHO], int gen){

	int i, j;					// La funcion recibe la matriz (la posicion 0, 0 de la matriz) a imprimir y el numero de generacion al cual pertenece la matriz.
							//
	printf("\nGeneracion %d\n", gen);		// Se imprime el numero de generacion.
	for(i = 1; i <= ALTO_REAL; i++){		// El primer for se encarga de iterar filas y el segundo for se encarga de iterar columnas,
		putchar('|');				// ambos for comienzan en 1 para no imprimir los bordes que fueron agregados para el
		for(j = 1; j <= ANCHO_REAL; j++){	// funcionamiento del programa. 
			printf("%c|", m[i][j]);		// 
		}					//
		putchar('\n');				// Agregamos nuevas lineas y barras para ayudar a la esteitca del juego.
	}						//
	putchar('\n');					//

}

// Esta funcion se encarga de validar que el jugador ingrese efectivamente un numero, ademas lo convierte de char a int. Tambien detecta cuando el jugador quiere salir.
int validar_num(void){

	int rta = 0, c, ingreso = 0;						// Esta funcion no recibe nada.
										// 	
	while((c = getchar()) != '\n'){						// Este while va a recibir todo lo que ingrese el jugador.
		ingreso++;							// Si el jugador ingresa algo, entra en el while y se incrementa la variable ingreso. 
		if(c <= '9' && c >= '0'){					// El if se encarga de asegurarse que lo que ingreso el jugador se un numero
			rta = rta * 10 + (c - '0');				// el numero se va guardando en la variable rta.
		} else if((c == 'q' || c == 'Q') && ingreso == 1){ 		// La segunda condicion revisa si el jugador ingreso solo una q. Si es el caso, devuelve un -1(SALIR)
			return SALIR;						// Si el jugador ingresa un numero seguido por una q, se considera que no quiere salir, sino que cometio un error.
		}else {								// 
			return NO_NUMERO;					// En caso de que lo que ingreso el jugador no sea un numero ni una unica q, la funcion devuelve un -2(NO_NUMERO).
		}								// 
	}									//
										//
	if(ingreso == 0){							// Si el jugador presiona enter, no se entra al while y por lo tanto ingreso vale 0, por lo que se devuelve un 1, para 
		return 1;							// avanzar una generacion.
	} else {								// Si el jugador ingresa un numero correctamente, se devuelve el numero.
		return rta;							//
	}									//
}

