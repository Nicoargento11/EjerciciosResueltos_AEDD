#include <stdio.h>
#include <string.h>

#include <stdlib.h>

/*
Ejercicio 2: Un centro educativo necesita registrar la información de 40 estudiantes. Se solicita
desarrollar un programa en lenguaje C que permita determinar el estudiante con el promedio
académico más alto y el estudiante con el promedio académico más bajo. Para ello:
- Almacene la información de cada estudiante en un array ingresando por teclado los siguientes
datos de cada estudiante: nombre (hasta 25 caracteres), apellido (hasta 25 caracteres), edad y
promedio académico.
o Para almacenar el nombre completo de los estudiantes se debe utilizar la función de cadena
adecuada que permite concatenar strings.
- Recorra el array para determinar el estudiante con el promedio más alto y el estudiante con
promedio más bajo (utilizar 2 funciones diferentes). Al momento de mostrar estos resultados por
pantalla, en cada caso, se debe mostrar el nombre del estudiante y su promedio académico
correspondiente.
**Nota: para simplificar la prueba considere solo 5 estudiantes.

*/

// ingresar nombre
// ingresar apellido
// ingresar edad
// ingresar promedio

// concatenar nombre y apellido
// calcular mayor promedio
// calcular menor promedio

// mostrar por pantalla
typedef char string[25];
typedef char stringNombre[50];

typedef struct
{
    string nombreCompleto;
    int edad;
    float promedio;
} datosEstudiantes;

typedef struct
{
    float promedio;
    int indice;
} datosPromedios;

datosPromedios prueba;
struct
{
    string nombre;
    string apellido;
} nombreCompleto;

datosPromedios mayorPromedio;
datosPromedios menorPromedio;
datosEstudiantes estudiantes[2];

int longitud = sizeof(estudiantes) / sizeof(estudiantes[0]);

stringNombre auxNombreCompleto;

datosPromedios funcionPrueba();
void ingresarDatos();
void concatenarCadenas();
void calcularMayorPromedio();
void calcularMenorPromedio();

int main()
{

    ingresarDatos();
    return 1;
}

void ingresarDatos()
{
    for (int i = 0; i < longitud; i++)
    {
        printf("Ingrese el nombre del estudiante: ");
        scanf("%s", &nombreCompleto.nombre);
        fflush(stdin);
        printf("Ingrese el apellido del estudiante: ");
        scanf("%s", &nombreCompleto.apellido);
        fflush(stdin);
        printf("Ingrese la edad del estudiante: \n");
        scanf("%s", &estudiantes[i].edad);
        fflush(stdin);
        printf("Ingrese el promedio del estudiante: \n");
        scanf("%f", &estudiantes[i].promedio);
        fflush(stdin);

        concatenarCadenas();
        strcpy(estudiantes[i].nombreCompleto, auxNombreCompleto);
        strcpy(auxNombreCompleto, "");
    }
    calcularMayorPromedio();
    calcularMenorPromedio();

    printf("\nindice: %d promedio: %.2f", funcionPrueba().indice, funcionPrueba().promedio);
}

void concatenarCadenas()
{
    strcat(auxNombreCompleto, nombreCompleto.nombre);
    strcat(auxNombreCompleto, " ");
    strcat(auxNombreCompleto, nombreCompleto.apellido);
}

void calcularMayorPromedio()
{
    mayorPromedio.promedio = 0;
    for (int i = 0; i < longitud; i++)
    {
        if (mayorPromedio.promedio < estudiantes[i].promedio)
        {
            mayorPromedio.promedio = estudiantes[i].promedio;
            mayorPromedio.indice = i;
        }
    }
    printf("el Nombre del alumno con mejor promedio es %s con un promedio de %.2f\n", estudiantes[mayorPromedio.indice], mayorPromedio.promedio);
};

void calcularMenorPromedio()
{
    menorPromedio.promedio = estudiantes[0].promedio;
    for (int i = 0; i < longitud; i++)
    {
        if (menorPromedio.promedio > estudiantes[i].promedio)
        {
            menorPromedio.promedio = estudiantes[i].promedio;
            menorPromedio.indice = i;
        }
    }
    printf("el Nombre del alumno con peor promedio es %s con un promedio de %.2f\n", estudiantes[menorPromedio.indice], menorPromedio.promedio);
};

datosPromedios funcionPrueba()
{
    prueba.indice = 1;
    prueba.promedio = 5;
    return prueba;
}