#include <stdio.h>
#define NUM_A_EVALUAR 2147483647			// Numero para ver si es primo rango (-2147483647 hasta 2147483648)

int main(void)
{
    int num = NUM_A_EVALUAR;				// Guarda en una variable el numero a ser evaluado
    int cont;						// Definimos un contador. 

    if (num <= 1){					// El if se encarga de asegurarse que el 
        printf("%d no es primo\n", num); 		// numero a evaluar sea un natural.
    }							// Ademas si es 1 tampoco es primo asi que lo incluimos en este rango.

    for(cont = num - 1; cont > 1; cont--){		// El for se encarga de iterar todos los numeros desde num-1 hasta 2 
        if(num % cont == 0){				// que luego seran los divisores de num.
            printf("%d no es primo\n", num);		// Al hacer la division y ver el resto, si el resto es 0 entonces  
            cont = 0;					// significa que num es multiplo de un numero distinto de si mismo o 1 y por ende no es primo.
        }						// Si no es primo ponemos cont en 0 para que salga del for.
    }							//
    
    if(cont == 1){					// El if revisa si el for se ejecuto por completo y termino valiendo 1 
        printf("%d es primo\n", num);			// lo que indicaria que num no es multiplo de ningun numero distinto de si mismo o 1, y por ende primo.
    }							// o si fue forzado a salir valiendo 0 y por ende no es primo.


    return 0;
}
