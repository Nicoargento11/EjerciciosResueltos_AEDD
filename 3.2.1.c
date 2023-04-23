#include <stdio.h>
#include <string.h>

char nombreProducto[30];
int cantidadProducto;
float precioUnitario;

void ingresarDatos();
void devolverTicket();

int main()
{
    ingresarDatos();
    devolverTicket();
    return 0;
}

void ingresarDatos()
{
    int cajero = 0;
    while (cajero != -1)
    {
        printf("Ingresa el nombre del producto: \n");
        scanf("%[^\n]s", &nombreProducto);
        fflush(stdin);
        printf("Ingresa la cantidad de %s \n", nombreProducto);
        scanf("%d", &cantidadProducto);
        fflush(stdin);
        printf("Ingresa el precio unitario del producto: %s \n", nombreProducto);
        scanf("%f", &precioUnitario);
        fflush(stdin);
        printf("¿Desea seguir agregando mas productos? \n");
        printf("SI- ingrese un numero positivo \nNO- ingrese -1 \n");
        scanf("%d", &cajero);
    }
}

void devolverTicket()
{
    float resultado = (float)cantidadProducto * precioUnitario;
    printf("\n******************************** \n");
    printf("TOTAL A PAGAR: $%.2f \n", resultado);
    printf("******************************** \n");
    printf("¡Gracias por su compra!");
}