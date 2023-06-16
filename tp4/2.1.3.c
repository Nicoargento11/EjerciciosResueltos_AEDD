/*
 Reutilice el código del programa correspondiente al ejercicio 2.1.2 y modifíquelo para que calcule una bonificación de 10% al total de la compra si ésta es mayor o igual a $5000 y si la forma de pago es en efectivo. Utilice una sola expresión lógica. Modificar el ticket para que incluya la forma de pago en el detalle. Será necesario ingresar la forma de pago. Las formas de pago disponibles son (c-tarjeta de crédito / d-tarjeta de débito / e-efectivo).
 *Nota: prestar atención al ingreso de datos de tipo char.
*/
#include <stdio.h>

int cantidad;
float precioUnitario;
float total;
float bonificacion = 0;
char metodoPago;
float calcularTotal(int, float, char);
void imprimirTicket();

int main()
{
    printf("Ingrese la cantidad de productos: \n");
    scanf("%d", &cantidad);
    fflush(stdin);
    printf("Ingrese el precio del producto: \n");
    scanf("%f", &precioUnitario);
    fflush(stdin);
    printf("Ingrese su metodo de pago: \n");
    printf("c-tarjeta de crédito / d-tarjeta de débito / e-efectivo \n");
    scanf(" %c", &metodoPago);
    fflush(stdin);
    total = calcularTotal(cantidad, precioUnitario, metodoPago);
    imprimirTicket();
    return 0;
}

float calcularTotal(int cant, float precio, char metodo)
{
    float resultado = (float)cant * precio;
    if (resultado >= 5000 || metodo == 'e')
    {
        bonificacion = (float)resultado * 0.10;
        resultado = resultado - bonificacion;
    }
    return resultado;
}

void imprimirTicket()
{
    printf("Cant. unidades: %d - Precio unit.: $ %.2f \n", cantidad, precioUnitario);
    printf("Total: $ %.2f \n", total + bonificacion);
    printf("Forma de pago: %c \n", metodoPago);
    printf("Bonificación: $ %.2f \n", bonificacion);
    printf("Total a pagar: $ %.2f \n", total);
    printf("¡Gracias por su compra! \n");
}