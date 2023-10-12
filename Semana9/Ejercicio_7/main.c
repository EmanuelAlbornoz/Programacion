 #include "calculos.h"
 #include "user_interface.h"

float sum(float, float);
float substract(float, float);
float multiply(float, float);
float divide(float, float);
float power(float, float);

int main(void){

	add_operation('+', sum);
	add_operation('-', substract);
	add_operation('*', multiply);
	add_operation('/', divide);
	add_operation('^', power);
	
	int error = 0;
	float num1, num2;
	char op;
	
	do{
		if(error == 1){
			error = 0;
			printf("Error\n");
			while(getchar() != '\n');
		}
		get_ecuation(&num1, &op, &num2, &error);
	} while (error == 1);
	
	printf("%f\n", calc_res(num1, num2, op, &error));

	return 0;
} 

float sum(float x, float y){
	return (x + y);
}

float substract(float x, float y){
	return (x - y);
}

float multiply(float x, float y){
	return (x * y);
}

float divide(float x, float y){
	return (x/y);
}

float power(float x, float y){
	int i = 0;
	for(i = 0; i < y; i++){
		x *= x;
	}
	return x;	
}
