#include <stdio.h>
enum MESES {ENERO = 1, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE}; // Definimos constantes para todos los meses.

/* LOGICA GENERAL DEL PROGRAMA
	Este programa toma del usuario dos fechas y devuelve la cantidad de dias que hay entre dichas fechas. Para hacer esto primero calcula cuantos dias hay entre el 1 de enero del año 1
	hasta cada una de las fechas dadas y luego resta esos 2 resultados, obteniendo la cantidad de dias entre ambas fechas, como era deseado. 
*/

// Esta funcion devuelve 1 si un año es bisiesto y 0 si no lo es.
int esBisiesto(int año);

// Esta funcion cuenta cuantos dias pasaron desde el 1 de enero del año 1 hasta la fecha.
int contadorDias(int dia, int mes, int año);

// Esta funcion valida que la fecha sea coherente, es decir, que exista.
int validar(int dia, int mes, int año);

// Esta funcion recibe los numeros del usuario, valida que efectivamente sean numeros y los convierte de caracteres a enteros.
int getNum(void);

// Esta funcion realiza la resta entre la cantidad de dias que tiene cada fecha, dando como resultado los dias que hay entre las fechas.
int diferenciaDias(int, int);

int main(void){
		
	int dia_i, mes_i, año_i;	// Definimos 6 variables, una para cada dato provisto por el usuario.
	int dia_f, mes_f, año_f;	// Es decir, dia, mes y año, inicial y final.
	int error = 0;			// Ademas, definimos una variable que indicara si el usuario cometio un error al ingresar los datos.
	
	do{												// Este do - while se encarga de tomar los datos del usuario.
		if(error == 1){										// Para ello imprime en panatalla el mensaje que indica que ingresar al usuario
			printf("\nError, la fecha ingresada no tiene sentido, intente de nuevo:\n");	// y luego llama a getNum que se encarga de recibir el numero y verificar que sea un numero
		}											// Luego cada dato es guardado en su respectiva variable. 
													//
		printf("Ingrese el dia inicial: ");							// Usamos un do - while para poder tener un mejor manejo en caso de que el usuario haga un error al
		dia_i = getNum();									// ingresar uno de los datos. Para ello la primera vez que se entra en el bloque del do - while la 
													// variable error esta en 0, si vuelve entrar al bloque do - while es porque fallo la validacion, y por 
		printf("Ingrese el mes inicial: ");							// lo tanto, o el usuario ingreso algo que no era un numero o bien la fecha ingresada no tenia sentido
		mes_i = getNum();									// (por ejemplo 30 de febrero). 
													// Como la primera vez que entro al do - while se guardo un 1 en la variable error, si vuelve a entrar
		printf("Ingrese el año inicial: ");							// va a cumplir la condicion del if que le indica al usuario que la fecha que ingreso contenia un error.	
		año_i = getNum();									//
													//
		printf("Ingrese el dia final: ");							//
		dia_f = getNum();									//
													//
		printf("Ingrese el mes final: ");							//
		mes_f = getNum();									//
													//
		printf("Ingrese el año final: ");							//
		año_f = getNum();									//
													//
		error = 1;										//
	} while(!(validar(dia_i, mes_i, año_i) && validar(dia_f, mes_f, año_f)));			//
	
		
	printf("Entre el %d/%d/%d y el %d/%d/%d hay ", dia_i, mes_i, año_i, dia_f, mes_f, año_f);			// Imprimimos las fechas y cuantos dias hay entre las mismas.
	printf("%d dias.\n", diferenciaDias(contadorDias(dia_i, mes_i, año_i), contadorDias(dia_f, mes_f, año_f)));	// Usamos 2 printf para mas orden en el codigo.

	return 0;
}

// Esta funcion devuelve 1 si un año es bisiesto y 0 si no lo es.
int esBisiesto(int año){	
					
	if (año % 4 == 0) {						// El primer if se encarga de ver si el 
		if (año % 100 == 0 && !(año % 400 == 0)) {		// año es multiplo de 4. Luego el segundo
			return 0;					// if revisa que cumpla la segunda condicion, es decir,
		}							// que si es multiplo de 100 pero no de 400 entonces no es bisiesto
		return 1;						//
	} else {							//
		return 0;						//
	}								//
}									//

