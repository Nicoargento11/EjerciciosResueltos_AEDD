#include <stdio.h>
int num;
int tablaMultiplicar(int);
int main()
{
    printf("Ingresa la tabla que desea ver: ");
    scanf("%d", &num);
    tablaMultiplicar(num);
    return 0;
}

int tablaMultiplicar(int numero)
{
    int resultado;
    printf("----------------- \n");
    printf("  Tabla del %d   \n", numero);
    printf("----------------- \n");
    for (int i = 0; i <= 10; i++)
    {
        resultado = numero * i;
        printf("   %d x %d = %d \n", numero, i, resultado);
    }
}