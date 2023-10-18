juego_de_la_vida: main.o program_logic.o user_interface.o
	gcc main.o program_logic.o user_interface.o -o juego_de_la_vida -Wall -g

main.o: main.c medidas.h program_logic.h user_interface.h 
	gcc main.c -c -Wall -g

program_logic.o: program_logic.c program_logic.h medidas.h
	gcc program_logic.c -c -Wall -g
	
user_interface.o: user_interface.c user_interface.h medidas.h
	gcc user_interface.c -c -Wall -g
	
clear: 
	rm *.o
