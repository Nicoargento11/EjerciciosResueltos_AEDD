#include <stdio.h>
// Declaración de variables Globales
int alto;
int ancho;
int resultado;

// Declaración de Prototipos
void funcion_calcular_perimetro();

// Función principal
int main()
{
    funcion_calcular_perimetro(ancho, alto);
    printf("La función retorno: %d\n", resultado);
    return 1;
}

// declaración de funciones
void funcion_calcular_perimetro(int ladoA, int ladoB)
{
    resultado = (ladoA + ladoB) * 2;
}