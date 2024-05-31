#include <stdio.h>
#include <stdlib.h>

int main()
{
    int I, MAT, MAMAT, MEMAT;
    float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 11.0;
    printf("ingrese la matricula del primer alumno:\t");
    scanf("%d",&MAT);
    while(MAT){
        SUM = 0;
        for ( I =1; I<=5; I++ )
        {
            printf("\tIngrese la calificacion del alumno:");
            scanf("%f",&CAL);
            SUM += CAL;

        }

        PRO = SUM / 5;
        printf("\nMatricula: %d\t Promedio:%5.2f", MAT, PRO);
        if (PRO> MAPRO)
        {
            MAPRO = PRO;
            MAMAT = MAT;
        }
        if (PRO < MEPRO){
            MEPRO = PRO;
            MEMAT = MAT;

        }
        printf("\nIngrese la matrica del siguiente alumno:");
        scanf("%d",&MAT);


    }
    printf("\nAlumno con mejor Promedio:\t%d\t%5.2f",MAMAT, MAPRO);
    printf("\nAlumno con PEOR Promedio:\t%d\t%5.2f",MEMAT, MAPRO);
}
