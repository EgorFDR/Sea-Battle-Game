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


int chel_attack_ten(int pole[10][10], int my_pole[10][10], int* count, int* count_b, int grid_x, int grid_y, int* count_hod, int flag_smoke) {
    int count_chel = count[0];
    if (count_chel == 10) {
        printf("Все корабли потоплены");
        return chel_win;
    }

    int str = grid_y;
    int stlb = grid_x;
    int flag = 0;
    printf("Ход:\n");
    if (str <= 9 && stlb <= 9 && str >= 0 && stlb >= 0 && ((flag_smoke==0 && pole[str][stlb] != 6 && pole[str][stlb] != 8) || (flag_smoke == 1)))
    {
        flag = 2;
        if (pole[str][stlb] == 9) {
            mina_ten(my_pole, str, stlb, count_b,1);
            pole[str][stlb] = 10;
            flag = 1;
            if (count_b[0] == 10) {
                printf("Все корабли потоплены");
                return bot_win;
            }
        }
        if (pole[str][stlb] == 1)
        {
            printf("Убит!\n");
            count_chel++;
            pole[str][stlb] = 8;
            if (count_chel == 10) return chel_win;
        }
        if (pole[str][stlb] == 2)
        {
            pole[str][stlb] = 8;
            if (pole[str][stlb - 1] != 2 && pole[str][stlb + 1] != 2 && pole[str - 1][stlb] != 2 && pole[str + 1][stlb] != 2)
            {
                count_chel++;
                printf("Убит!\n");
                if (count_chel == 10) return chel_win;
            }
            else
                printf("Ранен!\n");
        }
        if (pole[str][stlb] == 3)
        {
            pole[str][stlb] = 8;
            if (pole[str][stlb - 1] != 3 && pole[str][stlb + 1] != 3 && pole[str - 1][stlb] != 3 && pole[str + 1][stlb] != 3)
            {
                if (pole[str][stlb - 1] == 8)
                {
                    if (pole[str][stlb - 2] == 8)
                    {
                        count_chel++;
                        printf("Убит!\n");
                        if (count_chel == 10) return chel_win;
                    }
                    if (pole[str][stlb - 2] == 8)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole[str][stlb + 1] == 8)
                {
                    if (pole[str][stlb + 2] == 8)
                    {
                        count_chel++;
                        printf("Убит!\n");
                        if (count_chel == 10) return chel_win;
                    }
                    if (pole[str][stlb + 2] == 3)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole[str - 1][stlb] == 8)
                {
                    if (pole[str - 2][stlb] == 8)
                    {
                        count_chel++;
                        printf("Убит!\n");
                        if (count_chel == 10) return chel_win;
                    }
                    if (pole[str - 2][stlb] == 8)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole[str + 1][stlb] == 8)
                {
                    if (pole[str + 2][stlb] == 8)
                    {
                        count_chel++;
                        printf("Убит!\n");
                        if (count_chel == 10) return chel_win;
                    }
                    if (pole[str + 2][stlb] == 3)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole[str + 1][stlb] == 8 && pole[str - 1][stlb] == 8)
                {
                    count_chel++;
                    printf("Убит!\n");
                    if (count_chel == 10) return chel_win;
                }
                if (pole[str][stlb + 1] == 8 && pole[str][stlb - 1] == 8)
                {
                    count_chel++;
                    printf("Убит!\n");
                    if (count_chel == 10) return chel_win;
                }
            }
            else
                printf("Ранен!\n");
        }
        if (pole[str][stlb] == 4)
        {
            pole[str][stlb] = 8;
            if (pole[str][stlb - 1] != 4 && pole[str][stlb - 2] != 4 && pole[str][stlb - 3] != 4 && pole[str][stlb + 1] != 4 &&
                pole[str][stlb + 2] != 4 && pole[str][stlb + 3] != 4 && pole[str - 2][stlb] != 4 && pole[str - 1][stlb] != 4 && pole[str - 3][stlb] != 4 &&
                pole[str + 2][stlb] != 4 && pole[str + 3][stlb] != 4 && pole[str + 1][stlb] != 4)
            {
                count_chel++;
                printf("Убит!\n");
                if (count_chel == 10) return chel_win;
            }
            else
                printf("Ранен!\n");
        }
        if (pole[str][stlb] == 0 || pole[str][stlb] == 7)
        {
            flag = 1;
            printf("Мимо!\n");
            pole[str][stlb] = 6;
        }
        if (flag_smoke == 1 && (pole[str][stlb] == 6 || pole[str][stlb] == 7 || pole[str][stlb] == 8)) {
            flag = 1;
        }
    }
   /* printf("\n\n\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4 && my_pole[i][j] != 6 && my_pole[i][j] != 7 && my_pole[i][j] != 8)
                my_pole[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", my_pole[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4 && pole[i][j] != 6 && pole[i][j] != 7 && pole[i][j] != 8)
                pole[i][j] = 0;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", pole[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");*/
    count[0] = count_chel;
    if (flag == 0)  return hod_chel;
    count_hod[0] = count_hod[0] + 1;
    if (flag == 1) return hod_bot;
    else return hod_chel;
}

