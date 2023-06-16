/*
 Reutilice el código del programa correspondiente al ejercicio 1.a) y modifíquelo para que calcule una bonificación de 15% al total de la compra si ésta es mayor o igual a $5000 o se com pran más de 10 productos. Utilice una sola expresión lógica.
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
    printf("¡Gracias por su compra! \n");
}