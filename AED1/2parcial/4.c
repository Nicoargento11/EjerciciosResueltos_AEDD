#include <stdio.h>

/*

OBJETIVO: Una tienda online necesita llevar un registro mensual de sus ventas del primer trimestre.
Se requiere un programa Para determinar el mes y día con la mayor cantidad de
ventas y el mes y día con la menor cantidad de ventas.

ESTRATEGIA:
0- variables globales a utilizar:
    0.1 tipo definido para mostrar los meses
    0.2 matriz para almacenar las ventas realizadas
    0.3 vector para almacenar las ventas por meses
    0.4 vector para guardar el nombre de los meses

1- Funcion: Pedir el ingreso de datos
    1.1- Ingresar cantidad de ventas realizadas por dia

2- Funcion: Acumular el total de ventas por mes
3- Funcion: Determinar el dia y mes con mayor cantidad de ventas
    3.1 variables locales: dia,mes y mayor para mostrar por pantalla
4- Funcion: Determinar el dia y mes con menor cantidad de ventas
    4.1 variables locales: dia,mes y menor para mostrar por pantalla
5- Funcion: Visualizar todos los datos de la matriz
6- Imprimir resultados

*/
#define MESES 3
#define DIAS 5

typedef char string[25];
int totalVentas[MESES][DIAS];
int totalVentasMeses[MESES] = {0};
string nombreMeses[3] = {"Enero", "Febrero", "Marzo"};

void IngresarDatos()
{
    for (int i = 0; i < MESES; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            printf("Ingrese La cantidad de ventas del %d de %s: ", j + 1, nombreMeses[i]);
            scanf("%d", &totalVentas[i][j]);
            fflush(stdin);
        }
    }
}

void calcularVentasMeses()
{
    for (int i = 0; i < MESES; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            totalVentasMeses[i] += totalVentas[i][j];
        }
        printf("La cantidad de ventas en el mes de %s fue de %d\n", nombreMeses[i], totalVentasMeses[i]);
    }
}

void calcularMayorVentas()
{
    int mayor = 0;
    int dia, mes;
    for (int i = 0; i < MESES; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            if (mayor < totalVentas[i][j])
            {
                mayor = totalVentas[i][j];
                dia = j + 1;
                mes = i;
            }
        }
    }
    printf("El %d de %s con un total de %d ventas fue la mayor cantidad del trimestre\n", dia, nombreMeses[mes], mayor);
}

void calcularMenorVentas()
{
    int menor = totalVentas[0][0];
    int dia, mes;
    for (int i = 0; i < MESES; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            if (menor > totalVentas[i][j])
            {
                menor = totalVentas[i][j];
                dia = j + 1;
                mes = i;
            }
        }
    }
    printf("El %d de %s con un total de %d ventas fue la menor cantidad del trimestre\n", dia, nombreMeses[mes], menor);
}

void mostrarDatosDetallados()

{
    for (int i = 0; i < MESES; i++)
    {

        printf("%s", nombreMeses[i]);
        for (int j = 0; j < DIAS; j++)
        {
            printf("   %d   ", totalVentas[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    IngresarDatos();
    calcularVentasMeses();
    calcularMayorVentas();
    calcularMenorVentas();
    mostrarDatosDetallados();

    return 1;
}

/*
  |   CP                  DIAS            |
  |         |  1  |  2  |  3  |  4  |  5  | Calcular ventas meses | Calcular mayor ventas | Calcular menor ventas
M | ENERO   | 50    25    100   30    20  |           225                    100                     15
E | FEBRERO | 30    15    55    20    10  |           130
S | MARZO   | 25    60    70    75    90  |           320
*/
