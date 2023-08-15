#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
Estrategia:
while (finalizar != "N") {
    1.1: pedir al usuario el tipo de vivienda. "1-casa, 2-rancho, 3-casilla, 4-departamento" (int)
    1.2: pedir al usuario la cantidad de personas que habitan la vivienda (int)
    1.3: pedir al usuario la cantidad de dormitorios (int)
    1.4: pedir al usuario la cantidad de baños (int)
    1.5: pedir al usuario si dispone de cocina completa. "1-si, 2-no" (bool)
    2: contar la cantidad de viviendas censadas (int)
    3: contar la cantidad de viviendas que no tienen cocina ni baño, y representar su porcentaje sobre el total de viviendas. (float)
    4: verificar si hay sobrepoblacion en la vivienda (dormitorios/cantIntegrantes >= 0.4)
    4.1: Imprimir un mensaje que diga: *** Atención: esta vivienda
puede estar en condiciones de hacinamiento***
    5: Preguntar si desea ingresar mas datos


}
    6: imprimir el resultado final:
    "Cantidad total de viviendas censadas: 1500
    Cantidad de viviendas que no tienen cocina completa ni baño: 500
    Porcentaje que representan las viviendas que no tienen cocina completa ni baño, sobre todas las viviendas censadas: 33.33%"

Aclaraciones:
-Utilizar una constante para el titulo del informe
-Finalizar cuando el usuario no tenga mas por cargar
*/

char Titulo[30];

int tipoVivienda;
int cantPersonas;
int cantDormitorios;
int cantBaños;
int numeroCocina;
bool cocinaCompleta;

int viviendasCensadas = 0;
int viviendasNoCompletas;

char finalizar;

void ingresarDatos();
float porcentajeCasasIncompletas();
void avisoSobrepoblacion();

int main()
{
    while (finalizar != 'N')
    {
        ingresarDatos();
        cocinaCompleta = numeroCocina == 1 ? true : false;
        viviendasCensadas++;
    }
    strcpy(Titulo, "Viviendas Censadas - Provincia de Corrientes");
    printf("%s\n", Titulo);
    printf("Cantidad total de viviendas censadas: %d", viviendasCensadas);
    printf("\nCantidad de viviendas que no tienen cocina completa ni baño: %d", viviendasNoCompletas);
    printf("\nPorcentaje que representan las viviendas que no tienen cocina completa ni baño, sobre todas las viviendas censadas: %.2f%%", porcentajeCasasIncompletas());
    return 1;
}

void ingresarDatos()
{
    printf("Ingresa el tipo de vivienda: \n");
    printf("1-casa, 2-rancho, 3-casilla, 4-departamento ");
    scanf("%d", &tipoVivienda);
    printf("\nIngrese la cantidad de personas que habitan la vivienda: ");
    scanf("%d", &cantPersonas);
    printf("\nIngrese la cantidad de dormitorios: ");
    scanf("%d", &cantDormitorios);
    printf("\nIngrese la cantidad de baños: ");
    scanf("%d", &cantBaños);
    printf("\n¿Dispone de cocina completa? \n");
    printf("1-si, 2-no ");
    scanf("%d", &numeroCocina);
    fflush(stdin);
    avisoSobrepoblacion();
    printf("\nDesea Ingresar mas datos?");
    printf("\nS- si, N-no\n");
    scanf("%c", &finalizar);
    fflush(stdin);
}

float porcentajeCasasIncompletas()
{
    if (cantBaños == 0 && !cocinaCompleta)
    {
        viviendasNoCompletas++;
    }
    float resultado = (float)viviendasNoCompletas / viviendasCensadas;
    return resultado * 100;
}

void avisoSobrepoblacion()
{
    float resultado = (float)cantDormitorios / cantPersonas;
    if (resultado < 0.4)
    {
        printf("Atención: esta vivienda puede estar en condiciones de hacinamiento\n");
    }
}