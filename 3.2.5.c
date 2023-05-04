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
    scanf("%d", &documento);
    fflush(stdin);
    printf("\nIngrese su edad: ");
    scanf("%d", &edad);
    fflush(stdin);
    printf("\nIngrese su sexo (M/F): ");
    scanf("%c", &sexo);
    fflush(stdin);
    printf("\nIngrese su categoria");
    printf("\nN-Niños, C-Cadetes ");
    scanf("%c", &categoria);
    fflush(stdin);
    printf("\nIngrese su provincia de origen: ");
    printf("\n1-Chaco, 2- Formosa, 3-Corrientes \n ");
    scanf("%d", &origen);
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