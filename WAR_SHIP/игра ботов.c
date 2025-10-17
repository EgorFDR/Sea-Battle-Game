#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

enum {
    hod_chel,
    hod_bot,
    chel_win,
    bot_win

};

//легкий
int easy_bot_ten(int pole_bot_1[10][10], int pole_bot_2[10][10], int* count_bot, int* count, int* radar_count, int flag_mode){
    int count_rob = count_bot[0];
    srand(time(NULL));
    for (int j = 0; j < 1000; j++)
    {
        if(flag_mode==2) Sleep(100);
        if (count_rob == 10) return bot_win;
        int ll;
        int kk;
        int ss;
        int flag_k = 0;
        printf("Ход бота!\n");
        if (flag_mode == 1 && radar_bot_ten(pole_bot_1, radar_count, count_bot)==1) return hod_chel;
        if (count_rob == 10) return bot_win;
        int str_k, stlb_k;
        str_k = rand() % 10;
        stlb_k = rand() % 10;
        if (str_k <= 9 && stlb_k <= 9 && str_k >= 0 && stlb_k >= 0 && pole_bot_1[str_k][stlb_k] != 8 && pole_bot_1[str_k][stlb_k] != 6)
        {
            if (pole_bot_1[str_k][stlb_k] == 9) {
                mina_ten(pole_bot_2, str_k, stlb_k, count, 1);
                pole_bot_1[str_k][stlb_k] = 10;
                flag_k = 1;
                if (count[0] == 10) {
                    printf("Все корабли потоплены");
                    return chel_win;
                }
            }

            if (pole_bot_1[str_k][stlb_k] == 1)
            {
                printf("Убит!\n");
                printf("%d %d\n", str_k, stlb_k);
                count_rob++;

                pole_bot_1[str_k][stlb_k] = 8;
                if (count_rob == 10) return bot_win;
            }
            if (pole_bot_1[str_k][stlb_k] == 2)
            {
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 2 && pole_bot_1[str_k][stlb_k + 1] != 2 && pole_bot_1[str_k - 1][stlb_k] != 2 && pole_bot_1[str_k + 1][stlb_k] != 2)
                {
                    count_rob++;
                    printf("Убит!\n");

                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 10) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    for (int h = 0; h < 1000; h++)
                    {
                        ll = rand() % 4;
                        if (ll == 0 && str_k - 1 >= 0 && pole_bot_1[str_k - 1][stlb_k] != 6)
                            break;
                        if (ll == 1 && stlb_k - 1 >= 0 && pole_bot_1[str_k][stlb_k - 1] != 6)
                            break;
                        if (ll == 2 && str_k + 1 <= 9 && pole_bot_1[str_k + 1][stlb_k] != 6)
                            break;
                        if (ll == 3 && stlb_k + 1 <= 9 && pole_bot_1[str_k][stlb_k + 1] != 6)
                            break;
                    }

                    if (ll == 0)
                    {

                        if (pole_bot_1[str_k - 1][stlb_k] == 2)
                        {
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            flag_k = 1;
                            pole_bot_1[str_k - 1][stlb_k] = 6;
                        }
                    }
                    if (ll == 1)
                    {
                        if (pole_bot_1[str_k][stlb_k - 1] == 2)
                        {
                            pole_bot_1[str_k][stlb_k - 1] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            if (count_rob == 10) return bot_win;
                        }

                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            flag_k = 1;
                            pole_bot_1[str_k][stlb_k - 1] = 6;
                        }
                    }
                    if (ll == 3)
                    {
                        if (pole_bot_1[str_k][stlb_k + 1] == 2)
                        {
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            if (count_rob == 10) return bot_win;
                        }

                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            flag_k = 1;
                            pole_bot_1[str_k][stlb_k + 1] = 6;
                        }
                    }
                    if (ll == 2)
                    {
                        if (pole_bot_1[str_k + 1][stlb_k] == 2)
                        {
                            pole_bot_1[str_k + 1][stlb_k] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            flag_k = 1;
                            pole_bot_1[str_k + 1][stlb_k] = 6;
                        }
                    }
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 3)
            {
                pole_bot_1[str_k][stlb_k] = 8;

                if (pole_bot_1[str_k][stlb_k - 1] != 3 && pole_bot_1[str_k][stlb_k + 1] != 3 && pole_bot_1[str_k - 1][stlb_k] != 3 && pole_bot_1[str_k + 1][stlb_k] != 3)
                {

                    if (pole_bot_1[str_k][stlb_k - 1] == 8 && pole_bot_1[str_k][stlb_k - 2] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 10) return bot_win;
                    }
                    if (pole_bot_1[str_k][stlb_k - 1] == 8 && pole_bot_1[str_k][stlb_k - 2] == 3)
                    {
                        pole_bot_1[str_k][stlb_k - 2] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 10) return bot_win;
                    }

                    if (pole_bot_1[str_k][stlb_k + 1] == 8 && pole_bot_1[str_k][stlb_k + 2] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 10) return bot_win;
                    }
                    if (pole_bot_1[str_k][stlb_k + 1] == 8 && pole_bot_1[str_k][stlb_k + 2] == 3)
                    {
                        pole_bot_1[str_k][stlb_k + 2] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 10) return bot_win;
                    }

                    if (pole_bot_1[str_k - 1][stlb_k] == 8 && pole_bot_1[str_k - 2][stlb_k] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 10) return bot_win;
                    }
                    if (pole_bot_1[str_k - 1][stlb_k] == 8 && pole_bot_1[str_k - 2][stlb_k] == 3)
                    {
                        pole_bot_1[str_k - 2][stlb_k] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 10) return bot_win;
                    }

                    if (pole_bot_1[str_k + 1][stlb_k] == 8 && pole_bot_1[str_k + 2][stlb_k] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 10) return bot_win;
                    }
                    if (pole_bot_1[str_k + 1][stlb_k] == 8 && pole_bot_1[str_k + 2][stlb_k] == 3)
                    {
                        pole_bot_1[str_k + 2][stlb_k] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 10) return bot_win;
                    }
                    //
                    if (pole_bot_1[str_k + 1][stlb_k] == 8 && pole_bot_1[str_k - 1][stlb_k] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 10) return bot_win;
                    }
                    if (pole_bot_1[str_k][stlb_k + 1] == 8 && pole_bot_1[str_k][stlb_k - 1] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 10) return bot_win;
                    }
                    //
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);

                    for (int h = 0; h < 1000; h++)
                    {
                        kk = rand() % 4;
                        if (kk == 0 && str_k - 1 >= 0 && pole_bot_1[str_k - 1][stlb_k] != 6 && pole_bot_1[str_k - 1][stlb_k] != 8)
                            break;
                        if (kk == 1 && stlb_k - 1 >= 0 && pole_bot_1[str_k][stlb_k - 1] != 6 && pole_bot_1[str_k][stlb_k - 1] != 8)
                            break;
                        if (kk == 2 && str_k + 1 <= 9 && pole_bot_1[str_k + 1][stlb_k] != 6 && pole_bot_1[str_k + 1][stlb_k] != 8)
                            break;
                        if (kk == 3 && stlb_k + 1 <= 9 && pole_bot_1[str_k][stlb_k + 1] != 6 && pole_bot_1[str_k][stlb_k + 1] != 8)
                            break;
                    }
                    if (kk == 0)
                    {
                        if (pole_bot_1[str_k - 1][stlb_k] == 3)
                        {
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            if (pole_bot_1[str_k - 2][stlb_k] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }
                            if (pole_bot_1[str_k + 1][stlb_k] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }
                            if (pole_bot_1[str_k + 1][stlb_k] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k + 1, stlb_k);
                                pole_bot_1[str_k + 1][stlb_k] = 8;
                                printf("Убит!\n");

                                count_rob++;
                                printf("%d %d\n", str_k + 1, stlb_k);
                                if (count_rob == 10) return bot_win;
                            }
                            if (pole_bot_1[str_k - 2][stlb_k] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k - 2, stlb_k);
                                pole_bot_1[str_k - 2][stlb_k] = 8;
                                printf("Убит!\n");

                                count_rob++;
                                printf("%d %d\n", str_k - 2, stlb_k);
                                if (count_rob == 10) return bot_win;
                            }
                        }
                        else
                        {
                            printf("Мимо!\n");
                            flag_k = 1;

                            if (pole_bot_1[str_k - 1][stlb_k] == 0 || pole_bot_1[str_k - 1][stlb_k] == 7)
                                pole_bot_1[str_k - 1][stlb_k] = 6;
                        }
                    }
                    if (kk == 1)
                    {
                        if (pole_bot_1[str_k][stlb_k - 1] == 3)
                        {
                            pole_bot_1[str_k][stlb_k - 1] = 8;
                            if (pole_bot_1[str_k][stlb_k - 2] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }
                            if (pole_bot_1[str_k][stlb_k + 1] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }

                            if (pole_bot_1[str_k][stlb_k + 1] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k + 1);
                                pole_bot_1[str_k][stlb_k + 1] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k, stlb_k + 1);
                                if (count_rob == 10) return bot_win;
                            }
                            if (pole_bot_1[str_k][stlb_k - 2] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k - 2);
                                pole_bot_1[str_k][stlb_k - 2] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k, stlb_k - 2);
                                if (count_rob == 10) return bot_win;
                            }
                        }
                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 1] == 0 || pole_bot_1[str_k][stlb_k - 1] == 7)
                                pole_bot_1[str_k][stlb_k - 1] = 6;
                        }
                    }
                    if (kk == 2)
                    {
                        if (pole_bot_1[str_k + 1][stlb_k] == 3)
                        {
                            pole_bot_1[str_k + 1][stlb_k] = 8;
                            if (pole_bot_1[str_k + 2][stlb_k] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }
                            if (pole_bot_1[str_k - 1][stlb_k] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }

                            if (pole_bot_1[str_k - 1][stlb_k] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k - 1, stlb_k);
                                pole_bot_1[str_k - 1][stlb_k] = 8;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                                count_rob++;
                                printf("%d %d\n", str_k - 1, stlb_k);
                            }
                            if (pole_bot_1[str_k + 2][stlb_k] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k + 2, stlb_k);
                                pole_bot_1[str_k + 2][stlb_k] = 8;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                                count_rob++;
                                printf("%d %d\n", str_k + 2, stlb_k);
                            }
                        }
                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            flag_k = 1;
                            if (pole_bot_1[str_k + 1][stlb_k] == 0 || pole_bot_1[str_k + 1][stlb_k] == 7)
                                pole_bot_1[str_k + 1][stlb_k] = 6;
                        }
                    }
                    if (kk == 3)
                    {

                        if (pole_bot_1[str_k][stlb_k + 1] == 3)
                        {
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            if (pole_bot_1[str_k][stlb_k + 2] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }
                            if (pole_bot_1[str_k][stlb_k - 1] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }

                            if (pole_bot_1[str_k][stlb_k - 1] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k - 1);
                                pole_bot_1[str_k][stlb_k - 1] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k, stlb_k - 1);
                                if (count_rob == 10) return bot_win;
                            }
                            if (pole_bot_1[str_k][stlb_k + 2] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k + 2);
                                pole_bot_1[str_k][stlb_k + 2] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k, stlb_k + 2);
                                if (count_rob == 10) return bot_win;
                            }

                        } // posle pervogo ranen ne dva, TROIKI I DVOIKI STRELIAUT POVTORNO KUDA USHE STRLIALI

                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 1] == 0 || pole_bot_1[str_k][stlb_k + 1] == 7)
                                pole_bot_1[str_k][stlb_k + 1] = 6;
                        }
                    }
                }
            }
            int oe = 0;
            int oes = 0;
            int oess = 0;

            if (pole_bot_1[str_k][stlb_k] == 4)
            {
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4
                    && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 &&
                    pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 &&
                    pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 &&
                    pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                {
                    count_rob++;
                    printf("Убит!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 10) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    for (int h = 0; h < 1000; h++)
                    {
                        ss = rand() % 4;
                        if (ss == 0 && str_k - 1 >= 0 && pole_bot_1[str_k - 1][stlb_k] != 6 && pole_bot_1[str_k - 1][stlb_k] != 8)
                            break;
                        if (ss == 1 && stlb_k - 1 >= 0 && pole_bot_1[str_k][stlb_k - 1] != 6 && pole_bot_1[str_k][stlb_k - 1] != 8)
                            break;
                        if (ss == 2 && str_k + 1 <= 9 && pole_bot_1[str_k + 1][stlb_k] != 6 && pole_bot_1[str_k + 1][stlb_k] != 8)
                            break;
                        if (ss == 3 && stlb_k + 1 <= 9 && pole_bot_1[str_k][stlb_k + 1] != 6 && pole_bot_1[str_k][stlb_k + 1] != 8)
                            break;
                    }
                    if (ss == 0)
                    {
                        if (pole_bot_1[str_k - 1][stlb_k] == 4)
                        {
                            oe = 1;
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            if (pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k - 2][stlb_k] == 4)
                            {
                                oe = 2;
                                pole_bot_1[str_k - 2][stlb_k] = 8;
                                if (pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 10) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k - 3][stlb_k] == 4)
                            {
                                pole_bot_1[str_k - 3][stlb_k] = 8;
                                if (pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 10) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            //тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k - 1][stlb_k] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            flag_k = 1;
                            if (pole_bot_1[str_k - 1][stlb_k] == 0 || pole_bot_1[str_k - 1][stlb_k] == 7)
                                pole_bot_1[str_k - 1][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k - 2][stlb_k] != 8 && oe >= 1)
                        {
                            if (pole_bot_1[str_k - 2][stlb_k] == 0 || pole_bot_1[str_k - 2][stlb_k] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k - 2, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k - 2][stlb_k] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k - 2][stlb_k] == 0 || pole_bot_1[str_k - 2][stlb_k] == 7)
                                pole_bot_1[str_k - 2][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k - 3][stlb_k] != 8 && oe >= 2)
                        {
                            if (pole_bot_1[str_k - 3][stlb_k] == 0 || pole_bot_1[str_k - 3][stlb_k] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k - 3, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k - 3][stlb_k] == 6)
                                flag_k = 0;

                            if (pole_bot_1[str_k - 3][stlb_k] == 0 || pole_bot_1[str_k - 3][stlb_k] == 7)
                                pole_bot_1[str_k - 3][stlb_k] = 6;
                        }
                    }
                    if (ss == 1)
                    {
                        if (pole_bot_1[str_k][stlb_k - 1] == 4)
                        {
                            oes = 1;
                            pole_bot_1[str_k][stlb_k - 1] = 8;
                            if (pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k][stlb_k - 2] == 4)
                            {
                                oes = 2;
                                pole_bot_1[str_k][stlb_k - 2] = 8;
                                if (pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 10) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k][stlb_k - 3] == 4)
                            {
                                pole_bot_1[str_k][stlb_k - 3] = 8;
                                if (pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 10) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            //тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k - 1] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 1] == 0 || pole_bot_1[str_k][stlb_k - 1] == 7)
                                pole_bot_1[str_k][stlb_k - 1] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k - 2] != 8 && oes >= 1)
                        {
                            if (pole_bot_1[str_k][stlb_k - 2] == 0 || pole_bot_1[str_k][stlb_k - 2] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k - 2);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 2] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k - 2] == 0 || pole_bot_1[str_k][stlb_k - 2] == 7)
                                pole_bot_1[str_k][stlb_k - 2] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k - 3] != 8 && oes >= 2)
                        {
                            if (pole_bot_1[str_k][stlb_k - 3] == 0 || pole_bot_1[str_k][stlb_k - 3] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k - 3);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 3] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k - 3] == 0 || pole_bot_1[str_k][stlb_k - 3] == 7)
                                pole_bot_1[str_k][stlb_k - 3] = 6;
                        }

                        oe = 0;
                        oes = 0;
                        oess = 0;
                    }
                    if (ss == 2)
                    {
                        if (pole_bot_1[str_k + 1][stlb_k] == 4)
                        {
                            oe = 1;
                            pole_bot_1[str_k + 1][stlb_k] = 8;
                            if (pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k + 2][stlb_k] == 4)
                            {
                                oe = 2;
                                pole_bot_1[str_k + 2][stlb_k] = 8;
                                if (pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 10) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k + 3][stlb_k] == 4)
                            {
                                pole_bot_1[str_k + 3][stlb_k] = 8;
                                if (pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 10) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            // тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            flag_k = 1;
                            if (pole_bot_1[str_k + 1][stlb_k] == 0 || pole_bot_1[str_k + 1][stlb_k] == 7)
                                pole_bot_1[str_k + 1][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 8 && oe >= 1)
                        {
                            if (pole_bot_1[str_k + 2][stlb_k] == 0)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k + 2, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k + 2][stlb_k] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k + 2][stlb_k] == 0 || pole_bot_1[str_k + 2][stlb_k] == 7)
                                pole_bot_1[str_k + 2][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k + 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 8 && oe >= 2)
                        {
                            if (pole_bot_1[str_k + 3][stlb_k] == 0 || pole_bot_1[str_k + 3][stlb_k] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k + 3, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k + 3][stlb_k] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k + 3][stlb_k] == 0 || pole_bot_1[str_k + 3][stlb_k] == 7)
                                pole_bot_1[str_k + 3][stlb_k] = 6;
                        }
                    }
                    if (ss == 3)
                    {
                        if (pole_bot_1[str_k][stlb_k + 1] == 4)
                        {
                            oes = 1;
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            if (pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k][stlb_k + 2] == 4)
                            {
                                oes = 2;
                                pole_bot_1[str_k][stlb_k + 2] = 8;
                                if (pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 10) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k][stlb_k + 3] == 4)
                            {
                                pole_bot_1[str_k][stlb_k + 3] = 8;
                                if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 10) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            // тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 1] == 0 || pole_bot_1[str_k - 1][stlb_k] == 7)
                                pole_bot_1[str_k][stlb_k + 1] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 8 && oes >= 1)
                        {
                            if (pole_bot_1[str_k][stlb_k + 2] == 0 || pole_bot_1[str_k][stlb_k + 2] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k + 2);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 2] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k + 2] == 0 || pole_bot_1[str_k][stlb_k + 2] == 7)
                                pole_bot_1[str_k][stlb_k + 2] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 8 && oes >= 2)
                        {
                            if (pole_bot_1[str_k][stlb_k + 3] == 0 || pole_bot_1[str_k][stlb_k + 3] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k + 3);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 3] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k + 3] == 0 || pole_bot_1[str_k][stlb_k + 3] == 7)
                                pole_bot_1[str_k][stlb_k + 3] = 6;
                        }

                        if (count_rob == 10) return bot_win;
                    }
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 0 || pole_bot_1[str_k][stlb_k] == 7)
            {
                flag_k = 1;
                printf("Мимо!\n");
                pole_bot_1[str_k][stlb_k] = 6;
            }
            oe = 0; // sdelat chtob esli 10 viiti
            oes = 0;
            oess = 0;

            printf("\n\n\n");
           
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    printf("%d ", pole_bot_1[i][j]);
                }
                printf("\n");
            }
            printf("\n\n\n");
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    printf("%d ", pole_bot_2[i][j]);
                }
                printf("\n");
            }
            printf("\n\n\n");

            count_bot[0] = count_rob;
            if (flag_k == 0) continue;
            if (flag_k == 1) return hod_chel;
            if (count_rob == 10) return bot_win;
        }
    }
}

