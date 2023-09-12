// Nombre: Nicolas Valdes
// DNI: 45248190
// Comision: 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char string[30];
// estructura producto
typedef struct
{
    int codProducto;
    string descripcion;
    int precioUnitario;

} tProducto;
// estructura nodo
typedef struct nodo
{
    tProducto producto;
    struct nodo *siguiente;
} lista;

// declaracion del primer nodo
lista *miLista;
// declaracion del nuevo producto
tProducto productoNuevo;
int tamaño;

void inicializarNodo();
void agregarNodo(tProducto);
void eliminarPrimerNodo();
void agregarCualquierPos(tProducto, int);
void eliminarCualquierPos(int);
void recorrerNodo(lista *);
void vaciarMemoria();
bool listaVacia();

void ingresarProducto();
void interfaz();

int main()
{
    inicializarNodo();
    interfaz();
    return 1;
}

void interfaz()
{
    int eleccion = 0;
    int pos = 0;
    while (eleccion != -1)
    {
        printf("Que desea hacer \n 1-Agregar producto \n 2-Agregar en cualquier posicion \n 3-eliminar primer producto \n 4-eliminar cualquier producto \n -1 para finalizar\n");
        scanf("%d", &eleccion);
        switch (eleccion)
        {
        case 1:
            ingresarProducto();
            agregarNodo(productoNuevo);
            break;
        case 2:
            printf("Ingresa la posicion: ");
            scanf("%d", &pos);
            ingresarProducto();
            agregarCualquierPos(productoNuevo, pos);
            break;
        case 3:
            eliminarPrimerNodo();
            break;
        case 4:
            printf("Ingresa la posicion: ");
            scanf("%d", &pos);
            fflush(stdin);
            eliminarCualquierPos(pos);
            break;
        default:
            break;
        }
    }
    recorrerNodo(miLista);
    vaciarMemoria();
}

void inicializarNodo()
{
    miLista = NULL;
    tamaño = 0;
}

void agregarNodo(tProducto _producto)
{
    lista *nuevoNodo = (lista *)malloc(sizeof(lista));

    nuevoNodo->producto.codProducto = _producto.codProducto;
    nuevoNodo->producto.precioUnitario = _producto.precioUnitario;
    strcpy(nuevoNodo->producto.descripcion, _producto.descripcion);
    nuevoNodo->siguiente = NULL;
    if (listaVacia())
    {
        miLista = nuevoNodo;
    }
    else
    {
        lista *aux = miLista;
        while (aux->siguiente != NULL)
        {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
    }
    tamaño++;
}

void agregarCualquierPos(tProducto _producto, int _pos)
{
    lista *nuevoNodo = (lista *)malloc(sizeof(lista));

    nuevoNodo->producto.codProducto = _producto.codProducto;
    nuevoNodo->producto.precioUnitario = _producto.precioUnitario;
    strcpy(nuevoNodo->producto.descripcion, _producto.descripcion);
    nuevoNodo->siguiente = NULL;

    if (tamaño < _pos)
    {
        printf("La posicion ingresada no es valida \n");
        return;
    }
    if (listaVacia())
    {
        miLista = nuevoNodo;
        tamaño++;
    }
    else
    {
        lista *anterior = miLista;
        for (int i = 0; i < _pos - 1; i++)
        {
            anterior = anterior->siguiente;
        }
        nuevoNodo->siguiente = anterior->siguiente;
        anterior->siguiente = nuevoNodo;
        tamaño++;
    }
}

void recorrerNodo(lista *_nodo)
{
    lista *i = _nodo;
    if (listaVacia())
    {
        printf("No hay elementos en la lista");
    }
    else
    {

        while (i != NULL)
        {
            printf("|     Codigo:%d\n|     Precio:%d\nV     Descripcion:%s\n", i->producto.codProducto, i->producto.precioUnitario, i->producto.descripcion);
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
        printf("TAMAÑO: %d", tamaño);
    }
}

void eliminarPrimerNodo()
{
    if (listaVacia())
    {
        printf("la lista esta vacia");
        return;
    }
    else
    {
        lista *aux = miLista;
        miLista = miLista->siguiente;
        free(aux);
        tamaño--;
    }
}

void eliminarCualquierPos(int _pos)
{
    if (tamaño < _pos)
    {
        printf("La posicion ingresada no es valida");
        return;
    }
    if (listaVacia() || _pos < 0)
    {
        return;
    }

    if (_pos == 0)
    {
        lista *aux = miLista;
        miLista = miLista->siguiente;
        free(aux);
    }
    else
    {
        lista *anterior = miLista;
        for (int i = 0; i < _pos - 1; i++)
        {
            anterior = anterior->siguiente;
        }
        lista *aux = anterior->siguiente;
        anterior->siguiente = aux->siguiente;
        free(aux);
    }
    tamaño--;
}

void ingresarProducto()
{
    printf("Ingrese el codigo del producto: ");
    scanf("%d", &productoNuevo.codProducto);
    printf("\nIngrese el precio del producto: ");
    scanf("%d", &productoNuevo.precioUnitario);
    printf("\nIngrese la descripcion del producto: \n");
    fflush(stdin);
    scanf("%[^\n]s", &productoNuevo.descripcion);
    fflush(stdin);
}

bool listaVacia()
{
    return miLista == NULL;
}

void vaciarMemoria()
{
    lista *actual = miLista;
    while (actual != NULL)
    {
        lista *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
}