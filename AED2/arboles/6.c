#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct nodo
{
    float numero;
    struct nodo *izquierda;
    struct nodo *derecha;
} tArbol;

tArbol *arbol;
int numero;

void crearArbol(tArbol **);
bool arbolVacio(tArbol *);
void insertarElemento(tArbol **, int);
int cantidadNodos(tArbol *);
void visualizarInOrder(tArbol *);

int main()
{
}

void crearArbol(tArbol **pArbol)
{
    (*pArbol) = NULL;
    printf("Arbol creado");
}

bool arbolVacio(tArbol *pArbol)
{
    return pArbol == NULL;
}

void insertarElemento(tArbol **pArbol, int pNumero)
{
    if (arbolVacio(*pArbol))
    {
        (*pArbol) = (tArbol *)malloc(sizeof(tArbol));
        (*pArbol)->derecha = NULL;
        (*pArbol)->izquierda = NULL;
        (*pArbol)->numero = pNumero;
    }
    else
    {
        if (pNumero < (*pArbol)->numero)
        {
            insertarElemento((*pArbol)->izquierda, pNumero);
        }
        else if (pNumero > (*pArbol)->numero)
        {
            insertarElemento((*pArbol)->derecha, pNumero);
        }
        else
        {
            printf("El dato ya existe en el arbol\n");
        }
    }
}

int cantidadNodos(tArbol *pArbol)
{
    if (!arbolVacio(pArbol))
    {
        return 1 + cantidadNodos(pArbol->derecha) + cantidadNodos(pArbol->izquierda);
    }
    else
    {
        return 0;
    }
}