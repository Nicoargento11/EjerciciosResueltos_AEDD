/* 2.1.Generar una matriz de Ventas de 6 filas por 12 columnas ingresando por teclado el importe vendido en
cada una de las sucursales (filas) en cada mes (columna) del año 2019. Se desea conocer el máximo monto
de venta y a qué sucursal corresponde. Informar los resultados pedidos.

2.2.Modifique el programa del punto anterior para generar un vector cuyos elementos sean la suma de ventas
mensuales de cada sucursal, a fin de obtener la venta anual. Mostrar en pantalla los datos de la matriz y
el vector de resultados. */

#include <stdio.h>

//--definidas por el usuario--//

typedef float m_importe;

//--variables--//

m_importe ventas[6][12];
m_importe ventasAnuales[6];

int i, j;
float mayorValor;
int sucursal, mes;
float sumatoria;

//--funciones--//

void ingresarDatos()
{

    for (i = 0; i < 6; i++)
    {

        for (j = 0; j < 12; j++)
        {
            printf("ingrese el monto en sucursal %d, mes %d\n", i + 1, j + 1);
            scanf("%f", &ventas[i][j]);
            fflush(stdin);
        }
    }
}

void buscarMayor()
{

    mayorValor = 0;

    for (i = 0; i < 6; i++)
    {

        for (j = 0; j < 12; j++)
        {

            if (ventas[i][j] > mayorValor)
            {
                mayorValor = ventas[i][j];
                sucursal = i;
                mes = j;
            }
        }
    }
}

void mostrarDatos()
{
    printf("------------------------------------------------------------------\n");
    printf("El mayor monto fue %.2f\n", mayorValor);
    printf("sucursal %d, mes %d\n", i, j);
    printf("------------------------------------------------------------------\n");
}

void calcularVentasAnuales()
{

    sumatoria = 0;

    for (i = 0; i < 6; i++)
    {

        for (j = 0; j < 12; j++)
        {

            sumatoria += ventas[i][j];
        }
        ventasAnuales[i] = sumatoria;
    }

    for (i = 0; i < 6; i++)
    {

        printf("las sumas mensuales de la sucursal %d fueron %.2f\n", i + 1, ventasAnuales[i]);
    }
}

//--algoritmo princiopal--//

int main()
{

    ingresarDatos();
    buscarMayor();
    mostrarDatos();
    calcularVentasAnuales();

    return 0;
}