int chel_attack_fi(int pole[15][15], int my_pole[15][15], int* count, int* count_b, int grid_x, int grid_y, int* count_hod, int flag_smoke) {
    int count_chel = count[0];
    if (count_chel == 11) {
        printf("Все корабли потоплены");
        return chel_win;
    }

    int str = grid_y;
    int stlb = grid_x;
    int flag = 0;
    printf("Xoд:\n");
    if (str <= 14 && stlb <= 14 && str >= 0 && stlb >= 0 && ((flag_smoke == 0 && pole[str][stlb] != 6 && pole[str][stlb] != 8) || (flag_smoke == 1)))
    {
        flag = 2;
        if (pole[str][stlb] == 9) {
            mina_fi(my_pole, str, stlb, count_b,1);
            pole[str][stlb] = 10;
            flag = 1;
            if (count_b[0] == 11) {
                printf("Все корабли потоплены");
                return bot_win;
            }
        }
        if (pole[str][stlb] == 1) 
        {
            printf("Убит!\n");
            count_chel++;
            pole[str][stlb] = 8;
            if (count_chel == 11) return chel_win;
        }
        if (pole[str][stlb] == 2)
        {
            pole[str][stlb] = 8;
            if (pole[str][stlb - 1] != 2 && pole[str][stlb + 1] != 2 && pole[str - 1][stlb] != 2 && pole[str + 1][stlb] != 2)
            {
                count_chel++;
                printf("Убит!\n");
                if (count_chel == 11) return chel_win;
            }
            else
                printf("Ранен!\n");
        }
        if (pole[str][stlb] == 3)
        {
            pole[str][stlb] = 8;
            if (pole[str][stlb - 1] != 3 && pole[str][stlb + 1] != 3 && pole[str - 1][stlb] != 3 && pole[str + 1][stlb] != 3)
            {
                if (pole[str][stlb - 1] == 8)
                {
                    if (pole[str][stlb - 2] == 8)
                    {
                        count_chel++;
                        printf("Убит!\n");
                        if (count_chel == 10) return chel_win;
                    }
                    if (pole[str][stlb - 2] == 8)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole[str][stlb + 1] == 8)
                {
                    if (pole[str][stlb + 2] == 8)
                    {
                        count_chel++;
                        printf("Убит!\n");
                        if (count_chel == 10) return chel_win;
                    }
                    if (pole[str][stlb + 2] == 3)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole[str - 1][stlb] == 8)
                {
                    if (pole[str - 2][stlb] == 8)
                    {
                        count_chel++;
                        printf("Убит!\n");
                        if (count_chel == 10) return chel_win;
                    }
                    if (pole[str - 2][stlb] == 8)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole[str + 1][stlb] == 8)
                {
                    if (pole[str + 2][stlb] == 8)
                    {
                        count_chel++;
                        printf("Убит!\n");
                        if (count_chel == 10) return chel_win;
                    }
                    if (pole[str + 2][stlb] == 3)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole[str + 1][stlb] == 8 && pole[str - 1][stlb] == 8)
                {
                    count_chel++;
                    printf("Убит!\n");
                    if (count_chel == 10) return chel_win;
                }
                if (pole[str][stlb + 1] == 8 && pole[str][stlb - 1] == 8)
                {
                    count_chel++;
                    printf("Убит!\n");
                    if (count_chel == 10) return chel_win;
                }
            }
            else
                printf("Ранен!\n");
        }
        if (pole[str][stlb] == 4)
        {
            pole[str][stlb] = 8;
            if (pole[str][stlb - 1] != 4 && pole[str][stlb - 2] != 4 && pole[str][stlb - 3] != 4 && pole[str][stlb + 1] != 4 && pole[str][stlb + 2] != 4 &&
                pole[str][stlb + 3] != 4 && pole[str - 2][stlb] != 4 && pole[str - 1][stlb] != 4 && pole[str - 3][stlb] != 4 && pole[str + 2][stlb] != 4 &&
                pole[str + 3][stlb] != 4 && pole[str + 1][stlb] != 4)
            {
                count_chel++;
                printf("Убит!\n");
                if (count_chel == 11) return chel_win;
            }
            else
                printf("Ранен!\n");
        }
        if (pole[str][stlb] == 5)
        {
            pole[str][stlb] = 8;
            if (pole[str][stlb - 1] != 5 && pole[str][stlb - 2] != 5 && pole[str][stlb - 3] != 5 && pole[str][stlb - 4] != 5 && pole[str][stlb + 1] != 5 && pole[str][stlb + 2] != 5 && pole[str][stlb + 3] != 5 && pole[str][stlb + 4] != 5 && pole[str - 2][stlb] != 5 && pole[str - 1][stlb] != 5 && pole[str - 3][stlb] != 5 && pole[str - 4][stlb] != 5 && pole[str + 2][stlb] != 5 && pole[str + 3][stlb] != 5 && pole[str + 1][stlb] != 5 && pole[str + 4][stlb] != 5)
            {
                count_chel++;
                printf("Убит!\n");
                if (count_chel == 11) return chel_win;
            }
            else
                printf("Ранен!\n");
        }
        if (pole[str][stlb] == 0 || pole[str][stlb] == 7)
        {
            flag = 1;
            printf("Мимо!\n");
            pole[str][stlb] = 6;
        }
        if (flag_smoke == 1 && (pole[str][stlb] == 0 || pole[str][stlb] == 7 || pole[str][stlb] == 8)) {
            flag = 1;
        }
    }
   /* printf("\n\n\n");
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (my_pole[i][j] != 1 && my_pole[i][j] != 2 && my_pole[i][j] != 3 && my_pole[i][j] != 4 && my_pole[i][j] != 6 && my_pole[i][j] != 7 && my_pole[i][j] != 5 && my_pole[i][j] != 8)
                my_pole[i][j] = 0;
        }
    }
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            printf("%d ", my_pole[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (pole[i][j] != 1 && pole[i][j] != 2 && pole[i][j] != 3 && pole[i][j] != 4 && pole[i][j] != 6 && pole[i][j] != 7 && pole[i][j] != 5 && pole[i][j] != 8)
                pole[i][j] = 0;
        }
    }
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            printf("%d ", pole[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");*/
    count[0] = count_chel;
    if (flag == 0) return hod_chel;
    count_hod[0] = count_hod[0] + 1;
    if (flag == 2) return hod_chel;
    if (flag == 1) return hod_bot;
}

//легкий
int game_chel_komp_ten(int my_pole[10][10], int pole[10][10], int* count, int* count_b, int* radar_count, int grid_x, int grid_y, int flag_start_attack_bot, int* count_hod, int flag_smoke)
{
    //атака человека
    if (flag_start_attack_bot == 0) {
        return chel_attack_ten(pole, my_pole, count, count_b, grid_x, grid_y, count_hod, flag_smoke);
    }
        //атака компа
    if (flag_start_attack_bot) {
       return easy_bot_ten(my_pole, pole, count_b, count, radar_count, 1);
    }
}

int game_chel_komp_fi(int my_pole[15][15], int pole[15][15], int* count, int* count_b, int* radar_count, int grid_x, int grid_y, int flag_start_attack_bot, int* count_hod, int flag_smoke)
{
    int count_chel = count[0];
    int count_rob = count_b[0];
    if (flag_start_attack_bot == 0) {
        return chel_attack_fi(pole, my_pole, count, count_b, grid_x, grid_y, count_hod, flag_smoke);
    }
    if(flag_start_attack_bot==1){
        return easy_bot_fi(my_pole, pole, count_b, count, radar_count, 1);
    }
}
//------------------------------------------------------------------------------------------------------------------//

