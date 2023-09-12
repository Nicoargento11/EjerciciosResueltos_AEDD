#include <stdio.h>

int b = 0;
int a = 0;
int total = 0;

int calcularMultiplicacion(int _a, int _b)
{
    if (_b <= 0)
    {
        return 0;
    }
    else
    {
        return _a + (calcularMultiplicacion(_a, _b - 1));
    }
}

int main()
{
    printf("ingrese un numero: ");
    scanf("%d", &a);
    printf("ingrese otro numero: ");
    scanf("%d", &b);
    printf("%d\n", calcularMultiplicacion(a, b));
    return 1;
}