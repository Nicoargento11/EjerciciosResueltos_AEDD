#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

// funciones externas
#include "puntuacion.h"
#include "tetris.h"

// definicion de varibles (juego)
tTablero tablero;
tPieza pieza;
int colors[7] = {31, 32, 33, 34, 35, 31, 32};
int resultado;

// definicion de varibles (puntuacion)

FILE *archivoPuntuacion;
tDatos usuario;

tArbol *arbol;

int main()
{
    // limpiar consola
    imprimirReglas();
    fflush(stdin);
    char empezarJuego = 0;
    printf("\nDesea jugar? (s/n)");
    scanf("%c", &empezarJuego);
    fflush(stdin);

    if (toupper(empezarJuego) == 'S')
    {

        system("cls");
        srand(time(NULL));

        iniciarArchivo();

        // Preparacion del juego
        inicializarTablero();
        piezaNueva(&pieza, colors);
        imprimirEscenario();
        pintarPieza(&pieza);

        calcularPuntuacion();
        imprimirPuntuacion(resultado);

        // variables para controlar la velocidad de caida (fichas)
        clock_t tiempoAnterior = clock();
        clock_t tiempoTranscurrido;
        int tiempoCaida = INTERVALO_MOVIMIENTO;

        // variables para usar durante el juego
        int gameOver = 0;
        char tecla = 0;
        char seguirJugando = 0;
        resultado = 0;
        while (!gameOver)
        {
            // guardar previo valor en caso de colision
            int x = pieza.piezaFija.x;
            int y = pieza.piezaFija.y;

            // MOVIMIENTO DE LA FICHA MANUAL
            if (_kbhit())
            {
                // guardar la tecla presionada
                tecla = _getch();
                // accion en base a la tecla presionada
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
                    rotarPieza();
                    break;
                case ESC:
                    gameOver = 1;

                default:
                    break;
                }
                // se movio la ficha y hubo colision
                if (colision(&pieza))
                {
                    // volver a su lugar anterior
                    pieza.piezaFija.x = x;
                    pieza.piezaFija.y = y;
                }
                // actualizar escenario
                imprimirEscenario();
                pintarPieza(&pieza);
            }
            // CAIDA DE LA FICHA
            tiempoTranscurrido = clock() - tiempoAnterior;
            if (tiempoTranscurrido >= tiempoCaida * CLOCKS_PER_SEC / 1000)
            {
                // paso el tiempo -> baja la ficha
                pieza.piezaFija.y++;
                if (colision(&pieza))
                {
                    // insertar la pieza en el tablero
                    pieza.piezaFija.y--;
                    colocarPieza();
                    piezaNueva(&pieza, colors);

                    // crear nueva pieza
                    pintarPieza(&pieza);

                    calcularPuntuacion();
                    imprimirPuntuacion(resultado);
                }
                // doble colision == estar arriba del todo
                if (colision(&pieza))
                {

                    // Juego Perdido
                    gameOver = 1;

                    // guardar datos al archivo y arbol
                    guardarDatos(&arbol, resultado);

                    // Preguntar si quiere seguir jugando
                    fflush(stdin);
                    gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V + 8);
                    printf("Quieres seguir jugando? (s/n): ");
                    scanf("%c", &seguirJugando);
                    fflush(stdin);
                    if (toupper(seguirJugando) == 'S')
                    {
                        // Reiniciar el juego
                        system("cls");
                        gameOver = 0;
                        inicializarTablero();
                        piezaNueva(&pieza, colors);
                        resultado = 0;
                        imprimirPuntuacion(resultado);
                    }
                }
                // actualizar escenario
                imprimirEscenario();
                pintarPieza(&pieza);
                tiempoAnterior = clock();
            }
        }
        // fin de juego
        imprimirFinJuego();
    }
    return 0;
}
