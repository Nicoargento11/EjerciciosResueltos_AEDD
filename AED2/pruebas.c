// tGrafoPonderado ,  peso = tipo de dato compuesto
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 5

// Declaración de tipos de datos personalizados
typedef int tVertice;

typedef struct
{
    float com; // combustible en litros
    float dis; // distancia en km
} tPeso;

typedef struct
{
    tVertice origen;
    tVertice destino;
    tPeso peso;
} tArco;

typedef bool conjuntoVertices[N];
typedef tPeso conjuntoArcos[N][N];

typedef struct
{
    conjuntoVertices vertices;
    conjuntoArcos arcos;
} tGrafoPonderado;

// Declaración de prototipos de funciones
void inicializarGrafo(tGrafoPonderado *);
void ingresarVertice(tGrafoPonderado *, tVertice);
void ingreesarArco(tGrafoPonderado *, tArco *);

void eliminarVertice(tGrafoPonderado *, tVertice);
void eliminarArco(tGrafoPonderado *, tArco);

int maximoVertice(tGrafoPonderado);
void visualizarMatrizAdyacencia(tGrafoPonderado);
void visualizarMatrizPesos(tGrafoPonderado);
bool existeVertice(tGrafoPonderado, tVertice);

// Declaración de Variables Globales
tArco arco;
tGrafoPonderado grafo;

int main()
{
    inicializarGrafo(&grafo);
    ingresarVertice(&grafo, 1);
    ingresarVertice(&grafo, 2);
    ingresarVertice(&grafo, 3);
    ingresarVertice(&grafo, 4);

    arco.origen = 1;
    arco.destino = 2;
    arco.peso.com = 12.3;
    arco.peso.dis = 19.8;
    ingreesarArco(&grafo, &arco);

    arco.origen = 3;
    arco.destino = 1;
    arco.peso.com = 11.3;
    arco.peso.dis = 18.6;
    ingreesarArco(&grafo, &arco);

    visualizarMatrizAdyacencia(grafo);
    visualizarMatrizPesos(grafo);

    eliminarVertice(&grafo, 4);

    arco.origen = 3;
    arco.destino = 2;
    eliminarArco(&grafo, arco);

    visualizarMatrizAdyacencia(grafo);
    visualizarMatrizPesos(grafo);

    return 0;
}

// Implementación de la funciones
void inicializarGrafo(tGrafoPonderado *pGrafo)
{
    int x, y;
    for (x = 0; x <= N; x++)
    {
        pGrafo->vertices[x] = 0.0;
        for (y = 0; y <= N; y++)
        {
            pGrafo->arcos[x][y].com = 0.0;
            pGrafo->arcos[x][y].dis = 0.0;
        }
    }
}

void ingresarVertice(tGrafoPonderado *pGrafo, tVertice pVertice)
{
    if (pVertice < N)
    {
        pGrafo->vertices[pVertice] = true;
        printf("Vertice %d Habilitado \n", pVertice);
    }
    else
    {
        printf("Vertice invalido \n");
    }
}

void ingreesarArco(tGrafoPonderado *pGrafo, tArco *pArco)
{
    if (pGrafo->vertices[pArco->origen] == true && pGrafo->vertices[pArco->destino] == true)
    {
        pGrafo->arcos[pArco->origen][pArco->destino] = pArco->peso;
    }
}

void eliminarVertice(tGrafoPonderado *pGrafo, tVertice pVertice)
{
    bool existeV = false;
    existeV = existeVertice(*pGrafo, pVertice);

    if (existeV == true)
    {
        pGrafo->vertices[pVertice] = false;
        printf("El Vertice %d desabilitado", pVertice);
    }
    else
    {
        printf("Vertice no existente \n");
    }
}

void eliminarArco(tGrafoPonderado *pGrafo, tArco pArco)
{
    if (pGrafo->arcos[pArco.origen][pArco.destino].com != 0.0 &&
        pGrafo->arcos[pArco.origen][pArco.destino].dis)
    {
        pGrafo->arcos[pArco.origen][pArco.destino].com = 0.0;
        pGrafo->arcos[pArco.origen][pArco.destino].dis = 0.0;
        printf("El Arco [%d, %d] DESABILITADO \n", pArco.origen, pArco.destino);
    }
    else
    {
        printf("Arco no existente! \n");
    }
}

int maximoVertice(tGrafoPonderado pGrafo)
{
    int x, maxV;
    maxV = 0;

    for (x = 0; x < N; x++)
    {
        if (pGrafo.vertices[x] == 1)
        { // si es igual a true "veradero"
            maxV = x;
        }
    }
    return maxV;
}

void visualizarMatrizAdyacencia(tGrafoPonderado pGrafo)
{
    int x, y, maxV;
    maxV = maximoVertice(pGrafo);
    bool existe = false;

    for (x = 1; x <= maxV; x++)
    {
        for (y = 1; y <= maxV; y++)
        {
            existe = (pGrafo.arcos[x][y].com != 0.0 && pGrafo.arcos[x][y].dis != 0.0) && existeVertice(pGrafo, x) && existeVertice(pGrafo, y);

            if (existe == true)
            {
                printf("1 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void visualizarMatrizPesos(tGrafoPonderado pGrafo)
{
    int x, y, maxV;
    maxV = maximoVertice(pGrafo);
    bool existe = false;

    for (x = 1; x <= maxV; x++)
    {
        for (y = 1; y <= maxV; y++)
        {
            existe = (pGrafo.arcos[x][y].com != 0.0 && pGrafo.arcos[x][y].dis != 0.0) && existeVertice(pGrafo, x) && existeVertice(pGrafo, y);

            if (existe == true)
            {
                printf("(%.2f lts, %.2f km) ", pGrafo.arcos[x][y].com, pGrafo.arcos[x][y].dis);
            }
            else
            {
                printf("00.00 ");
            }
        }
        printf("\n");
    }
}

bool existeVertice(tGrafoPonderado pGrafo, tVertice pVertice)
{
    return pGrafo.vertices[pVertice] == true;
}