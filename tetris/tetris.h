// archivo que manejan la logica del tetris

#ifndef TETRIS_H
#define TETRIS_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

// codigo ASCII
#define ESC 27

// velocidad del juego
#define INTERVALO_MOVIMIENTO 500

// Caracteres escenario:
#define ESQ_SD 187
#define ESQ_SI 201
#define ESQ_II 200
#define ESQ_ID 188
#define LINEA_H 205
#define LINEA_V 186

#define TABLERO_ANCHO 15
#define TABLERO_LARGO 20
#define MARGEN_V 5
#define MARGEN_H 5
#define FICHA_SIZE 4
#define PIEZA 219

// DEFINICION DE ESTRUCTURAS
typedef struct
{
    int x, y;
} coord;

typedef struct
{
    coord piezaFija;
    coord movibles[3];
    int color;
} tPieza;

typedef struct
{
    int coord;
    int color;
} tDatoTablero;

typedef tDatoTablero tTablero[TABLERO_LARGO][TABLERO_ANCHO];

// DEFINICION DE PROTOTIPOS

void inicializarTablero();
void imprimirEscenario();
void gotoxy(int x, int y);
coord funcionCoordenadas(tPieza *pPieza, int n);

void piezaNueva(tPieza *pPieza, int *pColors);
void pintarPieza(tPieza *pPieza);
void pintarCuadrado(int x, int y);

bool colision(tPieza *);
void colocarPieza();
int tableroContarLineas();
bool tableroFilaLLena(int pFila);
void tableroColapsa(int pFila);
int calcularPuntuacion();

void rotarPieza();
coord rotarDerecha(coord);

// variables del main
extern tTablero tablero;
extern tPieza pieza;
extern int resultado;

// permite posicionarse en cualquier parte de la consola
void gotoxy(int x, int y)
{
    printf("%c[%d;%dH", ESC, y, x);
}

void inicializarTablero()
{
    int i;
    for (i = 0; i < TABLERO_LARGO; i++)
    {
        int j;
        for (j = 0; j < TABLERO_ANCHO; j++)
        {
            tablero[i][j].coord = 0;
        }
    }
}

void imprimirEscenario()
{
    char c;
    int i;
    // recorrido del tablero (matriz)
    for (i = 1; i <= TABLERO_LARGO + 2; i++)
    {
        int j;
        for (j = 1; j <= TABLERO_ANCHO + 2; j++)
        {
            // posicionar
            gotoxy(MARGEN_H + j, MARGEN_V + i);

            switch (i)
            {
            case 1:
                // fila superior
                c = j == 1 ? ESQ_SI : j == TABLERO_ANCHO + 2 ? ESQ_SD
                                                             : LINEA_H;
                break;
            case TABLERO_LARGO + 2:
                // fila inferior
                c = j == 1 ? ESQ_II : j == TABLERO_ANCHO + 2 ? ESQ_ID
                                                             : LINEA_H;
                break;
            default:
                // filas del medio (tablero  y bordes)
                c = j == 1 || j == TABLERO_ANCHO + 2 ? LINEA_V : tablero[i - 2][j - 2].coord == 1 ? PIEZA
                                                                                                  : ' ';
                break;
            }
            // posicion del tablero ocupado
            if (tablero[i - 2][j - 2].coord == 1)
            {
                // elegir  su color
                printf("\033[0;%dm", tablero[i - 2][j - 2].color);
            }
            // pintar
            printf("%c", c);
            // volver al color original
            printf("\033[0m");
            // mover hacia abajo
            if (j == TABLERO_ANCHO + 2)
            {
                gotoxy(MARGEN_H, MARGEN_V + i);
            }
        }
    }
}

void piezaNueva(tPieza *pPieza, int *pColors)
{
    // distintas piezas
    coord periferias[7][3] = {{{1, 0}, {0, 1}, {1, 1}},   // cuadrado
                              {{1, 0}, {-1, 1}, {0, 1}},  // ese
                              {{0, 1}, {1, 1}, {-1, 0}},  // zeta
                              {{0, 1}, {0, -1}, {1, 1}},  // ele
                              {{0, 1}, {0, -1}, {-1, 1}}, // jota
                              {{0, 1}, {0, -1}, {0, 2}},  // palo
                              {{-1, 0}, {1, 0}, {0, 1}}}; // te
    // elegir al azar
    int randomIndex = rand() % 7;
    // posicionar la pieza fija arriba en el medio
    pPieza->piezaFija.x = 6;
    pPieza->piezaFija.y = 1;

    int i;
    // posiconar sus piezas movibles con ella
    for (i = 0; i < 3; i++)
    {
        pPieza->movibles[i] = periferias[randomIndex][i];
        pPieza->color = pColors[randomIndex];
    }
}

