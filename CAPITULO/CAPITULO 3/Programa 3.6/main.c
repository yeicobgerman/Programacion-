#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I = 0;
    float NOM = 0, PRO = 0, SAL = 0;

    printf("Inserte un salario:");
    scanf("%f", &SAL);

    do{
        NOM += SAL;
        I += 1;

        printf("Inserte el segundo salario:");
        scanf("%f",&SAL);
    }
    while(SAL != 0);
    PRO = NOM/I;

    printf("Nomina: %f \t Promedio de salarios: %f", NOM, PRO);

}
