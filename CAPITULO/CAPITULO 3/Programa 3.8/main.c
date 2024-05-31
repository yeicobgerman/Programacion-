#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I = 0, NUM = 0;
    long FAC = 0;

    printf("ingrese un numero:");
    scanf("%d",&NUM);

    if(NUM >= 0){
        FAC = 1;
        for (I = 1; I <= NUM; I++){
            FAC *= I;
            printf("\nel factorial de %d es: %ld", NUM, FAC);
        }
        printf("\nresultado:%ld",FAC);

    }
    else {
    printf("\nError en el dato");
    }
}