int easy_bot_fi(int pole_bot_1[15][15], int pole_bot_2[15][15], int* count_bot, int* count, int* radar_count, int flag_mode) {
    int count_rob = count_bot[0];
    srand(time(NULL));
    for (int j = 0; j < 10000; j++)
    {
        if(flag_mode==2) Sleep(100);
        if (count_rob == 11) return bot_win;
        int ll;
        int kk;
        int ss;
        int flag_k = 0;
        printf("Ход бота!\n");
        if (flag_mode == 1 && radar_bot_fi(pole_bot_1, radar_count, count_bot) == 1) return hod_chel;
        if (count_rob == 11) return bot_win;
        int str_k, stlb_k;
        str_k = rand() % 15;
        stlb_k = rand() % 15;
        if (str_k <= 14 && stlb_k <= 14 && str_k >= 0 && stlb_k >= 0 && pole_bot_1[str_k][stlb_k] != 8 && pole_bot_1[str_k][stlb_k] != 6)
        {
            if (pole_bot_1[str_k][stlb_k] == 9) {
                mina_fi(pole_bot_2, str_k, stlb_k, count, 1);
                pole_bot_1[str_k][stlb_k] = 10;
                flag_k = 1;
                if (count[0] == 11) {
                    printf("Все корабли потоплены");
                    return chel_win;
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 1)
            {
                printf("Убит!\n");
                printf("%d %d\n", str_k, stlb_k);
                count_rob++;
                pole_bot_1[str_k][stlb_k] = 8;
                if (count_rob == 11) return bot_win;
            }
            if (pole_bot_1[str_k][stlb_k] == 2)
            {
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 2 && pole_bot_1[str_k][stlb_k + 1] != 2 && pole_bot_1[str_k - 1][stlb_k] != 2 && pole_bot_1[str_k + 1][stlb_k] != 2)
                {
                    count_rob++;
                    printf("Убит!\n");

                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 11) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    for (int h = 0; h < 1000; h++)
                    {
                        ll = rand() % 4;
                        if (ll == 0 && str_k - 1 >= 0 && pole_bot_1[str_k - 1][stlb_k] != 6)
                            break;
                        if (ll == 1 && stlb_k - 1 >= 0 && pole_bot_1[str_k][stlb_k - 1] != 6)
                            break;
                        if (ll == 2 && str_k + 1 <= 14 && pole_bot_1[str_k + 1][stlb_k] != 6)
                            break;
                        if (ll == 3 && stlb_k + 1 <= 14 && pole_bot_1[str_k][stlb_k + 1] != 6)
                            break;
                    }

                    if (ll == 0)
                    {
                        //test
                        if (pole_bot_1[str_k - 1][stlb_k] == 2)
                        {
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            flag_k = 1;
                            pole_bot_1[str_k - 1][stlb_k] = 6;
                        }
                    }
                    if (ll == 1)
                    {
                        if (pole_bot_1[str_k][stlb_k - 1] == 2)
                        {
                            pole_bot_1[str_k][stlb_k - 1] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            if (count_rob == 11) return bot_win;
                        }

                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            flag_k = 1;
                            pole_bot_1[str_k][stlb_k - 1] = 6;
                        }
                    }
                    if (ll == 3)
                    {
                        if (pole_bot_1[str_k][stlb_k + 1] == 2)
                        {
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            if (count_rob == 11) return bot_win;
                        }

                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            flag_k = 1;
                            pole_bot_1[str_k][stlb_k + 1] = 6;
                        }
                    }
                    if (ll == 2)
                    {
                        if (pole_bot_1[str_k + 1][stlb_k] == 2)
                        {
                            pole_bot_1[str_k + 1][stlb_k] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Mimo!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            flag_k = 1;
                            pole_bot_1[str_k + 1][stlb_k] = 6;
                        }
                    }
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 3)
            {
                pole_bot_1[str_k][stlb_k] = 8;

                if (pole_bot_1[str_k][stlb_k - 1] != 3 && pole_bot_1[str_k][stlb_k + 1] != 3 && pole_bot_1[str_k - 1][stlb_k] != 3 && pole_bot_1[str_k + 1][stlb_k] != 3)
                {

                    if (pole_bot_1[str_k][stlb_k - 1] == 8 && pole_bot_1[str_k][stlb_k - 2] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 11) return bot_win;
                    }
                    if (pole_bot_1[str_k][stlb_k - 1] == 8 && pole_bot_1[str_k][stlb_k - 2] == 3)
                    {
                        pole_bot_1[str_k][stlb_k - 2] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 11) return bot_win;
                    }

                    if (pole_bot_1[str_k][stlb_k + 1] == 8 && pole_bot_1[str_k][stlb_k + 2] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 11) return bot_win;
                    }
                    if (pole_bot_1[str_k][stlb_k + 1] == 8 && pole_bot_1[str_k][stlb_k + 2] == 3)
                    {
                        pole_bot_1[str_k][stlb_k + 2] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 11) return bot_win;
                    }

                    if (pole_bot_1[str_k - 1][stlb_k] == 8 && pole_bot_1[str_k - 2][stlb_k] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 11) return bot_win;
                    }
                    if (pole_bot_1[str_k - 1][stlb_k] == 8 && pole_bot_1[str_k - 2][stlb_k] == 3)
                    {
                        pole_bot_1[str_k - 2][stlb_k] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 11) return bot_win;
                    }

                    if (pole_bot_1[str_k + 1][stlb_k] == 8 && pole_bot_1[str_k + 2][stlb_k] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 11) return bot_win;
                    }
                    if (pole_bot_1[str_k + 1][stlb_k] == 8 && pole_bot_1[str_k + 2][stlb_k] == 3)
                    {
                        pole_bot_1[str_k + 2][stlb_k] = 8;
                        count_rob++;
                        printf("Ubit!\n");
                        if (count_rob == 11) return bot_win;
                    }
                    //
                    if (pole_bot_1[str_k + 1][stlb_k] == 8 && pole_bot_1[str_k - 1][stlb_k] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 11) return bot_win;
                    }
                    if (pole_bot_1[str_k][stlb_k + 1] == 8 && pole_bot_1[str_k][stlb_k - 1] == 8)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        if (count_rob == 11) return bot_win;
                    }
                    //
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);

                    for (int h = 0; h < 1000; h++)
                    {
                        kk = rand() % 4;
                        if (kk == 0 && str_k - 1 >= 0 && pole_bot_1[str_k - 1][stlb_k] != 6 && pole_bot_1[str_k - 1][stlb_k] != 8)
                            break;
                        if (kk == 1 && stlb_k - 1 >= 0 && pole_bot_1[str_k][stlb_k - 1] != 6 && pole_bot_1[str_k][stlb_k - 1] != 8)
                            break;
                        if (kk == 2 && str_k + 1 <= 14 && pole_bot_1[str_k + 1][stlb_k] != 6 && pole_bot_1[str_k + 1][stlb_k] != 8)
                            break;
                        if (kk == 3 && stlb_k + 1 <= 14 && pole_bot_1[str_k][stlb_k + 1] != 6 && pole_bot_1[str_k][stlb_k + 1] != 8)
                            break;
                    }
                    if (kk == 0)
                    {
                        if (pole_bot_1[str_k - 1][stlb_k] == 3)
                        {
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            if (pole_bot_1[str_k - 2][stlb_k] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            if (pole_bot_1[str_k + 1][stlb_k] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            if (pole_bot_1[str_k + 1][stlb_k] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k + 1, stlb_k);
                                pole_bot_1[str_k + 1][stlb_k] = 8;
                                printf("Убит!\n");

                                count_rob++;
                                printf("%d %d\n", str_k + 1, stlb_k);
                                if (count_rob == 11) return bot_win;
                            }
                            if (pole_bot_1[str_k - 2][stlb_k] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k - 2, stlb_k);
                                pole_bot_1[str_k - 2][stlb_k] = 8;
                                printf("Убит!\n");

                                count_rob++;
                                printf("%d %d\n", str_k - 2, stlb_k);
                                if (count_rob == 11) return bot_win;
                            }
                        }
                        else
                        {
                            printf("Мимо!\n");
                            flag_k = 1;

                            if (pole_bot_1[str_k - 1][stlb_k] == 0 || pole_bot_1[str_k - 1][stlb_k] == 7)
                                pole_bot_1[str_k - 1][stlb_k] = 6;
                        }
                    }
                    if (kk == 1)
                    {
                        if (pole_bot_1[str_k][stlb_k - 1] == 3)
                        {
                            pole_bot_1[str_k][stlb_k - 1] = 8;
                            if (pole_bot_1[str_k][stlb_k - 2] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            if (pole_bot_1[str_k][stlb_k + 1] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }

                            if (pole_bot_1[str_k][stlb_k + 1] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k + 1);
                                pole_bot_1[str_k][stlb_k + 1] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k, stlb_k + 1);
                                if (count_rob == 11) return bot_win;
                            }
                            if (pole_bot_1[str_k][stlb_k - 2] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k - 2);
                                pole_bot_1[str_k][stlb_k - 2] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k, stlb_k - 2);
                                if (count_rob == 11) return bot_win;
                            }
                        }
                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 1] == 0 || pole_bot_1[str_k][stlb_k - 1] == 7)
                                pole_bot_1[str_k][stlb_k - 1] = 6;
                        }
                    }
                    if (kk == 2)
                    {
                        if (pole_bot_1[str_k + 1][stlb_k] == 3)
                        {
                            pole_bot_1[str_k + 1][stlb_k] = 8;
                            if (pole_bot_1[str_k + 2][stlb_k] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            if (pole_bot_1[str_k - 1][stlb_k] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }

                            if (pole_bot_1[str_k - 1][stlb_k] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k - 1, stlb_k);
                                pole_bot_1[str_k - 1][stlb_k] = 8;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                                count_rob++;
                                printf("%d %d\n", str_k - 1, stlb_k);
                            }
                            if (pole_bot_1[str_k + 2][stlb_k] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k + 2, stlb_k);
                                pole_bot_1[str_k + 2][stlb_k] = 8;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                                count_rob++;
                                printf("%d %d\n", str_k + 2, stlb_k);
                            }
                        }
                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            flag_k = 1;
                            if (pole_bot_1[str_k + 1][stlb_k] == 0 || pole_bot_1[str_k + 1][stlb_k] == 7)
                                pole_bot_1[str_k + 1][stlb_k] = 6;
                        }
                    }
                    if (kk == 3)
                    {

                        if (pole_bot_1[str_k][stlb_k + 1] == 3)
                        {
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            if (pole_bot_1[str_k][stlb_k + 2] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            if (pole_bot_1[str_k][stlb_k - 1] == 8)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }

                            if (pole_bot_1[str_k][stlb_k - 1] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k - 1);
                                pole_bot_1[str_k][stlb_k - 1] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k, stlb_k - 1);
                                if (count_rob == 11) return bot_win;
                            }
                            if (pole_bot_1[str_k][stlb_k + 2] == 3)
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k + 2);
                                pole_bot_1[str_k][stlb_k + 2] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k, stlb_k + 2);
                                if (count_rob == 11) return bot_win;
                            }

                        } // posle pervogo ranen ne dva, TROIKI I DVOIKI STRELIAUT POVTORNO KUDA USHE STRLIALI

                        else
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 1] == 0 || pole_bot_1[str_k][stlb_k + 1] == 7)
                                pole_bot_1[str_k][stlb_k + 1] = 6;
                        }
                    }
                }
            }
            int oe = 0;
            int oes = 0;
            int oess = 0;

            if (pole_bot_1[str_k][stlb_k] == 4)
            {
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                {
                    count_rob++;
                    printf("Убит!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 11) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    for (int h = 0; h < 1000; h++)
                    {
                        ss = rand() % 4;
                        if (ss == 0 && str_k - 1 >= 0 && pole_bot_1[str_k - 1][stlb_k] != 6 && pole_bot_1[str_k - 1][stlb_k] != 8)
                            break;
                        if (ss == 1 && stlb_k - 1 >= 0 && pole_bot_1[str_k][stlb_k - 1] != 6 && pole_bot_1[str_k][stlb_k - 1] != 8)
                            break;
                        if (ss == 2 && str_k + 1 <= 14 && pole_bot_1[str_k + 1][stlb_k] != 6 && pole_bot_1[str_k + 1][stlb_k] != 8)
                            break;
                        if (ss == 3 && stlb_k + 1 <= 14 && pole_bot_1[str_k][stlb_k + 1] != 6 && pole_bot_1[str_k][stlb_k + 1] != 8)
                            break;
                    }
                    if (ss == 0)
                    {
                        if (pole_bot_1[str_k - 1][stlb_k] == 4)
                        {
                            oe = 1;
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            if (pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k - 2][stlb_k] == 4)
                            {
                                oe = 2;
                                pole_bot_1[str_k - 2][stlb_k] = 8;
                                if (pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k - 3][stlb_k] == 4)
                            {
                                pole_bot_1[str_k - 3][stlb_k] = 8;
                                if (pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            //тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k - 1][stlb_k] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            flag_k = 1;
                            if (pole_bot_1[str_k - 1][stlb_k] == 0 || pole_bot_1[str_k - 1][stlb_k] == 7)
                                pole_bot_1[str_k - 1][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k - 2][stlb_k] != 8 && oe >= 1)
                        {
                            if (pole_bot_1[str_k - 2][stlb_k] == 0 || pole_bot_1[str_k - 2][stlb_k] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k - 2, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k - 2][stlb_k] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k - 2][stlb_k] == 0)
                                pole_bot_1[str_k - 2][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k - 3][stlb_k] != 7 && oe >= 2)
                        {
                            if (pole_bot_1[str_k - 3][stlb_k] == 0 || pole_bot_1[str_k - 3][stlb_k] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k - 3, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k - 3][stlb_k] == 6)
                                flag_k = 0;

                            if (pole_bot_1[str_k - 3][stlb_k] == 0 || pole_bot_1[str_k - 3][stlb_k] == 7)
                                pole_bot_1[str_k - 3][stlb_k] = 6;
                        }
                    }
                    if (ss == 1)
                    {
                        if (pole_bot_1[str_k][stlb_k - 1] == 4)
                        {
                            oes = 1;
                            pole_bot_1[str_k][stlb_k - 1] = 8;
                            if (pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k][stlb_k - 2] == 4)
                            {
                                oes = 2;
                                pole_bot_1[str_k][stlb_k - 2] = 8;
                                if (pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k][stlb_k - 3] == 4)
                            {
                                pole_bot_1[str_k][stlb_k - 3] = 8;
                                if (pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            //тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k - 1] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 1] == 0 || pole_bot_1[str_k][stlb_k - 1] == 7)
                                pole_bot_1[str_k][stlb_k - 1] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k - 2] != 8 && oes >= 1)
                        {
                            if (pole_bot_1[str_k][stlb_k - 2] == 0)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k - 2);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 2] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k - 2] == 0 || pole_bot_1[str_k][stlb_k - 2] == 7)
                                pole_bot_1[str_k][stlb_k - 2] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k - 3] != 8 && oes >= 2)
                        {
                            if (pole_bot_1[str_k][stlb_k - 3] == 0 || pole_bot_1[str_k][stlb_k - 3] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k - 3);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 3] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k - 3] == 0 || pole_bot_1[str_k][stlb_k - 3] == 7)
                                pole_bot_1[str_k][stlb_k - 3] = 6;
                        }

                        oe = 0;
                        oes = 0;
                        oess = 0;
                    }
                    if (ss == 2)
                    {
                        if (pole_bot_1[str_k + 1][stlb_k] == 4)
                        {
                            oe = 1;
                            pole_bot_1[str_k + 1][stlb_k] = 8;
                            if (pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k + 2][stlb_k] == 4)
                            {
                                oe = 2;
                                pole_bot_1[str_k + 2][stlb_k] = 8;
                                if (pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k + 3][stlb_k] == 4)
                            {
                                pole_bot_1[str_k + 3][stlb_k] = 8;
                                if (pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            //тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            flag_k = 1;
                            if (pole_bot_1[str_k + 1][stlb_k] == 0 || pole_bot_1[str_k + 1][stlb_k] == 7)
                                pole_bot_1[str_k + 1][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 8 && oe >= 1)
                        {
                            if (pole_bot_1[str_k + 2][stlb_k] == 0 || pole_bot_1[str_k + 2][stlb_k] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k + 2, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k + 2][stlb_k] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k + 2][stlb_k] == 0 || pole_bot_1[str_k + 2][stlb_k] == 7)
                                pole_bot_1[str_k + 2][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k + 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 8 && oe >= 2)
                        {
                            if (pole_bot_1[str_k + 3][stlb_k] == 0 || pole_bot_1[str_k + 3][stlb_k] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k + 3, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k + 3][stlb_k] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k + 3][stlb_k] == 0 || pole_bot_1[str_k + 3][stlb_k] == 7)
                                pole_bot_1[str_k + 3][stlb_k] = 6;
                        }
                    }
                    if (ss == 3)
                    {
                        if (pole_bot_1[str_k][stlb_k + 1] == 4)
                        {
                            oes = 1;
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            if (pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k][stlb_k + 2] == 4)
                            {
                                oes = 2;
                                pole_bot_1[str_k][stlb_k + 2] = 8;
                                if (pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4)
                                {
                                    count_rob++;
                                    printf("Ubit!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k][stlb_k + 3] == 4)
                            {
                                pole_bot_1[str_k][stlb_k + 3] = 8;
                                if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            //тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 1] == 0 || pole_bot_1[str_k][stlb_k + 1] == 7)
                                pole_bot_1[str_k][stlb_k + 1] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 8 && oes >= 1)
                        {
                            if (pole_bot_1[str_k][stlb_k + 2] == 0)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k + 2);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 2] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k + 2] == 0 || pole_bot_1[str_k][stlb_k + 2] == 7)
                                pole_bot_1[str_k][stlb_k + 2] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 8 && oes >= 2)
                        {
                            if (pole_bot_1[str_k][stlb_k + 3] == 0 || pole_bot_1[str_k][stlb_k + 3] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k + 3);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 3] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k + 3] == 0 || pole_bot_1[str_k][stlb_k + 3] == 7)
                                pole_bot_1[str_k][stlb_k + 3] = 6;
                        }

                        if (count_rob == 11) return bot_win;
                    }
                }
            }
            oe = 0;
            oes = 0;
            oess = 0;
            if (pole_bot_1[str_k][stlb_k] == 5)
            {
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                {
                    count_rob++;
                    printf("Убит!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 11) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    for (int h = 0; h < 1000; h++)
                    {
                        ss = rand() % 4;
                        if (ss == 0 && str_k - 1 >= 0 && pole_bot_1[str_k - 1][stlb_k] != 6 && pole_bot_1[str_k - 1][stlb_k] != 8)
                            break;
                        if (ss == 1 && stlb_k - 1 >= 0 && pole_bot_1[str_k][stlb_k - 1] != 6 && pole_bot_1[str_k][stlb_k - 1] != 8)
                            break;
                        if (ss == 2 && str_k + 1 <= 14 && pole_bot_1[str_k + 1][stlb_k] != 6 && pole_bot_1[str_k + 1][stlb_k] != 8)
                            break;
                        if (ss == 3 && stlb_k + 1 <= 14 && pole_bot_1[str_k][stlb_k + 1] != 6 && pole_bot_1[str_k][stlb_k + 1] != 8)
                            break;
                    }
                    if (ss == 0)
                    {
                        if (pole_bot_1[str_k - 1][stlb_k] == 5)
                        {
                            oe = 1;
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            if (pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k - 2][stlb_k] == 5)
                            {
                                oe = 2;
                                pole_bot_1[str_k - 2][stlb_k] = 8;
                                if (pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k - 3][stlb_k] == 5)
                            {
                                oe = 3;
                                pole_bot_1[str_k - 3][stlb_k] = 8;
                                if (pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k - 4][stlb_k] == 5)
                            {
                                pole_bot_1[str_k - 4][stlb_k] = 8;
                                if (pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            //тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k - 1][stlb_k] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            flag_k = 1;
                            if (pole_bot_1[str_k - 1][stlb_k] == 0 || pole_bot_1[str_k - 1][stlb_k] == 7)
                                pole_bot_1[str_k - 1][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k - 2][stlb_k] != 8 && oe >= 1)
                        {
                            if (pole_bot_1[str_k - 2][stlb_k] == 0 || pole_bot_1[str_k - 2][stlb_k] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k - 2, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k - 2][stlb_k] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k - 2][stlb_k] == 0 || pole_bot_1[str_k - 2][stlb_k] == 7)
                                pole_bot_1[str_k - 2][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k - 3][stlb_k] != 8 && oe >= 2)
                        {
                            if (pole_bot_1[str_k - 3][stlb_k] == 0 || pole_bot_1[str_k - 3][stlb_k] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k - 3, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k - 3][stlb_k] == 6)
                                flag_k = 0;

                            if (pole_bot_1[str_k - 3][stlb_k] == 0 || pole_bot_1[str_k - 3][stlb_k] == 7)
                                pole_bot_1[str_k - 3][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k - 4][stlb_k] != 8 && oe >= 3)
                        {
                            if (pole_bot_1[str_k - 4][stlb_k] == 0)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k - 4, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k - 4][stlb_k] == 6)
                                flag_k = 0;

                            if (pole_bot_1[str_k - 4][stlb_k] == 0 || pole_bot_1[str_k - 4][stlb_k] == 7)
                                pole_bot_1[str_k - 4][stlb_k] = 6;
                        }
                    } // tut ostanovilsia!!!!
                    if (ss == 1)
                    {
                        if (pole_bot_1[str_k][stlb_k - 1] == 5)
                        {
                            oes = 1;
                            pole_bot_1[str_k][stlb_k - 1] = 8;
                            if (pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k][stlb_k - 2] == 5)
                            {
                                oes = 2;
                                pole_bot_1[str_k][stlb_k - 2] = 8;
                                if (pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k][stlb_k - 3] == 5)
                            {
                                oes = 3;
                                pole_bot_1[str_k][stlb_k - 3] = 8;
                                if (pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен!\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k][stlb_k - 4] == 5)
                            {
                                pole_bot_1[str_k][stlb_k - 4] = 8;
                                if (pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен!\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            //тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k - 1] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 1] == 0 || pole_bot_1[str_k][stlb_k - 1] == 7)
                                pole_bot_1[str_k][stlb_k - 1] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k - 2] != 8 && oes >= 1)
                        {
                            if (pole_bot_1[str_k][stlb_k - 2] == 0)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k - 2);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 2] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k - 2] == 0 || pole_bot_1[str_k][stlb_k - 2] == 7)
                                pole_bot_1[str_k][stlb_k - 2] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k - 3] != 8 && oes >= 2)
                        {
                            if (pole_bot_1[str_k][stlb_k - 3] == 0 || pole_bot_1[str_k][stlb_k - 3] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k - 3);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 3] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k - 3] == 0 || pole_bot_1[str_k][stlb_k - 3] == 7)
                                pole_bot_1[str_k][stlb_k - 3] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k - 4] != 8 && oes >= 3)
                        {
                            if (pole_bot_1[str_k][stlb_k - 4] == 0)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k - 4);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k - 4] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k - 4] == 0 || pole_bot_1[str_k][stlb_k - 4] == 7)
                                pole_bot_1[str_k][stlb_k - 4] = 6;
                        }

                        oe = 0;
                        oes = 0;
                        oess = 0;
                    }
                    if (ss == 2)
                    {
                        if (pole_bot_1[str_k + 1][stlb_k] == 5)
                        {
                            oe = 1;
                            pole_bot_1[str_k + 1][stlb_k] = 8;
                            if (pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k + 2][stlb_k] == 5)
                            {
                                oe = 2;
                                pole_bot_1[str_k + 2][stlb_k] = 8;
                                if (pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k + 3][stlb_k] == 5)
                            {
                                oe = 3;
                                pole_bot_1[str_k + 3][stlb_k] = 8;
                                if (pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k + 4][stlb_k] == 5)
                            {
                                pole_bot_1[str_k + 4][stlb_k] = 8;
                                if (pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            //тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            flag_k = 1;
                            if (pole_bot_1[str_k + 1][stlb_k] == 0 || pole_bot_1[str_k + 1][stlb_k] == 7)
                                pole_bot_1[str_k + 1][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 8 && oe >= 1)
                        {
                            if (pole_bot_1[str_k + 2][stlb_k] == 0)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k + 2, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k + 2][stlb_k] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k + 2][stlb_k] == 0 || pole_bot_1[str_k + 2][stlb_k] == 7)
                                pole_bot_1[str_k + 2][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 8 && oe >= 2)
                        {
                            if (pole_bot_1[str_k + 3][stlb_k] == 0)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k + 3, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k + 3][stlb_k] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k + 3][stlb_k] == 0 || pole_bot_1[str_k + 3][stlb_k] == 7)
                                pole_bot_1[str_k + 3][stlb_k] = 6;
                        }
                        if (pole_bot_1[str_k + 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 8 && oe >= 3)
                        {
                            if (pole_bot_1[str_k + 4][stlb_k] == 0)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k + 4, stlb_k);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k + 4][stlb_k] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k + 4][stlb_k] == 0 || pole_bot_1[str_k + 4][stlb_k] == 7)
                                pole_bot_1[str_k + 4][stlb_k] = 6;
                        }
                    }
                    if (ss == 3)
                    {
                        if (pole_bot_1[str_k][stlb_k + 1] == 5)
                        {
                            oes = 1;
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            if (pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                if (count_rob == 11) return bot_win;
                            }
                            else
                            {
                                printf("Ранен\n");
                                printf("%d %d\n", str_k, stlb_k);
                            }
                            if (pole_bot_1[str_k][stlb_k + 2] == 5)
                            {
                                oes = 2;
                                pole_bot_1[str_k][stlb_k + 2] = 8;
                                if (pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k][stlb_k + 3] == 5)
                            {
                                oes = 3;
                                pole_bot_1[str_k][stlb_k + 3] = 8;
                                if (pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }
                            if (pole_bot_1[str_k][stlb_k + 4] == 5)
                            {
                                oes = 3;
                                pole_bot_1[str_k][stlb_k + 4] = 8;
                                if (pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k - 1] != 5)
                                {
                                    count_rob++;
                                    printf("Убит!\n");
                                    if (count_rob == 11) return bot_win;
                                }
                                else
                                {
                                    printf("Ранен\n");
                                    printf("%d %d\n", str_k, stlb_k);
                                }
                            }

                            // тут поработать с 4 а так контррооль иф елс
                        }
                        if (pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 8)
                        {
                            printf("Мимо!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 1] == 0 || pole_bot_1[str_k][stlb_k + 1] == 7)
                                pole_bot_1[str_k][stlb_k + 1] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 8 && oes >= 1)
                        {
                            if (pole_bot_1[str_k][stlb_k + 2] == 0 || pole_bot_1[str_k][stlb_k + 2] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k + 2);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 2] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k + 2] == 0 || pole_bot_1[str_k][stlb_k + 2] == 7)
                                pole_bot_1[str_k][stlb_k + 2] = 6; // tut nado ispravit
                        }
                        if (pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 8 && oes >= 2)
                        {
                            if (pole_bot_1[str_k][stlb_k + 3] == 0 || pole_bot_1[str_k][stlb_k + 3] == 7)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k + 3);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 3] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k + 3] == 0 || pole_bot_1[str_k][stlb_k + 3] == 7)
                                pole_bot_1[str_k][stlb_k + 3] = 6;
                        }
                        if (pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 8 && oes >= 3)
                        {
                            if (pole_bot_1[str_k][stlb_k + 4] == 0)
                            {
                                printf("Мимо!\n");
                                printf("%d %d\n", str_k, stlb_k + 4);
                            }
                            flag_k = 1;
                            if (pole_bot_1[str_k][stlb_k + 4] == 6)
                                flag_k = 0;
                            if (pole_bot_1[str_k][stlb_k + 4] == 0 || pole_bot_1[str_k][stlb_k + 4] == 7)
                                pole_bot_1[str_k][stlb_k + 4] = 6;
                        }

               
                        if (count_rob == 11) return bot_win;
                    }
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 0 || pole_bot_1[str_k][stlb_k] == 7)
            {
                flag_k = 1;
                printf("Мимо!\n");
                pole_bot_1[str_k][stlb_k] = 6;
            }
            oe = 0; // sdelat chtob esli 10 viiti
            oes = 0;
            oess = 0;

 /*
            printf("\n\n\n");
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    if (pole_bot_1[i][j] != 1 && pole_bot_1[i][j] != 2 && pole_bot_1[i][j] != 3 && pole_bot_1[i][j] != 4 && pole_bot_1[i][j] != 6 && pole_bot_1[i][j] != 7 && pole_bot_1[i][j] != 5 && pole_bot_1[i][j] != 8)
                        pole_bot_1[i][j] = 0;
                }
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    printf("%d ", pole_bot_1[i][j]);
                }
                printf("\n");
            }
            printf("\n\n\n");
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    if (pole_bot_2[i][j] != 1 && pole_bot_2[i][j] != 2 && pole_bot_2[i][j] != 3 && pole_bot_2[i][j] != 4 && pole_bot_2[i][j] != 6 && pole_bot_2[i][j] != 7 && pole_bot_2[i][j] != 5 && pole_bot_2[i][j] != 8)
                        pole_bot_2[i][j] = 0;
                }
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    printf("%d ", pole_bot_2[i][j]);
                }
                printf("\n");
            }
            printf("\n\n\n");*/
            count_bot[0] = count_rob;
            if (flag_k == 0) continue;
            if (flag_k == 1) return hod_chel;
            if (count_rob == 11) return bot_win;
        }
    }
}
//-----------------------------------------------------------------------------------------//

