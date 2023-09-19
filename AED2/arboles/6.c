#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef char string[50];
typedef struct nodo
{
    float numero;
    struct nodo *izquierda;
    struct nodo *derecha;
} tArbol;

tArbol *arbol;
int numero;
string leyendaIzquierda = "Es un hijo izquierdo";
string leyendaDerecha = "Es un hijo derecho";
string raiz = "Es un nodo raiz";

void crearArbol(tArbol **);
bool arbolVacio(tArbol *);
void insertarElemento(tArbol **, int, string);
int cantidadNodos(tArbol *);
bool buscarElemento(tArbol *, int);
void visualizarInOrder(tArbol *);
int cantidadNodos();

void ingresarDatos();

int main()
{
    int eleccion = 0;
    crearArbol(&arbol);
    while (eleccion != -1)
    {
        ingresarDatos();
        insertarElemento(&arbol, numero, raiz);
        printf("Desea seguir agregando datos:\n");
        printf("1- si\n");
        printf("-1 no");
        scanf("%d", &eleccion);

        buscarElemento(arbol, 10) ? printf("existe\n") : printf("no existe\n");
    }
    printf("cantidad de nodos %d", cantidadNodos(arbol));
}

void crearArbol(tArbol **pArbol)
{
    *pArbol = NULL;
    printf("Arbol creado\n");
}

bool arbolVacio(tArbol *pArbol)
{
    return pArbol == NULL;
}

void insertarElemento(tArbol **pArbol, int pCodigo, string pLeyenda)
{
    if (arbolVacio(*pArbol))
    {

        (*pArbol) = (tArbol *)malloc(sizeof(tArbol));
        (*pArbol)->derecha = NULL;
        (*pArbol)->izquierda = NULL;
        (*pArbol)->numero = pCodigo;
        printf("%s\n\n", pLeyenda);
    }
    else
    {
        if (pCodigo < (*pArbol)->numero)
        {
            insertarElemento(&(*pArbol)->izquierda, pCodigo, leyendaIzquierda);
        }
        else if (pCodigo > (*pArbol)->numero)
        {
            insertarElemento(&(*pArbol)->derecha, pCodigo, leyendaDerecha);
        }
        else
        {
            printf("El dato ingresado ya se encuentra en el arbol\n");
        }
    }
}

void visualizarInOrder(tArbol *pArbol)
{
    if (!arbolVacio(pArbol))
    {
        visualizarInOrder(pArbol->izquierda);
        printf("%d  ", pArbol->numero);
        visualizarInOrder(pArbol->derecha);
    }
}

int cantidadNodos(tArbol *pArbol)
{
    if (arbolVacio(pArbol))
    {
        return 0;
    }
    else
    {
        return 1 + cantidadNodos(pArbol->izquierda) + cantidadNodos(pArbol->derecha);
    }
}

void ingresarDatos()
{
    printf("Ingrese el codigo: ");
    scanf("%d", &numero);
    fflush(stdin);
}

bool buscarElemento(tArbol *pArbol, int pElemento)
{
    if (arbolVacio(pArbol))
    {
        return false;
    }
    if (pElemento < pArbol->numero)
    {
        buscarElemento(pArbol->izquierda, pElemento);
    }
    else if (pElemento > pArbol->numero)
    {
        buscarElemento(pArbol->derecha, pElemento);
    }
    else
    {
        return true;
    }
}