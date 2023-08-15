#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[20];
typedef struct nodo
{
    struct nodo *siguiente;
    string nombre;
} nodo;

nodo *primer = NULL;
nodo *ultimo = NULL;
int tamaño = 0;
void AgregarFinal(nodo *);
void RecorrerNodo(nodo *);
void AgregarInicio(nodo *);
void AgregarCualquierPosicion(nodo *, int);
void EliminarNodoInicio();
void EliminarNodoFinal();
int main()
{
    nodo *primerNodo = (nodo *)malloc(sizeof(nodo));
    strcpy(primerNodo->nombre, "Nodo 1");
    nodo *segundoNodo = (nodo *)malloc(sizeof(nodo));
    strcpy(segundoNodo->nombre, "Nodo 2");
    nodo *tercerNodo = (nodo *)malloc(sizeof(nodo));
    strcpy(tercerNodo->nombre, "Nodo 3");
    nodo *cuartoNodo = (nodo *)malloc(sizeof(nodo));
    strcpy(cuartoNodo->nombre, "Nodo 4");
    nodo *quintoNodo = (nodo *)malloc(sizeof(nodo));
    strcpy(quintoNodo->nombre, "Nodo 5");

    AgregarFinal(primerNodo);
    AgregarFinal(segundoNodo);
    AgregarFinal(tercerNodo);
    AgregarCualquierPosicion(cuartoNodo, 1);
    AgregarInicio(quintoNodo);
    EliminarNodoInicio();
    EliminarNodoFinal();
    RecorrerNodo(primer);

    nodo *actual = primer;
    while (actual != NULL)
    {
        nodo *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    return 0;
}

void AgregarFinal(nodo *_nodo)
{
    _nodo->siguiente = NULL;
    if (primer == NULL)
    {
        primer = _nodo;
        ultimo = _nodo;
    }
    else
    {
        ultimo->siguiente = _nodo;
        ultimo = _nodo;
    }
    tamaño++;
}

void AgregarInicio(nodo *_nodo)
{
    _nodo->siguiente = NULL;
    if (primer == NULL)
    {
        primer = _nodo;
        ultimo = _nodo;
    }
    else
    {
        _nodo->siguiente = primer;
        primer = _nodo;
    }
    tamaño++;
}

void AgregarCualquierPosicion(nodo *_nodo, int _pos)
{
    _nodo->siguiente = NULL;
    if (tamaño < _pos)
        return;
    if (_pos == 0 && primer == NULL)
    {
        primer = _nodo;
        ultimo = _nodo;
    }
    else if (_pos == 0)
    {
        _nodo->siguiente = primer;
        primer = _nodo;
    }
    else
    {
        nodo *anterior = primer;
        for (int i = 0; i < _pos - 1; i++)
        {
            anterior = anterior->siguiente;
        }
        _nodo->siguiente = anterior->siguiente;
        anterior->siguiente = _nodo;
    }
    tamaño++;
}

void EliminarNodoInicio()

{
    nodo *nodoAEliminar;
    if (primer == NULL)
    {
        return;
    }
    else
    {
        nodoAEliminar = primer;
        primer = primer->siguiente;
    }
    free(nodoAEliminar);
    tamaño--;
}

void EliminarNodoFinal()
{
    if (primer == NULL)
    {
        return;
    }
    else if (primer->siguiente == NULL) // Si solo hay un nodo en la lista
    {
        free(primer);
        primer = NULL;
        ultimo = NULL;
    }
    else
    {
        nodo *anterior = primer;
        while (anterior->siguiente != ultimo)
        {
            anterior = anterior->siguiente;
        }

        free(ultimo);
        ultimo = anterior;
        ultimo->siguiente = NULL;
        tamaño--;
    }
}
void RecorrerNodo(nodo *_nodo)
{
    nodo *i = _nodo;
    while (i != NULL)
    {
        printf("Nombre: %s   v\n", i->nombre);
        printf("Dirección: %p\n", (void *)i);
        if (i->siguiente != NULL)
        {
            printf("Siguiente: %p\n", (void *)i->siguiente);
            printf("                 |");
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