//средний
//int otsl_bot_1 = -1;
//int otsl_bot_2 = -1;

int medi_bot_ten(int pole_bot_1[10][10], int pole_bot_2[10][10], int* otsl_bot_1, int* otsl_bot_2, int* count_bot, int* count, int* radar_count, int flag_bot, int flag_mode)
{
    int count_rob = count_bot[0];
    //printf("----------%d\n", count_rob);
        for (int j = 0; j < 1000; j++)
        {
           if(flag_mode==2) Sleep(100);
            if (count_rob == 10) return bot_win;
            int ll;
            int kk;
            int ss;
            int flag_k = 0;
            printf("Ход бота!\n");
            if (flag_mode == 1 && radar_bot_ten(pole_bot_1, radar_count, count_bot) == 1) return hod_chel;
            if (count_rob == 10) return bot_win;
            int str_k, stlb_k;
            if (flag_bot == 1) {
                otsl_bot_1[0] = otsl_bot_1[0] + 1;;
                strel_med_game_chel_komp_ten(otsl_bot_1[0], &str_k, &stlb_k);
            }
            else {
                otsl_bot_2[0]= otsl_bot_2[0] + 1;
                strel_med_game_chel_komp_ten(otsl_bot_2[0], &str_k, &stlb_k);
            }
            if (str_k <= 9 && stlb_k <= 9 && str_k >= 0 && stlb_k >= 0 && pole_bot_1[str_k][stlb_k] != 8 && pole_bot_1[str_k][stlb_k] != 6)
            {
                if (pole_bot_1[str_k][stlb_k] == 9) {
                    mina_ten(pole_bot_2, str_k, stlb_k, count, 1);
                    pole_bot_1[str_k][stlb_k] = 10;
                    flag_k = 1;
                    if (count[0] == 10) {
                        printf("Все корабли потоплены");
                        return chel_win;
                    }
                }

                if (pole_bot_1[str_k][stlb_k] == 1)
                {
                    printf("Убит!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    count_rob++;

                    pole_bot_1[str_k][stlb_k] = 8;
                    if (count_rob == 10) return bot_win;
                }
                if (pole_bot_1[str_k][stlb_k] == 2)
                {
                    pole_bot_1[str_k][stlb_k] = 8;
                    if (pole_bot_1[str_k][stlb_k - 1] != 2 && pole_bot_1[str_k][stlb_k + 1] != 2 && pole_bot_1[str_k - 1][stlb_k] != 2 && pole_bot_1[str_k + 1][stlb_k] != 2)
                    {
                        count_rob++;
                        printf("Убит!\n");

                        printf("%d %d\n", str_k, stlb_k);
                        if (count_rob == 10) return bot_win;
                    }
                    else
                    {
                        printf("Ранен!\n");
                        printf("%d %d\n", str_k, stlb_k);

                        if (pole_bot_1[str_k - 1][stlb_k] == 2 && (str_k-1)>=0)
                        {
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            if (count_rob == 10) return bot_win;
                        }
                        if (pole_bot_1[str_k][stlb_k - 1] == 2 && (stlb_k-1)>=0)
                        {
                            pole_bot_1[str_k][stlb_k - 1] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            if (count_rob == 10) return bot_win;
                        }

                        if (pole_bot_1[str_k][stlb_k + 1] == 2 && (stlb_k+1) <10)
                        {
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            if (count_rob == 10) return bot_win;
                        }

                        if (pole_bot_1[str_k + 1][stlb_k] == 2 && (str_k+1) < 10)
                        {
                            pole_bot_1[str_k + 1][stlb_k] = 8;
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            if (count_rob == 10) return bot_win;
                        }
                    }
                }

                if (pole_bot_1[str_k][stlb_k] == 3)
                {
                    pole_bot_1[str_k][stlb_k] = 8;

                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);

                    if (pole_bot_1[str_k][stlb_k - 1] == 3)
                    {
                        pole_bot_1[str_k][stlb_k - 1] = 8;
                        printf("Ранен!\n");
                        printf("%d %d\n", str_k, stlb_k - 1);
                        if (pole_bot_1[str_k][stlb_k - 2] == 3)
                        {
                            pole_bot_1[str_k][stlb_k - 2] = 8;
                            printf("Убит!\n");
                            count_rob++;
                            printf("%d %d\n", str_k, stlb_k - 2);
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            if (pole_bot_1[str_k][stlb_k + 1] == 3)
                            {
                                pole_bot_1[str_k][stlb_k + 1] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k, stlb_k + 1);
                                if (count_rob == 10) return bot_win;
                            }
                        }
                    }
                    else
                    {
                        if (pole_bot_1[str_k][stlb_k + 1] == 3)
                        {
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            if (pole_bot_1[str_k][stlb_k + 2] == 3)
                            {
                                pole_bot_1[str_k][stlb_k + 2] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k, stlb_k + 2);
                                if (count_rob == 10) return bot_win;
                            }
                        }
                        else
                        {
                            if (pole_bot_1[str_k - 1][stlb_k] == 3)
                            {
                                pole_bot_1[str_k - 1][stlb_k] = 8;
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k - 1, stlb_k);
                                if (pole_bot_1[str_k - 2][stlb_k] == 3)
                                {
                                    pole_bot_1[str_k - 2][stlb_k] = 8;
                                    printf("Убит!\n");
                                    count_rob++;
                                    printf("%d %d\n", str_k - 2, stlb_k);
                                    if (count_rob == 10) return bot_win;
                                }
                                else
                                {
                                    if (pole_bot_1[str_k + 1][stlb_k] == 3)
                                    {
                                        pole_bot_1[str_k + 1][stlb_k] = 8;
                                        printf("Убит!\n");
                                        count_rob++;
                                        printf("%d %d\n", str_k + 1, stlb_k);
                                        if (count_rob == 10) return bot_win;
                                    }
                                }
                            }
                            else
                            {
                                if (pole_bot_1[str_k + 1][stlb_k] == 3)
                                {
                                    pole_bot_1[str_k + 1][stlb_k] = 8;
                                    printf("Ранен!\n");
                                    printf("%d %d\n", str_k, stlb_k + 1);
                                    if (pole_bot_1[str_k + 2][stlb_k] == 3)
                                    {
                                        pole_bot_1[str_k + 2][stlb_k] = 8;
                                        printf("Убит!\n");
                                        count_rob++;
                                        printf("%d %d\n", str_k + 2, stlb_k);
                                        if (count_rob == 10) return bot_win;
                                    }
                                }
                            }
                        }
                    }
                }

                if (pole_bot_1[str_k][stlb_k] == 4)
                {
                    int flazok = 0;
                    pole_bot_1[str_k][stlb_k] = 8;
                    if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                    {
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k, stlb_k);
                        if (count_rob == 10) return bot_win;
                    }
                    else
                    {
                        printf("Ранен!\n");
                        printf("%d %d\n", str_k, stlb_k);

                        if (pole_bot_1[str_k][stlb_k - 1] == 4)
                        {
                            pole_bot_1[str_k][stlb_k - 1] = 8;
                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k, stlb_k - 1);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k - 1);
                            }
                        }
                        if (pole_bot_1[str_k][stlb_k - 2] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k][stlb_k - 2] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k, stlb_k - 2);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k - 2);
                            }
                        }
                        if (pole_bot_1[str_k][stlb_k - 3] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k][stlb_k - 3] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k, stlb_k - 3);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k - 3);
                            }
                        }
                        if (pole_bot_1[str_k][stlb_k + 1] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k][stlb_k + 1] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k, stlb_k + 1);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k + 1);
                            }
                        }
                        if (pole_bot_1[str_k][stlb_k + 2] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k][stlb_k + 2] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k, stlb_k + 2);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k + 2);
                            }
                        }
                        if (pole_bot_1[str_k][stlb_k + 3] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k][stlb_k + 3] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k, stlb_k + 3);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k + 3);
                            }
                        }

                        if (pole_bot_1[str_k + 1][stlb_k] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k + 1][stlb_k] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k + 1, stlb_k);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k + 1, stlb_k);
                            }
                        }
                        if (pole_bot_1[str_k + 2][stlb_k] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k + 2][stlb_k] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k + 2, stlb_k);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k + 2, stlb_k);
                            }
                        }
                        if (pole_bot_1[str_k + 3][stlb_k] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k + 3][stlb_k] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k + 3, stlb_k);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k + 3, stlb_k);
                            }
                        }

                        if (pole_bot_1[str_k - 1][stlb_k] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k - 1][stlb_k] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k - 1, stlb_k);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k - 1, stlb_k);
                            }
                        }
                        if (pole_bot_1[str_k - 2][stlb_k] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k - 2][stlb_k] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k - 2, stlb_k);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k - 2, stlb_k);
                            }
                        }
                        if (pole_bot_1[str_k - 3][stlb_k] == 4 && flazok != 1)
                        {
                            pole_bot_1[str_k - 3][stlb_k] = 8;

                            if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                            {
                                count_rob++;
                                printf("Убит!\n");
                                printf("%d %d\n", str_k - 3, stlb_k);
                                flazok = 1;
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k - 3, stlb_k);
                            }
                        }
                    }
                }
                if (pole_bot_1[str_k][stlb_k] == 0 || pole_bot_1[str_k][stlb_k] == 7)
                {
                    flag_k = 1;
                    printf("Мимо!\n");
                    pole_bot_1[str_k][stlb_k] = 6;
                }

              /*  printf("\n\n\n");
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (pole_bot_1[i][j] != 1 && pole_bot_1[i][j] != 2 && pole_bot_1[i][j] != 3 && pole_bot_1[i][j] != 4 && pole_bot_1[i][j] != 6 && pole_bot_1[i][j] != 7 && pole_bot_1[i][j] != 8)
                            pole_bot_1[i][j] = 0;
                    }
                }
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        printf("%d ", pole_bot_1[i][j]);
                    }
                    printf("\n");
                }
                printf("\n\n\n");
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        if (pole_bot_2[i][j] != 1 && pole_bot_2[i][j] != 2 && pole_bot_2[i][j] != 3 && pole_bot_2[i][j] != 4 && pole_bot_2[i][j] != 6 && pole_bot_2[i][j] != 7 && pole_bot_2[i][j] != 8)
                            pole_bot_2[i][j] = 0;
                    }
                }
                for (int i = 0; i < 10; i++)
                {
                    for (int j = 0; j < 10; j++)
                    {
                        printf("%d ", pole_bot_2[i][j]);
                    }
                    printf("\n");
                }
                printf("\n\n\n");*/
                count_bot[0] = count_rob;
                if (flag_k == 0) continue;
                if (flag_k == 1) return hod_chel;
                if (count_rob == 10) return bot_win;
            }
        }
}

