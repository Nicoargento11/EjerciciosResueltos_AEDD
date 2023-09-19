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
            insertarElemento(&(*pArbol)->izquierda, pNumero);
        }
        // sino si dato ingresado es mayor al nodo comparado --> izquierda
        else if (pNumero > (*pArbol)->numero)
        {
            insertarElemento(&(*pArbol)->derecha, pNumero);
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
        printf("%d  ", pArbol->numero);
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
        visualizarInOrder(pArbol->izquierda);
        // raiz
        printf("%d  ", pArbol->numero);
        // derecha
        visualizarInOrder(pArbol->derecha);
    }
}
void visualizarPostOrder(tarbol *pArbol)
{
    if (!arbolVacio(pArbol))
    {
        // izquierda
        visualizarPostOrder(pArbol->izquierda);
        // derecha
        visualizarPostOrder(pArbol->derecha);
        // raiz
        printf("%d  ", pArbol->numero);
    }
}

void ingresarDatos()
{
    printf("Ingrese el codigo: ");
    scanf("%d", &numero);
    fflush(stdin);
}