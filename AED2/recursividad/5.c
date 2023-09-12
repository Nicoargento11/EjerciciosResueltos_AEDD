#include <stdio.h>
#include <windows.h>

int num = 0;

int cuentaRegresiva(int _num)
{
    if (_num == 0)
    {
        printf("\n");
        return 0;
    }
    Sleep(250);
    printf("%d ", _num);
    cuentaRegresiva(_num - 1);
    Sleep(250);
    printf("%d ", _num);
}

int main()
{
    printf("Ingresa un numero: \n");
    scanf("%d", &num);
    cuentaRegresiva(num);
    return 1;
}
