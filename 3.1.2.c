#include <stdio.h>
#define N 20

int main()
{
    int contador = 0;
    for (int i = 1; i <= N; i++)
    {
        if ((i % 2) != 0)
        {
            contador = contador + i;
            printf("%d ", i);
        }
    }
    printf("\n El promedio es: %d", contador / N);
    return 0;
}