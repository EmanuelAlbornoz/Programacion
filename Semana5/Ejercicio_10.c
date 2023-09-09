#include <stdio.h>
#define ANCHO_REAL 6			// Definicion de macros:
#define ALTO_REAL 5			// ANCHO_REAL y ALTO_REAL son el ancho y alto que vera el jugador.
#define ANCHO (ANCHO_REAL + 2)		// ANCHO Y ALTO son el ancho y alto que usa el programa para 
#define ALTO (ALTO_REAL + 2)		// los distinots calculos.

#define NO_NUMERO -2			// Definimos una constante para manejo de errores de ingreso del jugador
#define SALIR -1			// y una constante para cuando el jugador quiere salir del juego.

#define ES_PAR(x) (((x) % 2) == 0)	// Definimos un macro parametrizado para revisar si un numero es par. 

/*LOGICA GENERAL DEL PROGRAMA
		El juego requiere analizar todas las posiciones de una matriz, para ello, hay que revizarla celda por celda sin realizarle cambios. Por ello, es necesario usar otra matriz
	para ir escribiendo la siguiente generacion con los cambios que se dan segun las reglas. Las reglas implican analizar los 8 vecinos de cada celda, para hacerlo ubicamos un puntero
	en la posicion del vecino que se ubica arriba a la izquierda y iteramos en un cuadrado de 3 x 3, pasando por todos los vecinos. Este mecanismo para analizar los vecinos nos plantea
	casos particulares, las esquinas y los bordes, ya que alguno de los vecinos esta en el exterior de la matriz. Para evitar esto, el programa trabaja con una matriz que es igual a la
	que se muestra en pantalla mas un borde que no se muestra pero nos ayuda a no tener casos especiales. 
*/


// Esta funcion se encarga de mostrar en pantalla la matriz con las celulas, junto con el respectivo numero de generacion.
void mostrar (char m[ALTO][ANCHO], int gen);

// Esta funcion se encarga de contar cuantos vecinos vivos tiene una celula, viva o muerta. 
int contador_vecinos (char m[ALTO][ANCHO], int i, int j);

// Esta funcion se encarga de preparar la siguiente generacion, recibe la matriz con la generacion actual y guarda en la otra matriz la nueva.  
void sig_gen (char gen1[ALTO][ANCHO], char gen2[ALTO][ANCHO]);

// Esta funcion se encarga de validar que el jugador ingrese efectivamente un numero, ademas lo convierte de char a int. Tambien detecta cuando el jugador quiere salir.
int validar_num (void);

int main (void){
	
	int contador_gen = 0;							// Definimos variables, una para contar las generaciones,
	int avanzar_gen, i;							// una para guardar el numero que ingresa el jugador y una para iterar un for.
										//					
	char m1[ALTO][ANCHO] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	// Defimos dos matrices del tamaño que ve el jugador mas un borde.		
				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 	// Una de las dos la incializamos con la generacion 0, asegurandonos que el	
				{' ', ' ', ' ', ' ', '*', ' ', ' ', ' '}, 	// borde que agregamos quede solo con celulas muertas. 
				{' ', ' ', '*', ' ', '*', ' ', ' ', ' '}, 	//		
				{' ', ' ', ' ', '*', '*', ' ', ' ', ' '}, 	//					
				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},	//					
				{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};	//
										//
	char m2[ALTO][ANCHO];							//
	
	printf("\nBienvenido al juego de la vida\nEste juego es una simulacion de una colonia de celulas.\n");	// Agregamos un pequeño menu, para dar contexto.
	printf("Para avanzar generaciones presione enter o indique cuantas generaciones quiere avanzar.\n");	// 
	printf("Cuando desee salir presione q.\n");								//
	printf("Presione enter para comenzar\n");								//
														// Este while se encarga de descartar todo lo que ingrese
	while(getchar() != '\n');										// el jugador hasta el enter para comenzar.
	
	do{																// El do - while se encarga del funcionamiento del juego.
																	//
		if(contador_gen == 0){													// La primera vez que entra, se muestra la matriz que esta
			mostrar(m1, contador_gen);											// inicializada y se prepara la siguiente generacion en la
			sig_gen(m1, m2);												// otra matriz. Y se aumenta el contador de la generacion.
			contador_gen++;													// 
		} else {														//
			for(i = 0; i < avanzar_gen; i++){										// La siguiente vez que entra, avanzar_gen va a tener el numero
				if (ES_PAR(contador_gen)){										// ingresado por el jugado (o 1 si el jugador dio enter).
					mostrar(m1, contador_gen);									// Si la generacion es par, la matriz a mostrar es la llamada m1
					sig_gen(m1, m2);										// y si es impar es la llamada m2; en cualquiera de los casos, se 
				} else {												// prepara la siguiente generacion en la otra matriz.
					mostrar(m2, contador_gen);									// Asi, las generaciones se van alternando entre matrices, permitiendo
					sig_gen(m2, m1);										// analazir las matrices sin cambiarlas.
				}													//
				contador_gen++;												// Se va incrementando el contandor de generador.
			}														//
		}															//
																	//
		printf("Ingrese el numero de generacion que quiere avanzar: ");								// Se pide al jugador que ingrese un numero, y se guarda en avanzar_gen.
		avanzar_gen = validar_num();												//
																	//
		if(avanzar_gen == NO_NUMERO){												// Si el jugador ingreso algo que no era un numero ni una q, se le 
			printf("\nPor favor, ingrese un numero natural o enter.\nO en caso de querer salir presione solo q.\n\n");	// avisa y se vuelve a entrar al do - while con un -2 en avanzar_gen, y
			while(getchar() != '\n');											// por lo tanto no ocurre nada y se vuelve a preguntar. El while se
		}															// encarga de descartar todo lo que ingreso el jugador, que no es un 
																	// numero.
	}while(avanzar_gen != SALIR);													//
																	// Si el jugador ingresa q, avanzar_gen es SALIR y termina el while.

	return 0;
}

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

