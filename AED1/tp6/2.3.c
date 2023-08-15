#include <stdio.h>

struct datosAceites
{
    int tipoAceite;
    int valoracion;
};
struct datosOpinion
{
    int exelente;
    int buena;
    int malo;
};

typedef char string[50];
string tiposAceites[5] = {"Aceite de oliva", "Aceite de coco", "Aceite de canola", "Aceite de aguacate", "Aceite de semillas de uva"};

struct datosAceites aceites[5];
struct datosOpinion valoracion[5] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

// variables para guardar el aceite mas bueno y mas malo con su respectivo indice para mostrarlo por pantalla
int aceiteExelente[2] = {0, 0};
int aceiteMalo[2] = {0, 0};

int longitud = sizeof(aceites) / sizeof(aceites[0]);
int finEjecucion;

void ingresarDatos();
void calcularCalidadAceites();
int main()
{
    ingresarDatos();
    calcularCalidadAceites();

    printf("\nEl Aceite con mejor calidad es %s \n", tiposAceites[aceiteExelente[1]]);
    printf("El Aceite con peor calidad es %s\n", tiposAceites[aceiteMalo[1]]);
    printf("------------------------------");
    for (int i = 0; i < longitud; i++)
    {
        printf("\n %s \n", tiposAceites[i]);
        printf("Exelente - bueno - malo\n");
        printf("   %d     -   %d   -  %d\n", valoracion[i].exelente, valoracion[i].buena, valoracion[i].malo);
        printf("------------------------------");
    }
    printf("\nMejor aceite: %s; Cantidad de valoraciones: %d Posicion: %d \n", tiposAceites[aceiteExelente[1]], aceiteExelente[0], aceiteExelente[1]);
    printf("Peor aceite: %s; Cantidad de valoraciones: %d Posicion: %d\n", tiposAceites[aceiteMalo[1]], aceiteMalo[0], aceiteMalo[1]);
}

void ingresarDatos()
{
    for (int i = 0; i < longitud; i++)
    {
        printf("Ingrese El tipo de aceite: \n1- Aceite de oliva\n2- Aceite de coco\n3- Aceite de canola\n4- Aceite de aguacate\n5- Aceite semilla de uva\n");
        scanf("%d", &aceites[i].tipoAceite);
        fflush(stdin);
        printf("Elija la valoracion:\n1-exelente\n2-buena\n3-malo\n");
        scanf("%d", &aceites[i].valoracion);

        // vamos acumulando valoraciones segun el aceite
        if (aceites[i].valoracion == 1)
        {
            valoracion[aceites[i].tipoAceite - 1].exelente += 1;
        }
        else if (aceites[i].valoracion == 2)
        {
            valoracion[aceites[i].tipoAceite - 1].buena += 1;
        }
        else
        {
            valoracion[aceites[i].tipoAceite - 1].malo += 1;
        }

        // printf("¿Desea terminar la carga de datos?\n1-si\n2-no\n");
        // scanf("%d", &finEjecucion);
        // // condicional para cortar ejecucion
        // if (finEjecucion == 1)
        // {
        //     i = longitud;
        // }
    }
}

void calcularCalidadAceites()
{
    for (int j = 0; j < longitud; j++)
    {
        // buscamos los aceites con mejor valoracion y la guardamos con su indice
        if (aceiteExelente[0] < valoracion[j].exelente)
        {
            aceiteExelente[0] = valoracion[j].exelente;
            aceiteExelente[1] = j;
        }
        // buscamos los aceites con peor valoracion y la guardamos con su indice
        if (aceiteMalo[0] < valoracion[j].malo)
        {
            aceiteMalo[0] = valoracion[j].malo;
            aceiteMalo[1] = j;
        }
    }
}