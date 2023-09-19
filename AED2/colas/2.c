// Se necesita procesar los datos de los llamados que ingresan al call center de una empresa de
// telecomunicaciones. Para ello se implementa una cola, en donde cada nodo contiene los siguientes datos:
// nombre y apellido, número de teléfono, DNI, código de lugar de procedencia (01-Corrientes 02-Chaco).
// Se solicita escribir las funciones para:
// a) Conocer la cantidad de llamadas provenientes de cada lugar de procedencia y la cantidad total
// de llamadas en cola de espera.
// b) Generar un listado que incluya los números telefónicos de las llamadas provenientes de
// Corrientes.
// Tener en cuenta que se deben realizar las operaciones básicas necesarias para la manipulación de la cola con
// punteros.

// pop en el inicio, push en el final
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char string[30];
typedef struct
{
    string nombreApellido;
    int numTelefono;
    int dni;
    int lugarProcedencia;
} datosLlamados;

typedef struct nodo
{
    datosLlamados llamado;
    struct nodo *siguiente;

} cola;

struct
{
    cola *primero;
    cola *ultimo;
} colaLlamadas;

datosLlamados llamado;

bool colaVacia();
void inicializarCola();
void removerMemoria();
void push(datosLlamados);
void pop();
void cantLugarProcedencia();
void visualizarCola();
void ingresarDatos();
void menu();

int main()
{
    inicializarCola();
    menu();
    removerMemoria();
    return 1;
}

void menu()
{
    int opcion = 0;
    while (opcion != -1)
    {
        if (colaVacia())
        {
            printf("La cola de llamadas esta vacia\n");
            ingresarDatos();
            push(llamado);
        }
        else
        {
            printf("Que desea hacer:\n");
            printf("1- Ingresar registro\n");
            printf("2- Eliminar registro:\n");
            printf("3- Cantidad de llamadas provenientes de cada lugar de procedencia :\n");
            printf("4- Visualizar cola de espera:\n");
            printf("-1 Finalizar programa:\n");
            scanf("%d", &opcion);
            switch (opcion)
            {
            case 1:
                ingresarDatos();
                push(llamado);
                break;
            case 2:
                pop();
                break;

            case 3:
                cantLugarProcedencia();
                break;

            case 4:
                visualizarCola();
                break;

            case -1:
                printf("Programa finalizado\n");
                break;
            default:
                break;
            }
        }
    }
    visualizarCola();
}

void cantLugarProcedencia()
{
    int cantCorrientes = 0;
    int cantChaco = 0;
    int cantCola = 0;
    struct nodo *indice = colaLlamadas.primero;
    while (indice != NULL)
    {
        cantCola++;
        indice->llamado.lugarProcedencia == 1 ? cantCorrientes++ : cantChaco++;
        indice = indice->siguiente;
    }
    printf("\nLa cantidad de personas de Corrientes es de: %d\n", cantCorrientes);
    printf("La cantidad de personas de Chaco es de: %d\n", cantChaco);
    printf("Llamadas en lista de espera: %d\n", cantCola);
}

void ingresarDatos()
{
    fflush(stdin);
    printf("Ingrese su nombre y apellido: ");
    scanf("%[^\n]s", &llamado.nombreApellido);
    fflush(stdin);
    printf("Ingrese su numero de Telefono: \n");
    scanf("%d", &llamado.numTelefono);
    printf("Ingrese su DNI: \n");
    scanf("%d", &llamado.dni);
    printf("Ingrese su lugar de procedencia: \n");
    printf("1-Corrientes \n");
    printf("2-Chaco: \n");
    scanf("%d", &llamado.lugarProcedencia);
    fflush(stdin);
}

void visualizarCola()
{
    struct nodo *i = colaLlamadas.primero;

    if (colaVacia())
    {
        printf("No hay elementos en la lista");
    }
    else
    {
        // printf("\n      Cima de la pila\n");
        // printf("      ---------------\n");
        while (i != NULL)
        {
            printf("|     Numero telefonico: %d\nV\n", i->llamado.numTelefono);
            printf("Dirección: %p\n", (void *)i);
            if (i->siguiente != NULL)
            {
                printf("Siguiente: %p\n", (void *)i->siguiente);
                printf("|");
            }
            else
            {
                printf("Siguiente: NULL\n");
            }
            printf("\n");
            i = i->siguiente;
        }
    }
}

void push(datosLlamados _llamado)
{
    struct nodo *nuevoNodo = (cola *)malloc(sizeof(cola));
    nuevoNodo->llamado = _llamado;
    nuevoNodo->siguiente = NULL;

    if (!colaVacia())
    {
        colaLlamadas.ultimo->siguiente = nuevoNodo;
        colaLlamadas.ultimo = nuevoNodo;
    }
    else
    {
        colaLlamadas.primero = nuevoNodo;
        colaLlamadas.ultimo = nuevoNodo;
    }
}

void pop()
{
    if (!colaVacia())
    {
        struct nodo *nodoAEliminar = colaLlamadas.primero;

        if (colaLlamadas.primero == colaLlamadas.ultimo)
        {
            inicializarCola();
        }
        else
        {
            colaLlamadas.primero = colaLlamadas.primero->siguiente;
        }
        free(nodoAEliminar);
        nodoAEliminar = NULL;
    }
    else
    {
        printf("No hay nodos a eliminar\n");
    }
}

bool colaVacia()
{
    return (colaLlamadas.primero == NULL) && (colaLlamadas.ultimo == NULL);
}

void inicializarCola()
{
    colaLlamadas.primero = NULL;
    colaLlamadas.ultimo = NULL;
}

void removerMemoria()
{
    struct nodo *i = colaLlamadas.primero;
    while (i != NULL)
    {
        struct nodo *nodoAEiminar = i;
        i = i->siguiente;
        free(nodoAEiminar);
        nodoAEiminar = NULL;
    }
    printf("Memoria eliminada correctamente\n");
}