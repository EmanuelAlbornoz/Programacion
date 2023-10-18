/*LOGICA GENERAL DEL PROGRAMA
		El juego requiere analizar todas las posiciones de una matriz, para ello, hay que revizarla celda por celda sin realizarle cambios. Por ello, es necesario usar otra matriz
	para ir escribiendo la siguiente generacion con los cambios que se dan segun las reglas. Las reglas implican analizar los 8 vecinos de cada celda, para hacerlo ubicamos un puntero
	en la posicion del vecino que se ubica arriba a la izquierda y iteramos en un cuadrado de 3 x 3, pasando por todos los vecinos. Este mecanismo para analizar los vecinos nos plantea
	casos particulares, las esquinas y los bordes, ya que alguno de los vecinos esta en el exterior de la matriz. Para evitar esto, el programa trabaja con una matriz que es igual a la
	que se muestra en pantalla mas un borde que no se muestra pero nos ayuda a no tener casos especiales. 
*/

#include "medidas.h"
#include "program_logic.h"
#include "user_interface.h"

#define ES_PAR(x) (((x) % 2) == 0)	// Definimos un macro parametrizado para revisar si un numero es par. 


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

