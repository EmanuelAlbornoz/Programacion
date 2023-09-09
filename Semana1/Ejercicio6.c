#include <stdio.h>
#define MASCARA_1 0x02 //define mascara 00000010 para comprobar si hay un 1 posicion 1 
#define MASCARA_5 0x20 //define mascara 00100000 para comprobar si hay un 1 posicion 5
#define MASCARA_2 0x04 //define mascara 00000100 para comprobar si hay un 0 posicion 2
#define MASCARA_6 0x40 //define mascara 01000000 para comprobar si hay un 0 posicion 6

int main(){

	char porta = 32; //Creo la variable porta que representa el registro AccA
	int condicion1 = (porta&MASCARA_1)&&(porta&MASCARA_5); //comprueba que ambas posiciones 1 y 5 tengan un 1 
	int condicion2 = (porta&MASCARA_2)&&(porta&MASCARA_6); //compureba que ambas posiciones 2 y 6 tengan un 1
	printf("%d\n", condicion1 || !condicion2); //negamos la condicion2 que solo es 0 si hay 0 en la posicion 2 y 6

}