int medi_bot_fif(int pole_bot_1[15][15], int pole_bot_2[15][15], int* otsl_bot_1, int* otsl_bot_2, int* count_bot, int* count, int* radar_count, int flag_bot, int flag_mode) {
    int count_rob = count_bot[0];
    for (int j = 0; j < 1000; j++)
    {
        if (flag_mode == 2) Sleep(100);
        if (count_rob == 11) return bot_win;
        int str;
        int stlb;
        char sim1;
        int sim2;
        int flag_k = 0;
        int str_k, stlb_k;
        printf("Ход бота!\n");
        if (flag_mode == 1 && radar_bot_fi(pole_bot_1, radar_count, count_bot) == 1) return hod_chel;
        if (count_rob == 11) return bot_win;
        if (flag_bot == 1) {
            otsl_bot_1[0] = otsl_bot_1[0] + 1;;
            strel_med_game_chel_komp_fif(otsl_bot_1[0], &str_k, &stlb_k);
        }
        else {
            otsl_bot_2[0] = otsl_bot_2[0] + 1;
            strel_med_game_chel_komp_fif(otsl_bot_2[0], &str_k, &stlb_k);
        }
        if (str_k <= 14 && stlb_k <= 14 && str_k >= 0 && stlb_k >= 0 && pole_bot_1[str_k][stlb_k] != 8 && pole_bot_1[str_k][stlb_k] != 6)
        {
            if (pole_bot_1[str_k][stlb_k] == 9) {
                mina_fi(pole_bot_2, str_k, stlb_k, count, 1);
                pole_bot_1[str_k][stlb_k] = 10;
                flag_k = 1;
                if (count[0] == 11) {
                    printf("Все корабли потоплены");
                    return chel_win;
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 1)
            {
                printf("Убит!\n");
                printf("%d %d\n", str_k, stlb_k);
                count_rob++;

                pole_bot_1[str_k][stlb_k] = 8;
                if (count_rob == 11) return bot_win;
            }
            if (pole_bot_1[str_k][stlb_k] == 2)
            {
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 2 && pole_bot_1[str_k][stlb_k + 1] != 2 && pole_bot_1[str_k - 1][stlb_k] != 2 && pole_bot_1[str_k + 1][stlb_k] != 2)
                {
                    count_rob++;
                    printf("Убит!\n");

                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 11) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);

                    if (pole_bot_1[str_k - 1][stlb_k] == 2 && (str_k - 1) >= 0)
                    {
                        pole_bot_1[str_k - 1][stlb_k] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k - 1, stlb_k);
                        if (count_rob == 11) return bot_win;
                    }
                    if (pole_bot_1[str_k][stlb_k - 1] == 2 && (stlb_k - 1) >= 0)
                    {
                        pole_bot_1[str_k][stlb_k - 1] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k, stlb_k - 1);
                        if (count_rob == 11) return bot_win;
                    }

                    if (pole_bot_1[str_k][stlb_k + 1] == 2 && (stlb_k + 1) < 15)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k, stlb_k + 1);
                        if (count_rob == 11) return bot_win;
                    }

                    if (pole_bot_1[str_k + 1][stlb_k] == 2 && (str_k + 1) < 15)
                    {
                        pole_bot_1[str_k + 1][stlb_k] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k + 1, stlb_k);
                        if (count_rob == 11) return bot_win;
                    }
                }
            }

            if (pole_bot_1[str_k][stlb_k] == 3)
            {
                pole_bot_1[str_k][stlb_k] = 8;

                printf("Ранен!\n");
                printf("%d %d\n", str_k, stlb_k);

                if (pole_bot_1[str_k][stlb_k - 1] == 3)
                {
                    pole_bot_1[str_k][stlb_k - 1] = 8;
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k - 1);
                    if (pole_bot_1[str_k][stlb_k - 2] == 3)
                    {
                        pole_bot_1[str_k][stlb_k - 2] = 8;
                        printf("Убит!\n");
                        count_rob++;
                        printf("%d %d\n", str_k, stlb_k - 2);
                        if (count_rob == 11) return bot_win;
                    }
                    else
                    {
                        if (pole_bot_1[str_k][stlb_k + 1] == 3)
                        {
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            printf("Убит!\n");
                            count_rob++;
                            printf("%d %d\n", str_k, stlb_k + 1);
                            if (count_rob == 11) return bot_win;
                        }
                    }
                }
                else
                {
                    if (pole_bot_1[str_k][stlb_k + 1] == 3)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;
                        printf("Ранен!\n");
                        printf("%d %d\n", str_k, stlb_k + 1);
                        if (pole_bot_1[str_k][stlb_k + 2] == 3)
                        {
                            pole_bot_1[str_k][stlb_k + 2] = 8;
                            printf("Убит!\n");
                            count_rob++;
                            printf("%d %d\n", str_k, stlb_k + 2);
                            if (count_rob == 11) return bot_win;
                        }
                    }
                    else
                    {
                        if (pole_bot_1[str_k - 1][stlb_k] == 3)
                        {
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            if (pole_bot_1[str_k - 2][stlb_k] == 3)
                            {
                                pole_bot_1[str_k - 2][stlb_k] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k - 2, stlb_k);
                                if (count_rob == 11) return bot_win;
                            }
                            else
                            {
                                if (pole_bot_1[str_k + 1][stlb_k] == 3)
                                {
                                    pole_bot_1[str_k + 1][stlb_k] = 8;
                                    printf("Убит!\n");
                                    count_rob++;
                                    printf("%d %d\n", str_k + 1, stlb_k);
                                    if (count_rob == 11) return bot_win;
                                }
                            }
                        }
                        else
                        {
                            if (pole_bot_1[str_k + 1][stlb_k] == 3)
                            {
                                pole_bot_1[str_k + 1][stlb_k] = 8;
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k + 1);
                                if (pole_bot_1[str_k + 2][stlb_k] == 3)
                                {
                                    pole_bot_1[str_k + 2][stlb_k] = 8;
                                    printf("Убит!\n");
                                    count_rob++;
                                    printf("%d %d\n", str_k + 2, stlb_k);
                                    if (count_rob == 11) return bot_win;
                                }
                            }
                        }
                    }
                }
            }

            if (pole_bot_1[str_k][stlb_k] == 4)
            {
                int flazok = 0;
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                {
                    count_rob++;
                    printf("Убит!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 11) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);

                    if (pole_bot_1[str_k][stlb_k - 1] == 4)
                    {
                        pole_bot_1[str_k][stlb_k - 1] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k - 2] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 2] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 2);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 2);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k - 3] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 3] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 3);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 3);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 1] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 2] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 2] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 2);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 2);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 3] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 3] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 3);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 3);
                        }
                    }

                    if (pole_bot_1[str_k + 1][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k + 1][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 2][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k + 2][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 2, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 2, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 3][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k + 3][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 3, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 3, stlb_k);
                        }
                    }

                    if (pole_bot_1[str_k - 1][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k - 1][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k - 2][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k - 2][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 2, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 2, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k - 3][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k - 3][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 3, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 3, stlb_k);
                        }
                    }
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 5)
            {
                int flaxo = 0;
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                {
                    count_rob++;
                    printf("Убит!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 11) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);

                    if (pole_bot_1[str_k - 1][stlb_k] == 5)
                    {
                        pole_bot_1[str_k - 1][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k - 2][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k - 2][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 2, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 2, stlb_k);
                        }
                    }

                    if (pole_bot_1[str_k - 3][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k - 3][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 3, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 3, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k - 4][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k - 4][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 4, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 4, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 1][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k + 1][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 2][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k + 2][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 2, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 2, stlb_k);
                        }
                    }

                    if (pole_bot_1[str_k + 3][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k + 3][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 3, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 3, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 4][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k + 4][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 4, stlb_k);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 4, stlb_k);
                        }
                    }

                    if (pole_bot_1[str_k][stlb_k - 1] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 1] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k - 2] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 2] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 2);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 2);
                        }
                    }

                    if (pole_bot_1[str_k][stlb_k - 3] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 3] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 3);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 3);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k - 4] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 4] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 4);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 4);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 1] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 2] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 2] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 2);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 2);
                        }
                    }

                    if (pole_bot_1[str_k][stlb_k + 3] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 3] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 3);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 3);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 4] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 4] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 4);
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 4);
                        }
                    }
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 0 || pole_bot_1[str_k][stlb_k] == 7)
            {
                flag_k = 1;
                printf("Мимо!\n");
                pole_bot_1[str_k][stlb_k] = 6;
            }
            /*printf("\n\n\n");
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    if (pole_bot_1[i][j] != 1 && pole_bot_1[i][j] != 2 && pole_bot_1[i][j] != 3 && pole_bot_1[i][j] != 4 && pole_bot_1[i][j] != 6 && pole_bot_1[i][j] != 7 && pole_bot_1[i][j] != 5 && pole_bot_1[i][j] != 8)
                        pole_bot_1[i][j] = 0;
                }
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    printf("%d ", pole_bot_1[i][j]);
                }
                printf("\n");
            }
            printf("\n\n\n");
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    if (pole_bot_2[i][j] != 1 && pole_bot_2[i][j] != 2 && pole_bot_2[i][j] != 3 && pole_bot_2[i][j] != 4 && pole_bot_2[i][j] != 6 && pole_bot_2[i][j] != 7 && pole_bot_2[i][j] != 5 && pole_bot_2[i][j] != 8)
                        pole_bot_2[i][j] = 0;
                }
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    printf("%d ", pole_bot_2[i][j]);
                }
                printf("\n");
            }*/
            count_bot[0] = count_rob;
            if (flag_k == 0) continue;
            if (flag_k == 1) return hod_chel;
            if (count_rob == 11) return bot_win;
        }
    }
}
//-----------------------------------------------------------------------------------------//

