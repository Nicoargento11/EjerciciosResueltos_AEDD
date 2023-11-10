#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long int dni;
    short int codigo;
    char genero;
    short int edad;
} tDatoAlumno;

typedef struct
{
    short int cantInscriptos;
    float porcentaje;
} tListado;

tDatoAlumno alumno;

FILE *Archivo;

int cantLSI, cantTotal = 0;
float porcentajeLsi = 0;

void ingresarDatos()
{
    printf("ingrese su DNI: \n");
    scanf("%d", &alumno.dni);

    printf("ingrese su codigo de carrera \n");
    printf("(18-Lic. en Sistemas de Información (LSI), 19-Lic. en Cs. Biológicas, 20-Agrimensura, 28-Bioquímica, 29-Ing. Electronica)\n");
    scanf("%d", &alumno.codigo);
    fflush(stdin);

    printf("Ingrese su genero \n");
    printf("(m-mujer,v-varón, x-otro)");
    scanf("%c", &alumno.genero);
    fflush(stdin);

    printf("ingrese su edad: \n");
    scanf("%d", &alumno.edad);
    fflush(stdin);
}

void agregarAlumno()
{
    fwrite(&alumno, sizeof(tDatoAlumno), 1, Archivo);
}

void listadoLSI()
{
    cantTotal++;

    if (alumno.codigo == 18)
    {
        cantLSI++;
    }
}
void mostrarDetallesAlumnos()
{
    Archivo = fopen("datosAlumnos.dat", "rb");
    fread(&alumno, sizeof(tDatoAlumno), 1, Archivo);

    while (!feof(Archivo))
    {
        listadoLSI();
        printf("%d %d %c %d\n", alumno.dni, alumno.codigo, alumno.genero, alumno.edad);
        fread(&alumno, sizeof(tDatoAlumno), 1, Archivo);
    }
    porcentajeLsi = (float)cantLSI / cantTotal * 100;
    printf("La cantidad de alumnos de LSI es de %d con un porcentaje de %.2f sobre el total", cantLSI, porcentajeLsi);
}

int main()
{
    char finalizar = 0;

    Archivo = fopen("datosAlumnos.dat", "ab");
    if (Archivo == NULL)
    {
        Archivo = fopen("datosAlumnos.dat", "wb");
    }

    while (finalizar != 'n')
    {
        ingresarDatos();
        agregarAlumno();
        printf("\ndesea seguir agregando alumnos? (s/n) ");
        scanf("%c", &finalizar);
        fflush(stdin);
        /* code */
    }
    fclose(Archivo);
    mostrarDetallesAlumnos();
    listadoLSI();
    fclose(Archivo);
}