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

// Получает значени из строки в конфиге, которая передается в аргумент
void get_value_from_line(const char* line, const int line_size, char dst_buf[], const int dst_buf_size) {
    int i = 0, j = 0;

    for (i = 0; i < line_size; i++) {
        if (line[i] == '=') {
            j = ++i;   // Увеличиваем i что бы не записывать позицию =
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
        puts("Имя пустое! Заполните поле имени");
        return;
    }

    strncpy(player->player_name, name, sizeof(player->player_name) - 1);
    player->player_name[sizeof(player->player_name) - 1] = '\0';
}

char* get_player_name(PLAYER* player) {
    return player->player_name;
}

void input_name(char buf[], const int buf_size) {
    int i = 0;

    printf("Введите ваше имя(ctrl+d для завершения): ");
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
    input_name(player_name, BUF_SIZE);
    set_player_name(&instance, player_name);
    get_value_from_line(config_buf, get_line_length(config_buf), player_name, BUF_SIZE);

    printf("Ваше имя: %s\n", get_player_name(&instance));

    fclose(fptr);
}
