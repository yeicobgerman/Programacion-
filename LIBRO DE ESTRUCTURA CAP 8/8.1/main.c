#include <stdio.h>
#include <stdlib.h>

typedef int Telemento;

typedef struct Registro {
    Telemento e;
    struct Registro* Sig;
} Nodo;

void VaciaL(Nodo **L) {
    *L = NULL;
}

int EsVaciaL(Nodo *L) {
    return (L == NULL);
}

void AnadePL(Nodo **L, Telemento e) {
    Nodo *Nuevo;
    Nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (Nuevo == NULL) {
        printf("Error en la asignación de memoria\n");
        return;
    }
    Nuevo->e = e;
    Nuevo->Sig = *L;
    *L = Nuevo;
}

void BorraPL(Nodo **L) {
    Nodo *Ptr;
    Ptr = *L;
    if (Ptr == NULL) {
        printf("Error en BorraPL\n");
        return;
    }
    *L = Ptr->Sig;
    free(Ptr);
}

Nodo *Resto(Nodo *L) {
    if (L == NULL) {
        printf("Error en Resto\n");
        return NULL;
    }
    return L->Sig;
}

void ModificaL(Nodo **L, Telemento e) {
    if (*L == NULL) {
        printf("Error en ModificaL\n");
        return;
    }
    (*L)->e = e;
}

Telemento PrimeroL(Nodo *L) {
    if (L == NULL) {
        printf("Error en PrimeroL\n");
        return 0;
    }
    return L->e;
}

int main() {

    Nodo *lista;
    VaciaL(&lista);

    AnadePL(&lista, 1);
    AnadePL(&lista, 2);
    AnadePL(&lista, 3);

    printf("Primero: %d\n", PrimeroL(lista));

    ModificaL(&lista, 10);
    printf("Primero modificado: %d\n", PrimeroL(lista));

    Nodo *resto = Resto(lista);
    printf("Resto primero: %d\n", PrimeroL(resto));

    BorraPL(&lista);
    printf("Después de borrar, primero: %d\n", PrimeroL(lista));

    return 0;
}
