#define _CRT_SECURE_NO_WARNINGS
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include <stdio.h> 
#include <stdlib.h>
#include <SOIL/SOIL.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

//количество используемых кнопок:
#define BUTTON_MAIN 4 
#define BUTTON_SIZE_FIELD 3 
#define BUTTON_DIFFICULT 4
#define BUTTON_MOD_BOT 7
#define BUTTON_MOD 3

//информация о кнопке (координаты, длина, ширина, название)
typedef struct {
    float x, y, width, height;
    const char* name;
} Button;


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


typedef struct record_node {
    char* nick;
    int score_chel;
    int score_bot;
    struct record_node* ptr_next;
}record_node;


enum {
    hod_chel,
    hod_bot,
    chel_win,
    bot_win

};


void download_background(global_data* data, char* file) {
    data->background = SOIL_load_OGL_texture(file, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
    if (!data->background) {
        printf("Ошибка загрузки изображения\n");
        return;
    }
}
//рисуем фон 
void paint_background(global_data* data) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, data->background);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.0f, -1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, -1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.0f, 1.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void print_text(global_data* data, const char* text, float x, float y) {
    glPushMatrix();
    for (const char* c = text; *c; c++) {
        FT_Load_Char(data->font, *c, FT_LOAD_RENDER);
        FT_Bitmap* bitmap = &data->font->glyph->bitmap;
        float vertical = data->font->glyph->bitmap_top;
        for (int i = 0; i < bitmap->rows; i++) {
            for (int j = 0; j < bitmap->width; j++) {
                if (bitmap->buffer[i * bitmap->width + j]) {
                    glColor3f(1.0f, 1.0f, 1.0f);
                    glBegin(GL_POINTS);
                    glVertex2f(x + j * 0.002f, y - (i - vertical) * 0.002f);
                    glEnd();
                }
            }
        }
        x = x + (data->font->glyph->advance.x >> 6) * 0.002f;
    }
    glPopMatrix();
}

//риусем кнопочки
void draw_button(global_data* data, Button temp) {
    glBegin(GL_QUADS);
    glColor3f(0.2f, 0.6f, 1.0f);
    glVertex2f(temp.x, temp.y);
    glVertex2f(temp.x + temp.width, temp.y);
    glVertex2f(temp.x + temp.width, temp.y - temp.height);
    glVertex2f(temp.x, temp.y - temp.height);
    glEnd();
    print_text(data, temp.name, temp.x + 0.02f, temp.y - temp.height + 0.05f);
}

//задаем параметры кнопкам
void update_size_buttons(GLFWwindow* window, int length, int height) {
    global_data* data = (global_data*)glfwGetWindowUserPointer(window);
    glViewport(0, 0, length, height);
    float ratio = (float)length / height;

    float button_width = 0.4f * ratio;
    float button_height = 0.15f;
    float position_x_main_button = -0.8f;

    data->main_buttons[0] = (Button){ position_x_main_button ,  0.3f, button_width, button_height, "Play" };
    data->main_buttons[1] = (Button){ position_x_main_button,  0.0f, button_width, button_height, "Settings" };
    data->main_buttons[2] = (Button){ position_x_main_button, -0.3f, button_width, button_height, "Records" };
    data->main_buttons[3] = (Button){ position_x_main_button, -0.6f, button_width, button_height, "Exit" };

    data->difficult_buttons[0] = (Button){ -button_width / 2,  0.3f, button_width, button_height, "Easy" };
    data->difficult_buttons[1] = (Button){ -button_width / 2,  0.1f, button_width, button_height, "Medium" };
    data->difficult_buttons[2] = (Button){ -button_width / 2, -0.1f, button_width, button_height, "Hard" };
    data->difficult_buttons[3] = (Button){ -button_width / 2, -0.3f, button_width, button_height, "Back" };

    data->size_buttons[0] = (Button){ -button_width / 2,  0.3f, button_width, button_height, "10x10" };
    data->size_buttons[1] = (Button){ -button_width / 2,  0.0f, button_width, button_height, "15x15" };
    data->size_buttons[2] = (Button){ -button_width / 2,  -0.3f, button_width, button_height, "Back" };

    data->mod[0] = (Button){ -button_width / 2,  0.3f, button_width, button_height, "Man VS Bot" };
    data->mod[1] = (Button){ -button_width / 2,  0.0f, button_width, button_height, "Bot VS Bot" };
    data->mod[2] = (Button){ -button_width / 2,  -0.3f, button_width, button_height, "Back" };


    data->mod_bot[0] = (Button){ -button_width + 0.15f,  0.7f, button_width + 0.25f, button_height, "Easy - Easy" };
    data->mod_bot[1] = (Button){ -button_width + 0.15f,  0.5f, button_width + 0.25f, button_height, "Easy - Medium" };
    data->mod_bot[2] = (Button){ -button_width + 0.15f,  0.3f, button_width + 0.25f, button_height, "Easy - Hard" };
    data->mod_bot[3] = (Button){ -button_width + 0.15f,  0.1f, button_width + 0.25f, button_height, "Medium - Medium" };
    data->mod_bot[4] = (Button){ -button_width + 0.15f, -0.1f, button_width + 0.25f, button_height, "Medium - Hard" };
    data->mod_bot[5] = (Button){ -button_width + 0.15f, -0.3f, button_width + 0.25f, button_height, "Hard - Hard" };
    data->mod_bot[6] = (Button){ -button_width + 0.15f, -0.5f, button_width + 0.25f, button_height, "Back" };

    data->game_buttons[0] = (Button){ 1.1f,  -0.8f, 0.4f, 0.10f , "" };
    data->game_buttons[1] = (Button){ 1.1f,  -0.65f, 0.4f, 0.10f, "" };

    data->game_save[0] = (Button){ -0.45f,  0.1f, 0.2f, 0.15f , "Yes" };
    data->game_save[1] = (Button){ -0.20f,  0.1f, 0.2f, 0.15f, "No" };
    data->game_save[2] = (Button){ 0.05f,  0.1f, 0.4f, 0.15f, "Cancel" };

    data->game_load[0] = (Button){ -button_width / 2,  0.3f, button_width, button_height, "New game" };
    data->game_load[1] = (Button){ -button_width / 2,  0.0f, button_width, button_height, "Continue" };
    data->game_load[2] = (Button){ -button_width / 2,  -0.3f, button_width, button_height, "Back" };
}

void quads(float x, float y, float x_s, float y_s) {
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + x_s, y);
    glVertex2f(x + x_s, y - y_s);
    glVertex2f(x, y - y_s);
    glEnd();
    glColor3f(1.0f, 1.0f, 1.0f);
}

void lines(float x, float y, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x, y);
    glVertex2f(x2, y2);
    glEnd();
}

void fast_print(char* txt, float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    glRasterPos2f(x, y);
    for (int j = 0; txt[j] != '\0'; j++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[j]);
    glColor3f(1.0f, 1.0f, 1.0f);
}

void draw_table(global_data* data, record_node* record) {
    if (data->flag_table == 1) {
        glColor3f(0.07f, 0.07f, 0.07f);
        quads(-0.1f, 0.7f, 0.9f, 1.65f);
        glColor3f(0.2f, 0.6f, 1.0f);
        quads(-0.1f, 0.9f, 0.9f, 0.15f);
        print_text(data, "Record", 0.2f, 0.80f);
        lines(-0.1f, 0.7f, -0.1f, -0.95f);
        lines(0.0f, 0.7f, 0.0f, -0.95f);
        lines(0.6f, 0.7f, 0.6f, -0.95f);
        lines(0.8f, 0.7f, 0.8f, -0.95f);
        float y = 0.7f;
        for (int i = 0; i < 12; i++) {
            lines(-0.1f, y, 0.8f, y);
            y = y - 0.15f;
        }
        lines(-0.1f, 0.7f, 0.8f, 0.7f);
        fast_print("N*", -0.08f, 0.6f);
        fast_print("PLAYER", 0.21f, 0.6f);
        fast_print("PTS", 0.65f, 0.6f);
        float num_y = 0.45f;
        char num[3] = { 0 };
        for (int i = 1; i <= 9; i++) {
            sprintf(num, "%d", i);
            fast_print(num, -0.07f, num_y);
            num_y = num_y - 0.15f;
        }
        sprintf(num, "%d", 10);
        fast_print(num, -0.08f, num_y);
        //if(record->nick!=NULL) fast_print(record->nick, 0.21f, 0.45);
        num_y = 0.45f;
        while (record != NULL) {
            fast_print(record->nick, 0.21f, num_y);
            sprintf(num, "%d", record->score_chel);
            fast_print(num, 0.62f, num_y);
            sprintf(num, "%d", record->score_bot);
            fast_print(":", 0.68f, num_y);
            fast_print(num, 0.70f, num_y);
            num_y = num_y - 0.15f;
            record = record->ptr_next;
        }
    }
}

