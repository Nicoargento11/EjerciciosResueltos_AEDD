#include <stdio.h>

#define TIPOS 4
#define MESES 3
/*
Ejercicio 3: Una persona necesita llevar un registro mensual de sus gastos. Se solicita desarrollar un
programa en lenguaje C para determinar el porcentaje que representan los gastos mensuales de
alimentación respecto de todos los gastos. Para ello:
- Almacene en una matriz ingresando por teclado, la información de los importes correspondientes
a cada tipo de gasto (1-Alimentos 2-Salud 3-Movilidad 4-Edudación) en el primer semestre del
año (desde enero hasta junio inclusive).
 Cada fila representa un tipo de gasto realizado y cada columna representa cada mes del semestre
- Recorra la matriz para generar un vector que registre el total acumulado del semestre por tipo de
gastos. Es decir, cada posición del vector representará un tipo de gasto y almacenará la suma de
los gastos realizados en el semestre.
- Incluya una función para visualizar los datos ingresados en la matriz, así como los valores
almacenados en el vector.
**Nota: para simplificar la prueba considere solo 3 meses y los 4 tipos de gastos.
*/
typedef char string[30];
int gastos[4][3];
int longitud = sizeof(gastos) / sizeof(gastos[0][0]);
string meses[3] = {"Enero", "Febrero", "Marzo"};
string tipos[4] = {"Alimentos", "Salud    ", "Movilidad", "Educacion"};

typedef enum tiposGastos
{
    ALIMENTOS,
    SALUD,
    MOVILIDAD,
    EDUCACION,
};


int totalGastos[4] = {0, 0, 0, 0};
float porcentajes[3];

void ingresarDatos();
void calcularGastos();
void mostrarDatosDetallados();
void calcularPorcentaje();
int main()
{
    ingresarDatos();
    calcularGastos();
    calcularPorcentaje();
    mostrarDatosDetallados();

    return 1;
}

void ingresarDatos()
{
    for (int i = 0; i < MESES; i++)
    {
        printf("Ingrese los gastos del mes de %s\n", meses[i]);
        printf("Ingrese el gasto de Alimentos: \n");
        scanf("%d", &gastos[ALIMENTOS][i]);
        fflush(stdin);
        printf("Ingrese el gasto de Salud: \n");
        scanf("%d", &gastos[SALUD][i]);
        fflush(stdin);
        printf("Ingrese el gasto de Movilidad: \n");
        scanf("%d", &gastos[MOVILIDAD][i]);
        fflush(stdin);
        printf("Ingrese el gasto de Educacion: \n");
        scanf("%d", &gastos[EDUCACION][i]);
        fflush(stdin);
    }
}
void calcularGastos()
{
    for (int i = 0; i < MESES; i++)
    {
        totalGastos[ALIMENTOS] += gastos[ALIMENTOS][i];
        totalGastos[SALUD] += gastos[SALUD][i];
        totalGastos[MOVILIDAD] += gastos[MOVILIDAD][i];
        totalGastos[EDUCACION] += gastos[EDUCACION][i];
    }

    for (int j = 0; j < TIPOS; j++)
    {
        printf("\nEl total de gastos totales es %d en %s\n", totalGastos[j], tipos[j]);
    }
}

void calcularPorcentaje()
{
    int gastoTotal = 0;
    int tipoGasto;
    float porcentajeTipoGasto = 0;
    int valorGasto;

    printf("\nsobre que tipo desea calcular el porcentaje: \n1-Alimentos\n2-Salud\n3-Movilidad\n4-Educacion\n");
    scanf("%d", &tipoGasto);
    for (int i = 0; i < MESES; i++)
    {
        gastoTotal += gastos[ALIMENTOS][i];
        gastoTotal += gastos[SALUD][i];
        gastoTotal += gastos[MOVILIDAD][i];
        gastoTotal += gastos[EDUCACION][i];

        valorGasto = gastos[tipoGasto - 1][i];
        porcentajeTipoGasto = (float)valorGasto / gastoTotal * 100;
        printf("El porcentaje que representa %s en %s es de: %.2f%%\n", tipos[tipoGasto - 1], meses[i], porcentajeTipoGasto);
    }
}
void mostrarDatosDetallados()
{
    printf("\n          %s  |   %s   |  %s\n", meses[0], meses[1], meses[2]);
    for (int i = 0; i < TIPOS; i++)
    {

        printf("%s", tipos[i]);
        for (int j = 0; j < MESES; j++)
        {
            printf("   %d      ", gastos[i][j]);
        }
        printf("\n");
    }
}