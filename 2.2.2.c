#include <stdio.h>
// Declaración de variables Globales
int tipoEntrada;
char anticipada;
// Declaración de Prototipos
int calcularImporte();
void pedirDatos();
void imprimir();
// Función principal
int main()
{
    pedirDatos();
    calcularImporte();
    imprimir();
    return 0;
}

// declaración de funciones

void pedirDatos()
{
    printf("Ingrese el tipo de entrada: \n");
    printf("1- con consumicion \n");
    printf("2- sin consumicion \n");
    scanf("%d", &tipoEntrada);
    fflush(stdin);
    printf("¿La compra fue anticipada? \n");
    printf("S- si \n");
    printf("N- no \n");
    scanf(" %c", &anticipada);
}

int calcularImporte()
{
    float importe;
    if (tipoEntrada == 1)
    {
        importe = 750;
    }
    else
    {
        importe = 500;
    }
    if (anticipada == 's' || anticipada == 'S')
    {
        importe = importe * 0.8;
    }

    return importe;
}

void imprimir()
{
    if (anticipada == 's' || anticipada == 'S')
    {
        printf("El tipo de su entrada es anticipada \n");
        printf("El importe a pagar con un descuento es de %d \n", calcularImporte());
    }
    else
    {
        printf("El tipo de su entrada no es anticipada \n");
        printf("El importe a pagar es de %d \n", calcularImporte());
    }
}