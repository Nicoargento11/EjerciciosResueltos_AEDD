#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// pop en el inicio, push en el final

// definir un tipo de dato char[50]
typedef char string[50];
// definir registro con los datos del turno:
//  número de turno,
//  nombre del cliente
//  motivo (1. transacción 2. consulta).
typedef struct
{
    int numTurno;
    string nombre;
    int motivo;
} datosCliente;

// estructura del nodo
typedef struct nodo
{
    datosCliente cliente;
    struct nodo *siguiente;
} cola;

// declarar la cola
struct
{
    struct nodo *primero;
    struct nodo *ultimo;

} colaClientes;

// declarar variable datosClientes
datosCliente cliente;

// funciones a utilizar:
//   - Menu
void menu();
//   - ingresarDatos
void ingresarDatos();
//   - inicializarCola
void inicializarCola();
//   - colaVacia
bool colaVacia();
//   - vaciarMemoria
void vaciarMemoria();
//   - push
void push(datosCliente);
//   - pop
void pop();
//   - cantTransaccion
int cantTransaccion();
//   - cantConsulta
int cantConsulta();
//   - visualizarCola
void visualizarCola();
int main()
{
    inicializarCola();
    menu();
    vaciarMemoria();
    return 1;
}

void menu()
{
    int opcion = 0;
    while (opcion != -1)
    {
        if (colaVacia())
        {
            ingresarDatos();
            push(cliente);
        }
        else
        {
            printf("\nQue desea hacer:\n");
            printf("1- Push: \n");
            printf("2- Pop: \n");
            printf("3- Cantidad de transacciones: \n");
            printf("4- Cantidad de consultas: \n");
            printf("5- Visualizar cola: \n");
            printf("-1 Finalizar: \n");
            scanf("%d", &opcion);
            switch (opcion)
            {
            case 1:
                ingresarDatos();
                push(cliente);
                break;
            case 2:
                pop();
                break;
            case 3:
                cantTransaccion();
                break;
            case 4:
                cantConsulta();
                break;
            case 5:
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

void ingresarDatos()
{
    printf("Ingrese su numero de turno: \n");
    scanf("%d", &cliente.numTurno);
    fflush(stdin);
    printf("Ingrese su nombre: ");
    scanf("%s", &cliente.nombre);
    printf("\nIngrese su motivo: ");
    printf("\n1- Transaccion: ");
    printf("\n2- consulta:\n");
    scanf("%d", &cliente.motivo);
    fflush(stdin);
}

void inicializarCola()
{
    colaClientes.primero = NULL;
    colaClientes.ultimo = NULL;
}

bool colaVacia()
{
    return (colaClientes.primero == NULL) && (colaClientes.ultimo == NULL);
}

void push(datosCliente _cliente)
{
    // pop en el inicio, push en el final

    struct nodo *nuevoNodo = (cola *)malloc(sizeof(cola));
    nuevoNodo->siguiente = NULL;
    nuevoNodo->cliente = _cliente;

    if (colaVacia())
    {
        colaClientes.primero = nuevoNodo;
        colaClientes.ultimo = nuevoNodo;
    }
    else
    {
        colaClientes.ultimo->siguiente = nuevoNodo;
        colaClientes.ultimo = nuevoNodo;
    }
}

void pop()
{
    // pop en el inicio, push en el final
    struct nodo *nodoAEliminar = colaClientes.primero;

    if (!colaVacia())
    {
        if (colaClientes.primero == colaClientes.ultimo)
        {
            inicializarCola();
        }
        else
        {
            colaClientes.primero = colaClientes.primero->siguiente;
        }
        free(nodoAEliminar);
        nodoAEliminar = NULL;
    }
    else
    {
        printf("La lista ya se encuentra vacia\n");
    }
}
void visualizarCola()
{
    struct nodo *i = colaClientes.primero;

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
            printf("|     Nombre:%s\n|     Turno:%d\nV     Motivo:%d\n", i->cliente.nombre, i->cliente.numTurno, i->cliente.motivo);
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

void vaciarMemoria()
{
    struct nodo *i = colaClientes.primero;
    while (i != NULL)
    {
        struct nodo *nodoAEiminar = i;
        i = i->siguiente;
        free(nodoAEiminar);
        nodoAEiminar = NULL;
    }
    printf("Memoria eliminada correctamente\n");
}

int cantTransaccion()
{
    int contador = 0;
    struct nodo *i = colaClientes.primero;
    while (i != NULL)
    {
        if (i->cliente.motivo == 1)
        {
            contador++;
        }
        i = i->siguiente;
    }
    printf("La cantidad de transacciones es de: %d", contador);
    return contador;
}

int cantConsulta()
{
    int contador = 0;
    struct nodo *i = colaClientes.primero;
    while (i != NULL)
    {
        if (i->cliente.motivo == 2)
        {
            contador++;
        }
        i = i->siguiente;
    }
    printf("La cantidad de consultas es de: %d", contador);
    return contador;
}