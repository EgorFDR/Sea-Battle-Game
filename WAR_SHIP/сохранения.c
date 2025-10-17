#define _CRT_SECURE_NO_WARNINGS
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <stdio.h> 
#include <stdlib.h>
#include <SOIL/SOIL.h>
#define STB_EASY_FONT_IMPLEMENTATION
#include "stb_easy_font.h"
#include <string.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

#define BUTTON_MAIN 4 
#define BUTTON_SIZE_FIELD 3 
#define BUTTON_DIFFICULT 4
#define BUTTON_MOD_BOT 7
#define BUTTON_MOD 3

typedef struct {
    float x, y, width, height;
    const char* name;
} Button;

typedef struct record_node {
    char* nick;
    int score_chel;
    int score_bot;
    struct record_node* ptr_next;
}record_node;

typedef struct {
    // инициализация кнопок 
    Button main_buttons[BUTTON_MAIN];
    Button difficult_buttons[BUTTON_DIFFICULT];
    Button size_buttons[BUTTON_SIZE_FIELD];
    Button mod_bot[BUTTON_MOD_BOT];
    Button mod[BUTTON_MOD];
    Button game_buttons[2];
    //флаги для отслеживания текущего меню
    int flag_difficult;
    int flag_size;
    int field_size;
    int flag_mod;
    int flag_start;
    int flag_menu;
    int flag_start_bot;
    int mod_type;
    int mode_difficult;
    int flag_radar_chel;
    int flag_radar_print;
    int flag_get_cell_radar;
    int count_radar;
    int hod_radar;
    int temp_radar;
    int radar_count_bot[1];
    int cell_x;
    int cell_y;
    int count_click_radar;
    int flag_radar_new;
    int flag_smoke;
    int smoke_hod;

    int flag_continue;
    //вывод текста 
    FT_Library library;
    FT_Face font;
    //загрузка фона игры
    GLuint background;
    //переменные для самой игры
    int napr;
    int count_click;
    int my_pole_ten[10][10];
    int my_pole_fi[15][15];
    int flag_end_get_pole;
    int pole_bot_ten[10][10];
    int pole_bot_fi[15][15];
    int flag_get_pole_bot;
    int count_ship_kil_by_player[1];
    int count_ship_kil_by_bot[1];
    int chel_or_bot_attack;
    int count_hod_chel[1];


    int cursor;
    char* name;
    int flag_get_enter;
    int flag_add_record;
    int count_record;
    int flag_table;

    int flag_back_menu;
    int flag_save;
    int flag_game_load;
    Button game_save[3];
    Button game_load[3];

    int temp_1;
    int temp_2;
    int temp_3;
    int temp_4;
    int temp_5;
    int temp_6;
    int otsl_bot_1[1];
    int otsl_bot_2[1];
} global_data;

void save_record(char* name_file, record_node* record) {
    FILE* file = fopen(name_file, "w");
    if (!file) {
        return;
    }

    while (record) {
        fprintf(file, "%s\n%d\n%d\n", record->nick, record->score_chel, record->score_bot);
        record = record->ptr_next;
    }

    fclose(file);
}

void load_record(char* name_file, record_node** record, global_data* data) {
    FILE* file = fopen(name_file, "r");
    if (!file) {
        return;
    }
    char buffer[11];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(data->name, buffer);
        if (!fgets(buffer, sizeof(buffer), file)) break;
        data->count_ship_kil_by_player[0] = atoi(buffer);
        if (!fgets(buffer, sizeof(buffer), file)) break;
        data->count_ship_kil_by_bot[0] = atoi(buffer);
        add_record(record, data);
    }
    fclose(file);
}

