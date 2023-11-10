#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// num = 9
// [1,2,3,4,5,6,7,8,9,10]
// inicio = 0
// fin = logingitud del array = 10
// medio = (fin - inicio) / 2 = 5

// si arr[medio] == num {
//     encontraste
//     return
// }
// if   num < arr[medio]
// fin = mitad
// mitad = (inicio + fin) / 2

// if   num > arr[medio]
// inicio = mitad
// mitad = (inicio + fin) / 2

int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

bool busquedaBinaria(int);

int inicio = 0;
int fin = sizeof(array) / sizeof(array[0]);
int num = 3;

int main()
{
    busquedaBinaria(num) ? printf("se encontro") : printf("no se encontro");
    return 1;
}

bool busquedaBinaria(int numPorBuscar)
{
    int medio = (inicio + fin) / 2;
    while (inicio <= fin)
    {
        printf("inicio: %d", inicio);
        printf("medio: %d", medio);
        printf("fin :%d\n", fin);

        if (array[medio] == numPorBuscar)
        {
            return true;
        }
        if (numPorBuscar < array[medio])
        {
            fin = medio - 1;
            medio = (inicio + fin) / 2;
        }
        if (numPorBuscar > array[medio])
        {
            inicio = medio + 1;
            medio = (inicio + fin) / 2;
        }
    }
    return false;
}

// {1, 2, 3, 4, 5, 6, 7, 8, 9, 10
//                 6, 7, 8, 9, 10 -> 5 + 10 / 2 = 7
//                 6 ,7
//                          9, 10
//                             10