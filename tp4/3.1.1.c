#include <stdio.h>

int main()
{
    int num;
    int total = 0;
    int i;
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
    {
        total = total + i;
        printf("%d ", i);
    }
    printf("\n La suma total es: %d", total);
    return 0;
}