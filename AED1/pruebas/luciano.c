#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Declaracion de tipo de dato personalizado
typedef char cadena[25];

// Declaracion de estructura Compuesta
typedef struct
{
    int codProducto;
    cadena descripcion;
    float precio;
} tProducto;

typedef struct nodo
{
    tProducto lProducto;
    struct nodo *siguiente;
} tLista;

// Prototipos
void inicializarLista(tLista *);
void ingresarProducto();
void mostrarProductos();

void insertarElemento(tProducto);
bool listaVacia(tLista *);
void crearPrimerNodo(tProducto);
void crearSiguienteNodo(tProducto);
void visualizarElementos(tLista *);
void eliminarPrimero(tLista *);
int contarNodos(tLista *);
void insertarK();

// Variables
tProducto producto;
int finalizar = 3;
int contador = 0;
// Creamos una variable de tipo puntero a Estructura. Seria crear una lista
tLista *lista;

int main()
{
    inicializarLista(lista);

    while (finalizar != 2)
    {
        printf("\nDesea ingresar Datos SI) 1   NO) 2 \n");
        scanf("%d", &finalizar);

        if (finalizar != 2)
        {
            ingresarProducto();
            insertarElemento(producto);
            mostrarProductos();
        }
    }
    visualizarElementos(lista);
    eliminarPrimero(lista);
    visualizarElementos(lista);
    contarNodos(lista);

    return 0;
}

// Funciones
void inicializarLista(tLista *lista)
{
    lista = NULL;
    printf("Inicializamos Lista \n");
}
void ingresarProducto()
{
    printf("\nIngrese el codigo del producto \n");
    scanf("%d", &producto.codProducto);
    fflush(stdin);

    printf("Ingrese la descripcion del producto \n");
    scanf("%[^\n]s", &producto.descripcion);
    fflush(stdin);

    printf("Ingrese el precio del producto \n");
    scanf("%f", &producto.precio);
    fflush(stdin);
}
void mostrarProductos()
{
    printf("\n Codigo: %d    Descripcion: %s   Precio: %.2f \n", producto.codProducto, producto.descripcion, producto.precio);
}
void insertarElemento(tProducto pElemento)
{
    if (listaVacia(lista))
    {
        crearPrimerNodo(pElemento);
    }
    else
    {
        crearSiguienteNodo(pElemento);
    }
}
bool listaVacia(tLista *lista)
{
    return lista == NULL;
}
void crearPrimerNodo(tProducto pElemento)
{
    // Creamos un nuevo nodo
    tLista *nuevoNodo;

    // Asignamos un espacio de memoria para el nuevo nodo
    nuevoNodo = (tLista *)malloc(sizeof(tLista));

    /* al nuevoNodo , Se  le asigna al dato recibido (lProducto) el componente corespondiente a
    tProducto (la variable de tipo tProducto "pElemento") */
    nuevoNodo->lProducto = pElemento;

    // Se indica que el primer nodo apunta a NULL
    nuevoNodo->siguiente = NULL;

    // nuevoNodo punta a lista
    lista = nuevoNodo;

    // lista es igual a nuevoNodo ; lo que quiere decir que nuevoNodo pisa a lista y hora es el  primer elemento
    printf("Primer Elemento insertado \n");
}
void crearSiguienteNodo(tProducto pElemento)
{
    // Creamos nuevamente un nuevo nodo
    tLista *nuevoNodo;

    // Almacenamos un espacio de memoria para el nuevo nodo
    nuevoNodo = (tLista *)malloc(sizeof(tLista));

    /* al nuevoNodo , Se  le asigna al dato recibido (lProducto) el componente corespondiente a
tProducto (la variable de tipo tProducto "pElemento") */
    nuevoNodo->lProducto = pElemento;
    // El 2 do nodo apunta a NULL
    nuevoNodo->siguiente = NULL;

    // El nuevo nodo apunta a lista
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
    printf("Elemento insertado \n");
}
void visualizarElementos(tLista *pLista)
{
    if (listaVacia(pLista))
    {
        printf("\nNo hay elementos para visualizar\n");
        return;
    }

    printf("\nElementos de la lista:\n");
    tLista *aux = pLista;
    while (aux != NULL)
    {
        printf("Codigo: %d  Descripcion: %s  Precio: %.2f\n", aux->lProducto.codProducto, aux->lProducto.descripcion, aux->lProducto.precio);
        aux = aux->siguiente;
    }
}
void eliminarPrimero(tLista *plista)
{
    tLista *aux = plista; // Guardamos el primer nodo en aux
    if (plista != NULL)
    {
        plista = plista->siguiente; // Actualizamos lista para que apunte al siguiente nodo
        free(aux);                  // Liberamos memoria
        printf("Se ha eliminado el primer elemento\n");
    }
    else
    {
        printf("La lista está vacía, no se puede eliminar.\n");
    }
}

int contarNodos(tLista *lista)
{
    tLista *aux;
    aux = lista;

    if (aux != NULL)
    {
        contador++;
        aux = aux->siguiente;
    }
    return contador;
}