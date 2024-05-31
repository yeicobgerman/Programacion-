#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I = 0, N = 0, NUM = 0,  SPA = 0, SIM = 0, CIM = 0;

    printf("ingrese un numero:");
    scanf("%d",&N);

    if (N > 0){
        for(I = 1; I<= N; I++)

        printf("\nInserte un numero%d:", I);
        scanf("%d",&NUM);

    if (NUM != 0){
        if (pow(-1, NUM) > 0)
            SPA += NUM;
    }
    else {
            SIM += NUM;
    CIM += 1;

    }

    }
    else{
        printf("\nError en el valor de %d",N);
    }


}
