// Escribir un programa que permita ingresar por teclado la cantidad de elementos de un vector, y cada uno de los valores de los elementos del vector. Ademas, escribir funciones para obtener:
// a) el maximo valor almacenado en el vector
// b) el minimo valor almacenado en el vector
// c) la media de todos los valores
// d) la semisuma (promedio entre el maximo y el minimo)

#include <stdio.h>

#define MAX 5

typedef int tVector[MAX];

tVector vector = {2, 4, 6, 8, 10};

int maximoValor(tVector);
int minimoValor(tVector);
float mediaValores(tVector);
float semisumaMaxMin(tVector);
int main()
{
    printf("maximo: %d\n", maximoValor(vector));
    printf("minimo: %d\n", minimoValor(vector));
    printf("promedio: %.2f\n", mediaValores(vector));
    printf("semisuma: %.2f\n", semisumaMaxMin(vector));
    return 1;
}

// supuesto o prepo
int maximoValor(tVector pVector)
{
    int mayor = pVector[0];
    int posMayor = -1;

    for (int i = 0; i < MAX; i++)
    {
        if (pVector[i] > mayor)
        {
            mayor = pVector[i];
            posMayor = i;
        }
    }
    return mayor;
}

int minimoValor(tVector pVector)
{
    int menor = pVector[0];
    int posMenor = -1;

    for (int i = 0; i < MAX; i++)
    {
        if (pVector[i] < menor)
        {
            menor = pVector[i];
            posMenor = i;
        }
    }
    return menor;
}

float mediaValores(tVector pVector)
{
    int count = 0;
    for (int i = 0; i < MAX; i++)
    {
        count += pVector[i];
    }
    float resultado = count / MAX;
    return resultado;
}

float semisumaMaxMin(tVector pVector)
{
    int max = maximoValor(vector);
    int min = minimoValor(vector);
    return (max + min) / 2;
}
