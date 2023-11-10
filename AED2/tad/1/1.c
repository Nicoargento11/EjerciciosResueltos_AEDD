#include <stdio.h>
#include "1.h"

int main()
{
    float base = 0;
    float altura = 0;
    printf("Ingrese la base: ");
    scanf("%f", &base);
    printf("Ingrese la altura: ");
    scanf("%f", &altura);
    printf("El resultado del perimetro es: %.2f\n", calcularArea(base, altura));
    printf("El resultado del area es: %.2f", calcularPerimetro(base, altura));
}