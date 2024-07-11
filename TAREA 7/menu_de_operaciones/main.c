#include <stdio.h>
#include <stdlib.h>

void leerDesdeDisco();
void grabarEnDisco();
void salir();

int main() {
    int opcion;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Leer desde disco\n");
        printf("2. Grabar en disco\n");
        printf("3. Salir\n");
        printf("Ingrese la opcion: ");
        scanf("%d", &opcion);


        switch (opcion) {
            case 1:
                leerDesdeDisco();
                break;
            case 2:
                grabarEnDisco();
                break;
            case 3:
                salir();
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}

void leerDesdeDisco() {

    printf("Funcion para leer desde disco.\n");
}

void grabarEnDisco() {

    printf("Funcion para grabar en disco.\n");
}

void salir() {
    printf("Saliendo del programa.\n");

    exit(0);
}
