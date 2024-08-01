#include <stdio.h>
#include <stdlib.h>

// Declaraci�n de un nodo de la lista enlazada
typedef struct Lista {
    char ch;
    struct Lista *Sig;
} Lista;

// Funci�n auxiliar para crear un nuevo nodo
Lista* NuevoNodo(char ch) {
    Lista *Nuevo = (Lista*)malloc(sizeof(Lista));
    if (Nuevo == NULL) {
        printf("Error de asignaci�n de memoria\n");
        return NULL;
    }
    Nuevo->ch = ch;
    Nuevo->Sig = NULL;
    return Nuevo;
}

// Funci�n para determinar si una lista es subcadena de otra
int EsSubcadenaDeCadena(Lista *Subcadena, Lista *Cadena) {
    Lista *Puntero1, *Puntero2;
    int Encontrado, Coincide;

    if (Cadena == NULL)
        return (Subcadena == NULL);
    else if (Subcadena == NULL)
        return 1;
    else {
        Encontrado = 0;
        while (Cadena != NULL && !Encontrado) {
            if (Cadena->ch != Subcadena->ch)
                Cadena = Cadena->Sig;
            else {
                // Intento de b�squeda de coincidencia
                Puntero1 = Cadena->Sig;
                Puntero2 = Subcadena->Sig;
                Coincide = 1;
                while (Puntero1 != NULL && Puntero2 != NULL && Coincide) {
                    if (Puntero1->ch == Puntero2->ch) {
                        Puntero1 = Puntero1->Sig;
                        Puntero2 = Puntero2->Sig;
                    } else {
                        Coincide = 0;
                    }
                }
                if (!Coincide)
                    Cadena = Cadena->Sig;
                else
                    Encontrado = (Puntero2 == NULL);
            }
        }
        return Encontrado;
    }
}

// Funci�n para imprimir una lista (�til para probar las funciones)
void ImprimirLista(Lista *L) {
    while (L != NULL) {
        printf("%c -> ", L->ch);
        L = L->Sig;
    }
    printf("NULL\n");
}

// Funci�n principal para probar la funci�n EsSubcadenaDeCadena
int main() {
    // Crear la lista para la cadena principal
    Lista *Cadena = NuevoNodo('a');
    Cadena->Sig = NuevoNodo('b');
    Cadena->Sig->Sig = NuevoNodo('c');
    Cadena->Sig->Sig->Sig = NuevoNodo('d');

    // Crear la lista para la subcadena
    Lista *Subcadena = NuevoNodo('b');
    Subcadena->Sig = NuevoNodo('c');

    printf("Cadena: ");
    ImprimirLista(Cadena);

    printf("Subcadena: ");
    ImprimirLista(Subcadena);

    if (EsSubcadenaDeCadena(Subcadena, Cadena)) {
        printf("La subcadena es una subcadena de la cadena principal.\n");
    } else {
        printf("La subcadena NO es una subcadena de la cadena principal.\n");
    }

    return 0;
}

