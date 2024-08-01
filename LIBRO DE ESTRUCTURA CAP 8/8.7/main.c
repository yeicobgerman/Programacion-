#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int Exponente;
    float Coeficiente;
} Telemento;

typedef struct polinomio {
    Telemento el;
    struct polinomio *Sig;
} Polinomio;

Polinomio* NuevoNodo(Telemento el) {
    Polinomio *NodoNuevo = (Polinomio*)malloc(sizeof(Polinomio));
    if (NodoNuevo == NULL) {
        printf("Error de asignación de memoria\n");
        return NULL;
    }
    NodoNuevo->el = el;
    NodoNuevo->Sig = NULL;
    return NodoNuevo;
}

void AgregaTermino(Telemento el, Polinomio **Primero, Polinomio **Ultimo) {
    Polinomio *Aux = NuevoNodo(el);
    if (*Ultimo == NULL) {
        *Primero = Aux;
    } else {
        (*Ultimo)->Sig = Aux;
    }
    *Ultimo = Aux;
}

void SumaPolinomios(Polinomio *p, Polinomio *q, Polinomio **Suma) {
    float c;
    Telemento e;
    Polinomio *Primero = NULL, *Ultimo = NULL;

    while (p != NULL && q != NULL) {
        if (p->el.Exponente == q->el.Exponente) {
            c = p->el.Coeficiente + q->el.Coeficiente;
            if (fabs(c) > 0.00001) {
                e.Coeficiente = c;
                e.Exponente = p->el.Exponente;
                AgregaTermino(e, &Primero, &Ultimo);
            }
            p = p->Sig;
            q = q->Sig;
        } else if (p->el.Exponente > q->el.Exponente) {
            AgregaTermino(p->el, &Primero, &Ultimo);
            p = p->Sig;
        } else {
            AgregaTermino(q->el, &Primero, &Ultimo);
            q = q->Sig;
        }
    }

    while (p != NULL) {
        AgregaTermino(p->el, &Primero, &Ultimo);
        p = p->Sig;
    }

    while (q != NULL) {
        AgregaTermino(q->el, &Primero, &Ultimo);
        q = q->Sig;
    }

    *Suma = Primero;
}

void CambiaDeSigno(Polinomio *q) {
    Polinomio *Aux = q;
    while (Aux != NULL) {
        Aux->el.Coeficiente = -Aux->el.Coeficiente;
        Aux = Aux->Sig;
    }
}

void RestaPolinomios(Polinomio *p, Polinomio *q, Polinomio **Resta) {
    CambiaDeSigno(q);
    SumaPolinomios(p, q, Resta);
    CambiaDeSigno(q);
}

void MultiplicaPorMonomio(Polinomio *p, Polinomio *Monomio, Polinomio **Pro) {
    Telemento x, y, z;
    Polinomio *Aux = p, *Primero = NULL, *Ultimo = NULL;
    y = Monomio->el;

    while (Aux != NULL) {
        x = Aux->el;
        z.Exponente = x.Exponente + y.Exponente;
        z.Coeficiente = x.Coeficiente * y.Coeficiente;
        AgregaTermino(z, &Primero, &Ultimo);
        Aux = Aux->Sig;
    }

    *Pro = Primero;
}

void MultiplicaPolinomios(Polinomio *p, Polinomio *q, Polinomio **Producto) {
    Polinomio *Aux1 = q, *ProductoAuxiliar = NULL, *Temp = NULL;
    *Producto = NULL;

    while (Aux1 != NULL) {
        MultiplicaPorMonomio(p, Aux1, &ProductoAuxiliar);
        SumaPolinomios(*Producto, ProductoAuxiliar, &Temp);
        *Producto = Temp;
        Aux1 = Aux1->Sig;
    }
}

void DividePolinomios(Polinomio *p, Polinomio *q, Polinomio **Cociente, Polinomio **Resto) {
    Polinomio *Dividendo = p, *Divisor = q, *Primero = NULL, *Ultimo = NULL;
    Telemento x, y, z;

    if (Divisor == NULL) {
        printf("Error: División por cero.\n");
        return;
    }

    y = Divisor->el;

    while (Dividendo != NULL && Dividendo->el.Exponente >= Divisor->el.Exponente) {
        x = Dividendo->el;
        z.Exponente = x.Exponente - y.Exponente;
        z.Coeficiente = x.Coeficiente / y.Coeficiente;
        Polinomio *Multiplicando = NuevoNodo(z);
        Polinomio *Suma = NULL;
        MultiplicaPolinomios(Divisor, Multiplicando, &Suma);
        AgregaTermino(z, &Primero, &Ultimo);
        RestaPolinomios(Dividendo, Suma, &Dividendo);
    }

    *Cociente = Primero;
    *Resto = Dividendo;
}

