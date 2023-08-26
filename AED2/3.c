// Nombre: Nicolas Valdes
// DNI: 45248190
// Comision: 3

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef char string[30];

typedef struct
{
    int libreta;
    string nombre;
} datosAlumno;

typedef struct nodo
{
    datosAlumno alumno;
    struct nodo *siguiente;
} lista;

lista *listaAlumno;
datosAlumno alumno;

void generarLista();

void insertarPrimer(datosAlumno);
void insertarInicio(datosAlumno);
void insertarCualquierPos(datosAlumno, int);

void eliminarCualquierPos(int);
void eliminarPrimer();

int contarALumnos();
void visualizarLista();
void ingresarDatosAlumno();
void menuPrincipal();
bool listaVacia();
void vaciarMemoria();

int main()
{
    generarLista();
    menuPrincipal();
    vaciarMemoria();

    return 1;
}

void vaciarMemoria()
{
    lista *actual = listaAlumno;
    while (actual != NULL)
    {
        lista *temp = actual;
        actual = actual->siguiente;
        free(temp);
    }
    printf("\nMemoria eliminada correctamente");
}

void insertarPrimer(datosAlumno _alumno)
{
    lista *primerNodo = (lista *)malloc(sizeof(lista));

    primerNodo->alumno.libreta = _alumno.libreta;
    strcpy(primerNodo->alumno.nombre, _alumno.nombre);
    primerNodo->siguiente = NULL;

    if (listaVacia())
    {
        listaAlumno = primerNodo;
    }
    else
    {
        printf("La lista ya tiene elementos");
        return;
    }
}

void insertarInicio(datosAlumno _alumno)
{
    lista *primerNodo = (lista *)malloc(sizeof(lista));
    primerNodo->alumno.libreta = _alumno.libreta;
    strcpy(primerNodo->alumno.nombre, _alumno.nombre);
    primerNodo->siguiente = NULL;

    if (listaVacia())
    {
        listaAlumno = primerNodo;
    }
    else
    {
        primerNodo->siguiente = listaAlumno;
        listaAlumno = primerNodo;
    }
}

void insertarCualquierPos(datosAlumno _alumno, int _pos)
{
    lista *nuevoNodo = (lista *)malloc(sizeof(lista));
    nuevoNodo->alumno.libreta = _alumno.libreta;
    strcpy(nuevoNodo->alumno.nombre, _alumno.nombre);
    nuevoNodo->siguiente = NULL;

    if (_pos > contarALumnos() || _pos < 0)
    {
        printf("la posicion ingresada no es valida");
        return;
    }
    if (listaVacia())
    {
        listaAlumno = nuevoNodo;
    }
    else
    {
        lista *anterior = listaAlumno;
        for (int i = 0; i < _pos - 1; i++)
        {
            anterior = anterior->siguiente;
        }
        nuevoNodo->siguiente = anterior->siguiente;
        anterior->siguiente = nuevoNodo;
    }
}

void eliminarCualquierPos(int _pos)
{
    if (_pos > contarALumnos() || _pos < 0)
    {
        printf("la posicion ingresada no es valida\n");
        return;
    }
    if (listaVacia())
    {
        printf("No hay elementos para eliminar");
        return;
    }
    else if (_pos == 0)
    {
        lista *aux = listaAlumno;
        listaAlumno = listaAlumno->siguiente;
        free(aux);
    }
    else
    {
        lista *anterior = listaAlumno;
        for (int i = 0; i < _pos - 1; i++)
        {
            anterior = anterior->siguiente;
        }
        lista *aux = anterior->siguiente;
        anterior->siguiente = aux->siguiente;
        free(aux);
    }
}

void eliminarPrimer()
{
    if (listaVacia())
    {
        printf("No hay elementos para eliminar");
        return;
    }
    else
    {
        lista *aux = listaAlumno;
        listaAlumno = listaAlumno->siguiente;
        free(aux);
    }
}

void generarLista()
{
    listaAlumno = NULL;
}

bool listaVacia()
{
    return listaAlumno == NULL;
}

void visualizarLista()
{
    lista *i = listaAlumno;
    if (listaVacia())
    {
        printf("No hay elementos en la lista");
    }
    else
    {

        while (i != NULL)
        {
            printf("|     Codigo:%d\nV     Nombre:%s\n", i->alumno.libreta, i->alumno.nombre);
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
        printf("TAMAÑO: %d", contarALumnos());
    }
}

void menuPrincipal()
{
    int eleccion = 0;
    int pos = 0;
    while (eleccion != -1)
    {
        if (listaVacia())
        {
            printf("La lista se encuentra vacia. Ingrese un alumno\n");
            ingresarDatosAlumno();
            insertarPrimer(alumno);
        }
        else
        {
            printf("\nQue desea hacer ahora:\n1- Insertar alumno al inicio\n2-Eliminar el primer alumno\n3-Insertar un alumno cualquier posicion\n4-Eliminar un alumno de cualquier posicion\n-1 Finalizar\n");
            scanf("%d", &eleccion);
            fflush(stdin);

            switch (eleccion)
            {
            case 1:
                ingresarDatosAlumno();
                insertarInicio(alumno);
                break;
            case 2:
                eliminarPrimer();
                break;
            case 3:
                printf("Ingresa la posicion a insertar: ");
                scanf("%d", &pos);
                ingresarDatosAlumno();
                insertarCualquierPos(alumno, pos);
                break;
            case 4:
                printf("Ingresa la posicion a eliminar: ");
                scanf("%d", &pos);
                fflush(stdin);
                eliminarCualquierPos(pos);
                break;
            case -1:
                printf("Programa finalizado\n\n");
                break;
            default:
                printf("El numero ingresado no es valido");
                break;
            }
        }
    }
    visualizarLista();
}

void ingresarDatosAlumno()
{
    printf("Ingresa el numero de libreta : ");
    scanf("%d", &alumno.libreta);
    fflush(stdin);
    printf("Ingresa el nombre del alumno: ");
    scanf("%[^\n]s", &alumno.nombre);
    fflush(stdin);
}

int contarALumnos()
{
    int contador = 0;
    lista *primerNodo = listaAlumno;

    while (primerNodo != NULL)
    {
        primerNodo = primerNodo->siguiente;
        contador++;
    }
    return contador;
}