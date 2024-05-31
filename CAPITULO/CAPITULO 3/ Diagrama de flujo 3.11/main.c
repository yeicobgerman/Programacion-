#include <stdio.h>
#include <stdlib.h>

int main()
{
    int R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;
    float CAL;

    printf("INSERTE un numero:",CAL);
    scanf("%f",&CAL);

    while (CAL != -1)
    {
        if ( CAL < 4 ){
            R1 += 1;
        }
            else if( CAL < 6){
                      R2+=1;
            }

            else if (CAL <8){
                     R3+=1;
            }

            else if (CAL < 9){
                      R4+=1;
            }
            else{
                R5+=1;
            }
             printf("Ingrese un numero:");
             scanf("%f", &CAL);
        }

    printf("resultado de:%d\n",R1);
    printf("resultado de:%d\n",R2);
    printf("resultado de:%d\n",R3);
    printf("resultado de:%d\n",R4);
    printf("resultado de:%d\n",R5);

    }



