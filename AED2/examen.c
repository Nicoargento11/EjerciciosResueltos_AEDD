#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 15

typedef int tvertice;

typedef struct
{
    float km;
    float combustible;
} tpesoArco;

typedef struct
{

    tvertice origen;
    tvertice destino;
    tpesoArco peso
} tArco;

typedef struct
{
    bool vertice[MAX];
    tpesoArco Arco[MAX][MAX];
} tGrafo;

tGrafo grafo;
tArco auxArco;
tvertice auxVertice;

void inicializarGrafo(tGrafo *pGrafo)
{
    for (int i = 0; i < MAX; i++)
    {
        pGrafo->vertice[i] = 0;
        for (int j = 0; j < MAX; j++)
        {
            pGrafo->Arco[i][j].km = 0;
            pGrafo->Arco[i][j].combustible = 0;
        }
    }
}

void agregarVertice(tGrafo *pGrafo, tvertice pVertice)
{
    pGrafo->vertice[pVertice] = true;
}

void agregarArco(tGrafo *pGrafo, tArco pArco)
{
    if (pGrafo->vertice[pArco.origen] && pGrafo->vertice[pArco.destino])
    {
        pGrafo->Arco[pArco.origen][pArco.destino].km = pArco.peso.km;
        pGrafo->Arco[pArco.origen][pArco.destino].combustible = pArco.peso.combustible;
    }
    else
    {
        printf("los vertices ingresados no existen");
    }
}

void borrarVertice(tGrafo *pGrafo, tvertice pVertice)
{
    if (pGrafo->vertice[pVertice])
    {
        pGrafo->vertice[pVertice] = 0;
    }
    else
    {
        printf("no existe papa");
    }
}

void borrarArco(tGrafo *pGrafo, tArco pArco)
{
    if (pGrafo->Arco[pArco.origen][pArco.destino].combustible && pGrafo->Arco[pArco.origen][pArco.destino].km)
    {
        pGrafo->Arco[pArco.origen][pArco.destino].km = 0;
        pGrafo->Arco[pArco.origen][pArco.destino].combustible = 0;
    }
    else
    {
        printf("no existe el arco");
    }
}

int maximoVertice(tGrafo pGrafo)
{
    int max = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (pGrafo.vertice[i])
        {
            max = i;
        }
    }
    return max;
}

bool existeVertice(tGrafo pGrafo, tvertice pVertice)
{
    return pGrafo.vertice[pVertice] == 1;
}

void visualizarGrafo(tGrafo pGrafo, char opcion)
{
    bool existeArco = false;
    int maxVertice = maximoVertice(grafo);

    for (int i = 0; i < maximoVertice; i++)
    {
        for (int j = 0; j < maximoVertice; j++)
        {
            existeArco = pGrafo.Arco[i][j].combustible && pGrafo.Arco[i][j].km && existeVertice(pGrafo, i) &&
                         existeVertice(pGrafo, j);
            if (existeArco)
            {
                opcion == 'p' ? printf("%.2f, %.2f", pGrafo.Arco[i][j].km, pGrafo.Arco[i][j].combustible)
                              : printf("1");
            }
            else
            {
                printf("0");
            }
        }
    }
    printf("\n");
}