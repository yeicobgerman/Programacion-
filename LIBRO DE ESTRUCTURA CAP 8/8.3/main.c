
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int e;
    struct Nodo* Sig;
} Nodo;


int NumeroDeNodosDeLaLista(Nodo *L) {
    int k = 0;
    Nodo *p = L;
    while (p != NULL) {
        k++;
        p = p->Sig;
    }
    return k;
}


void EliminaPosicion(Nodo** L, int i) {
    int k = 0;
    Nodo *Ptr = *L, *Ant = NULL;

    while ((k < i) && (Ptr != NULL)) {
        k++;
        Ant = Ptr;
        Ptr = Ptr->Sig;
    }

    if (k == i && Ptr != NULL) {
        if (Ant == NULL) {
            *L = Ptr->Sig;
        } else {
            Ant->Sig = Ptr->Sig;
        }
        free(Ptr);
    }
}


void InsertarLista(Nodo* Ant, int e) {
    Nodo *Nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (Nuevo == NULL) {
        printf("Error de asignación de memoria\n");
        return;
    }
    Nuevo->e = e;
    Nuevo->Sig = Ant->Sig;
    Ant->Sig = Nuevo;
}


Nodo* BuscarEnLista(Nodo* L, int e) {
    Nodo *Ptr = L;
    while (Ptr != NULL) {
        if (Ptr->e == e) {
            return Ptr;
        }
        Ptr = Ptr->Sig;
    }
    return NULL;
}


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


void ImprimirLista(Nodo *L) {
    Nodo *p = L;
    while (p != NULL) {
        printf("%d -> ", p->e);
        p = p->Sig;
    }
    printf("NULL\n");
}

int main() {
    Nodo *L = NuevoNodo(1);
    L->Sig = NuevoNodo(2);
    L->Sig->Sig = NuevoNodo(3);

    printf("Lista original: ");
    ImprimirLista(L);

    printf("Número de nodos: %d\n", NumeroDeNodosDeLaLista(L));

    Nodo *nodo = BuscarEnLista(L, 2);
    if (nodo != NULL) {
        printf("Nodo encontrado con valor: %d\n", nodo->e);
    } else {
        printf("Nodo no encontrado\n");
    }

    EliminaPosicion(&L, 1);
    printf("Lista después de eliminar en la posición 1: ");
    ImprimirLista(L);

    InsertarLista(L, 4);
    printf("Lista después de insertar 4 después del primer nodo: ");
    ImprimirLista(L);

    return 0;
}
