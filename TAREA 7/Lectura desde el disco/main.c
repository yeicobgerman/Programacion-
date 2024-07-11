#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nombre[50];
    int edad;
} Alumno;


void leerDesdeDisco();
void mostrarAlumno(Alumno alumno);

int main() {
    leerDesdeDisco();
    return 0;
}

void leerDesdeDisco() {
    FILE * archivo;
    Alumno alumno;


    archivo = fopen("alumnos.dat", "rb");

    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }


    while (fread(&alumno, sizeof(Alumno), 1, archivo) == 1) {
        mostrarAlumno(alumno);
    }


    fclose(archivo);
}

void mostrarAlumno(Alumno alumno) {
    printf("Nombre: %s\n", alumno.nombre);
    printf("Edad: %d\n", alumno.edad);
    printf("\n");
}