//int otsl = -1;
//средний
void strel_med_game_chel_komp_ten(int i, int* str, int* stlb)
{
    switch (i)
    {
        // Новый первый выстрел в центр (E5)
    case 0:
        *str = 4;
        *stlb = 4;
        break;

        // Оригинальные ваши координаты со сдвигом индексов +1
    case 1:
        *str = 0;
        *stlb = 0;
        break; // Ваш case 0 ? теперь case 1
    case 2:
        *str = 0;
        *stlb = 2;
        break; // Ваш case 1 ? теперь case 2
    case 3:
        *str = 0;
        *stlb = 4;
        break; // Ваш case 2 ? теперь case 3
    case 4:
        *str = 2;
        *stlb = 0;
        break;
    case 5:
        *str = 2;
        *stlb = 2;
        break;
    case 6:
        *str = 2;
        *stlb = 4;
        break;
    case 7:
        *str = 4;
        *stlb = 0;
        break;
    case 8:
        *str = 4;
        *stlb = 2;
        break;
    case 9:
        *str = 4;
        *stlb = 4;
        break;
    case 10:
        *str = 5;
        *stlb = 6;
        break;
    case 11:
        *str = 5;
        *stlb = 8;
        break;
    case 12:
        *str = 7;
        *stlb = 6;
        break;
    case 13:
        *str = 7;
        *stlb = 8;
        break;
    case 14:
        *str = 9;
        *stlb = 6;
        break;
    case 15:
        *str = 9;
        *stlb = 8;
        break;
    case 16:
        *str = 5;
        *stlb = 0;
        break;
    case 17:
        *str = 5;
        *stlb = 2;
        break;
    case 18:
        *str = 5;
        *stlb = 4;
        break;
    case 19:
        *str = 7;
        *stlb = 0;
        break;
    case 20:
        *str = 7;
        *stlb = 2;
        break;
    case 21:
        *str = 7;
        *stlb = 4;
        break;
    case 22:
        *str = 9;
        *stlb = 0;
        break;
    case 23:
        *str = 9;
        *stlb = 2;
        break;
    case 24:
        *str = 9;
        *stlb = 4;
        break;
    case 25:
        *str = 0;
        *stlb = 6;
        break;
    case 26:
        *str = 0;
        *stlb = 8;
        break;
    case 27:
        *str = 2;
        *stlb = 6;
        break;
    case 28:
        *str = 2;
        *stlb = 8;
        break;
    case 29:
        *str = 4;
        *stlb = 6;
        break;
    case 30:
        *str = 4;
        *stlb = 8;
        break;
    case 31:
        *str = 1;
        *stlb = 1;
        break;
    case 32:
        *str = 1;
        *stlb = 3;
        break;
    case 33:
        *str = 3;
        *stlb = 1;
        break;
    case 34:
        *str = 3;
        *stlb = 3;
        break;
    case 35:
        *str = 6;
        *stlb = 5;
        break;
    case 36:
        *str = 6;
        *stlb = 7;
        break;
    case 37:
        *str = 6;
        *stlb = 9;
        break;
    case 38:
        *str = 8;
        *stlb = 5;
        break;
    case 39:
        *str = 8;
        *stlb = 7;
        break;
    case 40:
        *str = 8;
        *stlb = 9;
        break;
    case 41:
        *str = 6;
        *stlb = 1;
        break;
    case 42:
        *str = 6;
        *stlb = 3;
        break;
    case 43:
        *str = 8;
        *stlb = 1;
        break;
    case 44:
        *str = 8;
        *stlb = 3;
        break;
    case 45:
        *str = 1;
        *stlb = 5;
        break;
    case 46:
        *str = 1;
        *stlb = 7;
        break;
    case 47:
        *str = 1;
        *stlb = 9;
        break;
    case 48:
        *str = 3;
        *stlb = 5;
        break;
    case 49:
        *str = 3;
        *stlb = 7;
        break;
    case 50:
        *str = 3;
        *stlb = 9;
        break;
    case 51:
        *str = 0;
        *stlb = 1;
        break;
    case 52:
        *str = 0;
        *stlb = 3;
        break;
    case 53:
        *str = 2;
        *stlb = 1;
        break;
    case 54:
        *str = 2;
        *stlb = 3;
        break;
    case 55:
        *str = 4;
        *stlb = 1;
        break;
    case 56:
        *str = 4;
        *stlb = 3;
        break;
    case 57:
        *str = 5;
        *stlb = 5;
        break;
    case 58:
        *str = 5;
        *stlb = 7;
        break;
    case 59:
        *str = 5;
        *stlb = 9;
        break;
    case 60:
        *str = 7;
        *stlb = 5;
        break;
    case 61:
        *str = 7;
        *stlb = 7;
        break;
    case 62:
        *str = 7;
        *stlb = 9;
        break;
    case 63:
        *str = 9;
        *stlb = 5;
        break;
    case 64:
        *str = 9;
        *stlb = 7;
        break;
    case 65:
        *str = 9;
        *stlb = 9;
        break;
    case 66:
        *str = 5;
        *stlb = 1;
        break;
    case 67:
        *str = 5;
        *stlb = 3;
        break;
    case 68:
        *str = 7;
        *stlb = 1;
        break;
    case 69:
        *str = 7;
        *stlb = 3;
        break;
    case 70:
        *str = 9;
        *stlb = 1;
        break;
    case 71:
        *str = 9;
        *stlb = 3;
        break;
    case 72:
        *str = 0;
        *stlb = 5;
        break;
    case 73:
        *str = 0;
        *stlb = 7;
        break;
    case 74:
        *str = 0;
        *stlb = 9;
        break;
    case 75:
        *str = 2;
        *stlb = 5;
        break;
    case 76:
        *str = 2;
        *stlb = 7;
        break;
    case 77:
        *str = 2;
        *stlb = 9;
        break;
    case 78:
        *str = 4;
        *stlb = 5;
        break;
    case 79:
        *str = 4;
        *stlb = 7;
        break;
    case 80:
        *str = 4;
        *stlb = 9;
        break;
    case 81:
        *str = 1;
        *stlb = 0;
        break;
    case 82:
        *str = 1;
        *stlb = 2;
        break;
    case 83:
        *str = 1;
        *stlb = 4;
        break;
    case 84:
        *str = 3;
        *stlb = 0;
        break;
    case 85:
        *str = 3;
        *stlb = 2;
        break;
    case 86:
        *str = 3;
        *stlb = 4;
        break;
    case 87:
        *str = 6;
        *stlb = 6;
        break;
    case 88:
        *str = 6;
        *stlb = 8;
        break;
    case 89:
        *str = 8;
        *stlb = 6;
        break;
    case 90:
        *str = 8;
        *stlb = 8;
        break;
    case 91:
        *str = 6;
        *stlb = 0;
        break;
    case 92:
        *str = 6;
        *stlb = 2;
        break;
    case 93:
        *str = 6;
        *stlb = 4;
        break;
    case 94:
        *str = 8;
        *stlb = 0;
        break;
    case 95:
        *str = 8;
        *stlb = 2;
        break;
    case 96:
        *str = 8;
        *stlb = 4;
        break;
    case 97:
        *str = 1;
        *stlb = 6;
        break;
    case 98:
        *str = 1;
        *stlb = 8;
        break;
    case 99:
        *str = 3;
        *stlb = 6;
        break;

        // Если индекс выходит за пределы, можно добавить рандом
    default:
        *str = rand() % 10;
        *stlb = rand() % 10;
        break;
    }
}
int game_medi_chel_komp_ten(int my_pole[10][10], int pole[10][10], int *otsl_bot_1, int* otsl_bot_2, int* count, int* count_b, int* radar_count, int grid_x, int grid_y, int flag_start_attack_bot, int* count_hod, int flag_smoke)
{
    int count_rob = count_b[0];
        if (flag_start_attack_bot == 0) {
            return chel_attack_ten(pole, my_pole, count, count_b, grid_x, grid_y, count_hod, flag_smoke);
        }
        if (flag_start_attack_bot) {
            return medi_bot_ten(my_pole, pole, otsl_bot_1, otsl_bot_2,count_b, count, radar_count, 1, 1);
        }
}

