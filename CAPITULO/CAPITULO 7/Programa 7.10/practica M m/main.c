#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>

int main() {
    char mayuscula, minuscula;

    // Solicita al usuario que ingrese una letra may�scula
    printf("Ingrese una letra may�scula: ");
    scanf("%c", &mayuscula);

    // Verifica que la letra ingresada est� en el rango de letras may�sculas (A-Z)
    if (mayuscula >= 'A' && mayuscula <= 'Z') {
        // Convierte la letra may�scula a min�scula sumando 32 (diferencia en el c�digo ASCII)
        minuscula = mayuscula + 32;
        printf("La letra min�scula correspondiente es: %c\n", minuscula);
    } else {
        printf("El car�cter ingresado no es una letra may�scula.\n");
    }

    return 0;
}