// проверям куда нажали мышкой 
void mouse_func(GLFWwindow* window, int button, int action, int mods) {
    global_data* data = (global_data*)glfwGetWindowUserPointer(window);
    const char* selectedDifficulty = "0";
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double x_positition, y_position;
        int width, height;
        glfwGetCursorPos(window, &x_positition, &y_position);
        glfwGetWindowSize(window, &width, &height);

        float normal_x = (x_positition / width) * 2.0f - 1.0f;
        float normal_y = 1.0f - (y_position / height) * 2.0f;
        if (!data->flag_difficult && !data->flag_size && !data->field_size && !data->flag_menu && !data->flag_mod && !data->flag_game_load) {
            for (int i = 0; i < BUTTON_MAIN; i++) {
                if (normal_x >= data->main_buttons[i].x && normal_x <= data->main_buttons[i].x + data->main_buttons[i].width
                    && normal_y <= data->main_buttons[i].y && normal_y >= data->main_buttons[i].y - data->main_buttons[i].height) {
                    printf("Кнопка '%s'\n", data->main_buttons[i].name);
                    if (strcmp(data->main_buttons[i].name, "Exit") == 0) {
                        glfwSetWindowShouldClose(window, GLFW_TRUE);
                    }
                    if (strcmp(data->main_buttons[i].name, "Settings") == 0) {
                        data->flag_menu = 1;
                        download_background(data, "rules.jpg");
                    }
                    if (strcmp(data->main_buttons[i].name, "Play") == 0) {
                        if (data->flag_save == 0) data->flag_mod = 1;
                        else data->flag_game_load = 1;
                    }
                    if (strcmp(data->main_buttons[i].name, "Records") == 0) {
                        if (data->flag_table == 0) data->flag_table = 1;
                        else data->flag_table = 0;
                    }
                }
            }
        }
        else if (data->flag_menu) {
            if (normal_x >= data->size_buttons[2].x && normal_x <= data->size_buttons[2].x + data->size_buttons[2].width &&
                normal_y <= data->size_buttons[2].y && normal_y >= data->size_buttons[2].y - data->size_buttons[2].height) {
                data->flag_menu = 0;
                download_background(data, "background.jpg");
            }
        }
        else if (data->flag_game_load && !data->flag_mod) {
            for (int i = 0; i < 3; i++) {
                if (normal_x >= data->game_load[i].x && normal_x <= data->game_load[i].x + data->game_load[i].width &&
                    normal_y <= data->game_load[i].y && normal_y >= data->game_load[i].y - data->game_load[i].height) {
                    if (strcmp(data->game_load[i].name, "New game") == 0) {
                        data->flag_mod = 1;
                        FILE* file = fopen("game_saving.txt", "w");
                      
                    }
                    else if (strcmp(data->game_load[i].name, "Continue") == 0) {
                        load_game(data, "game_saving.txt");

                    }
                    else if (strcmp(data->game_load[i].name, "Back") == 0) {
                        data->flag_game_load = 0;
                    }
                    printf("Загрузка: %s\n", data->game_load->name);
                }
            }
        }
        else if (data->flag_mod && !data->flag_size) {
            for (int i = 0; i < BUTTON_MOD; i++) {
                if (normal_x >= data->mod[i].x && normal_x <= data->mod[i].x + data->mod[i].width &&
                    normal_y <= data->mod[i].y && normal_y >= data->mod[i].y - data->mod[i].height) {
                    if (strcmp(data->mod[i].name, "Man VS Bot") == 0) {
                        data->mod_type = 1;
                        data->flag_size = 1;
                    }
                    else if (strcmp(data->mod[i].name, "Bot VS Bot") == 0) {
                        data->flag_size = 1;
                        data->mod_type = 2;
                    }
                    else if (strcmp(data->mod[i].name, "Back") == 0) {
                        data->flag_mod = 0;
                    }
                    printf("Рeжим: %d\n", data->mod_type);
                }

            }

        }
        else if (!data->field_size && data->flag_mod && data->flag_size) {
            for (int i = 0; i < BUTTON_SIZE_FIELD; i++) {
                if (normal_x >= data->size_buttons[i].x && normal_x <= data->size_buttons[i].x + data->size_buttons[i].width &&
                    normal_y <= data->size_buttons[i].y && normal_y >= data->size_buttons[i].y - data->size_buttons[i].height) {
                    if (strcmp(data->size_buttons[i].name, "10x10") == 0) {
                        data->field_size = 10;
                        data->flag_difficult = 1;
                    }
                    else if (strcmp(data->size_buttons[i].name, "15x15") == 0) {
                        data->field_size = 15;
                        data->flag_difficult = 1;
                    }
                    else if (strcmp(data->size_buttons[i].name, "Back") == 0) {
                        data->mod_type = 0;
                        data->flag_size = 0;
                        data->field_size = 0;
                    }
                    printf("Размер поля: %d\n", data->field_size);
                }
            }
        }
        else  if (data->field_size && !data->flag_start && data->mod_type == 1) {
            for (int i = 0; i < BUTTON_DIFFICULT; i++) {
                if (normal_x >= data->difficult_buttons[i].x && normal_x <= data->difficult_buttons[i].x + data->difficult_buttons[i].width
                    && normal_y <= data->difficult_buttons[i].y && normal_y >= data->difficult_buttons[i].y - data->difficult_buttons[i].height) {
                    if (strcmp(data->difficult_buttons[i].name, "Back") == 0) {
                        data->flag_difficult = 0;
                        data->field_size = 0;
                        data->flag_start = 0;
                    }
                    else {
                        if (strcmp(data->difficult_buttons[i].name, "Easy") == 0) {
                            data->flag_start = 1;
                            data->mode_difficult = 1;
                        }
                        if (strcmp(data->difficult_buttons[i].name, "Medium") == 0) {
                            data->flag_start = 1;
                            data->mode_difficult = 2;
                        }
                        if (strcmp(data->difficult_buttons[i].name, "Hard") == 0) {
                            data->flag_start = 1;
                            data->mode_difficult = 3;
                        }
                        printf("Сложность: %d\n", data->mode_difficult);
                    }
                }
            }
        }
        else if (data->mod_type == 2 && !data->flag_start) {
            for (int i = 0; i < BUTTON_MOD_BOT; i++) {
                if (normal_x >= data->mod_bot[i].x && normal_x <= data->mod_bot[i].x + data->mod_bot[i].width
                    && normal_y <= data->mod_bot[i].y && normal_y >= data->mod_bot[i].y - data->mod_bot[i].height) {
                    if (strcmp(data->mod_bot[i].name, "Back") == 0) {
                        //data->mod_type = 0;
                        data->flag_difficult = 0;
                        data->field_size = 0;
                    }
                    else {
                        if (strcmp(data->mod_bot[i].name, "Easy - Easy") == 0) {
                            data->flag_start = 1;
                            data->mode_difficult = 1;
                        }
                        if (strcmp(data->mod_bot[i].name, "Easy - Medium") == 0) {
                            data->flag_start = 1;
                            data->mode_difficult = 2;
                        }
                        if (strcmp(data->mod_bot[i].name, "Easy - Hard") == 0) {
                            data->flag_start = 1;
                            data->mode_difficult = 3;
                        }

                        if (strcmp(data->mod_bot[i].name, "Medium - Medium") == 0) {
                            data->flag_start = 1;
                            data->mode_difficult = 4;
                        }

                        if (strcmp(data->mod_bot[i].name, "Medium - Hard") == 0) {
                            data->flag_start = 1;
                            data->mode_difficult = 5;
                        }

                        if (strcmp(data->mod_bot[i].name, "Hard - Hard") == 0) {
                            data->flag_start = 1;
                            data->mode_difficult = 6;
                        }
                        printf("Сложность: %d\n", data->mode_difficult);
                    }
                }
            }
        }
    }
}

