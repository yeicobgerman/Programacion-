#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo {
    int e;
    struct Nodo* Sig;
} Nodo;


Nodo* NuevoNodo(int e) {
    Nodo *Nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (Nuevo == NULL) {
        printf("Error de asignación de memoria\n");
        return NULL;
    }
    Nuevo->e = e;
    Nuevo->Sig = NULL;
    return Nuevo;
}


void MezclarListasOrdenadas(Nodo *L1, Nodo *L2, Nodo **L3) {
    Nodo *Puntero1 = L1, *Puntero2 = L2;
    Nodo *Primero = NuevoNodo(-32767);
    Nodo *Ultimo = Primero;

    if (Primero == NULL) {
        *L3 = NULL;
        return;
    }

    while (Puntero1 && Puntero2) {
        if (Puntero1->e < Puntero2->e) {
            Ultimo->Sig = NuevoNodo(Puntero1->e);
            Puntero1 = Puntero1->Sig;
        } else {
            Ultimo->Sig = NuevoNodo(Puntero2->e);
            Puntero2 = Puntero2->Sig;
        }
        Ultimo = Ultimo->Sig;
    }

    while (Puntero1) {
        Ultimo->Sig = NuevoNodo(Puntero1->e);
        Ultimo = Ultimo->Sig;
        Puntero1 = Puntero1->Sig;
    }

    while (Puntero2) {
        Ultimo->Sig = NuevoNodo(Puntero2->e);
        Ultimo = Ultimo->Sig;
        Puntero2 = Puntero2->Sig;
    }

    *L3 = Primero->Sig;
    free(Primero);
}


void ImprimirLista(Nodo *L) {
    Nodo *p = L;
    while (p != NULL) {
        printf("%d -> ", p->e);
        p = p->Sig;
    }
    printf("NULL\n");
}


int main() {
    Nodo *L1 = NuevoNodo(1);
    L1->Sig = NuevoNodo(3);
    L1->Sig->Sig = NuevoNodo(5);

    Nodo *L2 = NuevoNodo(2);
    L2->Sig = NuevoNodo(4);
    L2->Sig->Sig = NuevoNodo(6);

    printf("Lista L1: ");
    ImprimirLista(L1);

    printf("Lista L2: ");
    ImprimirLista(L2);

    Nodo *L3 = NULL;
    MezclarListasOrdenadas(L1, L2, &L3);

    printf("Lista mezclada L3: ");
    ImprimirLista(L3);

    return 0;
}


