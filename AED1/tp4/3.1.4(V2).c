#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Declaración de variables Globales
const int CANT_NOTAS = 96;
// Declaración de Prototipos

// Función principal
int main()
{
    int nota, count, totalNotas = 0;
    float promedioNotas;
    srand(time(NULL));
    for (int i = 0; i < CANT_NOTAS; i++)
    {
        nota = rand() % 11;
        // printf("%d ", calificacion);

        if (nota >= 6)
        {
            totalNotas += nota;
            count++;
            printf("Nota del alumno %d: %d \n", i, nota);
        }
    }
    promedioNotas = (float)totalNotas / count;
    printf("\n la nota promedio de los %d alumnos aprobados es de %.2f", count, promedioNotas);

    return 0;
}

// declaración de funciones
