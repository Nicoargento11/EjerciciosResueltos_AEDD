#include <stdio.h>
#include <stdlib.h>

FILE *archivo;

typedef char string[50];
typedef struct
{
    short int numCuenta;
    string nombre;
    short int codOperacion;
    int importe;
} tDatosCliente;

tDatosCliente cliente;

void inicializacion()
{
    archivo = fopen("clientesBanco.dat", "ab");
    if (archivo != NULL)
    {
        printf("Archivo creado!!!\n");
    }
    else
    {
        printf("Archivo no encontrado");
        exit(EXIT_FAILURE);
    }
}

void ingresarDatos()
{
    printf("ingrese su numero de cuenta: \n");
    scanf("%d", &cliente.numCuenta);

    fflush(stdin);
    printf("ingrese su nombre \n");
    scanf("%s", &cliente.nombre);
    fflush(stdin);

    printf("Ingrese su cod operacion \n");
    scanf("%s", &cliente.codOperacion);

    printf("ingrese su importe: \n");
    scanf("%d", &cliente.importe);
    fflush(stdin);
}

void procesoAgregar()
{
    char finalizar;
    while (finalizar != 'n')
    {
        ingresarDatos();
        fflush(stdin);
        printf("Desea seguir agregando? s/n ");
        scanf("%c", &finalizar);
        fflush(stdin);

        fwrite(&cliente, sizeof(tDatosCliente), 1, archivo);
    }
}
void finalizacion()
{
    fclose(archivo);
}
int main()
{
    inicializacion();
    procesoAgregar();
    finalizacion();
}