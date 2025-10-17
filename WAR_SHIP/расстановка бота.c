#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

void easy_komp_ten(int pole[10][10], int mod)
{
    for (int i = 0; i < 1; i++)
    {
        int str;
        int stb;
        int napr;
        int flag = 0;
        for (int j = 0; j < 100; j++)
        {
            str = rand() % 10;
            stb = rand() % 10;
            napr = rand() % 2;
            if (pole[str][stb] == 0)
            {
                if (napr == 0)
                {
                    if (pole[str + 3][stb] == 0 && str + 3 <= 9)
                    {
                        flag = 1;
                    }
                }
                if (napr == 1)
                {
                    if (pole[str][stb + 3] == 0 && stb + 3 <= 9)
                    {
                        flag = 1;
                    }
                }
            }
            if (flag == 0)
                continue;
            if (flag == 1)
            {
                if (napr == 1)
                {
                    pole[str][stb] = 4;
                    pole[str][stb + 1] = 4;
                    pole[str][stb + 2] = 4;
                    pole[str][stb + 3] = 4;
                }
                if (napr == 0)
                {
                    pole[str][stb] = 4;
                    pole[str + 1][stb] = 4;
                    pole[str + 2][stb] = 4;
                    pole[str + 3][stb] = 4;
                }
            }
            if (napr == 0)
            {
                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
                    pole[str][stb + 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 9 && stb - 1 <= 9 && str + 2 >= 0 && stb - 1 >= 0)
                    pole[str + 2][stb - 1] = 7;
                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 9 && stb + 1 <= 9 && str + 2 >= 0 && stb + 1 >= 0)
                    pole[str + 2][stb + 1] = 7;
                if (pole[str + 3][stb - 1] == 0 && str + 3 <= 9 && stb - 1 <= 9 && str + 3 >= 0 && stb - 1 >= 0)
                    pole[str + 3][stb - 1] = 7;
                if (pole[str + 3][stb + 1] == 0 && str + 3 <= 9 && stb + 1 <= 9 && str + 3 >= 0 && stb + 1 >= 0)
                    pole[str + 3][stb + 1] = 7;
                if (pole[str + 4][stb] == 0 && str + 4 <= 9 && stb <= 9 && str + 4 >= 0 && stb >= 0)
                    pole[str + 4][stb] = 7;
                if (pole[str + 4][stb - 1] == 0 && str + 4 <= 9 && stb - 1 <= 9 && str + 4 >= 0 && stb - 1 >= 0)
                    pole[str + 4][stb - 1] = 7;
                if (pole[str + 4][stb + 1] == 0 && str + 4 <= 9 && stb + 1 <= 9 && str + 4 >= 0 && stb + 1 >= 0)
                    pole[str + 4][stb + 1] = 7;
            }
            if (napr == 1)
            {
                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
                    pole[str + 1][stb] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 9 && stb + 2 <= 9 && str - 1 >= 0 && stb + 2 >= 0)
                    pole[str - 1][stb + 2] = 7;
                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 9 && stb + 2 <= 9 && str + 1 >= 0 && stb + 2 >= 0)
                    pole[str + 1][stb + 2] = 7;
                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 9 && stb + 3 <= 9 && str - 1 >= 0 && stb + 3 >= 0)
                    pole[str - 1][stb + 3] = 7;
                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 9 && stb + 3 <= 9 && str + 1 >= 0 && stb + 3 >= 0)
                    pole[str + 1][stb + 3] = 7;
                if (pole[str][stb + 4] == 0 && str <= 9 && stb + 4 <= 9 && str >= 0 && stb + 4 >= 0)
                    pole[str][stb + 4] = 7;

                if (pole[str - 1][stb + 4] == 0 && str - 1 <= 9 && stb + 4 <= 9 && str - 1 >= 0 && stb + 4 >= 0)
                    pole[str - 1][stb + 4] = 7;
                if (pole[str + 1][stb + 4] == 0 && str + 1 <= 9 && stb + 4 <= 9 && str + 1 >= 0 && stb + 4 >= 0)
                    pole[str + 1][stb + 4] = 7;
            }
            break;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        int str;
        int stb;
        int napr;
        int flag = 0;
        for (int j = 0; j < 100; j++)
        {
            str = rand() % 10;
            stb = rand() % 10;
            napr = rand() % 2;
            if (pole[str][stb] == 0)
            {
                if (napr == 0)
                {
                    if (pole[str + 2][stb] == 0 && pole[str + 1][stb] == 0 && str + 2 <= 9)
                    {
                        flag = 1;
                    }
                }
                if (napr == 1)
                {
                    if (pole[str][stb + 2] == 0 && pole[str][stb + 1] == 0 && stb + 2 <= 9)
                    {
                        flag = 1;
                    }
                }
            }
            if (flag == 0)
                continue;
            ;
            if (flag == 1)
            {
                if (napr == 1)
                {
                    pole[str][stb] = 3;
                    pole[str][stb + 1] = 3;
                    pole[str][stb + 2] = 3;
                }
                if (napr == 0)
                {
                    pole[str][stb] = 3;
                    pole[str + 1][stb] = 3;
                    pole[str + 2][stb] = 3;
                }
            }
            if (napr == 0)
            {
                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
                    pole[str][stb + 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 9 && stb - 1 <= 9 && str + 2 >= 0 && stb - 1 >= 0)
                    pole[str + 2][stb - 1] = 7;
                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 9 && stb + 1 <= 9 && str + 2 >= 0 && stb + 1 >= 0)
                    pole[str + 2][stb + 1] = 7;
                if (pole[str + 3][stb] == 0 && str + 3 <= 9 && stb <= 9 && str + 3 >= 0 && stb >= 0)
                    pole[str + 3][stb] = 7;

                if (pole[str + 3][stb - 1] == 0 && str + 3 <= 9 && stb - 1 <= 9 && str + 3 >= 0 && stb - 1 >= 0)
                    pole[str + 3][stb - 1] = 7;
                if (pole[str + 3][stb + 1] == 0 && str + 3 <= 9 && stb + 1 <= 9 && str + 3 >= 0 && stb + 1 >= 0)
                    pole[str + 3][stb + 1] = 7;
            }
            if (napr == 1)
            {
                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;

                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
                    pole[str + 1][stb] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 9 && stb + 2 <= 9 && str - 1 >= 0 && stb + 2 >= 0)
                    pole[str - 1][stb + 2] = 7;
                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 9 && stb + 2 <= 9 && str + 1 >= 0 && stb + 2 >= 0)
                    pole[str + 1][stb + 2] = 7;
                if (pole[str][stb + 3] == 0 && str <= 9 && stb + 3 <= 9 && str >= 0 && stb + 3 >= 0)
                    pole[str][stb + 3] = 7;

                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 9 && stb + 3 <= 9 && str - 1 >= 0 && stb + 3 >= 0)
                    pole[str - 1][stb + 3] = 7;
                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 9 && stb + 3 <= 9 && str + 1 >= 0 && stb + 3 >= 0)
                    pole[str + 1][stb + 3] = 7;
            }
            break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int str;
        int stb;
        int napr;
        int flag = 0;
        for (int j = 0; j < 300; j++)
        {
            str = rand() % 10;
            stb = rand() % 10;
            napr = rand() % 2;
            if (pole[str][stb] == 0)
            {
                if (napr == 0)
                {
                    if (pole[str + 1][stb] == 0 && str + 1 <= 9)
                    {
                        flag = 1;
                    }
                }
                if (napr == 1)
                {
                    if (pole[str][stb + 1] == 0 && stb + 1 <= 9)
                    {
                        flag = 1;
                    }
                }
            }
            if (flag == 0)
                continue;
            ;
            if (flag == 1)
            {
                if (napr == 1)
                {
                    pole[str][stb] = 2;
                    pole[str][stb + 1] = 2;
                }
                if (napr == 0)
                {
                    pole[str][stb] = 2;
                    pole[str + 1][stb] = 2;
                }
            }
            if (napr == 0)
            {
                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
                    pole[str][stb + 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str + 2][stb] == 0 && str + 2 <= 9 && stb <= 9 && str + 2 >= 0 && stb >= 0)
                    pole[str + 2][stb] = 7;
                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 9 && stb - 1 <= 9 && str + 2 >= 0 && stb - 1 >= 0)
                    pole[str + 2][stb - 1] = 7;
                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 9 && stb + 1 <= 9 && str + 2 >= 0 && stb + 1 >= 0)
                    pole[str + 2][stb + 1] = 7;
            }
            if (napr == 1)
            {
                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
                    pole[str + 1][stb] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str][stb + 2] == 0 && str <= 9 && stb + 2 <= 9 && str >= 0 && stb + 2 >= 0)
                    pole[str][stb + 2] = 7;
                
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 9 && stb + 2 <= 9 && str + 1 >= 0 && stb + 2 >= 0)
                    pole[str + 1][stb + 2] = 7;
                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 9 && stb + 2 <= 9 && str - 1 >= 0 && stb + 2 >= 0)
                    pole[str - 1][stb + 2] = 7;
            }
            break;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int str;
        int stb;
        int flag = 0;
        for (int j = 0; j < 500; j++)
        {
            str = rand() % 10;
            stb = rand() % 10;
            if (pole[str][stb] == 0)
            {
                flag = 1;
            }
            if (flag == 0)
                continue;
            if (flag == 1)
            {
                pole[str][stb] = 1;
            }
            if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                pole[str - 1][stb] = 7;
            if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                pole[str - 1][stb - 1] = 7;
            if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
                pole[str - 1][stb + 1] = 7;
            if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
                pole[str][stb - 1] = 7;
            if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
                pole[str][stb + 1] = 7;
            if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
                pole[str + 1][stb] = 7;
            if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
                pole[str + 1][stb - 1] = 7;
            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
                pole[str + 1][stb + 1] = 7;

            break;
        }
    }
    if(mod==1) mina_pacement_ten(pole,1);
}

