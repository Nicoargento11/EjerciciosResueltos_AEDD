/*
 Reutilice el código del programa correspondiente al ejercicio 2.1.1 y modifíquelo para que el ticket incluya la bonificación en el detalle.

 Ejemplos:

 Cant. unidades: 7 - Precio unit.: $ 1000
 Total: $ 7000.00
 Bonificación: $ 1050.00
 Total a pagar: $ 5950.00
 ¡Gracias por su compra!

*/
#include <stdio.h>

int cantidad;
float precioUnitario;
float total;
float bonificacion = 0;
float calcularTotal(int, float);
void imprimirTicket();

int main()
{
    printf("Ingrese la cantidad de productos: \n");
    scanf("%d", &cantidad);
    fflush(stdin);
    printf("Ingrese el precio del producto: \n");
    scanf("%f", &precioUnitario);
    total = calcularTotal(cantidad, precioUnitario);
    imprimirTicket();
    return 0;
}

float calcularTotal(int cant, float precio)
{
    float resultado = (float)cant * precio;
    if (resultado >= 5000 || cant > 10)
    {
        bonificacion = (float)resultado * 0.15;
        resultado = resultado - bonificacion;
    }
    return resultado;
}

void imprimirTicket()
{
    printf("Cant. unidades: %d - Precio unit.: $ %.2f \n", cantidad, precioUnitario);
    printf("Total: $ %.2f \n", total);
    printf("Bonificación: $ %.2f \n", bonificacion);
    printf("¡Gracias por su compra! \n");
}