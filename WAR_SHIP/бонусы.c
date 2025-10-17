#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mina_pacement_ten(int pole[10][10], int level) {
    int count = 0;
    if (level == 1) count = 3;
    if (level == 2) count = 4;
    if(level == 3) count = 5;
    while (count != 0) {

        int str = rand() % 10;
        int stb = rand() % 10;

        if (pole[str][stb] == 0 || pole[str][stb] == 7)
        {
            pole[str][stb] = 9;
            count--;
        }
    }
}

void mina_pacement_fi(int pole[15][15], int level) {
    int count = 0;
    if (level == 1) count = 5;
    if (level == 2) count = 6;
    if (level == 3) count = 7;
    while (count != 0) {

        int str = rand() % 10;
        int stb = rand() % 10;

        if (pole[str][stb] == 0 || pole[str][stb] == 7)
        {
            pole[str][stb] = 9;
            count--;
        }
    }
}

void mina_ten(int pole_1[10][10], int str, int stlb, int *count, int flag) {
    printf("МИНА!! ШТОРМ!!\n");
    int count_temp = count[0];
        if (pole_1[str][stlb] == 1)
        {
            printf("Убит!\n");
            count_temp++;
            pole_1[str][stlb] = 8;
        }
        if (pole_1[str][stlb] == 2)
        {
            pole_1[str][stlb] = 8;
            if (pole_1[str][stlb - 1] != 2 && pole_1[str][stlb + 1] != 2 && pole_1[str - 1][stlb] != 2 && pole_1[str + 1][stlb] != 2)
            {
                count_temp++;
                printf("Убит!\n");
            }
            else
                printf("Ранен!\n");
        }
        if (pole_1[str][stlb] == 3)
        {
            pole_1[str][stlb] = 8;
            if (pole_1[str][stlb - 1] != 3 && pole_1[str][stlb + 1] != 3 && pole_1[str - 1][stlb] != 3 && pole_1[str + 1][stlb] != 3)
            {
                if (pole_1[str][stlb - 1] == 8)
                {
                    if (pole_1[str][stlb - 2] == 8)
                    {
                        count_temp++;
                        printf("Убит!\n");
                    }
                    if (pole_1[str][stlb - 2] == 8)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole_1[str][stlb + 1] == 8)
                {
                    if (pole_1[str][stlb + 2] == 8)
                    {
                        count_temp++;
                        printf("Убит!\n");
                    }
                    if (pole_1[str][stlb + 2] == 3)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole_1[str - 1][stlb] == 8)
                {
                    if (pole_1[str - 2][stlb] == 8)
                    {
                        count_temp++;
                        printf("Убит!\n");
                    }
                    if (pole_1[str - 2][stlb] == 8)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole_1[str + 1][stlb] == 8)
                {
                    if (pole_1[str + 2][stlb] == 8)
                    {
                        count_temp++;
                        printf("Убит!\n");
                    }
                    if (pole_1[str + 2][stlb] == 3)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole_1[str + 1][stlb] == 8 && pole_1[str - 1][stlb] == 8)
                {
                    count_temp++;
                    printf("Убит!\n");
                }
                if (pole_1[str][stlb + 1] == 8 && pole_1[str][stlb - 1] == 8)
                {
                    count_temp++;
                    printf("Убит!\n");
                }
            }
            else
                printf("Ранен!\n");
        }
        if (pole_1[str][stlb] == 4)
        {
            pole_1[str][stlb] = 8;
            if (pole_1[str][stlb - 1] != 4 && pole_1[str][stlb - 2] != 4 && pole_1[str][stlb - 3] != 4 && pole_1[str][stlb + 1] != 4 &&
                pole_1[str][stlb + 2] != 4 && pole_1[str][stlb + 3] != 4 && pole_1[str - 2][stlb] != 4 && pole_1[str - 1][stlb] != 4 && pole_1[str - 3][stlb] != 4 &&
                pole_1[str + 2][stlb] != 4 && pole_1[str + 3][stlb] != 4 && pole_1[str + 1][stlb] != 4)
            {
                count_temp++;
                printf("Убит!\n");
            }
            else
                printf("Ранен!\n");
        }
        if (flag==1 && (pole_1[str][stlb] == 0 || pole_1[str][stlb] == 7))
        {
            printf("Мимо!\n");
            pole_1[str][stlb] = 6;
        }
        if (pole_1[str][stlb] == 9 && flag==1) {
            pole_1[str][stlb] = 10;
        }
       
    count[0] = count_temp;
}

