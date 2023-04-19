#include <stdio.h>

/*Declaracion de variables globales*/
int sueldo;

/*Declaracion de prototipos de funciones*/
float calcularPrestamo(int);
void imprimirSueldo();

/*Declaracion de la funcion principal*/
int main()
{
    printf("Ingrese el sueldo: ");
    scanf("%d", &sueldo); // Lee el sueldo ingresado por el usuario y lo almacena en la variable sueldo
    imprimirSueldo();     // Llama a la función imprimirSueldo para imprimir el sueldo ingresado y el monto de préstamo autorizado
    return 0;
}
/*Función para calcular el monto de préstamo autorizado*/
float calcularPrestamo(int sueldo)
{
    float prestamo;
    if (sueldo >= 100000) // Si el sueldo es mayor o igual a 100000
    {
        prestamo = 300000;
    }
    else // Si el sueldo es menor a 100000
    {
        prestamo = (float)sueldo * 0.75; // Calcula el monto de préstamo multiplicando el sueldo por 0.75
    }
    return prestamo; // Devuelve el monto de préstamo
}
/*Función para imprimir el sueldo ingresado y el monto de préstamo autorizado*/
void imprimirSueldo()
{
    printf("Sueldo: %d - Prestamo autorizado.: $ %.2f \n", sueldo, calcularPrestamo(sueldo));
    printf("¡Gracias por confiar en nosotros! \n");
}
