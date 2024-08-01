#include <stdio.h>
#include <stdlib.h>

struct lista {
    int x;
    struct lista *Sig;
};

typedef struct lista Lista;

void imprimirLista(Lista *L) {
    while (L != NULL) {
        printf("%d -> ", L->x);
        L = L->Sig;
    }
    printf("NULL\n");
}

void ordena(Lista **L, int n) {
    if (*L == NULL || (*L)->Sig == NULL) return; // Lista vacía o con un solo elemento

    for (int i = 0; i < n - 1; i++) {
        Lista **ptr = L;
        for (int j = 0; j < n - i - 1; j++) {
            Lista *a = *ptr;
            Lista *b = a->Sig;
            if (a->x > b->x) {
                a->Sig = b->Sig;
                b->Sig = a;
                *ptr = b;
            }
            ptr = &((*ptr)->Sig);
        }
    }
}

// Función para agregar un nuevo nodo al final de la lista
void agregarNodo(Lista **L, int valor) {
    Lista *nuevoNodo = (Lista*)malloc(sizeof(Lista));
    nuevoNodo->x = valor;
    nuevoNodo->Sig = NULL;

    if (*L == NULL) {
        *L = nuevoNodo;
    } else {
        Lista *temp = *L;
        while (temp->Sig != NULL) {
            temp = temp->Sig;
        }
        temp->Sig = nuevoNodo;
    }
}

// Función principal para probar la ordenación de la lista
int main() {
    Lista *lista = NULL;

    // Agregar elementos a la lista
    agregarNodo(&lista, 4);
    agregarNodo(&lista, 2);
    agregarNodo(&lista, 5);
    agregarNodo(&lista, 3);
    agregarNodo(&lista, 1);

    printf("Lista original: ");
    imprimirLista(lista);

    // Ordenar la lista
    ordena(&lista, 5);

    printf("Lista ordenada: ");
    imprimirLista(lista);

    // Liberar memoria
    while (lista != NULL) {
        Lista *temp = lista;
        lista = lista->Sig;
        free(temp);
    }

    return 0;
}