void delete_save_data(global_data* data) {
     data->flag_difficult=0;
     data->flag_size=0;
     data->field_size=0;
     data->flag_mod=0;
     data->flag_start = 0;
     data->flag_menu=0;
     data->flag_start_bot=0;
     data->mod_type=0;
     data->mode_difficult=0;
     data->flag_radar_chel=0;
     data->flag_radar_print=0;
     data->flag_get_cell_radar=0;
     data->count_radar=3;
     data->hod_radar=0;
     data->temp_radar=0;
     data->radar_count_bot[0]=3;
     data->cell_x=0;
     data->cell_y=0;
     data->count_click_radar=0;
     data->flag_radar_new=0;
     data->flag_smoke=0;
     data->smoke_hod=0;

     data->flag_continue=0;
     data->napr=-1;
     data->count_click=0;
    memset(data->my_pole_ten,0, sizeof(data->my_pole_ten));
    memset(data->my_pole_fi, 0, sizeof(data->my_pole_fi));
    data->flag_end_get_pole=0;
    memset(data->pole_bot_ten, 0, sizeof(data->pole_bot_ten));
    memset(data->pole_bot_fi, 0, sizeof(data->pole_bot_fi));
    data->flag_get_pole_bot=0;
    data->count_ship_kil_by_player[0]=0;
    data->count_ship_kil_by_bot[0]=0;
    data->chel_or_bot_attack=0;
    data->count_hod_chel[0]=0;
    data->cursor=0;
    memset(data->name, 0, sizeof(data->name));
    data->flag_get_enter=0;
    data->flag_back_menu=0;
    data->flag_game_load=0;
    data->temp_1 = 0;
    data->temp_2 = 0;
    data->temp_3 = 0;
    data->temp_4 = 0;
    data->temp_5 = 0;
    data->temp_6 = 0;
    data->otsl_bot_1[0]=-1;
    data->otsl_bot_2[0]=-1;
}


typedef struct {
    int flag_difficult;
    int flag_size;
    int field_size;
    int flag_mod;
    int flag_start;
    int flag_menu;
    int flag_start_bot;
    int mod_type;
    int mode_difficult;
    int flag_radar_chel;
    int flag_radar_print;
    int flag_get_cell_radar;
    int count_radar;
    int hod_radar;
    int temp_radar;
    int radar_count_bot[1];
    int cell_x;
    int cell_y;
    int count_click_radar;
    int flag_radar_new;
    int flag_smoke;
    int smoke_hod;
    int flag_continue;
    int napr;
    int count_click;
    int my_pole_ten[10][10];
    int my_pole_fi[15][15];
    int flag_end_get_pole;
    int pole_bot_ten[10][10];
    int pole_bot_fi[15][15];
    int flag_get_pole_bot;
    int count_ship_kil_by_player[1];
    int count_ship_kil_by_bot[1];
    int chel_or_bot_attack;
    int count_hod_chel[1];
    int flag_get_enter;
    int flag_back_menu;
    int flag_save;
    int flag_game_load;
    int temp_1;
    int temp_2;
    int temp_3;
    int temp_4;
    int temp_5;
    int temp_6;
    int otsl_bot_1[1];
    int otsl_bot_2[1];
} global_data_save;


