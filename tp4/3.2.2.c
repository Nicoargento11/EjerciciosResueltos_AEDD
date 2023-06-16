#include <stdio.h>
#include <string.h>

char nombreProducto[30];
int cantidadProducto;
float precioUnitario;
float totalAcumulado = 0;

void ingresarDatos();
void devolverTicket();
void gastoActualizado();

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
        printf("Ingresa el precio unitario del producto: %s \n \n", nombreProducto);
        scanf("%f", &precioUnitario);
        fflush(stdin);
        totalAcumulado += (float)cantidadProducto * precioUnitario;
        gastoActualizado();
        printf("¿Desea seguir agregando mas productos? \n");
        printf("SI- ingrese un numero positivo \nNO- ingrese -1 \n");
        scanf("%d", &cajero);
        fflush(stdin);
    }
}

void devolverTicket()
{
    printf("\n******************************** \n");
    printf("TOTAL A PAGAR: $%.2f \n", totalAcumulado);
    printf("******************************** \n");
    printf("¡Gracias por su compra!");
}

void gastoActualizado()
{
    printf("******************************** \n");
    printf("%s \n: cantidad y valor", nombreProducto);
    printf("%d x %.2f \n", cantidadProducto, precioUnitario);
    printf("Total acumulado: %.2f \n \n", totalAcumulado);
    printf("******************************** \n");
}