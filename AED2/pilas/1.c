#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef char string[50];

typedef struct
{
    int codProducto;
    int codRubro;
    int cantidad;
    int precio;
    string descripcion;
} datosProducto;

typedef struct nodo
{
    datosProducto producto;
    struct nodo *siguiente;
} pila;

pila *pilaProductos;

datosProducto producto;

void inicializarPila();
void push(datosProducto);
void pop();
bool pilaVacia();
void removerMemoria();
void visualizarPila();

void menu();
void ingresarDatosProducto();
int totalAcumulado();

int main()
{
    inicializarPila();
    menu();
    removerMemoria();
}

void menu()
{
    int opcion = 0;
    while (opcion != -1)
    {
        if (pilaVacia())
        {
            ingresarDatosProducto();
            push(producto);
        }
        else
        {
            printf("Que desea hacer:\n");
            printf("1- Agregar\n");
            printf("2- Eliminar\n");
            printf("3- Ver monto total axumulado\n");
            printf("-1 Finalizar\n");
            scanf("%d", &opcion);
            switch (opcion)
            {
            case 1:
                ingresarDatosProducto();
                push(producto);

                break;
            case 2:
                pop();
                break;
            case 3:
                printf("monto total Acumulado: %d\n", totalAcumulado());
                break;
            case -1:
                printf("Programa finalizado\n");
                break;

            default:
                break;
            }
        }
    }
    visualizarPila();
}

void ingresarDatosProducto()
{
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &producto.codProducto);
    printf("\nIngrese el codigo de rubro: ");
    scanf("%d", &producto.codRubro);
    printf("\nIngrese la cantidad: ");
    scanf("%d", &producto.cantidad);
    printf("\nIngrese el precio unitario: ");
    scanf("%d", &producto.precio);
    fflush(stdin);
    printf("\nIngrese la descripcion del producto: ");
    scanf("%[^\n]s", &producto.descripcion);
    fflush(stdin);
}

int totalAcumulado()
{
    int montoTotal = 0;
    struct nodo *i = pilaProductos;
    while (i != NULL)
    {
        montoTotal += i->producto.precio * i->producto.cantidad;
        i = i->siguiente;
    }

    return montoTotal;
}

bool pilaVacia()
{
    return pilaProductos == NULL;
}

void push(datosProducto _producto)
{
    struct nodo *nuevoNodo = (pila *)malloc(sizeof(pila));
    nuevoNodo->siguiente = NULL;
    nuevoNodo->producto = _producto;

    if (pilaVacia())
    {
        pilaProductos = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = pilaProductos;
        pilaProductos = nuevoNodo;
    }
}

void pop()
{
    if (pilaVacia())
    {
        printf("No hay elementos para eliminar");
    }
    else
    {
        struct nodo *aux = pilaProductos;
        pilaProductos = pilaProductos->siguiente;
        printf("\nProducto eliminado: %s\n", aux->producto.descripcion);
        free(aux);
        aux = NULL;
    }
}

void visualizarPila()
{
    pila *i = pilaProductos;
    if (pilaVacia())
    {
        printf("No hay elementos en la lista");
    }
    else
    {
        printf("\n      Cima de la pila\n");
        printf("      ---------------\n");
        while (i != NULL)
        {
            printf("|     Cantidad:%d\n|     Precio:%d\nV     Descripcion:%s\n", i->producto.cantidad, i->producto.precio, i->producto.descripcion);
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
        // printf("TAMAÑO: %d", contarALumnos());
    }
}

void removerMemoria()
{

    struct nodo *actual = pilaProductos;
    while (actual != NULL)
    {
        struct nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    printf("\nMemoria eliminada correctamente");
}

void inicializarPila()
{
    pilaProductos = NULL;
}