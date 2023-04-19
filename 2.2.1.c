#include <stdio.h>

int sueldo;

float calcularPrestamo(int);
void imprimirSueldo();

int main()
{
    printf("Ingrese el sueldo: ");
    scanf("%d", &sueldo);
    imprimirSueldo();
    return 0;
}

float calcularPrestamo(int sueldo)
{
    float prestamo;
    if (sueldo >= 100000)
    {
        prestamo = 300000;
    }
    else
    {
        prestamo = (float)sueldo * 0.75;
    }
    return prestamo;
}

void imprimirSueldo()
{
    printf("Sueldo: %d - Prestamo autorizado.: $ %.2f \n", sueldo, calcularPrestamo(sueldo));
    printf("¡Gracias por confiar en nosotros! \n");
}