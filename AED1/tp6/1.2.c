#include <stdio.h>
#include <string.h>

void ingresoNotas(int, int[]);
float calcularNotaAprobados(int, int[], int *);
float calcularPorcentaje(int, int);
void informarPromedio(float, float);
void mostrarNotas(int, int[]);

int main()
{
    int estudiantes[10];
    int totalAprobados = 0;
    int cantEstudiantes = 10;
    ingresoNotas(cantEstudiantes, estudiantes);
    int notaAprobados = calcularNotaAprobados(cantEstudiantes, estudiantes, &totalAprobados);
    int porcentaje = calcularPorcentaje(cantEstudiantes, totalAprobados);
    informarPromedio(porcentaje, notaAprobados);
    mostrarNotas(cantEstudiantes, estudiantes);

    return 1;
}

void ingresoNotas(int c_cantEstudiantes, int c_estudiantes[])
{
    for (int i = 0; i < c_cantEstudiantes; i++)
    {
        printf("Ingrese la nota de los estudiantes: ");
        scanf("%d", &c_estudiantes[i]);
        fflush(stdin);
    }
}

float calcularNotaAprobados(int c_cantEstudiantes, int c_estudiantes[], int *totalAprobados)
{
    float notaAprobados = 0;

    for (int i = 0; i < c_cantEstudiantes; i++)
    {
        if (c_estudiantes[i] >= 6)
        {
            notaAprobados += c_estudiantes[i];
            (*totalAprobados)++;
        }
    }
    notaAprobados = (float)notaAprobados / *totalAprobados;
    return notaAprobados;
}

float calcularPorcentaje(int c_cantEstudiantes, int c_totalAprobados)
{
    float porcentaje = ((float)c_totalAprobados / c_cantEstudiantes) * 100;
    return porcentaje;
}

void informarPromedio(float c_porcentaje, float c_notaAprobados)
{
    printf("La nota promedio de los que aprobaron es de %.2f\n", c_notaAprobados);
    printf("El porcentaje que representa es de %.2f%%\n", c_porcentaje);
}

void mostrarNotas(int c_cantEstudiantes, int c_estudiantes[])
{
    for (int i = 0; i < c_cantEstudiantes; i++)
    {
        if (c_estudiantes[i] >= 6)
        {
            printf("La nota del estudiante %d es: %d\n", i, c_estudiantes[i]);
        }
    }
}