//устанавливаем новые координаты
void new_coordinate(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float ratio = (float)width / height;
    // printf("ac=%f\n", aspect);

    if (ratio >= 1.0f) {
        glOrtho(-ratio, ratio, -1.0, 1.0, -1.0, 1.0);
    }
    else {
        glOrtho(-1.0, 1.0, -1.0 / ratio, 1.0 / ratio, -1.0, 1.0);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//левая таблица
void draw_grid_left(global_data* data, int size) {
    float grid_size = 1.1f / size;
    for (int i = 0; i <= size; i++) {
        glBegin(GL_LINES);
        glVertex2f(-1.3f + i * grid_size, -0.5f);
        glVertex2f(-1.3f + i * grid_size, -0.5f + size * grid_size);
        glEnd();
        glRasterPos2f(-1.3f + i * grid_size + grid_size / 2 - 0.01f, 0.63f);
        //const char character[15] = "AБВГДЕЁЖЗИЙКЛМН";
        const char character[15] = "ABCDEFGHIJKLMNO";
        if (i != size) glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, character[i]);
    }

    for (int i = 0; i <= size; i++) {
        glBegin(GL_LINES);
        glVertex2f(-1.3f, -0.5f + i * grid_size);
        glVertex2f(-1.3f + size * grid_size, -0.5f + i * grid_size);
        glEnd();
        glRasterPos2f(-1.35f, -0.5f + i * grid_size + grid_size / 2 - 0.01f);
        if (i != size) {
            char num[3];
            int number = size - i;
            sprintf(num, "%d", number);
            for (int j = 0; num[j] != '\0'; j++)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, num[j]);
        }
    }
    glPushMatrix();
    glScalef(1.7f, 1.7f, 1.0f);
    print_text(data, "WAR SHIP", -0.23f, 0.45f);
    glPopMatrix();

}
//правая таблица
void draw_grid_right(int size) {
    float grid_size = 1.1f / size;
    for (int i = 0; i <= size; i++) {
        glBegin(GL_LINES);
        glVertex2f(1.3f - i * grid_size, -0.5f);
        glVertex2f(1.3f - i * grid_size, -0.5f + size * grid_size);
        glEnd();
        glRasterPos2f(1.3f - i * grid_size - grid_size / 2 - 0.01f, 0.63f);
        //const char character[15] = "AБВГДЕЁЖЗИЙКЛМН";
        const char character[15] = "ABCDEFGHIJKLMNO";
        if (i != size) glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, character[size - 1 - i]);
    }

    for (int i = 0; i <= size; i++) {
        glBegin(GL_LINES);
        glVertex2f(1.3f, -0.5f + i * grid_size);
        glVertex2f(1.3f - size * grid_size, -0.5f + i * grid_size);
        glEnd();
        glRasterPos2f(0.15f, -0.5f + i * grid_size + grid_size / 2 - 0.01f);
        if (i != size) {
            char num[3];
            int number = size - i;
            sprintf(num, "%d", number);
            for (int j = 0; num[j] != '\0'; j++)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, num[j]);
        }
    }
}

void draw_ship(int size, float x, float y) {
    float grid_size = 1.1f / 20;
    for (int i = 0; i <= size; i++) {
        glBegin(GL_LINES);
        glVertex2f(x + i * grid_size, y);
        glVertex2f(x + i * grid_size, y + grid_size);
        glEnd();
    }

    for (int i = 0; i <= 1; i++) {
        glBegin(GL_LINES);
        glVertex2f(x, y + i * grid_size);
        glVertex2f(x + size * grid_size, y + i * grid_size);
        glEnd();
    }
}

void enter(char* txt, float x, float y) {
    glColor3f(0.0f, 0.0f, 1.0f);
    glRasterPos2f(x, y);
    for (int j = 0; txt[j] != '\0'; j++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, txt[j]);
    glColor3f(1.0f, 1.0f, 1.0f);
}

void calc_ten_ship(global_data* data) {
    glPushMatrix();
    glScalef(0.67f, 0.7f, 1.0f);
    print_text(data, "SHIP:", -2.45f, -0.8f);
    print_text(data, "WEAPON:", -2.55f, 0.3f);
    print_text(data, "*", -2.43f, 0.15f);
    print_text(data, "**", -2.45f, 0.13f);
    print_text(data, "*", -2.43f, 0.11f);
    glPopMatrix();
    draw_ship(4, -1.65, -0.65);
    draw_ship(3, -1.65, -0.75);
    draw_ship(2, -1.65, -0.85);
    draw_ship(1, -1.65, -0.95);
    enter("/ 1", -1.38, -0.63);
    enter("/ 2", -1.38, -0.73);
    enter("/ 3", -1.38, -0.83);
    enter("/ 4", -1.38, -0.93);
    enter("/ 3", -1.5, 0.12);
    enter("/ 3", -1.5, 0.025);
    char num[4];
    if (data->count_click == 0 && data->napr == -1)  enter("o", -1.7, -0.63);
    if (data->napr == 1) {
        if (data->count_click == 0)  enter("o>", -1.7, -0.63);
        if (data->count_click >= 1 && data->count_click < 3)  enter("o>", -1.7, -0.73);
        if (data->count_click >= 3 && data->count_click < 6)  enter("o>", -1.7, -0.83);
        if (data->count_click >= 6 && data->count_click < 10)  enter("o>", -1.7, -0.93);
    }
    if (data->napr == 0) {
        if (data->count_click == 0) {
            enter("o", -1.7, -0.63);
            enter("v", -1.7, -0.655);
        }
        if (data->count_click >= 1 && data->count_click < 3) {
            enter("o", -1.7, -0.73);
            enter("v", -1.7, -0.755);
        }
        if (data->count_click >= 3 && data->count_click < 6) {
            enter("o", -1.7, -0.83);
            enter("v", -1.7, -0.855);
        }
        if (data->count_click >= 6 && data->count_click < 10) {
            enter("o", -1.7, -0.93);
            enter("v", -1.7, -0.955);
        }
    }
    if (data->count_click >= 10 && data->count_click < 13) {
        enter("o>", -1.7, 0.12);
    }
    if (data->count_click == 1) data->temp_1 = 1;
    sprintf(num, "%d", data->temp_1);
    enter(num, -1.41, -0.63);
    if (data->count_click == 2) data->temp_2 = 1;
    if (data->count_click == 3) data->temp_2 = 2;
    sprintf(num, "%d", data->temp_2);
    enter(num, -1.41, -0.73);
    if (data->count_click == 4) data->temp_3 = 1;
    if (data->count_click == 5) data->temp_3 = 2;
    if (data->count_click == 6) data->temp_3 = 3;
    sprintf(num, "%d", data->temp_3);
    enter(num, -1.41, -0.83);
    if (data->count_click == 7) data->temp_4 = 1;
    if (data->count_click == 8) data->temp_4 = 2;
    if (data->count_click == 9) data->temp_4 = 3;
    if (data->count_click == 10) data->temp_4 = 4;
    sprintf(num, "%d", data->temp_4);
    enter(num, -1.41, -0.93);
    if (data->count_click == 7) data->temp_4 = 1;
    if (data->count_click == 8) data->temp_4 = 2;
    if (data->count_click == 9) data->temp_4 = 3;
    if (data->count_click == 10) data->temp_4 = 4;
    if (data->count_click == 11) data->temp_5 = 1;
    if (data->count_click == 12) data->temp_5 = 2;
    if (data->count_click == 13) data->temp_5 = 3;
    sprintf(num, "%d", data->temp_5);
    enter(num, -1.53, 0.12);
    sprintf(num, "%d", data->count_radar);
    enter(num, -1.53, 0.025);
    if ((data->count_hod_chel[0] - data->hod_radar >= 5 || (data->hod_radar == 0 && data->flag_radar_new == 0)) &&
        data->count_click_radar == 0 && data->count_radar > 0) enter("+", -1.7, 0.025);
    else  enter("-", -1.7, 0.025);
    glPushMatrix();
    glScalef(0.4f, 0.4f, 0.4f);
    print_text(data, "((o))", -4.13f, 0.09f);
    print_text(data, "|", -4.043f, 0.04f);
    glPopMatrix();
}

