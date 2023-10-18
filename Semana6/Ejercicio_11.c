#include <stdio.h>
#define MAX_NUMS 100	// Definimos una constante para el maximo de numeros que el programa admite para que ingrese el usuario.

/* LOGICA GENERAL DEL PROGRAMA
		El programa recibe una lista de numeros enteros del usuario y, a traves del algoritmo de bubblesort, la ordena y la imprime en pantalla, indicando
	tambien cuantos intercambios hicieron falta para poder ordenar la lista. 
*/

// Esta funcion recibe 2 punteros y cambia entre si los valores a los cuales apuntan.
void swap(int*, int*);

// Esta funcion verifica que el usuario ingrese numeros, y los va guardando en un array que recibe; Y devuelve la cantidad de numeros ingresados.
int validar_num(int lista[], int* error);

// Esta funcion se encarga de ordenar el array que recibe de menor a mayor. Y devuelve la cantidad de intercambios.
int bubblesort(int lista[], int);

int main(void){
												//
	int lista[MAX_NUMS];									// Primero definimos variables, una para la lista, una para manejo de errores, una para
	int error = 0;										// la cantidad de numeros que ingresa el usuario y una para la cantida de elementos que se 
	int numeros;										// intercambian durante el ordenamiento.
	int intercambios;									//
												// Se pide que se ingrese la lista, y se llama a validar_num pasandole la lista y un puntero de la variable
	printf("Ingrese la lista de numeros a ordenar: ");					// error. validar_num guarda los numeros en la lista y devuelve la cantiad de numeros, que se guardan en la
	numeros = validar_num(lista, &error);							// variable numeros. Ademas, si hubo error, nos pone un 1 en la variable error (a traves del puntero).
												//
												//
	while(error == 1){									// Si hubo un error, se le indica al usuario que asi fue y se pone un 0 en la variable error. 
		printf("Error, ingrese solo numeros enteros separados por comas.\n");		// Luego, se vuelve a llamar a validar_num para que el usuario vuelva a ingresar la lista. Esto sucedera
		error = 0;									// hasta que el usuario ingrese una lista valida.
		numeros = validar_num(lista, &error);						//
	}											//
												//							
	if(numeros > MAX_NUMS){									// Si el usuario ingreso mas numeros de los que admite el programa, se le avisa y se toma la lista hasta	
		printf("Cuidado!! has ingresado mas numeros que el maximo permitido\n");	// el numero maximo de elementos, por ello se pone que numeros valga la cantidad maxima.  
		printf("Solo se consideraran los primeros %d numeros\n", MAX_NUMS);		//
		numeros = MAX_NUMS;								//
	}											//
												// Despues, se llama a la funcion bubblesort, a la cual le pasamos la lista y la cantidad de numeros a ordenar. 
	intercambios = bubblesort(lista, numeros);						// bubblesort nos ordena la lista (es decir, la guarda ya ordenada en el mismo arreglo) y nos devuelve la 
	putchar('\n');										// cantidad de intercambios que hizo, que se guardan en intercambios.
												//
	int i;											//
	for(i = 0; i < numeros; i++){								// Este for sirve para imprimir en pantalla la lista luego de ser ordenada,
		if(i == numeros-1){								// A la hora de imprimir el ultimo numero, se omite la coma y se pone una nueva linea.
			printf("%d\n", lista[i]);						//
		} else {									//
			printf("%d, ", lista[i]);						//
		}										//
	}											//
												//
	printf("\nSe realizaron %d intercambios\n", intercambios);				// Por ulitmo, se imprime en pantalla la cantidad de intercambios realizados.
												//
	return 0;										//
}												//

// Esta funcion recibe 2 punteros y cambia entre si los valores a los cuales apuntan.
void swap(int* a, int* b){

	int temp;	// Esta funcion recibe dos punteros, a y b; Se crea una variable temporal que guarda lo que hay en la posicion donde apunta el puntero a.
	temp = *a;	// Luego en la posicion donde apunta a, se guarda lo que hay en la posicion donde apunta b.
	*a = *b;	// Por ultimo, se guarda en la posicion apunta b el valor de la variabe temporal, que era el valor que habia en donde apuntaba a.
	*b = temp;	// Intercambiando lo que habia en la posicion que apunta a por lo que hay en la posicion que apunta b, y viceversa.  
}

