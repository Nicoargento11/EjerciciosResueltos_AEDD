/* Un local comercial quiere colocar una cinta con una leyenda impresa en una caja rectangular.
Para determinar la cantidad de cinta a comprar necesita conocer el perímetro de la caja.
Escriba una función que calcule y devuelva el valor del perímetro. El programa debe permitir
el ingreso de los datos requeridos: el ancho (lado1) y alto (lado2) de la caja y debe mostrar en
pantalla los datos de la caja y la cantidad de metros de cinta a comprar.
Nota: perímetro = 2 * (lado1 + lado2). */

#include <stdio.h>

/* Variables globales */
int ancho;
int alto;
int resultado;

/* prototipo de funciones */

int calcularPromedio(int, int);

int main()
{
    printf("Calcular el perimetro de una caja \n Ingrese el ancho de la caja: ", ancho);
    scanf("%d", &ancho);
    fflush(stdin);
    printf("Ingrese el alto de la caja: ", alto);
    scanf("%d", &alto);
    calcularPromedio(ancho, alto);
    printf("el resultado del perimetro de su caja es de: %dcm", resultado);

    return ancho;
}

int calcularPromedio(int a, int b)
{
    resultado = 2 * (a + b);
    return resultado;
}