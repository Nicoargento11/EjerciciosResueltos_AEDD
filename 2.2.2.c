/* Con el objeto de conseguir fondos para su viaje de egresados, los alumnos de 6to. año organizaron un baile. El precio de las entradas es de $750 con una consumición, y de $500 sin consumición. Si la venta es anticipada, se realiza un descuento del 20% al valor de la entrada. Escriba un algoritmo que solicite por teclado el tipo de entrada (1-con consumición, 2-sin consumición) y un carácter que indique si la venta fue anticipada (‘S’) o no (‘N’) y muestre por pantalla el tipo de entrada y el importe a pagar. */

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