#include <stdio.h>
#include <stdlib.h>

int main()
{
    float PAG = 0.0, SPA = 0.0;

    printf("Ingrese el pago:");
    scanf("%f",&PAG);

    while(PAG != 0){
        SPA += PAG;
    printf("Ingrese el pago:");
    scanf("%f",&PAG);
    }

    printf("El total de pagos del mes es: %f",SPA);

}
