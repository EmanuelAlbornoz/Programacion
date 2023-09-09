#include <stdio.h>
#define INICIO 1		// Con que numero empieza la matriz
#define FILAS 5			// Numeros de filas de la matriz
#define COLUMNAS 4		// Numero de columnas de la matriz

int main(void){

    int m = FILAS, n = COLUMNAS;				// Definimos m, cantidad de filas, y n, cantidad de columnas.
    int start= INICIO;						// Definimos una variable con el valor de la casilla columna 1, fila 1.
    int fila, columna;						// Definimos variables para iterar dentro de la matriz.

    for(fila = start; fila <= m - 1 + start; fila++){		// Llamamos fila a la posicion de la fila + el start, es decir, 
    								// fila va a valer una cte mas la posicion de la fila, por lo que termina cuando fila = m - 1 + start (-1 porque empieza en posicion 1)														
        for(columna = 1; columna <= n; columna++){	        // Llamamos columna a la posicion de la columna.
            printf("%3d  ", columna + fila - 1);		// El numero de la casilla resulta de sumar las coordenadas de la matriz y restar 1, asi se va incrementando segun incrementan las columnas
        }							// y segun incrementan las filas.
        							//
        printf("\n");						// Agregamos nueva linea.
    }

    return 0;
}
