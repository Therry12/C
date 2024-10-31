#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(void);

int main() {
    int game_status = 1, current_points, sum;   // game status 2 - lose, 1 - while, 0 - win
    srand(time(NULL));
    current_points = sum = roll_dice();

    printf("You roll your dice and droped %d points!\n", sum);
    switch (sum) {
    case 7 :
    case 11 :
        game_status = 0;
        break;
    case 2 :
    case 3 :
    case 12 :
        game_status = 2;
        break;
    default :
        while (game_status == 1) {
            sum = roll_dice();
            printf("You roll again your dice and droped %d points!\n", sum);
            if (current_points == sum) {
                game_status = 0;
            } else if (sum == 7) {
                game_status = 2;
            }
        }
    }

    if (game_status == 0) {
        printf("You won!\n");
    } else {
        printf("You lose! Try again\n");
    }
    return 0;
}

int roll_dice() {
    int sum = -1, roll_1, roll_2;

    roll_1 = 1 + (rand() % 6);
    roll_2 = 1 + (rand() % 6);

    sum = roll_1 + roll_2;
    return sum;
}
