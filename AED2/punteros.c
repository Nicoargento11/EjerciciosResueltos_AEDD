#include <stdio.h>
#include <stdlib.h>

int a = 25;
int *ipuntero;
int main()
{
    ipuntero = (int *)malloc(sizeof(int));
    *ipuntero = 5;
    printf("la direccion de la variable que esta apuntando ipuntero es: %p\n", &a);
    printf("El valor de la variable que esta apuntando ipuntero es: %d\n", a);
    printf("la direccion hacia donde apunta ipuntero es: %p\n", ipuntero);
    printf("El valor hacia adonde apunta ipuntero es: %d\n", *ipuntero);
    printf("La direccion de memoria de ipuntero es: %p\n", &ipuntero);
    return 0;
}