void strel_med_game_chel_komp_fif(int i, int* str, int* stlb)
{
    switch (i)
    {
    case 0:
        *str = 7;
        *stlb = 7;
        break;
    case 1:
        *str = 0;
        *stlb = 0;
        break;
    case 2:
        *str = 0;
        *stlb = 2;
        break;
    case 3:
        *str = 0;
        *stlb = 4;
        break;
    case 4:
        *str = 0;
        *stlb = 6;
        break;
    case 5:
        *str = 2;
        *stlb = 0;
        break;
    case 6:
        *str = 2;
        *stlb = 2;
        break;
    case 7:
        *str = 2;
        *stlb = 4;
        break;
    case 8:
        *str = 2;
        *stlb = 6;
        break;
    case 9:
        *str = 4;
        *stlb = 0;
        break;
    case 10:
        *str = 4;
        *stlb = 2;
        break;
    case 11:
        *str = 4;
        *stlb = 4;
        break;
    case 12:
        *str = 4;
        *stlb = 6;
        break;
    case 13:
        *str = 6;
        *stlb = 0;
        break;
    case 14:
        *str = 6;
        *stlb = 2;
        break;
    case 15:
        *str = 6;
        *stlb = 4;
        break;
    case 16:
        *str = 6;
        *stlb = 6;
        break;
    case 17:
        *str = 8;
        *stlb = 0;
        break;
    case 18:
        *str = 8;
        *stlb = 2;
        break;
    case 19:
        *str = 8;
        *stlb = 4;
        break;
    case 20:
        *str = 8;
        *stlb = 6;
        break;
    case 21:
        *str = 10;
        *stlb = 0;
        break;
    case 22:
        *str = 10;
        *stlb = 2;
        break;
    case 23:
        *str = 10;
        *stlb = 4;
        break;
    case 24:
        *str = 10;
        *stlb = 6;
        break;
    case 25:
        *str = 12;
        *stlb = 0;
        break;
    case 26:
        *str = 12;
        *stlb = 2;
        break;
    case 27:
        *str = 12;
        *stlb = 4;
        break;
    case 28:
        *str = 12;
        *stlb = 6;
        break;
    case 29:
        *str = 14;
        *stlb = 0;
        break;
    case 30:
        *str = 14;
        *stlb = 2;
        break;
    case 31:
        *str = 14;
        *stlb = 4;
        break;
    case 32:
        *str = 14;
        *stlb = 6;
        break;
    case 33:
        *str = 0;
        *stlb = 8;
        break;
    case 34:
        *str = 0;
        *stlb = 10;
        break;
    case 35:
        *str = 0;
        *stlb = 12;
        break;
    case 36:
        *str = 0;
        *stlb = 14;
        break;
    case 37:
        *str = 2;
        *stlb = 8;
        break;
    case 38:
        *str = 2;
        *stlb = 10;
        break;
    case 39:
        *str = 2;
        *stlb = 12;
        break;
    case 40:
        *str = 2;
        *stlb = 14;
        break;
    case 41:
        *str = 4;
        *stlb = 8;
        break;
    case 42:
        *str = 4;
        *stlb = 10;
        break;
    case 43:
        *str = 4;
        *stlb = 12;
        break;
    case 44:
        *str = 4;
        *stlb = 14;
        break;
    case 45:
        *str = 6;
        *stlb = 8;
        break;
    case 46:
        *str = 6;
        *stlb = 10;
        break;
    case 47:
        *str = 6;
        *stlb = 12;
        break;
    case 48:
        *str = 6;
        *stlb = 14;
        break;
    case 49:
        *str = 8;
        *stlb = 8;
        break;
    case 50:
        *str = 8;
        *stlb = 10;
        break;
    case 51:
        *str = 8;
        *stlb = 12;
        break;
    case 52:
        *str = 8;
        *stlb = 14;
        break;
    case 53:
        *str = 10;
        *stlb = 8;
        break;
    case 54:
        *str = 10;
        *stlb = 10;
        break;
    case 55:
        *str = 10;
        *stlb = 12;
        break;
    case 56:
        *str = 10;
        *stlb = 14;
        break;
    case 57:
        *str = 12;
        *stlb = 8;
        break;
    case 58:
        *str = 12;
        *stlb = 10;
        break;
    case 59:
        *str = 12;
        *stlb = 12;
        break;
    case 60:
        *str = 12;
        *stlb = 14;
        break;
    case 61:
        *str = 14;
        *stlb = 8;
        break;
    case 62:
        *str = 14;
        *stlb = 10;
        break;
    case 63:
        *str = 14;
        *stlb = 12;
        break;
    case 64:
        *str = 14;
        *stlb = 14;
        break;
    case 65:
        *str = 1;
        *stlb = 1;
        break;
    case 66:
        *str = 1;
        *stlb = 3;
        break;
    case 67:
        *str = 1;
        *stlb = 5;
        break;
    case 68:
        *str = 1;
        *stlb = 7;
        break;
    case 69:
        *str = 3;
        *stlb = 1;
        break;
    case 70:
        *str = 3;
        *stlb = 3;
        break;
    case 71:
        *str = 3;
        *stlb = 5;
        break;
    case 72:
        *str = 3;
        *stlb = 7;
        break;
    case 73:
        *str = 5;
        *stlb = 1;
        break;
    case 74:
        *str = 5;
        *stlb = 3;
        break;
    case 75:
        *str = 5;
        *stlb = 5;
        break;
    case 76:
        *str = 5;
        *stlb = 7;
        break;
    case 77:
        *str = 7;
        *stlb = 1;
        break;
    case 78:
        *str = 7;
        *stlb = 3;
        break;
    case 79:
        *str = 7;
        *stlb = 5;
        break;
    case 80:
        *str = 7;
        *stlb = 7;
        break;
    case 81:
        *str = 9;
        *stlb = 1;
        break;
    case 82:
        *str = 9;
        *stlb = 3;
        break;
    case 83:
        *str = 9;
        *stlb = 5;
        break;
    case 84:
        *str = 9;
        *stlb = 7;
        break;
    case 85:
        *str = 11;
        *stlb = 1;
        break;
    case 86:
        *str = 11;
        *stlb = 3;
        break;
    case 87:
        *str = 11;
        *stlb = 5;
        break;
    case 88:
        *str = 11;
        *stlb = 7;
        break;
    case 89:
        *str = 13;
        *stlb = 1;
        break;
    case 90:
        *str = 13;
        *stlb = 3;
        break;
    case 91:
        *str = 13;
        *stlb = 5;
        break;
    case 92:
        *str = 13;
        *stlb = 7;
        break;
    case 93:
        *str = 1;
        *stlb = 9;
        break;
    case 94:
        *str = 1;
        *stlb = 11;
        break;
    case 95:
        *str = 1;
        *stlb = 13;
        break;
    case 96:
        *str = 3;
        *stlb = 9;
        break;
    case 97:
        *str = 3;
        *stlb = 11;
        break;
    case 98:
        *str = 3;
        *stlb = 13;
        break;
    case 99:
        *str = 5;
        *stlb = 9;
        break;
    case 100:
        *str = 5;
        *stlb = 11;
        break;
    case 101:
        *str = 5;
        *stlb = 13;
        break;
    case 102:
        *str = 7;
        *stlb = 9;
        break;
    case 103:
        *str = 7;
        *stlb = 11;
        break;
    case 104:
        *str = 7;
        *stlb = 13;
        break;
    case 105:
        *str = 9;
        *stlb = 9;
        break;
    case 106:
        *str = 9;
        *stlb = 11;
        break;
    case 107:
        *str = 9;
        *stlb = 13;
        break;
    case 108:
        *str = 11;
        *stlb = 9;
        break;
    case 109:
        *str = 11;
        *stlb = 11;
        break;
    case 110:
        *str = 11;
        *stlb = 13;
        break;
    case 111:
        *str = 13;
        *stlb = 9;
        break;
    case 112:
        *str = 13;
        *stlb = 11;
        break;
    case 113:
        *str = 13;
        *stlb = 13;
        break;
    case 114:
        *str = 0;
        *stlb = 1;
        break;
    case 115:
        *str = 0;
        *stlb = 3;
        break;
    case 116:
        *str = 0;
        *stlb = 5;
        break;
    case 117:
        *str = 0;
        *stlb = 7;
        break;
    case 118:
        *str = 2;
        *stlb = 1;
        break;
    case 119:
        *str = 2;
        *stlb = 3;
        break;
    case 120:
        *str = 2;
        *stlb = 5;
        break;
    case 121:
        *str = 2;
        *stlb = 7;
        break;
    case 122:
        *str = 4;
        *stlb = 1;
        break;
    case 123:
        *str = 4;
        *stlb = 3;
        break;
    case 124:
        *str = 4;
        *stlb = 5;
        break;
    case 125:
        *str = 4;
        *stlb = 7;
        break;
    case 126:
        *str = 6;
        *stlb = 1;
        break;
    case 127:
        *str = 6;
        *stlb = 3;
        break;
    case 128:
        *str = 6;
        *stlb = 5;
        break;
    case 129:
        *str = 6;
        *stlb = 7;
        break;
    case 130:
        *str = 8;
        *stlb = 1;
        break;
    case 131:
        *str = 8;
        *stlb = 3;
        break;
    case 132:
        *str = 8;
        *stlb = 5;
        break;
    case 133:
        *str = 8;
        *stlb = 7;
        break;
    case 134:
        *str = 10;
        *stlb = 1;
        break;
    case 135:
        *str = 10;
        *stlb = 3;
        break;
    case 136:
        *str = 10;
        *stlb = 5;
        break;
    case 137:
        *str = 10;
        *stlb = 7;
        break;
    case 138:
        *str = 12;
        *stlb = 1;
        break;
    case 139:
        *str = 12;
        *stlb = 3;
        break;
    case 140:
        *str = 12;
        *stlb = 5;
        break;
    case 141:
        *str = 12;
        *stlb = 7;
        break;
    case 142:
        *str = 14;
        *stlb = 1;
        break;
    case 143:
        *str = 14;
        *stlb = 3;
        break;
    case 144:
        *str = 14;
        *stlb = 5;
        break;
    case 145:
        *str = 14;
        *stlb = 7;
        break;
    case 146:
        *str = 0;
        *stlb = 9;
        break;
    case 147:
        *str = 0;
        *stlb = 11;
        break;
    case 148:
        *str = 0;
        *stlb = 13;
        break;
    case 149:
        *str = 2;
        *stlb = 9;
        break;
    case 150:
        *str = 2;
        *stlb = 11;
        break;
    case 151:
        *str = 2;
        *stlb = 13;
        break;
    case 152:
        *str = 4;
        *stlb = 9;
        break;
    case 153:
        *str = 4;
        *stlb = 11;
        break;
    case 154:
        *str = 4;
        *stlb = 13;
        break;
    case 155:
        *str = 6;
        *stlb = 9;
        break;
    case 156:
        *str = 6;
        *stlb = 11;
        break;
    case 157:
        *str = 6;
        *stlb = 13;
        break;
    case 158:
        *str = 8;
        *stlb = 9;
        break;
    case 159:
        *str = 8;
        *stlb = 11;
        break;
    case 160:
        *str = 8;
        *stlb = 13;
        break;
    case 161:
        *str = 10;
        *stlb = 9;
        break;
    case 162:
        *str = 10;
        *stlb = 11;
        break;
    case 163:
        *str = 10;
        *stlb = 13;
        break;
    case 164:
        *str = 12;
        *stlb = 9;
        break;
    case 165:
        *str = 12;
        *stlb = 11;
        break;
    case 166:
        *str = 12;
        *stlb = 13;
        break;
    case 167:
        *str = 14;
        *stlb = 9;
        break;
    case 168:
        *str = 14;
        *stlb = 11;
        break;
    case 169:
        *str = 14;
        *stlb = 13;
        break;
    case 170:
        *str = 1;
        *stlb = 0;
        break;
    case 171:
        *str = 1;
        *stlb = 2;
        break;
    case 172:
        *str = 1;
        *stlb = 4;
        break;
    case 173:
        *str = 1;
        *stlb = 6;
        break;
    case 174:
        *str = 3;
        *stlb = 0;
        break;
    case 175:
        *str = 3;
        *stlb = 2;
        break;
    case 176:
        *str = 3;
        *stlb = 4;
        break;
    case 177:
        *str = 3;
        *stlb = 6;
        break;
    case 178:
        *str = 5;
        *stlb = 0;
        break;

    case 179:
        *str = 5;
        *stlb = 2;
        break;
    case 180:
        *str = 5;
        *stlb = 4;
        break;
    case 181:
        *str = 5;
        *stlb = 6;
        break;
    case 182:
        *str = 7;
        *stlb = 0;
        break;
    case 183:
        *str = 7;
        *stlb = 2;
        break;
    case 184:
        *str = 7;
        *stlb = 4;
        break;
    case 185:
        *str = 7;
        *stlb = 6;
        break;
    case 186:
        *str = 9;
        *stlb = 0;
        break;
    case 187:
        *str = 9;
        *stlb = 2;
        break;
    case 188:
        *str = 9;
        *stlb = 4;
        break;
    case 189:
        *str = 9;
        *stlb = 6;
        break;
    case 190:
        *str = 11;
        *stlb = 0;
        break;
    case 191:
        *str = 11;
        *stlb = 2;
        break;
    case 192:
        *str = 11;
        *stlb = 4;
        break;
    case 193:
        *str = 11;
        *stlb = 6;
        break;
    case 194:
        *str = 13;
        *stlb = 0;
        break;
    case 195:
        *str = 13;
        *stlb = 2;
        break;
    case 196:
        *str = 13;
        *stlb = 4;
        break;
    case 197:
        *str = 13;
        *stlb = 6;
        break;
    case 198:
        *str = 1;
        *stlb = 8;
        break;
    case 199:
        *str = 1;
        *stlb = 10;
        break;
    case 200:
        *str = 1;
        *stlb = 12;
        break;
    case 201:
        *str = 1;
        *stlb = 14;
        break;
    case 202:
        *str = 3;
        *stlb = 8;
        break;
    case 203:
        *str = 3;
        *stlb = 10;
        break;
    case 204:
        *str = 3;
        *stlb = 12;
        break;
    case 205:
        *str = 3;
        *stlb = 14;
        break;
    case 206:
        *str = 5;
        *stlb = 8;
        break;
    case 207:
        *str = 5;
        *stlb = 10;
        break;
    case 208:
        *str = 5;
        *stlb = 12;
        break;
    case 209:
        *str = 5;
        *stlb = 14;
        break;
    case 210:
        *str = 7;
        *stlb = 8;
        break;
    case 211:
        *str = 7;
        *stlb = 10;
        break;
    case 212:
        *str = 7;
        *stlb = 12;
        break;
    case 213:
        *str = 7;
        *stlb = 14;
        break;
    case 214:
        *str = 9;
        *stlb = 8;
        break;
    case 215:
        *str = 9;
        *stlb = 10;
        break;
    case 216:
        *str = 9;
        *stlb = 12;
        break;
    case 217:
        *str = 9;
        *stlb = 14;
        break;
    case 218:
        *str = 11;
        *stlb = 8;
        break;
    case 219:
        *str = 11;
        *stlb = 10;
        break;
    case 220:
        *str = 11;
        *stlb = 12;
        break;
    case 221:
        *str = 11;
        *stlb = 14;
        break;
    case 222:
        *str = 13;
        *stlb = 8;
        break;
    case 223:
        *str = 13;
        *stlb = 10;
        break;
    case 224:
        *str = 13;
        *stlb = 12;
        break;
    case 225:
        *str = 13;
        *stlb = 14;
        break;
    }
}
int game_medi_chel_komp_fif(int my_pole[15][15], int pole[15][15], int* otsl_bot_1, int* otsl_bot_2, int* count, int* count_b, int* radar_count, int grid_x, int grid_y, int flag_start_attack_bot, int* count_hod, int flag_smoke)
{
    if (flag_start_attack_bot == 0) {
        return chel_attack_fi(pole, my_pole, count, count_b, grid_x, grid_y, count_hod, flag_smoke);
    }
    if (flag_start_attack_bot == 1) {
        return medi_bot_fif(my_pole, pole, otsl_bot_1, otsl_bot_2, count_b, count, radar_count, 1, 1);
    }
}
//----------------------------------------------------------------------------------------------------------------------//