void calc_fi_ship(global_data* data) {
    glPushMatrix();
    glScalef(0.67f, 0.7f, 1.0f);
    print_text(data, "SHIP:", -2.55f, -0.65f);
    print_text(data, "WEAPON:", -2.55f, 0.3f);
    print_text(data, "*", -2.43f, 0.15f);
    print_text(data, "**", -2.45f, 0.13f);
    print_text(data, "*", -2.43f, 0.11f);
    glPopMatrix();
    draw_ship(5, -1.71, -0.55);
    draw_ship(4, -1.71, -0.65);
    draw_ship(3, -1.71, -0.75);
    draw_ship(2, -1.71, -0.85);
    draw_ship(1, -1.71, -0.95);
    enter("/ 1", -1.4, -0.53);
    enter("/ 1", -1.4, -0.63);
    enter("/ 2", -1.4, -0.73);
    enter("/ 3", -1.4, -0.83);
    enter("/ 4", -1.4, -0.93);
    enter("/ 5", -1.5, 0.12);
    enter("/ 3", -1.5, 0.025);
    char num[4];
    if (data->count_click == 0 && data->napr == -1)  enter("o", -1.76, -0.53);
    if (data->napr == 1) {
        if (data->count_click == 0)  enter("o>", -1.76, -0.53);
        if (data->count_click == 1)  enter("o>", -1.76, -0.63);
        if (data->count_click >= 2 && data->count_click < 4)  enter("o>", -1.76, -0.73);
        if (data->count_click >= 4 && data->count_click < 7)  enter("o>", -1.76, -0.83);
        if (data->count_click >= 7 && data->count_click < 11)  enter("o>", -1.76, -0.93);
    }
    if (data->napr == 0) {
        if (data->count_click == 0) {
            enter("o", -1.76, -0.53);
            enter("v", -1.76, -0.555);
        }
        if (data->count_click == 1) {
            enter("o", -1.76, -0.63);
            enter("v", -1.76, -0.655);
        }
        if (data->count_click >= 2 && data->count_click < 4) {
            enter("o", -1.76, -0.73);
            enter("v", -1.76, -0.755);
        }
        if (data->count_click >= 4 && data->count_click < 7) {
            enter("o", -1.76, -0.83);
            enter("v", -1.76, -0.855);
        }
        if (data->count_click >= 7 && data->count_click < 11) {
            enter("o", -1.76, -0.93);
            enter("v", -1.76, -0.955);
        }
    }
    if (data->count_click >= 11 && data->count_click < 16) {
        enter("o>", -1.7, 0.12);
    }
    if (data->count_click == 1) data->temp_5 = 1;
    sprintf(num, "%d", data->temp_5);
    enter(num, -1.43, -0.53);
    if (data->count_click == 2) data->temp_1 = 1;
    sprintf(num, "%d", data->temp_1);
    enter(num, -1.43, -0.63);
    if (data->count_click == 3) data->temp_2 = 1;
    if (data->count_click == 4) data->temp_2 = 2;
    sprintf(num, "%d", data->temp_2);
    enter(num, -1.43, -0.73);
    if (data->count_click == 5) data->temp_3 = 1;
    if (data->count_click == 6) data->temp_3 = 2;
    if (data->count_click == 7) data->temp_3 = 3;
    sprintf(num, "%d", data->temp_3);
    enter(num, -1.43, -0.83);
    if (data->count_click == 8) data->temp_4 = 1;
    if (data->count_click == 9) data->temp_4 = 2;
    if (data->count_click == 10) data->temp_4 = 3;
    if (data->count_click == 11) data->temp_4 = 4;
    sprintf(num, "%d", data->temp_4);
    enter(num, -1.43, -0.93);
    if (data->count_click == 12) data->temp_6 = 1;
    if (data->count_click == 13) data->temp_6 = 2;
    if (data->count_click == 14) data->temp_6 = 3;
    if (data->count_click == 15) data->temp_6 = 4;
    if (data->count_click == 16) data->temp_6 = 5;
    sprintf(num, "%d", data->temp_6);
    enter(num, -1.53, 0.12);
    sprintf(num, "%d", data->count_radar);
    enter(num, -1.53, 0.025);
    if ((data->count_hod_chel[0] - data->hod_radar >= 5 || (data->hod_radar == 0 && data->flag_radar_new == 0)) &&
        data->count_click_radar == 0 && data->count_radar > 0) enter("+", -1.7, 0.025);
    else  enter("-", -1.7, 0.025);
    glPushMatrix();
    glScalef(0.4f, 0.4f, 0.4f);
    print_text(data, "((o))", -4.13f, 0.09f);
    print_text(data, "|", -4.043f, 0.04f);
    glPopMatrix();
}

void calc_kill(global_data* data) {
    if (data->field_size == 10) {
        glPushMatrix();
        glScalef(0.67f, 0.7f, 1.0f);
        print_text(data, "KILL", -2.45f, 0.8f);
        print_text(data, "/ 10", -2.35f, 0.6f);
        print_text(data, "KILL", 2.15f, 0.8f);
        print_text(data, "/ 10", 2.25f, 0.6f);
        int count_chel = 0;
        int count_bot = 0;
        char num[4];
        count_chel = data->count_ship_kil_by_player[0];
        count_bot = data->count_ship_kil_by_bot[0];
        if (data->chel_or_bot_attack == chel_win) {
            data->count_ship_kil_by_player[0] = 10;
            count_chel = 10;
        }

        if (data->chel_or_bot_attack == bot_win) {
            count_bot = 10;
            data->count_ship_kil_by_bot[0] = 10;
        }

        sprintf(num, "%d", count_chel);

        print_text(data, num, -2.45f, 0.6f);

        sprintf(num, "%d", count_bot);
        print_text(data, num, 2.15f, 0.6f);

        glPopMatrix();
    }
    if (data->field_size == 15) {
        glPushMatrix();
        glScalef(0.67f, 0.7f, 1.0f);
        print_text(data, "KILL", -2.45f, 0.8f);
        print_text(data, "/ 11", -2.35f, 0.6f);
        print_text(data, "KILL", 2.15f, 0.8f);
        print_text(data, "/ 11", 2.25f, 0.6f);
        int count_chel = 0;
        int count_bot = 0;
        char num[4];
        count_chel = data->count_ship_kil_by_player[0];
        count_bot = data->count_ship_kil_by_bot[0];
        if (data->chel_or_bot_attack == chel_win) {
            data->count_ship_kil_by_player[0] = 11;
            count_chel = 11;
        }
        if (data->chel_or_bot_attack == bot_win) {
            data->count_ship_kil_by_bot[0] = 11;
            count_bot = 11;
        }

        sprintf(num, "%d", count_chel);

        print_text(data, num, -2.45f, 0.6f);

        sprintf(num, "%d", count_bot);
        print_text(data, num, 2.15f, 0.6f);
        glPopMatrix();
    }

}

void print_bot(global_data* data) {
    glPushMatrix();
    glScalef(0.67f, 0.7f, 1.0f);
    print_text(data, "BOT 1", -2.45f, 0.9f);
    print_text(data, "BOT 2", 2.15f, 0.9f);
    if (data->mode_difficult == 1) {
        print_text(data, "EASY", -2.45f, 1.0f);
        print_text(data, "EASY", 2.155f, 1.0f);
    }
    else if (data->mode_difficult == 2) {
        print_text(data, "EASY", -2.45f, 1.0f);
        print_text(data, "MEDIUM", 2.15f, 1.0f);
    }
    else if (data->mode_difficult == 3) {
        print_text(data, "EASY", -2.45f, 1.0f);
        print_text(data, "HARD", 2.15f, 1.0f);
    }
    else if (data->mode_difficult == 4) {
        print_text(data, "MEDIUM", -2.45f, 1.0f);
        print_text(data, "MEDIUM", 2.15f, 1.0f);
    }
    else if (data->mode_difficult == 5) {
        print_text(data, "MEDIUM", -2.45f, 1.0f);
        print_text(data, "HARD", 2.15f, 1.0f);
    }
    else if (data->mode_difficult == 6) {
        print_text(data, "HARD", -2.45f, 1.0f);
        print_text(data, "HARD", 2.15f, 1.0f);
    }

    if (data->flag_get_pole_bot == 0) {
        glPushMatrix();
        glScalef(1.2f, 1.2f, 1.2f);
        print_text(data, "PRESS 1 TO START GAME", -0.57f, -0.85f);
        glPopMatrix();
    }
    else {
        glPushMatrix();
        glScalef(1.0f, 0.7f, 1.0f);
        print_text(data, "HOLD 1 - PAUSE", -2.5f, -1.5f);
        print_text(data, "PRESS 0 - START", -2.5f, -1.7f);
        glPopMatrix();
    }

    glPopMatrix();
}

int press_zero_one(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
        return 1;
    }
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS) {
        return 0;
    }
    return -1;
}

int press_enter_space(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
        return 1;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        return 0;
    }
    return -1;
}

int press_attachment(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        return 1;
    }
    return 0;
}

//раскраска клеток поля 10/15
void fill_cells(global_data* data, int size, int pole[10][10], int flag) {
    float grid_size = 1.1f / size;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            int value = pole[row][col];
            if (value == 0) glColor3f(0.0f, 0.0f, 1.0f);
            else if (value == 6) glColor3f(0.8f, 0.8f, 0.8f);
            else if (value == 8)  glColor3f(1.0f, 0.0f, 0.0f);
            else if (value == 7 && (data->flag_end_get_pole == 0 && data->flag_get_pole_bot == 0)) glColor3f(0.2f, 0.6f, 0.8f);
            else if (value == 7 && (data->flag_end_get_pole != 0 || data->flag_get_pole_bot == 1)) glColor3f(0.0f, 0.0f, 1.0f);
            else if (value == 9) glColor3f(0.0, 0.0, 0.0);
            else if (value == 10) glColor3f(0.07f, 0.07f, 0.07f);
            else glColor3f(0.25f, 0.25f, 0.25f);
            float x = 0;
            float y = 0;
            if (flag == 0) {
                x = -1.3f + col * grid_size;
                y = -0.5f + size * grid_size - grid_size - row * grid_size;
            }
            else {
                x = 1.3f - size * grid_size + col * grid_size;
                y = -0.5f + size * grid_size - grid_size - row * grid_size;
            }

            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + grid_size, y);
            glVertex2f(x + grid_size, y + grid_size);
            glVertex2f(x, y + grid_size);
            glEnd();
        }
    }
    glColor3f(1.0f, 1.0f, 1.0f);
}