// Esta funcion cuenta cuantos dias pasaron desde el 1 de enero del año 1 hasta la fecha.
int contadorDias(int dia, int mes, int año){

	int rta = 0;									// Definimos una variable para ir guardando la suma de dias.
											//
	rta += dia;									// Primero contamos cuantos dias pasaron desde el comienzo del mes hasta el dia pedido.
											//
	int i;										// Definimos una variable para iterar dentro del for.
	for(i = ENERO; i < mes; i++){							// Este for se encarga de contar cuantos dias pasaron desde el comienzo del el año el hasta comienzo del mes.
		if (i <= JULIO){							// Desde enero hasta julio se cumple que los meses pares tiene 30 (exepto febrero) y los impares 31
			if(i == FEBRERO){						// Este if dentro es para el caso particular de febrero.
				rta += (esBisiesto(año) ? 29 : 28);			// Revisamos si el año es bisiesto o no, lo que dira si febrero tuvo 28 o 29 dias.
			} else {							//
				rta += (i % 2 ? 31 : 30);				// Si es mes par sumamos 30 y si es impar 31. (i % 2 devuelve 0 si el mes es par) 
			}								//
											//
		} else {								//
			rta += (i % 2 ? 30 : 31);					// Luego de julio se cumple que los meses pares tienen 31 y los impares 30, por eso esta al reves.
		}									//
	}										//
											//
	for(--año; año > 0; año--){							// Este for se encarga de contar cuantos dias pasaron desde el 1 de enero del año 1 hasta el comienzo del
		if(esBisiesto(año)){							// año en el año dado. Para ello va iterando desde el año anterior al dado hasta el año 1, se pregunta
			rta += 366;							// si cada año fue bisisesto o no y suma 365 o 366 dias consecuentemente. 
		} else {								//
			rta += 365;							//
		}									//
	}										//
											//
	return rta;									// Devuelve la cantidad de dias.
}											//

// Esta funcion valida que la fecha sea coherente, es decir, que exista.
int validar(int dia, int mes, int año){
															
	if(año <= 0){							// Primero revisa si año es 0, lo cual es invalido (pues suponemos que el primer año es el 1).
		return 0;						// Ademas revisa que la variable año no sea -1, que indicaria que getNum identifico que se ingreso 
	}								// algo que no era un numero.
									//
	if(mes <= DICIEMBRE && mes > 0){				// En principio revisa que el mes este dentro del rango ENERO-DICIEMBRE y que no sea -1(no numero).
		switch(mes){						// Entra al switch
			case ENERO:					// 
			case MARZO:					//
			case MAYO:					//
			case JULIO:					// Estos 7 casos son los meses que tienen 31 dias, y por ello mismo, si la fecha dada esta 
			case AGOSTO:					// en alguno de estos meses, el rango el cual puede tener la variable dia es entre 1 y 31.
			case OCTUBRE:					//
			case DICIEMBRE:					//
				if(dia <= 31 && dia > 0){		// El if nuevamente ademas de revisar el rango se asegura que no sea -1(no numero)
					return 1;			// De cumplirse esto queda validada la fecha
				} else {				//
					return 0;			// 
				}					//
				break;					//
			case FEBRERO:					// Caso particular, febrero.
				if(esBisiesto(año) == 1){		// El primer if revisa si el año es bisiesto.
					if(dia <= 29 && dia > 0){	// En caso que sea bisiesto el rango que puede tener dia es entre 1 y 29.
						return 1;		//
					} else {			//
						return 0;		//
					}				//
				} else {				//
					if(dia <= 28 && dia > 0){	// En caso de que no sea bisiesto el rango que puede tener dia es entre 1 y 28.
						return 1;		//
					} else {			// En ambos caso verifica que no sea -1(no numero)
						return 0;		//
					}				//
				}					//
				break;					//
			case ABRIL:					//
			case JUNIO:					// Estos 4 ultimos casos son los meses que tienen 30 dias, y por ello, si la fecha dada esta
			case SEPTIEMBRE:				// en alguno de estos meses, el rango el cual puede tener la variable dia es entre 1 y 30.
			case NOVIEMBRE:					//
				if(dia <= 30 && dia > 0){		// Verifica que cumpla el rango y no sea -1(no numero)
					return 1;			// Si se cumpla queda validada la fecha
				} else {				//
					return 0;			//
				}					//
				break;					//
		}							//
	} else {							//
		return 0;						//
	}								//
	return 0;							//						
}

// Esta funcion recibe los numeros del usuario, valida que efectivamente sean numeros y los convierte de caracteres a enteros.
int getNum(void){
							// 
	int c, num = 0;					// Definimos 2 variables, una que recibe el caracter del usuario y otra para 
							// ir guardando el numero ya transformado a entero.
	while((c = getchar()) != '\n'){			// Tomamos todos los caracteres hasta que el usuario de enter.
		if(c >= '0' && c <= '9'){		// Validamos que el caracter sea un caracter de numero.
			num = num * 10 + (c - '0');	// Si asi es, corremos los digitos del numero a la izquierda (multiplicando por la base) y sumamos el caracter convertido a entero.
		} else {				//
			c = '\n';			// En caso de que no se valide que es un numero, ya no vale la pena seguir, por lo que se pone un enter en c, y sale del while.
			num = -1;			// A su vez, se pone num igual a -1 para indicar que hubo un error. Este -1 
		}					// va a ser identificado luego por la funcion validar como una fecha no valida. 
	}						//
							//
	return num;					// Devolvemos el numero ya convertido.
}

// Esta funcion realiza la resta entre la cantidad de dias que tiene cada fecha, dando como resultado los dias que hay entre las fechas.
int diferenciaDias(int fecha_i, int fecha_f){
						// 
	if(fecha_i >= fecha_f){			// Primero revisa cual de las fechas es la fecha mas actual. 
		return fecha_i - fecha_f;	// Luego, consecuentemente, hace la resta de forma que 
	} else {				// el resultado siempre sea una cantidad de dias positiva.
		return fecha_f - fecha_i;	//
	}					//
}