//сложный 
void strel_hard_game_chel_komp_ten(int i, int* str, int* stlb)
{
    switch (i)
    {
        // === Чётные клетки (50 штук) ===
        // Центр и ближайшие
    case 0:
        *str = 4;
        *stlb = 4;
        break; // E5 (центр)
    case 1:
        *str = 3;
        *stlb = 3;
        break; // D4
    case 2:
        *str = 3;
        *stlb = 5;
        break; // D6
    case 3:
        *str = 5;
        *stlb = 3;
        break; // F4
    case 4:
        *str = 5;
        *stlb = 5;
        break; // F6
    case 5:
        *str = 4;
        *stlb = 2;
        break; // E3
    case 6:
        *str = 4;
        *stlb = 6;
        break; // E7
    case 7:
        *str = 2;
        *stlb = 4;
        break; // C5
    case 8:
        *str = 6;
        *stlb = 4;
        break; // G5

        // Второй слой
    case 9:
        *str = 2;
        *stlb = 2;
        break; // C3
    case 10:
        *str = 2;
        *stlb = 6;
        break; // C7
    case 11:
        *str = 6;
        *stlb = 2;
        break; // G3
    case 12:
        *str = 6;
        *stlb = 6;
        break; // G7
    case 13:
        *str = 1;
        *stlb = 1;
        break; // B2
    case 14:
        *str = 1;
        *stlb = 3;
        break; // B4
    case 15:
        *str = 1;
        *stlb = 5;
        break; // B6
    case 16:
        *str = 1;
        *stlb = 7;
        break; // B8
    case 17:
        *str = 3;
        *stlb = 1;
        break; // D2
    case 18:
        *str = 3;
        *stlb = 7;
        break; // D8
    case 19:
        *str = 5;
        *stlb = 1;
        break; // F2
    case 20:
        *str = 5;
        *stlb = 7;
        break; // F8
    case 21:
        *str = 7;
        *stlb = 1;
        break; // H2
    case 22:
        *str = 7;
        *stlb = 3;
        break; // H4
    case 23:
        *str = 7;
        *stlb = 5;
        break; // H6
    case 24:
        *str = 7;
        *stlb = 7;
        break; // H8

        // Крайние чётные
    case 25:
        *str = 0;
        *stlb = 0;
        break; // A1
    case 26:
        *str = 0;
        *stlb = 2;
        break; // A3
    case 27:
        *str = 0;
        *stlb = 4;
        break; // A5
    case 28:
        *str = 0;
        *stlb = 6;
        break; // A7
    case 29:
        *str = 0;
        *stlb = 8;
        break; // A9
    case 30:
        *str = 2;
        *stlb = 0;
        break; // C1
    case 31:
        *str = 2;
        *stlb = 8;
        break; // C9
    case 32:
        *str = 4;
        *stlb = 0;
        break; // E1
    case 33:
        *str = 4;
        *stlb = 8;
        break; // E9
    case 34:
        *str = 6;
        *stlb = 0;
        break; // G1
    case 35:
        *str = 6;
        *stlb = 8;
        break; // G9
    case 36:
        *str = 8;
        *stlb = 0;
        break; // I1
    case 37:
        *str = 8;
        *stlb = 2;
        break; // I3
    case 38:
        *str = 8;
        *stlb = 4;
        break; // I5
    case 39:
        *str = 8;
        *stlb = 6;
        break; // I7
    case 40:
        *str = 8;
        *stlb = 8;
        break; // I9
    case 41:
        *str = 9;
        *stlb = 1;
        break; // J2
    case 42:
        *str = 9;
        *stlb = 3;
        break; // J4
    case 43:
        *str = 9;
        *stlb = 5;
        break; // J6
    case 44:
        *str = 9;
        *stlb = 7;
        break; // J8
    case 45:
        *str = 9;
        *stlb = 9;
        break; // J10

        // === Нечётные клетки (50 штук) ===
        // Центральные нечётные
    case 46:
        *str = 4;
        *stlb = 3;
        break; // E4
    case 47:
        *str = 4;
        *stlb = 5;
        break; // E6
    case 48:
        *str = 3;
        *stlb = 4;
        break; // D5
    case 49:
        *str = 5;
        *stlb = 4;
        break; // F5
    case 50:
        *str = 2;
        *stlb = 3;
        break; // C4
    case 51:
        *str = 2;
        *stlb = 5;
        break; // C6
    case 52:
        *str = 3;
        *stlb = 2;
        break; // D3
    case 53:
        *str = 3;
        *stlb = 6;
        break; // D7
    case 54:
        *str = 5;
        *stlb = 2;
        break; // F3
    case 55:
        *str = 5;
        *stlb = 6;
        break; // F7
    case 56:
        *str = 6;
        *stlb = 3;
        break; // G4
    case 57:
        *str = 6;
        *stlb = 5;
        break; // G6

        // Второй слой
    case 58:
        *str = 1;
        *stlb = 2;
        break; // B3
    case 59:
        *str = 1;
        *stlb = 4;
        break; // B5
    case 60:
        *str = 1;
        *stlb = 6;
        break; // B7
    case 61:
        *str = 2;
        *stlb = 1;
        break; // C2
    case 62:
        *str = 2;
        *stlb = 7;
        break; // C8
    case 63:
        *str = 4;
        *stlb = 1;
        break; // E2
    case 64:
        *str = 4;
        *stlb = 7;
        break; // E8
    case 65:
        *str = 6;
        *stlb = 1;
        break; // G2
    case 66:
        *str = 6;
        *stlb = 7;
        break; // G8
    case 67:
        *str = 7;
        *stlb = 2;
        break; // H3
    case 68:
        *str = 7;
        *stlb = 4;
        break; // H5
    case 69:
        *str = 7;
        *stlb = 6;
        break; // H7
    case 70:
        *str = 8;
        *stlb = 1;
        break; // I2
    case 71:
        *str = 8;
        *stlb = 3;
        break; // I4
    case 72:
        *str = 8;
        *stlb = 5;
        break; // I6
    case 73:
        *str = 8;
        *stlb = 7;
        break; // I8

        // Крайние нечётные
    case 74:
        *str = 0;
        *stlb = 1;
        break; // A2
    case 75:
        *str = 0;
        *stlb = 3;
        break; // A4
    case 76:
        *str = 0;
        *stlb = 5;
        break; // A6
    case 77:
        *str = 0;
        *stlb = 7;
        break; // A8
    case 78:
        *str = 0;
        *stlb = 9;
        break; // A10
    case 79:
        *str = 1;
        *stlb = 0;
        break; // B1
    case 80:
        *str = 1;
        *stlb = 8;
        break; // B9
    case 81:
        *str = 1;
        *stlb = 9;
        break; // B10
    case 82:
        *str = 3;
        *stlb = 0;
        break; // D1
    case 83:
        *str = 3;
        *stlb = 8;
        break; // D9
    case 84:
        *str = 3;
        *stlb = 9;
        break; // D10
    case 85:
        *str = 5;
        *stlb = 0;
        break; // F1
    case 86:
        *str = 5;
        *stlb = 8;
        break; // F9
    case 87:
        *str = 5;
        *stlb = 9;
        break; // F10
    case 88:
        *str = 7;
        *stlb = 0;
        break; // H1
    case 89:
        *str = 7;
        *stlb = 8;
        break; // H9
    case 90:
        *str = 7;
        *stlb = 9;
        break; // H10
    case 91:
        *str = 9;
        *stlb = 0;
        break; // J1
    case 92:
        *str = 9;
        *stlb = 2;
        break; // J3
    case 93:
        *str = 9;
        *stlb = 4;
        break; // J5
    case 94:
        *str = 9;
        *stlb = 6;
        break; // J7
    case 95:
        *str = 9;
        *stlb = 8;
        break; // J9

        // Оставшиеся нечётные (если что-то пропущено)
    case 96:
        *str = 2;
        *stlb = 9;
        break;
    case 97:
        *str = 4;
        *stlb = 9;
        break;
    case 98:
        *str = 6;
        *stlb = 9;
        break;
    case 99:
        *str = 8;
        *stlb = 9;
        break;
    }
}
int game_hard_chel_komp_ten(int my_pole[10][10], int pole[10][10], int* otsl_bot_1, int* otsl_bot_2, int* count, int* count_b, int* radar_count, int grid_x, int grid_y, int flag_start_attack_bot, int* count_hod, int flag_smoke)
{
    //атака человека
    if (flag_start_attack_bot == 0) {
        return chel_attack_ten(pole, my_pole, count, count_b, grid_x, grid_y, count_hod, flag_smoke);
    }
    //атака компа
    if (flag_start_attack_bot) {
        return hard_bot_ten(my_pole, pole, otsl_bot_1, otsl_bot_2, count_b, count, radar_count, 1, 1);
    }
}

