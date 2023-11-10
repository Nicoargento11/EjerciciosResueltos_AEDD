#include <stdio.h>
#include "2.h"

int main()
{
    float num1 = 0;
    float num2 = 0;
    char operacion;
    printf("Ingrese el primer numero: ");
    scanf("%f", &num1);
    fflush(stdin);
    printf("Ingrese la operacion: ");
    scanf("%c", &operacion);
    fflush(stdin);
    printf("Ingrese el segundo numero: ");
    scanf("%f", &num2);
    printf("%c", &operacion);
    switch (operacion)
    {
    case '+':
        printf("el resultado de la suma es: %.2f", sumarDosNumeros(num1, num2));
        break;
    case '-':
        printf("el resultado de la division es: %.2f", restarDosNumeros(num1, num2));
        break;
    case '*':
        printf("el resultado de la division es: %.2f", multiplicarDosNumeros(num1, num2));
        break;
    case '/':
        printf("el resultado de la division es: %.2f", dividirDosNumeros(num1, num2));
        break;

    default:
        printf("la operacion ingresada no es valida");
        break;
    }
    return 1;
}
