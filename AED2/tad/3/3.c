#include <stdio.h>
#include "3.h"
int main()
{
    int num1 = 0;
    int num2 = 0;
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);
    printf("El valor mayor es: %d\n", calcularMayorValor(num1, num2));
    printf("El valor menor es: %d\n", calcularMenorValor(num1, num2));
    calcularIgualValor(num1, num2) ? printf("Los valores son iguales\n") : printf("Los valores son distintos\n");
    intercambiarValores(&num1, &num2);
    printf("primer numero: %d ", num1);
    printf("segundo numero: %d\n", num2);
}