/*
 Una farmacia emite un ticket de compra en función de la cantidad y precio del producto vendido, y el tipo de producto: ‘P’, ‘F’ o ‘L’ (P-Perfumería, F-Farmacia y L-Limpieza). Escriba un programa en C paracalcular el valor de la compra, aplicando una bonificación de acuerdo al tipo de producto: ‘P’: 5%, ‘F’: 10%, ‘L’: 15%. Imprimir el importe a pagar y el porcentaje de bonificación, con la leyenda “% bonificado: XX”.
*/

#include <stdio.h>
// Declaración de variables Globales
int totalCompra;
char tipoProducto;
int bonificacion;
// Declaración de Prototipos
float calcularBonificacion();

// Función principal
int main()
{
    printf("Ingrese el valor de su compra: \n");
    scanf("%d", &totalCompra);
    fflush(stdin);
    printf("Ingrese el tipo de producto: \n");
    printf("P-Perfumería F-Farmacia L-Limpieza) \n");
    scanf(" %c", &tipoProducto);
    calcularBonificacion();
    printf("El importe a pagar es de: %.2f \n", calcularBonificacion());
    printf("Con una bonificación del %d%%", bonificacion);

    return 1;
}

// declaración de funciones

float calcularBonificacion()
{
    float totalBonificado;
    switch (tipoProducto)
    {
    case 'P':
        bonificacion = 5;
        totalBonificado = (float)totalCompra * 0.95;
        break;
    case 'F':
        bonificacion = 10;
        totalBonificado = (float)totalCompra * 0.90;
        break;
    case 'L':
        bonificacion = 15;
        totalBonificado = (float)totalCompra * 0.85;
        break;

    default:
        printf("El tipo de producto ingresado no es valido");
        break;
    }
    return totalBonificado;
}