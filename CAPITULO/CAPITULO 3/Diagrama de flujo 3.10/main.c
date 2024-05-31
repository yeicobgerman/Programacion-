#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N = 0, NUM = 0, SPA = 0, SIM = 0, CIM = 0, I = 0;

    printf("Inserte un numero:");
    scanf("%d",&N );

    if (N>0){

    for (I = 1; I <= N; I++){
            printf("ingrese otro numero:");
            scanf("%d",&NUM);
            if (NUM != 0){
                if (pow(-1, NUM)>0);
                 SPA += NUM;

            }
            else{
                 SIM += NUM;
                 CIM += 1;
            }



    }
    printf("\n La suma de los numeros es:%d",SPA);

    printf("\nEl promedio de numeros imparares es:%i",SIM/CIM);

    }
    else
     printf("ERROR");
}