void fill_cells_rt(global_data* data, int size, int pole_bot[10][10]) {
    float grid_size = 1.1f / size;

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            int value = pole_bot[row][col];
            if (value == 6) {
                glColor3f(0.8f, 0.8f, 0.8f);
            }
            else if (value == 8) {
                glColor3f(1.0f, 0.0f, 0.0f);
            }
            else if (value == 10) glColor3f(0.0, 0.0, 0.0);
            else {
                glColor3f(0.0f, 0.0f, 1.0f);
            }

            // float x = 1.3f - col * grid_size-row;
            float x = 1.3f - size * grid_size + col * grid_size;
            float y = -0.5f + size * grid_size - grid_size - row * grid_size;

            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + grid_size, y);
            glVertex2f(x + grid_size, y + grid_size);
            glVertex2f(x, y + grid_size);
            glEnd();
        }
    }
    glColor3f(1.0f, 1.0f, 1.0f);
}

void fill_cells_rf(global_data* data, int size, int pole_bot[15][15]) {
    float grid_size = 1.1f / size;

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            int value = pole_bot[row][col];
            if (value == 6) {
                glColor3f(0.8f, 0.8f, 0.8f);
            }
            else if (value == 8) {
                glColor3f(1.0f, 0.0f, 0.0f);
            }
            else if (value == 10) glColor3f(0.0, 0.0, 0.0);
            else {
                glColor3f(0.0f, 0.0f, 1.0f);
            }

            // float x = 1.3f - col * grid_size-row;
            float x = 1.3f - size * grid_size + col * grid_size;
            float y = -0.5f + size * grid_size - grid_size - row * grid_size;

            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + grid_size, y);
            glVertex2f(x + grid_size, y + grid_size);
            glVertex2f(x, y + grid_size);
            glEnd();
        }
    }
    glColor3f(1.0f, 1.0f, 1.0f);
}

void fill_cells_fi(global_data* data, int size, int pole[15][15], int flag) {
    float grid_size = 1.1f / size;

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            int value = pole[row][col];
            if (value == 0) glColor3f(0.0f, 0.0f, 1.0f);
            else if (value == 6) glColor3f(0.8f, 0.8f, 0.8f);
            else if (value == 8)  glColor3f(1.0f, 0.0f, 0.0f);
            else if (value == 7 && (data->flag_end_get_pole == 0 && data->flag_get_pole_bot == 0)) glColor3f(0.2f, 0.6f, 0.8f);
            else if (value == 7 && (data->flag_end_get_pole != 0 || data->flag_get_pole_bot == 1)) glColor3f(0.0f, 0.0f, 1.0f);
            else if (value == 9) glColor3f(0.0, 0.0, 0.0);
            else if (value == 10) glColor3f(0.07f, 0.07f, 0.07f);
            else glColor3f(0.25f, 0.25f, 0.25f);

            float x = 0;
            float y = 0;
            if (flag == 0) {
                x = -1.3f + col * grid_size;
                y = -0.5f + size * grid_size - grid_size - row * grid_size;
            }
            else {
                x = 1.3f - size * grid_size + col * grid_size;
                y = -0.5f + size * grid_size - grid_size - row * grid_size;
            }

            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + grid_size, y);
            glVertex2f(x + grid_size, y + grid_size);
            glVertex2f(x, y + grid_size);
            glEnd();
        }
    }
    glColor3f(1.0f, 1.0f, 1.0f);
}

//на какую клетку указал курсор
void mouse_for_rigth_table(GLFWwindow* window, int button, int action, int mods) {
    global_data* data = (global_data*)glfwGetWindowUserPointer(window);
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);

        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        float ratio = (float)width / height;
        float normal_x = ((xpos / width) * 2.0f - 1.0f) * ratio;
        float normal_y = 1.0f - (ypos / height) * 2.0f;
        if (normal_x >= data->game_buttons[0].x && normal_x <= data->game_buttons[0].x + data->game_buttons[0].width
            && normal_y <= data->game_buttons[0].y && normal_y >= data->game_buttons[0].y - data->game_buttons[0].height) {
            printf("Кнопка: continue\n");
            data->flag_continue = 1;
        }
        if (normal_x >= data->game_buttons[1].x && normal_x <= data->game_buttons[1].x + data->game_buttons[1].width
            && normal_y <= data->game_buttons[1].y && normal_y >= data->game_buttons[1].y - data->game_buttons[1].height) {
            data->flag_back_menu = 1;
            printf("Кнопка: menu\n");
        }
        if (data->flag_back_menu) {
            for (int i = 0; i < 3; i++) {
                if (normal_x >= data->game_save[i].x && normal_x <= data->game_save[i].x + data->game_save[i].width
                    && normal_y <= data->game_save[i].y && normal_y >= data->game_save[i].y - data->game_save[i].height) {
                    printf("Кнопка '%s'\n", data->game_save[i].name);
                    if (strcmp(data->game_save[i].name, "Yes") == 0) {
                        data->flag_save = 1;
                        save_game(data, "game_saving.txt");
                        delete_save_data(data);
                    }
                    if (strcmp(data->game_save[i].name, "No") == 0) {
                        data->flag_save = 0;
                        delete_save_data(data);
                        FILE* file = fopen("game_saving.txt", "w");
                    }
                    if (strcmp(data->game_save[i].name, "Cancel") == 0) {
                        data->flag_back_menu = 0;
                    }
                }
            }
        }
        //printf("mouse_x==%f\n", normal_x);
        //printf("mouse_y==%f\n", normal_y);


        //printf("rat=%f\n", ratio);
        float mouse_x = (float)xpos / (float)width * 2.0f - ratio;
        // printf("mouse_x==%f\n", mouse_x);
        float mouse_y = -((float)ypos / (float)height * 2.0f - 1.0f);
        //printf("mouse_y==%f\n", mouse_y);

        int size = data->field_size;
        float grid_size_y = 1.1f / data->field_size;
        float grid_size_x = (1.1f / data->field_size / ratio); //т.к ось x расстянута
        //printf("size==%f\n", grid_size_x);
        float grid_origin_x = -1.5f;
        //printf("sfdf=%f\n", mouse_x - grid_origin_x);
        float grid_origin_y = 0.6f;
        // click(mouse_x, mouse_y, grid_origin_x, grid_origin_y, grid_size, size);
        int grid_x = (int)((mouse_x - grid_origin_x) / grid_size_x);
        int grid_y = (int)((fabs(mouse_y - grid_origin_y)) / grid_size_y);
        //printf("abs==%f\n", fabs(mouse_y - grid_origin_y));

        if (data->flag_end_get_pole != 1 && data->flag_continue == 0 && data->flag_back_menu==0) {
            if (data->field_size == 10 && grid_y >= 0 && grid_y < 10 && mouse_y < 0.6f
                && grid_x >= 0 && grid_x < 10) {
                printf("Cтолбец:%d\n", grid_x);
                printf("Строка: %d\n", grid_y);
                data->count_click += 1;
                // printf("click==%d", data->count_click);
                if (data->count_click < 14)
                    // printf("click==%d\n", data->count_click);
                    data->count_click = placement_ten(data->my_pole_ten, data->count_click, grid_x, grid_y, data->napr);
                //printf("click==%d", data->count_click);
            }
            if (data->field_size == 15 && grid_y >= 0 && grid_y < 15 && mouse_y < 0.6f
                && grid_x >= 0 && grid_x < 15) {
                printf("Cтолбец:%d\n", grid_x);
                printf("Строка: %d\n", grid_y);
                data->count_click += 1;
                if (data->count_click < 17)
                    //printf("click==%d", data->count_click);
                    data->count_click = placement_fi(data->my_pole_fi, data->count_click, grid_x, grid_y, data->napr);
            }
        }
        if (data->flag_end_get_pole == 1 && data->flag_continue == 0 && data->flag_back_menu == 0) {
            float grid_origin_x = -0.66f;
            float grid_origin_y = 0.6f;
            int grid_x = (int)((mouse_x - grid_origin_x) / grid_size_x);
            int grid_y = (int)((fabs(mouse_y - grid_origin_y)) / grid_size_y);
            if (data->field_size == 10 && grid_y >= 0 && grid_y < 10 && mouse_y < 0.6f
                && grid_x >= 0 && grid_x < 10) {
                //data->chel_or_bot_attack = 1;
                printf("Cтолбец:%d\n", grid_x);
                printf("Строка: %d\n", grid_y);
                int temp = 0;
                if (data->flag_radar_chel == 1) {
                    data->temp_radar = data->count_hod_chel[0];
                }

                if (data->flag_radar_chel == 1 && (data->temp_radar - data->hod_radar >= 5 || (data->hod_radar == 0 && data->flag_radar_new == 0)) && data->count_click_radar == 0 && data->count_radar > 0) {
                    printf("Радар!");
                    data->count_click_radar = 1;
                    data->flag_radar_new = 1;
                    data->cell_x = grid_x;
                    data->cell_y = grid_y;
                    data->hod_radar = data->temp_radar;
                    data->flag_get_cell_radar = 1;
                    data->count_radar = data->count_radar - 1;
                }
                else {
                    if ((data->count_ship_kil_by_bot != 10 || data->count_ship_kil_by_player != 10) && data->chel_or_bot_attack == 0) {

                        data->count_click_radar = 0;
                        data->chel_or_bot_attack = game_ten(data->my_pole_ten, data->pole_bot_ten, data->otsl_bot_1, data->otsl_bot_2, data->count_ship_kil_by_player, data->count_ship_kil_by_bot, data->radar_count_bot,
                            grid_x, grid_y, data->chel_or_bot_attack, data->mode_difficult, data->count_hod_chel, data->flag_smoke);
                    }
                    if (data->chel_or_bot_attack == hod_bot) {
                        data->chel_or_bot_attack = game_ten(data->my_pole_ten, data->pole_bot_ten, data->otsl_bot_1, data->otsl_bot_2, data->count_ship_kil_by_player, data->count_ship_kil_by_bot, data->radar_count_bot,
                            grid_x, grid_y, data->chel_or_bot_attack, data->mode_difficult, data->count_hod_chel, data->flag_smoke);
                    }
                }
            }
            if (data->field_size == 15 && grid_y >= 0 && grid_y < 15 && mouse_y < 0.6f
                && grid_x >= 0 && grid_x < 15) {
                printf("Cтолбец:%d\n", grid_x);
                printf("Строка: %d\n", grid_y);
                int temp = 0;
                if (data->flag_radar_chel == 1) {
                    data->temp_radar = data->count_hod_chel[0];
                }

                if (data->flag_radar_chel == 1 && (data->temp_radar - data->hod_radar >= 5 || (data->hod_radar == 0 && data->flag_radar_new == 0)) && data->count_click_radar == 0 && data->count_radar > 0) {
                    printf("Радар!");
                    data->count_click_radar = 1;
                    data->flag_radar_new = 1;
                    data->cell_x = grid_x;
                    data->cell_y = grid_y;
                    data->hod_radar = data->temp_radar;
                    data->flag_get_cell_radar = 1;
                    data->count_radar = data->count_radar - 1;
                }
                else {
                    if ((data->count_ship_kil_by_bot != 15 || data->count_ship_kil_by_player != 15) && data->chel_or_bot_attack == 0) {
                        data->count_click_radar = 0;
                        data->chel_or_bot_attack = game_fi(data->my_pole_fi, data->pole_bot_fi, data->otsl_bot_1, data->otsl_bot_2, data->count_ship_kil_by_player, data->count_ship_kil_by_bot, data->radar_count_bot, grid_x, grid_y, data->chel_or_bot_attack, data->mode_difficult, data->count_hod_chel, data->flag_smoke);
                    }
                    if (data->chel_or_bot_attack == hod_bot)
                        data->chel_or_bot_attack = game_fi(data->my_pole_fi, data->pole_bot_fi, data->otsl_bot_1, data->otsl_bot_2, data->count_ship_kil_by_player, data->count_ship_kil_by_bot, data->radar_count_bot, grid_x, grid_y, data->chel_or_bot_attack, data->mode_difficult, data->count_hod_chel, data->flag_smoke);
                }
            }
        }
    }
}

