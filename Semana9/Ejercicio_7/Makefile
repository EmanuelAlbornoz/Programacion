calculadora: main.o calculos.o user_interface.o
	gcc main.o calculos.o user_interface.o -Wall -g -o calculadora

main.o: main.c calculos.h user_interface.h 
	gcc main.c -c -Wall -g
	
calculos.o: calculos.c calculos.h
	gcc calculos.c -c -Wall -g
	
user_interface.o: user_interface.c user_interface.h
	gcc user_interface.c -c -Wall -g
	
clean: 
	rm *.o
