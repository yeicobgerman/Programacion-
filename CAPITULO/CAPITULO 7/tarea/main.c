#include <stdio.h>
#include <ctype.h>

void main(void) {
    char str[100];
    int i, lower = 0, upper = 0, digits = 0;

    printf("Ingrese una cadena de caracteres: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (islower(str[i]))
            lower++;
        else if (isupper(str[i]))
            upper++;
        else if (isdigit(str[i]))
            digits++;
    }

    printf("\nN�mero de letras min�sculas: %d", lower);
    printf("\nN�mero de letras may�sculas: %d", upper);
    printf("\nN�mero de d�gitos: %d\n", digits);
}

