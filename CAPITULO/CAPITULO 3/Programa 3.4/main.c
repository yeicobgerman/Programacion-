#include <stdio.h>
#include <stdlib.h>

int main()
{
    long CUA = 0, SUC = 0;
    int NUM;

    printf("Ingrese un numero:");
    scanf("%i",&NUM);

    while(NUM != 0){
        CUA = pow(NUM,2);
        printf("el numero:<%i> al cubo es:%ld",NUM,CUA);
    SUC += CUA;

    printf("\ningrese otro numero:",NUM);
    scanf("%i",&NUM);
    }
  printf("Suma de cuadrados es:%ld",SUC);
}
