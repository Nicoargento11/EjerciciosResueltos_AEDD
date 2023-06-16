/* La maestra de la Sala Verde del jardín maternal Bichito de Luz, quiere pintar las figuras circulares de madera con las que juegan los niños (todas del mismo tamaño). Una vez que sepa toda el área a cubrir, en la pinturería le indicarán la cantidad necesaria de pintura. Para ello necesita saber el área del círculo de las figuras. Escriba una función que calcule y devuelva el valor del área. El programa debe permitir el ingreso de la cantidad de figuras y el valor del
radio, y debe mostrar en pantalla la cantidad de figuras y el total de la superficie a cubrir.
Nota: área de círculo= PI * r2*/

#include <stdio.h>

/* Variables globales */
int cant_circulos;
int radio;
int resultadoArea;
int totalSuperficie;
int PI = 3.14;

/* prototipo de funciones */

int calcularArea(int);
int calcularSuperficie(int, int);

int main()
{
    printf("Calcular la superficie a pintar \n Ingrese la cantidad de circulos: ", cant_circulos);
    scanf("%d", &cant_circulos);
    fflush(stdin);
    printf("Ingrese el radio de los circulos: ", radio);
    scanf("%d", &radio);
    calcularArea(radio);
    calcularSuperficie(cant_circulos, resultadoArea);
    printf("el resultado de la superficie que desea pintar es de: %d", totalSuperficie);

    return 1;
}

int calcularArea(int a)
{
    resultadoArea = PI * (a * a);
    return resultadoArea;
}

int calcularSuperficie(int a, int b)
{
    totalSuperficie = a * b;
    return totalSuperficie;
}