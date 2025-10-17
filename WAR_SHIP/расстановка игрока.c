#define _CRT_SECURE_NO_WARNINGS
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

int my_plan_ten(int pole[10][10], int count_click, int grid_x, int grid_y, int nap)
{
    //flag = 0 координаты неверные или заняты
    //flag = 1 координаты правильные
    //flag = 2 корабль установлен.
    // napr=0 вертикально вниз, napr=1 горизонтально вправо
    
    //расстановка линкора
    if (count_click == 1) {
        int flag = 0;
        printf("Линкор\n");
        //scanf(" %c%d", &sim1, &sim2);
       // str = sim2 - 1;
        //stb = trans(sim1);
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        printf("napr!!==%d\n", nap);
        if (str >= 0 && str <= 9 && stb <= 9 && stb >= 0 && pole[str][stb] == 0)
        {
            flag = 1;
        }
        if (flag == 0) {
            count_click = 0;
            return count_click;
            //continue;
        }

        //scanf("%d", &napr);
        if (napr == 0 && str + 1 <= 9 && str + 2 <= 9 && str + 3 <= 9)
        {
            if (pole[str + 1][stb] == 0 && pole[str + 2][stb] == 0 && pole[str + 3][stb] == 0)
            {
                flag = 2;
                pole[str][stb] = 4;
                pole[str + 1][stb] = 4;
                pole[str + 2][stb] = 4;
                pole[str + 3][stb] = 4;
            }
        }
        if (napr == 1 && stb + 1 <= 9 && stb + 2 <= 9 && stb + 3 <= 9)
        {
            if (pole[str][stb + 1] == 0 && pole[str][stb + 2] == 0 && pole[str][stb + 3] == 0)
            {
                flag = 2;
                pole[str][stb] = 4;
                pole[str][stb + 1] = 4;
                pole[str][stb + 2] = 4;
                pole[str][stb + 3] = 4;
            }
        }
        if (flag == 1) {
            //continue;
            count_click = 0;
            return count_click;
        }
        if (flag == 2) {
            printf("Линкор установлен\n");
           // return 1;
            //}
            //break;

    //}

            if (napr == 0)
            {
                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
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
                //
                if (pole[str - 1][stb-1] == 0 && str - 1 <= 9 && stb-1 <= 9 && str - 1 >= 0 && stb-1 >= 0)
                    pole[str - 1][stb-1] = 7;
                if (pole[str - 1][stb+1] == 0 && str - 1 <= 9 && stb +1 <= 9 && str - 1 >= 0 && stb +1 >= 0)
                    pole[str - 1][stb+1] = 7;
                if (pole[str + 4][stb + 1] == 0 && str + 4 <= 9 && stb + 1 <= 9 && str + 4 >= 0 && stb + 1 >= 0)
                    pole[str + 4][stb + 1] = 7;
                if (pole[str + 4][stb -1] == 0 && str + 4 <= 9 && stb - 1 <= 9 && str + 4 >= 0 && stb - 1 >= 0)
                    pole[str + 4][stb - 1] = 7;


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
                //
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str + 1][stb + 4] == 0 && str + 1 <= 9 && stb + 4 <= 9 && str + 1 >= 0 && stb + 4 >= 0)
                    pole[str + 1][stb + 4] = 7;
                if (pole[str -1][stb + 4] == 0 && str -1 <= 9 && stb +4 <= 9 && str -1 >= 0 && stb+4 >= 0)
                    pole[str -1][stb + 4] = 7;
            }
            return 1;
        }
    }
   // крейсера
      if(count_click==2 || count_click==3){
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        int flag = 0;
        printf("Крейсер\n");
         
            if (str >= 0 && str <= 9 && stb <= 9 && stb >= 0 && pole[str][stb] == 0)
            {
                flag = 1;
            }
            if (flag == 0 && count_click == 2) {
                count_click = 1;
                return count_click;
            }
            if (flag == 0 && count_click == 3) {
                count_click = 2;
                return count_click;
            }
            if (napr == 0 && str + 1 <= 9 && str + 2 <= 9)
            {
                if (pole[str + 1][stb] == 0 && pole[str + 2][stb] == 0)
                {
                    flag = 2;
                    pole[str][stb] = 3;
                    pole[str + 1][stb] = 3;
                    pole[str + 2][stb] = 3;
                }
            }
            if (napr == 1 && stb + 1 <= 9 && stb + 2 <= 9)
            {
                if (pole[str][stb + 1] == 0 && pole[str][stb + 2] == 0)
                {
                    flag = 2;
                    pole[str][stb] = 3;
                    pole[str][stb + 1] = 3;
                    pole[str][stb + 2] = 3;
                }
            }
            if (flag == 1 && count_click==2) {
                count_click = 1;
                return count_click;
            }
            if (flag == 1 && count_click == 3) {
                count_click = 2;
                return count_click;
            }
            if (flag == 2) {
                if (napr == 0)
                {
                    if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                        pole[str - 1][stb] = 7;
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
                    //
                    if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                        pole[str - 1][stb - 1] = 7;
                    if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
                        pole[str - 1][stb + 1] = 7;
                    if (pole[str + 3][stb + 1] == 0 && str + 3 <= 9 && stb + 1 <= 9 && str + 3 >= 0 && stb + 1 >= 0)
                        pole[str + 3][stb + 1] = 7;
                    if (pole[str + 3][stb - 1] == 0 && str + 3 <= 9 && stb - 1 <= 9 && str + 3 >= 0 && stb - 1 >= 0)
                        pole[str + 3][stb - 1] = 7;
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
                    if (pole[str - 1][stb + 2] == 0 && str - 1 <= 9 && stb + 2 <= 9 && str - 1 >= 0 && stb + 2 >= 0)
                        pole[str - 1][stb + 2] = 7;
                    if (pole[str + 1][stb + 2] == 0 && str + 1 <= 9 && stb + 2 <= 9 && str + 1 >= 0 && stb + 2 >= 0)
                        pole[str + 1][stb + 2] = 7;
                    if (pole[str][stb + 3] == 0 && str <= 9 && stb + 3 <= 9 && str >= 0 && stb + 3 >= 0)
                        pole[str][stb + 3] = 7;
                    //
                    if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                        pole[str - 1][stb - 1] = 7;
                    if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
                        pole[str + 1][stb - 1] = 7;
                    if (pole[str + 1][stb + 3] == 0 && str + 1 <= 9 && stb + 3 <= 9 && str + 1 >= 0 && stb + 3 >= 0)
                        pole[str + 1][stb + 3] = 7;
                    if (pole[str - 1][stb + 3] == 0 && str - 1 <= 9 && stb + 3 <= 9 && str - 1 >= 0 && stb + 3 >= 0)
                        pole[str - 1][stb + 3] = 7;
                }
                if (count_click == 2) {
                    return 2;
                }
                if (count_click == 3) {
                    return 3;
                }
            }
      }
  
    //эсминцы
    if(count_click>=4 && count_click<=6)
    {
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        int flag = 0;

          
            printf("Эсминец\n");
        
            if (str >= 0 && str <= 9 && stb <= 9 && stb >= 0 && pole[str][stb] == 0)
            {
                flag = 1;
            }
            if (flag == 0 && count_click == 4) return 3;
            if (flag == 0 && count_click == 5) return 4;
            if (flag == 0 && count_click == 6) return 5;
            if (napr == 0 && str + 1 <= 9)
            {
                if (pole[str + 1][stb] == 0)
                {
                    flag = 2;
                    pole[str][stb] = 2;
                    pole[str + 1][stb] = 2;
                }
            }
            if (napr == 1 && stb + 1 <= 9)
            {
                if (pole[str][stb + 1] == 0)
                {
                    flag = 2;
                    pole[str][stb] = 2;
                    pole[str][stb + 1] = 2;
                }
            }
            if (flag == 1 && count_click == 4) return 3;
            if (flag == 1 && count_click == 5) return 4;
            if (flag == 1 && count_click == 6) return 5;
            //if(flag==2){

            if (napr == 0)
            {
                if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                    pole[str - 1][stb] = 7;
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
                //
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
                    pole[str - 1][stb + 1] = 7;
                if (pole[str + 2][stb + 1] == 0 && str + 2 <= 9 && stb + 1 <= 9 && str + 2 >= 0 && stb + 1 >= 0)
                    pole[str + 2][stb + 1] = 7;
                if (pole[str + 2][stb - 1] == 0 && str + 2 <= 9 && stb - 1 <= 9 && str + 2 >= 0 && stb - 1 >= 0)
                    pole[str + 2][stb - 1] = 7;
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
                //
                if (pole[str - 1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str - 1 >= 0 && stb - 1 >= 0)
                    pole[str - 1][stb - 1] = 7;
                if (pole[str + 1][stb - 1] == 0 && str + 1 <= 9 && stb - 1 <= 9 && str + 1 >= 0 && stb - 1 >= 0)
                    pole[str + 1][stb - 1] = 7;
                if (pole[str + 1][stb + 2] == 0 && str + 1 <= 9 && stb + 2 <= 9 && str + 1 >= 0 && stb + 2 >= 0)
                    pole[str + 1][stb + 2] = 7;
                if (pole[str - 1][stb + 2] == 0 && str - 1 <= 9 && stb + 2 <= 9 && str - 1 >= 0 && stb + 2 >= 0)
                    pole[str - 1][stb + 2] = 7;
            }
            if (flag == 2 && count_click == 4) return 4;
            if (flag == 2 && count_click == 5) return 5;
            if (flag == 2 && count_click == 6) return 6;
    }
    //каетера
    if(count_click >= 7 && count_click <= 10)
    {
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        int flag = 0;
            printf("Катер\n");
            if (str >= 0 && str <= 9 && stb <= 9 && stb >= 0 && pole[str][stb] == 0)
            {
                flag = 1;
            }
            if (flag == 0 && count_click == 7) return 6;
            if (flag == 0 && count_click == 8) return 7;
            if (flag == 0 && count_click == 9) return 8;
            if (flag == 0 && count_click == 10) return 9;
           

            if (pole[str][stb] == 0)
            {
                flag = 2;
                pole[str][stb] = 1;
            }

            if (flag == 0 && count_click == 7) return 6;
            if (flag == 0 && count_click == 8) return 7;
            if (flag == 0 && count_click == 9) return 8;
            if (flag == 0 && count_click == 10) return 9;

            if (pole[str - 1][stb] == 0 && str - 1 <= 9 && stb <= 9 && str - 1 >= 0 && stb >= 0)
                pole[str - 1][stb] = 7;
            if (pole[str][stb - 1] == 0 && str <= 9 && stb - 1 <= 9 && str >= 0 && stb - 1 >= 0)
                pole[str][stb - 1] = 7;
            if (pole[str][stb + 1] == 0 && str <= 9 && stb + 1 <= 9 && str >= 0 && stb + 1 >= 0)
                pole[str][stb + 1] = 7;
            if (pole[str + 1][stb] == 0 && str + 1 <= 9 && stb <= 9 && str + 1 >= 0 && stb >= 0)
                pole[str + 1][stb] = 7;
            if (pole[str + 1][stb+1] == 0 && str + 1 <= 9 && stb+1 <= 9 && str + 1 >= 0 && stb+1 >= 0)
                pole[str + 1][stb+1] = 7;
            if (pole[str + 1][stb-1] == 0 && str + 1 <= 9 && stb-1 <= 9 && str + 1 >= 0 && stb-1 >= 0)
                pole[str + 1][stb-1] = 7;
            if (pole[str -1][stb - 1] == 0 && str - 1 <= 9 && stb - 1 <= 9 && str -1 >= 0 && stb - 1 >= 0)
                pole[str - 1][stb - 1] = 7;
            if (pole[str - 1][stb + 1] == 0 && str - 1 <= 9 && stb + 1 <= 9 && str - 1 >= 0 && stb + 1 >= 0)
                pole[str - 1][stb + 1] = 7;

            if (flag == 2 && count_click == 7) return 7;
            if (flag == 2 && count_click == 8) return 8;
            if (flag == 2 && count_click == 9) return 9;
            if (flag == 2 && count_click == 10) return 10;
      
    }
    if (count_click >= 11 && count_click <= 13) {
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        int flag = 0;
        printf("Мина!\n");
        if (str >= 0 && str <= 9 && stb <= 9 && stb >= 0 && (pole[str][stb] == 0 || pole[str][stb] == 7))
        {
            flag = 1;
        }
        if (flag == 0 && count_click == 11) return 10;
        if (flag == 0 && count_click == 12) return 11;
        if (flag == 0 && count_click == 13) return 12;


        if (pole[str][stb] == 0 || pole[str][stb] == 7)
        {
            flag = 2;
            pole[str][stb] = 9;
        }

        if (flag == 0 && count_click == 11) return 12;
        if (flag == 0 && count_click == 12) return 11;
        if (flag == 0 && count_click == 13) return 12;

      

        if (flag == 2 && count_click == 11) return 11;
        if (flag == 2 && count_click == 12) return 12;
        if (flag == 2 && count_click == 13) return 13;
    }
   return 13;
}