void save_game(global_data* data, char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        return;
    }
    fprintf(file, "flag_save=%d\n", data->flag_save);
    fprintf(file, "flag_difficult=%d\n", data->flag_difficult);
    fprintf(file, "flag_size=%d\n", data->flag_size);
    fprintf(file, "field_size=%d\n", data->field_size);
    fprintf(file, "flag_mod=%d\n", data->flag_mod);
    fprintf(file, "flag_start=%d\n", data->flag_start);
    fprintf(file, "flag_menu=%d\n", data->flag_menu);
    fprintf(file, "flag_start_bot=%d\n", data->flag_start_bot);
    fprintf(file, "mod_type=%d\n", data->mod_type);
    fprintf(file, "mode_difficult=%d\n", data->mode_difficult);
    fprintf(file, "flag_radar_chel=%d\n", data->flag_radar_chel);
    fprintf(file, "flag_radar_print=%d\n", data->flag_radar_print);
    fprintf(file, "flag_get_cell_radar=%d\n", data->flag_get_cell_radar);
    fprintf(file, "count_radar=%d\n", data->count_radar);
    fprintf(file, "hod_radar=%d\n", data->hod_radar);
    fprintf(file, "temp_radar=%d\n", data->temp_radar);
    fprintf(file, "radar_count_bot=%d\n", data->radar_count_bot[0]);
    fprintf(file, "cell_x=%d\n", data->cell_x);
    fprintf(file, "cell_y=%d\n", data->cell_y);
    fprintf(file, "count_click_radar=%d\n", data->count_click_radar);
    fprintf(file, "flag_radar_new=%d\n", data->flag_radar_new);
    fprintf(file, "flag_smoke=%d\n", data->flag_smoke);
    fprintf(file, "smoke_hod=%d\n", data->smoke_hod);
    fprintf(file, "flag_continue=%d\n", data->flag_continue);
    fprintf(file, "napr=%d\n", data->napr);
    fprintf(file, "count_click=%d\n", data->count_click);
    fprintf(file, "flag_end_get_pole=%d\n", data->flag_end_get_pole);
    fprintf(file, "flag_get_pole_bot=%d\n", data->flag_get_pole_bot);
    fprintf(file, "count_ship_kil_by_player=%d\n", data->count_ship_kil_by_player[0]);
    fprintf(file, "count_ship_kil_by_bot=%d\n", data->count_ship_kil_by_bot[0]);
    fprintf(file, "chel_or_bot_attack=%d\n", data->chel_or_bot_attack);
    fprintf(file, "count_hod_chel=%d\n", data->count_hod_chel[0]);
    fprintf(file, "cursor=%d\n", data->cursor);
    fprintf(file, "flag_get_enter=%d\n", data->flag_get_enter);
    fprintf(file, "flag_game_load=%d\n", data->flag_game_load);
    fprintf(file, "temp_1=%d\n", data->temp_1);
    fprintf(file, "temp_2=%d\n", data->temp_2);
    fprintf(file, "temp_3=%d\n", data->temp_3);
    fprintf(file, "temp_4=%d\n", data->temp_4);
    fprintf(file, "temp_5=%d\n", data->temp_5);
    fprintf(file, "temp_6=%d\n", data->temp_6);
    fprintf(file, "otsl_bot_1=%d\n", data->otsl_bot_1[0]);
    fprintf(file, "otsl_bot_2=%d\n", data->otsl_bot_2[0]);

    fprintf(file, "my_pole_ten=");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            fprintf(file, "%d ", data->my_pole_ten[i][j]);
        }
    }
    fprintf(file, "\n");

    fprintf(file, "my_pole_fi=");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            fprintf(file, "%d ", data->my_pole_fi[i][j]);
        }
    }
    fprintf(file, "\n");
    fprintf(file, "pole_bot_ten=");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){
            fprintf(file, "%d ", data->pole_bot_ten[i][j]);
        }
    }
    fprintf(file, "\n");
    fprintf(file, "pole_bot_fi=");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            fprintf(file, "%d ", data->pole_bot_fi[i][j]);
        }
    }
    fprintf(file, "\n");

    fclose(file);
}


