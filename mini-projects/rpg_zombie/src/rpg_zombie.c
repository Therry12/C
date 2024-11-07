#include "game.h"

#include <stdio.h>

#define BUF_SIZE 128

int main(void) {
    char buf[BUF_SIZE] = {};
    char player_name[BUF_SIZE] = {};
    FILE* fptr = fopen("../config", "r");
    PLAYER instance;

    fgets(buf, BUF_SIZE, fptr);
    get_value_from_line(buf, get_line_length(buf), player_name, BUF_SIZE);

    set_player_name(&instance, player_name);
    printf("%s\n", get_player_name(&instance));


    fclose(fptr);
    return 0;
}
