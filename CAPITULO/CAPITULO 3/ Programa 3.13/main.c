#include <stdio.h>
#include <stdlib.h>

int main()
{
   int PRI = 0, SEG = 1, SIG = 0;
   printf("seleccionaste el numero: %d %d\n", PRI, SEG);

   for(int I = 3; I <= 50; I++ ){
        SIG = PRI + SEG;
        PRI = SEG;
        SEG = SIG;
   printf("RESULT: %d\n", SIG);
   }
   printf("FIN");

}
