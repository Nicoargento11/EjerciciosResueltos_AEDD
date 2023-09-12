// Escribir una función que calcule la división entera entre 2 números de manera recursiva. Recordar que la
// división matemática se define como una operación aritmética, que consiste en saber cuántas veces un
// número (divisor) está contenido en otra cifra (dividendo).
#include <stdio.h>

int divisor = 0;
int dividendo = 0;
int total = 0;
int calcularDivision(int _dividendo, int _divisor)
{

    if (_divisor > _dividendo)
    {
        printf("El cociente es: %d\n", total);
        printf("%d = %d * %d + %d", dividendo, divisor, total, dividendo - (divisor * total));
        return 1;
    }
    total = total + 1;

    calcularDivision(_dividendo, divisor + _divisor);
}
int main()
{
    printf("ingrese un dividendo: ");
    scanf("%d", &dividendo);
    printf("ingrese un divisor: ");
    scanf("%d", &divisor);
    calcularDivision(dividendo, divisor);
    return 1;
}