#include <stdio.h>
#include <stdlib.h>

int main()
{
    float P,S,R;
    printf("\nIngrese las ventas de los tres vendedores:");
    scanf("%f %f %f", &P, &S , &R);

    if (P> S)
        if (P>R)
        if (S>R)
        printf("\n\nEl oden es P , S , R: %8.2f R: %8.2f R: %8.2f", P,S,R);
    else
    printf("\n\nEl oden es P , S , R: %8.2f R: %8.2f R: %8.2f", P,S,R);
    else
     printf("\n\nEl oden es P , S , R: %8.2f R: %8.2f R: %8.2f", P,S,R);
    else
        if (S>R)
        if (P>R)
        printf("\n\nEl orden es S,P y R: %8.2f %8.2f %8.2f",S, P, R);
    else
        printf("\n\nEl orden es S, R  P:  %8.2f  %8.2f  %8.2f", S, R , P );
    else
        printf("\n\nEl orden es R,S y P:  %8.2f  %8.2f  %8.2f", R,S,P);


}






