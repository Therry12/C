#include <stdio.h>

typedef struct {
    char* player_name;
    int player_health;
} PLAYER;

void print_buf(char buf[], const int buf_size);
void get_value_from_line(char* line, const int line_size, char dst_buf[], const int dst_buf_size);
int get_line_length(char line[]);

void set_player_name(PLAYER* player, const char* player_name);