void mouse_for_bot(GLFWwindow* window, int button, int action, int mods) {
    global_data* data = (global_data*)glfwGetWindowUserPointer(window);
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        float ratio = (float)width / height;
        float normal_x = ((xpos / width) * 2.0f - 1.0f) * ratio;
        float normal_y = 1.0f - (ypos / height) * 2.0f;
        if (normal_x >= data->game_buttons[1].x && normal_x <= data->game_buttons[1].x + data->game_buttons[1].width
            && normal_y <= data->game_buttons[1].y && normal_y >= data->game_buttons[1].y - data->game_buttons[1].height) {
            data->flag_back_menu = 1;
            printf("Кнопка: menu\n");
        }
        if (data->flag_back_menu) {
            for (int i = 0; i < 3; i++) {
                if (normal_x >= data->game_save[i].x && normal_x <= data->game_save[i].x + data->game_save[i].width
                    && normal_y <= data->game_save[i].y && normal_y >= data->game_save[i].y - data->game_save[i].height) {
                    printf("Кнопка '%s'\n", data->game_save[i].name);
                    if (strcmp(data->game_save[i].name, "Yes") == 0) {
                        data->flag_save = 1;
                        save_game(data, "game_saving.txt");
                        delete_save_data(data);
                    }
                    if (strcmp(data->game_save[i].name, "No") == 0) {
                        data->flag_save = 0;
                        delete_save_data(data);
                        FILE* file = fopen("game_saving.txt", "w");
                    }
                    if (strcmp(data->game_save[i].name, "Cancel") == 0) {
                        data->flag_back_menu = 0;
                    }
                }
            }
        }
    }
}

void go_placement(global_data* data, GLFWwindow* window) {
    if (((data->field_size == 10 && data->count_click >= 13) || (data->field_size == 15 && data->count_click >= 16)) && data->flag_end_get_pole == 0) {
        //printf("Расстановка закончена\n");
        glPushMatrix();
        glScalef(1.0f, 1.0f, 1.0f);
        print_text(data, "Press ENTER to start game", -0.57f, -0.65f);
        print_text(data, "OR", -0.1f, -0.75f);
        print_text(data, "Press SPACE to replace", -0.57f, -0.85f);
        glPopMatrix();
        if (press_enter_space(window) == 1) {
            data->flag_end_get_pole = 1;
        }
        else if (press_enter_space(window) == 0) {
            data->count_click = 0;
            if (data->field_size == 10) memset(data->my_pole_ten, 0, sizeof(data->my_pole_ten));
            if (data->field_size == 15) memset(data->my_pole_fi, 0, sizeof(data->my_pole_fi));
            data->temp_1 = 0;
            data->temp_2 = 0;
            data->temp_3 = 0;
            data->temp_4 = 0;
            data->temp_5 = 0;
            data->temp_6 = 0;
        }
    }
    if (data->flag_end_get_pole == 1 && data->field_size == 10 && data->flag_get_pole_bot == 0) {
        placement_bot_ten(data->pole_bot_ten, data->mode_difficult, 1, data->mod_type);
        data->flag_get_pole_bot = 1;
    }
    if (data->flag_end_get_pole == 1 && data->field_size == 15 && data->flag_get_pole_bot == 0) {
        placement_bot_fi(data->pole_bot_fi, data->mode_difficult, 1, data->mod_type);
        data->flag_get_pole_bot = 1;
    }
}

