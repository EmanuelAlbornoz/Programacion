#include <stdio.h>

int main()
{

    double var = -1.75; // define una variable double
    int int_var = (int)var; //definimos la parte entera (truncada) para ayudar en calculos
    double rta_a = (double)(var>=0 ? int_var + 1 : int_var); // si la variable es positiva se trunca y se suma una, si es negaativa basta con truncar
    double rta_b = (double)(var>=0 ? int_var : int_var - 1); // si la variable es positiva basta con truncar, si es negativa se trunca y se suma 1
    double rta_c = (double)(var >=0 ? ((var - int_var) >= 0.5 ? rta_a : rta_b) : ((int_var - var) >= 0.5 ? rta_b : rta_a)); //Revisa si la parte fraccionaria es mayor que 0.5 (2 casos para pos y neg)
    double rta_d = (double)int_var; // pasamos a double la parte entera
    double rta_e = var>=0 ? var : -var; // si es positivo queda igual, si es negativo cambia de signo 
    printf("a)Funcion Techo: %f\nb)Funcion Piso: %f\nc)Redondeo %f\nd)Funcion Truncado: %f\ne)Valor absoluto: %f\n", rta_a, rta_b, rta_c, rta_d, rta_e);

}
