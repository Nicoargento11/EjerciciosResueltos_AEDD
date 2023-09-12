#include <stdio.h>

int num = 0;

int cuentaRegresiva(int _num)
{
    if (_num == 0)
    {
        return 0;
    }
    printf("%d ", _num);
    cuentaRegresiva(_num - 1);
}

int main()
{
    printf("Ingresa un numero: \n");
    scanf("%d", &num);
    cuentaRegresiva(num);
    return 1;
}