//сложный
int hard_bot_ten(int pole_bot_1[10][10], int pole_bot_2[10][10], int* otsl_bot_1, int* otsl_bot_2, int* count_bot, int* count, int* radar_count, int flag_bot, int flag_mode)
{
    int count_rob = count_bot[0];
    for (int j = 0; j < 1000; j++)
    {
        if(flag_mode==2) Sleep(100);
        if (count_rob == 10) return bot_win;
        int ll;
        int kk;
        int ss;
        int flag_k = 0;
        printf("Ход бота!\n");
        if (flag_mode == 1 && radar_bot_ten(pole_bot_1, radar_count, count_bot) == 1) return hod_chel;
        if (count_rob == 10) return bot_win;
        int str_k, stlb_k;
        if (flag_bot == 1) {
            otsl_bot_1[0] = otsl_bot_1[0] + 1;;
            strel_hard_game_chel_komp_ten(otsl_bot_1[0], &str_k, &stlb_k);
        }
        else {
            otsl_bot_2[0] = otsl_bot_2[0] + 1;
            strel_hard_game_chel_komp_ten(otsl_bot_2[0], &str_k, &stlb_k);
        }
        if (str_k <= 9 && stlb_k <= 9 && str_k >= 0 && stlb_k >= 0 && pole_bot_1[str_k][stlb_k] != 6 && pole_bot_1[str_k][stlb_k] != 8)
        {
            if (pole_bot_1[str_k][stlb_k] == 9) {
                mina_ten(pole_bot_2, str_k, stlb_k, count, 1);
                pole_bot_1[str_k][stlb_k] = 10;
                flag_k = 1;
                if (count[0] == 10) {
                    printf("Все корабли потоплены");
                    return chel_win;
                }
            }

            if (pole_bot_1[str_k][stlb_k] == 1)
            {
                printf("Убит!\n");
                printf("%d %d\n", str_k, stlb_k);
                count_rob++;

                pole_bot_1[str_k][stlb_k] = 8;
                if (count_rob == 10) return bot_win;
            }
            if (pole_bot_1[str_k][stlb_k] == 2)
            {
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 2 && pole_bot_1[str_k][stlb_k + 1] != 2 && pole_bot_1[str_k - 1][stlb_k] != 2 && pole_bot_1[str_k + 1][stlb_k] != 2)
                {
                    count_rob++;
                    printf("Убит!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 10) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (pole_bot_1[str_k - 1][stlb_k] == 2 && (str_k - 1) >= 0)
                    {
                        pole_bot_1[str_k - 1][stlb_k] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k - 1, stlb_k);
                        if (count_rob == 10) return bot_win;
                    }
                    if (pole_bot_1[str_k][stlb_k - 1] == 2 && (stlb_k - 1) >= 0)
                    {
                        pole_bot_1[str_k][stlb_k - 1] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k, stlb_k - 1);
                        if (count_rob == 10) return bot_win;
                    }

                    if (pole_bot_1[str_k][stlb_k + 1] == 2 && (stlb_k + 1) < 10)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k, stlb_k + 1);
                        if (count_rob == 10) return bot_win;
                    }

                    if (pole_bot_1[str_k + 1][stlb_k] == 2 && (str_k + 1) < 10)
                    {
                        pole_bot_1[str_k + 1][stlb_k] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k + 1, stlb_k);
                        if (count_rob == 10) return bot_win;
                    }
                }
            }

            if (pole_bot_1[str_k][stlb_k] == 3)
            {
                pole_bot_1[str_k][stlb_k] = 8;

                printf("Ранен!\n");
                printf("%d %d\n", str_k, stlb_k);

                if (pole_bot_1[str_k][stlb_k - 1] == 3)
                {
                    pole_bot_1[str_k][stlb_k - 1] = 8;
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k - 1);
                    if (pole_bot_1[str_k][stlb_k - 2] == 3)
                    {
                        pole_bot_1[str_k][stlb_k - 2] = 8;
                        printf("Убит!\n");
                        count_rob++;
                        printf("%d %d\n", str_k, stlb_k - 2);
                        if (count_rob == 10) return bot_win;
                    }
                    else
                    {
                        if (pole_bot_1[str_k][stlb_k + 1] == 3)
                        {
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            printf("Убит!\n");
                            count_rob++;
                            printf("%d %d\n", str_k, stlb_k + 1);
                            if (count_rob == 10) return bot_win;
                        }
                    }
                }
                else
                {
                    if (pole_bot_1[str_k][stlb_k + 1] == 3)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;
                        printf("Ранен!\n");
                        printf("%d %d\n", str_k, stlb_k + 1);
                        if (pole_bot_1[str_k][stlb_k + 2] == 3)
                        {
                            pole_bot_1[str_k][stlb_k + 2] = 8;
                            printf("Убит!\n");
                            count_rob++;
                            printf("%d %d\n", str_k, stlb_k + 2);
                            if (count_rob == 10) return bot_win;
                        }
                    }
                    else
                    {
                        if (pole_bot_1[str_k - 1][stlb_k] == 3)
                        {
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            if (pole_bot_1[str_k - 2][stlb_k] == 3)
                            {
                                pole_bot_1[str_k - 2][stlb_k] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k - 2, stlb_k);
                                if (count_rob == 10) return bot_win;
                            }
                            else
                            {
                                if (pole_bot_1[str_k + 1][stlb_k] == 3)
                                {
                                    pole_bot_1[str_k + 1][stlb_k] = 8;
                                    printf("Убит!\n");
                                    count_rob++;
                                    printf("%d %d\n", str_k + 1, stlb_k);
                                    if (count_rob == 10) return bot_win;
                                }
                            }
                        }
                        else
                        {
                            if (pole_bot_1[str_k + 1][stlb_k] == 3)
                            {
                                pole_bot_1[str_k + 1][stlb_k] = 8;
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k + 1);
                                if (pole_bot_1[str_k + 2][stlb_k] == 3)
                                {
                                    pole_bot_1[str_k + 2][stlb_k] = 8;
                                    printf("Убит!\n");
                                    count_rob++;
                                    printf("%d %d\n", str_k + 2, stlb_k);
                                    if (count_rob == 10) return bot_win;
                                }
                            }
                        }
                    }
                }
            }

            if (pole_bot_1[str_k][stlb_k] == 4)
            {
                int flazok = 0;
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                {
                    count_rob++;
                    printf("Убит!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 10) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);

                    if (pole_bot_1[str_k][stlb_k - 1] == 4)
                    {
                        pole_bot_1[str_k][stlb_k - 1] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k - 2] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 2] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 2);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 2);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k - 3] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 3] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 3);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 3);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 1] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 2] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 2] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 2);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 2);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 3] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 3] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 3);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 3);
                        }
                    }

                    if (pole_bot_1[str_k + 1][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k + 1][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 2][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k + 2][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 2, stlb_k);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 2, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 3][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k + 3][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 3, stlb_k);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 3, stlb_k);
                        }
                    }

                    if (pole_bot_1[str_k - 1][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k - 1][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k - 2][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k - 2][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 2, stlb_k);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 2, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k - 3][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k - 3][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 3, stlb_k);
                            flazok = 1;
                            if (count_rob == 10) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 3, stlb_k);
                        }
                    }
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 0 || pole_bot_1[str_k][stlb_k] == 7)
            {
                flag_k = 1;
                printf("Mimo!\n");
                pole_bot_1[str_k][stlb_k] = 6;
            }
           /* printf("\n\n\n");
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (pole_bot_1[i][j] != 1 && pole_bot_1[i][j] != 2 && pole_bot_1[i][j] != 3 && pole_bot_1[i][j] != 4 && pole_bot_1[i][j] != 6 && pole_bot_1[i][j] != 7 && pole_bot_1[i][j] != 8)
                        pole_bot_1[i][j] = 0;
                }
            }
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    printf("%d ", pole_bot_1[i][j]);
                }
                printf("\n");
            }
            printf("\n\n\n");
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    if (pole_bot_2[i][j] != 1 && pole_bot_2[i][j] != 2 && pole_bot_2[i][j] != 3 && pole_bot_2[i][j] != 4 && pole_bot_2[i][j] != 6 && pole_bot_2[i][j] != 7 && pole_bot_2[i][j] != 8)
                        pole_bot_2[i][j] = 0;
                }
            }
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    printf("%d ", pole_bot_2[i][j]);
                }
                printf("\n");
            }
            printf("\n\n\n");*/
            count_bot[0] = count_rob;
            if (flag_k == 0) continue;
            if (flag_k == 1) return hod_chel;
            if (count_rob == 10) return bot_win;
        }
    }

}

