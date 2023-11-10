#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>

#define ESC 27

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

tPieza pieza;
tDatoTablero tablero[TABLERO_LARGO][TABLERO_ANCHO];
int result = 0;
void rectanguloLleno(int, int);
void pintarPieza(tPieza *);
void gotoxy(int, int);
void pintarCuadrado(int, int);
void piezaNueva(tPieza *);
void inicializarTablero();
void imprimirEscenario();
bool colision();
coord funcionCoordenadas(tPieza *, int);
void colocarPieza();
void rotarPieza();
coord rotarDerecha(coord);

bool tableroFilaLLena(int);
void tableroColapsa(int);
int tableroContarLineas();
void imprimirContador();

int colors[7] = {31, 32, 33, 34, 35, 31, 32};

int main()
{
    system("cls");
    srand(time(NULL));
    // pieza.piezaFija.x = 0;
    // pieza.piezaFija.y = 0;

    // pieza.movibles[0].x = 1;
    // pieza.movibles[0].y = 0;
    // pieza.movibles[1].x = 2;
    // pieza.movibles[1].y = 0;
    // pieza.movibles[2].x = -1;
    // pieza.movibles[2].y = 0;

    int x, y;
    int gameOver = 0;
    char tecla = 0;
    piezaNueva(&pieza);
    inicializarTablero();
    imprimirEscenario();
    // char tecla = _getch();
    pintarPieza(&pieza);
    while (!gameOver)
    {

        if (_kbhit())
        {
            tecla = _getch();
            switch (tecla)
            {
            case 's':
                /* code */
                pieza.piezaFija.y++;
                if (colision())
                {
                    pieza.piezaFija.y--;
                    colocarPieza();
                    piezaNueva(&pieza);
                    pintarPieza(&pieza);
                }
                imprimirEscenario();
                pintarPieza(&pieza);

                break;
            case 'a':
                pieza.piezaFija.x--;
                if (colision())
                {
                    pieza.piezaFija.x++;
                }
                imprimirEscenario();
                pintarPieza(&pieza);
                break;
            case 'd':
                pieza.piezaFija.x++;
                if (colision())
                {
                    pieza.piezaFija.x--;
                }

                imprimirEscenario();
                pintarPieza(&pieza);
                break;
            case 'w':
                rotarPieza();
                imprimirEscenario();
                pintarPieza(&pieza);
                break;
            case ESC:
                gameOver = 1;

            default:
                break;
            }
        }
        imprimirContador();
    }

    // repintar
    // redimensionar
    // pintar
    return 1;
}

void pintarPieza(tPieza *pPieza)
{
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
void piezaNueva(tPieza *pPieza)
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
    pPieza->piezaFija.y = 1;

    // printf("pieza numero %d:\n", randomIndex);
    for (int i = 0; i < 3; i++)
    {
        pPieza->movibles[i] = periferias[randomIndex][i];
        pPieza->color = colors[randomIndex];
        // printf("%d", pPieza->movibles[i].x);
        // printf("%d \n", pPieza->movibles[i].y);
    }
}

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
                c = j == 1 || j == TABLERO_ANCHO + 2 ? LINEA_V : tablero[i - 1][j - 1].coord == 1 ? PIEZA
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
void imprimirContador()
{
    gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V);
    result += tableroContarLineas();
    printf("%d", result);
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
        // Marcar la posiciÃ³n actual de la ficha en el tablero
        tablero[c.y - 1][c.x - 1].coord = 1;
        tablero[c.y - 1][c.x - 1].color = pieza.color;
    }
}

// funciones del puntuacion

bool tableroFilaLLena(int pFila)
{
    for (int i = 0; i < TABLERO_ANCHO; i++)
    {
        if (tablero[pFila][i].coord == 0)
        {
            return false;
        }
    }
    return true;
}

void tableroColapsa(int fila)
{
    for (int i = fila; i > 0; i--)
    {
        for (int j = 0; j < TABLERO_ANCHO; j++)
        {
            tablero[i][j].coord = tablero[i - 1][j].coord;
        }
    }
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
            count++;
        }
        else
        {
            fila--;
        }
    }
    return count;
}