// Esta funcion verifica que el usuario ingrese numeros, y los va guardando en un array que recibe; Y devuelve la cantidad de numeros ingresados.
int validar_num(int lista[], int* error){
	
	int c, res_temp = 0, neg = 0, cont = 0;				// Esta funcion recibe un arreglo y el puntero a una variable int.
	while((c = getchar()) != '\n' && cont < MAX_NUMS){		// Primero definimos algunas variables, res_temp va guardando cada numero que ingresa el usuario; 
		if(c <= '9' && c >= '0'){				// neg se activa si el numero ingresado es negativo.
			res_temp = res_temp*10 + (c - '0');		// El while funciona hasta encontrar una nueva linea o hasta que la lista llegue al maximo posible.
			if(neg == 0){					// el primer if verifica que lo que ingreso el usuario sea un numero, si no es el caso hay 3 opciones validas:
				lista[cont] = res_temp;			// o el usuario ingreso un - al comienzo del numero (por eso res_temp == 0) indicando que es negativo, o el usuario ingreso
			} else {					// un espacio para separar comas y numeros (en este ultimo caso el programa no debe hacer nada).
				lista[cont] = -res_temp;		// La ultima opcion es que ingreso una coma para indicar que termino un numero;
			}						//
		} else if((c == '-') && (res_temp == 0)){		// La forma en que funciona es que el primer if va guardando en una posicion los digitos de cada numero, hasta que
			neg = 1;					// encuentra una coma y se incrementa el contador, haciendo que en la proxima pasada el numero se guarde en la siguiente posicion.
		} else if(c == ','){					// Por eso, cuando encuentra una coma, ademas de incrementar el contador, resetea las variables que guardan las caracteristicas de cada
			cont++;						// numero.
			res_temp = 0;					//
			neg = 0;					// El puntero que se le pasa sirve para el manejo de errores. Si el usuario ingresa algo que no sea un numero o una opcion 
		} else if(c == ' ' && (res_temp == 0)){			// valida, la funcion guarda en la posicion a la que apunta el puntero un 1, indicando que hubo error. Es decir, la funcion
		} else {						// indica que hubo un error pero el manejo del error se hace por fuera de la funcion.
			*error = 1;					//
		}							// Si el usuario pone una coma sin poner un numero, se interpreta como un cero (Por ejemplo 1,,2 = 1, 0, 2).
	}								//
									//
	return ++cont;							// Por ultimo, la funcion devuelve la cantidad de numeros que ingreso el usuario, como el contador comienza en 0, luego del while
}									// termina en la cantidad de numeros - 1, por eso se incrementa. 

// Esta funcion se encarga de ordenar el array que recibe de menor a mayor. Y devuelve la cantidad de intercambios.
int bubblesort(int lista[], int nums){

	int i, j;							// Esta funcion recibe un arreglo y la cantidad de numeros a ordenar.
	int cont_intercambios = 0;					// 
									// Para ordenar la lista se utilizo el algoritmo de ordenamiento bubblesort. Para ello, se va iterando hasta el anteultimo elemento, y
	for(i = 0; i < nums; i++){					// a cada elemento se lo compara con el siguiente, en caso de ser mayor al siguiente, intercambian lugares. Y de esto se 
		for(j = 0; j < nums - 1; j++){				// encarga el segundo for. Ademas cada vez que se intercambian lugares, se aumenta un contador de intercambios.
			if(lista[j+1] < lista[j]){			// 
				swap(&lista[j+1], &lista[j]);		// El primer for esta para asegurarse que este procedimiento se repita tantas veces como cantidad de numeros haya. Esto es  
				cont_intercambios++;			// necesario para asegurarse que hasta en el peor caso, las listas quedan bien ordenadas.
			}						// 
		}							//  
	}								// 
	return cont_intercambios;					// Por ultimo, se devuelve la cantidad de intercambios que hubo. 
}									//
