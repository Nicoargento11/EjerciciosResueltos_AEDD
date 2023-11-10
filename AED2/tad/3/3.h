#include <stdbool.h>

int calcularMayorValor(int, int);
int calcularMenorValor(int, int);
bool calcularIgualValor(int, int);
void intercambiarValores(int *, int *);

int calcularMayorValor(int pNum1, int pNum2)
{
    int valorMayor = pNum1 > pNum2 ? pNum1 : pNum2;
    return valorMayor;
}
int calcularMenorValor(int pNum1, int pNum2)
{
    int valorMenor = pNum1 < pNum2 ? pNum1 : pNum2;
    return valorMenor;
}
bool calcularIgualValor(int pNum1, int pNum2)
{
    return pNum1 == pNum2;
}

void intercambiarValores(int *pNum1, int *pNum2)
{
    int aux = *pNum1;
    *pNum1 = *pNum2;
    *pNum2 = aux;
}