void strel_hard_game_chel_komp_fif(int i, int* str, int* stlb)
{
    switch (i)
    {
        // === Чётные клетки (центр -> края) ===
        // Центр (H8)
    case 0:
        *str = 7;
        *stlb = 7;
        break; // Центр

        // Ближайшие к центру (чётные)
    case 1:
        *str = 6;
        *stlb = 6;
        break; // G7
    case 2:
        *str = 6;
        *stlb = 8;
        break; // G9
    case 3:
        *str = 8;
        *stlb = 6;
        break; // I7
    case 4:
        *str = 8;
        *stlb = 8;
        break; // I9
    case 5:
        *str = 7;
        *stlb = 5;
        break; // H6
    case 6:
        *str = 7;
        *stlb = 9;
        break; // H10
    case 7:
        *str = 5;
        *stlb = 7;
        break; // F8
    case 8:
        *str = 9;
        *stlb = 7;
        break; // J8
    case 9:
        *str = 5;
        *stlb = 5;
        break;
    case 10:
        *str = 9;
        *stlb = 5;
        break;
    case 11:
        *str = 5;
        *stlb = 9;
        break;
    case 12:
        *str = 9;
        *stlb = 9;
        break;

        // Следующий слой (чётные)

    case 13:
        *str = 4;
        *stlb = 4;
        break; // G6
    case 14:
        *str = 10;
        *stlb = 4;
        break; // G10
    case 15:
        *str = 4;
        *stlb = 10;
        break; // I6
    case 16:
        *str = 10;
        *stlb = 10;
        break; // I10
    case 17:
        *str = 4;
        *stlb = 6;
        break; // F7
    case 18:
        *str = 4;
        *stlb = 8;
        break; // F9
    case 19:
        *str = 10;
        *stlb = 6;
        break; // J7
    case 20:
        *str = 10;
        *stlb = 8;
        break; // J9

        // Продолжаем по спирали (чётные)
    case 21:
        *str = 6;
        *stlb = 4;
        break; // E5
    case 22:
        *str = 8;
        *stlb = 4;
        break; // E11
    case 23:
        *str = 6;
        *stlb = 10;
        break; // K5
    case 24:
        *str = 8;
        *stlb = 10;
        break; // K11
    case 25:
        *str = 3;
        *stlb = 3;
        break; // D4
    case 26:
        *str = 3;
        *stlb = 11;
        break; // D12
    case 27:
        *str = 11;
        *stlb = 3;
        break; // L4
    case 28:
        *str = 11;
        *stlb = 11;
        break; // L12
    case 29:
        *str = 7;
        *stlb = 3;
        break; // H4
    case 30:
        *str = 7;
        *stlb = 11;
        break; // H12
    case 31:
        *str = 3;
        *stlb = 7;
        break; // D8
    case 32:
        *str = 11;
        *stlb = 7;
        break; // L8
    case 33:
        *str = 5;
        *stlb = 3;
        break;
    case 34:
        *str = 9;
        *stlb = 3;
        break;
    case 35:
        *str = 11;
        *stlb = 5;
        break;
    case 36:
        *str = 11;
        *stlb = 9;
        break;
    case 37:
        *str = 9;
        *stlb = 11;
        break;
    case 38:
        *str = 5;
        *stlb = 11;
        break;
    case 39:
        *str = 3;
        *stlb = 5;
        break;
    case 40:
        *str = 3;
        *stlb = 9;
        break;
    case 41:
        *str = 2;
        *stlb = 2;
        break;
    case 42:
        *str = 12;
        *stlb = 2;
        break;
    case 43:
        *str = 12;
        *stlb = 12;
        break;
    case 44:
        *str = 2;
        *stlb = 12;
        break;
    case 45:
        *str = 4;
        *stlb = 2;
        break;
    case 46:
        *str = 2;
        *stlb = 4;
        break;
    case 47:
        *str = 6;
        *stlb = 2;
        break;
    case 48:
        *str = 2;
        *stlb = 6;
        break;
    case 49:
        *str = 8;
        *stlb = 2;
        break;
    case 50:
        *str = 2;
        *stlb = 8;
        break;
    case 51:
        *str = 10;
        *stlb = 2;
        break;
    case 52:
        *str = 2;
        *stlb = 10;
        break;
    case 53:
        *str = 12;
        *stlb = 4;
        break;
    case 54:
        *str = 4;
        *stlb = 12;
        break;
    case 55:
        *str = 12;
        *stlb = 6;
        break;
    case 56:
        *str = 6;
        *stlb = 12;
        break;
    case 57:
        *str = 12;
        *stlb = 8;
        break;
    case 58:
        *str = 8;
        *stlb = 12;
        break;
    case 59:
        *str = 12;
        *stlb = 10;
        break;
    case 60:
        *str = 10;
        *stlb = 12;
        break;
    case 61:
        *str = 1;
        *stlb = 1;
        break;
    case 62:
        *str = 13;
        *stlb = 1;
        break;
    case 63:
        *str = 13;
        *stlb = 13;
        break;
    case 64:
        *str = 1;
        *stlb = 13;
        break;
    case 65:
        *str = 3;
        *stlb = 1;
        break;
    case 66:
        *str = 5;
        *stlb = 1;
        break;
    case 67:
        *str = 7;
        *stlb = 1;
        break;
    case 68:
        *str = 9;
        *stlb = 1;
        break;
    case 69:
        *str = 11;
        *stlb = 1;
        break;
    case 70:
        *str = 1;
        *stlb = 3;
        break;
    case 71:
        *str = 13;
        *stlb = 3;
        break;
    case 72:
        *str = 1;
        *stlb = 5;
        break;
    case 73:
        *str = 13;
        *stlb = 5;
        break;
    case 74:
        *str = 1;
        *stlb = 7;
        break;
    case 75:
        *str = 13;
        *stlb = 7;
        break;
    case 76:
        *str = 1;
        *stlb = 9;
        break;
    case 77:
        *str = 13;
        *stlb = 9;
        break;
    case 78:
        *str = 1;
        *stlb = 11;
        break;
    case 79:
        *str = 13;
        *stlb = 11;
        break;
    case 80:
        *str = 3;
        *stlb = 13;
        break;
    case 81:
        *str = 5;
        *stlb = 13;
        break;
    case 82:
        *str = 7;
        *stlb = 13;
        break;
    case 83:
        *str = 9;
        *stlb = 13;
        break;
    case 84:
        *str = 11;
        *stlb = 13;
        break;
    case 85:
        *str = 0;
        *stlb = 0;
        break;
    case 86:
        *str = 14;
        *stlb = 0;
        break;
    case 87:
        *str = 14;
        *stlb = 14;
        break;
    case 88:
        *str = 0;
        *stlb = 14;
        break;
    case 89:
        *str = 2;
        *stlb = 0;
        break;
    case 90:
        *str = 0;
        *stlb = 2;
        break;
    case 91:
        *str = 4;
        *stlb = 0;
        break;
    case 92:
        *str = 0;
        *stlb = 4;
        break;
    case 93:
        *str = 6;
        *stlb = 0;
        break;
    case 94:
        *str = 0;
        *stlb = 6;
        break;
    case 95:
        *str = 8;
        *stlb = 0;
        break;
    case 96:
        *str = 0;
        *stlb = 8;
        break;
    case 97:
        *str = 10;
        *stlb = 0;
        break;
    case 98:
        *str = 0;
        *stlb = 10;
        break;
    case 99:
        *str = 12;
        *stlb = 0;
        break;
    case 100:
        *str = 0;
        *stlb = 12;
        break;
    case 101:
        *str = 14;
        *stlb = 2;
        break;
    case 102:
        *str = 2;
        *stlb = 14;
        break;
    case 103:
        *str = 14;
        *stlb = 4;
        break;
    case 104:
        *str = 4;
        *stlb = 14;
        break;
    case 105:
        *str = 14;
        *stlb = 6;
        break;
    case 106:
        *str = 6;
        *stlb = 14;
        break;
    case 107:
        *str = 14;
        *stlb = 8;
        break;
    case 108:
        *str = 8;
        *stlb = 14;
        break;
    case 109:
        *str = 10;
        *stlb = 14;
        break;
    case 110:
        *str = 14;
        *stlb = 10;
        break;
    case 111:
        *str = 14;
        *stlb = 12;
        break;
    case 112:
        *str = 12;
        *stlb = 14;
        break;

        // === Нечётные клетки ===
        // Центральные нечётные
    case 113:
        *str = 7;
        *stlb = 6;
        break; // H7 (нечётная сумма)
    case 114:
        *str = 7;
        *stlb = 8;
        break; // H9
    case 115:
        *str = 6;
        *stlb = 7;
        break; // G8
    case 116:
        *str = 8;
        *stlb = 7;
        break; // I8

        // Следующий слой (нечётные)
    case 117:
        *str = 5;
        *stlb = 6;
        break; // F7
    case 118:
        *str = 5;
        *stlb = 8;
        break; // F9
    case 119:
        *str = 9;
        *stlb = 6;
        break; // J7
    case 120:
        *str = 9;
        *stlb = 8;
        break; // J9
    case 121:
        *str = 6;
        *stlb = 5;
        break; // G6
    case 122:
        *str = 6;
        *stlb = 9;
        break; // G10
    case 123:
        *str = 8;
        *stlb = 5;
        break; // I6
    case 124:
        *str = 8;
        *stlb = 9;
        break; // I10
    case 125:
        *str = 5;
        *stlb = 4;
        break;
    case 126:
        *str = 4;
        *stlb = 5;
        break;
    case 127:
        *str = 4;
        *stlb = 9;
        break;
    case 128:
        *str = 9;
        *stlb = 4;
        break;
    case 129:
        *str = 4;
        *stlb = 7;
        break;
    case 130:
        *str = 7;
        *stlb = 4;
        break;
    case 131:
        *str = 10;
        *stlb = 5;
        break;
    case 132:
        *str = 5;
        *stlb = 10;
        break;
    case 133:
        *str = 8;
        *stlb = 9;
        break;
    case 134:
        *str = 7;
        *stlb = 10;
        break;
    case 135:
        *str = 10;
        *stlb = 7;
        break;
    case 136:
        *str = 9;
        *stlb = 10;
        break;
    case 137:
        *str = 10;
        *stlb = 9;
        break;
    case 138:
        *str = 4;
        *stlb = 3;
        break;
    case 139:
        *str = 3;
        *stlb = 4;
        break;
    case 140:
        *str = 5;
        *stlb = 2;
        break;
    case 141:
        *str = 2;
        *stlb = 5;
        break;
    case 142:
        *str = 6;
        *stlb = 3;
        break;
    case 143:
        *str = 3;
        *stlb = 6;
        break;
    case 144:
        *str = 2;
        *stlb = 7;
        break;
    case 145:
        *str = 7;
        *stlb = 2;
        break;
    case 146:
        *str = 14;
        *stlb = 9;
        break;
    case 147:
        *str = 8;
        *stlb = 3;
        break;
    case 148:
        *str = 3;
        *stlb = 8;
        break;
    case 149:
        *str = 3;
        *stlb = 10;
        break;
    case 150:
        *str = 10;
        *stlb = 3;
        break;
    case 151:
        *str = 2;
        *stlb = 9;
        break;
    case 152:
        *str = 9;
        *stlb = 2;
        break;
    case 153:
        *str = 4;
        *stlb = 11;
        break;
    case 154:
        *str = 11;
        *stlb = 4;
        break;
    case 155:
        *str = 11;
        *stlb = 6;
        break;
    case 156:
        *str = 6;
        *stlb = 11;
        break;
    case 157:
        *str = 8;
        *stlb = 11;
        break;
    case 158:
        *str = 11;
        *stlb = 8;
        break;
    case 159:
        *str = 11;
        *stlb = 2;
        break;
    case 160:
        *str = 2;
        *stlb = 11;
        break;
    case 161:
        *str = 11;
        *stlb = 10;
        break;
    case 162:
        *str = 10;
        *stlb = 11;
        break;
    case 163:
        *str = 3;
        *stlb = 2;
        break;
    case 164:
        *str = 2;
        *stlb = 3;
        break;
    case 165:
        *str = 1;
        *stlb = 2;
        break;
    case 166:
        *str = 2;
        *stlb = 1;
        break;
    case 167:
        *str = 4;
        *stlb = 1;
        break;
    case 168:
        *str = 1;
        *stlb = 4;
        break;
    case 169:
        *str = 6;
        *stlb = 1;
        break;
    case 170:
        *str = 1;
        *stlb = 6;
        break;
    case 171:
        *str = 8;
        *stlb = 1;
        break;
    case 172:
        *str = 1;
        *stlb = 8;
        break;
    case 173:
        *str = 1;
        *stlb = 10;
        break;
    case 174:
        *str = 10;
        *stlb = 1;
        break;
    case 175:
        *str = 1;
        *stlb = 12;
        break;
    case 176:
        *str = 12;
        *stlb = 1;
        break;
    case 177:
        *str = 3;
        *stlb = 12;
        break;
    case 178:
        *str = 12;
        *stlb = 3;
        break;
    case 179:
        *str = 5;
        *stlb = 12;
        break;
    case 180:
        *str = 12;
        *stlb = 5;
        break;
    case 181:
        *str = 12;
        *stlb = 7;
        break;
    case 182:
        *str = 7;
        *stlb = 12;
        break;
    case 183:
        *str = 12;
        *stlb = 9;
        break;
    case 184:
        *str = 9;
        *stlb = 12;
        break;
    case 185:
        *str = 12;
        *stlb = 11;
        break;
    case 186:
        *str = 11;
        *stlb = 12;
        break;
    case 187:
        *str = 0;
        *stlb = 1;
        break;
    case 188:
        *str = 13;
        *stlb = 1;
        break;
    case 189:
        *str = 0;
        *stlb = 3;
        break;
    case 190:
        *str = 13;
        *stlb = 3;
        break;
    case 191:
        *str = 0;
        *stlb = 5;
        break;
    case 192:
        *str = 13;
        *stlb = 5;
        break;
    case 193:
        *str = 0;
        *stlb = 7;
        break;
    case 194:
        *str = 13;
        *stlb = 7;
        break;
    case 195:
        *str = 0;
        *stlb = 9;
        break;
    case 196:
        *str = 13;
        *stlb = 9;
        break;
    case 197:
        *str = 13;
        *stlb = 11;
        break;
    case 198:
        *str = 0;
        *stlb = 11;
        break;
    case 199:
        *str = 13;
        *stlb = 12;
        break;
    case 200:
        *str = 12;
        *stlb = 13;
        break;
    case 201:
        *str = 0;
        *stlb = 13;
        break;
    case 202:
        *str = 2;
        *stlb = 13;
        break;
    case 203:
        *str = 4;
        *stlb = 13;
        break;
    case 204:
        *str = 6;
        *stlb = 13;
        break;
    case 205:
        *str = 8;
        *stlb = 13;
        break;
    case 206:
        *str = 14;
        *stlb = 11;
        break;
    case 207:
        *str = 14;
        *stlb = 14;
        break;
    case 208:
        *str = 1;
        *stlb = 0;
        break;
    case 209:
        *str = 1;
        *stlb = 14;
        break;
    case 210:
        *str = 3;
        *stlb = 14;
        break;
    case 211:
        *str = 3;
        *stlb = 0;
        break;
    case 212:
        *str = 5;
        *stlb = 0;
        break;
    case 213:
        *str = 5;
        *stlb = 14;
        break;
    case 214:
        *str = 7;
        *stlb = 0;
        break;
    case 215:
        *str = 7;
        *stlb = 14;
        break;
    case 216:
        *str = 9;
        *stlb = 0;
        break;
    case 217:
        *str = 9;
        *stlb = 14;
        break;
    case 218:
        *str = 11;
        *stlb = 0;
        break;
    case 219:
        *str = 11;
        *stlb = 14;
        break;
    case 220:
        *str = 13;
        *stlb = 0;
        break;
    case 221:
        *str = 13;
        *stlb = 14;
        break;
    case 222:
        *str = 14;
        *stlb = 3;
        break;
    case 223:
        *str = 14;
        *stlb = 1;
        break;
    case 224:
        *str = 14;
        *stlb = 5;
        break;
    case 225:
        *str = 14;
        *stlb = 7;
        break;
    }
}
int game_hard_chel_komp_fif(int my_pole[15][15], int pole[15][15], int* otsl_bot_1, int* otsl_bot_2, int* count, int* count_b, int* radar_count, int grid_x, int grid_y, int flag_start_attack_bot, int* count_hod, int flag_smoke)
{
    if (flag_start_attack_bot == 0) {
        return chel_attack_fi(pole, my_pole, count, count_b, grid_x, grid_y, count_hod, flag_smoke);
    }
    if (flag_start_attack_bot == 1) {
        return hard_bot_fif(my_pole, pole, otsl_bot_1, otsl_bot_2, count_b, count, radar_count, 1, 1);
    }
}
//----------------------------------------------------------------------------------------------------------------------//