void mina_fi(int pole[15][15], int str, int stlb, int* count, int flag){
    printf("МИНА!! ШТОРМ!!\n");
    int count_temp = count[0];
        
    if (pole[str][stlb] == 1)
        {
            printf("Убит!\n");
            count_temp++;
            pole[str][stlb] = 8;
        }
        if (pole[str][stlb] == 2)
        {
            pole[str][stlb] = 8;
            if (pole[str][stlb - 1] != 2 && pole[str][stlb + 1] != 2 && pole[str - 1][stlb] != 2 && pole[str + 1][stlb] != 2)
            {
                count_temp++;
                printf("Убит!\n");
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
                        count_temp++;
                        printf("Убит!\n");
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
                        count_temp++;
                        printf("Убит!\n");
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
                        count_temp++;
                        printf("Убит!\n");
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
                        count_temp++;
                        printf("Убит!\n");
                    }
                    if (pole[str + 2][stlb] == 3)
                    {
                        printf("Ранен!\n");
                    }
                }
                if (pole[str + 1][stlb] == 8 && pole[str - 1][stlb] == 8)
                {
                    count_temp++;
                    printf("Убит!\n");
                }
                if (pole[str][stlb + 1] == 8 && pole[str][stlb - 1] == 8)
                {
                    count_temp++;
                    printf("Убит!\n");
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
                count_temp++;
                printf("Убит!\n");
            }
            else
                printf("Ранен!\n");
        }
        if (pole[str][stlb] == 5)
        {
            pole[str][stlb] = 8;
            if (pole[str][stlb - 1] != 5 && pole[str][stlb - 2] != 5 && pole[str][stlb - 3] != 5 && pole[str][stlb - 4] != 5 && pole[str][stlb + 1] != 5 && pole[str][stlb + 2] != 5 && pole[str][stlb + 3] != 5 && pole[str][stlb + 4] != 5 && pole[str - 2][stlb] != 5 && pole[str - 1][stlb] != 5 && pole[str - 3][stlb] != 5 && pole[str - 4][stlb] != 5 && pole[str + 2][stlb] != 5 && pole[str + 3][stlb] != 5 && pole[str + 1][stlb] != 5 && pole[str + 4][stlb] != 5)
            {
                count_temp++;
                printf("Убит!\n");
            }
            else
                printf("Ранен!\n");
        }
        if (flag == 1 && (pole[str][stlb] == 0 || pole[str][stlb] == 7))
        {
            printf("Мимо!\n");
            pole[str][stlb] = 6;
        }
        if(pole[str][stlb] == 9 && flag==1)  pole[str][stlb] = 10;
    count[0] = count_temp;
}

typedef struct {
    int x;
    int y;
    int count_v;
    int count_h;
}storm_struct;

storm_struct storm = { 0 };

void storm_ten(int pole[10][10], int* count) {
    storm.x = rand() % 10;
    storm.y = rand() % 10;
    storm.count_v = rand() % 4 + 2;
    storm.count_h = rand() % 4 + 2;
    int i = 0;
    int j = 0;
    for (int row = storm.y; row < 10 && i < storm.count_v; row++, i++) {
        j = 0;
        for (int col = storm.x; col < 10 && j < storm.count_h; col++, j++) {
            mina_ten(pole, row, col, count,0);
        }
    }
}

void storm_fi(int pole[15][15], int* count) {
    storm.x = rand() % 15;
    storm.y = rand() % 15;
    storm.count_v = rand() % 6 + 2;
    storm.count_h = rand() % 6 + 2;
    int i = 0;
    int j = 0;
    for (int row = storm.y; row < 15 && i < storm.count_v; row++, i++) {
        j = 0;
        for (int col = storm.x; col < 15 && j < storm.count_h; col++, j++) {
            mina_fi(pole, row, col, count, 0);
        }
    }
}

int radar_bot_ten(int pole[10][10], int* count_radar, int* count_bot) {
    printf("Радар бот!\n");
    int temp = rand() % 11;
    //int temp = 9;
    if (count_radar[0] != 0 && temp==9) {
        count_radar[0] = count_radar[0] - 1;
        int flag = 0;
        for (int row = 0; row < 10; row++) {
            for (int col = 0; col < 10; col++) {
                if (pole[row][col] == 1) {
                    pole[row][col] = 8;
                    count_bot[0] = count_bot[0] + 1;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
        return 1;
    }
    return 0;
}

int radar_bot_fi(int pole[15][15], int* count_radar, int* count_bot) {
    printf("Радар бот!\n");
    int temp = rand() % 11;
    //int temp = 9;
    if (count_radar[0] != 0 && temp == 9) {
        count_radar[0] = count_radar[0] - 1;
        int flag = 0;
        for (int row = 0; row < 15; row++) {
            for (int col = 0; col < 15; col++) {
                if (pole[row][col] == 1) {
                    pole[row][col] = 8;
                    count_bot[0] = count_bot[0] + 1;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
        return 1;
    }
    return 0;
}