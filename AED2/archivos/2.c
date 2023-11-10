#include <stdio.h>
#include <stdlib.h>
FILE *archivoTexto;

typedef char string[30];
typedef struct
{
    int dni;
    string nombre;
} tDatosAlumno;

tDatosAlumno alummno;
int count = 1;

void ingresarDatos()
{
    printf("ingrese su nombre: \n");
    scanf("%[^\n]s", &alummno.nombre);
    printf("ingrese su dni: \n");
    scanf("%d", &alummno.dni);
    fflush(stdin);
}
void agregarAlumno()
{
    fprintf(archivoTexto, "%s %d\n", alummno.nombre, alummno.dni);
}
void mostrarDetallesAlumnos()
{
    archivoTexto = fopen("datosAlumnos.txt", "r");
    fscanf(archivoTexto, "%s %d", &alummno.nombre, &alummno.dni);

    while (!feof(archivoTexto))
    {
        printf("%s %d\n", alummno.nombre, alummno.dni);
        fscanf(archivoTexto, "%s %d", &alummno.nombre, &alummno.dni);
        count++;
    }
}
int main()
{
    char finalizar = 0;
    archivoTexto = fopen("datosAlumnos.txt", "a");
    // if (archivoTexto == NULL)
    // {
    //     archivoTexto = fopen("datosAlumnos.txt", "w");
    // }
    while (finalizar != 'n')
    {
        ingresarDatos();
        agregarAlumno();
        printf("\ndesea seguir agregando alumnos? (s/n) ");
        scanf("%c", &finalizar);
        fflush(stdin);
        /* code */
    }
    fclose(archivoTexto);
    mostrarDetallesAlumnos();
    fclose(archivoTexto);
    printf("cantidad de alumnos: %d", count);
}