// Esta funcion se encarga de contar cuantos vecinos vivos tiene una celula, viva o muerta. 
int contador_vecinos (char m[ALTO][ANCHO], int i, int j){

	int vecinos = 0;					// Esta funcion recibe la matriz (la posicion 0, 0 de la matriz) que se este analizando y dos coordenadas.
	int k, l;						// Las coordenadas no pertenecen a la celda que se esta analizando, sino a 
								// la celda vecina superior izquierda.
	for(k = 0; k < 3; k++){					// Desde esa posicion itera en 3 columnas y 3 filas. 
		for(l = 0; l < 3; l++){				// Es decir, los for anidados iteran por todos los vecinos de la celda y por 
			if(!(k == 1 && l == 1)){		// la celda misma. Por eso el if, se encarga de que el for ignore la posicion
				if(m[i + k][j + l] == '*'){	// de la celda, ya que solo nos interesan los vecinos. 
					++vecinos;		// 
				}				// Notar que l y k son los que iteran de 0 a 2, y eso es cuanto se movio desde la
			}					// celda que fue recibida, es decir, la vecina superior izquierda.
		}						// 
	}							// Luego, si un vecino esta vivo aumenta el contador de vecinos.
	return vecinos;						// La funcion devuelve la cantidad de vecinos que tiene una celda.
}

// Esta funcion se encarga de preparar la siguiente generacion, recibe la matriz con la generacion actual y guarda en la otra matriz la nueva.  
void sig_gen (char gen1[ALTO][ANCHO], char gen2[ALTO][ANCHO]){
	
	int i, j;															// Esta funcion recibe las dos matrices  
																	// (las posiciones 0, 0 de las matrices). 
	for(i = 0; i < ALTO; i++){													// La idea detras de esta funcion es ir iterando las dos matrices
			for(j = 0; j < ANCHO; j++){											// a la vez. 
				if(((i == 0) || (j == 0) || (i == ALTO - 1) || (j == ANCHO - 1))){					// Primera condicion, si la posicion actual es alguno de los bordes
					gen2[i][j] = ' ';										// agregados y que el jugador no ve, guardar en la otra matriz una
				} else {												// celula muerta.
					if(gen1[i][j] == '*'){										// Si no es el borde, revisa si la celula esta viva, si lo esta
						if(contador_vecinos(gen1, i-1, j-1) == 2 || contador_vecinos(gen1, i-1, j-1) == 3){	// llama a contador_vecinos y si cumple con las reglas para sobrevivir,
							gen2[i][j] = '*';								// se guarda en la otra matriz una celula viva en la misma posicion. 
						} else {										// Caso contrario guarda una celula muerta en esa posicion.
							gen2[i][j] = ' ';								//
						} 											//
					} else {											// Luego si la celula esta muerta, llama a contador_vecinos y si
						if(contador_vecinos(gen1, i-1, j-1) == 3){						// cumple con la condicion para revivir, se guarda en la otra matriz
							gen2[i][j] = '*';								// una celula viva en la misma posicion. Caso contrario guarda una 
						} else {										// celula muerta en esa posicion. 
							gen2[i][j] = ' ';								//
						} 											//
					}												//
				}
			}
		}
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
