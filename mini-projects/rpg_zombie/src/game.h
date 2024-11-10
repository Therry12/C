#include <stdio.h>
#define PLAYER_NAME_SIZE 128
#define BUF_SIZE         128

typedef struct {
    char player_name[PLAYER_NAME_SIZE];
    int player_health;
} PLAYER;

enum CONFIG_TYPES { Eplayer_name = 1, Eplyaer_health = 2 };

void print_buf(char buf[], const int buf_size);
void input_player_name(char* player_name, const int buf_size);
char* compare_types(int type);
void buf_clean(char* buf, int buf_size);
void get_value_from_line(const char* line, const int line_size, char dst_buf[], const int dst_buf_size,
                         int type);
int check_config_valid(FILE* fptr);
int get_line_length(char line[]);
void find_value_line(FILE* fptr, int value, char dst[], const int dst_size);
int lines_quanity(FILE* fptr);
void set_player_name(PLAYER* player, const char* player_name);
char* get_player_name(PLAYER* player);

void init_game();
