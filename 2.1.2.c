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