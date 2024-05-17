#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x = 0.0;
    float b = 0.0;
    int cnt = 0;
    printf ("\nPragrama calculo Raiz cuadrada\n");

    printf ("ingrese un numero:");
    scanf ("%f",&x);
    b = x;

    while(!(b==(x/b)))
    {
      b = 0.5 * ((x/b)+b);
      printf ("Raiz cuadrada de %f = %f\n",x,b);
       cnt++;
      if (cnt > 10)
        break;
    }
    printf ("el resultado es: %f = %f",x,b);

}


