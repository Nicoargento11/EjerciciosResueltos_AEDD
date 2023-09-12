#include <stdio.h>
#include <math.h>

int num = 0;
int pasarABinario(int _num)
{

    if (_num < 2)
    {
        printf("%d", _num);
        return 1;
    }

    pasarABinario(_num / 2);
    printf("%d", _num % 2);
}
int main()
{
    printf("Ingrese un numero: \n");
    scanf("%d", &num);
    pasarABinario(num);
}

// 100/2 50/2  25/2  12/2  6/2  3/2
//   0    0     1     0     0    1   c:1