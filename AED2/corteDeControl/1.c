#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[50];
typedef struct
{
    short int numCuenta;
    string nombre;
    short int codOperacion;
    int importe;
} tDatosCliente;

typedef struct
{
    int cantMovimientos;
    float totalDeposito;
    float totalExtraccion;
} tInforme;

tDatosCliente cliente, clienteAnterior;
tInforme informe, informeFinal;
FILE *archivo;

void inicializacion()
{
    /*	Actividades al inicio del programa:
    1. Abrir archivo en modo lectura
    2. Leer el primer registro
    3. Guardar campo de control anterior, en este caso el registro completo anterior
    4. Inicializar contadores/acumuladores generales/totales
    5. Escribir titulos */
    archivo = fopen("clientesBanco.dat", "rb");
    if (archivo != NULL)
    {
        fread(&cliente, sizeof(cliente), 1, archivo);
    }
    else
    {
        printf("Archivo no encontrado");
        exit(EXIT_FAILURE);
    }
    clienteAnterior = cliente;
    informeFinal.totalDeposito = 0;
    informeFinal.cantMovimientos = 0;
    informeFinal.totalExtraccion = 0;
}

procesoCorte()
{
    while (!feof(archivo))
    {
        // principio corte
        informe.totalDeposito = 0;
        informe.cantMovimientos = 0;
        informe.totalExtraccion = 0;

        while (!feof(archivo) && clienteAnterior.numCuenta == cliente.numCuenta)
        {
            if (cliente.codOperacion == 1)
            {
                informe.totalDeposito += cliente.importe;
            }
            else
            {
                informe.totalExtraccion += cliente.importe;
            }
            fread(&cliente, sizeof(tDatosCliente), 1, archivo);
        }
        // mostrar informe cliente final
        informeFinal.totalDeposito += informe.totalDeposito;
        informeFinal.totalExtraccion += informe.totalExtraccion;
        clienteAnterior = cliente;
    }
}
void finalizacion()
{
    // imprimir total clientes
    fclose(archivo);
}
int main()
{
    inicializacion();
    procesoCorte();
    finalizacion();
}
