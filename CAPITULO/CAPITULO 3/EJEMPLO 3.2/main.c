#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N = 0, I = 0, SUM = 0, NUM = 0;

    printf("Ingrese un numero entero:");
    scanf("%i",&N);

    for (I = 1; I <= N; I++){

    printf("Ingrese un numero entero:");
    scanf("%i",&NUM);

    if (NUM > 0)
        SUM += NUM;
    }


    printf("La suma de los numeros positivos es: %d",SUM);
}
