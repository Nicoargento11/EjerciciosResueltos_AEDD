// archivo que maneja la puntuacion del tetris

#ifndef PUNTUACION_H
#define PUNTUACION_H

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#include "tetris.h"

typedef char string[25];
// datos del jugador
typedef struct
{
    string nombre;
    int puntuacion;
} tDatos;
// datos de los nodos del arbol
typedef struct nodo
{
    tDatos datos;
    struct nodo *hijoIzquierdo;
    struct nodo *hijoDerecho;
} tArbol;

// DEFINICION DE PROTOTIPOS
void inicializarArbol(tArbol **);
bool arbolVacio(tArbol *);

void imprimirHistorial();
int buscarMayor(tArbol *);

void iniciarArchivo();
void insertarDatos(tArbol **, tDatos);
void guardarDatos(tArbol **, int);

void imprimirPuntuacion(int);
void imprimirReglas();

void imprimirFinJuego();

// variables del main
extern tDatos usuario;
extern FILE *archivoPuntuacion;
extern tArbol *arbol;

void inicializarArbol(tArbol **pArbol)
{
    *pArbol = NULL;
}

bool arbolVacio(tArbol *pArbol)
{
    return pArbol == NULL;
}

void iniciarArchivo()
{
    // modo de apertura (lectura)
    archivoPuntuacion = fopen("dataPuntuacion.dat", "rb");
    if (archivoPuntuacion == NULL)
    {

        // No hay archivo, preguntamos nombre
        printf("No se han encontrado registros. Por favor, ingresa tu nombre: ");
        scanf("%s", usuario.nombre);
    }
    else
    {
        // Se leyo un registro, mostrar nombre del usuario
        fread(&usuario, sizeof(tDatos), 1, archivoPuntuacion);
        gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V);
        printf("Bienvenido %s! \n", usuario.nombre);

        inicializarArbol(&arbol);
        // insertar los datos del archivo en el arbol
        while (!feof(archivoPuntuacion))
        {
            insertarDatos(&arbol, usuario);
            fread(&usuario, sizeof(tDatos), 1, archivoPuntuacion);
        }
    }
    // cerrar archivo
    fclose(archivoPuntuacion);
}

void insertarDatos(tArbol **pArbol, tDatos pDato)
{
    // insertar datos al iniciar el programa o al terminar la partida. En el arbol
    if (arbolVacio(*pArbol))
    {
        // reservar memoria
        *pArbol = (tArbol *)malloc(sizeof(tArbol));

        // guardar datos
        if (*pArbol != NULL)
        {
            (*pArbol)->datos = pDato;
            (*pArbol)->hijoIzquierdo = NULL;
            (*pArbol)->hijoDerecho = NULL;
        }
    }
    else
    {
        // moverse al nodo correspondiente
        if (pDato.puntuacion > (*pArbol)->datos.puntuacion)
        {
            insertarDatos(&(*pArbol)->hijoDerecho, pDato);
        }
        else
        {
            if (pDato.puntuacion < (*pArbol)->datos.puntuacion)
            {
                insertarDatos(&(*pArbol)->hijoIzquierdo, pDato);
            }
        }
    }
}

void guardarDatos(tArbol **pArbol, int pResultado)
{
    // cargar datos luego de terminar la partida en el archivo

    int mayorPuntuacion = buscarMayor(arbol);
    if (pResultado > 0)
    {
        // modo de apertura (añadir/editar)
        archivoPuntuacion = fopen("dataPuntuacion.dat", "ab");

        if (archivoPuntuacion != NULL)
        {
            // nueva record
            if (pResultado > mayorPuntuacion)
            {
                gotoxy(MARGEN_H + 1, MARGEN_V);
                printf("Nuevo Record!!!");
            }
            // actualizar puntuacion del usuario
            usuario.puntuacion = pResultado;
            // guardar datos en ambos (arbol/archivo)
            insertarDatos(pArbol, usuario);
            fwrite(&usuario, sizeof(tDatos), 1, archivoPuntuacion);
        }
        else
        {
            printf("ha ocurrido un error al crear el archivo");
            exit(EXIT_FAILURE);
        }
        // cerrar archivo
        fclose(archivoPuntuacion);
    }
}

int buscarMayor(tArbol *pArbol)
{
    // ARBOL BINARIO

    if (arbolVacio(pArbol))
    {
        // no se encontro
        return 0;
    }
    else
    {
        // encontro nodo siguiente, se mueve
        if (!arbolVacio(pArbol->hijoDerecho))
        {
            return buscarMayor(pArbol->hijoDerecho);
        }
        else
        {
            // no hay mas nodos, devuelve
            return pArbol->datos.puntuacion;
        }
    }
}

void imprimirHistorial()
{
    int posx = MARGEN_H + TABLERO_ANCHO + 52;
    int posy = MARGEN_V + 4;

    archivoPuntuacion = fopen("dataPuntuacion.dat", "rb");

    fread(&usuario, sizeof(tDatos), 1, archivoPuntuacion);

    // printf("Usuario: %s\n", usuario.nombre);

    while (!feof(archivoPuntuacion))
    {
        gotoxy(posx, posy++);
        printf("Puntos: %d\n ", usuario.puntuacion);
        fread(&usuario, sizeof(tDatos), 1, archivoPuntuacion);
    }
    fclose(archivoPuntuacion);
}

void imprimirPuntuacion(int pResult)
{
    int posx = MARGEN_H + TABLERO_ANCHO + 10;
    int posy = MARGEN_V + 1;

    gotoxy(posx, posy++);
    printf("-----------------------------------------\n");
    gotoxy(posx, posy++);
    printf("Puntuacion: %d Puntuacion Maxima: %d", pResult, buscarMayor(arbol));
    gotoxy(posx, posy++);
    printf("-----------------------------------------\n");
}

void imprimirReglas()
{
    system("cls"); // Limpia la consola antes de imprimir las reglas

    printf("-------------------------------------------------\n");
    printf("|                 Reglas del Tetris             |\n");
    printf("-------------------------------------------------\n\n");

    printf("1. Objetivo del juego:\n");
    printf("   Mueve y gira las piezas para formar lineas horizontales completas.\n");
    printf("   Cuando completas una linea, esa linea desaparece, y ganas puntos.\n\n");

    printf("2. Teclas de control:\n");
    printf("   - Mover hacia abajo:         <S>\n");
    printf("   - Mover hacia la izquierda:  <A>\n");
    printf("   - Mover hacia la derecha:    <D>\n");
    printf("   - Rotar la pieza:            <W>\n");

    printf("3. Puntuacion:\n");
    printf("   - Cada linea completada:     100 puntos\n\n");

    printf("4. Fin del juego:\n");
    printf("   - El juego termina cuando las piezas alcanzan la parte superior del tablero.\n\n");

    printf("Buena suerte!!!\n");
}

void imprimirFinJuego()
{
    int posX = MARGEN_H + TABLERO_ANCHO + 10;
    int posY = MARGEN_V + 1;
    gotoxy(posX, posY + 4);
    printf("Partida terminada Puntuacion: %d\n", resultado);

    gotoxy(posX + 42, posY++);
    printf("-------------------------\n");
    gotoxy(posX + 42, posY++);
    printf("Historial de puntuaciones\n");
    gotoxy(posX + 42, posY++);
    printf("-------------------------\n");
    gotoxy(posX + 42, posY++);
    // imprimir sus puntaciones (no repetidas)
    imprimirHistorial();

    gotoxy(posX + 20, posY + 20);
}

#endif