int game_ten(int my_pole[10][10], int pole[10][10], int* otsl_bot_1, int* otsl_bot_2, int* count, int* count_b, int*count_radar, int grid_x, int grid_y, int flag_start_attack_bot, int level, int* count_hod, int flag_smoke) {
    if (level == 1) return game_chel_komp_ten(my_pole, pole, count, count_b, count_radar, grid_x, grid_y, flag_start_attack_bot, count_hod, flag_smoke);
    else if (level == 2)  return game_medi_chel_komp_ten(my_pole, pole, otsl_bot_1, otsl_bot_2, count, count_b, count_radar, grid_x, grid_y, flag_start_attack_bot, count_hod, flag_smoke);
    else if(level==3) return game_hard_chel_komp_ten(my_pole, pole, otsl_bot_1, otsl_bot_2, count, count_b, count_radar, grid_x, grid_y, flag_start_attack_bot, count_hod, flag_smoke);
}

int game_fi(int my_pole[15][15], int pole[15][15], int* otsl_bot_1, int* otsl_bot_2, int* count, int* count_b, int* count_radar, int grid_x, int grid_y, int flag_start_attack_bot, int level, int* count_hod, int flag_smoke) {
    if (level == 1)  return game_chel_komp_fi(my_pole, pole, count, count_b, count_radar, grid_x, grid_y, flag_start_attack_bot, count_hod,flag_smoke);
    else if(level==2)  return game_medi_chel_komp_fif(my_pole, pole, otsl_bot_1, otsl_bot_2, count, count_b, count_radar, grid_x, grid_y, flag_start_attack_bot, count_hod, flag_smoke);
    else if(level==3) return game_hard_chel_komp_fif(my_pole, pole, otsl_bot_1, otsl_bot_2, count, count_b, count_radar, grid_x, grid_y, flag_start_attack_bot, count_hod, flag_smoke);
}