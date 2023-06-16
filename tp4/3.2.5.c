#include <stdio.h>

/*
Estrategia:
while (finalizar !== 'S') {
    1.1: pedir al usuario el ingreso del DNI. (int)
    1.2: pedir al usuario el ingreso de la edad. (int)
    1.3: pedir al usuario el ingreso del sexo. "M-masculuno, F-femenino" (char)
    1.4: pedir al usuario el ingreso de la categoria. "N-niños, C-cadetes" (char)
    1.5: pedir al usuario el ingreso de la provincia de origen. "1-Chaco, 2- Formosa, 3-Corrientes" (int)
     2.1: si los datos son iguales a: mujeres && cadetes && (Corrientes || Chaco). Mostrar su DNI por pantalla
     2.2: imprimir cantidad de: (10 <= varones <= 12) && Formosa.
      3.1: Funcion para pedir datos.
      3.2: Funcion para saber si mostrar DNI.
      3.3: Funcion para mostrar el punto 2.2.

}
*/
int varonesFormosa = 0;
char finalizar;
int documento;
int edad;
char categoria;
char sexo;
int origen;

void pedirDatos();
void mostrarDni();

int main()
{
    while (finalizar != 'S')
    {
        pedirDatos();

        if (sexo == 'F' && categoria == 'C' && (origen == 3 || origen == 1))
        {
            mostrarDni();
        }
        printf("\nDesea finalizar el programa? (S/N) ");
        scanf("%c", &finalizar);
        fflush(stdin);
    }
    printf("La cantidad total de varones entre 10 y 12 años de Formosa es de: %d", varonesFormosa);
    return 1;
}

void pedirDatos()
{
    printf("Ingrese su numero de documento: ");
    if (scanf("%d", &documento) != 1)
    {
        printf("Error: debe ingresar un número entero.\n");
        fflush(stdin);
        return;
    }
    fflush(stdin);

    printf("\nIngrese su edad: ");
    if (scanf("%d", &edad) != 1 || edad < 0)
    {
        printf("Error: debe ingresar un número entero positivo.\n");
        fflush(stdin);
        return;
    }
    fflush(stdin);

    printf("\nIngrese su sexo (M/F): ");
    if (scanf(" %c", &sexo) != 1 || (sexo != 'M' && sexo != 'F'))
    {
        printf("Error: debe ingresar 'M' o 'F'.\n");
        fflush(stdin);
        return;
    }
    fflush(stdin);

    printf("\nIngrese su categoria");
    printf("\nN-Niños, C-Cadetes ");
    if (scanf(" %c", &categoria) != 1 || (categoria != 'N' && categoria != 'C'))
    {
        printf("Error: debe ingresar 'N' o 'C'.\n");
        fflush(stdin);
        return;
    }
    fflush(stdin);

    printf("\nIngrese su provincia de origen: ");
    printf("\n1-Chaco, 2- Formosa, 3-Corrientes \n ");
    if (scanf("%d", &origen) != 1 || (origen != 1 && origen != 2 && origen != 3))
    {
        printf("Error: debe ingresar un número entre 1 y 3.\n");
        fflush(stdin);
        return;
    }
    fflush(stdin);

    if (sexo == 'M' && (edad >= 10 && edad <= 12) && origen == 2)
    {
        varonesFormosa++;
    }
}

void mostrarDni()
{
    printf("El DNI del usuario es : %d", documento);
}