void load_game(global_data* data, char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return;
    }
    char str[1000] = { 0 };
    while (fgets(str, sizeof(str), file)) {
        if (sscanf(str, "flag_save=%d", &data->flag_save)) continue;
        if (sscanf(str, "flag_difficult=%d", &data->flag_difficult)) continue;
        if (sscanf(str, "flag_size=%d", &data->flag_size)) continue;
        if (sscanf(str, "field_size=%d", &data->field_size)) continue;
        if (sscanf(str, "flag_mod=%d", &data->flag_mod)) continue;
        if (sscanf(str, "flag_start=%d", &data->flag_start)) continue;
        if (sscanf(str, "flag_menu=%d", &data->flag_menu)) continue;
        if (sscanf(str, "flag_start_bot=%d", &data->flag_start_bot)) continue;
        if (sscanf(str, "mod_type=%d", &data->mod_type)) continue;
        if (sscanf(str, "mode_difficult=%d", &data->mode_difficult)) continue;
        if (sscanf(str, "flag_radar_chel=%d", &data->flag_radar_chel)) continue;
        if (sscanf(str, "flag_radar_print=%d", &data->flag_radar_print)) continue;
        if (sscanf(str, "flag_get_cell_radar=%d", &data->flag_get_cell_radar)) continue;
        if (sscanf(str, "count_radar=%d", &data->count_radar)) continue;
        if (sscanf(str, "hod_radar=%d", &data->hod_radar)) continue;
        if (sscanf(str, "temp_radar=%d", &data->temp_radar)) continue;
        if (sscanf(str, "radar_count_bot=%d", &data->radar_count_bot[0])) continue;
        if (sscanf(str, "cell_x=%d", &data->cell_x)) continue;
        if (sscanf(str, "cell_y=%d", &data->cell_y)) continue;
        if (sscanf(str, "count_click_radar=%d", &data->count_click_radar)) continue;
        if (sscanf(str, "flag_radar_new=%d", &data->flag_radar_new)) continue;
        if (sscanf(str, "flag_smoke=%d", &data->flag_smoke)) continue;
        if (sscanf(str, "smoke_hod=%d", &data->smoke_hod)) continue;
        if (sscanf(str, "flag_continue=%d", &data->flag_continue)) continue;
        if (sscanf(str, "napr=%d", &data->napr)) continue;
        if (sscanf(str, "count_click=%d", &data->count_click)) continue;
        if (sscanf(str, "flag_end_get_pole=%d", &data->flag_end_get_pole)) continue;
        if (sscanf(str, "flag_get_pole_bot=%d", &data->flag_get_pole_bot)) continue;
        if (sscanf(str, "count_ship_kil_by_player=%d", &data->count_ship_kil_by_player[0])) continue;
        if (sscanf(str, "count_ship_kil_by_bot=%d", &data->count_ship_kil_by_bot[0])) continue;
        if (sscanf(str, "chel_or_bot_attack=%d", &data->chel_or_bot_attack)) continue;
        if (sscanf(str, "count_hod_chel=%d", &data->count_hod_chel[0])) continue;
        if (sscanf(str, "cursor=%d", &data->cursor)) continue;
        if (sscanf(str, "flag_get_enter=%d", &data->flag_get_enter)) continue;
        if (sscanf(str, "flag_game_load=%d", &data->flag_game_load)) continue;
        if (sscanf(str, "temp_1=%d", &data->temp_1)) continue;
        if (sscanf(str, "temp_2=%d", &data->temp_2)) continue;
        if (sscanf(str, "temp_3=%d", &data->temp_3)) continue;
        if (sscanf(str, "temp_4=%d", &data->temp_4)) continue;
        if (sscanf(str, "temp_5=%d", &data->temp_5)) continue;
        if (sscanf(str, "temp_6=%d", &data->temp_6)) continue;
        if (sscanf(str, "otsl_bot_1=%d", &data->otsl_bot_1[0])) continue;
        if (sscanf(str, "otsl_bot_2=%d", &data->otsl_bot_2[0])) continue;

        if (strncmp(str, "my_pole_ten=", 12) == 0) {
            char* ptr = str + 12;
            for (int i = 0; i < 10; i++) {  
                for (int j = 0; j < 10; j++) {
                    sscanf(ptr, "%d", &data->my_pole_ten[i][j]), ptr = strchr(ptr, ' ') + 1;
                }
            }
            continue;
        }

        if (strncmp(str, "my_pole_fi=", 11) == 0) {
            char* ptr = str + 11;
            for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 15; j++) {
                    sscanf(ptr, "%d", &data->my_pole_fi[i][j]), ptr = strchr(ptr, ' ') + 1;
                }
            }
            continue;
        }

        if (strncmp(str, "pole_bot_ten=", 13) == 0) {
            char* ptr = str + 13;
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    sscanf(ptr, "%d", &data->pole_bot_ten[i][j]), ptr = strchr(ptr, ' ') + 1;
                }
            }
            continue;
        }

        if (strncmp(str, "pole_bot_fi=", 12) == 0) {
            char* ptr = str + 12;
            for (int i = 0; i < 15; i++) {
                for (int j = 0; j < 15; j++) {
                    sscanf(ptr, "%d", &data->pole_bot_fi[i][j]), ptr = strchr(ptr, ' ') + 1;
                }
            }
            continue;
        }
    }

    fclose(file);
}

int is_save(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        return 0;
    }

    char line[12] = { 0 };
    int flag = 0;
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "flag_save=%d", &flag) == 1) {
            fclose(file);
            return flag;
        }
    }
    fclose(file);
    return 0;
}
