#include <stdio.h>
#include <math.h>

int main()
{
    int TRA, EDA, DIA;
    float COS;
    printf("Ingrese tipo de tratamiento edad y dias:");
    scanf("%d %d %d", &TRA, &EDA, &DIA);

    switch(TRA)
    {
        case 1: COS = DIA * 2800; break;
        case 2: COS = DIA * 1950; break;
        case 3: COS = DIA * 2500; break;
        case 4: COS = DIA * 1150; break;

    }
    if (COS != -1){
    if (EDA <= 25 )
        COS = COS*0.85;
        else
            if (EDA <= 25)
            COS = COS * 0.85;
    printf("\n Clave tratamiento:%d\t: DIAS:%d\t  Costo total:%8.2f",TRA,DIA, COS);
    }
    else
        printf("\nClave del tratamiento  es incorrecto");
}