void placement_bot(global_data* data) {
    if (data->field_size == 10 && data->flag_get_pole_bot == 0) {
        if (data->mode_difficult == 1) {
            placement_bot_ten(data->my_pole_ten, 1, 1, data->mod_type);
            Sleep(1000);
            placement_bot_ten(data->pole_bot_ten, 1, 1, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
        else if (data->mode_difficult == 2) {
            placement_bot_ten(data->my_pole_ten, 1, 1, data->mod_type);
            Sleep(1000);
            placement_bot_ten(data->pole_bot_ten, 2, 1, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
        else if (data->mode_difficult == 3) {
            placement_bot_ten(data->my_pole_ten, 1, 1, data->mod_type);
            Sleep(1000);
            placement_bot_ten(data->pole_bot_ten, 3, 1, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
        else if (data->mode_difficult == 4) {
            placement_bot_ten(data->my_pole_ten, 2, 1, data->mod_type);
            Sleep(1000);
            placement_bot_ten(data->pole_bot_ten, 2, 2, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
        else if (data->mode_difficult == 5) {
            placement_bot_ten(data->my_pole_ten, 2, 1, data->mod_type);
            Sleep(1000);
            placement_bot_ten(data->pole_bot_ten, 3, 1, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
        else if (data->mode_difficult == 6) {
            placement_bot_ten(data->my_pole_ten, 3, 1, data->mod_type);
            Sleep(1000);
            placement_bot_ten(data->pole_bot_ten, 3, 2, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
    }
    if (data->field_size == 15 && data->flag_get_pole_bot == 0) {
        if (data->mode_difficult == 1) {
            placement_bot_fi(data->my_pole_fi, 1, 1, data->mod_type);
            Sleep(1000);
            placement_bot_fi(data->pole_bot_fi, 1, 1, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
        else if (data->mode_difficult == 2) {
            placement_bot_fi(data->my_pole_fi, 1, 1, data->mod_type);
            Sleep(1000);
            placement_bot_fi(data->pole_bot_fi, 2, 1, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
        else if (data->mode_difficult == 3) {
            placement_bot_fi(data->my_pole_fi, 1, 1, data->mod_type);
            Sleep(1000);
            placement_bot_fi(data->pole_bot_fi, 3, 1, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
        else if (data->mode_difficult == 4) {
            placement_bot_fi(data->my_pole_fi, 2, 1, data->mod_type);
            Sleep(1000);
            placement_bot_fi(data->pole_bot_fi, 2, 2, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
        else if (data->mode_difficult == 5) {
            placement_bot_fi(data->my_pole_fi, 2, 1, data->mod_type);
            Sleep(1000);
            placement_bot_fi(data->pole_bot_fi, 3, 1, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
        else if (data->mode_difficult == 6) {
            placement_bot_fi(data->my_pole_fi, 3, 1, data->mod_type);
            Sleep(1000);
            placement_bot_fi(data->pole_bot_fi, 3, 2, data->mod_type);
            data->flag_get_pole_bot = 1;
        }
    }

}

void win(global_data* data) {
    if (data->mod_type == 1) {
        if (data->chel_or_bot_attack == bot_win) {
            glPushMatrix();
            glScalef(1.2f, 1.2f, 1.2f);
            print_text(data, ">>YOU LOOSE!<<", -0.62f, -0.65f);
            glPopMatrix();

        }
        if (data->chel_or_bot_attack == chel_win) {
            glPushMatrix();
            glScalef(1.2f, 1.2f, 1.2f);
            //glColor3f(0.4f, 0.1f, 0.1f);
            print_text(data, ">>YOU WIN!<<", -0.33f, -0.65f);
            glPopMatrix();

        }
    }
    else if (data->mod_type == 2) {
        if (data->chel_or_bot_attack == bot_win) {
            glPushMatrix();
            glScalef(1.2f, 1.2f, 1.2f);
            print_text(data, "BOT 2 WIN!", -0.3f, -0.65f);
            glPopMatrix();

        }
        if (data->chel_or_bot_attack == chel_win) {
            glPushMatrix();
            glScalef(1.2f, 1.2f, 1.2f);
            //glColor3f(0.4f, 0.1f, 0.1f);
            print_text(data, "BOT 1 WIN", -0.3f, -0.65f);
            glPopMatrix();
        }
    }
}

void radar_chel(global_data* data, int grid_x, int grid_y) {
    int count_v = 0;
    int count_h = 0;
    if (data->field_size == 10) {
        count_v = 3;
        count_h = 3;
    }
    if (data->field_size == 15) {
        count_v = 4;
        count_h = 4;
    }
    float grid_size = 1.1f / data->field_size;
    int i = 0;
    int j = 0;
    for (int row = grid_x; row < data->field_size && i < count_v; row++, i++) {
        j = 0;
        for (int col = grid_y; col < data->field_size && j < count_h; col++, j++) {
            int value = 0;
            if (data->field_size == 10) value = data->pole_bot_ten[row][col];
            if (data->field_size == 15) value = data->pole_bot_fi[row][col];
            if (value != 6 && value != 8 && value != 7 && value != 0 && value != 9 && value != 10) {
                glColor3f(0.0f, 1.0f, 0.0f);
                float x = 1.3f - data->field_size * grid_size + col * grid_size;
                float y = -0.5f + data->field_size * grid_size - grid_size - row * grid_size;
                glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x + grid_size, y);
                glVertex2f(x + grid_size, y + grid_size);
                glVertex2f(x, y + grid_size);
                glEnd();
            }
        }
    }
    glColor3f(1.0f, 1.0f, 1.0f);
}

typedef struct {
    int x;
    int y;
    int count_v;
    int count_h;
}smoke_struct;

void smoke_weed(global_data* data, smoke_struct* smoke) {
    int temp = rand() % 10000;
    //int temp = 9;
    if (temp == 9 && data->flag_smoke == 0 && data->flag_end_get_pole) {
        data->smoke_hod = data->count_hod_chel[0];
        data->flag_smoke = 1;
        smoke->x = rand() % 10;
        smoke->y = rand() % 10;
        smoke->count_v = rand() % 10 + 2;
        smoke->count_h = rand() % 10 + 2;
    }
    if (data->flag_smoke == 1) {
        if ((data->count_hod_chel[0] - data->smoke_hod) % 2 == 0 && data->count_hod_chel[0] != 0 && data->count_hod_chel[0] != data->smoke_hod) {
            data->flag_smoke = 0;
            return;
        }
        float grid_size = 1.1f / data->field_size;

        int i = 0;
        int j = 0;
        for (int row = smoke->y; row < data->field_size && i < smoke->count_v; row++, i++) {
            j = 0;
            for (int col = smoke->x; col < data->field_size && j < smoke->count_h; col++, j++) {
                glColor3f(0.5f, 0.5f, 0.5f);
                float x = 1.3f - data->field_size * grid_size + col * grid_size;
                float y = -0.5f + data->field_size * grid_size - grid_size - row * grid_size;
                glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x + grid_size, y);
                glVertex2f(x + grid_size, y + grid_size);
                glVertex2f(x, y + grid_size);
                glEnd();

            }
        }
        glColor3f(1.0f, 1.0f, 1.0f);
    }
}

void go_storm(global_data* data) {
    int temp = rand() % 15000;
    //int temp = 1;
    if (temp == 1 && data->flag_end_get_pole && data->chel_or_bot_attack != bot_win && data->chel_or_bot_attack != chel_win) {
        int pole = rand() % 5;
        //int pole = 1;
        if (pole == 0) {
            if (data->field_size == 10) {
                storm_ten(data->my_pole_ten, data->count_ship_kil_by_bot);
                if (data->count_ship_kil_by_bot[0] == 10) data->chel_or_bot_attack = bot_win;
            }
            if (data->field_size == 15) {
                storm_fi(data->my_pole_fi, data->count_ship_kil_by_bot);
                if (data->count_ship_kil_by_bot[0] == 11) data->chel_or_bot_attack = bot_win;
            }
        }
        if (pole == 1) {
            if (data->field_size == 10) {
                storm_ten(data->pole_bot_ten, data->count_ship_kil_by_player);
                if (data->count_ship_kil_by_player[0] == 10) data->chel_or_bot_attack = chel_win;

            }
            if (data->field_size == 15) {
                storm_fi(data->pole_bot_fi, data->count_ship_kil_by_player);
                if (data->count_ship_kil_by_player[0] == 10) data->chel_or_bot_attack = chel_win;
            }
        }
    }
}

record_node* create_node(global_data* data) {
    record_node* new_ptr = (record_node*)malloc(sizeof(record_node));
    if (new_ptr != NULL) {
        data->count_record = data->count_record + 1;
        new_ptr->nick = (char*)malloc(11 * sizeof(char));
        if (new_ptr->nick == NULL) exit(1);
        strncpy(new_ptr->nick, data->name, 10);
        new_ptr->nick[10] = '\0';
        memset(data->name, 0, 10 * sizeof(char));
        new_ptr->score_bot = data->count_ship_kil_by_bot[0];
        new_ptr->score_chel = data->count_ship_kil_by_player[0];
        new_ptr->ptr_next = NULL;
    }
    return new_ptr;
}

void delete(record_node** record) {
    record_node* current = *record;
    record_node* prev = NULL;
    while (current->ptr_next && current->ptr_next->ptr_next) {
        current = current->ptr_next;
    }
    free(current->ptr_next->nick);
    free(current->ptr_next);
    current->ptr_next = NULL;
}

void add_record(record_node** record, global_data* data) {
    record_node* new_node = create_node(data);

    if (!*record || data->count_ship_kil_by_bot[0] < (*record)->score_bot) {
        new_node->ptr_next = *record;
        *record = new_node;
    }
    else {
        record_node* current = *record;
        while (current->ptr_next && current->ptr_next->score_bot <= data->count_ship_kil_by_bot[0]) {
            current = current->ptr_next;
        }
        new_node->ptr_next = current->ptr_next;
        current->ptr_next = new_node;
    }
    if (data->count_record > 10) {
        delete(record);
    }
}

void keyboard(GLFWwindow* window, unsigned int code) {
    global_data* data = (global_data*)glfwGetWindowUserPointer(window);
    if (data->cursor < 10 && data->flag_continue == 1) {
        data->name[data->cursor] = (char)code;
        data->cursor++;
        data->name[data->cursor] = '\0';
    }
}

void del_enter(GLFWwindow* window, int key, int scancode, int action, int mods) {
    global_data* data = (global_data*)glfwGetWindowUserPointer(window);
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_BACKSPACE && data->cursor > 0) {
            data->cursor--;
            data->name[data->cursor] = '\0';
        }
        else if (key == GLFW_KEY_ENTER && data->flag_continue == 1) {
            printf("Имя: %s\n", data->name);
            data->flag_get_enter = 1;
        }
    }
}

int is_record(record_node* record, global_data* data) {
    if (record == NULL) return 1;
    while (record) {
        if (data->count_ship_kil_by_bot <= record->score_bot) return 1;
        record->ptr_next;
    }
    return 0;
}

void continue_but(global_data* data, GLFWwindow* window, record_node* record) {
    draw_button(data, data->game_buttons[1]);
    glPushMatrix();
    glScalef(0.67f, 0.7f, 1.0f);
    print_text(data, "~~Menu~~", 1.70f, -1.04f);
    glPopMatrix();

    if (data->mod_type==1 && data->chel_or_bot_attack == chel_win && is_record(record, data)) {
        draw_button(data, data->game_buttons[0]);
        glPushMatrix();
        glScalef(0.67f, 0.7f, 1.0f);
        print_text(data, "Continue >>", 1.68f, -1.25f);
        glPopMatrix();
        if (data->flag_continue && data->flag_get_enter == 0) {
            glColor3f(0.2f, 0.6f, 1.0f);
            quads(-0.5f, 0.3f, 1.0f, 0.4f);
            print_text(data, "! RECORD !", -0.25f, 0.20f);
            print_text(data, "Enter your name:", -0.33f, 0.1f);
            glColor3f(0.0, 0.0, 0.0);
            quads(-0.45f, 0.07f, 0.9f, 0.15f);
            glfwSetCharCallback(window, keyboard);
            glfwSetKeyCallback(window, del_enter);
            print_text(data, data->name, -0.43f, -0.03f);
        }
        if (data->flag_get_enter && data->flag_add_record == 0) {
            add_record(record, data);
            data->flag_add_record = 1;
        }
    }
    if (data->flag_back_menu) {
        glColor3f(0.25f, 0.25f, 0.25f);
        quads(-0.5f, 0.3f, 1.0f, 0.4f);
        print_text(data, "SAVE ?", -0.16f, 0.20f);
        for (int i = 0; i < 3; i++) draw_button(data,data->game_save[i]);
    }
}

int main(int argc, char** argv) {
    setlocale(LC_ALL, "Russian");
    HWND hwnd = GetConsoleWindow();
    if (hwnd != NULL) {
        ShowWindow(hwnd, SW_HIDE);
    }
    if (!glfwInit()) {
        fprintf(stderr, "Ошибка инициализации GLFW\n");
        return 1;
    }
    glutInit(&argc, argv);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    GLFWwindow* window = glfwCreateWindow(800, 600, "WAR_SHIP", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Ошибка создания окна\n");
        glfwTerminate();
        return 1;
    }

    global_data data = { 0 };
    smoke_struct smoke = { 0 };
    glfwSetWindowUserPointer(window, &data);

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, mouse_func);

    FT_Init_FreeType(&data.library);
    FT_New_Face(data.library, "arial.ttf", 0, &data.font);
    FT_Set_Pixel_Sizes(data.font, 0, 48);
    download_background(&data, "background.jpg");
    update_size_buttons(window, 800, 600);
    data.napr = -1;
    data.count_ship_kil_by_bot[0] = 0;
    data.count_ship_kil_by_player[0] = 0;
    data.count_hod_chel[0] = 0;
    data.mode_difficult = 1;
    data.count_radar = 3;
    data.radar_count_bot[0] = 3;    
    data.otsl_bot_1[0]=-1;
    data.otsl_bot_2[0]=-1;
    data.name = (char*)malloc(11 * sizeof(char));
    if (data.name == NULL) exit(1);
    record_node* record = NULL;
    load_record("record_save.txt", &record, &data);
    data.count_ship_kil_by_player[0] = 0;
    data.count_ship_kil_by_bot[0] = 0;
    data.flag_save = is_save("game_saving.txt");
    memset(data.name, 0, 11 * sizeof(char));
    srand(time(NULL));
    while (!glfwWindowShouldClose(window)) {
        glfwSetMouseButtonCallback(window, mouse_func);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
        paint_background(&data);
        if (!data.flag_difficult && !data.flag_size && !data.field_size && !data.flag_menu && !data.flag_mod && !data.flag_game_load) {
            for (int i = 0; i < BUTTON_MAIN; i++) {
                draw_button(&data, data.main_buttons[i]);
            }
            draw_table(&data, record);
        }
        if (!data.flag_difficult && !data.flag_start && !data.mod_type && data.flag_game_load) {
            for (int i = 0; i < 3; i++) {
                draw_button(&data, data.game_load[i]);
            }
        }
        if (data.flag_menu) {
            draw_button(&data, data.size_buttons[2]);
        }
        if (data.flag_size && data.flag_difficult == 0) {
            for (int i = 0; i < BUTTON_SIZE_FIELD; i++) draw_button(&data, data.size_buttons[i]);
        }
        if (data.flag_difficult && !data.flag_start && data.mod_type == 1) {
            for (int i = 0; i < BUTTON_DIFFICULT; i++) {
                draw_button(&data, data.difficult_buttons[i]);
            }
        }
        if (data.flag_mod && !data.flag_size) {
            for (int i = 0; i < BUTTON_MOD; i++) {
                draw_button(&data, data.mod[i]);
            }
        }
        if (data.mod_type == 2 && !data.flag_start && data.flag_difficult) {
            for (int i = 0; i < BUTTON_MOD_BOT; i++) {
                draw_button(&data, data.mod_bot[i]);
            }
        }

        if (data.flag_start) {
            glClear(GL_COLOR_BUFFER_BIT);
            GLFWmonitor* monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
            int width, height;
            glfwGetFramebufferSize(window, &width, &height);
            new_coordinate(window, width, height);
            if (data.mod_type == 1) {
                if (data.field_size == 10) fill_cells(&data, data.field_size, data.my_pole_ten, 0);
                if (data.field_size == 15) fill_cells_fi(&data, data.field_size, data.my_pole_fi, 0);
                if (data.field_size == 10) fill_cells_rt(&data, data.field_size, data.pole_bot_ten);
                if (data.field_size == 15) fill_cells_rf(&data, data.field_size, data.pole_bot_fi);
                smoke_weed(&data, &smoke);
                go_storm(&data);
                data.flag_radar_chel = press_attachment(window);
                if (data.flag_radar_print == 0) {
                    data.flag_radar_print = data.flag_radar_chel;
                }
                if (data.flag_radar_print == 1 && data.flag_get_cell_radar == 1) radar_chel(&data, data.cell_y, data.cell_x);
                draw_grid_left(&data, data.field_size);
                draw_grid_right(data.field_size);

                if (data.field_size == 10) calc_ten_ship(&data);
                if (data.field_size == 15) calc_fi_ship(&data);
                calc_kill(&data);
                int temp = press_zero_one(window);

                if (temp != -1) data.napr = temp;
                glfwSetMouseButtonCallback(window, mouse_for_rigth_table);
                go_placement(&data, window);
                win(&data);
                continue_but(&data, window, &record);


            }
            else {
                if (data.field_size == 10) fill_cells(&data, data.field_size, data.my_pole_ten, 0);
                if (data.field_size == 10) fill_cells(&data, data.field_size, data.pole_bot_ten, 1);
                if (data.field_size == 15) fill_cells_fi(&data, data.field_size, data.my_pole_fi, 0);
                if (data.field_size == 15) fill_cells_fi(&data, data.field_size, data.pole_bot_fi, 1);
                draw_grid_left(&data, data.field_size);
                draw_grid_right(data.field_size);
                int temp = press_zero_one(window);
                if (temp == 1 && data.flag_get_pole_bot == 0) {
                    placement_bot(&data);
                }
                if (temp != -1) data.napr = temp;
                calc_kill(&data);
                print_bot(&data);
                if (data.napr == 0) {
                    int bot_1 = 0;
                    int bot_2 = 0;
                    if (data.field_size == 10 && data.flag_get_pole_bot && data.count_ship_kil_by_player[0] != 10 && data.count_ship_kil_by_bot[0] != 10) {
                        data.chel_or_bot_attack = game_bot_ten(data.my_pole_ten, data.pole_bot_ten, data.otsl_bot_1, data.otsl_bot_2,data.count_ship_kil_by_player, data.count_ship_kil_by_bot, data.radar_count_bot, data.mode_difficult, bot_1, bot_2);

                    }
                    if (data.field_size == 15 && data.flag_get_pole_bot && data.count_ship_kil_by_player[0] != 11 && data.count_ship_kil_by_bot[0] != 11) {
                        data.chel_or_bot_attack = game_bot_fi(data.my_pole_fi, data.pole_bot_fi, data.otsl_bot_1, data.otsl_bot_2, data.count_ship_kil_by_player, data.count_ship_kil_by_bot, data.radar_count_bot, data.mode_difficult, bot_1, bot_2);
                    }
                }
                win(&data);
                continue_but(&data, window, &record);
                glfwSetMouseButtonCallback(window, mouse_for_bot);
            }

        }
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    save_record("record_save.txt", record);
    FT_Done_Face(data.font);
    FT_Done_FreeType(data.library);
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
