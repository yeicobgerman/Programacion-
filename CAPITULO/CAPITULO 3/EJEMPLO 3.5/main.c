#include <stdio.h>
#include <stdlib.h>

int main()
{
    float SPA = 0, PAG = 0;

    printf("Ingrese un numero:");
    scanf("%f",&PAG);

    do{
        SPA += PAG;
        printf("Ingrese otro numero:");
        scanf("%f",&PAG);

    }
    while (PAG != 0);
    printf("total de pagos del mes:%f",SPA);
}
