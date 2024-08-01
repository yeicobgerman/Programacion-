#include <stdio.h>
#include <stdlib.h>
#define Mx 20

typedef int Telemento;

struct lista {
    Telemento el;
    struct lista *Sgte;
};

typedef struct lista Lista;

typedef struct {
    Lista *Comienzo, *Ultimo;
    int n;
} Tvector;

Lista* ReservaMemoria() {
    Lista *Puntero1, *Puntero2;
    int i;
    Puntero2 = (Lista*)malloc(sizeof(Lista));
    Puntero1 = Puntero2;
    for (i = 2; i <= Mx; i++) {
        Puntero1->Sgte = (Lista*)malloc(sizeof(Lista));
        Puntero1 = Puntero1->Sgte;
    }
    Puntero1->Sgte = NULL;
    return Puntero2;
}

void CreacionDelVector(Tvector *V) {
    V->Comienzo = ReservaMemoria();
    V->Ultimo = NULL;
    V->n = 0;
}

void AsignarUnElemento(Tvector *V, Telemento T) {
    if (V->Ultimo == NULL) {
        V->Comienzo->el = T;
        V->Ultimo = V->Comienzo;
    } else {
        if ((V->n % Mx) == 0 && (V->Ultimo->Sgte == NULL)) {
            V->Ultimo->Sgte = ReservaMemoria();
        }
        V->Ultimo = V->Ultimo->Sgte;
        V->Ultimo->el = T;
    }
    V->n++;
}

Lista* EncuentraDireccion(Tvector V, Telemento el) {
    Lista *Puntero1;
    int Encontrado = 0;
    Puntero1 = V.Comienzo;
    while (!Encontrado && Puntero1 != NULL) {
        Encontrado = Puntero1->el == el;
        if (!Encontrado)
            Puntero1 = Puntero1->Sgte;
    }
    return Puntero1;
}

Lista* BuscaAnterior(Tvector V, Lista *Puntero1) {
    Lista *Anterior = V.Comienzo;
    if (Anterior != Puntero1) {
        while (Anterior->Sgte != Puntero1)
            Anterior = Anterior->Sgte;
    }
    return Anterior;
}

void BorrarUnElemento(Tvector *V, Telemento T) {
    Lista *Puntero1, *Anterior, *Aux;
    Puntero1 = EncuentraDireccion(*V, T);
    if (Puntero1 != NULL) {
        Anterior = BuscaAnterior(*V, Puntero1);
        if (Puntero1 == V->Ultimo) {
            V->Ultimo = Anterior;
        } else {
            if (V->Comienzo == Puntero1) {
                V->Comienzo = V->Comienzo->Sgte;
            } else {
                Anterior->Sgte = Puntero1->Sgte;
            }
            Aux = V->Ultimo->Sgte;
            V->Ultimo->Sgte = Puntero1;
            Puntero1->Sgte = Aux;
        }
        V->n--;
    }
}

void ImprimirVector(Tvector V) {
    Lista *Puntero = V.Comienzo;
    while (Puntero != NULL && V.n > 0) {
        printf("%d -> ", Puntero->el);
        Puntero = Puntero->Sgte;
        V.n--;
    }
    printf("NULL\n");
}

int main() {
    Tvector vector;
    CreacionDelVector(&vector);

    // Asignar elementos al vector
    AsignarUnElemento(&vector, 10);
    AsignarUnElemento(&vector, 20);
    AsignarUnElemento(&vector, 30);

    printf("Vector después de asignar elementos:\n");
    ImprimirVector(vector);

    // Borrar un elemento del vector
    BorrarUnElemento(&vector, 20);

    printf("Vector después de borrar el elemento 20:\n");
    ImprimirVector(vector);

    return 0;
}

