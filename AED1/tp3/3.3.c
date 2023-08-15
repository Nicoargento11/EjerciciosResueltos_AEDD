#include <stdio.h>

float peso_kg;
int altura_cm;

float calcular_IMC(float, int);
int main()
{
    float imc;
    printf("Ingrese su peso en kg: \n");
    scanf("%f", &peso_kg);
    fflush(stdin);
    printf("Ingrese su altura en cm: \n");
    scanf("%d", &altura_cm);
    imc = calcular_IMC(peso_kg, altura_cm);
    printf("El resultado es %f \n", imc);

    return 0;
}

float calcular_IMC(float peso, int altura)
{
    float altura_m = (float)altura / 100;
    float resultado = peso / (altura_m * altura_m);
    return resultado;
}