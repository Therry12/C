#include "game.h"

#include <stdio.h>
#include <string.h>

// печатает содержимое буфера на экран символами
void print_buf(char* buf, const int buf_size) {
    int i = 0;

    for (i = 0; i < buf_size; i++) {
        printf("%c", buf[i]);
    }
}

int get_line_length(char* line) {
    int line_length = 0;

    line_length = strlen(line) - 1;
    return line_length;
}

int lines_quanity(FILE* fptr) {
    if (fptr == NULL) {
        return -1;
    }

    int lines_quainity = 0;
    const int buf_size = 128;
    char buf[buf_size];

    char ch;
    while((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            lines_quainity++;
        }
    }

    if (ch > 0 || lines_quainity == 0 && ch != '\n') {
        lines_quainity++;
    }
    return lines_quainity;
}

int find_value_line(FILE* fptr) {
    int line = 0;


    return line;
}

// Получает значениe из строки в конфиге, которая передается в аргумент
void get_value_from_line(const char* line, const int line_size, char dst_buf[], const int dst_buf_size,
                         int type) {
    int i = 0, j = 0;

    for (i = 0; i < line_size; i++) {
        if (line[i] == '=') {
            j = ++i;   // Увеличеваем i что бы не записывать позицию =
            break;     // Используем цикл для нахожения позиции =
        }
    }

    for (i = 0; line[j] != '\0' || i < dst_buf_size; j++, i++) {
        dst_buf[i] = line[j];
    }
}

void set_player_name(PLAYER* player, const char* name) {
    if (name == NULL) {
        puts("Имя = NULL");
        return;
    }
    if (name[0] == '\0' || name[0] == '\n' || name[0] == ' ') {
        puts("Имя пустое или начинается с пробела! Заполните поле имени");
        return;
    }
    strncpy(player->player_name, name, sizeof(player->player_name) - 1);
    player->player_name[sizeof(player->player_name) - 1] = '\0';
}

char* get_player_name(PLAYER* player) {
    return player->player_name;
}

void input_player_name(char buf[], const int buf_size) {
    int i = 0;

    printf("Введите ваше имя: ");
    while (i < buf_size) {
        buf[i] = getchar();
        i++;
    }
}

void init_game() {
    char config_buf[BUF_SIZE] = {};
    char player_name[BUF_SIZE] = {};
    FILE* fptr = fopen("../config", "r");
    PLAYER instance;

    fgets(config_buf, BUF_SIZE, fptr);
#if 0
    input_player_name(player_name, BUF_SIZE);
#endif
    get_value_from_line(config_buf, get_line_length(config_buf), player_name, BUF_SIZE, Eplayer_name);
    set_player_name(&instance, player_name);

    printf("Ваше имя: %s\n", get_player_name(&instance));

    printf("%d\n", lines_quanity(fptr));
    fclose(fptr);
}
