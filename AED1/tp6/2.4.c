#include <stdio.h>
#include <string.h>

/*
 El Ministerio de Salud de la Argentina lleva un registro diario de nuevos casos de COVID 19 de los últimos
3 meses: marzo, abril y mayo. Genere una matriz ingresando por teclado: mes, día y cantidad de nuevos
casos. Genere un vector que registre el acumulado mensual. Determine la mayor cantidad de casos nuevos
y a que día y mes corresponde. Determine la menor cantidad de casos nuevos y a que día y mes
corresponde. Al final muestre los datos de la matriz y el vector con los datos acumulados. **nota: para
simplificar la prueba considere solo 5 días de cada mes.
*/

// total dias
#define DIAS 3

// total meses
#define MESES 3

// tipo personalizado para cadenas de texto
typedef char string[20];

// datos para mayor/menor cantidad de casos
typedef struct
{
    int cantCasos;
    int dia;
    int mes;
} datosCantidad;

// estructura para guardar momentaneamente los datos, una vez ingresado lo necesario lo mando al array con los datos de COVID (casos)
struct
{
    int dia;
    int mes;
    int casos;
} datosCovid;

// array para almacenar los casos
int casos[DIAS][MESES];

// array para mostrar los meses de los casos
string meses[3] = {"Marzo", "Abril", "Mayo"};

// acumulador de casos
int totalCasos = 0;

// longitud total de los casos
int longitud = sizeof(casos) / sizeof(casos[0][0]);

// variables para guardar los datos en el que ocurrio la mayor y menor cantidad de casos
datosCantidad mayorCasos;
datosCantidad menorCasos;

// filtrar que dia y mes ocurrio el mayor/menor caso de COVID, como asi tambien su cantidad
void calcularMayorCasos();
void calcularMenorCasos();

main()
{
    // pedido de datos en base a la cantidad de dias/meses
    for (int i = 0; i < longitud; i++)
    {
        // utilizo un do while por si el usuario ingresa un dia que ya ingreso
        do
        {
            printf("Ingrese el dia: ");
            scanf("%d", &datosCovid.dia);
            fflush(stdin);
            printf("Ingrese el mes: \n1-Marzo\n2-Abril\n3-Mayo\n");
            scanf("%d", &datosCovid.mes);

            // error por si ya ha ingresado una fecha anteriormente
            if (casos[datosCovid.dia - 1][datosCovid.mes - 1] > 0)
            {
                printf("Ya se han ingresado los casos de COVID en este dia, pruebe con otro.\n");
            }

            // si la fecha no ha sido ingresada continuara, y sino volvera a preguntar
        } while (casos[datosCovid.dia - 1][datosCovid.mes - 1] > 0);

        printf("Ingrese la cantidad de casos de COVID: ");
        scanf("%d", &datosCovid.casos);
        fflush(stdin);

        // guardo la cant en el array con todos los casos
        casos[datosCovid.dia - 1][datosCovid.mes - 1] = datosCovid.casos;

        // acumulo los casos, para devolver el total anual de casos
        totalCasos += casos[datosCovid.dia - 1][datosCovid.mes - 1];
    }
    printf("La cantidad de casos totales es de: %d\n", totalCasos);

    // Calculo y muestro la cantidad mayor/menor de casos con sus datos: dia, mes, cantidad
    calcularMayorCasos();
    calcularMenorCasos();
    return 1;
}

void calcularMayorCasos()
{
    mayorCasos.cantCasos = 0;
    for (int i = 0; i < MESES / 3; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            if (mayorCasos.cantCasos < casos[i][j])
            {
                mayorCasos.cantCasos = casos[i][j];
                mayorCasos.dia = j + 1;
                mayorCasos.mes = i;
            }
        }
    }
    printf("\nEl dia que mas caso hubo fue el %d de %s con un total de %d casos\n", mayorCasos.dia, meses[mayorCasos.mes], mayorCasos.cantCasos);
}

void calcularMenorCasos()
{
    menorCasos.cantCasos = casos[0][0];
    for (int i = 0; i < MESES / 3; i++)
    {
        for (int j = 0; j < DIAS; j++)
        {
            if (menorCasos.cantCasos > casos[i][j])
            {
                menorCasos.cantCasos = casos[i][j];
                menorCasos.dia = j + 1;
                menorCasos.mes = i;
            }
        }
    }
    printf("El dia que menos caso hubo fue el %d de %s con un total de %d casos", menorCasos.dia, meses[menorCasos.mes], menorCasos.cantCasos);
}