#include "program_logic.h"

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
