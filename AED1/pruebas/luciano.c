/*Almacene en una matriz ingresando por teclado, la información de los importes correspondientes
a cada tipo de gasto (1-Alimentos 2-Salud 3-Movilidad 4-Edudación) en el primer semestre del
año (desde enero hasta junio inclusive).
o Cada fila representa un tipo de gasto realizado y cada columna representa cada mes del
semestre
- Recorra la matriz para generar un vector que registre el total acumulado del semestre por tipo de
gastos. Es decir, cada posición del vector representará un tipo de gasto y almacenará la suma de
los gastos realizados en el semestre.
- Incluya una función para visualizar los datos ingresados en la matriz, así como los valores
almacenados en el vector.
*/
#include <stdio.h>
#include <string.h>
#define MESES 3
#define TIPO 4

// Matriz
int matriz[3][4];

// Array
int v_total[4];

// Variable Glogal
int var_total = 0;

// Prototipos de Funciones
void ingresarDatos();
void calcularTotalTipo();
void calcularGastoTotal();
void imprimirResultados();

int main()
{
    ingresarDatos();
    calcularTotalTipo();
    calcularGastoTotal();
    imprimirResultados();
    return 0;
}

// Funciones
void ingresarDatos()
{
    for (int i = 0; i < TIPO; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            printf("Ingrese gasto del MES %d del TIPO %d \n", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}
void calcularTotalTipo()
{
    for (int i = 0; i < MESES; i++)
    {
        v_total[0] += matriz[0][i];
        v_total[1] += matriz[1][i];
        v_total[2] += matriz[2][i];
        v_total[3] += matriz[3][i];
    }
}
void calcularGastoTotal()
{
    for (int i = 0; i < TIPO; i++)
    {
        var_total += v_total[i];
    }
}
void imprimirResultados()
{
    printf("El de gastos del tipo 1 es %d \n", v_total[0]);
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("El de gastos del tipo 2 es %d \n", v_total[1]);
    printf("**************************\n");
    printf("El de gastos del tipo 3 es %d \n", v_total[2]);
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("El de gastos del tipo 4 es %d \n", v_total[0]);
    printf("_________________________\n");
    printf("EL TOTAL ES: %d \n", var_total);
    printf("_________________________");
}