int my_plan_fi(int pole[15][15], int count_click, int grid_x, int grid_y, int nap)
{

    //авианосец
    if (count_click == 1) {
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        int flag = 0;
        printf("Авианосец\n");

        if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && pole[str][stb] == 0)
        {
            flag = 1;
        }
        if (flag == 0) return 0;
          
      
        if (napr == 0 && str + 1 <= 14 && str + 2 <= 14 && str + 3 <= 14 && str + 4 <= 14)
        {
            if (pole[str + 1][stb] == 0 && pole[str + 2][stb] == 0 && pole[str + 3][stb] == 0 && pole[str + 4][stb] == 0)
            {
                flag = 2;
                pole[str][stb] = 5;
                pole[str + 1][stb] = 5;
                pole[str + 2][stb] = 5;
                pole[str + 3][stb] = 5;
                pole[str + 4][stb] = 5;
            }
        }
        if (napr == 1 && stb + 1 <= 14 && stb + 2 <= 14 && stb + 3 <= 14 && stb + 4 <= 14)
        {
            if (pole[str][stb + 1] == 0 && pole[str][stb + 2] == 0 && pole[str][stb + 3] == 0 && pole[str][stb + 4] == 0)
            {
                flag = 2;
                pole[str][stb] = 5;
                pole[str][stb + 1] = 5;
                pole[str][stb + 2] = 5;
                pole[str][stb + 3] = 5;
                pole[str][stb + 4] = 5;
            }
        }
        if (flag == 1)
            return 0;

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
        return 1;
    }

    if (count_click == 2) {
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        int flag = 0;

            if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && pole[str][stb] == 0)
            {
                flag = 1;
            }
            if (flag == 0)
               return 1;
            if (napr == 0 && str + 1 <= 14 && str + 2 <= 14 && str + 3 <= 14)
            {
                if (pole[str + 1][stb] == 0 && pole[str + 2][stb] == 0 && pole[str + 3][stb] == 0)
                {
                    flag = 2;
                    pole[str][stb] = 4;
                    pole[str + 1][stb] = 4;
                    pole[str + 2][stb] = 4;
                    pole[str + 3][stb] = 4;
                }
            }
            if (napr == 1 && stb + 1 <= 14 && stb + 2 <= 14 && stb + 3 <= 14)
            {
                if (pole[str][stb + 1] == 0 && pole[str][stb + 2] == 0 && pole[str][stb + 3] == 0)
                {
                    flag = 2;
                    pole[str][stb] = 4;
                    pole[str][stb + 1] = 4;
                    pole[str][stb + 2] = 4;
                    pole[str][stb + 3] = 4;
                }
            }
            if (flag == 1) return 1;
 
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
        return 2;
    }

    if (count_click == 3 || count_click==4) {
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        int flag = 0;


            if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && pole[str][stb] == 0)
            {
                flag = 1;
            }
            if (flag == 0 && count_click == 3) return 2;
            if (flag == 0 && count_click == 4) return 3;
             
            if (napr == 0 && str + 1 <= 14 && str + 2 <= 14)
            {
                if (pole[str + 1][stb] == 0 && pole[str + 2][stb] == 0)
                {
                    flag = 2;
                    pole[str][stb] = 3;
                    pole[str + 1][stb] = 3;
                    pole[str + 2][stb] = 3;
                }
            }
            if (napr == 1 && stb + 1 <= 14 && stb + 2 <= 14)
            {
                if (pole[str][stb + 1] == 0 && pole[str][stb + 2] == 0)
                {
                    flag = 2;
                    pole[str][stb] = 3;
                    pole[str][stb + 1] = 3;
                    pole[str][stb + 2] = 3;
                }
            }
            if (flag == 1 && count_click == 3) return 2;
            if (flag == 1 && count_click == 4) return 3;
           
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
            if (count_click == 3) return 3;
            if (count_click == 4) return 4;
     
    }

    if (count_click>= 5  && count_click<=7 ) {
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        int flag = 0;

        
            if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && pole[str][stb] == 0)
            {
                flag = 1;
            }
            if (flag == 0 && count_click == 5) return 4;
            if (flag == 0 && count_click == 6) return 5;
            if (flag == 0 && count_click == 7) return 6;
               
          
            if (napr == 0 && str + 1 <= 14)
            {
                if (pole[str + 1][stb] == 0)
                {
                    flag = 2;
                    pole[str][stb] = 2;
                    pole[str + 1][stb] = 2;
                }
            }
            if (napr == 1 && stb + 1 <= 14)
            {
                if (pole[str][stb + 1] == 0)
                {
                    flag = 2;
                    pole[str][stb] = 2;
                    pole[str][stb + 1] = 2;
                }
            }
            if (flag == 1 && count_click == 5) return 4;
            if (flag == 1 && count_click == 6) return 5;
            if (flag == 1 && count_click == 7) return 6;

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
                if (pole[str +2][stb - 1] == 0 && str + 2 <= 14 && stb - 1 <= 14 && str + 2 >= 0 && stb - 1 >= 0)
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
            if (count_click == 5) return 5;
            if (count_click == 6) return 6;
            if (count_click == 7) return 7;
      
    }

    if (count_click >= 8 && count_click <= 11) {
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        int flag = 0;
        if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && pole[str][stb] == 0)
        {
            flag = 1;
        }
        if (flag == 0 && count_click == 8) return 7;
        if (flag == 0 && count_click == 9) return 8;
        if (flag == 0 && count_click == 10) return 9;
        if (flag == 0 && count_click == 11) return 10;

        if (pole[str][stb] == 0)
        {
            flag = 2;
            pole[str][stb] = 1;
        }

        if (flag == 1 && count_click == 8) return 7;
        if (flag == 1 && count_click == 9) return 8;
        if (flag == 1 && count_click == 10) return 9;
        if (flag == 1 && count_click == 11) return 10;

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


        if (count_click == 8) return 8;
        if (count_click == 9) return 9;
        if (count_click == 10) return 10;
        if (count_click == 11) return 11;
    }
    if (count_click >= 12 && count_click <= 16) {
        int stb = grid_x;
        int str = grid_y;
        int napr = nap;
        int flag = 0;
        printf("Мина!\n");
        if (str >= 0 && str <= 14 && stb <= 14 && stb >= 0 && (pole[str][stb] == 0 || pole[str][stb] == 7))
        {
            flag = 1;
        }
        if (flag == 0 && count_click == 12) return 11;
        if (flag == 0 && count_click == 13) return 12;
        if (flag == 0 && count_click == 14) return 13;
        if (flag == 0 && count_click == 15) return 14;
        if (flag == 0 && count_click == 16) return 15;


        if (pole[str][stb] == 0 || pole[str][stb] == 7)
        {
            flag = 2;
            pole[str][stb] = 9;
        }

        if (flag == 2 && count_click == 12) return 12;
        if (flag == 2 && count_click == 13) return 13;
        if (flag == 2 && count_click == 14) return 14;
        if (flag == 2 && count_click == 15) return 15;
        if (flag == 2 && count_click == 16) return 16;
    }
   return 16;
}

int placement_ten(int my_pole[10][10], int count_click, int grid_x, int grid_y, int nap) {
        int count = 0; 
        count = my_plan_ten(my_pole, count_click, grid_x, grid_y, nap);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) printf("%d ", my_pole[i][j]);
            printf("\n");
        }
        return count;
}

int placement_fi(int my_pole[15][15], int count_click, int grid_x, int grid_y, int nap) {
    int count = 0;
   // printf("click==%d", count_click);
    count = my_plan_fi(my_pole, count_click, grid_x, grid_y, nap);
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) printf("%d ", my_pole[i][j]);
        printf("\n");
    }
    return count;
}

