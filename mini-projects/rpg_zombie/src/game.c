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

char* compare_types(int type) {
    char* str;

    switch (type) {
    case 1 :
        str = "player_name";
        break;
    }
    return str;
}

int get_line_length(char* line) {
    int line_length = 0;

    line_length = strlen(line) - 1;
    return line_length;
}

int lines_quanity(FILE* fptr) {   // #TODO: Если в конфиге есть пустые строки, то они будут также засчитаны
    if (fptr == NULL) {
        return -1;
    }

    int lines_quainity = 0;
    const int buf_size = 128;
    char buf[buf_size];

    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            lines_quainity++;
        }
    }

    if (ch > 0 || lines_quainity == 0 || ch != '\n') {
        lines_quainity++;
    }
    return lines_quainity;
}

void buf_clean(char* buf, int buf_size) {
    for (int i = 0; i < buf_size; i++) {
        buf[i] = 0;
    }
}

void find_value_line(FILE* fptr, int type, char dst[], const int dst_size) {
    if (fptr == NULL) {
        puts("Указатель на файл не удалось прочитать!");
        return;
    }

    char line[BUF_SIZE] = {};
    char key_buf[BUF_SIZE] = {};
    char tmp_buf[BUF_SIZE] = {};

    rewind(fptr);

    int i = 0;
    while (fgets(tmp_buf, BUF_SIZE, fptr)) {
        for (i = 0; tmp_buf[i] != '='; i++) {
            key_buf[i] = tmp_buf[i];
        }

        if (dst_size < i) {
            puts("Dst buf size is too small");
            return;
        }
        if (strncmp(tmp_buf, "player_name", i) == 0) {
            puts("in cmp");
            strncpy(dst, tmp_buf, i);
            break;
        }
    }
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

int check_config_valid(FILE* fptr) {
    int lines_count = lines_quanity(fptr);
    if (lines_count <= 2) {
        return 1;
    }

    return 0;
}

void init_game() {
    char config_buf[BUF_SIZE] = {};
    char player_name[BUF_SIZE] = {};
    char line[BUF_SIZE] = {};
    FILE* fptr = fopen("../config", "r");
    PLAYER instance;

    if (check_config_valid(fptr)) {
        puts("Конфиг не валидный!");
        return;
    }

    find_value_line(fptr, Eplayer_name, line, BUF_SIZE);
    printf("%s\n", line);
    fgets(config_buf, BUF_SIZE, fptr);
#if 0
    input_player_name(player_name, BUF_SIZE);
    get_value_from_line(config_buf, get_line_length(config_buf), player_name, BUF_SIZE, Eplayer_name);
    set_player_name(&instance, player_name);
#endif
    fclose(fptr);
}
