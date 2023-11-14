#include "funciones.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

// void mostrarAlumno(datos pAlumno)
// {
//     printf("%d", pAlumno.dni);
// }

extern tTablero tablero;
extern tPieza pieza;
extern int result;

void gotoxy(int x, int y)
{
    printf("%c[%d;%dH", ESC, y, x);
}

void inicializarTablero()
{
    for (int i = 0; i < TABLERO_LARGO; i++)
    {
        for (int j = 0; j < TABLERO_ANCHO; j++)
        {
            tablero[i][j].coord = 0;
        }
    }
}

void imprimirEscenario()
{
    char c;
    for (int i = 1; i <= TABLERO_LARGO + 2; i++)
    {
        for (int j = 1; j <= TABLERO_ANCHO + 2; j++)
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
                c = j == 1 || j == TABLERO_ANCHO + 2 ? LINEA_V : tablero[i - 1][j - 1].coord == 1 ? '1'
                                                                                                  : ' ';
                break;
            }
            if (tablero[i - 1][j - 1].coord == 1)
            {
                printf("\033[0;%dm", tablero[i - 1][j - 1].color);
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
    pPieza->piezaFija.x = (MARGEN_H + TABLERO_ANCHO) / 2;
    pPieza->piezaFija.y = 0;

    for (int i = 0; i < 3; i++)
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

    for (int i = 0; i < 3; i++)
    {

        pintarCuadrado(pPieza->piezaFija.x + pPieza->movibles[i].x, pPieza->piezaFija.y + pPieza->movibles[i].y);
    }
}

void pintarCuadrado(int x, int y)
{
    char c = PIEZA;
    gotoxy(x + MARGEN_H, y + MARGEN_V);
    printf("\033[0;%dm", pieza.color);
    printf("%c", c);
    printf("\033[0m");
}

bool colision()
{
    for (int i = 0; i < 4; i++)
    {
        coord c = funcionCoordenadas(&pieza, i);
        if (c.x < 2 || c.x >= TABLERO_ANCHO + 2)
        {
            return true;
        }
        if (c.y < 0 || c.y >= TABLERO_LARGO + 2)
        {
            return true;
        }
        if (tablero[c.y - 1][c.x - 1].coord != 0)
        {
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
    for (int i = 0; i < 4; i++)
    {
        coord c = funcionCoordenadas(&pieza, i);
        // Marcar la posición actual de la ficha en el tablero
        tablero[c.y - 1][c.x - 1].coord = 1;
        tablero[c.y - 1][c.x - 1].color = pieza.color;
    }
}

void imprimirContador()
{
    static int result = 0; // Variable estática para mantener la puntuación entre llamadas

    // Actualizar la puntuación y asegurarse de que no supere el límite máximo
    result += tableroContarLineas();
    if (result > MAX_PUNTUACION)
    {
        result = MAX_PUNTUACION;
    }

    // Imprimir el contador en una posición específica
    gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V + 1);
    printf("-----------------------------------------\n");
    gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V + 2);

    printf("Puntuacion: %04d Puntuacion Maxima: %04d", result, MAX_PUNTUACION); // Imprimir con formato de 4 dígitos
    gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V + 3);

    printf("-----------------------------------------\n");
}

int tableroContarLineas()
{
    int fila = TABLERO_LARGO - 1;
    int count = 0;
    while (fila >= 0)
    {
        if (tableroFilaLLena(fila))
        {
            tableroColapsa(fila);
            count += 100;
        }
        else
        {
            fila--;
        }
    }
    return count;
}

bool tableroFilaLLena(int pFila)
{
    for (int i = 0; i < TABLERO_ANCHO; i++)
    {
        if (tablero[pFila][i].coord == 0)
        {
            return false;
        }
    }
    gotoxy(50, 50);
    printf("true");
    return true;
}

void tableroColapsa(int pFila)
{
    for (int i = pFila; i >= 0; i--)
    {
        for (int j = 0; j < TABLERO_ANCHO; j++)
        {
            tablero[i][j] = tablero[i - 1][j];
        }
    }
    for (int j = 0; j < TABLERO_ANCHO; j++)
    {
        tablero[0][j].coord = 0;
    }
}

void rotarPieza()
{
    for (int i = 0; i < 3; i++)
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