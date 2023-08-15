/* ESTRATEGIA:
1 CREAR UNA MATRIZ (6 FILAS Y 12 COLUMNAS)
2 INGRESAR LOS DATOS
3 CALCULAR MAXIMO MONTO Y SUCURSAL
4 IMPRIMIR RESULTADOS
*/
#include <stdio.h>
#define SUCURSALES 2
#define MESES 3

// Decalración de Matriz
int matriz[SUCURSALES][MESES];

// Tipo de Dato Personalizado
typedef int tEntero;

// Variables Globales
tEntero sucursales[SUCURSALES];
tEntero montoAnual[SUCURSALES] = {0, 0};
tEntero monto_maximo = 0;
tEntero sucursal = 0;

// Prototipo de Funciones
void ingresarDatos();
void calcularMontoSucursal();
void calcularMontoMayor();
void imprimirResultados();

int main()
{
    ingresarDatos();
    calcularMontoSucursal();
    calcularMontoMayor();
    imprimirResultados();
    return 0;
}

// Funciones
void ingresarDatos()
{
    for (int i = 0; i < SUCURSALES; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            printf("Ingresar un valor para la sucursal %d en el mes %d\n", i + 1, j + 1);
            fflush(stdin);
            scanf("%d", &matriz[i][j]);
        }
    }
}
void calcularMontoSucursal()
{
    int i, j;
    for (i = 0; i < SUCURSALES; i++)
    {
        for (j = 0; j < MESES; j++)
        {
            if (matriz[i][j] > sucursales[i])
            {
                sucursales[i] = matriz[i][j];
            }

            montoAnual[i] += matriz[i][j];
        }
        printf("El valor mayor de la sucursal %d es %d \n", i + 1, sucursales[i]);
        printf("El valor anual de la sucursal %d es %d\n\n", i + 1, montoAnual[i]);
    }
}
void calcularMontoMayor()
{
    // Crear el vector y almacenar los valores
    for (int i = 0; i < 6; i++)
    {
        if (sucursales[i] > monto_maximo)
        {
            monto_maximo = sucursales[i];
            sucursal = i + 1;
        }
    }
}
void imprimirResultados()
{
    printf("El monto maximo total es %d \n", monto_maximo);
    printf("Se realizo en la sucursal %d", sucursal);
}