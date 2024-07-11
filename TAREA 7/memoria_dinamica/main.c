#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char nombre[50];
    int edad;
} Alumno;


void grabarEnDisco();
Alumno * crearAlumno();
void liberarAlumno(Alumno * alumno);

int main() {
    grabarEnDisco();
    return 0;
}

void grabarEnDisco() {
    FILE * archivo;
    Alumno * alumno;
    char respuesta;


    archivo = fopen("alumnos.dat", "ab");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    do {

        alumno = crearAlumno();


        fwrite(alumno, sizeof(Alumno), 1, archivo);


        liberarAlumno(alumno);


        printf("¿Desea agregar otro registro? (s/n): ");
        scanf(" %c", &respuesta);
    } while (respuesta == 's' || respuesta == 'S');


    fclose(archivo);
}

Alumno * crearAlumno() {
    Alumno * alumno = (Alumno *) malloc(sizeof(Alumno));

    if (alumno == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese el nombre del alumno: ");
    scanf(" %[^\n]", alumno->nombre);

    printf("Ingrese la edad del alumno: ");
    scanf("%d", &alumno->edad);

    return alumno;
}

void liberarAlumno(Alumno * alumno) {
    free(alumno);
}
