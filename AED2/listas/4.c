// Nombre: Nicolas Valdes
// DNI: 45248190
// Comision: 3

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

typedef char string[20];

// tipo definido para los datos de la persona
typedef struct
{
    char sexo;
    int edad;
    int peso;
    int altura;
    string imc;
} datosPersonas;

// tipo definido de los nodos
typedef struct nodo
{
    datosPersonas persona;
    struct nodo *siguiente;
} lista;

// Arreglo para guardar los tipos de clasificaciones
string clasificaciones[] = {"Peso bajo", "Peso normal", "Sobrepeso"};

// declaramos el primer nodo
lista *listaPersonas;

// declaramos una variable estructura de los datos para añadirlos a los nodos
datosPersonas personas;

// funciones de lista
bool listaVacia();
void inicializarLista();
void visualizarLista();
void vaciarMemoria();

void insertarNodo(datosPersonas);
void insertarK(datosPersonas, int);

void eliminarNodo();
void eliminarK(int);

// funciones del ejercicio
void ingresarDatos();
int calcularIMC(int, int, char);
int cantidadEncuestados();
void calcularPesoBajo();
void listaSobrepeso();

void menu();

int main()
{
    inicializarLista();
    menu();
    vaciarMemoria();
    return 1;
}

void menu()
{
    // variables para la eleccion de acciones
    int eleccion = 0;
    int pos = 0;

    // mostraremos el menu hasta que quiera finalizar
    while (eleccion != -1)
    {
        // si esta vacia la lista lo unico que podra hacer es ingresar datos
        if (listaVacia())
        {
            printf("La lista se encuentra vacia ingrese los datos correspondientes\n");
            ingresarDatos();
            insertarNodo(personas);
        }
        else
        {
            // acciones que puede realizar el usuario
            printf("\nQue desea hacer:\n");

            printf("1- Insertar\n");
            printf("2-Eliminar\n");
            printf("3-Insertar K\n");
            printf("4-Eliminar K\n");
            printf("5-Porcentaje de personas con bajo peso, mayores de 15 años\n");
            printf("6-Lista de Personas con sobrepeso\n");
            printf("-1 Finalizar\n");
            scanf("%d", &eleccion);
            fflush(stdin);

            switch (eleccion)
            {
            case 1:
                ingresarDatos();
                insertarNodo(personas);
                break;
            case 2:
                eliminarNodo();
                break;
            case 3:
                printf("Ingresa la posicion a insertar: ");
                scanf("%d", &pos);
                ingresarDatos();
                insertarK(personas, pos);
                break;
            case 4:
                printf("Ingresa la posicion a eliminar: ");
                scanf("%d", &pos);
                fflush(stdin);
                eliminarK(pos);
                break;
            case 5:
                calcularPesoBajo();
                break;
            case 6:
                listaSobrepeso();
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

    printf("Cantidad total de encuestados: %d", cantidadEncuestados());

    listaSobrepeso();
    calcularPesoBajo();
}

void inicializarLista()
{
    // inicializamos la lista
    listaPersonas = NULL;
}

void ingresarDatos()
{
    // guardamos los datos ingresados en una structura
    printf("Ingresa la altura en cm: ");
    scanf("%d", &personas.altura);
    fflush(stdin);
    printf("Ingresa la edad:(01. Menor de 15 años, 02. Entre 15 y 30 años, 03. Más de 30 años)\n");
    scanf("%d", &personas.edad);
    fflush(stdin);
    printf("Ingresa el peso kg: ");
    scanf("%d", &personas.peso);
    fflush(stdin);
    printf("Ingresa el sexo del alumno:\nF: femenino,M: masculino\n");
    scanf("%c", &personas.sexo);
    fflush(stdin);
    // copiamos la posicion de clasificaciones que va a estar dada por el resultado de la funcion calcularIMC
    strcpy(personas.imc, clasificaciones[calcularIMC(personas.peso, personas.altura, personas.sexo)]);
}

void insertarNodo(datosPersonas _datos)
{
    // declaramos un nuevo nodo y reservamos espacio de memoria en base al tañamo de nuestro nodo
    lista *nuevoNodo = (lista *)malloc(sizeof(lista));
    // guardamos los datos en el nuevoNodo
    nuevoNodo->persona = _datos;
    // asignamos NULL al siguiente del nuevoNodo
    nuevoNodo->siguiente = NULL;

    // si esta vacia lo ingresaremos sin problemas
    if (listaVacia())
    {
        listaPersonas = nuevoNodo;
    }
    else
    {
        // si no esta vacia, recorremos hasta llegar al ultimo nodo
        // creamos un auxiliar para que pueda recorrer la lista y no modificar la original
        lista *aux = listaPersonas;
        while (aux->siguiente != NULL)
        {
            // si no es NULL significa que no llegamos al final y debemos seguir avanzando
            aux = aux->siguiente;
        }
        // una vez llegamos al ultimo Nodo insertamos el nuevoNodo en el siguiente del ultimo
        aux->siguiente = nuevoNodo;
    }
}

void insertarK(datosPersonas _datos, int _pos)
{
    // declaramos un nuevo nodo
    lista *nuevoNodo = (lista *)malloc(sizeof(lista));
    // guardamos los datos en el nuevoNodo
    nuevoNodo->persona = _datos;
    // asignamos NULL al siguiente del nuevoNodo
    nuevoNodo->siguiente = NULL;

    // si el numero ingresado no es valido mostramos un mensaje de error
    if (_pos > cantidadEncuestados() || _pos < 0)
    {
        printf("la posicion ingresada no es valida");
        return;
    }
    // si esta vacia lo ingresaremos sin problemas
    if (listaVacia())
    {
        listaPersonas = nuevoNodo;
    }
    // al querer insertar en el primer lugar tenemos que usar una logica diferente
    // ya que nuestro bucle for no funciona para el primer elemento ya que siempre
    // va a estar posicionado en el primer elemento y no nos sirve
    else if (_pos == 0)
    {
        // el siguiente del nuevoNodo va a ser el que era primero
        nuevoNodo->siguiente = listaPersonas;
        // el primero pasa a ser el nuevoNodo
        listaPersonas = nuevoNodo;
    }
    else
    {
        // creamos un auxiliar para llegar hasta el anterior de la posicion k
        lista *anterior = listaPersonas;
        for (int i = 0; i < _pos - 1; i++)
        {
            anterior = anterior->siguiente;
        }
        // el siguiente del nuevoNodo va a apuntar hacia el nodo K
        nuevoNodo->siguiente = anterior->siguiente;
        // el nodo anterior al K va a apuntar al nodoNuevo
        anterior->siguiente = nuevoNodo;
    }
}

void eliminarNodo()
{
    // no podemos eliminar nodos si esta vacia
    if (listaVacia())
    {
        printf("No existen nodos para eliminar");
    }
    else
    {
        lista *aux = listaPersonas;
        if (aux->siguiente == NULL)
        {
            inicializarLista();
            free(aux);
        }
        else
        {

            while (aux->siguiente->siguiente != NULL)
            {
                aux = aux->siguiente;
            }
            // utilizamos un aux para llegar al anteultimo nodo, si llegamos al ultimo no lo podemos eliminar porque no podemos cambiar la direccion del anterior
            // estamos en el anterior
            // su siguiente es el ultimo
            // guardamos el ultimo para despues eliminarlo
            lista *nodoAEliminar = aux->siguiente;
            // sacamos al ultimo de la lista
            aux->siguiente = NULL;
            // lo eliminamos
            free(nodoAEliminar);
        }
    }
}

void eliminarK(int _pos)
{
    // si el numero ingresado no es valido mostramos un mensaje de error
    if (_pos > cantidadEncuestados() || _pos < 0)
    {
        printf("la posicion ingresada no es valida\n");
        return;
    }
    // no podemos eliminar nodos si esta vacia
    if (listaVacia())
    {
        printf("No hay elementos para eliminar");
        return;
    }
    // caso especial
    else if (_pos == 0)
    {
        lista *aux = listaPersonas;
        listaPersonas = listaPersonas->siguiente;
        free(aux);
    }
    else
    {
        lista *anterior = listaPersonas;
        // nos posicionamos en el anterior de K
        for (int i = 0; i < _pos - 1; i++)
        {
            anterior = anterior->siguiente;
        }
        // lo guardamos a k
        lista *aux = anterior->siguiente;
        // el anterior se va a saltear a k
        anterior->siguiente = aux->siguiente;
        // eliminamos k
        free(aux);
    }
}

int cantidadEncuestados()
{
    // contamos encuestados x cada lista sumamos al contador
    int contador = 0;
    lista *indice = listaPersonas;
    while (indice != NULL)
    {
        contador++;
        indice = indice->siguiente;
    }
    return contador;
}

int calcularIMC(int _peso, int _altura, char _sexo)
{
    // conversion de datos
    float metros = (float)_altura / 100;
    // Calculo del IMC Kg/m^2
    float imc = (float)_peso / pow((metros), 2);

    // Si es fememino
    // Dependiendo el imc devolveremos un numero del 0-2 que esta relacionado con el arreglo de clasificaciones
    if (toupper(_sexo) == 'F')
    {
        if (imc < 20)
        {
            return 0;
        }
        else if (imc >= 20 && imc <= 25)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    // Si es masculino
    else if (toupper(_sexo) == 'M')
    {
        if (imc < 19)
        {
            return 0;
        }
        else if (imc >= 19 && imc <= 24)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    // caso de error
    else
    {
        printf("El sexo ingresado no es valido");
        return -1;
    }
}

void calcularPesoBajo()
{
    // recorremos la lista
    lista *indice = listaPersonas;
    int cantPesoBajo = 0;
    while (indice != NULL)
    {
        // si encontramos un nodo que cumpla las condiciones sumamos
        if (strcmp(indice->persona.imc, "Peso bajo") == 0 && indice->persona.edad <= 1)
        {
            cantPesoBajo++;
        }
        indice = indice->siguiente;
    }
    // sacamos el promedio con la cantidad total
    float promedio = (float)cantPesoBajo / cantidadEncuestados();
    printf("\nEl promedio de personas de bajo peso es: %.2f%%\n\n", promedio * 100);
}

void listaSobrepeso()
{
    // recorremos la lita
    lista *indice = listaPersonas;
    printf("\nPersonas con sobrepeso:\n");
    while (indice != NULL)
    {
        // si encontramos un nodo que cumpla las condiciones la mostramos
        if (strcmp(indice->persona.imc, "Sobrepeso") == 0)
        {
            printf("Sexo:%c, Edad:%d\nPeso:%d, Altura:%d\nIMC:%s\n\n", indice->persona.sexo, indice->persona.edad, indice->persona.peso, indice->persona.altura, indice->persona.imc);
        }

        indice = indice->siguiente;
    }
}

void visualizarLista()
{
    // recorremos la lista
    lista *i = listaPersonas;
    if (listaVacia())
    {
        printf("No hay elementos en la lista");
    }
    else
    {

        while (i != NULL)
        {
            // visualizamos cada nodo
            printf("|     Sexo:%c\n|     Edad:%d\n|     Peso:%d\n|     Altura:%d\nV     IMC:%s\n", i->persona.sexo, i->persona.edad, i->persona.peso, i->persona.altura, i->persona.imc);
            printf("Dirección: %p\n", (void *)i);
            if (i->siguiente != NULL)
            {
                printf("Siguiente: %p\n", (void *)i->siguiente);
                printf("|");
            }
            else
            // si estamos en el ultimo
            {
                printf("Siguiente: NULL\n");
            }
            printf("\n");
            i = i->siguiente;
        }
    }
}

bool listaVacia()
{
    return listaPersonas == NULL;
}

void vaciarMemoria()
{
    lista *actual = listaPersonas;
    while (actual != NULL)
    {
        lista *aux = actual;
        actual = actual->siguiente;
        free(aux);
    }
    printf("\nMemoria vaciada correctamente");
}
