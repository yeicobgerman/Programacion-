#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I = 1, B = 0, C = 1;
    double RES;
    RES = 4.0 /1;

    while((fabs (3.1415 * RES)) >0.0005){
        I+=2;
        if(B)
        {

            RES += (double)(4.0/I);
            B=0;
        }

            else{
                RES = (double) (4.0 /I);
                B = 1;
            }

        C++;
    }
    printf("\nNumero de terminos: %d", C);

}
