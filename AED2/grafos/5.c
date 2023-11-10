#include <stdio.h>
#include <stdbool.h>
#define N 4

typedef int tVertice;

typedef struct
{
    tVertice origen;
    tVertice destino;
} tArco;

typedef bool conjuntoVertices[N];
// [ 0, 0, 0, 0 ];
typedef bool conjuntoArcos[N][N];
// [
//     [ 0, 0, 0, 0 ],
//     [ 0, 0, 0, 0 ],
//     [ 0, 0, 0, 0 ],
//     [ 0, 0, 0, 0 ],
// ]

typedef struct
{
    conjuntoVertices vertices;
    conjuntoArcos arcos;
} tGrafo;

void inicializarGrafo(tGrafo *);
void agregarVertice(tGrafo *, tVertice);
void agregarArco(tGrafo *, tArco);
void eliminarVertice(tGrafo *, tVertice);
void eliminarArco(tGrafo *, tArco);

int maximoVertice(tGrafo);
void visualizarMatrizAdyacencia(tGrafo);
bool existeVertice(tGrafo, tVertice);
void menu();

tGrafo grafoNoPonderado;
tArco arco;

int main()
{
    menu();

    return 1;
}

void menu()
{
    int fin = 0;
    int vertice = 0;

    while (fin != -1)
    {
        while (fin != -1)
        {

            printf("Ingresa un vertice\n");
            scanf("%d", &vertice);
            agregarVertice(&grafoNoPonderado, vertice);
            printf("Desea seguir agregando:\n");
            printf("1- si");
            printf("-1 no\n");
            scanf("%d", &fin);
        }
        fin = 0;
        printf("Ingresa el origen del Arco\n");
        scanf("%d", &arco.origen);
        printf("Ingresa el destino del Arco\n");
        scanf("%d", &arco.destino);
        agregarArco(&grafoNoPonderado, arco);
        printf("Desea seguir agregando:\n");
        printf("1- si");
        printf("-1 no\n");
        scanf("%d", &fin);
    }
}

void inicializarGrafo(tGrafo *pGrafo)
{
    for (int i = 0; i < N; i++)
    {
        // inicializar la matriz de vertices
        pGrafo->vertices[i] = 0;
        for (int j = 0; j < N; j++)
        {
            // inicializar la matriz de arcos (M de adyacencia)
            pGrafo->arcos[i][j] = 0;
        }
    }
}

void agregarVertice(tGrafo *pGrafo, tVertice pVertice)
{
    // agrego en la matriz de vertices
    pGrafo->vertices[pVertice] = 1;
}

void agregarArco(tGrafo *pGrafo, tArco pArco)
{
    // Verificar que existan los vertices
    if (pGrafo->vertices[pArco.origen] == 1 && pGrafo->vertices[pArco.destino] == 1)
    {
        // agregar en la matriz
        (*pGrafo).arcos[pArco.origen][pArco.destino] = 1;
    }
    else
    {
        printf("No existe alguno de los vertices\n");
    }
    // no existe alguno de los vertices
}

void borrarVertice(tGrafo *tGrafo, tVertice pVertice)
{
    // verifico que exista
    if (tGrafo->vertices[pVertice] != 0)
    {
        // borro el vertice
        (*tGrafo).vertices[pVertice] = 0;
    }
    else
    {
        // no existe el vertice
        printf("No existe el vertice");
    }
}

void borrarArco(tGrafo *pGrafo, tArco pArco)
{
    // verifico que exista
    if (pGrafo->arcos[pArco.origen][pArco.destino] != 0)
    {
        // borro el arco
        (*pGrafo).arcos[pArco.origen][pArco.destino] = 0;
    }
    else
    {
        //  no existe el arco
        printf("No existe el arco");
    }
}

int maximoVertice(tGrafo pGrafo)
{
    // verifico cual es el vertice mas grande
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        if (pGrafo.vertices[i] == 1)
        {
            max = i;
        }
    }
    return max;
}

bool existeVertice(tGrafo pGrafo, tVertice pVertice)
{
    return pGrafo.vertices[pVertice] == 1;
}

void visualizarMatrizAdyacencia(tGrafo pGrafo)
{
    bool existeArista = false;

    int maxVer = maximoVertice(pGrafo);

    for (int i = 1; i <= maxVer; i++)
    {
        for (int j = 1; j <= maxVer; j++)
        {
            existeArista = (pGrafo.arcos[j][i] == 1) &&
                           existeVertice(pGrafo, i) &&
                           existeVertice(pGrafo, j);
            if (existeArista)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
}
