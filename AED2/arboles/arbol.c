#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
typedef char tstring[25];

typedef struct nodo
{
    int numero;
    struct nodo *izquierda;
    struct nodo *derecha;
} tarbol;

tarbol *arbol;
int numero;

void crearArbol(tarbol **);
bool arbolVacio();
void insertarElemento(tarbol **, int);
void visualizarPreOrder(tarbol *);
void visualizarPostOrder(tarbol *);
void visualizarInOrder(tarbol *);
int cantidadNodos(tarbol *);
bool buscarElemento(tarbol *, int);

void eliminarElemento(tarbol **, int);
tarbol *buscarMin(tarbol *);

void ingresarDatos();
int main()
{
    int eleccion = 0;
    crearArbol(&arbol);
    while (eleccion != -1)
    {
        ingresarDatos();
        insertarElemento(&arbol, numero); // siempre con &
        printf("Desea seguir agregando datos:\n");
        printf("1- si\n");
        printf("-1 no");
        scanf("%d", &eleccion);
    }
    visualizarPreOrder(arbol);
    printf("\n");
    visualizarInOrder(arbol);
    printf("\n");
    visualizarPostOrder(arbol);
    printf("\n");

    return 1;
}

void crearArbol(tarbol **parbol)
{
    // crear arbol
    *parbol = NULL;
    printf("Arbol inicializado!\n");
}

bool arbolVacio(tarbol *pArbol)
{
    return pArbol == NULL;
}

void insertarElemento(tarbol **pArbol, int pNumero)
{
    // creamos el nodo para insertar al arbol
    // al llegar al nodo vacio, insertamos el nodo
    if (arbolVacio(*pArbol))
    {
        (*pArbol) = (tarbol *)malloc(sizeof(tarbol));
        if (*pArbol == NULL)
        {
            printf("No hay espacio suficiente");
        }
        else
        {
            (*pArbol)->numero = pNumero;
            (*pArbol)->izquierda = NULL;
            (*pArbol)->derecha = NULL;
        }
    }
    else
    {
        // si el dato ingresado es menor al nodo comparado --> derecha
        if (pNumero < (*pArbol)->numero)
        {
            insertarElemento(&(*pArbol)->derecha, pNumero);
        }
        // sino si dato ingresado es mayor al nodo comparado --> izquierda
        else if (pNumero > (*pArbol)->numero)
        {
            insertarElemento(&(*pArbol)->izquierda, pNumero);
        }
        else
        // el elemento a ingresar ya existe en el arbol
        {
            printf("No se puede insertar elementos duplicados\n");
        }
    }
}
void visualizarPreOrder(tarbol *pArbol)
{
    if (!arbolVacio(pArbol))
    {
        // raiz
        printf("%d - %s   ", pArbol->numero, pArbol->numero);
        // izquierda
        visualizarPreOrder(pArbol->izquierda);
        // derecha
        visualizarPreOrder(pArbol->derecha);
    }
}

void visualizarInOrder(tarbol *pArbol)
{
    if (!arbolVacio(pArbol))
    {
        // izquierda
        visualizarPreOrder(pArbol->izquierda);
        // raiz
        printf("%d - %s  ", pArbol->numero, pArbol->numero);
        // derecha
        visualizarPreOrder(pArbol->derecha);
    }
}
void visualizarPostOrder(tarbol *pArbol)
{
    if (!arbolVacio(pArbol))
    {
        // izquierda
        visualizarPreOrder(pArbol->izquierda);
        // derecha
        visualizarPreOrder(pArbol->derecha);
        // raiz
        printf("%d - %s  ", pArbol->numero, pArbol->numero);
    }
}

int cantidadNodos(tarbol *pArbol)
{
    if (!arbolVacio(pArbol))
    {
        // sumo 1 x cada nodo distinto de vacio
        return 1 + cantidadNodos(pArbol->derecha) + cantidadNodos(pArbol->izquierda);
    }
    else
    {
        // no sumpo nada si esta vacio
        return 0;
    }
}

bool buscarElemento(tarbol *pArbol, int pNumero)
{
    if (arbolVacio(pArbol))
    {
        return false;
    }
    // si el dato a buscar es menor al nodo comparado --> derecha
    else if (pNumero < pArbol->numero)
    {
        buscarElemento(pArbol->derecha, pNumero);
    }
    // sino si el dato a buscar es mayor al nodo comparado --> izquierda
    else if (pNumero > pArbol->numero)
    {
        buscarElemento(pArbol->izquierda, pNumero);
    }
    else
    {
        return true;
    }
}

void eliminarElemento(tarbol **pArbol, int pCodigo)
{
    tarbol *aux;
    if (arbolVacio(*pArbol))
    {
        printf("No existe el elemento a eliminar\n");
    }
    else if (pCodigo < (*pArbol)->numero)
    {
        eliminarElemento(&(*pArbol)->izquierda, pCodigo);
    }
    else if (pCodigo > (*pArbol)->numero)
    {
        eliminarElemento(&(*pArbol)->derecha, pCodigo);
    }
    else
    {
        if ((*pArbol)->derecha == NULL)
        {
            aux = *pArbol;
            *pArbol = (*pArbol)->izquierda;
            free(aux);
        }
        else if ((*pArbol)->izquierda == NULL)
        {
            aux = *pArbol;
            *pArbol = (*pArbol)->derecha;
            free(aux);
        }
        else
        {
            aux = buscarMin((*pArbol)->derecha);
            (*pArbol)->numero = aux->numero;
            eliminarElemento(&((*pArbol)->derecha), (*pArbol)->numero);
        }
    }
}

tarbol *buscarMin(tarbol *pArbol)
{
    if (arbolVacio(pArbol))
    {
        return NULL;
    }
    else if (!arbolVacio(pArbol->izquierda))
    {
        return buscarMin(pArbol->izquierda);
    }
    else
    {
        return pArbol;
    }
}

void ingresarDatos()
{
    printf("Ingrese el codigo: ");
    scanf("%d", &numero);
    fflush(stdin);
    printf("Ingrese la descripcion: ");
    scanf("%[^\n]s", &numero);
    fflush(stdin);
}