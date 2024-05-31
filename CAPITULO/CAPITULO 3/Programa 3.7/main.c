#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I = 0, N = 0;
    float SLA = 0.0, LAN = 0.0;

    do{
        printf("Inserte un numero de lanzamiento:");
        scanf("%d",&N);

    }
    while(N<1 || N>10);

    for (I = 1; I <=N; I++){
        printf("Ingrese el lazanmiento:");
        scanf("%f",&LAN);
        SLA += LAN;

    }
    SLA /= N;
    printf("Resultado:%f",SLA);
}
