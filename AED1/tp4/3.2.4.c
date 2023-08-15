#include <stdio.h>
#include <string.h>

/*
estrategia :
    while (nroSocio !== -9) {
    1.1: pedir al usuario el ingreso del nro socio (int)
    1.2: pedir al usuario el ingreso del titulo de la obra (char)
    1.3: pedir al usuario el tipo de prestamo (1- Lectura en sala, 2-Lectura en domicilio) (int)
     2: mostar por pantalla los datos del usuario que lleva un libro a domicilio ej:
     'El socio 2589 LLEVA A DOMICILIO el título “Algoritmos y Estructuras de Datos”'
      3: contabilizar la cantidad de libros leidos en la sala
      3.1: contabilizar el porcentaje de libros leidos en la sala sobre el total de prestamos
    }
        5: mostrar el resultado final obtenido en la pantalla

*/

int nroSocio;
char tituloObra[30];
int tipoPrestamo;
int totalLibrosSala;
int totalLibrosPrestamo;

void pedirDatos();
void mostrarDatos();
void devolverPorcentaje();

int main()
{
    while (nroSocio != -9)
    {
        pedirDatos();
        if (tipoPrestamo == 2)
        {
            totalLibrosPrestamo++;
            mostrarDatos();
        }
        else if (tipoPrestamo == 1)
        {
            totalLibrosSala++;
        }
        else
        {
            printf("El dato ingresado no es valido");
            return 1;
        }
    }
    devolverPorcentaje();
    return 1;
}

void pedirDatos()
{
    printf("Ingrese su numero de socio: \n");
    scanf("%d", &nroSocio);
    fflush(stdin);
    printf("Ingrese el titulo de la obra \n");
    scanf("%[^\n]s", &tituloObra);
    fflush(stdin);
    printf("Ingrese el tipo de prestamo \n");
    printf("1- Lectura en sala, 2-Lectura en domicilio \n");
    scanf("%d", &tipoPrestamo);
    fflush(stdin);
}
void mostrarDatos()
{
    printf("El socio %d \n", nroSocio);
    printf("Lleva a domicilio ");
    printf("El titulo: %s \n", tituloObra);
}

void devolverPorcentaje()
{
    float resultado = (float)totalLibrosSala / totalLibrosPrestamo * 100;
    printf("El porcentaje de libros leidos en la sala sobre prestados es de %.2f%%", resultado);
}
