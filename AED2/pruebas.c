

// Definición de una estructura llamada "nodo" para una lista enlazada
typedef struct nodo // nombre de la estructura
{
    int producto;           // Contenido del nodo
    struct nodo *siguiente; // Puntero al siguiente nodo
} lista;                    // Nombre de tipo para la estructura (variable)

// Ejemplos de cómo usar la estructura:

lista *miLista1;       // Declaración de una variable de tipo "lista"
struct nodo *miLista2; // Declaración de una variable utilizando el nombre de la estructura "nodo"

int main()
{
    miLista1->producto;
    miLista2->producto;
    return 1;
}