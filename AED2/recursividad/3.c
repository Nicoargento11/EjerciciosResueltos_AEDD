#include <stdio.h>

int num = 0;

int numeroInvertido(int _num)
{
    if (_num < 1)
    {
        return 1;
    }
    printf("%d", _num % 10);
    numeroInvertido(_num / 10);
}
int main()
{
    printf("ingrese un numero: ");
    scanf("%d", &num);
    numeroInvertido(num);
    return 1;
}

// 123%10       3
// 123/10 12

// 12%10        2
// 12/10 1

// 1%10         1
// 1%10 0 FIN
