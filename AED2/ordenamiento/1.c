#include <stdio.h>
#include <stdlib.h>
// burbuja
// seleccion
// insercion || baraja
#define MAX 5

int array[MAX] = {3, 8, 2, 6, 5};
void seleccionDirecta(int *pVector)
{
    // nesecitamos la posicion y valor del menor para despues intercambiarlo
    int posMenor, valMenor;
    // usamos un aux para poder intercambiar.Triangular
    int aux;
    for (int i = 0; i < MAX - 1; i++)
    {
        // tomamos el primer elemento como menor, a medida que avanza i
        valMenor = pVector[i];
        // guardamos su posicion
        posMenor = i;
        for (int j = i + 1; j < MAX; j++) // empezamos en el siguiente de i ya que lo que esta atras ya esta ordenado
        {
            // encontramos un numero menor
            if (pVector[j] < valMenor)
            {
                // cambiamos nuestro menor
                valMenor = pVector[j];
                posMenor = j;
            }
        }
        // hubo cambios en la posicion del menor
        if (posMenor != i)
        {
            // cambiamos el menor que encontramos con el primer elemento, dependiendo de i
            aux = pVector[i];
            pVector[i] = valMenor;
            pVector[posMenor] = aux;
        }
    }
};
// encontramos el menor
void insercionDirecta(int *pVector)
{
    int i, j;
    int aux;
    for (i = 1; i < MAX; i++)
    {
        aux = pVector[i];
        j = i - 1;
        while (j >= 0 && pVector[j] > aux)
        {
            pVector[j + 1] = pVector[j];
            j = j - 1;
        }
        pVector[j + 1] = aux;
    }
};
// encontramos el mayor
void burbuja(int *pVector)
{
    int aux;
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            if (pVector[j] > pVector[j + 1])
            {
                aux = pVector[j];
                pVector[j] = pVector[j + 1];
                pVector[j + 1] = aux;
            }
        }
    }
}
// encontramos el mayor

int main()
{
    seleccionDirecta(array);
    for (int i = 0; i < MAX; i++)
    {

        printf("%d", array[i]);
    }

    return 1;
}