#include <stdio.h>
#define FILAS 5
#define COLUMNAS 4
typedef int tMatriz[FILAS][COLUMNAS];
typedef struct
{
    int valor;
    int indiceFila;
    int indiceColumna;
} tdatosValor;

tMatriz matriz = {{10, 24, 61, 8},
                  {10, 12, 14, 16},
                  {30, 40, 50, 60},
                  {312, 52, 27, 29},
                  {21, 22, 23, 24}};

tdatosValor maximoValor(tMatriz);
tdatosValor minimoValor(tMatriz);

int main()
{
    printf("Fila:%d Columna:%d maximo: %d\n", minimoValor(matriz).indiceFila + 1, minimoValor(matriz).indiceColumna + 1, minimoValor(matriz).valor);
    printf("Fila:%d Columna:%d minimo: %d\n", maximoValor(matriz).indiceFila + 1, maximoValor(matriz).indiceColumna + 1, maximoValor(matriz).valor);
    return 1;
}

tdatosValor maximoValor(tMatriz pMatriz)
{
    tdatosValor mayor;
    mayor.valor = pMatriz[0][0];

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (pMatriz[i][j] > mayor.valor)
            {
                mayor.valor = pMatriz[i][j];
                mayor.indiceFila = i;
                mayor.indiceColumna = j;
            }
        }
    }
    return mayor;
}

tdatosValor minimoValor(tMatriz pMatriz)
{
    tdatosValor menor;
    menor.valor = pMatriz[0][0];

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (pMatriz[i][j] < menor.valor)
            {
                menor.valor = pMatriz[i][j];
                menor.indiceFila = i;
                menor.indiceColumna = j;
            }
        }
    }
    return menor;
}