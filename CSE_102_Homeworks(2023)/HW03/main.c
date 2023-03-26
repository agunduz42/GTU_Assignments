#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void map_create(int map_size, int door_x, int door_y, int player_x, int player_y);
/*
void status_control() {
    kapiya ulasip ulasmadigi
    ulastiysa program sonlanmali
}
*/
int gameplay(int map_size, int door_x, int door_y, int player_x, int player_y) {
    char move;
    int move_counter = 0;
    
    while(!(door_x == player_x && door_y == player_y)) {
        map_create(map_size, door_x, door_y, player_x, player_y);
        printf("\nw(up) a(left) s(down) d(right): ");
        scanf("%c", &move);
        switch(move) {
            case 'w':
                player_y -= 1;
                move_counter++;
                break;
            
            case 'a':
                player_x -= 1;
                move_counter++;
                break;

            case 's':
                player_y += 1;
                move_counter++;
                break;

            case 'd':
                player_x += 1;
                move_counter++;
                break;

            default:
                printf("You have entered an INVALID movement\n");
                printf("Please enter one of the valid movements below\n");
        }
    }
    return(move_counter);
}


void map_create(int map_size, int door_x, int door_y, int player_x, int player_y) {
    int y = 0, x;
    while(y < map_size) {
        x = 0;
        printf("|");
        while(x < map_size) {
            if(player_x == x && player_y == y || door_x == x && door_y == y) {
                if(player_x == x && player_y == y)
                    printf("C|");
                else if(door_x == x && door_y == y)
                    printf("D|");
            }
            else
                printf(" |");
            x++;
        }
        printf("\n");
        y++;
    }
}

int main() {
    int option, map_size, door_x, door_y, player_x, player_y, move_counter;
    printf("Welcome to the 2D puzzle game!\n");
    printf("1. New Game\n");
    printf("2. Help\n");
    printf("3. Exit\n");
    printf("option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Please enter a map_size: ");
            scanf("%d", &map_size);
            srand(time(NULL));
            door_x = rand() % map_size;
            door_y = rand() % map_size;
            player_x = rand() % map_size;
            player_y = rand() % map_size;

            while(door_x == player_x && door_y == player_y) {
                player_x = rand() % map_size;
                player_y = rand() % map_size;
            }

            move_counter = gameplay(map_size, door_x, door_y, player_x, player_y);
            printf("%d", move_counter);
            break;
        
        case 2:
            break;

        case 3:
            printf("Goodbye take care!\n");
            return(0);
            break;

        default:
            printf("You have entered an INVALID option!");
            return(0);
    }
}