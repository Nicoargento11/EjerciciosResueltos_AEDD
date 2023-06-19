#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char cadena[25];

struct datosProducto
{
    cadena nombre;
    int cantidad;
    float precio;
};

struct datosProducto productos[2];
int longitud = sizeof(productos) / sizeof(productos[0]);
char nombreMayus;

void convertirMayusculas(cadena, int);

int productoMayor();
int productoMenor();

cadena mayus;

int main()
{
    int i;
    for (i = 0; i < longitud; i++)
    {
        printf("Ingrese el nombre del producto: \n");
        scanf("%[^\n]s", &productos[i].nombre);
        fflush(stdin);
        convertirMayusculas(productos[i].nombre, i);
        strcpy(productos[i].nombre, mayus);
        printf("Ingrese la cantidad de producto/s: \n");
        scanf("%d", &productos[i].cantidad);
        fflush(stdin);
        printf("Ingrese el precio del producto: \n\n");
        scanf("%f", &productos[i].precio);
        fflush(stdin);
    }
    printf("producto mayor %d\n", productoMayor());
    printf("producto menor %d\n\n", productoMenor());

    int j;
    for (j = 0; j < longitud; j++)
    {
        printf("Palabra de los productos a Mayuscula: %s \n", productos[j].nombre);
    }
    return 1;
}

int productoMayor()
{
    int i;
    int mayor = 0;
    for (i = 0; i < longitud; i++)
    {
        if (mayor < productos[i].cantidad)
        {
            mayor = productos[i].cantidad;
        }
    }
    return mayor;
}

int productoMenor()
{
    int i;
    int menor = productos[0].cantidad;
    for (i = 0; i < longitud; i++)
    {
        if (menor > productos[i].cantidad)
        {
            menor = productos[i].cantidad;
        }
    }
    return menor;
}

void convertirMayusculas(cadena c_nombre, int indice)
{
    int longitud = strlen(c_nombre);
    int i;
    for (i = 0; i < longitud; i++)
    {
        mayus[i] = toupper(c_nombre[i]);
    }
}