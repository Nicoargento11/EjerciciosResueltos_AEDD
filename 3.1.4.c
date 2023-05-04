#include <stdio.h>
// Declaración de variables Globales
int cantNotas = 10;

// Declaración de Prototipos

// Función principal
int main()
{

    float nota;
    int count;
    float totalNotas;
    for (int i = 0; i < cantNotas; i++)
    {
        printf("ingresa la nota: \n");
        scanf("%f", &nota);
        if (nota >= 6)
        {
            count++;
            totalNotas = totalNotas + nota;
        }
    }
    printf("la nota promedio de los %d alumnos aprobados es de %.2f", count, totalNotas / count);

    return 1;
}

// declaración de funciones