void pintarPieza(tPieza *pPieza)
{
    // pintar la fija
    pintarCuadrado(pPieza->piezaFija.x, pPieza->piezaFija.y);
    int i;
    // pintar las movibles
    for (i = 0; i < 3; i++)
    {
        // piezas movibles se acomodan en base a la fija
        pintarCuadrado(pPieza->piezaFija.x + pPieza->movibles[i].x, pPieza->piezaFija.y + pPieza->movibles[i].y);
    }
}

void pintarCuadrado(int x, int y)
{
    char c = PIEZA;
    // preveer los bordes (MARGEN_H + 2)
    gotoxy(MARGEN_H + 2 + x, y + MARGEN_V + 2);
    // colores
    printf("\033[0;%dm", pieza.color);
    printf("%c", c);
    printf("\033[0m");
}

bool colision(tPieza *pieza)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        // obtener la coordenada de una pieza
        coord c = funcionCoordenadas(pieza, i);
        // verificar que no colosione con bordes/piezas
        if (c.x < 0 || c.x >= TABLERO_ANCHO)
        {
            return true;
        }
        if (c.y >= TABLERO_LARGO)
        {
            return true;
        }
        if (tablero[c.y][c.x].coord != 0)
        {
            return true;
        }
    }
    return false;
}

coord funcionCoordenadas(tPieza *pPieza, int n)
{
    // caso pieza fija
    coord eje = {pPieza->piezaFija.x,
                 pPieza->piezaFija.y};

    if (n != 0)
    {
        // caso piezas movibles
        eje.x += pPieza->movibles[n - 1].x;
        eje.y += pPieza->movibles[n - 1].y;
    }
    return eje;
}

void colocarPieza()
{
    int i;
    for (i = 0; i < 4; i++)
    {
        // obtener la coordenada de una pieza
        coord c = funcionCoordenadas(&pieza, i);

        // Marcar la posición actual de la pieza en el tablero
        tablero[c.y][c.x].coord = 1;
        tablero[c.y][c.x].color = pieza.color;
    }
}

int calcularPuntuacion()
{
    // acumular todas las lineas colapsadas (suma puntos)
    resultado += tableroContarLineas();

    return resultado;
}

int tableroContarLineas()
{
    int fila = TABLERO_LARGO;
    int count = 0;

    // recorrido de filas abajo-arriba
    while (fila >= 0)
    {
        // la fila esta llena
        if (tableroFilaLLena(fila))
        {
            // quitar la fila
            tableroColapsa(fila);
            // sumar para la puntuacion
            count++;
        }
        // no esta  llena
        else
        {
            // ir a la siguiente fila
            fila--;
        }
    }
    // multiplicar todas las filas colapsadas encontradas
    return count * 100;
}

void tableroColapsa(int pFila)
{
    // mover todas las filas para abajo
    int i;
    for (i = pFila; i > 0; i--)
    {
        int j;
        for (j = 0; j < TABLERO_ANCHO; j++)
        {
            tablero[i][j] = tablero[i - 1][j];
        }
    }
    int j;
    // igualar la primera fila en 0
    for (j = 0; j < TABLERO_ANCHO; j++)
    {
        tablero[0][j].coord = 0;
    }
}

bool tableroFilaLLena(int pFila)
{
    int i;
    // verificar que toda la fila este llena
    for (i = 0; i < TABLERO_ANCHO; i++)
    {
        if (tablero[pFila][i].coord == 0)
        {
            return false;
        }
    }

    return true;
}

void rotarPieza()
{
    tPieza piezaAnterior = pieza;
    int i;
    // rotar las 4 piezas
    for (i = 0; i < 3; i++)
    {
        pieza.movibles[i] = rotarDerecha(pieza.movibles[i]);
    }
    // esa rotacion no es valida
    if (colision(&pieza))
    {
        // la dejamos como estaba
        pieza = piezaAnterior;
    }
}
coord rotarDerecha(coord pPieza)
{

    coord piezaRotada = {pPieza.y,
                         -pPieza.x};

    return piezaRotada;
}

#endif