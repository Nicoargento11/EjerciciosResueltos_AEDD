#include <stdbool.h>
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

bool colision();
void imprimirContador();
int tableroContarLineas();
void colocarPieza();

coord funcionCoordenadas(tPieza *pPieza, int n);

bool tableroFilaLLena(int pFila);
void tableroColapsa(int pFila);
void rotarPieza();
coord rotarDerecha();