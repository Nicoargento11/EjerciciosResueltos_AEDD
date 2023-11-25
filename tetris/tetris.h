#ifndef TETRIS_H
#define TETRIS_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define ESC 27

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

#define MAX_PUNTUACION 1000

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

void inicializarTablero();
void imprimirEscenario();
void gotoxy(int x, int y);

void piezaNueva(tPieza *pPieza, int *pColors);
void pintarPieza(tPieza *pPieza);
void pintarCuadrado(int x, int y);

bool colision(tPieza *);
int calcularPuntuacion();
int tableroContarLineas();
void colocarPieza();

coord funcionCoordenadas(tPieza *pPieza, int n);

bool tableroFilaLLena(int pFila);
void tableroColapsa(int pFila);
void rotarPieza();
coord rotarDerecha(coord);

extern tTablero tablero;
extern tPieza pieza;
extern int resultado;

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
    for (i = 1; i <= TABLERO_LARGO + 2; i++)
    {
        int j;
        for (j = 1; j <= TABLERO_ANCHO + 2; j++)
        {
            gotoxy(MARGEN_H + j, MARGEN_V + i);

            switch (i)
            {
            case 1:
                /* code */
                c = j == 1 ? ESQ_SI : j == TABLERO_ANCHO + 2 ? ESQ_SD
                                                             : LINEA_H;
                break;
            case TABLERO_LARGO + 2:
                c = j == 1 ? ESQ_II : j == TABLERO_ANCHO + 2 ? ESQ_ID
                                                             : LINEA_H;
                break;
            default:
                c = j == 1 || j == TABLERO_ANCHO + 2 ? LINEA_V : tablero[i - 2][j - 2].coord == 1 ? PIEZA
                                                                                                  : ' ';
                break;
            }
            if (tablero[i - 2][j - 2].coord == 1)
            {
                printf("\033[0;%dm", tablero[i - 2][j - 2].color);
            }
            printf("%c", c);
            printf("\033[0m");
            if (j == TABLERO_ANCHO + 2)
            {
                gotoxy(MARGEN_H, MARGEN_V + i);
            }
        }
    }
}

void piezaNueva(tPieza *pPieza, int *pColors)
{
    coord periferias[7][3] = {{{1, 0}, {0, 1}, {1, 1}},   // cuadrado
                              {{1, 0}, {-1, 1}, {0, 1}},  // ese
                              {{0, 1}, {1, 1}, {-1, 0}},  // zeta
                              {{0, 1}, {0, -1}, {1, 1}},  // ele
                              {{0, 1}, {0, -1}, {-1, 1}}, // jota
                              {{0, 1}, {0, -1}, {0, 2}},  // palo
                              {{-1, 0}, {1, 0}, {0, 1}}}; // te

    int randomIndex = rand() % 7;
    pPieza->piezaFija.x = 6;
    pPieza->piezaFija.y = 1;

    int i;
    for (i = 0; i < 3; i++)
    {
        pPieza->movibles[i] = periferias[randomIndex][i];
        pPieza->color = pColors[randomIndex];
    }
}

void pintarPieza(tPieza *pPieza)
{
    // if (posiciones[i].y > 0 && posiciones[i].y <= TABLERO_LARGO + 1 &&
    // posiciones[i].x >= 0 && posiciones[i].x <= TABLERO_ANCHO)

    pintarCuadrado(pPieza->piezaFija.x, pPieza->piezaFija.y);
    // gotoxy(30, 15);
    // printf("x: %d y: %d\n", pPieza->piezaFija.x, pPieza->piezaFija.y);
    int i;
    for (i = 0; i < 3; i++)
    {
        gotoxy(30, 20 + 1 + i * 2);

        // printf("x: %d y: %d", pPieza->piezaFija.x + pPieza->movibles[i].x, pPieza->piezaFija.y + pPieza->movibles[i].y);
        pintarCuadrado(pPieza->piezaFija.x + pPieza->movibles[i].x, pPieza->piezaFija.y + pPieza->movibles[i].y);
    }
}

void pintarCuadrado(int x, int y)
{
    char c = PIEZA;
    gotoxy(MARGEN_H + 2 + x, y + MARGEN_V + 2);
    printf("\033[0;%dm", pieza.color);
    printf("%c", c);
    printf("\033[0m");
}

bool colision(tPieza *pieza)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        coord c = funcionCoordenadas(pieza, i);
        // gotoxy(30, 19 + i);
        // printf("y: %d x: %d\n", c.y, c.x);
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
            // gotoxy(30, 19);
            // printf("y: %d x: %d\n", c.y, c.x);
            return true;
        }
        // arreglar
    }
    return false;
}

coord funcionCoordenadas(tPieza *pPieza, int n)
{
    coord eje = {pPieza->piezaFija.x,
                 pPieza->piezaFija.y};
    if (n != 0)
    {
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
        coord c = funcionCoordenadas(&pieza, i);

        // Marcar la posición actual de la ficha en el tablero
        // gotoxy(30, 20 + i * 2);
        // printf("x: %d\n", c.x);
        tablero[c.y][c.x].coord = 1;
        tablero[c.y][c.x].color = pieza.color;
    }
}

int calcularPuntuacion()
{

    // Actualizar la puntuación y asegurarse de que no supere el límite máximo
    resultado += tableroContarLineas();
    // if (result > MAX_PUNTUACION)
    // {
    //     result = MAX_PUNTUACION;
    // }
    return resultado;

    // Imprimir el contador en una posición específica
}

int tableroContarLineas()
{
    int fila = TABLERO_LARGO;
    int count = 0;

    while (fila >= 0)
    {
        if (tableroFilaLLena(fila))
        {
            tableroColapsa(fila);
            count++;
        }
        else
        {
            fila--;
        }
    }
    return count * 100;
}

void tableroColapsa(int pFila)
{
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
    for (j = 0; j < TABLERO_ANCHO; j++)
    {
        tablero[0][j].coord = 0;
    }
}

bool tableroFilaLLena(int pFila)
{
    int i;
    for (i = 0; i < TABLERO_ANCHO; i++)
    {
        // gotoxy(50 + i, 50);
        // printf("%d", tablero[pFila][i].coord);
        if (tablero[pFila][i].coord == 0)
        {
            return false;
        }
    }

    return true;
}

void rotarPieza()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        pieza.movibles[i] = rotarDerecha(pieza.movibles[i]);
    }
}
coord rotarDerecha(coord pPieza)
{
    coord piezaRotada = {pPieza.y,
                         -pPieza.x};

    return piezaRotada;
}

#endif