typedef char string[30];

typedef struct nodo
{
    int codigo;
    string descripcion;
    struct nodo *izquierda;
    struct nodo *derecha;

} tArbolTipoProductos;