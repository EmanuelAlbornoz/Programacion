#include "user_interface.h"

static float get_num(int *, int * enter);
static char get_op(void);

static float get_num(int * error, int * enter){

	int c, neg = 0;
	float rta = 0.0, punto = 0.0;

	while((c = getchar()) == ' '); // Este while se encarga de borrar todos los espacios que ponga el usuario.
	if(c == '\n'){
		*error = 1;
		return 0.0;
	}

	do{
		if(c <= '9' && c >= '0'){
			if(punto == 0){
				rta = rta * 10 + (c-'0');
			} else {
				rta = rta + (c-'0')/punto;
				punto *= 10;
			}
		} else if ((c == '.' || c == ',') && punto == 0){
			punto = 10;
		} else if(c == '-' && neg == 0){
			neg = 1;
		} else {
			*error = 1;
		}
	}while((c = getchar()) != ' ' && (c != '\n'));
	
	if(c == '\n'){
		*enter = 1;
	}
	
	if(neg == 0){
		return rta;
	} else {
		return -rta;
	}
}

static char get_op(void){
	int c;
	while((c = getchar()) == ' ');
	return (char)c;
}

int get_ecuation(float * x, char * op, float * y, int * err){ 
	int enter = 0;
	*x = get_num(err, &enter);
	if(enter == 1){
		*err = 1;
		return 1;
	}
	*op = get_op();
	if(*op == '\n'){
		*err = 1;
		return 1;
	}
	*y = get_num(err, &enter);
	
	return 0;
}
