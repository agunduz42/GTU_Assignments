#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_MAP_SIZE 5
#define MAX_MAP_SIZE 10
#define UP 'w'
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'

void map_create(int map_size, int door_row, int door_col, int player_row, int player_col);
int check_if_player_reached_door(int door_row, int door_col, int player_row, int player_col);
int gameplay(int map_size, int door_row, int door_col, int player_row, int player_col);
int simple_menu(void);
void invalid_movement(void);
//func prototypes


int check_if_player_reached_door(int door_row, int door_col, int player_row, int player_col) {
    if(door_row == player_row && door_col == player_col)
        return(1); // player reached the door
    else
        return(0); // player NOT at door
}

void invalid_movement() {
    printf("\nINVALID movement!\n");
    printf("You can move within the boundaries of the map.\n");
}

int gameplay(int map_size, int door_row, int door_col, int player_row, int player_col) {
    char move;
    int move_counter = 0;

    while(!(check_if_player_reached_door(door_row, door_col, player_row, player_col))) {
        map_create(map_size, door_row, door_col, player_row, player_col);
        printf("\nPlease enter one move at a time: %c(up) %c(left) %c(down) %c(right): ", UP, LEFT, DOWN, RIGHT);
        move = getchar();
        while(getchar() != '\n');
        switch(move) {
            case UP:
                if(0 < player_col && player_col <= map_size-1) {
                    player_col -= 1;
                    move_counter++;
                }
                else
                    invalid_movement();
                break;
            
            case LEFT:
                if(0 < player_row && player_row <= map_size-1) {
                    player_row -= 1;
                    move_counter++;
                }
                else
                    invalid_movement();
                break;

            case DOWN:
                if(0 <= player_col && player_col < map_size-1) {
                    player_col += 1;
                    move_counter++;
                }
                else
                    invalid_movement();
                break;

            case RIGHT:
                if(0 <= player_row && player_row < map_size-1) {
                    player_row += 1;
                    move_counter++;
                }
                else
                    invalid_movement();
                break;

            default:
                printf("\n\nYou have entered an INVALID movement\n");
                break;
        }
    }
    return(move_counter);
}


void map_create(int map_size, int door_row, int door_col, int player_row, int player_col) {
    int col_index, row_index;

    for(int i = 0; i < map_size*2+1; i++)
        printf("-");    //top border

    printf("\n");

    for(col_index = 0; col_index < map_size; col_index++) {
        printf("|");
        for(row_index = 0; row_index < map_size; row_index++) {
            if(door_row == row_index && door_col == col_index)
                printf("D|");   //draw the door symbol
            else if(player_row == row_index && player_col == col_index)
                printf("C|");   //draw the player symbol
            else
                printf(" |");   //draw empty space
        }
        printf("\n");
    }

    for(int i = 0; i < map_size*2 + 1; i++)
        printf("-");    //bottom border
}

int simple_menu() {
    int menu_choice = 1, map_size, door_row, door_col, player_row, player_col, move_counter;
    printf("\nWelcome to the 2D puzzle game!\n");
    while(1) {
        printf("1. New Game\n2. Help\n3. Exit\n");
        printf("menu_choice: ");
        scanf(" %d", &menu_choice);
        getchar();

        switch (menu_choice) {
            case 1:
                printf("Please enter a map_size between 5 and 10: ");
                scanf(" %d", &map_size);
                getchar();
                while(map_size < MIN_MAP_SIZE || map_size > MAX_MAP_SIZE) {
                    printf("INVALID input you need to enter between %d-%d: ", MIN_MAP_SIZE, MAX_MAP_SIZE);
                    scanf(" %d", &map_size);
                    getchar();
                }
                srand(time(NULL)); // The time() function is used to set the seed based on the current time.
                // I have used srand() function to set the seed for the rand() function to generate random coordinates for the player and the door
                door_row = rand() % map_size;
                door_col = rand() % map_size;
                player_row = rand() % map_size;
                player_col = rand() % map_size;
                // If the coordinates of the door and the player are the same, the program reassigns new coordinates for the player.
                while(door_row == player_row && door_col == player_col) {
                    player_row = rand() % map_size;
                    player_col = rand() % map_size;
                }

                move_counter = gameplay(map_size, door_row, door_col, player_row, player_col);
                printf("Congrats you have finished the game in %d move\n\n", move_counter);
                break;
            
            case 2:
                printf("\n****************************************************************************************\n");
                printf("_Welcome to the 2D puzzle game_\n");
                printf("# This guide will teach you how to play the game #\n\n");
                printf("Here are the RULES!\n");
                printf("The character is able to move one space in any of the four cardinal directions: up, down, left, and right\n");
                printf("You can use '%c' key to go UP, '%c' key to go LEFT, '%c' key to go DOWN and '%c' key to go RIGHT\n", UP, LEFT, DOWN, RIGHT);
                printf("Diagonal moves are not allowed!\n");
                printf("The game ends when the character reaches the door\n\n");
                printf("****************************************************************************************\n");
                break;

            case 3:
                printf("Goodbye take care!\n\n");
                return(0);

            default:
                printf("\nYou have entered an INVALID option!\n");
                printf("Please enter a valid option below:\n\n");
                break;
        }
    }
}

int main() {
    simple_menu();
    return(0);
}