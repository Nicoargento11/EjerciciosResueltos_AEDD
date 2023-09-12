#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef char string[50];

// typedef enum categoria
// {
//     ESTUDIANTES = 1,
//     PROFESIONALES = 2,
//     PUBLICO_GENERAL = 3,
// };

typedef struct
{
    int dni;
    string nombre;
    string apellido;
    string email;
    int codCategoria;
    int montoAbonado;
} datosInscriptos;

typedef struct nodo
{
    datosInscriptos inscriptos;
    struct nodo *siguiente;
} pila;

pila *pilaInscriptos;

datosInscriptos inscriptos;

void inicializarPila();
void push(datosInscriptos);
void pop();
bool pilaVacia();
void removerMemoria();
void visualizarPila();

int cantProfesionales();
int montoTotalEstudiantes();
int montoTotal();
void menu();
void ingresarDatosInscriptos();
int calcularMontoAbonar(int);

int main()
{
    inicializarPila();
    menu();
    removerMemoria();
    return 1;
}
void menu()
{
    int opcion = 0;
    while (opcion != -1)
    {
        if (pilaVacia())
        {
            ingresarDatosInscriptos();
            push(inscriptos);
        }
        else
        {
            printf("\nQue desea hacer:\n");
            printf("1- Agregar\n");
            printf("2- Eliminar\n");
            printf("3- Cantidad de profesionales\n");
            printf("4- Monto recaudado en estudiantes\n");
            printf("5- Total recaudado\n");
            printf("-1 Finalizar\n");
            scanf("%d", &opcion);
            switch (opcion)
            {
            case 1:
                ingresarDatosInscriptos();
                push(inscriptos);
                break;
            case 2:
                pop();
                break;
            case 3:
                cantProfesionales();
                break;
            case 4:
                montoTotalEstudiantes();
                break;
            case 5:
                montoTotal();
                break;
            case -1:
                printf("Programa finalizado\n");
                break;
            default:
                break;
            }
        }
    }
    visualizarPila();
}
void ingresarDatosInscriptos()
{
    printf("Ingrese el DNI: ");
    scanf("%d", &inscriptos.dni);
    printf("\nIngrese su nombre: ");
    scanf("%s", &inscriptos.nombre);
    printf("\nIngrese su apellido: ");
    scanf("%s", &inscriptos.apellido);
    printf("\nIngrese su email: ");
    scanf("%s", &inscriptos.email);
    printf("\nIngrese su categoria:\n");
    printf("1- Estudiante\n");
    printf("2- Profesional\n");
    printf("3- Publico general\n");
    scanf("%d", &inscriptos.codCategoria);
    inscriptos.montoAbonado = calcularMontoAbonar(inscriptos.codCategoria);
    fflush(stdin);
}
int calcularMontoAbonar(int _codCategoria)
{
    return (_codCategoria == 2) || (_codCategoria == 3) ? 350 : 200;
}

void inicializarPila()
{
    pilaInscriptos = NULL;
}

void push(datosInscriptos _inscriptos)
{
    struct nodo *nuevoNodo = (pila *)malloc(sizeof(pila));
    nuevoNodo->siguiente = NULL;
    nuevoNodo->inscriptos = _inscriptos;

    if (pilaVacia())
    {
        pilaInscriptos = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = pilaInscriptos;
        pilaInscriptos = nuevoNodo;
    }
}

void pop()
{
    if (pilaVacia())
    {
        printf("No hay elementos para eliminar");
    }
    else
    {
        struct nodo *aux = pilaInscriptos;
        pilaInscriptos = pilaInscriptos->siguiente;
        printf("Nombre eliminado: %s\n", aux->inscriptos.nombre);
        free(aux);
        aux = NULL;
    }
}

bool pilaVacia()
{
    return pilaInscriptos == NULL;
}

void removerMemoria()
{
    struct nodo *i = pilaInscriptos;
    while (i != NULL)
    {
        struct nodo *nodoAEiminar = i;
        i = i->siguiente;
        free(nodoAEiminar);
        nodoAEiminar = NULL;
    }
    printf("Memoria eliminada correctamente\n");
}
void visualizarPila()
{
    struct nodo *i = pilaInscriptos;

    if (pilaVacia())
    {
        printf("No hay elementos en la lista");
    }
    else
    {
        printf("\n      Cima de la pila\n");
        printf("      ---------------\n");
        while (i != NULL)
        {
            printf("|     Nombre:%s\n|     Email:%d\nV     Monto abonado:%d\n", i->inscriptos.nombre, i->inscriptos.email, i->inscriptos.montoAbonado);
            printf("Dirección: %p\n", (void *)i);
            if (i->siguiente != NULL)
            {
                printf("Siguiente: %p\n", (void *)i->siguiente);
                printf("|");
            }
            else
            {
                printf("Siguiente: NULL\n");
            }
            printf("\n");
            i = i->siguiente;
        }
    }
}

int cantProfesionales()
{
    int totalProfesionales = 0;
    int totalInscriptos = 0;
    struct nodo *i = pilaInscriptos;
    while (i != NULL)
    {
        if (i->inscriptos.codCategoria == 2)
        {
            totalProfesionales++;
        }
        totalInscriptos++;
        i = i->siguiente;
    }
    float promedioProfesionales = (float)totalProfesionales / totalInscriptos;
    printf("La cantidad de profesionales inscriptos es de: %d\n", totalProfesionales);
    printf("El promedio de profesionales es de: %.2f%%\n", promedioProfesionales * 100);
    return totalProfesionales;
}

int montoTotalEstudiantes()
{
    int montoRecaudado = 0;
    struct nodo *i = pilaInscriptos;
    while (i != NULL)
    {
        if (i->inscriptos.codCategoria == 1)
        {
            montoRecaudado += i->inscriptos.montoAbonado;
        }
        i = i->siguiente;
    }
    printf("El monto total recaudado de los estudiantes es de: %d\n", montoRecaudado);
    return montoRecaudado;
}

int montoTotal()
{
    int montoRecaudado = 0;
    struct nodo *i = pilaInscriptos;
    while (i != NULL)
    {

        montoRecaudado += i->inscriptos.montoAbonado;

        i = i->siguiente;
    }
    printf("El monto total recaudado es: %d\n", montoRecaudado);
    return montoRecaudado;
}