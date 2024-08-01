#include <stdio.h>
#include <stdlib.h>

// Definición del tipo de dato
typedef int Telemento;

// Definición de la estructura del nodo
typedef struct Nodo {
    Telemento e;
    struct Nodo* Sig;
} Nodo;

// Función para crear un nuevo nodo
Nodo* NuevoNodo(Telemento e) {
    Nodo* nn;
    nn = (Nodo*)malloc(sizeof(Nodo));
    if (nn == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);  // Asegurarse de manejar el error de asignación de memoria
    }
    nn->e = e;
    nn->Sig = NULL;
    return nn;
}

// Función para insertar un elemento de forma ordenada en la lista
void InsertarOrd(Nodo** L, Telemento e) {
    Nodo* Nuevo, * Ant, * Pos;
    Nuevo = NuevoNodo(e);
    if (*L == NULL) {
        *L = Nuevo;
    } else if (e <= (*L)->e) {
        Nuevo->Sig = *L;
        *L = Nuevo;
    } else {
        // La inserción se realiza no en la primera posición de la lista
        Ant = Pos = *L;
        while ((e > Pos->e) && (Pos->Sig != NULL)) {
            Ant = Pos;
            Pos = Pos->Sig;
        }
        if (e > Pos->e)
            Ant = Pos;
        Nuevo->Sig = Ant->Sig;
        Ant->Sig = Nuevo;
    }
}

// Función para borrar un elemento de la lista
void BorrarOrd(Nodo** L, Telemento e) {
    Nodo* Ant, * Pos;
    int Encontrado = 0;
    Ant = NULL;
    Pos = *L;
    while ((!Encontrado) && (Pos != NULL)) {
        Encontrado = (e <= (Pos->e));
        if (!Encontrado) {
            Ant = Pos;
            Pos = Pos->Sig;
        }
    }
    if (Encontrado) {
        // Se corta la búsqueda, hay que ver si está en la lista
        Encontrado = ((Pos->e) == e);
        if (Encontrado) {
            // Si es verdadero, hay que borrar
            if (Ant == NULL) {
                // Si el elemento a borrar es el primero
                *L = Pos->Sig;
            } else {
                Ant->Sig = Pos->Sig;
            }
            free(Pos);
        }
    }
}

// Función para contar el número de nodos en la lista
int NumeroDeNodosDeLaLista(Nodo* L) {
    int k = 0;
    Nodo* p;
    p = L;
    while (p != NULL) {
        k++;
        p = p->Sig;
    }
    return k;
}

// Función para eliminar el nodo en una posición específica
void EliminaPosicion(Nodo** L, int i) {
    int k = 0;
    Nodo* Ptr = *L;
    Nodo* Ant = NULL;
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

// Función para insertar un elemento en la lista conociendo el nodo anterior
void InsertarLista(Nodo* Ant, Telemento e) {
    Nodo* Nuevo;
    Nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (Nuevo == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);  // Asegurarse de manejar el error de asignación de memoria
    }
    Nuevo->e = e;
    Nuevo->Sig = Ant->Sig;
    Ant->Sig = Nuevo;
}

// Función para buscar un elemento en la lista
Nodo* BuscarEnLista(Nodo* L, Telemento e) {
    Nodo* Ptr;
    for (Ptr = L; Ptr != NULL; Ptr = Ptr->Sig) {
        if (Ptr->e == e) {
            return Ptr;
        }
    }
    return NULL;
}

// Programa principal para probar las funciones
int main() {
    Nodo* lista = NULL;
    Nodo* encontrado;
    int numNodos;

    // Insertar elementos en la lista
    InsertarOrd(&lista, 3);
    InsertarOrd(&lista, 1);
    InsertarOrd(&lista, 4);
    InsertarOrd(&lista, 2);

    // Contar el número de nodos
    numNodos = NumeroDeNodosDeLaLista(lista);
    printf("Numero de nodos: %d\n", numNodos);

    // Buscar un elemento en la lista
    encontrado = BuscarEnLista(lista, 2);
    if (encontrado != NULL) {
        printf("Elemento 2 encontrado en la lista.\n");
    } else {
        printf("Elemento 2 no encontrado en la lista.\n");
    }

    // Eliminar un elemento en una posición específica
    EliminaPosicion(&lista, 1);

    // Contar el número de nodos después de eliminar
    numNodos = NumeroDeNodosDeLaLista(lista);
    printf("Numero de nodos despues de eliminar la posicion 1: %d\n", numNodos);

    // Insertar un elemento conociendo el nodo anterior
    encontrado = BuscarEnLista(lista, 3);
    if (encontrado != NULL) {
        InsertarLista(encontrado, 5);
    }

    // Contar el número de nodos después de insertar
    numNodos = NumeroDeNodosDeLaLista(lista);
    printf("Numero de nodos despues de insertar 5 despues de 3: %d\n", numNodos);

    // Liberar memoria de la lista
    while (lista != NULL) {
        Nodo* temp = lista;
        lista = lista->Sig;
        free(temp);
    }

    return 0;
}



