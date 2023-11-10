#include <stdio.h>
#include <stdbool.h>
#define N 4

// tipo de dato para el vertice
typedef int tVertice;

// tipo de dato para el arco
typedef struct
{
    tVertice origen;
    tVertice destino;
} tArco;

// tipo de dato para los vertices
typedef bool tConjuntoVertices[N];
// tipo de dato para los arcos
typedef bool tConjuntoArcos[N][N];

// tipo de datos para el grafo
typedef struct
{
    tConjuntoVertices vertices;
    tConjuntoArcos arcos;
} tGrafo;

tGrafo grafoNoPonderado;

// array de Vertices
// array de Arcos

void inicializarGrafo(tGrafo *);
void agregarVertice(tGrafo *, tVertice);
void agregarArco(tGrafo *, tArco);
void visualizarMatriz();

int main()
{

    return 1;
}