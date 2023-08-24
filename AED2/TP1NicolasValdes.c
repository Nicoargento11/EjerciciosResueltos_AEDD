// Nombre: Nicolas Valdes
// DNI: 45248190
// Comision: 3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// tipoos punto 6
typedef char *apuntadorC;
// tipos punto 7
typedef int *tpEntero;
typedef char *tpCaracter;

void punto6();
void punto7a();
void punto7b();
void punto7c();

int main()
{
    punto6();
    punto7a();
    punto7b();
    punto7c();
    return 1;
}

void punto6()
{
    apuntadorC a1, a2;
    a1 = (apuntadorC)malloc(sizeof(char));
    a2 = (apuntadorC)malloc(sizeof(char));
    *a1 = 'A';
    *a2 = 'B';
    printf("%c \n", *a1);
    printf("%c \n", *a2);
}
// RTA: la salida de la linea 19 va a ser "A" y la salida de la linea 20 va a ser "B". Esto sucede ya que estamos declarando dos variables e inicializandolas con una memoria dinamica.A su vez le asignamos un valor (char) a la memoria y por ultimo imprimimos dicho valor.

void punto7a()
{
    tpEntero p1, p2;

    p1 = (tpEntero)malloc(sizeof(int));
    p2 = (tpEntero)malloc(sizeof(int));
    *p1 = 5;
    *p2 = *p1 + 20;
    printf("*p1 igual a %d, *p2 igual a %d\n", *p1, *p2);
}
// RTA: la salida de la linea 40 va a ser la memoria de p1 = 5, y la memoria de p2 = 25

void punto7b()
{
    tpEntero p1, p2;

    p2 = (tpEntero)malloc(sizeof(int));
    *p2 = 2;
    *p2 = pow(*p2, 2);
    p1 = (tpEntero)malloc(sizeof(int));
    *p1 = fmod(*p2, 3);
    printf("*p1 igual a %d, *p2 igual a %d\n", *p1, *p2);
}
// RTA: la salida de la linea 57 va a ser la memoria de p1 = 1, y la memoria de p2 = 4

void punto7c()
{
    tpCaracter q1, q2, q3;

    q1 = (tpCaracter)malloc(sizeof(char));
    q2 = (tpCaracter)malloc(sizeof(char));
    q3 = (tpCaracter)malloc(sizeof(char));
    *q1 = 'Y';
    *q2 = (*q1) - 1;
    *q3 = (*q1) + 1;
    printf("*q1 igual a %c, *q2 igual a %c, q3 igual a %c\n", *q1, *q2, *q3);
}
// RTA: la salida de la linea 70 va a ser la memoria de q1 = Y, la memoria de q2 = X, y la memoria de q3 = Z.Esto ocurre ya que es el orden en el que esta el codigo ASCII
