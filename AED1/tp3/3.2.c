#include <stdio.h>

int mitadDe(int);
int dobleDe(int);
int tripleDe(int);
int anteriorDe(int);
int posteriorDe(int);
int posteriorDelDobleDe(int);

int valor;
int opcion;

int main()
{
    printf("Ingrese el número que desea transformarlo: \n");
    scanf("%d", &valor);
    fflush(stdin);
    while (opcion != 7)
    {
        printf("Ingrese que desea hacer con el numero \n 1- mitad del numero \n 2- doble del numero \n 3- triple de un numero \n 4- anterior de un numero \n 5- posterior de un numero \n 6- doble del posterior de un numero \n 7- Apagar \n");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            printf("el resultado es: %d \n", mitadDe(valor));
            break;
        case 2:
            printf("el resultado es: %d \n", dobleDe(valor));
            break;
        case 3:
            printf("el resultado es: %d \n", tripleDe(valor));
            break;
        case 4:
            printf("el resultado es: %d \n", anteriorDe(valor));
            break;
        case 5:
            printf("el resultado es: %d \n", posteriorDe(valor));
            break;
        case 6:
            printf("el resultado es: %d \n", posteriorDelDobleDe(valor));
            break;
        case 7:
            printf("La calculadora se ha apagado \n");
            return 0;
        default:
            printf("El numero ingresado no es valido \n");
            break;
        }
    }
    return 0;
}

int posteriorDelDobleDe(int num)
{
    int resultado = (num * 2) + 1;
    return resultado;
}

int mitadDe(int num)
{
    int resultado = num / 2;
    return resultado;
}
int dobleDe(int num)
{
    int resultado = num * 2;
    return resultado;
}
int tripleDe(int num)
{
    int resultado = num * 3;
    return resultado;
}
int anteriorDe(int num)
{
    int resultado = num - 1;
    return resultado;
}
int posteriorDe(int num)
{
    int resultado = num + 1;
    return resultado;
}