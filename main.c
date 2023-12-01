#include "2048.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
int main()
{
    int a[4][4] = {0};
    srand(time(NULL));
    Input(a);
    do
    {
        Input(a);
        system("cls");
        Output(a);
        MoveAndAdd(a);
        system("cls");
        Output(a);
    }while(!GameOver(a));
    printf("”Œœ∑Ω· ¯£°");
    system("pause");
    return 0;
}