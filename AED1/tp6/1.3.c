#include <stdio.h>
#include <string.h>

struct Altura
{
    char mes[30];
    int altura;
};

struct Altura series[2][12] =
    {
        {{"Mayo", 54},
         {"Junio", 73},
         {"Julio", 23},
         {"Agosto", 64},
         {"Septiembre", 23},
         {"Octubre", 92},
         {"Noviembre", 17},
         {"Diciembre", 53},
         {"Enero", 75},
         {" Febrero ", 35},
         {" Marzo ", 75},
         {" Abril ", 64}},
        {{" Mayo ", 53},
         {" Junio ", 32},
         {" Julio ", 73},
         {" Agosto ", 28},
         {" Septiembre ", 83},
         {" Octubre ", 28},
         {" Noviembre ", 19},
         {" Diciembre ", 16},
         {" Enero ", 74},
         {" Febrero ", 38},
         {" Marzo ", 10},
         {"Abril", 12}}};

int menorAlturaGeneral = 1000;
char mesAltura[30];
int primerSerieMenorAltura;
int segundaSerieMenorAltura;
int main()
{
    // en q mes ocurrio la menor altura
    // cual fue la menor altura en cada una
    // en cual se dio la menor altura
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (i == 0 && series[i][j].altura < menorAlturaGeneral)
            {
                primerSerieMenorAltura = series[i][j].altura;
            }
            else
            {
                segundaSerieMenorAltura = series[i][j].altura;
            }

            if (series[i][j].altura < menorAlturaGeneral)
            {
                menorAlturaGeneral = series[i][j].altura;
                strcpy(mesAltura, series[i][j].mes);
            }
            printf("%s\n", series[i][j].mes);
        }
    }
    printf("La menor altura ocurrio en%s y es de:%d \n", mesAltura, menorAlturaGeneral);
    printf("La menor altura en la primera serie es: %d\n", primerSerieMenorAltura);
    printf("La menor altura en la segunda serie es: %d\n", segundaSerieMenorAltura);

    if (primerSerieMenorAltura < segundaSerieMenorAltura)
    {
        printf("La menor altura ocurrio en la primer serie y es de: %d\n", primerSerieMenorAltura);
    }
    else
    {
        printf("La menor altura entre las dos ocurrio en la segunda serie y es de: %d\n", segundaSerieMenorAltura);
    }
    return 1;
}