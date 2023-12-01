#include "2048.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>
void Input(int a[4][4])
{
    int i, j, count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
            {
                goto END;
            }
            else
            {
                count++;
            }
        }
    }
    if (count == 16)
    {
        return;
    }
END:
    do
    {
        i = rand() % 4;
        j = rand() % 4;
    } while (a[i][j] != 0);
    int k = rand() % 2;
    if (k)
    {
        a[i][j] = 2;
    }
    else
    {
        a[i][j] = 4;
    }
}
void Output(int a[4][4])
{
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)(log(a[i][j]) / log(2)));
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            sum += a[i][j];
        }
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printf("当前分数为：%d\n", sum);
}
int GameOver(int a[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
            {
                return 0;
            }
        }
    }
    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j < 3; j++)
        {
            if (a[i][j] == a[i - 1][j] || a[i][j] == a[i + 1][j] || a[i][j] == a[i][j + 1] || a[i][j] == a[i][j - 1])
            {
                return 0;
            }
        }
    }
    if (a[0][0] == a[1][0] || a[0][0] == a[0][1])
    {
        return 0;
    }
    if (a[0][3] == a[1][3] || a[0][3] == a[0][2])
    {
        return 0;
    }
    if (a[3][0] == a[3][1] || a[3][0] == a[2][0])
    {
        return 0;
    }
    if (a[3][3] == a[2][3] || a[3][3] == a[3][2])
    {
        return 0;
    }
    return 1;
}
void MoveAndAdd(int a[4][4])
{
    char c;
    int p,s,g;
START:
    s = scanf(" %c", &c);
    g = getchar();
    if (c == 'w')
    {
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                if (a[i][j] == 0)
                {
                    continue;
                }
                else if (i > 0 && a[i][j] == a[i - 1][j])
                {
                    a[i - 1][j] += a[i][j];
                    a[i][j] = 0;
                }
                else if (i > 1 && a[i][j] == a[i - 2][j] && a[i - 1][j] == 0)
                {
                    a[i - 2][j] += a[i][j];
                    a[i][j] = 0;
                }
                else if (i > 2 && a[i][j] == a[i - 3][j] && a[i - 1][j] == 0 && a[i - 2][j] == 0)
                {
                    a[i - 3][j] += a[i][j];
                    a[i][j] = 0;
                }
                else
                {
                    continue;
                }
            }
        }
        for (int j = 0; j < 4; j++)
        {
            for (int i = 0; i < 4; i++)
            {
                p = i;
                while (a[p - 1][j] == 0 && p > 0)
                {
                    a[p - 1][j] = a[p][j];
                    a[p][j] = 0;
                    p--;
                }
            }
        }
    }
    else if (c == 'a')
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (a[i][j] == 0)
                {
                    continue;
                }
                else if (j > 0 && a[i][j] == a[i][j - 1])
                {
                    a[i][j - 1] += a[i][j];
                    a[i][j] = 0;
                }
                else if (j > 1 && a[i][j] == a[i][j - 2] && a[i][j - 1] == 0)
                {
                    a[i][j - 2] += a[i][j];
                    a[i][j] = 0;
                }
                else if (j > 2 && a[i][j] == a[i][j - 3] && a[i][j - 2] == 0 && a[i][j - 1] == 0)
                {
                    a[i][j - 3] += a[i][j];
                    a[i][j] = 0;
                }
                else
                {
                    continue;
                }
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                p = j;
                while (p > 0 && a[i][p - 1] == 0)
                {
                    a[i][p - 1] = a[i][p];
                    a[i][p] = 0;
                    p--;
                }
            }
        }
    }
    else if (c == 's')
    {
        for (int j = 0; j < 4; j++)
        {
            for (int i = 3; i >= 0; i--)
            {
                if (a[i][j] == 0)
                {
                    continue;
                }
                else if (i > 0 && a[i][j] == a[i - 1][j])
                {
                    a[i - 1][j] += a[i][j];
                    a[i][j] = 0;
                }
                else if (i > 1 && a[i][j] == a[i - 2][j] && a[i - 1][j] == 0)
                {
                    a[i - 2][j] += a[i][j];
                    a[i][j] = 0;
                }
                else if (i > 2 && a[i][j] == a[i - 3][j] && a[i - 1][j] == 0 && a[i - 2][j] == 0)
                {
                    a[i - 3][j] += a[i][j];
                    a[i][j] = 0;
                }
                else
                {
                    continue;
                }
            }
        }
        for (int j = 3; j >= 0; j--)
        {
            for (int i = 3; i >= 0; i--)
            {
                p = i;
                while (a[p + 1][j] == 0 && p < 3)
                {
                    a[p + 1][j] = a[p][j];
                    a[p][j] = 0;
                    p++;
                }
            }
        }
    }
    else if (c == 'd')
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 3; j >= 0; j--)
            {
                if (a[i][j] == 0)
                {
                    continue;
                }
                else if (j > 0 && a[i][j] == a[i][j - 1])
                {
                    a[i][j - 1] += a[i][j];
                    a[i][j] = 0;
                }
                else if (j > 1 && a[i][j] == a[i][j - 2] && a[i][j - 1] == 0)
                {
                    a[i][j - 2] += a[i][j];
                    a[i][j] = 0;
                }
                else if (i > 2 && a[i][j] == a[i][j - 3] && a[i][j - 2] == 0 && a[i][j - 1] == 0)
                {
                    a[i][j - 3] += a[i][j];
                    a[i][j] = 0;
                }
                else
                {
                    continue;
                }
            }
        }
        for (int i = 3; i >= 0; i--)
        {
            for (int j = 3; j >= 0; j--)
            {
                p = j;
                while (p < 3 && a[i][p + 1] == 0)
                {
                    a[i][p + 1] = a[i][p];
                    a[i][p] = 0;
                    p++;
                }
            }
        }
    }
    else
    {
        printf("杂鱼~你输入的怎么不是wasd呀~重新输入吧：");
        goto START;
    }
}