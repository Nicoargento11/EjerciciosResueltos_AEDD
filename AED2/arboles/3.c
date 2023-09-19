typedef char string[30];

typedef struct nodo
{
    int codigo;
    string parentesco;
    struct nodo *izquierda;
    struct nodo *derecha;

} tArbolTipoParientes;