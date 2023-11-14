#include "funciones.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

tTablero tablero;
tPieza pieza;
int result = 0;
int colors[7] = {31, 32, 33, 34, 35, 31, 32};

int main()
{
    system("cls");
    srand(time(NULL));

    // creacion de tablero y fichas
    inicializarTablero(tablero);
    piezaNueva(&pieza, colors);
    imprimirEscenario(tablero);
    pintarPieza(&pieza);
    imprimirContador(&result);

    // varibles de frameSpeed y bucle
    clock_t tiempoAnterior = clock();
    clock_t tiempoTranscurrido;
    int tiempoCaida = INTERVALO_MOVIMIENTO;
    int gameOver = 0;
    char tecla = 0;

    while (!gameOver)
    {
        if (kbhit())
        {
            tecla = _getch();
            switch (tecla)
            {
            case 's':
                pieza.piezaFija.y++;

                break;
            case 'a':
                pieza.piezaFija.x--;
                if (colision())
                {
                    pieza.piezaFija.x++;
                }

                break;
            case 'd':
                pieza.piezaFija.x++;
                if (colision())
                {
                    pieza.piezaFija.x--;
                }

                break;
            case 'w':
                rotarPieza();

                break;
            case ESC:
                gameOver = 1;

            default:
                break;
            }
        }
        tiempoTranscurrido = clock() - tiempoAnterior;
        if (tiempoTranscurrido >= tiempoCaida * CLOCKS_PER_SEC / 1000)
        {
            pieza.piezaFija.y++;
            if (colision())
            {
                pieza.piezaFija.y--;
                colocarPieza();
                gotoxy(45, 45);
                printf("x: %d y: %d", pieza.piezaFija.x, pieza.piezaFija.y);
                piezaNueva(&pieza, colors);
                pintarPieza(&pieza);
                imprimirContador();
            }
            imprimirEscenario(tablero);
            pintarPieza(&pieza);
            tiempoAnterior = clock();
        }
    }
    return 1;
}