float Valor(Polinomio *p, float x) {
    float Suma = 0;
    while (p != NULL) {
        Suma += p->el.Coeficiente * pow(x, p->el.Exponente);
        p = p->Sig;
    }
    return Suma;
}

void Deriva(Polinomio **p) {
    Polinomio *Aux = *p, *Anterior = NULL;
    while (Aux != NULL) {
        if (Aux->el.Exponente == 0) {
            if (Anterior == NULL) {
                *p = Aux->Sig;
                free(Aux);
                Aux = *p;
            } else {
                Anterior->Sig = Aux->Sig;
                free(Aux);
                Aux = Anterior->Sig;
            }
        } else {
            Aux->el.Coeficiente *= Aux->el.Exponente;
            Aux->el.Exponente--;
            Anterior = Aux;
            Aux = Aux->Sig;
        }
    }
}

void InsertarOrden(Polinomio **L, Telemento e) {
    Polinomio *Nuevo = NuevoNodo(e);
    if (*L == NULL || (*L)->el.Exponente < e.Exponente) {
        Nuevo->Sig = *L;
        *L = Nuevo;
    } else {
        Polinomio *Aux = *L;
        while (Aux->Sig != NULL && Aux->Sig->el.Exponente > e.Exponente) {
            Aux = Aux->Sig;
        }
        Nuevo->Sig = Aux->Sig;
        Aux->Sig = Nuevo;
    }
}

void LeePolinomio(Polinomio **p) {
    Telemento x;
    *p = NULL;
    printf("Ingrese términos del polinomio (coeficiente exponente), termine con exponente negativo:\n");
    while (1) {
        scanf("%f %d", &x.Coeficiente, &x.Exponente);
        if (x.Exponente < 0) break;
        InsertarOrden(p, x);
    }
}


void ImprimirPolinomio(Polinomio *p) {
    while (p != NULL) {
        printf("%.2fx^%d", p->el.Coeficiente, p->el.Exponente);
        if (p->Sig != NULL) printf(" + ");
        p = p->Sig;
    }
    printf("\n");
}

int main() {

    Polinomio *p = NULL, *UltimoP = NULL;
    AgregaTermino((Telemento){2, 3}, &p, &UltimoP);
    AgregaTermino((Telemento){1, 2}, &p, &UltimoP);
    AgregaTermino((Telemento){0, 1}, &p, &UltimoP);


    Polinomio *q = NULL, *UltimoQ = NULL;
    AgregaTermino((Telemento){2, 1}, &q, &UltimoQ);
    AgregaTermino((Telemento){0, 4}, &q, &UltimoQ);

    printf("Polinomio p: ");
    ImprimirPolinomio(p);
    printf("Polinomio q: ");
    ImprimirPolinomio(q);


    Polinomio *Suma = NULL;
    SumaPolinomios(p, q, &Suma);
    printf("Suma de p y q: ");
    ImprimirPolinomio(Suma);


    Polinomio *Resta = NULL;
    RestaPolinomios(p, q, &Resta);
    printf("Resta de p y q: ");
    ImprimirPolinomio(Resta);

    Polinomio *Producto = NULL;
    MultiplicaPolinomios(p, q, &Producto);
    printf("Producto de p y q: ");
    ImprimirPolinomio(Producto);


    Polinomio *Cociente = NULL, *Resto = NULL;
    DividePolinomios(p, q, &Cociente, &Resto);
    printf("Cociente de p dividido por q: ");
    ImprimirPolinomio(Cociente);
    printf("Resto de p dividido por q: ");
    ImprimirPolinomio(Resto);


    float valor = Valor(p, 2);
    printf("Valor de p en x = 2: %.2f\n", valor);


    Deriva(&p);
    printf("Derivada de p: ");
    ImprimirPolinomio(p);


    Polinomio *nuevoPolinomio = NULL;
    LeePolinomio(&nuevoPolinomio);
    printf("Polinomio leído: ");
    ImprimirPolinomio(nuevoPolinomio);

    return 0;
}
