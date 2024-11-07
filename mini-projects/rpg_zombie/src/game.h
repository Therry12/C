#include <stdio.h>
#define PLAYER_NAME_SIZE 128
#define BUF_SIZE         128

typedef struct {
    char player_name[PLAYER_NAME_SIZE];
    int player_health;
} PLAYER;

void print_buf(char buf[], const int buf_size);
char* input_player_name();
void get_value_from_line(const char* line, const int line_size, char dst_buf[], const int dst_buf_size);
int get_line_length(char line[]);

void set_player_name(PLAYER* player, const char* player_name);
char* get_player_name(PLAYER* player);

void init_game();
