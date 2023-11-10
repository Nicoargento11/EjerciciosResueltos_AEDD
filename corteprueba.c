#include <stdio.h>
#include <stdlib.h>

typedef char string[50];
typedef struct
{
    short int codTipo;
    string nombre;
    int stock;
} tRevista;

tRevista revista;
tRevista revistaAnterior;

int revistasConStock;
int revistasSinStock;

struct
{
    int tipo;
    int cantidad
} cantRevistaMayor;

int tiposRevistas[5] = {"informatica", "comics", "educativa", "Arquitectura", "biologia"};

FILE *archivo;

void inicializacion()
{
    archivo = fopen("dataRevistas", "rb");
    if (archivo != NULL)
    {
        fread(&revista, sizeof(tRevista), 1, archivo);
    }
    else
    {
        printf("no se ha encontrado");
        exit(EXIT_FAILURE);
    }
    revistaAnterior = revista;
    cantRevistaMayor.cantidad = 0;
    cantRevistaMayor.tipo = 0;
    printf("TIPO DE REVISTA | CANTIDAD DE REVISTAS CON STOCK | CANTIDAD DE REVISTAS SIN STOCK");
}

void procesoCorte()
{
    while (!feof(archivo))
    {
        // inicioCorte();
        revistasConStock = 0;
        revistasSinStock = 0;
        while (!feof(archivo) && revista.codTipo == revistaAnterior.codTipo)
        {
            //    unaRevista();
            if (revista.stock <= 0)
            {
                revistasSinStock++;
            }
            else
            {
                revistasConStock++;
            }

            fread(&revista, sizeof(tRevista), 1, archivo);
        }
        // finCorte();
        if (revistasConStock > cantRevistaMayor.cantidad)
        {
            cantRevistaMayor.cantidad = revistasConStock;
            cantRevistaMayor.tipo = revista.codTipo;
        }
        printf("%s | %d revistas | %d revistas", tiposRevistas[revista.codTipo - 1], revistasConStock, revistasSinStock);
        revistaAnterior = revista;
    }
}

void finalizacion()
{
    printf("tipo de revistas con mayor cantidad de stock disponible %s - Hay %d revistas en stock", tiposRevistas[cantRevistaMayor.tipo - 1], cantRevistaMayor.cantidad);
    fclose(archivo);
}
int main()
{
    iniacializacion();
    procesoCorte();
    finalizacion();
    return 1;
}