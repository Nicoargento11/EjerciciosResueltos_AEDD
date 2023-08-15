#include <stdio.h>

/*

OBJETIVO: Un sitio web necesita llevar un registro mensual de las visitas recibidas durante el primer
trimestre del año. Se requiere un programa en lenguaje C para determinar la cantidad de visitas
promedio del trimestre.

ESTRATEGIA:
0- variables globales a utilizar:
    0.1 tipo definido para mostrar los meses
    0.2 matriz para almacenar los espectadores
    0.3 vector para almacenar el promedio de espectadores por mes
    0.3 vector para almacenar el promedio de espectadores total
    0.4 vector para guardar el nombre de los meses

1- Funcion: Pedir el ingreso de datos
    1.1- Ingresar cantidad de espectadores por dia

2- Funcion: calcular  el promedio de espectadores por mes
3- Funcion: calcular  el promedio de espectadores del trimestre
4- Funcion: Visualizar todos los datos de la matriz
*/
#define MESES 3
#define DIAS 5

typedef char string[25];
int totalEspectadores[MESES][DIAS];
float totalEspectadoresMeses[MESES] = {0};
float totalEspectadoresTrimestre = 0;
string nombreMeses[3] = {"Abril", "Mayo", "Junio"};

void IngresarDatos()
{
    for (int i = 0; i < MESES; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            printf("Ingrese La cantidad de espectadores del %d de %s: ", j + 1, nombreMeses[i]);
            scanf("%d", &totalEspectadores[i][j]);
            fflush(stdin);
        }
    }
}

void calcularEspectadoresMeses()
{
    for (int i = 0; i < MESES; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            totalEspectadoresMeses[i] += totalEspectadores[i][j];
        }
        totalEspectadoresMeses[i] = (float)totalEspectadoresMeses[i] / DIAS;
        printf("La cantidad promedio de espectadores en el mes de %s fue de %.2f\n", nombreMeses[i], totalEspectadoresMeses[i]);
    }
}
void calcularEspectadoresTrimestre()
{
    for (int i = 0; i < MESES; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            totalEspectadoresTrimestre += totalEspectadores[i][j];
        }
    }
    totalEspectadoresTrimestre = (float)totalEspectadoresTrimestre / (MESES * DIAS);
    printf("La cantidad promedio de espectadores en el trimestre fue de %.2f\n", totalEspectadoresTrimestre);
}

void mostrarDatosDetallados()

{
    for (int i = 0; i < MESES; i++)
    {

        printf("%s", nombreMeses[i]);
        for (int j = 0; j < DIAS; j++)
        {
            printf("   %d   ", totalEspectadores[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    IngresarDatos();
    calcularEspectadoresMeses();
    calcularEspectadoresTrimestre();
    mostrarDatosDetallados();

    return 1;
}

/*
  |   CP                  DIAS            |
  |         |  1  |  2  |  3  |  4  |  5  | Calcular promedio espectadore meses | Calcular promedio espectadores trimestral |
M | ENERO   | 50    25    100   30    20  |           45                                            45
E | FEBRERO | 30    15    55    20    10  |           26
S | MARZO   | 25    60    70    75    90  |           64
*/
