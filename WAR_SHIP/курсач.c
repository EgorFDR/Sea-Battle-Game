//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <string.h>
//#include <locale.h>
//
//typedef enum
//{
//    TEN,
//    FIFTIN
//} POLE;
//
//typedef enum
//{
//    EASY,
//    MEDIUM,
//    HARD
//} SLOZH;
//
//int trans(char sim1)
//{
//    int sim;
//    if (sim1 == 'А')
//        sim = 0;
//    if (sim1 == 'Б')
//        sim = 1;
//    if (sim1 == 'В')
//        sim = 2;
//    if (sim1 == 'Г')
//        sim = 3;
//    if (sim1 == 'Д')
//        sim = 4;
//    if (sim1 == 'Е')
//        sim = 5;
//    if (sim1 == 'Ё')
//        sim = 6;
//    if (sim1 == 'Ж')
//        sim = 7;
//    if (sim1 == 'З')
//        sim = 8;
//    if (sim1 == 'И')
//        sim = 9;
//    return sim;
//}
//
//int trans_fif(char sim1)
//{
//    int sim;
//    if (sim1 == 'А')
//        sim = 0;
//    if (sim1 == 'Б')
//        sim = 1;
//    if (sim1 == 'В')
//        sim = 2;
//    if (sim1 == 'Г')
//        sim = 3;
//    if (sim1 == 'Д')
//        sim = 4;
//    if (sim1 == 'Е')
//        sim = 5;
//    if (sim1 == 'Ё')
//        sim = 6;
//    if (sim1 == 'Ж')
//        sim = 7;
//    if (sim1 == 'З')
//        sim = 8;
//    if (sim1 == 'И')
//        sim = 9;
//    if (sim1 == 'Й')
//        sim = 10;
//    if (sim1 == 'К')
//        sim = 11;
//    if (sim1 == 'Л')
//        sim = 12;
//    if (sim1 == 'М')
//        sim = 13;
//    if (sim1 == 'Н')
//        sim = 14;
//    return sim;
//}
//
//void my_plan_fif(int pole[15][15])
//{
//    for (int i = 0; i < 1; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        for (int j = 0; j < 100; j++)
//        {
//
//            int sim2;
//            char sim1;
//            int flag = 0;
//            printf("Zero\n");
//            scanf(" %c%d", &sim1, &sim2);
//            str = sim2 - 1;
//            stb = trans_fif(sim1);
//            if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//            scanf("%d", &napr);
//            if (napr == 0 && str + 1 <= 14 && str + 2 <= 14 && str + 3 <= 14 && str + 4 <= 14)
//            {
//                if (pole[str + 1][stb] == 0 && pole[str + 2][stb] == 0 && pole[str + 3][stb] == 0 && pole[str + 4][stb] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 5;
//                    pole[str + 1][stb] = 5;
//                    pole[str + 2][stb] = 5;
//                    pole[str + 3][stb] = 5;
//                    pole[str + 4][stb] = 5;
//                }
//            }
//            if (napr == 1 && stb + 1 <= 14 && stb + 2 <= 14 && stb + 3 <= 14 && stb + 4 <= 14)
//            {
//                if (pole[str][stb + 1] == 0 && pole[str][stb + 2] == 0 && pole[str][stb + 3] == 0 && pole[str][stb + 4] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 5;
//                    pole[str][stb + 1] = 5;
//                    pole[str][stb + 2] = 5;
//                    pole[str][stb + 3] = 5;
//                    pole[str][stb + 4] = 5;
//                }
//            }
//            if (flag == 1)
//                continue;
//            if (flag == 2)
//                break;
//        }
//
//        if (napr == 0)
//        {
//            if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                pole[str - 1][stb] = 7;
//            if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                pole[str - 1][stb - 1] = 7;
//            if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                pole[str - 1][stb + 1] = 7;
//            if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                pole[str][stb - 1] = 7;
//            if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                pole[str][stb + 1] = 7;
//            if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                pole[str + 1][stb - 1] = 7;
//            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                pole[str + 1][stb + 1] = 7;
//            if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
//                pole[str + 2][stb - 1] = 7;
//            if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
//                pole[str + 2][stb + 1] = 7;
//            if (pole[str + 3][stb - 1] == 0 && str + 3 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
//                pole[str + 3][stb - 1] = 7;
//            if (pole[str + 3][stb + 1] == 0 && str + 3 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
//                pole[str + 3][stb + 1] = 7;
//            if (pole[str + 4][stb - 1] == 0 && str + 4 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
//                pole[str + 4][stb - 1] = 7;
//            if (pole[str + 4][stb + 1] == 0 && str + 4 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
//                pole[str + 4][stb + 1] = 7;
//            if (pole[str + 5][stb] == 0 && str + 5 <= 14 && stb <= 14 && str + 4 >= 0 && stb >= 0)
//                pole[str + 5][stb] = 7;
//            if (pole[str + 5][stb - 1] == 0 && str + 4 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
//                pole[str + 5][stb - 1] = 7;
//            if (pole[str + 5][stb + 1] == 0 && str + 4 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
//                pole[str + 5][stb + 1] = 7;
//        }
//        if (napr == 1)
//        {
//            if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                pole[str][stb - 1] = 7;
//            if (pole[str - 1][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                pole[str - 1][stb - 1] = 7;
//            if (pole[str + 1][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                pole[str + 1][stb - 1] = 7;
//            if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                pole[str - 1][stb] = 7;
//            if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
//                pole[str + 1][stb] = 7;
//            if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                pole[str - 1][stb + 1] = 7;
//            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                pole[str + 1][stb + 1] = 7;
//            if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
//                pole[str - 1][stb + 2] = 7;
//            if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
//                pole[str + 1][stb + 2] = 7;
//            if (pole[str - 1][stb + 3] == 0 && str - 1 <= 14 && stb + 3 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
//                pole[str - 1][stb + 3] = 7;
//            if (pole[str + 1][stb + 3] == 0 && str + 1 <= 14 && stb + 3 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
//                pole[str + 1][stb + 3] = 7;
//            if (pole[str - 1][stb + 4] == 0 && str - 1 <= 14 && stb + 4 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
//                pole[str - 1][stb + 4] = 7;
//            if (pole[str + 1][stb + 4] == 0 && str + 1 <= 14 && stb + 4 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
//                pole[str + 1][stb + 4] = 7;
//            if (pole[str][stb + 5] == 0 && str <= 14 && stb + 5 <= 14 && str >= 0 && stb + 4 >= 0)
//                pole[str][stb + 5] = 7;
//            if (pole[str - 1][stb + 5] == 0 && str - 1 <= 14 && stb + 4 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
//                pole[str - 1][stb + 5] = 7;
//            if (pole[str + 1][stb + 5] == 0 && str + 1 <= 14 && stb + 4 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
//                pole[str + 1][stb + 5] = 7;
//        }
//        break;
//    }
//    for (int i = 0; i < 1; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        for (int j = 0; j < 100; j++)
//        {
//
//            int sim2;
//            char sim1;
//            int flag = 0;
//            printf("One\n");
//            scanf(" %c%d", &sim1, &sim2);
//            str = sim2 - 1;
//            stb = trans_fif(sim1);
//            if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//            scanf("%d", &napr);
//            if (napr == 0 && str + 1 <= 14 && str + 2 <= 14 && str + 3 <= 14)
//            {
//                if (pole[str + 1][stb] == 0 && pole[str + 2][stb] == 0 && pole[str + 3][stb] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 4;
//                    pole[str + 1][stb] = 4;
//                    pole[str + 2][stb] = 4;
//                    pole[str + 3][stb] = 4;
//                }
//            }
//            if (napr == 1 && stb + 1 <= 14 && stb + 2 <= 14 && stb + 3 <= 14)
//            {
//                if (pole[str][stb + 1] == 0 && pole[str][stb + 2] == 0 && pole[str][stb + 3] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 4;
//                    pole[str][stb + 1] = 4;
//                    pole[str][stb + 2] = 4;
//                    pole[str][stb + 3] = 4;
//                }
//            }
//            if (flag == 1)
//                continue;
//            if (flag == 2)
//                break;
//        }
//
//        if (napr == 0)
//        {
//            if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                pole[str - 1][stb] = 7;
//            if (pole[str - 1][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                pole[str - 1][stb - 1] = 7;
//            if (pole[str - 1][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                pole[str - 1][stb + 1] = 7;
//            if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                pole[str][stb - 1] = 7;
//            if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                pole[str][stb + 1] = 7;
//            if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                pole[str + 1][stb - 1] = 7;
//            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                pole[str + 1][stb + 1] = 7;
//            if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
//                pole[str + 2][stb - 1] = 7;
//            if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
//                pole[str + 2][stb + 1] = 7;
//            if (pole[str + 3][stb - 1] == 0 && str + 3 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
//                pole[str + 3][stb - 1] = 7;
//            if (pole[str + 3][stb + 1] == 0 && str + 3 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
//                pole[str + 3][stb + 1] = 7;
//            if (pole[str + 4][stb] == 0 && str + 4 <= 14 && stb <= 14 && str + 4 >= 0 && stb >= 0)
//                pole[str + 4][stb] = 7;
//            if (pole[str + 4][stb - 1] == 0 && str + 4 <= 14 && stb - 1 <= 14 && str + 4 >= 0 && stb - 1 >= 0)
//                pole[str + 4][stb - 1] = 7;
//            if (pole[str + 4][stb + 1] == 0 && str + 4 <= 14 && stb + 1 <= 14 && str + 4 >= 0 && stb + 1 >= 0)
//                pole[str + 4][stb + 1] = 7;
//        }
//        if (napr == 1)
//        {
//            if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                pole[str][stb - 1] = 7;
//            if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                pole[str + 1][stb - 1] = 7;
//            if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                pole[str - 1][stb - 1] = 7;
//            if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                pole[str - 1][stb] = 7;
//            if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
//                pole[str + 1][stb] = 7;
//            if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                pole[str - 1][stb + 1] = 7;
//            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                pole[str + 1][stb + 1] = 7;
//            if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
//                pole[str - 1][stb + 2] = 7;
//            if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
//                pole[str + 1][stb + 2] = 7;
//            if (pole[str - 1][stb + 3] == 0 && str - 1 <= 14 && stb + 3 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
//                pole[str - 1][stb + 3] = 7;
//            if (pole[str + 1][stb + 3] == 0 && str + 1 <= 14 && stb + 3 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
//                pole[str + 1][stb + 3] = 7;
//            if (pole[str][stb + 4] == 0 && str <= 14 && stb + 4 <= 14 && str >= 0 && stb + 4 >= 0)
//                pole[str][stb + 4] = 7;
//            if (pole[str + 1][stb + 4] == 0 && str + 1 <= 14 && stb + 4 <= 14 && str + 1 >= 0 && stb + 4 >= 0)
//                pole[str + 1][stb + 4] = 7;
//            if (pole[str - 1][stb + 4] == 0 && str - 1 <= 14 && stb + 4 <= 14 && str - 1 >= 0 && stb + 4 >= 0)
//                pole[str - 1][stb + 4] = 7;
//        }
//        break;
//    }
//
//    for (int i = 0; i < 2; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        for (int j = 0; j < 300; j++)
//        {
//
//            int sim2;
//            char sim1;
//            int flag = 0;
//            printf("Two\n");
//            scanf(" %c%d", &sim1, &sim2);
//            str = sim2 - 1;
//            stb = trans_fif(sim1);
//            if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//            scanf("%d", &napr);
//            if (napr == 0 && str + 1 <= 14 && str + 2 <= 14)
//            {
//                if (pole[str + 1][stb] == 0 && pole[str + 2][stb] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 3;
//                    pole[str + 1][stb] = 3;
//                    pole[str + 2][stb] = 3;
//                }
//            }
//            if (napr == 1 && stb + 1 <= 14 && stb + 2 <= 14)
//            {
//                if (pole[str][stb + 1] == 0 && pole[str][stb + 2] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 3;
//                    pole[str][stb + 1] = 3;
//                    pole[str][stb + 2] = 3;
//                }
//            }
//            if (flag == 1)
//                continue;
//             if(flag==2) break;
//
//            if (napr == 0)
//            {
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                    pole[str][stb + 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
//                    pole[str + 2][stb - 1] = 7;
//                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
//                    pole[str + 2][stb + 1] = 7;
//                if (pole[str + 3][stb] == 0 && str + 3 <= 14 && stb <= 14 && str + 3 >= 0 && stb >= 0)
//                    pole[str + 3][stb] = 7;
//                if (pole[str + 3][stb - 1] == 0 && str + 3 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
//                    pole[str + 3][stb - 1] = 7;
//                if (pole[str + 3][stb + 1] == 0 && str + 3 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
//                    pole[str + 3][stb + 1] = 7;
//            }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
//                    pole[str - 1][stb + 2] = 7;
//                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
//                    pole[str + 1][stb + 2] = 7;
//                if (pole[str][stb + 3] == 0 && str <= 14 && stb + 3 <= 14 && str >= 0 && stb + 3 >= 0)
//                    pole[str][stb + 3] = 7;
//                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 14 && stb + 3 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
//                    pole[str][stb + 3] = 7;
//                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 14 && stb + 3 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
//                    pole[str + 1][stb + 3] = 7;
//            }
//            break;
//        }
//    }
//
//    for (int i = 0; i < 3; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        for (int j = 0; j < 300; j++)
//        {
//
//            int sim2;
//            char sim1;
//            int flag = 0;
//            printf("Three\n");
//            scanf(" %c%d", &sim1, &sim2);
//            str = sim2 - 1;
//            stb = trans_fif(sim1);
//            if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//            scanf("%d", &napr);
//            if (napr == 0 && str + 1 <= 14)
//            {
//                if (pole[str + 1][stb] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 2;
//                    pole[str + 1][stb] = 2;
//                }
//            }
//            if (napr == 1 && stb + 1 <= 14)
//            {
//                if (pole[str][stb + 1] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 2;
//                    pole[str][stb + 1] = 2;
//                }
//            }
//            if (flag == 1)
//                continue;
//             if(flag==2) break;
//
//            if (napr == 0)
//            {
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                    pole[str][stb + 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str + 2][stb] == 0 && str + 2 <= 14 && stb <= 14 && str + 2 >= 0 && stb >= 0)
//                    pole[str + 2][stb] = 7;
//                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
//                    pole[str + 2][stb] = 7;
//                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
//                    pole[str + 2][stb + 1] = 7;
//            }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str][stb + 2] == 0 && str <= 14 && stb + 2 <= 14 && str >= 0 && stb + 2 >= 0)
//                    pole[str][stb + 2] = 7;
//                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
//                    pole[str - 1][stb + 2] = 7;
//                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
//                    pole[str + 1][stb + 2] = 7;
//            }
//            break;
//        }
//    }
//
//    for (int i = 0; i < 4; i++)
//    {
//        int str;
//        int stb;
//        for (int j = 0; j < 300; j++)
//        {
//
//            int sim2;
//            char sim1;
//            int flag = 0;
//            printf("Four\n");
//            scanf(" %c%d", &sim1, &sim2);
//            str = sim2 - 1;
//            stb = trans_fif(sim1);
//            if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//
//            if (pole[str][stb] == 0)
//            {
//                flag = 2;
//                pole[str][stb] = 1;
//            }
//
//            if (flag == 1)
//                continue;
//             if(flag==2) break;
//
//            if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                pole[str - 1][stb] = 7;
//            if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                pole[str - 1][stb - 1] = 7;
//            if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                pole[str - 1][stb + 1] = 7;
//            if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                pole[str][stb - 1] = 7;
//            if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                pole[str + 1][stb - 1] = 7;
//            if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                pole[str][stb + 1] = 7;
//            if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
//                pole[str + 1][stb] = 7;
//            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                pole[str + 1][stb + 1] = 7;
//
//            break;
//        }
//    }
//}
//
//void my_plan_ten(int pole[10][10])
//{
//    for (int i = 0; i < 1; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        for (int j = 0; j < 100; j++)
//        {
//
//            int sim2;
//            char sim1;
//            int flag = 0;
//            printf("One\n");
//            scanf(" %c%d", &sim1, &sim2);
//            str = sim2 - 1;
//            stb = trans(sim1);
//            if (str >= 0 && str <= 9 && stb <= 9 && stb >= 0 && pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//            scanf("%d", &napr);
//            if (napr == 0 && str + 1 <= 9 && str + 2 <= 9 && str + 3 <= 9)
//            {
//                if (pole[str + 1][stb] == 0 && pole[str + 2][stb] == 0 && pole[str + 3][stb] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 4;
//                    pole[str + 1][stb] = 4;
//                    pole[str + 2][stb] = 4;
//                    pole[str + 3][stb] = 4;
//                }
//            }
//            if (napr == 1 && stb + 1 <= 9 && stb + 2 <= 9 && stb + 3 <= 9)
//            {
//                if (pole[str][stb + 1] == 0 && pole[str][stb + 2] == 0 && pole[str][stb + 3] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 4;
//                    pole[str][stb + 1] = 4;
//                    pole[str][stb + 2] = 4;
//                    pole[str][stb + 3] = 4;
//                }
//            }
//            if (flag == 1)
//                continue;
//            if (flag == 2)
//                break;
//        }
//
//        if (napr == 0)
//        {
//            if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                pole[str - 1][stb] = 7;
//            if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                pole[str][stb - 1] = 7;
//            if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
//                pole[str][stb + 1] = 7;
//            if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
//                pole[str + 1][stb - 1] = 7;
//            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                pole[str + 1][stb + 1] = 7;
//            if (pole[str + 2][stb - 1] == 0 && str + 2 <= 9 && stb - 1 <= 9 && str + 2 >= 0 && stb - 1 >= 0)
//                pole[str + 2][stb - 1] = 7;
//            if (pole[str + 2][stb + 1] == 0 && str + 2 <= 9 && stb + 1 <= 9 && str + 2 >= 0 && stb + 1 >= 0)
//                pole[str + 2][stb + 1] = 7;
//            if (pole[str + 3][stb - 1] == 0 && str + 3 <= 9 && stb - 1 <= 9 && str + 3 >= 0 && stb - 1 >= 0)
//                pole[str + 3][stb - 1] = 7;
//            if (pole[str + 3][stb + 1] == 0 && str + 3 <= 9 && stb + 1 <= 9 && str + 3 >= 0 && stb + 1 >= 0)
//                pole[str + 3][stb + 1] = 7;
//            if (pole[str + 4][stb] == 0 && str + 4 <= 9 && stb <= 9 && str + 4 >= 0 && stb >= 0)
//                pole[str + 4][stb] = 7;
//        }
//        if (napr == 1)
//        {
//            if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                pole[str][stb - 1] = 7;
//            if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                pole[str - 1][stb] = 7;
//            if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
//                pole[str + 1][stb] = 7;
//            if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
//                pole[str - 1][stb + 1] = 7;
//            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                pole[str + 1][stb + 1] = 7;
//            if (pole[str - 1][stb + 2] == 0 && str - 1 <= 9 && stb + 2 <= 9 && str - 1 >= 0 && stb + 2 >= 0)
//                pole[str - 1][stb + 2] = 7;
//            if (pole[str + 1][stb + 2] == 0 && str + 1 <= 9 && stb + 2 <= 9 && str + 1 >= 0 && stb + 2 >= 0)
//                pole[str + 1][stb + 2] = 7;
//            if (pole[str - 1][stb + 3] == 0 && str - 1 <= 9 && stb + 3 <= 9 && str - 1 >= 0 && stb + 3 >= 0)
//                pole[str - 1][stb + 3] = 7;
//            if (pole[str + 1][stb + 3] == 0 && str + 1 <= 9 && stb + 3 <= 9 && str + 1 >= 0 && stb + 3 >= 0)
//                pole[str + 1][stb + 3] = 7;
//            if (pole[str][stb + 4] == 0 && str <= 9 && stb + 4 <= 9 && str >= 0 && stb + 4 >= 0)
//                pole[str][stb + 4] = 7;
//        }
//        break;
//    }
//
//    for (int i = 0; i < 2; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        for (int j = 0; j < 200; j++)
//        {
//
//            int sim2;
//            char sim1;
//            int flag = 0;
//            printf("Two\n");
//            scanf(" %c%d", &sim1, &sim2);
//            str = sim2 - 1;
//            stb = trans(sim1);
//            if (str >= 0 && str <= 9 && stb <= 9 && stb >= 0 && pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//            scanf("%d", &napr);
//            if (napr == 0 && str + 1 <= 9 && str + 2 <= 9)
//            {
//                if (pole[str + 1][stb] == 0 && pole[str + 2][stb] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 3;
//                    pole[str + 1][stb] = 3;
//                    pole[str + 2][stb] = 3;
//                }
//            }
//            if (napr == 1 && stb + 1 <= 9 && stb + 2 <= 9)
//            {
//                if (pole[str][stb + 1] == 0 && pole[str][stb + 2] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 3;
//                    pole[str][stb + 1] = 3;
//                    pole[str][stb + 2] = 3;
//                }
//            }
//            if (flag == 1)
//                continue;
//             if(flag==2) break;
//
//            if (napr == 0)
//            {
//                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
//                    pole[str][stb + 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 9 && stb - 1 <= 9 && str + 2 >= 0 && stb - 1 >= 0)
//                    pole[str + 2][stb - 1] = 7;
//                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 9 && stb + 1 <= 9 && str + 2 >= 0 && stb + 1 >= 0)
//                    pole[str + 2][stb + 1] = 7;
//                if (pole[str + 3][stb] == 0 && str + 3 <= 9 && stb <= 9 && str + 3 >= 0 && stb >= 0)
//                    pole[str + 3][stb] = 7;
//            }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 9 && stb + 2 <= 9 && str - 1 >= 0 && stb + 2 >= 0)
//                    pole[str - 1][stb + 2] = 7;
//                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 9 && stb + 2 <= 9 && str + 1 >= 0 && stb + 2 >= 0)
//                    pole[str + 1][stb + 2] = 7;
//                if (pole[str][stb + 3] == 0 && str <= 9 && stb + 3 <= 9 && str >= 0 && stb + 3 >= 0)
//                    pole[str][stb + 3] = 7;
//            }
//            break;
//        }
//    }
//
//    for (int i = 0; i < 3; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        for (int j = 0; j < 300; j++)
//        {
//
//            int sim2;
//            char sim1;
//            int flag = 0;
//            printf("Three\n");
//            scanf(" %c%d", &sim1, &sim2);
//            str = sim2 - 1;
//            stb = trans(sim1);
//            if (str >= 0 && str <= 9 && stb <= 9 && stb >= 0 && pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//            scanf("%d", &napr);
//            if (napr == 0 && str + 1 <= 9)
//            {
//                if (pole[str + 1][stb] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 2;
//                    pole[str + 1][stb] = 2;
//                }
//            }
//            if (napr == 1 && stb + 1 <= 9)
//            {
//                if (pole[str][stb + 1] == 0)
//                {
//                    flag = 2;
//                    pole[str][stb] = 2;
//                    pole[str][stb + 1] = 2;
//                }
//            }
//            if (flag == 1)
//                continue;
//             if(flag==2) break;
//
//            if (napr == 0)
//            {
//                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
//                    pole[str][stb + 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str + 2][stb] == 0 && str + 2 <= 9 && stb <= 9 && str + 2 >= 0 && stb >= 0)
//                    pole[str + 2][stb] = 7;
//            }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str][stb + 2] == 0 && str <= 9 && stb + 2 <= 9 && str >= 0 && stb + 2 >= 0)
//                    pole[str][stb + 2] = 7;
//            }
//            break;
//        }
//    }
//
//    for (int i = 0; i < 4; i++)
//    {
//        int str;
//        int stb;
//        for (int j = 0; j < 300; j++)
//        {
//
//            int sim2;
//            char sim1;
//            int flag = 0;
//            printf("Four\n");
//            scanf(" %c%d", &sim1, &sim2);
//            str = sim2 - 1;
//            stb = trans(sim1);
//            if (str >= 0 && str <= 9 && stb <= 9 && stb >= 0 && pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//
//            if (pole[str][stb] == 0)
//            {
//                flag = 2;
//                pole[str][stb] = 1;
//            }
//
//            if (flag == 1)
//                continue;
//             if(flag==2) break;
//
//            if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                pole[str - 1][stb] = 7;
//            if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                pole[str][stb - 1] = 7;
//            if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
//                pole[str][stb + 1] = 7;
//            if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
//                pole[str + 1][stb] = 7;
//
//            break;
//        }
//    }
//}
//
//void easy_komp_ten(int pole[10][10])
//{
//    for (int i = 0; i < 1; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        int flag = 0;
//        for (int j = 0; j < 100; j++)
//        {
//            str = rand() % 10;
//            stb = rand() % 10;
//            napr = rand() % 2;
//            if (pole[str][stb] == 0)
//            {
//                if (napr == 0)
//                {
//                    if (pole[str + 3][stb] == 0 && str + 3 <= 9)
//                    {
//                        flag = 1;
//                    }
//                }
//                if (napr == 1)
//                {
//                    if (pole[str][stb + 3] == 0 && stb + 3 <= 9)
//                    {
//                        flag = 1;
//                    }
//                }
//            }
//            if (flag == 0)
//                continue;
//            ;
//            if (flag == 1)
//            {
//                if (napr == 1)
//                {
//                    pole[str][stb] = 4;
//                    pole[str][stb + 1] = 4;
//                    pole[str][stb + 2] = 4;
//                    pole[str][stb + 3] = 4;
//                }
//                if (napr == 0)
//                {
//                    pole[str][stb] = 4;
//                    pole[str + 1][stb] = 4;
//                    pole[str + 2][stb] = 4;
//                    pole[str + 3][stb] = 4;
//                }
//            }
//            if (napr == 0)
//            {
//                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
//                    pole[str][stb + 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 9 && stb - 1 <= 9 && str + 2 >= 0 && stb - 1 >= 0)
//                    pole[str + 2][stb - 1] = 7;
//                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 9 && stb + 1 <= 9 && str + 2 >= 0 && stb + 1 >= 0)
//                    pole[str + 2][stb + 1] = 7;
//                if (pole[str + 3][stb - 1] == 0 && str + 3 <= 9 && stb - 1 <= 9 && str + 3 >= 0 && stb - 1 >= 0)
//                    pole[str + 3][stb - 1] = 7;
//                if (pole[str + 3][stb + 1] == 0 && str + 3 <= 9 && stb + 1 <= 9 && str + 3 >= 0 && stb + 1 >= 0)
//                    pole[str + 3][stb + 1] = 7;
//                if (pole[str + 4][stb] == 0 && str + 4 <= 9 && stb <= 9 && str + 4 >= 0 && stb >= 0)
//                    pole[str + 4][stb] = 7;
//                if (pole[str + 4][stb - 1] == 0 && str + 4 <= 9 && stb - 1 <= 9 && str + 4 >= 0 && stb - 1 >= 0)
//                    pole[str + 4][stb - 1] = 7;
//                if (pole[str + 4][stb + 1] == 0 && str + 4 <= 9 && stb + 1 <= 9 && str + 4 >= 0 && stb + 1 >= 0)
//                    pole[str + 4][stb + 1] = 7;
//            }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 9 && stb + 2 <= 9 && str - 1 >= 0 && stb + 2 >= 0)
//                    pole[str - 1][stb + 2] = 7;
//                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 9 && stb + 2 <= 9 && str + 1 >= 0 && stb + 2 >= 0)
//                    pole[str + 1][stb + 2] = 7;
//                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 9 && stb + 3 <= 9 && str - 1 >= 0 && stb + 3 >= 0)
//                    pole[str - 1][stb + 3] = 7;
//                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 9 && stb + 3 <= 9 && str + 1 >= 0 && stb + 3 >= 0)
//                    pole[str + 1][stb + 3] = 7;
//                if (pole[str][stb + 4] == 0 && str <= 9 && stb + 4 <= 9 && str >= 0 && stb + 4 >= 0)
//                    pole[str][stb + 4] = 7;
//
//                if (pole[str - 1][stb + 4] == 0 && str - 1 <= 9 && stb + 4 <= 9 && str - 1 >= 0 && stb + 4 >= 0)
//                    pole[str - 1][stb + 4] = 7;
//                if (pole[str + 1][stb + 4] == 0 && str + 1 <= 9 && stb + 4 <= 9 && str + 1 >= 0 && stb + 4 >= 0)
//                    pole[str + 1][stb + 4] = 7;
//            }
//            break;
//        }
//    }
//    for (int i = 0; i < 2; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        int flag = 0;
//        for (int j = 0; j < 100; j++)
//        {
//            str = rand() % 10;
//            stb = rand() % 10;
//            napr = rand() % 2;
//            if (pole[str][stb] == 0)
//            {
//                if (napr == 0)
//                {
//                    if (pole[str + 2][stb] == 0 && pole[str + 1][stb] == 0 && str + 2 <= 9)
//                    {
//                        flag = 1;
//                    }
//                }
//                if (napr == 1)
//                {
//                    if (pole[str][stb + 2] == 0 && pole[str][stb + 1] == 0 && stb + 2 <= 9)
//                    {
//                        flag = 1;
//                    }
//                }
//            }
//            if (flag == 0)
//                continue;
//            ;
//            if (flag == 1)
//            {
//                if (napr == 1)
//                {
//                    pole[str][stb] = 3;
//                    pole[str][stb + 1] = 3;
//                    pole[str][stb + 2] = 3;
//                }
//                if (napr == 0)
//                {
//                    pole[str][stb] = 3;
//                    pole[str + 1][stb] = 3;
//                    pole[str + 2][stb] = 3;
//                }
//            }
//            if (napr == 0)
//            {
//                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
//                    pole[str][stb + 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 9 && stb - 1 <= 9 && str + 2 >= 0 && stb - 1 >= 0)
//                    pole[str + 2][stb - 1] = 7;
//                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 9 && stb + 1 <= 9 && str + 2 >= 0 && stb + 1 >= 0)
//                    pole[str + 2][stb + 1] = 7;
//                if (pole[str + 3][stb] == 0 && str + 3 <= 9 && stb <= 9 && str + 3 >= 0 && stb >= 0)
//                    pole[str + 3][stb] = 7;
//
//                if (pole[str + 3][stb - 1] == 0 && str + 3 <= 9 && stb - 1 <= 9 && str + 3 >= 0 && stb - 1 >= 0)
//                    pole[str + 3][stb - 1] = 7;
//                if (pole[str + 3][stb + 1] == 0 && str + 3 <= 9 && stb + 1 <= 9 && str + 3 >= 0 && stb + 1 >= 0)
//                    pole[str + 3][stb + 1] = 7;
//            }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 9 && stb + 2 <= 9 && str - 1 >= 0 && stb + 2 >= 0)
//                    pole[str - 1][stb + 2] = 7;
//                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 9 && stb + 2 <= 9 && str + 1 >= 0 && stb + 2 >= 0)
//                    pole[str + 1][stb + 2] = 7;
//                if (pole[str][stb + 3] == 0 && str <= 9 && stb + 3 <= 9 && str >= 0 && stb + 3 >= 0)
//                    pole[str][stb + 3] = 7;
//
//                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 9 && stb + 3 <= 9 && str - 1 >= 0 && stb + 3 >= 0)
//                    pole[str - 1][stb + 3] = 7;
//                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 9 && stb + 3 <= 9 && str + 1 >= 0 && stb + 3 >= 0)
//                    pole[str + 1][stb + 3] = 7;
//            }
//            break;
//        }
//    }
//    for (int i = 0; i < 3; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        int flag = 0;
//        for (int j = 0; j < 300; j++)
//        {
//            str = rand() % 10;
//            stb = rand() % 10;
//            napr = rand() % 2;
//            if (pole[str][stb] == 0)
//            {
//                if (napr == 0)
//                {
//                    if (pole[str + 1][stb] == 0 && str + 1 <= 9)
//                    {
//                        flag = 1;
//                    }
//                }
//                if (napr == 1)
//                {
//                    if (pole[str][stb + 1] == 0 && stb + 1 <= 9)
//                    {
//                        flag = 1;
//                    }
//                }
//            }
//            if (flag == 0)
//                continue;
//            ;
//            if (flag == 1)
//            {
//                if (napr == 1)
//                {
//                    pole[str][stb] = 2;
//                    pole[str][stb + 1] = 2;
//                }
//                if (napr == 0)
//                {
//                    pole[str][stb] = 2;
//                    pole[str + 1][stb] = 2;
//                }
//            }
//            if (napr == 0)
//            {
//                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
//                    pole[str][stb + 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str + 2][stb] == 0 && str + 2 <= 9 && stb <= 9 && str + 2 >= 0 && stb >= 0)
//                    pole[str + 2][stb] = 7;
//                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 9 && stb - 1 <= 9 && str + 2 >= 0 && stb - 1 >= 0)
//                    pole[str + 2][stb - 1] = 7;
//                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 9 && stb + 1 <= 9 && str + 2 >= 0 && stb + 1 >= 0)
//                    pole[str + 2][stb + 1] = 7;
//            }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str][stb + 2] == 0 && str <= 9 && stb + 2 <= 9 && str >= 0 && stb + 2 >= 0)
//                    pole[str][stb + 2] = 7;
//                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 9 && stb + 2 <= 9 && str - 1 >= 0 && stb + 2 >= 0)
//                    pole[str][stb + 2] = 7;
//                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 9 && stb + 2 <= 9 && str + 1 >= 0 && stb + 2 >= 0)
//                    pole[str + 1][stb + 2] = 7;
//            }
//            break;
//        }
//    }
//    for (int i = 0; i < 4; i++)
//    {
//        int str;
//        int stb;
//        int flag = 0;
//        for (int j = 0; j < 500; j++)
//        {
//            str = rand() % 10;
//            stb = rand() % 10;
//            if (pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//            if (flag == 1)
//            {
//                pole[str][stb] = 1;
//            }
//            if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
//                pole[str - 1][stb] = 7;
//            if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
//                pole[str - 1][stb - 1] = 7;
//            if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
//                pole[str - 1][stb + 1] = 7;
//            if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
//                pole[str][stb - 1] = 7;
//            if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
//                pole[str][stb + 1] = 7;
//            if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
//                pole[str + 1][stb] = 7;
//            if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
//                pole[str + 1][stb - 1] = 7;
//            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 9 && stb + 1 <= 9 && str + 1 >= 0 && stb + 1 >= 0)
//                pole[str + 1][stb + 1] = 7;
//
//            break;
//        }
//    }
//}
//
//void medi_komp_ten(int pole[10][10])
//{
//    pole[0][0] = 4;
//    pole[0][1] = 4;
//    pole[0][2] = 4;
//    pole[0][3] = 4;
//    pole[2][0] = 2;
//    pole[2][1] = 2;
//    pole[4][0] = 2;
//    pole[4][1] = 2;
//    pole[2][3] = 3;
//    pole[3][3] = 3;
//    pole[4][3] = 3;
//    pole[9][0] = 2;
//    pole[9][1] = 2;
//    pole[7][1] = 3;
//    pole[7][2] = 3;
//    pole[7][3] = 3;
//
//    pole[1][6] = 1;
//    pole[4][7] = 1;
//    pole[8][8] = 1;
//    pole[6][5] = 1;
//}
//
//void hard_komp_ten(int pole[10][10])
//{
//    pole[1][0] = 4;
//    pole[2][0] = 4;
//    pole[3][0] = 4;
//    pole[4][0] = 4;
//    pole[6][0] = 2;
//    pole[7][0] = 2;
//    pole[9][1] = 3;
//    pole[9][2] = 3;
//    pole[9][3] = 3;
//    pole[7][9] = 2;
//    pole[8][9] = 2;
//    pole[0][9] = 3;
//    pole[0][7] = 3;
//    pole[0][8] = 3;
//    pole[3][9] = 2;
//    pole[4][9] = 2;
//    pole[6][4] = 1;
//    pole[3][6] = 1;
//    pole[7][6] = 1;
//    pole[3][3] = 1;
//}
//
//void easy_komp_fif(int pole[15][15])
//{
//    for (int i = 0; i < 1; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        int flag = 0;
//        for (int j = 0; j < 200; j++)
//        {
//            str = rand() % 15;
//            stb = rand() % 15;
//            napr = rand() % 2;
//            if (pole[str][stb] == 0)
//            {
//                if (napr == 0)
//                {
//                    if (pole[str + 4][stb] == 0 && pole[str + 2][stb] == 0 && pole[str + 1][stb] == 0 && str + 4 <= 14)
//                    {
//                        flag = 1;
//                    }
//                }
//                if (napr == 1)
//                {
//                    if (pole[str][stb + 4] == 0 && pole[str][stb + 2] == 0 && pole[str][stb + 1] == 0 && stb + 4 <= 14)
//                    {
//                        flag = 1;
//                    }
//                }
//            }
//            if (flag == 0)
//                continue;
//
//            if (flag == 1)
//            {
//                if (napr == 1)
//                {
//                    pole[str][stb] = 5;
//                    pole[str][stb + 1] = 5;
//                    pole[str][stb + 2] = 5;
//                    pole[str][stb + 3] = 5;
//                    pole[str][stb + 4] = 5;
//                }
//                if (napr == 0)
//                {
//                    pole[str][stb] = 5;
//                    pole[str + 1][stb] = 5;
//                    pole[str + 2][stb] = 5;
//                    pole[str + 3][stb] = 5;
//                    pole[str + 4][stb] = 5;
//                }
//            }
//            if (napr == 0)
//                if (napr == 0)
//                {
//                    if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                        pole[str - 1][stb] = 7;
//                    if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                        pole[str - 1][stb - 1] = 7;
//                    if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                        pole[str - 1][stb + 1] = 7;
//                    if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                        pole[str][stb - 1] = 7;
//                    if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                        pole[str][stb + 1] = 7;
//                    if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                        pole[str + 1][stb - 1] = 7;
//                    if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                        pole[str + 1][stb + 1] = 7;
//                    if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
//                        pole[str + 2][stb - 1] = 7;
//                    if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
//                        pole[str + 2][stb + 1] = 7;
//                    if (pole[str + 3][stb - 1] == 0 && str + 3 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
//                        pole[str + 3][stb - 1] = 7;
//                    if (pole[str + 3][stb + 1] == 0 && str + 3 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
//                        pole[str + 3][stb + 1] = 7;
//                    if (pole[str + 4][stb - 1] == 0 && str + 4 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
//                        pole[str + 4][stb - 1] = 7;
//                    if (pole[str + 4][stb + 1] == 0 && str + 4 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
//                        pole[str + 4][stb + 1] = 7;
//                    if (pole[str + 5][stb] == 0 && str + 5 <= 14 && stb <= 14 && str + 4 >= 0 && stb >= 0)
//                        pole[str + 5][stb] = 7;
//                    if (pole[str + 5][stb - 1] == 0 && str + 4 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
//                        pole[str + 5][stb - 1] = 7;
//                    if (pole[str + 5][stb + 1] == 0 && str + 4 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
//                        pole[str + 5][stb + 1] = 7;
//                }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
//                    pole[str - 1][stb + 2] = 7;
//                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
//                    pole[str + 1][stb + 2] = 7;
//                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 14 && stb + 3 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
//                    pole[str - 1][stb + 3] = 7;
//                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 14 && stb + 3 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
//                    pole[str + 1][stb + 3] = 7;
//                if (pole[str - 1][stb + 4] == 0 && str - 1 <= 14 && stb + 4 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
//                    pole[str - 1][stb + 4] = 7;
//                if (pole[str + 1][stb + 4] == 0 && str + 1 <= 14 && stb + 4 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
//                    pole[str + 1][stb + 4] = 7;
//                if (pole[str][stb + 5] == 0 && str <= 14 && stb + 5 <= 14 && str >= 0 && stb + 4 >= 0)
//                    pole[str][stb + 5] = 7;
//                if (pole[str - 1][stb + 5] == 0 && str - 1 <= 14 && stb + 4 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
//                    pole[str - 1][stb + 5] = 7;
//                if (pole[str + 1][stb + 5] == 0 && str + 1 <= 14 && stb + 4 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
//                    pole[str + 1][stb + 5] = 7;
//            }
//            break;
//        }
//    }
//    for (int i = 0; i < 1; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        int flag = 0;
//        for (int j = 0; j < 200; j++)
//        {
//            str = rand() % 15;
//            stb = rand() % 15;
//            napr = rand() % 2;
//            if (pole[str][stb] == 0)
//            {
//                if (napr == 0)
//                {
//                    if (pole[str + 3][stb] == 0 && pole[str + 2][stb] == 0 && pole[str + 1][stb] == 0 && str + 3 <= 14)
//                    {
//                        flag = 1;
//                    }
//                }
//                if (napr == 1)
//                {
//                    if (pole[str][stb + 3] == 0 && pole[str][stb + 2] == 0 && pole[str][stb + 1] == 0 && stb + 3 <= 14)
//                    {
//                        flag = 1;
//                    }
//                }
//            }
//            if (flag == 0)
//                continue;
//
//            if (flag == 1)
//            {
//                if (napr == 1)
//                {
//                    pole[str][stb] = 4;
//                    pole[str][stb + 1] = 4;
//                    pole[str][stb + 2] = 4;
//                    pole[str][stb + 3] = 4;
//                }
//                if (napr == 0)
//                {
//                    pole[str][stb] = 4;
//                    pole[str + 1][stb] = 4;
//                    pole[str + 2][stb] = 4;
//                    pole[str + 3][stb] = 4;
//                }
//            }
//            if (napr == 0)
//            {
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                    pole[str][stb + 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
//                    pole[str + 2][stb - 1] = 7;
//                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
//                    pole[str + 2][stb + 1] = 7;
//                if (pole[str + 3][stb - 1] == 0 && str + 3 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
//                    pole[str + 3][stb - 1] = 7;
//                if (pole[str + 3][stb + 1] == 0 && str + 3 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
//                    pole[str + 3][stb + 1] = 7;
//                if (pole[str + 4][stb] == 0 && str + 4 <= 14 && stb <= 14 && str + 4 >= 0 && stb >= 0)
//                    pole[str + 4][stb] = 7;
//                if (pole[str + 4][stb - 1] == 0 && str + 4 <= 14 && stb - 1 <= 14 && str + 4 >= 0 && stb - 1 >= 0)
//                    pole[str + 4][stb - 1] = 7;
//                if (pole[str + 4][stb + 1] == 0 && str + 4 <= 14 && stb + 1 <= 14 && str + 4 >= 0 && stb + 1 >= 0)
//                    pole[str + 4][stb + 1] = 7;
//            }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
//                    pole[str - 1][stb + 2] = 7;
//                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
//                    pole[str + 1][stb + 2] = 7;
//                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 14 && stb + 3 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
//                    pole[str - 1][stb + 3] = 7;
//                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 14 && stb + 3 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
//                    pole[str + 1][stb + 3] = 7;
//                if (pole[str][stb + 4] == 0 && str <= 14 && stb + 4 <= 14 && str >= 0 && stb + 4 >= 0)
//                    pole[str][stb + 4] = 7;
//                if (pole[str + 1][stb + 4] == 0 && str + 1 <= 14 && stb + 4 <= 14 && str + 1 >= 0 && stb + 4 >= 0)
//                    pole[str + 1][stb + 4] = 7;
//                if (pole[str - 1][stb + 4] == 0 && str - 1 <= 14 && stb + 4 <= 14 && str - 1 >= 0 && stb + 4 >= 0)
//                    pole[str - 1][stb + 4] = 7;
//            }
//            break;
//        }
//    }
//    for (int i = 0; i < 2; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        int flag = 0;
//        for (int j = 0; j < 200; j++)
//        {
//            str = rand() % 15;
//            stb = rand() % 15;
//            napr = rand() % 2;
//            if (pole[str][stb] == 0)
//            {
//                if (napr == 0)
//                {
//                    if (pole[str + 2][stb] == 0 && pole[str + 1][stb] == 0 && str + 2 <= 14)
//                    {
//                        flag = 1;
//                    }
//                }
//                if (napr == 1)
//                {
//                    if (pole[str][stb + 2] == 0 && pole[str][stb + 1] == 0 && stb + 2 <= 14)
//                    {
//                        flag = 1;
//                    }
//                }
//            }
//            if (flag == 0)
//                continue;
//            ;
//            if (flag == 1)
//            {
//                if (napr == 1)
//                {
//                    pole[str][stb] = 3;
//                    pole[str][stb + 1] = 3;
//                    pole[str][stb + 2] = 3;
//                }
//                if (napr == 0)
//                {
//                    pole[str][stb] = 3;
//                    pole[str + 1][stb] = 3;
//                    pole[str + 2][stb] = 3;
//                }
//            }
//            if (napr == 0)
//            {
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                    pole[str][stb + 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
//                    pole[str + 2][stb - 1] = 7;
//                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
//                    pole[str + 2][stb + 1] = 7;
//                if (pole[str + 3][stb] == 0 && str + 3 <= 14 && stb <= 14 && str + 3 >= 0 && stb >= 0)
//                    pole[str + 3][stb] = 7;
//                if (pole[str + 3][stb - 1] == 0 && str + 3 <= 14 && stb - 1 <= 14 && str + 3 >= 0 && stb - 1 >= 0)
//                    pole[str + 3][stb - 1] = 7;
//                if (pole[str + 3][stb + 1] == 0 && str + 3 <= 14 && stb + 1 <= 14 && str + 3 >= 0 && stb + 1 >= 0)
//                    pole[str + 3][stb + 1] = 7;
//            }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
//                    pole[str - 1][stb + 2] = 7;
//                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
//                    pole[str + 1][stb + 2] = 7;
//                if (pole[str][stb + 3] == 0 && str <= 14 && stb + 3 <= 14 && str >= 0 && stb + 3 >= 0)
//                    pole[str][stb + 3] = 7;
//                if (pole[str - 1][stb + 3] == 0 && str - 1 <= 14 && stb + 3 <= 14 && str - 1 >= 0 && stb + 3 >= 0)
//                    pole[str][stb + 3] = 7;
//                if (pole[str + 1][stb + 3] == 0 && str + 1 <= 14 && stb + 3 <= 14 && str + 1 >= 0 && stb + 3 >= 0)
//                    pole[str + 1][stb + 3] = 7;
//            }
//            break;
//        }
//    }
//    for (int i = 0; i < 3; i++)
//    {
//        int str;
//        int stb;
//        int napr;
//        int flag = 0;
//        for (int j = 0; j < 300; j++)
//        {
//            str = rand() % 15;
//            stb = rand() % 15;
//            napr = rand() % 2;
//            if (pole[str][stb] == 0)
//            {
//                if (napr == 0)
//                {
//                    if (pole[str + 1][stb] == 0 && str + 1 <= 14)
//                    {
//                        flag = 1;
//                    }
//                }
//                if (napr == 1)
//                {
//                    if (pole[str][stb + 1] == 0 && stb + 1 <= 14)
//                    {
//                        flag = 1;
//                    }
//                }
//            }
//            if (flag == 0)
//                continue;
//            ;
//            if (flag == 1)
//            {
//                if (napr == 1)
//                {
//                    pole[str][stb] = 2;
//                    pole[str][stb + 1] = 2;
//                }
//                if (napr == 0)
//                {
//                    pole[str][stb] = 2;
//                    pole[str + 1][stb] = 2;
//                }
//            }
//            if (napr == 0)
//            {
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                    pole[str][stb + 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str + 2][stb] == 0 && str + 2 <= 14 && stb <= 14 && str + 2 >= 0 && stb >= 0)
//                    pole[str + 2][stb] = 7;
//                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
//                    pole[str + 2][stb] = 7;
//                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 14 && stb + 1 <= 14 && str + 2 >= 0 && stb + 1 >= 0)
//                    pole[str + 2][stb + 1] = 7;
//            }
//            if (napr == 1)
//            {
//                if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                    pole[str][stb - 1] = 7;
//                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                    pole[str - 1][stb - 1] = 7;
//                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                    pole[str + 1][stb - 1] = 7;
//                if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                    pole[str - 1][stb] = 7;
//                if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
//                    pole[str + 1][stb] = 7;
//                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                    pole[str - 1][stb + 1] = 7;
//                if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                    pole[str + 1][stb + 1] = 7;
//                if (pole[str][stb + 2] == 0 && str <= 14 && stb + 2 <= 14 && str >= 0 && stb + 2 >= 0)
//                    pole[str][stb + 2] = 7;
//                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 14 && stb + 2 <= 14 && str - 1 >= 0 && stb + 2 >= 0)
//                    pole[str - 1][stb + 2] = 7;
//                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 14 && stb + 2 <= 14 && str + 1 >= 0 && stb + 2 >= 0)
//                    pole[str + 1][stb + 2] = 7;
//            }
//            break;
//        }
//    }
//    for (int i = 0; i < 4; i++)
//    {
//        int str;
//        int stb;
//        int flag = 0;
//        for (int j = 0; j < 500; j++)
//        {
//            str = rand() % 15;
//            stb = rand() % 15;
//            if (pole[str][stb] == 0)
//            {
//                flag = 1;
//            }
//            if (flag == 0)
//                continue;
//            if (flag == 1)
//            {
//                pole[str][stb] = 1;
//            }
//            if (pole[str - 1][stb] == 0 && str - 1 <= 14 && stb <= 14 && str - 1 >= 0 && stb >= 0)
//                pole[str - 1][stb] = 7;
//            if (pole[str - 1][stb - 1] == 0 && str - 1 <= 14 && stb - 1 <= 14 && str - 1 >= 0 && stb - 1 >= 0)
//                pole[str - 1][stb - 1] = 7;
//            if (pole[str - 1][stb + 1] == 0 && str - 1 <= 14 && stb + 1 <= 14 && str - 1 >= 0 && stb + 1 >= 0)
//                pole[str - 1][stb + 1] = 7;
//            if (pole[str][stb - 1] == 0 && str <= 14 && stb - 1 <= 14 && str >= 0 && stb - 1 >= 0)
//                pole[str][stb - 1] = 7;
//            if (pole[str + 1][stb - 1] == 0 && str + 1 <= 14 && stb - 1 <= 14 && str + 1 >= 0 && stb - 1 >= 0)
//                pole[str + 1][stb - 1] = 7;
//            if (pole[str][stb + 1] == 0 && str <= 14 && stb + 1 <= 14 && str >= 0 && stb + 1 >= 0)
//                pole[str][stb + 1] = 7;
//            if (pole[str + 1][stb] == 0 && str + 1 <= 14 && stb <= 14 && str + 1 >= 0 && stb >= 0)
//                pole[str + 1][stb] = 7;
//            if (pole[str + 1][stb + 1] == 0 && str + 1 <= 14 && stb + 1 <= 14 && str + 1 >= 0 && stb + 1 >= 0)
//                pole[str + 1][stb + 1] = 7;
//
//            break;
//        }
//    }
//}
//
//void medi_komp_fif(int pole[15][15])
//{
//    pole[0][5] = 4;
//    pole[1][5] = 4;
//    pole[2][5] = 4;
//    pole[3][5] = 4;
//    pole[2][1] = 3;
//    pole[2][2] = 3;
//    pole[2][3] = 3;
//    pole[4][3] = 2;
//    pole[5][3] = 2;
//    pole[7][0] = 3;
//    pole[7][1] = 3;
//    pole[7][2] = 3;
//    pole[10][1] = 2;
//    pole[11][1] = 2;
//    pole[13][3] = 2;
//    pole[14][3] = 2;
//    pole[8][5] = 5;
//    pole[9][5] = 5;
//    pole[10][5] = 5;
//    pole[11][5] = 5;
//    pole[12][5] = 5;
//    pole[0][13] = 1;
//    pole[2][9] = 1;
//    pole[7][12] = 1;
//    pole[13][10] = 1;
//}
//
//void hard_komp_fif(int pole[15][15])
//
//{
//    pole[1][0] = 4;
//    pole[2][0] = 4;
//    pole[3][0] = 4;
//    pole[4][0] = 4;
//    pole[9][0] = 2;
//    pole[10][0] = 2;
//    pole[14][3] = 5;
//    pole[14][4] = 5;
//    pole[14][5] = 5;
//    pole[14][6] = 5;
//    pole[14][7] = 5;
//    pole[14][12] = 3;
//    pole[14][13] = 3;
//    pole[14][14] = 3;
//    pole[9][14] = 2;
//    pole[10][14] = 2;
//    pole[0][12] = 3;
//    pole[0][13] = 3;
//    pole[0][14] = 3;
//    pole[0][2] = 2;
//    pole[0][3] = 2;
//    pole[3][8] = 1;
//    pole[11][8] = 1;
//    pole[8][5] = 1;
//    pole[7][10] = 1;
//}
//
//void game_chel_komp_ten(int my_pole[10][10], int pole[10][10], int *count, int *count_b)
//{
//    int count_chel = 0;
//    int count_rob = 0;
//
//    for (int i = 0; i < 10000 && count_chel < 10 && count_rob < 10; i++)
//    {
//        if (count_chel == 10)
//            break;
//        for (int j = 0; i < 1000; j++)
//        {
//            if (count_chel == 10)
//                break;
//            int str;
//            int stlb;
//            char sim1;
//            int sim2;
//            int flag = 0;
//            printf("Hod:\n");
//            scanf(" %c%d", &sim1, &sim2);
//            stlb = trans(sim1);
//            str = sim2 - 1;
//            if (str <= 9 && stlb <= 9 && str >= 0 && stlb >= 0 && pole[str][stlb] != 7 && pole[str][stlb] != 6)
//            {
//                flag = 2;
//                if (pole[str][stlb] == 1)
//                {
//                    printf("Ubit!\n");
//                    count_chel++;
//                    pole[str][stlb] = 7;
//                     if(count_chel==10) break;
//                }
//                if (pole[str][stlb] == 2)
//                {
//                    pole[str][stlb] = 7;
//                    if (pole[str][stlb - 1] != 2 && pole[str][stlb + 1] != 2 && pole[str - 1][stlb] != 2 && pole[str + 1][stlb] != 2)
//                    {
//                        count_chel++;
//                        printf("Ubit!\n");
//                         if(count_chel==10) break;
//                    }
//                    else
//                        printf("Ranen!\n");
//                }
//                if (pole[str][stlb] == 3)
//                {
//                    pole[str][stlb] = 7;
//                    if (pole[str][stlb - 1] != 3 && pole[str][stlb + 1] != 3 && pole[str - 1][stlb] != 3 && pole[str + 1][stlb] != 3)
//                    {
//                        if (pole[str][stlb - 1] == 7)
//                        {
//                            if (pole[str][stlb - 2] == 7)
//                            {
//                                count_chel++;
//                                printf("Ubit!\n");
//                                  if(count_chel==10) break;
//                            }
//                            if (pole[str][stlb - 2] == 3)
//                            {
//                                printf("Ranen!\n");
//                            }
//                        }
//                        if (pole[str][stlb + 1] == 7)
//                        {
//                            if (pole[str][stlb + 2] == 7)
//                            {
//                                count_chel++;
//                                printf("Ubit!\n");
//                                 if(count_chel==10) break;
//                            }
//                            if (pole[str][stlb + 2] == 3)
//                            {
//                                printf("Ranen!\n");
//                            }
//                        }
//                        if (pole[str - 1][stlb] == 7)
//                        {
//                            if (pole[str - 2][stlb] == 7)
//                            {
//                                count_chel++;
//                                printf("Ubit!\n");
//                                 if(count_chel==10) break;
//                            }
//                            if (pole[str - 2][stlb] == 3)
//                            {
//                                printf("Ranen!\n");
//                            }
//                        }
//                        if (pole[str + 1][stlb] == 7)
//                        {
//                            if (pole[str + 2][stlb] == 7)
//                            {
//                                count_chel++;
//                                printf("Ubit!\n");
//                                 if(count_chel==10) break;
//                            }
//                            if (pole[str + 2][stlb] == 3)
//                            {
//                                printf("Ranen!\n");
//                            }
//                        }
//                    }
//                    else
//                        printf("Ranen!\n");
//                }
//                if (pole[str][stlb] == 4)
//                {
//                    pole[str][stlb] = 7;
//                    if (pole[str][stlb - 1] != 4 && pole[str][stlb - 2] != 4 && pole[str][stlb - 3] != 4 && pole[str][stlb + 1] != 4 && pole[str][stlb + 2] != 4 && pole[str][stlb + 3] != 4 && pole[str - 2][stlb] != 4 && pole[str - 1][stlb] != 4 && pole[str - 3][stlb] != 4 && pole[str + 2][stlb] != 4 && pole[str + 3][stlb] != 4 && pole[str + 1][stlb] != 4)
//                    {
//                        count_chel++;
//                        printf("Ubit!\n");
//                         if(count_chel==10) break;
//                    }
//                    else
//                        printf("Ranen!\n");
//                }
//                if (pole[str][stlb] == 0)
//                {
//                    flag = 1;
//                    printf("Mimo!\n");
//                    pole[str][stlb] = 6;
//                }
//            }
//            if (flag == 0)
//                continue;
//            if (flag == 2)
//                continue;
//
//            printf("\n\n\n");
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4 && my_pole[i][j] != 6 && my_pole[i][j] != 7)
//                        my_pole[i][j] = 0;
//                }
//            }
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    printf("%d ", my_pole[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\n\n\n");
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4 && pole[i][j] != 6 && pole[i][j] != 7)
//                        pole[i][j] = 0;
//                }
//            }
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    printf("%d ", pole[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\n\n\n");
//            if (flag == 1)
//                break;
//        }
//        for (int j = 0; j < 1000; j++)
//        {
//            if (count_rob == 10)
//                break;
//            int ll;
//            int kk;
//            int ss;
//            int flag_k = 0;
//            printf("Ход бота!\n");
//            int str_k, stlb_k;
//            str_k = rand() % 10;
//            stlb_k = rand() % 10;
//            if (str_k <= 9 && stlb_k <= 9 && str_k >= 0 && stlb_k >= 0 && my_pole[str_k][stlb_k] != 7 && my_pole[str_k][stlb_k] != 6)
//            {
//                if (my_pole[str_k][stlb_k] == 1)
//                {
//                    printf("Убит!\n");
//                    printf("%d %d\n", str_k, stlb_k);
//                    count_rob++;
//
//                    my_pole[str_k][stlb_k] = 7;
//                     if(count_rob==10) break;
//                }
//                if (my_pole[str_k][stlb_k] == 2)
//                {
//                    my_pole[str_k][stlb_k] = 7;
//                    if (my_pole[str_k][stlb_k - 1] != 2 && my_pole[str_k][stlb_k + 1] != 2 && my_pole[str_k - 1][stlb_k] != 2 && my_pole[str_k + 1][stlb_k] != 2)
//                    {
//                        count_rob++;
//                        printf("Убит!\n");
//
//                        printf("%d %d\n", str_k, stlb_k);
//                         if(count_rob==10) break;
//                    }
//                    else
//                    {
//                        printf("Ранен!\n");
//                        printf("%d %d\n", str_k, stlb_k);
//                        for (int h = 0; h < 1000; h++)
//                        {
//                            ll = rand() % 4;
//                            if (ll == 0 && str_k - 1 >= 0 && my_pole[str_k - 1][stlb_k] != 6)
//                                break;
//                            if (ll == 1 && stlb_k - 1 >= 0 && my_pole[str_k][stlb_k - 1] != 6)
//                                break;
//                            if (ll == 2 && str_k + 1 <= 9 && my_pole[str_k + 1][stlb_k] != 6)
//                                break;
//                            if (ll == 3 && stlb_k + 1 <= 9 && my_pole[str_k][stlb_k + 1] != 6)
//                                break;
//                        }
//
//                        if (ll == 0)
//                        {
//
//                            if (my_pole[str_k - 1][stlb_k] == 2)
//                            {
//                                my_pole[str_k - 1][stlb_k] = 7;
//                                count_rob++;
//                                printf("Убит!\n");
//                                printf("%d %d\n", str_k - 1, stlb_k);
//                                 if(count_rob==10) break;
//                            }
//                            else
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k - 1, stlb_k);
//                                flag_k = 1;
//                                my_pole[str_k - 1][stlb_k] = 6;
//                            }
//                        }
//                        if (ll == 1)
//                        {
//                            if (my_pole[str_k][stlb_k - 1] == 2)
//                            {
//                                my_pole[str_k][stlb_k - 1] = 7;
//                                count_rob++;
//                                printf("Убит!\n");
//                                printf("%d %d\n", str_k, stlb_k - 1);
//                                 if(count_rob==10) break;
//                            }
//
//                            else
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k, stlb_k - 1);
//                                flag_k = 1;
//                                my_pole[str_k][stlb_k - 1] = 6;
//                            }
//                        }
//                        if (ll == 3)
//                        {
//                            if (my_pole[str_k][stlb_k + 1] == 2)
//                            {
//                                my_pole[str_k][stlb_k + 1] = 7;
//                                count_rob++;
//                                printf("Убит!\n");
//                                printf("%d %d\n", str_k, stlb_k + 1);
//                                 if(count_rob==10) break;
//                            }
//
//                            else
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k, stlb_k + 1);
//                                flag_k = 1;
//                                my_pole[str_k][stlb_k + 1] = 6;
//                            }
//                        }
//                        if (ll == 2)
//                        {
//                            if (my_pole[str_k + 1][stlb_k] == 2)
//                            {
//                                my_pole[str_k + 1][stlb_k] = 7;
//                                count_rob++;
//                                printf("Убит!\n");
//                                printf("%d %d\n", str_k + 1, stlb_k);
//                                 if(count_rob==10) break;
//                            }
//                            else
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k + 1, stlb_k);
//                                flag_k = 1;
//                                my_pole[str_k + 1][stlb_k] = 6;
//                            }
//                        }
//                    }
//                }
//                if (my_pole[str_k][stlb_k] == 3)
//                {
//                    my_pole[str_k][stlb_k] = 7;
//
//                    if (my_pole[str_k][stlb_k - 1] != 3 && my_pole[str_k][stlb_k + 1] != 3 && my_pole[str_k - 1][stlb_k] != 3 && my_pole[str_k + 1][stlb_k] != 3)
//                    {
//
//                        if (my_pole[str_k][stlb_k - 1] == 7 && my_pole[str_k][stlb_k - 2] == 7)
//                        {
//                            count_rob++;
//                            printf("Убит!\n");
//                             if(count_rob==10) break;
//                        }
//                        if (my_pole[str_k][stlb_k - 1] == 7 && my_pole[str_k][stlb_k - 2] == 3)
//                        {
//                            my_pole[str_k][stlb_k - 2] = 7;
//                            count_rob++;
//                            printf("Убит!\n");
//                             if(count_rob==10) break;
//                        }
//
//                        if (my_pole[str_k][stlb_k + 1] == 7 && my_pole[str_k][stlb_k + 2] == 7)
//                        {
//                            count_rob++;
//                            printf("Убит!\n");
//                             if(count_rob==10) break;
//                        }
//                        if (my_pole[str_k][stlb_k + 1] == 7 && my_pole[str_k][stlb_k + 2] == 3)
//                        {
//                            my_pole[str_k][stlb_k + 2] = 7;
//                            count_rob++;
//                            printf("Убит!\n");
//                             if(count_rob==10) break;
//                        }
//
//                        if (my_pole[str_k - 1][stlb_k] == 7 && my_pole[str_k - 2][stlb_k] == 7)
//                        {
//                            count_rob++;
//                            printf("Убит!\n");
//                             if(count_rob==10) break;
//                        }
//                        if (my_pole[str_k - 1][stlb_k] == 7 && my_pole[str_k - 2][stlb_k] == 3)
//                        {
//                            my_pole[str_k - 2][stlb_k] = 7;
//                            count_rob++;
//                            printf("Убит!\n");
//                             if(count_rob==10) break;
//                        }
//
//                        if (my_pole[str_k + 1][stlb_k] == 7 && my_pole[str_k + 2][stlb_k] == 7)
//                        {
//                            count_rob++;
//                            printf("Убит!\n");
//                             if(count_rob==10) break;
//                        }
//                        if (my_pole[str_k + 1][stlb_k] == 7 && my_pole[str_k + 2][stlb_k] == 3)
//                        {
//                            my_pole[str_k + 2][stlb_k] = 7;
//                            count_rob++;
//                            printf("Убит!\n");
//                             if(count_rob==10) break;
//                        }
//                    }
//                    else
//                    {
//                        printf("Ранен!\n");
//                        printf("%d %d\n", str_k, stlb_k);
//
//                        for (int h = 0; h < 1000; h++)
//                        {
//                            kk = rand() % 4;
//                            if (kk == 0 && str_k - 1 >= 0 && my_pole[str_k - 1][stlb_k] != 6 && my_pole[str_k - 1][stlb_k] != 7)
//                                break;
//                            if (kk == 1 && stlb_k - 1 >= 0 && my_pole[str_k][stlb_k - 1] != 6 && my_pole[str_k][stlb_k - 1] != 7)
//                                break;
//                            if (kk == 2 && str_k + 1 <= 9 && my_pole[str_k + 1][stlb_k] != 6 && my_pole[str_k + 1][stlb_k] != 7)
//                                break;
//                            if (kk == 3 && stlb_k + 1 <= 9 && my_pole[str_k][stlb_k + 1] != 6 && my_pole[str_k][stlb_k + 1] != 7)
//                                break;
//                        }
//                        if (kk == 0)
//                        {
//                            if (my_pole[str_k - 1][stlb_k] == 3)
//                            {
//                                my_pole[str_k - 1][stlb_k] = 7;
//                                if (my_pole[str_k - 2][stlb_k] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                      if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k + 1][stlb_k] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                     if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k + 1][stlb_k] == 3)
//                                {
//                                    printf("Ранен!\n");
//                                    printf("%d %d\n", str_k + 1, stlb_k);
//                                    my_pole[str_k + 1][stlb_k] = 7;
//                                    printf("Убит!\n");
//
//                                    count_rob++;
//                                    printf("%d %d\n", str_k + 1, stlb_k);
//                                       if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k - 2][stlb_k] == 3)
//                                {
//                                    printf("Ранен!\n");
//                                    printf("%d %d\n", str_k - 2, stlb_k);
//                                    my_pole[str_k - 2][stlb_k] = 7;
//                                    printf("Убит!\n");
//
//                                    count_rob++;
//                                    printf("%d %d\n", str_k - 2, stlb_k);
//                                     if(count_rob==10) break;
//                                }
//                            }
//                            else
//                            {
//                                printf("Мимо!\n");
//                                flag_k = 1;
//
//                                if (my_pole[str_k - 1][stlb_k] == 0)
//                                    my_pole[str_k - 1][stlb_k] = 6;
//                            }
//                        }
//                        if (kk == 1)
//                        {
//                            if (my_pole[str_k][stlb_k - 1] == 3)
//                            {
//                                my_pole[str_k][stlb_k - 1] = 7;
//                                if (my_pole[str_k][stlb_k - 2] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                      if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k][stlb_k + 1] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                       if(count_rob==10) break;
//                                }
//
//                                if (my_pole[str_k][stlb_k + 1] == 3)
//                                {
//                                    printf("Ранен!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 1);
//                                    my_pole[str_k][stlb_k + 1] = 7;
//                                    printf("Убит!\n");
//                                    count_rob++;
//                                    printf("%d %d\n", str_k, stlb_k + 1);
//                                      if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k][stlb_k - 2] == 3)
//                                {
//                                    printf("Ранен!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 2);
//                                    my_pole[str_k][stlb_k - 2] = 7;
//                                    printf("Убит!\n");
//                                    count_rob++;
//                                    printf("%d %d\n", str_k, stlb_k - 2);
//                                      if(count_rob==10) break;
//                                }
//                            }
//                            else
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k, stlb_k - 1);
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 1] == 0)
//                                    my_pole[str_k][stlb_k - 1] = 6;
//                            }
//                        }
//                        if (kk == 2)
//                        {
//                            if (my_pole[str_k + 1][stlb_k] == 3)
//                            {
//                                my_pole[str_k + 1][stlb_k] = 7;
//                                if (my_pole[str_k + 2][stlb_k] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                      if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k - 1][stlb_k] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                      if(count_rob==10) break;
//                                }
//
//                                if (my_pole[str_k - 1][stlb_k] == 3)
//                                {
//                                    printf("Ранен!\n");
//                                    printf("%d %d\n", str_k - 1, stlb_k);
//                                    my_pole[str_k - 1][stlb_k] = 7;
//                                    printf("Убит!\n");
//                                     if(count_rob==10) break;
//                                    count_rob++;
//                                    printf("%d %d\n", str_k - 1, stlb_k);
//                                }
//                                if (my_pole[str_k + 2][stlb_k] == 3)
//                                {
//                                    printf("Ранен!\n");
//                                    printf("%d %d\n", str_k + 2, stlb_k);
//                                    my_pole[str_k + 2][stlb_k] = 7;
//                                    printf("Убит!\n");
//                                     if(count_rob==10) break;
//                                    count_rob++;
//                                    printf("%d %d\n", str_k + 2, stlb_k);
//                                }
//                            }
//                            else
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k + 1, stlb_k);
//                                flag_k = 1;
//                                if (my_pole[str_k + 1][stlb_k] == 0)
//                                    my_pole[str_k + 1][stlb_k] = 6;
//                            }
//                        }
//                        if (kk == 3)
//                        {
//
//                            if (my_pole[str_k][stlb_k + 1] == 3)
//                            {
//                                my_pole[str_k][stlb_k + 1] = 7;
//                                if (my_pole[str_k][stlb_k + 2] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                     if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k][stlb_k - 1] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                     if(count_rob==10) break;
//                                }
//
//                                if (my_pole[str_k][stlb_k - 1] == 3)
//                                {
//                                    printf("Ранен!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 1);
//                                    my_pole[str_k][stlb_k - 1] = 7;
//                                    printf("Убит!\n");
//                                    count_rob++;
//                                    printf("%d %d\n", str_k, stlb_k - 1);
//                                      if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k][stlb_k + 2] == 3)
//                                {
//                                    printf("Ранен!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 2);
//                                    my_pole[str_k][stlb_k + 2] = 7;
//                                    printf("Убит!\n");
//                                    count_rob++;
//                                    printf("%d %d\n", str_k, stlb_k + 2);
//                                      if(count_rob==10) break;
//                                }
//
//                            } // posle pervogo ranen ne dva, TROIKI I DVOIKI STRELIAUT POVTORNO KUDA USHE STRLIALI
//
//                            else
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k, stlb_k + 1);
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 1] == 0)
//                                    my_pole[str_k][stlb_k + 1] = 6;
//                            }
//                        }
//                    }
//                }
//                int oe = 0;
//                int oes = 0;
//                int oess = 0;
//
//                if (my_pole[str_k][stlb_k] == 4)
//                {
//                    my_pole[str_k][stlb_k] = 7;
//                    if (my_pole[str_k][stlb_k - 1] != 4 && my_pole[str_k][stlb_k + 1] != 4 && my_pole[str_k - 1][stlb_k] != 4 && my_pole[str_k + 1][stlb_k] != 4 && my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k + 3] != 4 && my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                    {
//                        count_rob++;
//                        printf("Убит!\n");
//                        printf("%d %d\n", str_k, stlb_k);
//                         if(count_rob==10) break;
//                    }
//                    else
//                    {
//                        printf("Ранен!\n");
//                        printf("%d %d\n", str_k, stlb_k);
//                        for (int h = 0; h < 1000; h++)
//                        {
//                            ss = rand() % 4;
//                            if (ss == 0 && str_k - 1 >= 0 && my_pole[str_k - 1][stlb_k] != 6 && my_pole[str_k - 1][stlb_k] != 7)
//                                break;
//                            if (ss == 1 && stlb_k - 1 >= 0 && my_pole[str_k][stlb_k - 1] != 6 && my_pole[str_k][stlb_k - 1] != 7)
//                                break;
//                            if (ss == 2 && str_k + 1 <= 9 && my_pole[str_k + 1][stlb_k] != 6 && my_pole[str_k + 1][stlb_k] != 7)
//                                break;
//                            if (ss == 3 && stlb_k + 1 <= 9 && my_pole[str_k][stlb_k + 1] != 6 && my_pole[str_k][stlb_k + 1] != 7)
//                                break;
//                        }
//                        if (ss == 0)
//                        {
//                            if (my_pole[str_k - 1][stlb_k] == 4)
//                            {
//                                oe = 1;
//                                my_pole[str_k - 1][stlb_k] = 7;
//                                if (my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k + 1][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                     if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ранен\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k - 2][stlb_k] == 4)
//                                {
//                                    oe = 2;
//                                    my_pole[str_k - 2][stlb_k] = 7;
//                                    if (my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k + 1][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Убит!\n");
//                                           if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ранен\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k - 3][stlb_k] == 4)
//                                {
//                                    my_pole[str_k - 3][stlb_k] = 7;
//                                    if (my_pole[str_k + 1][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Убит!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ранен\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                 тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k - 1][stlb_k] != 4 && my_pole[str_k - 1][stlb_k] != 7)
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k - 1, stlb_k);
//                                flag_k = 1;
//                                if (my_pole[str_k - 1][stlb_k] == 0)
//                                    my_pole[str_k - 1][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k - 2][stlb_k] != 7 && oe >= 1)
//                            {
//                                if (my_pole[str_k - 2][stlb_k] == 0)
//                                {
//                                    printf("Мимо!\n");
//                                    printf("%d %d\n", str_k - 2, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k - 2][stlb_k] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k - 2][stlb_k] == 0)
//                                    my_pole[str_k - 2][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k - 3][stlb_k] != 7 && oe >= 2)
//                            {
//                                if (my_pole[str_k - 3][stlb_k] == 0)
//                                {
//                                    printf("Мимо!\n");
//                                    printf("%d %d\n", str_k - 3, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k - 3][stlb_k] == 6)
//                                    flag_k = 0;
//
//                                if (my_pole[str_k - 3][stlb_k] == 0)
//                                    my_pole[str_k - 3][stlb_k] = 6;
//                            }
//                        }
//                        if (ss == 1)
//                        {
//                            if (my_pole[str_k][stlb_k - 1] == 4)
//                            {
//                                oes = 1;
//                                my_pole[str_k][stlb_k - 1] = 7;
//                                if (my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k + 1] != 4 && my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k][stlb_k + 3] != 4)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                     if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ранен\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k][stlb_k - 2] == 4)
//                                {
//                                    oes = 2;
//                                    my_pole[str_k][stlb_k - 2] = 7;
//                                    if (my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k + 1] != 4 && my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k][stlb_k + 3] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Убит!\n");
//                                            if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ранен\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k][stlb_k - 3] == 4)
//                                {
//                                    my_pole[str_k][stlb_k - 3] = 7;
//                                    if (my_pole[str_k][stlb_k + 1] != 4 && my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k][stlb_k + 3] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Убит!\n");
//                                           if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ранен\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                    тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k][stlb_k - 1] != 4 && my_pole[str_k][stlb_k - 1] != 7)
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k, stlb_k - 1);
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 1] == 0)
//                                    my_pole[str_k][stlb_k - 1] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k - 2] != 7 && oes >= 1)
//                            {
//                                if (my_pole[str_k][stlb_k - 2] == 0)
//                                {
//                                    printf("Мимо!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 2);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 2] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k - 2] == 0)
//                                    my_pole[str_k][stlb_k - 2] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k - 3] != 7 && oes >= 2)
//                            {
//                                if (my_pole[str_k][stlb_k - 3] == 0)
//                                {
//                                    printf("Мимо!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 3);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 3] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k - 3] == 0)
//                                    my_pole[str_k][stlb_k - 3] = 6;
//                            }
//
//                            oe = 0;
//                            oes = 0;
//                            oess = 0;
//                        }
//                        if (ss == 2)
//                        {
//                            if (my_pole[str_k + 1][stlb_k] == 4)
//                            {
//                                oe = 1;
//                                my_pole[str_k + 1][stlb_k] = 7;
//                                if (my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k - 1][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                      if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ранен\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k + 2][stlb_k] == 4)
//                                {
//                                    oe = 2;
//                                    my_pole[str_k + 2][stlb_k] = 7;
//                                    if (my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k - 1][stlb_k] != 4 && my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Убит!\n");
//                                          if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ранен\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k + 3][stlb_k] == 4)
//                                {
//                                    my_pole[str_k + 3][stlb_k] = 7;
//                                    if (my_pole[str_k - 1][stlb_k] != 4 && my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k - 3][stlb_k] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Убит!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ранен\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                    тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k + 1][stlb_k] != 4 && my_pole[str_k + 1][stlb_k] != 7)
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k + 1, stlb_k);
//                                flag_k = 1;
//                                if (my_pole[str_k + 1][stlb_k] == 0)
//                                    my_pole[str_k + 1][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 7 && oe >= 1)
//                            {
//                                if (my_pole[str_k + 2][stlb_k] == 0)
//                                {
//                                    printf("Мимо!\n");
//                                    printf("%d %d\n", str_k + 2, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k + 2][stlb_k] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k + 2][stlb_k] == 0)
//                                    my_pole[str_k + 2][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k + 3][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 7 && oe >= 2)
//                            {
//                                if (my_pole[str_k + 3][stlb_k] == 0)
//                                {
//                                    printf("Мимо!\n");
//                                    printf("%d %d\n", str_k + 3, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k + 3][stlb_k] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k + 3][stlb_k] == 0)
//                                    my_pole[str_k + 3][stlb_k] = 6;
//                            }
//                        }
//                        if (ss == 3)
//                        {
//                            if (my_pole[str_k][stlb_k + 1] == 4)
//                            {
//                                oes = 1;
//                                my_pole[str_k][stlb_k + 1] = 7;
//                                if (my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k - 1] != 4 && my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k][stlb_k + 3] != 4)
//                                {
//                                    count_rob++;
//                                    printf("Убит!\n");
//                                     if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ранен\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k][stlb_k + 2] == 4)
//                                {
//                                    oes = 2;
//                                    my_pole[str_k][stlb_k + 2] = 7;
//                                    if (my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k - 1] != 4 && my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k + 3] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Убит!\n");
//                                          if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ранен\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k][stlb_k + 3] == 4)
//                                {
//                                    my_pole[str_k][stlb_k + 3] = 7;
//                                    if (my_pole[str_k][stlb_k - 1] != 4 && my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k - 3] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Убит!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ранен\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                    тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k][stlb_k + 1] != 4 && my_pole[str_k][stlb_k + 1] != 7)
//                            {
//                                printf("Мимо!\n");
//                                printf("%d %d\n", str_k, stlb_k + 1);
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 1] == 0)
//                                    my_pole[str_k][stlb_k + 1] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k][stlb_k + 2] != 7 && oes >= 1)
//                            {
//                                if (my_pole[str_k][stlb_k + 2] == 0)
//                                {
//                                    printf("Мимо!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 2);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 2] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k + 2] == 0)
//                                    my_pole[str_k][stlb_k + 2] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k + 3] != 4 && my_pole[str_k][stlb_k + 3] != 7 && oes >= 2)
//                            {
//                                if (my_pole[str_k][stlb_k + 3] == 0)
//                                {
//                                    printf("Мимо!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 3);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 3] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k + 3] == 0)
//                                    my_pole[str_k][stlb_k + 3] = 6;
//                            }
//
//                             if(count_chel==10) break;
//                             if(count_rob==10) break;
//                        }
//                    }
//                }
//                if (my_pole[str_k][stlb_k] == 0)
//                {
//                    flag_k = 1;
//                    printf("Мимо!\n");
//                    my_pole[str_k][stlb_k] = 6;
//                }
//                oe = 0; // sdelat chtob esli 10 viiti
//                oes = 0;
//                oess = 0;
//
//                if (flag_k == 0)
//                    continue;
//                printf("\n\n\n");
//                for (int i = 0; i < 10; i++)
//                {
//                    for (int j = 0; j < 10; j++)
//                    {
//                        if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4 && my_pole[i][j] != 6 && my_pole[i][j] != 7)
//                            my_pole[i][j] = 0;
//                    }
//                }
//                for (int i = 0; i < 10; i++)
//                {
//                    for (int j = 0; j < 10; j++)
//                    {
//                        printf("%d ", my_pole[i][j]);
//                    }
//                    printf("\n");
//                }
//                printf("\n\n\n");
//                for (int i = 0; i < 10; i++)
//                {
//                    for (int j = 0; j < 10; j++)
//                    {
//                        if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4 && pole[i][j] != 6 && pole[i][j] != 7)
//                            pole[i][j] = 0;
//                    }
//                }
//                for (int i = 0; i < 10; i++)
//                {
//                    for (int j = 0; j < 10; j++)
//                    {
//                        printf("%d ", pole[i][j]);
//                    }
//                    printf("\n");
//                }
//                printf("\n\n\n");
//                if (flag_k == 1)
//                    break;
//                
//                 if(count_rob==10) break;
//            }
//        }
//    }
//    *count = count_chel;
//    *count_b = count_rob;
//}
//
//void game_chel_komp_fif(int my_pole[15][15], int pole[15][15], int *count, int *count_b)
//{
//    int count_chel = 0;
//    int count_rob = 0;
//
//    for (int i = 0; i < 10000 && count_chel < 11 && count_rob < 11; i++)
//    {
//        if (count_chel == 11)
//            break;
//        for (int j = 0; i < 1000; j++)
//        {
//            if (count_chel == 11)
//                break;
//            int str;
//            int stlb;
//            char sim1;
//            int sim2;
//            int flag = 0;
//            printf("Hod:\n");
//            scanf(" %c%d", &sim1, &sim2);
//            stlb = trans_fif(sim1);
//            str = sim2 - 1;
//            if (str <= 14 && stlb <= 14 && str >= 0 && stlb >= 0 && pole[str][stlb] != 7 && pole[str][stlb] != 6)
//            {
//                flag = 2;
//                if (pole[str][stlb] == 1)
//                {
//                    printf("Ubit!\n");
//                    count_chel++;
//                    pole[str][stlb] = 7;
//                     if(count_chel==10) break;
//                }
//                if (pole[str][stlb] == 2)
//                {
//                    pole[str][stlb] = 7;
//                    if (pole[str][stlb - 1] != 2 && pole[str][stlb + 1] != 2 && pole[str - 1][stlb] != 2 && pole[str + 1][stlb] != 2)
//                    {
//                        count_chel++;
//                        printf("Ubit!\n");
//                         if(count_chel==10) break;
//                    }
//                    else
//                        printf("Ranen!\n");
//                }
//                if (pole[str][stlb] == 3)
//                {
//                    pole[str][stlb] = 7;
//                    if (pole[str][stlb - 1] != 3 && pole[str][stlb + 1] != 3 && pole[str - 1][stlb] != 3 && pole[str + 1][stlb] != 3)
//                    {
//                        if (pole[str][stlb - 1] == 7)
//                        {
//                            if (pole[str][stlb - 2] == 7)
//                            {
//                                count_chel++;
//                                printf("Ubit!\n");
//                                  if(count_chel==10) break;
//                            }
//                            if (pole[str][stlb - 2] == 3)
//                            {
//                                printf("Ranen!\n");
//                            }
//                        }
//                        if (pole[str][stlb + 1] == 7)
//                        {
//                            if (pole[str][stlb + 2] == 7)
//                            {
//                                count_chel++;
//                                printf("Ubit!\n");
//                                 if(count_chel==10) break;
//                            }
//                            if (pole[str][stlb + 2] == 3)
//                            {
//                                printf("Ranen!\n");
//                            }
//                        }
//                        if (pole[str - 1][stlb] == 7)
//                        {
//                            if (pole[str - 2][stlb] == 7)
//                            {
//                                count_chel++;
//                                printf("Ubit!\n");
//                                 if(count_chel==10) break;
//                            }
//                            if (pole[str - 2][stlb] == 3)
//                            {
//                                printf("Ranen!\n");
//                            }
//                        }
//                        if (pole[str + 1][stlb] == 7)
//                        {
//                            if (pole[str + 2][stlb] == 7)
//                            {
//                                count_chel++;
//                                printf("Ubit!\n");
//                                 if(count_chel==10) break;
//                            }
//                            if (pole[str + 2][stlb] == 3)
//                            {
//                                printf("Ranen!\n");
//                            }
//                        }
//                    }
//                    else
//                        printf("Ranen!\n");
//                }
//                if (pole[str][stlb] == 4)
//                {
//                    pole[str][stlb] = 7;
//                    if (pole[str][stlb - 1] != 4 && pole[str][stlb - 2] != 4 && pole[str][stlb - 3] != 4 && pole[str][stlb + 1] != 4 && pole[str][stlb + 2] != 4 && pole[str][stlb + 3] != 4 && pole[str - 2][stlb] != 4 && pole[str - 1][stlb] != 4 && pole[str - 3][stlb] != 4 && pole[str + 2][stlb] != 4 && pole[str + 3][stlb] != 4 && pole[str + 1][stlb] != 4)
//                    {
//                        count_chel++;
//                        printf("Ubit!\n");
//                         if(count_chel==10) break;
//                    }
//                    else
//                        printf("Ranen!\n");
//                }
//                if (pole[str][stlb] == 5)
//                {
//                    pole[str][stlb] = 7;
//                    if (pole[str][stlb - 1] != 5 && pole[str][stlb - 2] != 5 && pole[str][stlb - 3] != 5 && pole[str][stlb - 4] != 5 && pole[str][stlb + 1] != 5 && pole[str][stlb + 2] != 5 && pole[str][stlb + 3] != 5 && pole[str][stlb + 4] != 5 && pole[str - 2][stlb] != 5 && pole[str - 1][stlb] != 5 && pole[str - 3][stlb] != 5 && pole[str - 4][stlb] != 5 && pole[str + 2][stlb] != 5 && pole[str + 3][stlb] != 5 && pole[str + 1][stlb] != 5 && pole[str + 4][stlb] != 5)
//                    {
//                        count_chel++;
//                        printf("Ubit!\n");
//                         if(count_chel==10) break;
//                    }
//                    else
//                        printf("Ranen!\n");
//                }
//                if (pole[str][stlb] == 0)
//                {
//                    flag = 1;
//                    printf("Mimo!\n");
//                    pole[str][stlb] = 6;
//                }
//            }
//            if (flag == 0)
//                continue;
//            if (flag == 2)
//                continue;
//
//            printf("\n\n\n");
//            for (int i = 0; i < 15; i++)
//            {
//                for (int j = 0; j < 15; j++)
//                {
//                    if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4 && my_pole[i][j] != 6 && my_pole[i][j] != 7 && my_pole[i][j] != 5)
//                        my_pole[i][j] = 0;
//                }
//            }
//            for (int i = 0; i < 15; i++)
//            {
//                for (int j = 0; j < 15; j++)
//                {
//                    printf("%d ", my_pole[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\n\n\n");
//            for (int i = 0; i < 15; i++)
//            {
//                for (int j = 0; j < 15; j++)
//                {
//                    if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4 && pole[i][j] != 6 && pole[i][j] != 7 && pole[i][j] != 5)
//                        pole[i][j] = 0;
//                }
//            }
//            for (int i = 0; i < 15; i++)
//            {
//                for (int j = 0; j < 15; j++)
//                {
//                    printf("%d ", pole[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\n\n\n");
//            if (flag == 1)
//                break;
//        }
//        for (int j = 0; j < 10000; j++)
//        {
//            if (count_rob == 11)
//                break;
//            int ll;
//            int kk;
//            int ss;
//            int flag_k = 0;
//            printf("Hod komp!\n");
//            int str_k, stlb_k;
//            str_k = rand() % 15;
//            stlb_k = rand() % 15;
//            if (str_k <= 14 && stlb_k <= 14 && str_k >= 0 && stlb_k >= 0 && my_pole[str_k][stlb_k] != 7 && my_pole[str_k][stlb_k] != 6)
//            {
//                if (my_pole[str_k][stlb_k] == 1)
//                {
//                    printf("Ubit!\n");
//                    printf("%d %d\n", str_k, stlb_k);
//                    count_rob++;
//
//                    my_pole[str_k][stlb_k] = 7;
//                     if(count_rob==10) break;
//                }
//                if (my_pole[str_k][stlb_k] == 2)
//                {
//                    my_pole[str_k][stlb_k] = 7;
//                    if (my_pole[str_k][stlb_k - 1] != 2 && my_pole[str_k][stlb_k + 1] != 2 && my_pole[str_k - 1][stlb_k] != 2 && my_pole[str_k + 1][stlb_k] != 2)
//                    {
//                        count_rob++;
//                        printf("Ubit!\n");
//
//                        printf("%d %d\n", str_k, stlb_k);
//                         if(count_rob==10) break;
//                    }
//                    else
//                    {
//                        printf("Ranen!\n");
//                        printf("%d %d\n", str_k, stlb_k);
//                        for (int h = 0; h < 1000; h++)
//                        {
//                            ll = rand() % 4;
//                            if (ll == 0 && str_k - 1 >= 0 && my_pole[str_k - 1][stlb_k] != 6)
//                                break;
//                            if (ll == 1 && stlb_k - 1 >= 0 && my_pole[str_k][stlb_k - 1] != 6)
//                                break;
//                            if (ll == 2 && str_k + 1 <= 14 && my_pole[str_k + 1][stlb_k] != 6)
//                                break;
//                            if (ll == 3 && stlb_k + 1 <= 14 && my_pole[str_k][stlb_k + 1] != 6)
//                                break;
//                        }
//
//                        if (ll == 0)
//                        {
//                             test
//                            if (my_pole[str_k - 1][stlb_k] == 2)
//                            {
//                                my_pole[str_k - 1][stlb_k] = 7;
//                                count_rob++;
//                                printf("Ubit!\n");
//                                printf("%d %d\n", str_k - 1, stlb_k);
//                                 if(count_rob==10) break;
//                            }
//                            else
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k - 1, stlb_k);
//                                flag_k = 1;
//                                my_pole[str_k - 1][stlb_k] = 6;
//                            }
//                        }
//                        if (ll == 1)
//                        {
//                            if (my_pole[str_k][stlb_k - 1] == 2)
//                            {
//                                my_pole[str_k][stlb_k - 1] = 7;
//                                count_rob++;
//                                printf("Ubit!\n");
//                                printf("%d %d\n", str_k, stlb_k - 1);
//                                 if(count_rob==10) break;
//                            }
//
//                            else
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k, stlb_k - 1);
//                                flag_k = 1;
//                                my_pole[str_k][stlb_k - 1] = 6;
//                            }
//                        }
//                        if (ll == 3)
//                        {
//                            if (my_pole[str_k][stlb_k + 1] == 2)
//                            {
//                                my_pole[str_k][stlb_k + 1] = 7;
//                                count_rob++;
//                                printf("Ubit!\n");
//                                printf("%d %d\n", str_k, stlb_k + 1);
//                                 if(count_rob==10) break;
//                            }
//
//                            else
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k, stlb_k + 1);
//                                flag_k = 1;
//                                my_pole[str_k][stlb_k + 1] = 6;
//                            }
//                        }
//                        if (ll == 2)
//                        {
//                            if (my_pole[str_k + 1][stlb_k] == 2)
//                            {
//                                my_pole[str_k + 1][stlb_k] = 7;
//                                count_rob++;
//                                printf("Ubit!\n");
//                                printf("%d %d\n", str_k + 1, stlb_k);
//                                 if(count_rob==10) break;
//                            }
//                            else
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k + 1, stlb_k);
//                                flag_k = 1;
//                                my_pole[str_k + 1][stlb_k] = 6;
//                            }
//                        }
//                    }
//                }
//                if (my_pole[str_k][stlb_k] == 3)
//                {
//                    my_pole[str_k][stlb_k] = 7;
//
//                    if (my_pole[str_k][stlb_k - 1] != 3 && my_pole[str_k][stlb_k + 1] != 3 && my_pole[str_k - 1][stlb_k] != 3 && my_pole[str_k + 1][stlb_k] != 3)
//                    {
//
//                        if (my_pole[str_k][stlb_k - 1] == 7 && my_pole[str_k][stlb_k - 2] == 7)
//                        {
//                            count_rob++;
//                            printf("Ubit!\n");
//                             if(count_rob==10) break;
//                        }
//                        if (my_pole[str_k][stlb_k - 1] == 7 && my_pole[str_k][stlb_k - 2] == 3)
//                        {
//                            my_pole[str_k][stlb_k - 2] = 7;
//                            count_rob++;
//                            printf("Ubit!\n");
//                             if(count_rob==10) break;
//                        }
//
//                        if (my_pole[str_k][stlb_k + 1] == 7 && my_pole[str_k][stlb_k + 2] == 7)
//                        {
//                            count_rob++;
//                            printf("Ubit!\n");
//                             if(count_rob==10) break;
//                        }
//                        if (my_pole[str_k][stlb_k + 1] == 7 && my_pole[str_k][stlb_k + 2] == 3)
//                        {
//                            my_pole[str_k][stlb_k + 2] = 7;
//                            count_rob++;
//                            printf("Ubit!\n");
//                             if(count_rob==10) break;
//                        }
//
//                        if (my_pole[str_k - 1][stlb_k] == 7 && my_pole[str_k - 2][stlb_k] == 7)
//                        {
//                            count_rob++;
//                            printf("Ubit!\n");
//                             if(count_rob==10) break;
//                        }
//                        if (my_pole[str_k - 1][stlb_k] == 7 && my_pole[str_k - 2][stlb_k] == 3)
//                        {
//                            my_pole[str_k - 2][stlb_k] = 7;
//                            count_rob++;
//                            printf("Ubit!\n");
//                             if(count_rob==10) break;
//                        }
//
//                        if (my_pole[str_k + 1][stlb_k] == 7 && my_pole[str_k + 2][stlb_k] == 7)
//                        {
//                            count_rob++;
//                            printf("Ubit!\n");
//                             if(count_rob==10) break;
//                        }
//                        if (my_pole[str_k + 1][stlb_k] == 7 && my_pole[str_k + 2][stlb_k] == 3)
//                        {
//                            my_pole[str_k + 2][stlb_k] = 7;
//                            count_rob++;
//                            printf("Ubit!\n");
//                             if(count_rob==10) break;
//                        }
//                    }
//                    else
//                    {
//                        printf("Ranen!\n");
//                        printf("%d %d\n", str_k, stlb_k);
//
//                        for (int h = 0; h < 1000; h++)
//                        {
//                            kk = rand() % 4;
//                            if (kk == 0 && str_k - 1 >= 0 && my_pole[str_k - 1][stlb_k] != 6 && my_pole[str_k - 1][stlb_k] != 7)
//                                break;
//                            if (kk == 1 && stlb_k - 1 >= 0 && my_pole[str_k][stlb_k - 1] != 6 && my_pole[str_k][stlb_k - 1] != 7)
//                                break;
//                            if (kk == 2 && str_k + 1 <= 14 && my_pole[str_k + 1][stlb_k] != 6 && my_pole[str_k + 1][stlb_k] != 7)
//                                break;
//                            if (kk == 3 && stlb_k + 1 <= 14 && my_pole[str_k][stlb_k + 1] != 6 && my_pole[str_k][stlb_k + 1] != 7)
//                                break;
//                        }
//                        if (kk == 0)
//                        {
//                            if (my_pole[str_k - 1][stlb_k] == 3)
//                            {
//                                my_pole[str_k - 1][stlb_k] = 7;
//                                if (my_pole[str_k - 2][stlb_k] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                      if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k + 1][stlb_k] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k + 1][stlb_k] == 3)
//                                {
//                                    printf("Ranen!\n");
//                                    printf("%d %d\n", str_k + 1, stlb_k);
//                                    my_pole[str_k + 1][stlb_k] = 7;
//                                    printf("Ubit!\n");
//
//                                    count_rob++;
//                                    printf("%d %d\n", str_k + 1, stlb_k);
//                                       if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k - 2][stlb_k] == 3)
//                                {
//                                    printf("Ranen!\n");
//                                    printf("%d %d\n", str_k - 2, stlb_k);
//                                    my_pole[str_k - 2][stlb_k] = 7;
//                                    printf("Ubit!\n");
//
//                                    count_rob++;
//                                    printf("%d %d\n", str_k - 2, stlb_k);
//                                     if(count_rob==10) break;
//                                }
//                            }
//                            else
//                            {
//                                printf("Mimo!\n");
//                                flag_k = 1;
//
//                                if (my_pole[str_k - 1][stlb_k] == 0)
//                                    my_pole[str_k - 1][stlb_k] = 6;
//                            }
//                        }
//                        if (kk == 1)
//                        {
//                            if (my_pole[str_k][stlb_k - 1] == 3)
//                            {
//                                my_pole[str_k][stlb_k - 1] = 7;
//                                if (my_pole[str_k][stlb_k - 2] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                      if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k][stlb_k + 1] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                       if(count_rob==10) break;
//                                }
//
//                                if (my_pole[str_k][stlb_k + 1] == 3)
//                                {
//                                    printf("Ranen!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 1);
//                                    my_pole[str_k][stlb_k + 1] = 7;
//                                    printf("Ubit!\n");
//                                    count_rob++;
//                                    printf("%d %d\n", str_k, stlb_k + 1);
//                                      if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k][stlb_k - 2] == 3)
//                                {
//                                    printf("Ranen!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 2);
//                                    my_pole[str_k][stlb_k - 2] = 7;
//                                    printf("Ubit!\n");
//                                    count_rob++;
//                                    printf("%d %d\n", str_k, stlb_k - 2);
//                                      if(count_rob==10) break;
//                                }
//                            }
//                            else
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k, stlb_k - 1);
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 1] == 0)
//                                    my_pole[str_k][stlb_k - 1] = 6;
//                            }
//                        }
//                        if (kk == 2)
//                        {
//                            if (my_pole[str_k + 1][stlb_k] == 3)
//                            {
//                                my_pole[str_k + 1][stlb_k] = 7;
//                                if (my_pole[str_k + 2][stlb_k] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                      if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k - 1][stlb_k] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                      if(count_rob==10) break;
//                                }
//
//                                if (my_pole[str_k - 1][stlb_k] == 3)
//                                {
//                                    printf("Ranen!\n");
//                                    printf("%d %d\n", str_k - 1, stlb_k);
//                                    my_pole[str_k - 1][stlb_k] = 7;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                    count_rob++;
//                                    printf("%d %d\n", str_k - 1, stlb_k);
//                                }
//                                if (my_pole[str_k + 2][stlb_k] == 3)
//                                {
//                                    printf("Ranen!\n");
//                                    printf("%d %d\n", str_k + 2, stlb_k);
//                                    my_pole[str_k + 2][stlb_k] = 7;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                    count_rob++;
//                                    printf("%d %d\n", str_k + 2, stlb_k);
//                                }
//                            }
//                            else
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k + 1, stlb_k);
//                                flag_k = 1;
//                                if (my_pole[str_k + 1][stlb_k] == 0)
//                                    my_pole[str_k + 1][stlb_k] = 6;
//                            }
//                        }
//                        if (kk == 3)
//                        {
//
//                            if (my_pole[str_k][stlb_k + 1] == 3)
//                            {
//                                my_pole[str_k][stlb_k + 1] = 7;
//                                if (my_pole[str_k][stlb_k + 2] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k][stlb_k - 1] == 7)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                }
//
//                                if (my_pole[str_k][stlb_k - 1] == 3)
//                                {
//                                    printf("Ranen!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 1);
//                                    my_pole[str_k][stlb_k - 1] = 7;
//                                    printf("Ubit!\n");
//                                    count_rob++;
//                                    printf("%d %d\n", str_k, stlb_k - 1);
//                                      if(count_rob==10) break;
//                                }
//                                if (my_pole[str_k][stlb_k + 2] == 3)
//                                {
//                                    printf("Ranen!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 2);
//                                    my_pole[str_k][stlb_k + 2] = 7;
//                                    printf("Ubit!\n");
//                                    count_rob++;
//                                    printf("%d %d\n", str_k, stlb_k + 2);
//                                      if(count_rob==10) break;
//                                }
//
//                            } // posle pervogo ranen ne dva, TROIKI I DVOIKI STRELIAUT POVTORNO KUDA USHE STRLIALI
//
//                            else
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k, stlb_k + 1);
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 1] == 0)
//                                    my_pole[str_k][stlb_k + 1] = 6;
//                            }
//                        }
//                    }
//                }
//                int oe = 0;
//                int oes = 0;
//                int oess = 0;
//
//                if (my_pole[str_k][stlb_k] == 4)
//                {
//                    my_pole[str_k][stlb_k] = 7;
//                    if (my_pole[str_k][stlb_k - 1] != 4 && my_pole[str_k][stlb_k + 1] != 4 && my_pole[str_k - 1][stlb_k] != 4 && my_pole[str_k + 1][stlb_k] != 4 && my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k + 3] != 4 && my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                    {
//                        count_rob++;
//                        printf("Ubit!\n");
//                        printf("%d %d\n", str_k, stlb_k);
//                         if(count_rob==10) break;
//                    }
//                    else
//                    {
//                        printf("Ranen!\n");
//                        printf("%d %d\n", str_k, stlb_k);
//                        for (int h = 0; h < 1000; h++)
//                        {
//                            ss = rand() % 4;
//                            if (ss == 0 && str_k - 1 >= 0 && my_pole[str_k - 1][stlb_k] != 6 && my_pole[str_k - 1][stlb_k] != 7)
//                                break;
//                            if (ss == 1 && stlb_k - 1 >= 0 && my_pole[str_k][stlb_k - 1] != 6 && my_pole[str_k][stlb_k - 1] != 7)
//                                break;
//                            if (ss == 2 && str_k + 1 <= 14 && my_pole[str_k + 1][stlb_k] != 6 && my_pole[str_k + 1][stlb_k] != 7)
//                                break;
//                            if (ss == 3 && stlb_k + 1 <= 14 && my_pole[str_k][stlb_k + 1] != 6 && my_pole[str_k][stlb_k + 1] != 7)
//                                break;
//                        }
//                        if (ss == 0)
//                        {
//                            if (my_pole[str_k - 1][stlb_k] == 4)
//                            {
//                                oe = 1;
//                                my_pole[str_k - 1][stlb_k] = 7;
//                                if (my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k + 1][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ranen\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k - 2][stlb_k] == 4)
//                                {
//                                    oe = 2;
//                                    my_pole[str_k - 2][stlb_k] = 7;
//                                    if (my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k + 1][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                           if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k - 3][stlb_k] == 4)
//                                {
//                                    my_pole[str_k - 3][stlb_k] = 7;
//                                    if (my_pole[str_k + 1][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                 тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k - 1][stlb_k] != 4 && my_pole[str_k - 1][stlb_k] != 7)
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k - 1, stlb_k);
//                                flag_k = 1;
//                                if (my_pole[str_k - 1][stlb_k] == 0)
//                                    my_pole[str_k - 1][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k - 2][stlb_k] != 7 && oe >= 1)
//                            {
//                                if (my_pole[str_k - 2][stlb_k] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k - 2, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k - 2][stlb_k] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k - 2][stlb_k] == 0)
//                                    my_pole[str_k - 2][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k - 3][stlb_k] != 7 && oe >= 2)
//                            {
//                                if (my_pole[str_k - 3][stlb_k] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k - 3, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k - 3][stlb_k] == 6)
//                                    flag_k = 0;
//
//                                if (my_pole[str_k - 3][stlb_k] == 0)
//                                    my_pole[str_k - 3][stlb_k] = 6;
//                            }
//                        }
//                        if (ss == 1)
//                        {
//                            if (my_pole[str_k][stlb_k - 1] == 4)
//                            {
//                                oes = 1;
//                                my_pole[str_k][stlb_k - 1] = 7;
//                                if (my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k + 1] != 4 && my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k][stlb_k + 3] != 4)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ranen\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k][stlb_k - 2] == 4)
//                                {
//                                    oes = 2;
//                                    my_pole[str_k][stlb_k - 2] = 7;
//                                    if (my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k + 1] != 4 && my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k][stlb_k + 3] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                            if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k][stlb_k - 3] == 4)
//                                {
//                                    my_pole[str_k][stlb_k - 3] = 7;
//                                    if (my_pole[str_k][stlb_k + 1] != 4 && my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k][stlb_k + 3] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                           if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                    тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k][stlb_k - 1] != 4 && my_pole[str_k][stlb_k - 1] != 7)
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k, stlb_k - 1);
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 1] == 0)
//                                    my_pole[str_k][stlb_k - 1] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k - 2] != 7 && oes >= 1)
//                            {
//                                if (my_pole[str_k][stlb_k - 2] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 2);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 2] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k - 2] == 0)
//                                    my_pole[str_k][stlb_k - 2] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k - 3] != 7 && oes >= 2)
//                            {
//                                if (my_pole[str_k][stlb_k - 3] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 3);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 3] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k - 3] == 0)
//                                    my_pole[str_k][stlb_k - 3] = 6;
//                            }
//
//                            oe = 0;
//                            oes = 0;
//                            oess = 0;
//                        }
//                        if (ss == 2)
//                        {
//                            if (my_pole[str_k + 1][stlb_k] == 4)
//                            {
//                                oe = 1;
//                                my_pole[str_k + 1][stlb_k] = 7;
//                                if (my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k - 1][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                      if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ranen\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k + 2][stlb_k] == 4)
//                                {
//                                    oe = 2;
//                                    my_pole[str_k + 2][stlb_k] = 7;
//                                    if (my_pole[str_k - 3][stlb_k] != 4 && my_pole[str_k - 1][stlb_k] != 4 && my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                          if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k + 3][stlb_k] == 4)
//                                {
//                                    my_pole[str_k + 3][stlb_k] = 7;
//                                    if (my_pole[str_k - 1][stlb_k] != 4 && my_pole[str_k - 2][stlb_k] != 4 && my_pole[str_k - 3][stlb_k] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                    тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k + 1][stlb_k] != 4 && my_pole[str_k + 1][stlb_k] != 7)
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k + 1, stlb_k);
//                                flag_k = 1;
//                                if (my_pole[str_k + 1][stlb_k] == 0)
//                                    my_pole[str_k + 1][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k + 2][stlb_k] != 4 && my_pole[str_k + 2][stlb_k] != 7 && oe >= 1)
//                            {
//                                if (my_pole[str_k + 2][stlb_k] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k + 2, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k + 2][stlb_k] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k + 2][stlb_k] == 0)
//                                    my_pole[str_k + 2][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k + 3][stlb_k] != 4 && my_pole[str_k + 3][stlb_k] != 7 && oe >= 2)
//                            {
//                                if (my_pole[str_k + 3][stlb_k] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k + 3, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k + 3][stlb_k] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k + 3][stlb_k] == 0)
//                                    my_pole[str_k + 3][stlb_k] = 6;
//                            }
//                        }
//                        if (ss == 3)
//                        {
//                            if (my_pole[str_k][stlb_k + 1] == 4)
//                            {
//                                oes = 1;
//                                my_pole[str_k][stlb_k + 1] = 7;
//                                if (my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k - 1] != 4 && my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k][stlb_k + 3] != 4)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ranen\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k][stlb_k + 2] == 4)
//                                {
//                                    oes = 2;
//                                    my_pole[str_k][stlb_k + 2] = 7;
//                                    if (my_pole[str_k][stlb_k - 3] != 4 && my_pole[str_k][stlb_k - 1] != 4 && my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k + 3] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                          if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k][stlb_k + 3] == 4)
//                                {
//                                    my_pole[str_k][stlb_k + 3] = 7;
//                                    if (my_pole[str_k][stlb_k - 1] != 4 && my_pole[str_k][stlb_k - 2] != 4 && my_pole[str_k][stlb_k - 3] != 4)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                    тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k][stlb_k + 1] != 4 && my_pole[str_k][stlb_k + 1] != 7)
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k, stlb_k + 1);
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 1] == 0)
//                                    my_pole[str_k][stlb_k + 1] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k + 2] != 4 && my_pole[str_k][stlb_k + 2] != 7 && oes >= 1)
//                            {
//                                if (my_pole[str_k][stlb_k + 2] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 2);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 2] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k + 2] == 0)
//                                    my_pole[str_k][stlb_k + 2] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k + 3] != 4 && my_pole[str_k][stlb_k + 3] != 7 && oes >= 2)
//                            {
//                                if (my_pole[str_k][stlb_k + 3] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 3);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 3] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k + 3] == 0)
//                                    my_pole[str_k][stlb_k + 3] = 6;
//                            }
//
//                             if(count_chel==10) break;
//                             if(count_rob==10) break;
//                        }
//                    }
//                }
//                oe = 0;
//                oes = 0;
//                oess = 0;
//                if (my_pole[str_k][stlb_k] == 5)
//                {
//                    my_pole[str_k][stlb_k] = 7;
//                    if (my_pole[str_k][stlb_k - 1] != 5 && my_pole[str_k][stlb_k + 1] != 5 && my_pole[str_k - 1][stlb_k] != 5 && my_pole[str_k + 1][stlb_k] != 5 && my_pole[str_k][stlb_k - 2] != 5 && my_pole[str_k][stlb_k + 2] != 5 && my_pole[str_k - 2][stlb_k] != 5 && my_pole[str_k + 2][stlb_k] != 5 && my_pole[str_k][stlb_k - 3] != 5 && my_pole[str_k][stlb_k + 3] != 5 && my_pole[str_k - 3][stlb_k] != 5 && my_pole[str_k + 3][stlb_k] != 5 && my_pole[str_k][stlb_k - 4] != 5 && my_pole[str_k][stlb_k + 4] != 5 && my_pole[str_k - 4][stlb_k] != 5 && my_pole[str_k + 4][stlb_k] != 5)
//                    {
//                        count_rob++;
//                        printf("Ubit!\n");
//                        printf("%d %d\n", str_k, stlb_k);
//                         if(count_rob==10) break;
//                    }
//                    else
//                    {
//                        printf("Ranen!\n");
//                        printf("%d %d\n", str_k, stlb_k);
//                        for (int h = 0; h < 1000; h++)
//                        {
//                            ss = rand() % 4;
//                            if (ss == 0 && str_k - 1 >= 0 && my_pole[str_k - 1][stlb_k] != 6 && my_pole[str_k - 1][stlb_k] != 7)
//                                break;
//                            if (ss == 1 && stlb_k - 1 >= 0 && my_pole[str_k][stlb_k - 1] != 6 && my_pole[str_k][stlb_k - 1] != 7)
//                                break;
//                            if (ss == 2 && str_k + 1 <= 14 && my_pole[str_k + 1][stlb_k] != 6 && my_pole[str_k + 1][stlb_k] != 7)
//                                break;
//                            if (ss == 3 && stlb_k + 1 <= 14 && my_pole[str_k][stlb_k + 1] != 6 && my_pole[str_k][stlb_k + 1] != 7)
//                                break;
//                        }
//                        if (ss == 0)
//                        {
//                            if (my_pole[str_k - 1][stlb_k] == 5)
//                            {
//                                oe = 1;
//                                my_pole[str_k - 1][stlb_k] = 7;
//                                if (my_pole[str_k - 2][stlb_k] != 5 && my_pole[str_k - 3][stlb_k] != 5 && my_pole[str_k - 4][stlb_k] != 5 && my_pole[str_k + 1][stlb_k] != 5 && my_pole[str_k + 2][stlb_k] != 5 && my_pole[str_k + 3][stlb_k] != 5 && my_pole[str_k + 4][stlb_k] != 5)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ranen\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k - 2][stlb_k] == 5)
//                                {
//                                    oe = 2;
//                                    my_pole[str_k - 2][stlb_k] = 7;
//                                    if (my_pole[str_k - 3][stlb_k] != 5 && my_pole[str_k - 4][stlb_k] != 5 && my_pole[str_k + 1][stlb_k] != 5 && my_pole[str_k + 2][stlb_k] != 5 && my_pole[str_k + 3][stlb_k] != 5 && my_pole[str_k + 4][stlb_k] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                           if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k - 3][stlb_k] == 5)
//                                {
//                                    oe = 3;
//                                    my_pole[str_k - 3][stlb_k] = 7;
//                                    if (my_pole[str_k - 4][stlb_k] != 5 && my_pole[str_k + 1][stlb_k] != 5 && my_pole[str_k + 2][stlb_k] != 5 && my_pole[str_k + 3][stlb_k] != 5 && my_pole[str_k + 4][stlb_k] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k - 4][stlb_k] == 5)
//                                {
//                                    my_pole[str_k - 4][stlb_k] = 7;
//                                    if (my_pole[str_k + 1][stlb_k] != 5 && my_pole[str_k + 2][stlb_k] != 5 && my_pole[str_k + 3][stlb_k] != 5 && my_pole[str_k + 4][stlb_k] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                 тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k - 1][stlb_k] != 5 && my_pole[str_k - 1][stlb_k] != 7)
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k - 1, stlb_k);
//                                flag_k = 1;
//                                if (my_pole[str_k - 1][stlb_k] == 0)
//                                    my_pole[str_k - 1][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k - 2][stlb_k] != 5 && my_pole[str_k - 2][stlb_k] != 7 && oe >= 1)
//                            {
//                                if (my_pole[str_k - 2][stlb_k] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k - 2, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k - 2][stlb_k] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k - 2][stlb_k] == 0)
//                                    my_pole[str_k - 2][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k - 3][stlb_k] != 5 && my_pole[str_k - 3][stlb_k] != 7 && oe >= 2)
//                            {
//                                if (my_pole[str_k - 3][stlb_k] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k - 3, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k - 3][stlb_k] == 6)
//                                    flag_k = 0;
//
//                                if (my_pole[str_k - 3][stlb_k] == 0)
//                                    my_pole[str_k - 3][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k - 4][stlb_k] != 5 && my_pole[str_k - 4][stlb_k] != 7 && oe >= 3)
//                            {
//                                if (my_pole[str_k - 4][stlb_k] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k - 4, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k - 4][stlb_k] == 6)
//                                    flag_k = 0;
//
//                                if (my_pole[str_k - 4][stlb_k] == 0)
//                                    my_pole[str_k - 4][stlb_k] = 6;
//                            }
//                        } // tut ostanovilsia!!!!
//                        if (ss == 1)
//                        {
//                            if (my_pole[str_k][stlb_k - 1] == 5)
//                            {
//                                oes = 1;
//                                my_pole[str_k][stlb_k - 1] = 7;
//                                if (my_pole[str_k][stlb_k - 2] != 5 && my_pole[str_k][stlb_k - 3] != 5 && my_pole[str_k][stlb_k - 4] != 5 && my_pole[str_k][stlb_k + 1] != 5 && my_pole[str_k][stlb_k + 2] != 5 && my_pole[str_k][stlb_k + 3] != 5 && my_pole[str_k][stlb_k + 4] != 5)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ranen\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k][stlb_k - 2] == 5)
//                                {
//                                    oes = 2;
//                                    my_pole[str_k][stlb_k - 2] = 7;
//                                    if (my_pole[str_k][stlb_k - 3] != 5 && my_pole[str_k][stlb_k - 4] != 5 && my_pole[str_k][stlb_k + 1] != 5 && my_pole[str_k][stlb_k + 2] != 5 && my_pole[str_k][stlb_k + 3] != 5 && my_pole[str_k][stlb_k + 4] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                            if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k][stlb_k - 3] == 5)
//                                {
//                                    oes = 3;
//                                    my_pole[str_k][stlb_k - 3] = 7;
//                                    if (my_pole[str_k][stlb_k - 4] != 5 && my_pole[str_k][stlb_k + 1] != 5 && my_pole[str_k][stlb_k + 2] != 5 && my_pole[str_k][stlb_k + 3] != 5 && my_pole[str_k][stlb_k + 4] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                           if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k][stlb_k - 4] == 5)
//                                {
//                                    my_pole[str_k][stlb_k - 4] = 7;
//                                    if (my_pole[str_k][stlb_k + 1] != 5 && my_pole[str_k][stlb_k + 2] != 5 && my_pole[str_k][stlb_k + 3] != 5 && my_pole[str_k][stlb_k + 4] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                           if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                    тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k][stlb_k - 1] != 5 && my_pole[str_k][stlb_k - 1] != 7)
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k, stlb_k - 1);
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 1] == 0)
//                                    my_pole[str_k][stlb_k - 1] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k - 2] != 5 && my_pole[str_k][stlb_k - 2] != 7 && oes >= 1)
//                            {
//                                if (my_pole[str_k][stlb_k - 2] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 2);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 2] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k - 2] == 0)
//                                    my_pole[str_k][stlb_k - 2] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k - 3] != 5 && my_pole[str_k][stlb_k - 3] != 7 && oes >= 2)
//                            {
//                                if (my_pole[str_k][stlb_k - 3] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 3);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 3] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k - 3] == 0)
//                                    my_pole[str_k][stlb_k - 3] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k - 4] != 5 && my_pole[str_k][stlb_k - 4] != 7 && oes >= 3)
//                            {
//                                if (my_pole[str_k][stlb_k - 4] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k, stlb_k - 4);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k - 4] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k - 4] == 0)
//                                    my_pole[str_k][stlb_k - 4] = 6;
//                            }
//
//                            oe = 0;
//                            oes = 0;
//                            oess = 0;
//                        }
//                        if (ss == 2)
//                        {
//                            if (my_pole[str_k + 1][stlb_k] == 5)
//                            {
//                                oe = 1;
//                                my_pole[str_k + 1][stlb_k] = 7;
//                                if (my_pole[str_k - 2][stlb_k] != 5 && my_pole[str_k - 3][stlb_k] != 5 && my_pole[str_k - 4][stlb_k] != 5 && my_pole[str_k - 1][stlb_k] != 5 && my_pole[str_k + 2][stlb_k] != 5 && my_pole[str_k + 3][stlb_k] != 5 && my_pole[str_k + 4][stlb_k] != 5)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                      if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ranen\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k + 2][stlb_k] == 5)
//                                {
//                                    oe = 2;
//                                    my_pole[str_k + 2][stlb_k] = 7;
//                                    if (my_pole[str_k - 2][stlb_k] != 5 && my_pole[str_k - 3][stlb_k] != 5 && my_pole[str_k - 4][stlb_k] != 5 && my_pole[str_k - 1][stlb_k] != 5 && my_pole[str_k + 3][stlb_k] != 5 && my_pole[str_k + 4][stlb_k] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                          if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k + 3][stlb_k] == 5)
//                                {
//                                    oe = 3;
//                                    my_pole[str_k + 3][stlb_k] = 7;
//                                    if (my_pole[str_k - 2][stlb_k] != 5 && my_pole[str_k - 3][stlb_k] != 5 && my_pole[str_k - 4][stlb_k] != 5 && my_pole[str_k - 1][stlb_k] != 5 && my_pole[str_k + 4][stlb_k] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k + 4][stlb_k] == 5)
//                                {
//                                    my_pole[str_k + 4][stlb_k] = 7;
//                                    if (my_pole[str_k - 2][stlb_k] != 5 && my_pole[str_k - 3][stlb_k] != 5 && my_pole[str_k - 4][stlb_k] != 5 && my_pole[str_k - 1][stlb_k] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                    тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k + 1][stlb_k] != 5 && my_pole[str_k + 1][stlb_k] != 7)
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k + 1, stlb_k);
//                                flag_k = 1;
//                                if (my_pole[str_k + 1][stlb_k] == 0)
//                                    my_pole[str_k + 1][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k + 2][stlb_k] != 5 && my_pole[str_k + 2][stlb_k] != 7 && oe >= 1)
//                            {
//                                if (my_pole[str_k + 2][stlb_k] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k + 2, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k + 2][stlb_k] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k + 2][stlb_k] == 0)
//                                    my_pole[str_k + 2][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k + 3][stlb_k] != 5 && my_pole[str_k + 3][stlb_k] != 7 && oe >= 2)
//                            {
//                                if (my_pole[str_k + 3][stlb_k] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k + 3, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k + 3][stlb_k] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k + 3][stlb_k] == 0)
//                                    my_pole[str_k + 3][stlb_k] = 6;
//                            }
//                            if (my_pole[str_k + 4][stlb_k] != 5 && my_pole[str_k + 4][stlb_k] != 7 && oe >= 3)
//                            {
//                                if (my_pole[str_k + 4][stlb_k] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k + 4, stlb_k);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k + 4][stlb_k] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k + 4][stlb_k] == 0)
//                                    my_pole[str_k + 4][stlb_k] = 6;
//                            }
//                        }
//                        if (ss == 3)
//                        {
//                            if (my_pole[str_k][stlb_k + 1] == 5)
//                            {
//                                oes = 1;
//                                my_pole[str_k][stlb_k + 1] = 7;
//                                if (my_pole[str_k][stlb_k - 2] != 5 && my_pole[str_k][stlb_k - 3] != 5 && my_pole[str_k][stlb_k - 4] != 5 && my_pole[str_k][stlb_k - 1] != 5 && my_pole[str_k][stlb_k + 2] != 5 && my_pole[str_k][stlb_k + 3] != 5 && my_pole[str_k][stlb_k + 4] != 5)
//                                {
//                                    count_rob++;
//                                    printf("Ubit!\n");
//                                     if(count_rob==10) break;
//                                }
//                                else
//                                {
//                                    printf("Ranen\n");
//                                    printf("%d %d\n", str_k, stlb_k);
//                                }
//                                if (my_pole[str_k][stlb_k + 2] == 5)
//                                {
//                                    oes = 2;
//                                    my_pole[str_k][stlb_k + 2] = 7;
//                                    if (my_pole[str_k][stlb_k - 2] != 5 && my_pole[str_k][stlb_k - 3] != 5 && my_pole[str_k][stlb_k - 4] != 5 && my_pole[str_k][stlb_k - 1] != 5 && my_pole[str_k][stlb_k + 3] != 5 && my_pole[str_k][stlb_k + 4] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                          if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k][stlb_k + 3] == 5)
//                                {
//                                    oes = 3;
//                                    my_pole[str_k][stlb_k + 3] = 7;
//                                    if (my_pole[str_k][stlb_k - 2] != 5 && my_pole[str_k][stlb_k - 3] != 5 && my_pole[str_k][stlb_k - 4] != 5 && my_pole[str_k][stlb_k - 1] != 5 && my_pole[str_k][stlb_k + 4] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//                                if (my_pole[str_k][stlb_k + 4] == 5)
//                                {
//                                    oes = 3;
//                                    my_pole[str_k][stlb_k + 4] = 7;
//                                    if (my_pole[str_k][stlb_k - 2] != 5 && my_pole[str_k][stlb_k - 3] != 5 && my_pole[str_k][stlb_k - 4] != 5 && my_pole[str_k][stlb_k - 1] != 5)
//                                    {
//                                        count_rob++;
//                                        printf("Ubit!\n");
//                                         if(count_rob==10) break;
//                                    }
//                                    else
//                                    {
//                                        printf("Ranen\n");
//                                        printf("%d %d\n", str_k, stlb_k);
//                                    }
//                                }
//
//                                    тут поработать с 4 а так контррооль иф елс
//                            }
//                            if (my_pole[str_k][stlb_k + 1] != 5 && my_pole[str_k][stlb_k + 1] != 7)
//                            {
//                                printf("Mimo!\n");
//                                printf("%d %d\n", str_k, stlb_k + 1);
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 1] == 0)
//                                    my_pole[str_k][stlb_k + 1] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k + 2] != 5 && my_pole[str_k][stlb_k + 2] != 7 && oes >= 1)
//                            {
//                                if (my_pole[str_k][stlb_k + 2] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 2);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 2] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k + 2] == 0)
//                                    my_pole[str_k][stlb_k + 2] = 6; // tut nado ispravit
//                            }
//                            if (my_pole[str_k][stlb_k + 3] != 5 && my_pole[str_k][stlb_k + 3] != 7 && oes >= 2)
//                            {
//                                if (my_pole[str_k][stlb_k + 3] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 3);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 3] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k + 3] == 0)
//                                    my_pole[str_k][stlb_k + 3] = 6;
//                            }
//                            if (my_pole[str_k][stlb_k + 4] != 5 && my_pole[str_k][stlb_k + 4] != 7 && oes >= 3)
//                            {
//                                if (my_pole[str_k][stlb_k + 4] == 0)
//                                {
//                                    printf("Mimo!\n");
//                                    printf("%d %d\n", str_k, stlb_k + 4);
//                                }
//                                flag_k = 1;
//                                if (my_pole[str_k][stlb_k + 4] == 6)
//                                    flag_k = 0;
//                                if (my_pole[str_k][stlb_k + 4] == 0)
//                                    my_pole[str_k][stlb_k + 4] = 6;
//                            }
//
//                             if(count_chel==10) break;
//                             if(count_rob==10) break;
//                        }
//                    }
//                }
//                if (my_pole[str_k][stlb_k] == 0)
//                {
//                    flag_k = 1;
//                    printf("Mimo!\n");
//                    my_pole[str_k][stlb_k] = 6;
//                }
//                oe = 0; // sdelat chtob esli 10 viiti
//                oes = 0;
//                oess = 0;
//
//                if (flag_k == 0)
//                    continue;
//                printf("\n\n\n");
//                for (int i = 0; i < 15; i++)
//                {
//                    for (int j = 0; j < 15; j++)
//                    {
//                        if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4 && my_pole[i][j] != 6 && my_pole[i][j] != 7 && my_pole[i][j] != 5)
//                            my_pole[i][j] = 0;
//                    }
//                }
//                for (int i = 0; i < 15; i++)
//                {
//                    for (int j = 0; j < 15; j++)
//                    {
//                        printf("%d ", my_pole[i][j]);
//                    }
//                    printf("\n");
//                }
//                printf("\n\n\n");
//                for (int i = 0; i < 15; i++)
//                {
//                    for (int j = 0; j < 15; j++)
//                    {
//                        if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4 && pole[i][j] != 6 && pole[i][j] != 7 && pole[i][j] != 5)
//                            pole[i][j] = 0;
//                    }
//                }
//                for (int i = 0; i < 15; i++)
//                {
//                    for (int j = 0; j < 15; j++)
//                    {
//                        printf("%d ", pole[i][j]);
//                    }
//                    printf("\n");
//                }
//                printf("\n\n\n");
//                if (flag_k == 1)
//                    break;
//                
//                 if(count_rob==10) break;
//            }
//        }
//    }
//    *count = count_chel;
//    *count_b = count_rob;
//}
//
//void strel_med_game_chel_komp_ten(int i, int *str, int *stlb){
//    switch(i){
//        case 0:
//        *str=0;
//        *stlb=0;
//        break;
//        case 1:
//        *str=0;
//        *stlb=2;
//        break;
//        case 2:
//        *str=0;
//        *stlb=4;
//        break;
//        case 3:
//        *str=2;
//        *stlb=0;
//        break;
//        case 4:
//        *str=2;
//        *stlb=2;
//        break;
//        case 5:
//        *str=2;
//        *stlb=4;
//        break;
//        case 6:
//        *str=4;
//        *stlb=0;
//        break;
//        case 7:
//        *str=4;
//        *stlb=2;
//        break;
//        case 8:
//        *str=4;
//        *stlb=4;
//        break;
//        case 9:
//        *str=5;
//        *stlb=6;
//        break;
//        case 10:
//        *str=5;
//        *stlb=8;
//        break;
//        case 11:
//        *str=7;
//        *stlb=6;
//        break;
//        case 12:
//        *str=7;
//        *stlb=8;
//        break;
//        case 13:
//        *str=9;
//        *stlb=6;
//        break;
//        case 14:
//        *str=9;
//        *stlb=8;
//        break;
//        case 15:
//        *str=5;
//        *stlb=0;
//        break;
//        case 16:
//        *str=5;
//        *stlb=2;
//        break;
//        case 17:
//        *str=5;
//        *stlb=4;
//        break;
//        case 18:
//        *str=7;
//        *stlb=0;
//        break;
//        case 19:
//        *str=7;
//        *stlb=2;
//        break;
//        case 20:
//        *str=7;
//        *stlb=4;
//        break;
//        case 21:
//        *str=9;
//        *stlb=0;
//        break;
//        case 22:
//        *str=9;
//        *stlb=2;
//        break;
//        case 23:
//        *str=9;
//        *stlb=4;
//        break;
//        case 24:
//        *str=0;
//        *stlb=6;
//        break;
//        case 25:
//        *str=0;
//        *stlb=8;
//        break;
//        case 26:
//        *str=2;
//        *stlb=6;
//        break;
//        case 27:
//        *str=2;
//        *stlb=8;
//        break;
//        case 28:
//        *str=4;
//        *stlb=6;
//        break;
//        case 29:
//        *str=4;
//        *stlb=8;
//        break;
//        case 30:
//        *str=1;
//        *stlb=1;
//        break;
//        case 31:
//        *str=1;
//        *stlb=3;
//        break;
//        case 32:
//        *str=3;
//        *stlb=1;
//        break;
//        case 33:
//        *str=3;
//        *stlb=3;
//        break;
//        case 34:
//        *str=6;
//        *stlb=5;
//        break;
//        case 35:
//        *str=6;
//        *stlb=7;
//        break;
//        case 36:
//        *str=6;
//        *stlb=9;
//        break;
//        case 37:
//        *str=8;
//        *stlb=5;
//        break;
//        case 38:
//        *str=8;
//        *stlb=7;
//        break;
//        case 39:
//        *str=8;
//        *stlb=9;
//        break;
//        case 40:
//        *str=6;
//        *stlb=1;
//        break;
//        case 41:
//        *str=6;
//        *stlb=3;
//        break;
//        case 42:
//        *str=8;
//        *stlb=1;
//        break;
//        case 43:
//        *str=8;
//        *stlb=3;
//        break;
//        case 44:
//        *str=1;
//        *stlb=5;
//        break;
//        case 45:
//        *str=1;
//        *stlb=7;
//        break;
//        case 46:
//        *str=1;
//        *stlb=9;
//        break;
//        case 47:
//        *str=3;
//        *stlb=5;
//        break;
//        case 48:
//        *str=3;
//        *stlb=7;
//        break;
//        case 49:
//        *str=3;
//        *stlb=9;
//        break;
//        case 50:
//        *str=0;
//        *stlb=1;
//        break;
//        case 51:
//        *str=0;
//        *stlb=3;
//        break;
//        case 52:
//        *str=2;
//        *stlb=1;
//        break;
//        case 53:
//        *str=2;
//        *stlb=3;
//        break;
//        case 54:
//        *str=4;
//        *stlb=1;
//        break;
//        case 55:
//        *str=4;
//        *stlb=3;
//        break;
//        case 56:
//        *str=5;
//        *stlb=5;
//        break;
//        case 57:
//        *str=5;
//        *stlb=7;
//        break;
//        case 58:
//        *str=5;
//        *stlb=9;
//        break;
//        case 59:
//        *str=7;
//        *stlb=5;
//        break;
//        case 60:
//        *str=7;
//        *stlb=7;
//        break;
//        case 61:
//        *str=7;
//        *stlb=9;
//        break;
//        case 62:
//        *str=9;
//        *stlb=5;
//        break;
//        case 63:
//        *str=9;
//        *stlb=7;
//        break;
//        case 64:
//        *str=9;
//        *stlb=9;
//        break;
//        case 65:
//        *str=5;
//        *stlb=1;
//        break;
//        case 66:
//        *str=5;
//        *stlb=3;
//        break;
//        case 67:
//        *str=7;
//        *stlb=1;
//        break;
//        case 68:
//        *str=7;
//        *stlb=3;
//        break;
//        case 69:
//        *str=9;
//        *stlb=1;
//        break;
//        case 70:
//        *str=9;
//        *stlb=3;
//        break;
//        case 71:
//        *str=0;
//        *stlb=5;
//        break;
//        case 72:
//        *str=0;
//        *stlb=7;
//        break;
//        case 73:
//        *str=0;
//        *stlb=9;
//        break;
//        case 74:
//        *str=2;
//        *stlb=5;
//        break;
//        case 75:
//        *str=2;
//        *stlb=7;
//        break;
//        case 76:
//        *str=2;
//        *stlb=9;
//        break;
//        case 77:
//        *str=4;
//        *stlb=5;
//        break;
//        case 78:
//        *str=4;
//        *stlb=7;
//        break;
//        case 79:
//        *str=4;
//        *stlb=9;
//        break;
//        case 80:
//        *str=1;
//        *stlb=0;
//        break;
//        case 81:
//        *str=1;
//        *stlb=2;
//        break;
//        case 82:
//        *str=1;
//        *stlb=4;
//        break;
//        case 83:
//        *str=3;
//        *stlb=0;
//        break;
//        case 84:
//        *str=3;
//        *stlb=2;
//        break;
//        case 85:
//        *str=3;
//        *stlb=4;
//        break;
//        case 86:
//        *str=6;
//        *stlb=6;
//        break;
//        case 87:
//        *str=6;
//        *stlb=8;
//        break;
//        case 88:
//        *str=8;
//        *stlb=6;
//        break;
//        case 89:
//        *str=8;
//        *stlb=8;
//        break;
//        case 90:
//        *str=6;
//        *stlb=0;
//        break;
//        case 91:
//        *str=6;
//        *stlb=2;
//        break;
//        case 92:
//        *str=6;
//        *stlb=4;
//        break;
//        case 93:
//        *str=8;
//        *stlb=0;
//        break;
//        case 94:
//        *str=8;
//        *stlb=2;
//        break;
//        case 95:
//        *str=8;
//        *stlb=4;
//        break;
//        case 96:
//        *str=1;
//        *stlb=6;
//        break;
//        case 97:
//        *str=1;
//        *stlb=8;
//        break;
//        case 98:
//        *str=3;
//        *stlb=6;
//        break;
//        case 99:
//        *str=3;
//        *stlb=8;
//        break;
//    }
//}
//
//void game_medi_chel_komp_ten(int my_pole[10][10], int pole[10][10], int *count, int *count_b)
//
//int main()
//{
//    setlocale(LC_ALL, "ru_RU.UTF-8");
//    POLE w;  // вводим поле
//    SLOZH s; // вводим сложность
//    int count = 0;
//    printf("Поле>> \n");
//    scanf("%d", &w);
//    if (w == 0)
//    {
//        int my_pole[10][10] = {0};
//        my_plan_ten(my_pole);
//        int pole[10][10] = {0};
//        srand(time(NULL));
//        printf("Сложность>> \n");
//        scanf("%d", &s);
//        if (s == 0)
//        {
//            easy_komp_ten(pole);
//            printf("\n\n\n");
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4)
//                        my_pole[i][j] = 0;
//                }
//            }
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    printf("%d ", my_pole[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\n\n\n");
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4)
//                        pole[i][j] = 0;
//                }
//            }
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    printf("%d ", pole[i][j]);
//                }
//                printf("\n");
//            }
//            int count = 0;
//            int count_r = 0;
//            game_chel_komp_ten(my_pole, pole, &count, &count_r);
//            if (count > count_r)
//                printf("Выиграл человек\n\n\n");
//            else
//                printf("Выиграл бот\n\n\n");
//        }
//        if (s == 1)
//        {
//            medi_komp_ten(pole);
//            printf("\n\n\n");
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4)
//                        my_pole[i][j] = 0;
//                }
//            }
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    printf("%d ", my_pole[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\n\n\n");
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4)
//                        pole[i][j] = 0;
//                }
//            }
//            for (int i = 0; i < 10; i++)
//            {
//                for (int j = 0; j < 10; j++)
//                {
//                    printf("%d ", pole[i][j]);
//                }
//                printf("\n");
//            }
//            int count = 0;
//            int count_r = 0;
//            game_medi_chel_komp_ten(my_pole, pole, &count, &count_r);
//            if (count > count_r)
//                printf("Выиграл человек\n\n\n");
//            else
//                printf("Выиграл бот\n\n\n");
//        }
//        if (s == 2)
//        {
//            hard_komp_ten(pole);
//        }
//        count = 10;
//        printf("\n\n\n");
//        for (int i = 0; i < count; i++)
//        {
//            for (int j = 0; j < count; j++)
//            {
//                if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4)
//                    my_pole[i][j] = 0;
//            }
//        }
//        for (int i = 0; i < count; i++)
//        {
//            for (int j = 0; j < count; j++)
//            {
//                printf("%d ", my_pole[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n\n\n");
//        for (int i = 0; i < count; i++)
//        {
//            for (int j = 0; j < count; j++)
//            {
//                if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4)
//                    pole[i][j] = 0;
//            }
//        }
//        for (int i = 0; i < count; i++)
//        {
//            for (int j = 0; j < count; j++)
//            {
//                printf("%d ", pole[i][j]);
//            }
//            printf("\n");
//        }
//    }
//
//
//
//
//
//    if (w == 1)
//    {
//
//        count = 15;
//        int my_pole[15][15] = {0};
//        scanf("%d", &s);
//        my_plan_fif(my_pole);
//        int pole[15][15] = {0};
//        srand(time(NULL));
//        if (s == 0)
//        {
//            easy_komp_fif(pole);
//            printf("\n\n\n");
//            for (int i = 0; i < 15; i++)
//            {
//                for (int j = 0; j < 15; j++)
//                {
//                    if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4 && my_pole[i][j] != 5)
//                        my_pole[i][j] = 0;
//                }
//            }
//            for (int i = 0; i < 15; i++)
//            {
//                for (int j = 0; j < 15; j++)
//                {
//                    printf("%d ", my_pole[i][j]);
//                }
//                printf("\n");
//            }
//            printf("\n\n\n");
//            for (int i = 0; i < 15; i++)
//            {
//                for (int j = 0; j < 15; j++)
//                {
//                    if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4 && pole[i][j] != 5)
//                        pole[i][j] = 0;
//                }
//            }
//            for (int i = 0; i < 15; i++)
//            {
//                for (int j = 0; j < 15; j++)
//                {
//                    printf("%d ", pole[i][j]);
//                }
//                printf("\n");
//            }
//            int count = 0;
//            int count_r = 0;
//            game_chel_komp_fif(my_pole, pole, &count, &count_r);
//            if (count > count_r)
//                printf("Выиграл человек\n\n\n");
//            else
//                printf("Выиграл бот\n\n\n");
//        }
//
//        if (s == 1)
//        {
//            medi_komp_fif(pole);
//        }
//        if (s == 2)
//        {
//            hard_komp_fif(pole);
//        }
//        printf("\n\n\n");
//        for (int i = 0; i < count; i++)
//        {
//            for (int j = 0; j < count; j++)
//            {
//                if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4 && my_pole[i][j] != 5)
//                    my_pole[i][j] = 0;
//            }
//        }
//        for (int i = 0; i < count; i++)
//        {
//            for (int j = 0; j < count; j++)
//            {
//                printf("%d ", my_pole[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n\n\n");
//        for (int i = 0; i < count; i++)
//        {
//            for (int j = 0; j < count; j++)
//            {
//                if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4 && pole[i][j] != 5)
//                    pole[i][j] = 0;
//            }
//        }
//        for (int i = 0; i < count; i++)
//        {
//            for (int j = 0; j < count; j++)
//            {
//                printf("%d ", pole[i][j]);
//            }
//            printf("\n");
//        }
//
//         dopisat easy pravilno ugli     TROIKI ranen
//    }
//    return 0;
//}