void easy_komp_fi(int pole[15][15], int mod)
{
    for (int i = 0; i < 1; i++)
    {
        int str;
        int stb;
        int napr;
        int flag = 0;
        for (int j = 0; j < 200; j++)
        {
            str = rand() % 15;
            stb = rand() % 15;
            napr = rand() % 2;
            if (pole[str][stb] == 0)
            {
                if (napr == 0)
                {
                    if (pole[str + 4][stb] == 0 && pole[str + 2][stb] == 0 && pole[str + 1][stb] == 0 && str + 4 <= 14)
                    {
                        flag = 1;
                    }
                }
                if (napr == 1)
                {
                    if (pole[str][stb + 4] == 0 && pole[str][stb + 2] == 0 && pole[str][stb + 1] == 0 && stb + 4 <= 14)
                    {
                        flag = 1;
                    }
                }
            }
            if (flag == 0)
                continue;

            if (flag == 1)
            {
                if (napr == 1)
                {
                    pole[str][stb] = 5;
                    pole[str][stb + 1] = 5;
                    pole[str][stb + 2] = 5;
                    pole[str][stb + 3] = 5;
                    pole[str][stb + 4] = 5;
                }
                if (napr == 0)
                {
                    pole[str][stb] = 5;
                    pole[str + 1][stb] = 5;
                    pole[str + 2][stb] = 5;
                    pole[str + 3][stb] = 5;
                    pole[str + 4][stb] = 5;
                }
            }
            if (napr == 0)
                if (napr == 0)
                {
                    if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
                        pole[str - 1][stb] = 7;
                    if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
                        pole[str - 1][stb - 1] = 7;
                    if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
                        pole[str - 1][stb + 1] = 7;
                    if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                        pole[str][stb - 1] = 7;
                    if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
                        pole[str][stb + 1] = 7;
                    if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
                        pole[str + 1][stb - 1] = 7;
                    if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
                        pole[str + 1][stb + 1] = 7;
                    if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
                        pole[str + 2][stb - 1] = 7;
                    if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
                        pole[str + 2][stb + 1] = 7;
                    if (pole[str + 3][stb - 1] == 0 && str + 3 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
                        pole[str + 3][stb - 1] = 7;
                    if (pole[str + 3][stb + 1] == 0 && str + 3 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
                        pole[str + 3][stb + 1] = 7;
                    if (pole[str + 4][stb - 1] == 0 && str + 4 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
                        pole[str + 4][stb - 1] = 7;
                    if (pole[str + 4][stb + 1] == 0 && str + 4 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
                        pole[str + 4][stb + 1] = 7;
                    if (pole[str + 5][stb] == 0 && str + 5 <= 14 && stb <= 14 && str + 4 >= 0 && stb >= 0)
                        pole[str + 5][stb] = 7;
                    if (pole[str + 5][stb - 1] == 0 && str + 4 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
                        pole[str + 5][stb - 1] = 7;
                    if (pole[str + 5][stb + 1] == 0 && str + 4 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
                        pole[str + 5][stb + 1] = 7;
                }
            if (napr == 1)
            {
                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str - 1][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
                    pole[str + 1][stb] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
                    pole[str - 1][stb + 2] = 7;
                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
                    pole[str + 1][stb + 2] = 7;
                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 14 && stb + 3 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
                    pole[str - 1][stb + 3] = 7;
                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 14 && stb + 3 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
                    pole[str + 1][stb + 3] = 7;
                if (pole[str - 1][stb + 4] == 0 && str - 1 <= 14 && stb + 4 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
                    pole[str - 1][stb + 4] = 7;
                if (pole[str + 1][stb + 4] == 0 && str + 1 <= 14 && stb + 4 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
                    pole[str + 1][stb + 4] = 7;
                if (pole[str][stb + 5] == 0 && str <= 14 && stb + 5 <= 14 && str >= 0 && stb + 4 >= 0)
                    pole[str][stb + 5] = 7;
                if (pole[str - 1][stb + 5] == 0 && str - 1 <= 14 && stb + 4 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
                    pole[str - 1][stb + 5] = 7;
                if (pole[str + 1][stb + 5] == 0 && str + 1 <= 14 && stb + 4 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
                    pole[str + 1][stb + 5] = 7;
            }
            break;
        }
    }
    for (int i = 0; i < 1; i++)
    {
        int str;
        int stb;
        int napr;
        int flag = 0;
        for (int j = 0; j < 200; j++)
        {
            str = rand() % 15;
            stb = rand() % 15;
            napr = rand() % 2;
            if (pole[str][stb] == 0)
            {
                if (napr == 0)
                {
                    if (pole[str + 3][stb] == 0 && pole[str + 2][stb] == 0 && pole[str + 1][stb] == 0 && str + 3 <= 14)
                    {
                        flag = 1;
                    }
                }
                if (napr == 1)
                {
                    if (pole[str][stb + 3] == 0 && pole[str][stb + 2] == 0 && pole[str][stb + 1] == 0 && stb + 3 <= 14)
                    {
                        flag = 1;
                    }
                }
            }
            if (flag == 0)
                continue;

            if (flag == 1)
            {
                if (napr == 1)
                {
                    pole[str][stb] = 4;
                    pole[str][stb + 1] = 4;
                    pole[str][stb + 2] = 4;
                    pole[str][stb + 3] = 4;
                }
                if (napr == 0)
                {
                    pole[str][stb] = 4;
                    pole[str + 1][stb] = 4;
                    pole[str + 2][stb] = 4;
                    pole[str + 3][stb] = 4;
                }
            }
            if (napr == 0)
            {
                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str - 1][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str - 1][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
                    pole[str][stb + 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
                    pole[str + 2][stb - 1] = 7;
                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
                    pole[str + 2][stb + 1] = 7;
                if (pole[str + 3][stb - 1] == 0 && str + 3 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
                    pole[str + 3][stb - 1] = 7;
                if (pole[str + 3][stb + 1] == 0 && str + 3 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
                    pole[str + 3][stb + 1] = 7;
                if (pole[str + 4][stb] == 0 && str + 4 <= 14 && stb <= 14 && str + 4 >= 0 && stb >= 0)
                    pole[str + 4][stb] = 7;
                if (pole[str + 4][stb - 1] == 0 && str + 4 <= 14 && stb - 1 <= 14 && str + 4 >= 0 && stb - 1 >= 0)
                    pole[str + 4][stb - 1] = 7;
                if (pole[str + 4][stb + 1] == 0 && str + 4 <= 14 && stb + 1 <= 14 && str + 4 >= 0 && stb + 1 >= 0)
                    pole[str + 4][stb + 1] = 7;
            }
            if (napr == 1)
            {
                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
                    pole[str + 1][stb] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
                    pole[str - 1][stb + 2] = 7;
                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
                    pole[str + 1][stb + 2] = 7;
                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 14 && stb + 3 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
                    pole[str - 1][stb + 3] = 7;
                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 14 && stb + 3 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
                    pole[str + 1][stb + 3] = 7;
                if (pole[str][stb + 4] == 0 && str <= 14 && stb + 4 <= 14 && str >= 0 && stb + 4 >= 0)
                    pole[str][stb + 4] = 7;
                if (pole[str + 1][stb + 4] == 0 && str + 1 <= 14 && stb + 4 <= 14 && str + 1 >= 0 && stb + 4 >= 0)
                    pole[str + 1][stb + 4] = 7;
                if (pole[str - 1][stb + 4] == 0 && str - 1 <= 14 && stb + 4 <= 14 && str - 1 >= 0 && stb + 4 >= 0)
                    pole[str - 1][stb + 4] = 7;
            }
            break;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        int str;
        int stb;
        int napr;
        int flag = 0;
        for (int j = 0; j < 200; j++)
        {
            str = rand() % 15;
            stb = rand() % 15;
            napr = rand() % 2;
            if (pole[str][stb] == 0)
            {
                if (napr == 0)
                {
                    if (pole[str + 2][stb] == 0 && pole[str + 1][stb] == 0 && str + 2 <= 14)
                    {
                        flag = 1;
                    }
                }
                if (napr == 1)
                {
                    if (pole[str][stb + 2] == 0 && pole[str][stb + 1] == 0 && stb + 2 <= 14)
                    {
                        flag = 1;
                    }
                }
            }
            if (flag == 0)
                continue;
            ;
            if (flag == 1)
            {
                if (napr == 1)
                {
                    pole[str][stb] = 3;
                    pole[str][stb + 1] = 3;
                    pole[str][stb + 2] = 3;
                }
                if (napr == 0)
                {
                    pole[str][stb] = 3;
                    pole[str + 1][stb] = 3;
                    pole[str + 2][stb] = 3;
                }
            }
            if (napr == 0)
            {
                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
                    pole[str][stb + 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
                    pole[str + 2][stb - 1] = 7;
                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
                    pole[str + 2][stb + 1] = 7;
                if (pole[str + 3][stb] == 0 && str + 3 <= 14 && stb <= 14 && str + 3 >= 0 && stb >= 0)
                    pole[str + 3][stb] = 7;
                if (pole[str + 3][stb - 1] == 0 && str + 3 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
                    pole[str + 3][stb - 1] = 7;
                if (pole[str + 3][stb + 1] == 0 && str + 3 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
                    pole[str + 3][stb + 1] = 7;
            }
            if (napr == 1)
            {
                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
                    pole[str + 1][stb] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
                    pole[str - 1][stb + 2] = 7;
                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
                    pole[str + 1][stb + 2] = 7;
                if (pole[str][stb + 3] == 0 && str <= 14 && stb + 3 <= 14 && str >= 0 && stb + 3 >= 0)
                    pole[str][stb + 3] = 7;
                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 14 && stb + 3 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
                    pole[str][stb + 3] = 7;
                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 14 && stb + 3 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
                    pole[str + 1][stb + 3] = 7;
                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 14 && stb + 3 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
                    pole[str - 1][stb + 3] = 7;
            }
            break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int str;
        int stb;
        int napr;
        int flag = 0;
        for (int j = 0; j < 300; j++)
        {
            str = rand() % 15;
            stb = rand() % 15;
            napr = rand() % 2;
            if (pole[str][stb] == 0)
            {
                if (napr == 0)
                {
                    if (pole[str + 1][stb] == 0 && str + 1 <= 14)
                    {
                        flag = 1;
                    }
                }
                if (napr == 1)
                {
                    if (pole[str][stb + 1] == 0 && stb + 1 <= 14)
                    {
                        flag = 1;
                    }
                }
            }
            if (flag == 0)
                continue;
            ;
            if (flag == 1)
            {
                if (napr == 1)
                {
                    pole[str][stb] = 2;
                    pole[str][stb + 1] = 2;
                }
                if (napr == 0)
                {
                    pole[str][stb] = 2;
                    pole[str + 1][stb] = 2;
                }
            }
            if (napr == 0)
            {
                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
                    pole[str][stb + 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str + 2][stb] == 0 && str + 2 <= 14 && stb <= 14 && str + 2 >= 0 && stb >= 0)
                    pole[str + 2][stb] = 7;
                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
                    pole[str + 2][stb] = 7;
                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
                    pole[str + 2][stb + 1] = 7;
                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
                    pole[str + 2][stb - 1] = 7;
            }
            if (napr == 1)
            {
                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                    pole[str][stb - 1] = 7;
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
                if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
                    pole[str + 1][stb] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
                    pole[str + 1][stb + 1] = 7;
                if (pole[str][stb + 2] == 0 && str <= 14 && stb + 2 <= 14 && str >= 0 && stb + 2 >= 0)
                    pole[str][stb + 2] = 7;
                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
                    pole[str - 1][stb + 2] = 7;
                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
                    pole[str + 1][stb + 2] = 7;
            }
            break;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        int str;
        int stb;
        int flag = 0;
        for (int j = 0; j < 500; j++)
        {
            str = rand() % 15;
            stb = rand() % 15;
            if (pole[str][stb] == 0)
            {
                flag = 1;
            }
            if (flag == 0)
                continue;
            if (flag == 1)
            {
                pole[str][stb] = 1;
            }
            if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
                pole[str - 1][stb] = 7;
            if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
                pole[str - 1][stb - 1] = 7;
            if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
                pole[str - 1][stb + 1] = 7;
            if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
                pole[str][stb - 1] = 7;
            if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
                pole[str + 1][stb - 1] = 7;
            if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
                pole[str][stb + 1] = 7;
            if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
                pole[str + 1][stb] = 7;
            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
                pole[str + 1][stb + 1] = 7;

            break;
        }
    }
    if (mod == 1) mina_pacement_fi(pole, 1);
}

void medi_komp_ten(int pole[10][10], int mod)
{
    pole[0][0] = 4;
    pole[0][1] = 4;
    pole[0][2] = 4;
    pole[0][3] = 4;
    pole[2][0] = 2;
    pole[2][1] = 2;
    pole[4][0] = 2;
    pole[4][1] = 2;
    pole[2][3] = 3;
    pole[3][3] = 3;
    pole[4][3] = 3;
    pole[9][0] = 2;
    pole[9][1] = 2;
    pole[7][1] = 3;
    pole[7][2] = 3;
    pole[7][3] = 3;

    pole[1][6] = 1;
    pole[4][7] = 1;
    pole[8][8] = 1;
    pole[6][5] = 1;
    if (mod == 1) mina_pacement_ten(pole, 2);
}

void medi_komp_fif(int pole[15][15], int mod)
{
    pole[0][5] = 4;
    pole[1][5] = 4;
    pole[2][5] = 4;
    pole[3][5] = 4;
    pole[2][1] = 3;
    pole[2][2] = 3;
    pole[2][3] = 3;
    pole[4][3] = 2;
    pole[5][3] = 2;
    pole[7][0] = 3;
    pole[7][1] = 3;
    pole[7][2] = 3;
    pole[10][1] = 2;
    pole[11][1] = 2;
    pole[13][3] = 2;
    pole[14][3] = 2;
    pole[8][5] = 5;
    pole[9][5] = 5;
    pole[10][5] = 5;
    pole[11][5] = 5;
    pole[12][5] = 5;
    pole[0][13] = 1;
    pole[2][9] = 1;
    pole[7][12] = 1;
    pole[13][10] = 1;
    if (mod == 1) mina_pacement_fi(pole, 2);
}

void medi_komp_ten_2(int pole[10][10])
{
    pole[0][6] = 4;
    pole[0][9] = 4;
    pole[0][8] = 4;
    pole[0][7] = 4;
    pole[2][9] = 2;
    pole[3][9] = 2;
    pole[2][6] = 2;
    pole[2][7] = 2;
    pole[6][6] = 3;
    pole[6][7] = 3;
    pole[6][8] = 3;
    pole[8][9] = 2;
    pole[9][9] = 2;
    pole[9][5] = 3;
    pole[9][6] = 3;
    pole[9][7] = 3;

    pole[2][1] = 1;
    pole[9][0] = 1;
    pole[5][3] = 1;
    pole[0][4] = 1;
}

void medi_komp_fif_2(int pole[15][15])
{
    pole[4][8] = 4;
    pole[3][8] = 4;
    pole[2][8] = 4;
    pole[1][8] = 4;
    pole[13][10] = 3;
    pole[13][9] = 3;
    pole[13][8] = 3;
    pole[11][8] = 2;
    pole[10][8] = 2;
    pole[9][14] = 3;
    pole[8][14] = 3;
    pole[7][14] = 3;
    pole[6][10] = 2;
    pole[6][11] = 2;
    pole[3][13] = 2;
    pole[3][12] = 2;
    pole[0][10] = 5;
    pole[0][11] = 5;
    pole[0][12] = 5;
    pole[0][13] = 5;
    pole[0][14] = 5;
    pole[12][5] = 1;
    pole[9][3] = 1;
    pole[5][0] = 1;
    pole[2][3] = 1;
}

void hard_komp_ten(int pole[10][10], int mod)
{
    pole[1][0] = 4;
    pole[2][0] = 4;
    pole[3][0] = 4;
    pole[4][0] = 4;
    pole[6][0] = 2;
    pole[7][0] = 2;
    pole[9][1] = 3;
    pole[9][2] = 3;
    pole[9][3] = 3;
    pole[7][9] = 2;
    pole[8][9] = 2;
    pole[0][9] = 3;
    pole[0][7] = 3;
    pole[0][8] = 3;
    pole[3][9] = 2;
    pole[4][9] = 2;
    pole[6][4] = 1;
    pole[3][6] = 1;
    pole[7][6] = 1;
    pole[3][3] = 1;
    if (mod == 1) mina_pacement_ten(pole,3);
}

void hard_komp_fif(int pole[15][15], int mod)

{
    pole[1][0] = 4;
    pole[2][0] = 4;
    pole[3][0] = 4;
    pole[4][0] = 4;
    pole[9][0] = 2;
    pole[10][0] = 2;
    pole[14][3] = 5;
    pole[14][4] = 5;
    pole[14][5] = 5;
    pole[14][6] = 5;
    pole[14][7] = 5;
    pole[14][12] = 3;
    pole[14][13] = 3;
    pole[14][14] = 3;
    pole[9][14] = 2;
    pole[10][14] = 2;
    pole[0][12] = 3;
    pole[0][13] = 3;
    pole[0][14] = 3;
    pole[0][2] = 2;
    pole[0][3] = 2;
    pole[3][8] = 1;
    pole[11][8] = 1;
    pole[8][5] = 1;
    pole[7][10] = 1;
    if (mod == 1)mina_pacement_fi(pole, 3);
}

void hard_komp_ten_2(int pole[10][10])
{
    pole[0][3] = 4;
    pole[0][4] = 4;
    pole[0][5] = 4;
    pole[0][6] = 4;
    pole[0][0] = 2;
    pole[0][1] = 2;
    pole[2][9] = 3;
    pole[3][9] = 3;
    pole[4][9] = 3;
    pole[5][0] = 2;
    pole[6][0] = 2;
    pole[9][2] = 3;
    pole[9][3] = 3;
    pole[9][4] = 3;
    pole[8][9] = 2;
    pole[9][9] = 2;
    pole[7][3] = 1;
    pole[4][7] = 1;
    pole[5][6] = 1;
    pole[3][4] = 1;
}

void hard_komp_fif_2(int pole[15][15])

{
    pole[14][2] = 4;
    pole[14][3] = 4;
    pole[14][4] = 4;
    pole[14][5] = 4;
    pole[10][0] = 2;
    pole[11][0] = 2;
    pole[0][10] = 5;
    pole[0][11] = 5;
    pole[0][12] = 5;
    pole[0][13] = 5;
    pole[0][14] = 5;
    pole[7][14] = 3;
    pole[8][14] = 3;
    pole[9][14] = 3;
    pole[0][3] = 2;
    pole[0][4] = 2;
    pole[14][12] = 3;
    pole[14][13] = 3;
    pole[14][14] = 3;
    pole[4][0] = 2;
    pole[5][0] = 2;
    pole[5][8] = 1;
    pole[10][8] = 1;
    pole[8][7] = 1;
    pole[7][4] = 1;
}
 
void placement_bot_ten(int pole[10][10], int level, int flag, int mod) {
    srand(time(NULL));
    if(level==1) easy_komp_ten(pole, mod);
    else if (level == 2 && flag==1) {
        medi_komp_ten(pole, mod);
    }
    else if (level == 2 && flag == 2) {
        medi_komp_ten_2(pole);
    }
    else if (level == 3 && flag==1) {
        hard_komp_ten(pole, mod);
    }
    else if (level == 3 && flag == 2) {
        hard_komp_ten_2(pole);
    }
    printf("\n");
    printf("Расстановка бота:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) printf("%d ", pole[i][j]);
        printf("\n");
    }
}

void placement_bot_fi(int pole[15][15], int level, int flag, int mod) {
    srand(time(NULL));
    if (level == 1) easy_komp_fi(pole, mod);
    else if (level == 2 && flag==1) {
        medi_komp_fif(pole, mod);
    }
    else if (level == 2 && flag == 2) {
        medi_komp_fif_2(pole);
    }
    else if (level == 3 && flag == 1) {
        hard_komp_fif(pole, mod);
    }
    else if (level == 3 && flag == 2) {
        hard_komp_fif_2(pole);
    }
    printf("\n");
    printf("Расстановка бота:\n");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) printf("%d ", pole[i][j]);
        printf("\n");
    }
}
