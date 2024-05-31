#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I = 0;
    float NOM = 0, SAL = 0;

    for (I = 1; I <= 15; I++){
    printf("Ingrese el salario:");
    scanf("%f",&SAL);

    NOM += SAL;

    }
    printf("\n el total de la nominina es:%f",NOM);
}
