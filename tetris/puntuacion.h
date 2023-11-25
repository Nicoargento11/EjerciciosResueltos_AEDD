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

typedef struct
{
    string nombre;
    int puntuacion;
} tDatos;

typedef struct nodo
{
    tDatos datos;
    struct nodo *hijoIzquierdo;
    struct nodo *hijoDerecho;
} tArbol;

void inicializarArbol(tArbol **);
bool arbolVacio(tArbol *);

void recorrerEnPreorden(tArbol *, int);
int buscarMayor(tArbol *);

void iniciarArchivo();
void insertarDatos(tArbol **, tDatos);
void cargarDatos(tArbol **, int);

void leerPuntuacion(tDatos);
void imprimirPuntuacion(int);

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
    // iniciamos archivo y cargamos datos (arbol)
    // memset(&usuario, 0, sizeof(tDatos));
    // usuario.nombre[0] = '\0';
    archivoPuntuacion = fopen("dataPuntuacion.dat", "rb");
    if (archivoPuntuacion == NULL)
    {

        // Si no se leyó nada, el archivo está vacío
        printf("No se han encontrado registros. Por favor, ingresa tu nombre: ");
        scanf("%s", usuario.nombre);
    }
    else
    {
        // Si se leyó un registro, muestra el nombre del usuario
        fread(&usuario, sizeof(tDatos), 1, archivoPuntuacion);
        gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V);
        printf("Bienvenido %s! \n", usuario.nombre);

        inicializarArbol(&arbol);
        while (!feof(archivoPuntuacion))
        {
            insertarDatos(&arbol, usuario);
            fread(&usuario, sizeof(tDatos), 1, archivoPuntuacion);
        }
    }

    fclose(archivoPuntuacion);
}

void insertarDatos(tArbol **pArbol, tDatos pDato)
{
    // insertar datos antes del programa o al terminar la partida (arbol)
    if (arbolVacio(*pArbol))
    {
        *pArbol = (tArbol *)malloc(sizeof(tArbol));

        if (*pArbol != NULL)
        {
            (*pArbol)->datos = pDato;
            (*pArbol)->hijoIzquierdo = NULL;
            (*pArbol)->hijoDerecho = NULL;
        }
    }
    else
    {
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

void cargarDatos(tArbol **pArbol, int pResultado)
{
    // cargar datos luego de terminar la partida en el archivo
    int mayorPuntuacion = buscarMayor(arbol);
    if (pResultado > 0)
    {

        archivoPuntuacion = fopen("dataPuntuacion.dat", "ab");

        if (archivoPuntuacion != NULL)
        {
            if (pResultado > mayorPuntuacion)
            {
                gotoxy(MARGEN_H + 1, MARGEN_V);
                printf("Nuevo Record!!!");
            }
            usuario.puntuacion = pResultado;
            insertarDatos(pArbol, usuario);
            fwrite(&usuario, sizeof(tDatos), 1, archivoPuntuacion);
        }
        else
        {
            printf("ha ocurrido un error al crear el archivo");
            exit(EXIT_FAILURE);
        }
        fclose(archivoPuntuacion);
    }
}

int buscarMayor(tArbol *pArbol)
{
    if (arbolVacio(pArbol))
    {
        return 1;
    }
    else
    {
        if (!arbolVacio(pArbol->hijoDerecho))
        {
            return buscarMayor(pArbol->hijoDerecho);
        }
        else
        {
            return pArbol->datos.puntuacion;
        }
    }
}

void recorrerEnPreorden(tArbol *pArbol, int pPosicion)
{
    if (!arbolVacio(pArbol))
    {
        gotoxy(MARGEN_H + TABLERO_ANCHO + 52, MARGEN_V + 4 + pPosicion);
        printf("%s - %d \n", pArbol->datos.nombre, pArbol->datos.puntuacion);
        recorrerEnPreorden(pArbol->hijoIzquierdo, pPosicion + 1);
        recorrerEnPreorden(pArbol->hijoDerecho, pPosicion + 1);
    }
}

void imprimirPuntuacion(int pResult)
{

    gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V + 1);
    printf("-----------------------------------------\n");
    gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V + 2);

    printf("Puntuacion: %d Puntuacion Maxima: %d", pResult, buscarMayor(arbol)); // Imprimir con formato de 4 dígitos
    gotoxy(MARGEN_H + TABLERO_ANCHO + 10, MARGEN_V + 3);

    printf("-----------------------------------------\n");
}

void leerPuntuacion(tDatos usuario)
{
    archivoPuntuacion = fopen("dataPuntuacion.dat", "rb");

    fread(&usuario, sizeof(tDatos), 1, archivoPuntuacion);

    printf("Usuario: %s\n", usuario.nombre);

    while (!feof(archivoPuntuacion))
    {
        printf("puntuacion: %d nombre: %s\n ", usuario.puntuacion, usuario.nombre);
        fread(&usuario, sizeof(tDatos), 1, archivoPuntuacion);
    }
    fclose(archivoPuntuacion);
}

#endif