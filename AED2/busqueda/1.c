
// tipos de busqueda:

// secuencial
// secuencial ordenada
// busqueda binaria

// busqueda de maximos y minimos:
//  ramificacion del arbol
//  campeonato
//  supuesto o prepo

// 1) escribir un programa que permita determinar  si un entero ingresado por teclado existe en un vector. Para ello sera necesario disponer de lo siguiente
//  a una funcion que permita cargar elementos en un vector de numeros enteros
//  una funcion que permita visualizar los elementos almacenados en el vector
//  una funcion que devuelva verdadero en el caso que el elemento a buscar exista en el vector, y falso en caso contrario

#include <stdio.h>
#include <stdbool.h>
#define MAX 5
typedef int tVector[MAX];

tVector vector = {7, 2, 6, 4, 8};

bool busquedaSecuencial(tVector pVector, int elem)
{
    int result = -1;
    int i = 0;
    while (i < MAX)
    {
        if (elem == pVector[i])
        {
            result = elem;
            i = MAX;
        }
        i++;
    }
    return result == -1 ? false : true;
}

void visualizarelementos(tVector pVector)
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", pVector[i]);
    }
}

int main()
{
    busquedaSecuencial(vector, 7) ? printf("numero encontrado\n") : printf("numero no encontrado");
    visualizarelementos(vector);
    return 1;
}