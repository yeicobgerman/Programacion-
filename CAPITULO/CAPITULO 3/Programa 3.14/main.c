#include <stdio.h>
#include <stdlib.h>

int main()

{
    int C1 = 0,C2 = 0,C3 = 0,C4 = 0,C5 = 0, NU = 0, VOT, SVO;
    float P01, P02,P03,P04,P05,P0N;
    printf("INSERTE UN NUMERO:");
    scanf("%d",&VOT);

    while (VOT != 0){
        switch(VOT){

        case 1: C1++; break;
        case 2: C2++; break;
        case 3: C3++; break;
        case 4: C4++; break;
        case 5: C5++; break;
          default:NU++; break;
        }
         printf("INSERTE UN NUMERO:");
         scanf("%d",&VOT);

    }
    SVO =(C1 + C2 + C3 + C4 + C5 + NU);
    P01 = (C1/SVO)*100;
    P02 = (C2/SVO)*100;
    P03 = (C3/SVO)*100;
    P04 = (C4/SVO)*100;
    P05 = (C5/SVO)*100;
    P0N = (NU/SVO)*100;

    printf("\nRESULT: %d %d %d %d %d %d",C1, P01, C2, P02, C3, P03);
    printf("\nRESULT: %d %d %d %d %d %d",C4, P04, C5, P05, NU, P0N);
}