int hard_bot_fif(int pole_bot_1[15][15], int pole_bot_2[15][15], int* otsl_bot_1, int* otsl_bot_2, int* count_bot, int* count, int* radar_count, int flag_bot, int flag_mode) {
    int count_rob = count_bot[0];
    for (int j = 0; j < 10000; j++)
    {
        if (flag_mode == 2) Sleep(100);
        if (count_rob == 11) return bot_win;
        int ll;
        int kk;
        int ss;
        int flag_k = 0;
        printf("Ход бота!\n");
        if (flag_mode == 1 && radar_bot_fi(pole_bot_1, radar_count, count_bot) == 1) return hod_chel;
        if (count_rob == 11) return bot_win;
        int str_k, stlb_k;
        if (flag_bot == 1) {
            otsl_bot_1[0] = otsl_bot_1[0] + 1;;
            strel_hard_game_chel_komp_fif(otsl_bot_1[0], &str_k, &stlb_k);
        }
        else {
            otsl_bot_2[0] = otsl_bot_2[0] + 1;
            strel_hard_game_chel_komp_fif(otsl_bot_2[0], &str_k, &stlb_k);
        }
        if (str_k <= 14 && stlb_k <= 14 && str_k >= 0 && stlb_k >= 0 && pole_bot_1[str_k][stlb_k] != 6 && pole_bot_1[str_k][stlb_k] != 8)
        {
            if (pole_bot_1[str_k][stlb_k] == 9) {
                mina_fi(pole_bot_2, str_k, stlb_k, count, 1);
                pole_bot_1[str_k][stlb_k] = 10;
                flag_k = 1;
                if (count[0] == 11) {
                    printf("Все корабли потоплены");
                    return chel_win;
                }
            }

            if (pole_bot_1[str_k][stlb_k] == 1)
            {
                printf("Убит!\n");
                printf("%d %d\n", str_k, stlb_k);
                count_rob++;

                pole_bot_1[str_k][stlb_k] = 8;
                if (count_rob == 11) return bot_win;
            }
            if (pole_bot_1[str_k][stlb_k] == 2)
            {
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 2 && pole_bot_1[str_k][stlb_k + 1] != 2 && pole_bot_1[str_k - 1][stlb_k] != 2 && pole_bot_1[str_k + 1][stlb_k] != 2)
                {
                    count_rob++;
                    printf("Убит!\n");

                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 11) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (pole_bot_1[str_k - 1][stlb_k] == 2 && (str_k - 1) >= 0)
                    {
                        pole_bot_1[str_k - 1][stlb_k] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k - 1, stlb_k);
                        if (count_rob == 11) return bot_win;
                    }
                    if (pole_bot_1[str_k][stlb_k - 1] == 2 && (stlb_k - 1) >= 0)
                    {
                        pole_bot_1[str_k][stlb_k - 1] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k, stlb_k - 1);
                        if (count_rob == 11) return bot_win;
                    }

                    if (pole_bot_1[str_k][stlb_k + 1] == 2 && (stlb_k + 1) < 15)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k, stlb_k + 1);
                        if (count_rob == 11) return bot_win;
                    }

                    if (pole_bot_1[str_k + 1][stlb_k] == 2 && (str_k + 1) < 15)
                    {
                        pole_bot_1[str_k + 1][stlb_k] = 8;
                        count_rob++;
                        printf("Убит!\n");
                        printf("%d %d\n", str_k + 1, stlb_k);
                        if (count_rob == 11) return bot_win;
                    }
                }
            }

            if (pole_bot_1[str_k][stlb_k] == 3)
            {
                pole_bot_1[str_k][stlb_k] = 8;

                printf("Ранен!\n");
                printf("%d %d\n", str_k, stlb_k);

                if (pole_bot_1[str_k][stlb_k - 1] == 3)
                {
                    pole_bot_1[str_k][stlb_k - 1] = 8;
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k - 1);
                    if (pole_bot_1[str_k][stlb_k - 2] == 3)
                    {
                        pole_bot_1[str_k][stlb_k - 2] = 8;
                        printf("Убит!\n");
                        count_rob++;
                        printf("%d %d\n", str_k, stlb_k - 2);
                        if (count_rob == 11) return bot_win;
                    }
                    else
                    {
                        if (pole_bot_1[str_k][stlb_k + 1] == 3)
                        {
                            pole_bot_1[str_k][stlb_k + 1] = 8;
                            printf("Убит!\n");
                            count_rob++;
                            printf("%d %d\n", str_k, stlb_k + 1);
                            if (count_rob == 11) return bot_win;
                        }
                    }
                }
                else
                {
                    if (pole_bot_1[str_k][stlb_k + 1] == 3)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;
                        printf("Ранен!\n");
                        printf("%d %d\n", str_k, stlb_k + 1);
                        if (pole_bot_1[str_k][stlb_k + 2] == 3)
                        {
                            pole_bot_1[str_k][stlb_k + 2] = 8;
                            printf("Убит!\n");
                            count_rob++;
                            printf("%d %d\n", str_k, stlb_k + 2);
                            if (count_rob == 11) return bot_win;
                        }
                    }
                    else
                    {
                        if (pole_bot_1[str_k - 1][stlb_k] == 3)
                        {
                            pole_bot_1[str_k - 1][stlb_k] = 8;
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            if (pole_bot_1[str_k - 2][stlb_k] == 3)
                            {
                                pole_bot_1[str_k - 2][stlb_k] = 8;
                                printf("Убит!\n");
                                count_rob++;
                                printf("%d %d\n", str_k - 2, stlb_k);
                                if (count_rob == 11) return bot_win;
                            }
                            else
                            {
                                if (pole_bot_1[str_k + 1][stlb_k] == 3)
                                {
                                    pole_bot_1[str_k + 1][stlb_k] = 8;
                                    printf("Убит!\n");
                                    count_rob++;
                                    printf("%d %d\n", str_k + 1, stlb_k);
                                    if (count_rob == 11) return bot_win;
                                }
                            }
                        }
                        else
                        {
                            if (pole_bot_1[str_k + 1][stlb_k] == 3)
                            {
                                pole_bot_1[str_k + 1][stlb_k] = 8;
                                printf("Ранен!\n");
                                printf("%d %d\n", str_k, stlb_k + 1);
                                if (pole_bot_1[str_k + 2][stlb_k] == 3)
                                {
                                    pole_bot_1[str_k + 2][stlb_k] = 8;
                                    printf("Убит!\n");
                                    count_rob++;
                                    printf("%d %d\n", str_k + 2, stlb_k);
                                    if (count_rob == 11) return bot_win;
                                }
                            }
                        }
                    }
                }
            }

            if (pole_bot_1[str_k][stlb_k] == 4)
            {
                int flazok = 0;
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                {
                    count_rob++;
                    printf("Убит!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 11) return bot_win;
                }
                else
                {
                    printf("Ranen!\n");
                    printf("%d %d\n", str_k, stlb_k);

                    if (pole_bot_1[str_k][stlb_k - 1] == 4)
                    {
                        pole_bot_1[str_k][stlb_k - 1] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k - 2] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 2] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 2);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 2);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k - 3] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 3] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 3);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 3);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 1] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 2] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 2] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 2);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 2);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 3] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 3] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 3);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 3);
                        }
                    }

                    if (pole_bot_1[str_k + 1][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k + 1][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ranen!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 2][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k + 2][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 2, stlb_k);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 2, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 3][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k + 3][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 3, stlb_k);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 3, stlb_k);
                        }
                    }

                    if (pole_bot_1[str_k - 1][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k - 1][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k - 2][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k - 2][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 2, stlb_k);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 2, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k - 3][stlb_k] == 4 && flazok != 1)
                    {
                        pole_bot_1[str_k - 3][stlb_k] = 8;

                        if (pole_bot_1[str_k][stlb_k - 1] != 4 && pole_bot_1[str_k][stlb_k + 1] != 4 && pole_bot_1[str_k - 1][stlb_k] != 4 && pole_bot_1[str_k + 1][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 2] != 4 && pole_bot_1[str_k][stlb_k + 2] != 4 && pole_bot_1[str_k - 2][stlb_k] != 4 && pole_bot_1[str_k + 2][stlb_k] != 4 && pole_bot_1[str_k][stlb_k - 3] != 4 && pole_bot_1[str_k][stlb_k + 3] != 4 && pole_bot_1[str_k - 3][stlb_k] != 4 && pole_bot_1[str_k + 3][stlb_k] != 4)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 3, stlb_k);
                            flazok = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 3, stlb_k);
                        }
                    }
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 5)
            {
                int flaxo = 0;
                pole_bot_1[str_k][stlb_k] = 8;
                if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                {
                    count_rob++;
                    printf("Убит!\n");
                    printf("%d %d\n", str_k, stlb_k);
                    if (count_rob == 11) return bot_win;
                }
                else
                {
                    printf("Ранен!\n");
                    printf("%d %d\n", str_k, stlb_k);

                    if (pole_bot_1[str_k - 1][stlb_k] == 5)
                    {
                        pole_bot_1[str_k - 1][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ranen!\n");
                            printf("%d %d\n", str_k - 1, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k - 2][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k - 2][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 2, stlb_k);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 2, stlb_k);
                        }
                    }

                    if (pole_bot_1[str_k - 3][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k - 3][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 3, stlb_k);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ranen!\n");
                            printf("%d %d\n", str_k - 3, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k - 4][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k - 4][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k - 4, stlb_k);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k - 4, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 1][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k + 1][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 1, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 2][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k + 2][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 2, stlb_k);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 2, stlb_k);
                        }
                    }

                    if (pole_bot_1[str_k + 3][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k + 3][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 3, stlb_k);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 3, stlb_k);
                        }
                    }
                    if (pole_bot_1[str_k + 4][stlb_k] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k + 4][stlb_k] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k + 4, stlb_k);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k + 4, stlb_k);
                        }
                    }

                    if (pole_bot_1[str_k][stlb_k - 1] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 1] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 1);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k - 2] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 2] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 2);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 2);
                        }
                    }

                    if (pole_bot_1[str_k][stlb_k - 3] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 3] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k - 3);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 3);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k - 4] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k - 4] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит\n");
                            printf("%d %d\n", str_k, stlb_k - 4);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k - 4);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 1] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 1] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 1);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 2] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 2] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 2);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 2);
                        }
                    }

                    if (pole_bot_1[str_k][stlb_k + 3] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 3] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 3);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 3);
                        }
                    }
                    if (pole_bot_1[str_k][stlb_k + 4] == 5 && flaxo != 1)
                    {
                        pole_bot_1[str_k][stlb_k + 4] = 8;
                        if (pole_bot_1[str_k][stlb_k - 1] != 5 && pole_bot_1[str_k][stlb_k + 1] != 5 && pole_bot_1[str_k - 1][stlb_k] != 5 && pole_bot_1[str_k + 1][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 2] != 5 && pole_bot_1[str_k][stlb_k + 2] != 5 && pole_bot_1[str_k - 2][stlb_k] != 5 && pole_bot_1[str_k + 2][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 3] != 5 && pole_bot_1[str_k][stlb_k + 3] != 5 && pole_bot_1[str_k - 3][stlb_k] != 5 && pole_bot_1[str_k + 3][stlb_k] != 5 && pole_bot_1[str_k][stlb_k - 4] != 5 && pole_bot_1[str_k][stlb_k + 4] != 5 && pole_bot_1[str_k - 4][stlb_k] != 5 && pole_bot_1[str_k + 4][stlb_k] != 5)
                        {
                            count_rob++;
                            printf("Убит!\n");
                            printf("%d %d\n", str_k, stlb_k + 4);
                            flaxo = 1;
                            if (count_rob == 11) return bot_win;
                        }
                        else
                        {
                            printf("Ранен!\n");
                            printf("%d %d\n", str_k, stlb_k + 4);
                        }
                    }
                }
            }
            if (pole_bot_1[str_k][stlb_k] == 0 || pole_bot_1[str_k][stlb_k] == 7)
            {
                flag_k = 1;
                printf("Mimo!\n");
                pole_bot_1[str_k][stlb_k] = 6;
            }

  
           /* if (flag_k == 0) continue;
            printf("\n\n\n");
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    if (pole_bot_1[i][j] != 1 && pole_bot_1[i][j] != 2 && pole_bot_1[i][j] != 3 && pole_bot_1[i][j] != 4 && pole_bot_1[i][j] != 6 && pole_bot_1[i][j] != 7 && pole_bot_1[i][j] != 5 && pole_bot_1[i][j] != 8)
                        pole_bot_1[i][j] = 0;
                }
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    printf("%d ", pole_bot_1[i][j]);
                }
                printf("\n");
            }
            printf("\n\n\n");
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    if (pole_bot_2[i][j] != 1 && pole_bot_2[i][j] != 2 && pole_bot_2[i][j] != 3 && pole_bot_2[i][j] != 4 && pole_bot_2[i][j] != 6 && pole_bot_2[i][j] != 7 && pole_bot_2[i][j] != 5 && pole_bot_2[i][j] != 8)
                        pole_bot_2[i][j] = 0;
                }
            }
            for (int i = 0; i < 15; i++)
            {
                for (int j = 0; j < 15; j++)
                {
                    printf("%d ", pole_bot_2[i][j]);
                }
                printf("\n");
            }
            printf("\n\n\n");*/
            count_bot[0] = count_rob;
            if (flag_k == 0) continue;
            if (flag_k == 1) return hod_chel;
            if (count_rob == 11) return bot_win;
        }
    }
}
//-----------------------------------------------------------------------------------------//   
//int bot_1 = 1;
//int bot_2 = 1;
int game_bot_ten(int pole_bot_1[10][10], int pole_bot_2[10][10], int* otsl_bot_1, int* otsl_bot_2, int* count_bot_1, int* count_bot_2, int* count_radar, int level, int bot_1, int bot_2) {
    if (level == 1) {
        if (bot_1 != 3 && bot_2 != 3) bot_1 = easy_bot_ten(pole_bot_2, pole_bot_1, count_bot_1, count_bot_2, count_radar, 2);
        if (bot_2 != 3 && bot_1 != 3) bot_2 = easy_bot_ten(pole_bot_1, pole_bot_2, count_bot_2, count_bot_1, count_radar, 2);

    }
    else if (level == 2) {
        if (bot_2 != 3 && bot_1 != 3) bot_2 = medi_bot_ten(pole_bot_1, pole_bot_2, otsl_bot_1, otsl_bot_2, count_bot_2, count_bot_1, count_radar, 1,2);
        if (bot_1 != 3 && bot_2 != 3) bot_1 = easy_bot_ten(pole_bot_2, pole_bot_1, count_bot_1, count_bot_2, count_radar, 2);

    }
    else if (level == 3) { 
        if (bot_1 != 3 && bot_2 != 3) bot_1 = easy_bot_ten(pole_bot_2, pole_bot_1, count_bot_1, count_bot_2, count_radar, 2);
        if (bot_2 != 3 && bot_1 != 3) bot_2 = hard_bot_ten(pole_bot_1, pole_bot_2, otsl_bot_1, otsl_bot_2, count_bot_2, count_bot_1, count_radar, 1,2);
    }
    else if (level == 4) {
        if (bot_2 != 3 && bot_1 != 3) bot_2 = medi_bot_ten(pole_bot_1, pole_bot_2, otsl_bot_1, otsl_bot_2, count_bot_2, count_bot_1, count_radar, 2,2);
        if (bot_1 != 3 && bot_2 != 3) bot_1 = medi_bot_ten(pole_bot_2, pole_bot_1, otsl_bot_1, otsl_bot_2,count_bot_1, count_bot_2, count_radar, 1,2);
        
    }
    else if (level == 5) {
        if (bot_1 != 3 && bot_2 != 3) bot_1 = medi_bot_ten(pole_bot_2, pole_bot_1, otsl_bot_1, otsl_bot_2, count_bot_1, count_bot_2, count_radar, 1,2);
        if (bot_2 != 3 && bot_1 != 3) bot_2 = hard_bot_ten(pole_bot_1, pole_bot_2, otsl_bot_1, otsl_bot_2, count_bot_2, count_bot_1, count_radar, 2,2);
    }
    else if (level == 6) {
        if (bot_1 != 3 && bot_2 != 3) bot_1 = hard_bot_ten(pole_bot_2, pole_bot_1, otsl_bot_1, otsl_bot_2, count_bot_1, count_bot_2, count_radar, 1,2);
        if (bot_2 != 3 && bot_1 != 3) bot_2 = hard_bot_ten(pole_bot_1, pole_bot_2, otsl_bot_1, otsl_bot_2, count_bot_2, count_bot_1, count_radar, 2,2);
    }
    if (bot_1 == 3) return 2;
    if (bot_2 == 3) return 3;
}
int game_bot_fi(int pole_bot_1[15][15], int pole_bot_2[15][15], int* otsl_bot_1, int* otsl_bot_2, int* count_bot_1, int* count_bot_2, int* count_radar, int level, int bot_1, int bot_2) {
    if (level == 1) {
        if (bot_1 != 3 && bot_2 != 3) bot_1 = easy_bot_fi(pole_bot_2, pole_bot_1, count_bot_1, count_bot_2, count_radar, 2);
        if (bot_2 != 3 && bot_1 != 3) bot_2 = easy_bot_fi(pole_bot_1, pole_bot_2, count_bot_2, count_bot_1, count_radar, 2);
    }
    else if (level == 2) {
        if (bot_2 != 3 && bot_1 != 3) bot_2 = medi_bot_fif(pole_bot_1, pole_bot_2, otsl_bot_1, otsl_bot_2, count_bot_2, count_bot_1, count_radar, 1, 2);
        if (bot_1 != 3 && bot_2 != 3) bot_1 = easy_bot_fi(pole_bot_2, pole_bot_1, count_bot_1, count_bot_2, count_radar, 2);

    }
    else if (level == 3) {
        if (bot_1 != 3 && bot_2 != 3) bot_1 = easy_bot_fi(pole_bot_2, pole_bot_1, count_bot_1, count_bot_2, count_radar, 2);
        if (bot_2 != 3 && bot_1 != 3) bot_2 = hard_bot_fif(pole_bot_1, pole_bot_2, otsl_bot_1, otsl_bot_2, count_bot_2, count_bot_1, count_radar, 1, 2);
    }
    else if (level == 4) {
        if (bot_1 != 3 && bot_2 != 3) bot_1 = medi_bot_fif(pole_bot_2, pole_bot_1, otsl_bot_1, otsl_bot_2, count_bot_1, count_bot_2, count_radar, 1, 2);
        if (bot_2 != 3 && bot_1 != 3) bot_2 = medi_bot_fif(pole_bot_1, pole_bot_2, otsl_bot_1, otsl_bot_2, count_bot_2, count_bot_1, count_radar, 2, 2);
    }
    else if (level == 5) {
        if (bot_1 != 3 && bot_2 != 3) bot_1 = medi_bot_fif(pole_bot_2, pole_bot_1, otsl_bot_1, otsl_bot_2, count_bot_1, count_bot_2, count_radar, 1, 2);
        if (bot_2 != 3 && bot_1 != 3) bot_2 = hard_bot_fif(pole_bot_1, pole_bot_2, otsl_bot_1, otsl_bot_2, count_bot_2, count_bot_1, count_radar, 2, 2);
    }
    else if (level == 6) {
        if (bot_1 != 3 && bot_2 != 3) bot_1 = hard_bot_fif(pole_bot_2, pole_bot_1, otsl_bot_1, otsl_bot_2, count_bot_1, count_bot_2, count_radar, 1, 2);
        if (bot_2 != 3 && bot_1 != 3) bot_2 = hard_bot_fif(pole_bot_1, pole_bot_2, otsl_bot_1, otsl_bot_2, count_bot_2, count_bot_1, count_radar, 2, 2);
    }
    if (bot_1 == 3) return 2;
    if (bot_2 == 3) return 3;
}

