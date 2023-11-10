#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *archivoTexto;

void leerArchivo()
{
    archivoTexto = fopen("Fix_you.txt", "r");

    verificarArchivo();

    char c = fgetc(archivoTexto);
    while (!feof(archivoTexto))
    {
        printf("%c", c);
        c = getc(archivoTexto);
    }
}
void verificarArchivo()
{
    // el archivo no existe
    if (archivoTexto == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

int main()
{
    // siempre cerrarlo luego de abrirlo
    leerArchivo();
    fclose(archivoTexto);

    return 1;
}
