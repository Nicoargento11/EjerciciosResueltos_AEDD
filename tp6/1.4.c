#include <stdio.h>
#include <string.h>

typedef char string[50];
string primeraComision[6];
string segundaComision[6];

int comision;
int cantRepetidos;
char nombreAlumno[20];
int main()
{
    for (int i = 0; i < sizeof(primeraComision) / 4; i++)
    {
        printf("Ingrese el nombre del alumno");
        scanf("%s", &nombreAlumno);
        printf("Ingrese la comision: 1 o 2");
        scanf("%d", &comision);
        if (comision == 1)
        {
            strcpy(primeraComision[i], nombreAlumno);
        }
        else
        {
            strcpy(segundaComision[i], nombreAlumno);
        }
    }
}