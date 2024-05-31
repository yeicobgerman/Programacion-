#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int NUM = 0;
    printf("inserte un numero:");
    scanf("%d",&NUM);

    if (NUM>0){
        printf("el numero es: %d\n", NUM);

        while (NUM != 1){

            if(pow (-1,NUM)>0)
                NUM /=2;

            else
                NUM = (NUM * 3) + 1;
                printf("RESULT:%d\n", NUM);
        }
    }

     else
        printf("NUM debe ser un entero positivo");



}
