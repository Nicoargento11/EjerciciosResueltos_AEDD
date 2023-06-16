#include <stdio.h>

int nroUsuario;
int categoria;
float importeFacturado;

int totalImporte = 0;
int usuarioResidencial = 0;

void pedirDatos();
float calcularPorcentaje();

int main()
{
    pedirDatos();
    printf("El resultado del porcentaje es: %.2f%%", calcularPorcentaje());
    return 0;
}

void pedirDatos()
{
    int cantUsuarios = 2;
    int contador = 0;

    while (cantUsuarios != contador)
    {
        printf("Ingrese su numero de usuario \n");
        scanf("%d", &nroUsuario);
        fflush(stdin);
        printf("Ingrese su categoria: \n");
        printf("1-residencial 2-comercial 3-industrial \n");
        scanf("%d", &categoria);
        fflush(stdin);
        printf("Ingrese el importe \n");
        scanf("%f", &importeFacturado);
        fflush(stdin);
        contador++;
        totalImporte += importeFacturado;
        if (categoria == 1)
        {
            usuarioResidencial += importeFacturado;
        }
    }
    printf("La cantidad de usuarios ingresados es suficiente \n");
}

float calcularPorcentaje()
{
    float resultado = (float)usuarioResidencial / totalImporte * 100;
    return resultado;
}