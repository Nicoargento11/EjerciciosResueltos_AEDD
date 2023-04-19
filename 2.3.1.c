/*
 Se dispone de un termómetro para medir con exactitud la temperatura en un determinado lugar. Se
desea una aplicación que permita ingresar un valor de temperatura y muestre un mensaje que indique la sensación térmica, considerando los rangos siguientes:

Rango de temperatura     Sensación térmica
     [-10, 10)               Mucho frío
     [10, 15)                Poco frío
     [15, 25)                Temperatura normal
     [25, 30)                Poco calor
     [30, 45)                Mucho calor

*/
#include <stdio.h>
// Declaración de variables Globales
int temperatura;

// Declaración de Prototipos
void sensacionTermica(int);

// Función principal
int main()
{
    printf("Ingrese la temperatura: \n");
    scanf("%d", &temperatura);
    fflush(stdin);
    sensacionTermica(temperatura);
    return 1;
}

// declaración de funciones
void sensacionTermica(int temp)
{
    if (temp >= -10 && temp < 10)
    {
        printf("Mucho frío");
    }
    else if (temp >= 10 && temp < 15)
    {
        printf("Poco frío");
    }
    else if (temp >= 15 && temp < 25)
    {
        printf("Temperatura normal");
    }
    else if (temp >= 25 && temp < 30)
    {
        printf("Poco calor");
    }
    else if (temp >= 30 && temp < 45)
    {
        printf("Mucho calor");
    }
}