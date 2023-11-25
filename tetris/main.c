#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#include "puntuacion.h"
#include "tetris.h"

tTablero tablero;
tPieza pieza;
int resultado = 0;
int colors[7] = {31, 32, 33, 34, 35, 31, 32};

FILE *archivoPuntuacion;
tDatos usuario;

tArbol *arbol;

int main()
{
    system("cls");
    srand(time(NULL));

    resultado = 0;
    iniciarArchivo();

    // juego
    inicializarTablero();
    piezaNueva(&pieza, colors);
    imprimirEscenario();
    pintarPieza(&pieza);

    calcularPuntuacion();
    imprimirPuntuacion(resultado);

    clock_t tiempoAnterior = clock();
    clock_t tiempoTranscurrido;

    int tiempoCaida = INTERVALO_MOVIMIENTO;
    int gameOver = 0;
    char tecla = 0;
    char seguirJugando = 0;

    while (!gameOver)
    {
        int x = pieza.piezaFija.x;
        int y = pieza.piezaFija.y;
        if (_kbhit())
        {

            tecla = _getch();
            switch (tecla)
            {
            case 's':
                pieza.piezaFija.y++;

                break;
            case 'a':
                pieza.piezaFija.x--;

                break;
            case 'd':
                pieza.piezaFija.x++;

                break;
            case 'w':
                if (!colision(&pieza))
                {
                    rotarPieza();
                }

                break;
            case ESC:
                gameOver = 1;

            default:
                break;
            }
            if (colision(&pieza))
            {
                pieza.piezaFija.x = x;
                pieza.piezaFija.y = y;
            }
            imprimirEscenario();
            pintarPieza(&pieza);
        }

        tiempoTranscurrido = clock() - tiempoAnterior;
        if (tiempoTranscurrido >= tiempoCaida * CLOCKS_PER_SEC / 1000)
        {
            pieza.piezaFija.y++;
            if (colision(&pieza))
            {
                pieza.piezaFija.y--;
                colocarPieza();
                piezaNueva(&pieza, colors);

                pintarPieza(&pieza);
                calcularPuntuacion();
                imprimirPuntuacion(resultado);
            }
            if (colision(&pieza))
            {

                // Juego terminado
                gameOver = 1;
                // printf("usuario: %s", usuario.nombre);
                cargarDatos(&arbol, resultado);

                // Muestra la puntuación al jugador
                // Pregunta al jugador si quiere seguir jugando
                fflush(stdin);
                gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V + 8);
                printf("Quieres seguir jugando? (s/n): ");
                scanf("%c", &seguirJugando);
                fflush(stdin);
                if (seguirJugando == 's' || seguirJugando == 'S')
                {
                    // Reiniciar el juego
                    system("cls");
                    gameOver = 0;
                    inicializarTablero(tablero);
                    piezaNueva(&pieza, colors);
                    resultado = 0;
                    imprimirPuntuacion(resultado);
                }
            }
            imprimirEscenario();
            pintarPieza(&pieza);
            tiempoAnterior = clock();
        }
    }
    // fin juego
    // leerPuntuacion(usuario);
    gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V + 5);
    printf("Partida terminada Puntuacion: %d\n", resultado);

    // gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V + 7);

    // printf("MAYOR PUNTUACION: %d \n", buscarMayor(arbol));

    gotoxy(MARGEN_H + TABLERO_ANCHO + 52, MARGEN_V + 1);
    printf("-------------------------\n");
    gotoxy(MARGEN_H + TABLERO_ANCHO + 52, MARGEN_V + 2);
    printf("Historial de puntuaciones\n");
    gotoxy(MARGEN_H + TABLERO_ANCHO + 52, MARGEN_V + 3);
    printf("-------------------------\n");
    gotoxy(MARGEN_H + TABLERO_ANCHO + 52, MARGEN_V + 4);

    recorrerEnPreorden(arbol, 0);

    gotoxy(MARGEN_H + TABLERO_ANCHO + 30, MARGEN_V + 22);

    return 0;
}
