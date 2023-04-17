#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define STONE 1
#define PAPER 2
#define SCISSORS 3

void result_display(int players_move, int random_move);
void print_choices(int choice);
int random_choice_generator();
int game_menu();
// function prototypes

void result_display(int players_move, int random_move) {
    char who_won; // 'p' for player. 'c' for computer

    printf("You");
    print_choices(players_move);
    printf(" I");
    print_choices(random_move);
    
    if(players_move == random_move)
        printf(" It's a tie!\n");
    else if(players_move == STONE) {
        if(random_move == PAPER)
            who_won = 'c';
        else if(random_move == SCISSORS)
            who_won = 'p';
    }
    else if(players_move == PAPER) {
        if(random_move == STONE)
            who_won = 'p';
        else if(random_move == SCISSORS)
            who_won = 'c';
    }
    else if(players_move == SCISSORS) {
        if(random_move == STONE)
            who_won = 'c';
        else if(random_move == PAPER)
            who_won = 'p';
    }

    if(who_won == 'c')
        printf(" I won!\n");
    else if(who_won == 'p')
        printf(" You won!\n");
}

void print_choices(int choice) {
    if(choice == STONE)
        printf(" chose Stone.");
    else if(choice == PAPER)
        printf(" chose Paper.");
    else
        printf(" chose Scissors.");
}

int random_choice_generator() {
    int random_move; 

    srand(time(NULL));
    random_move = rand() % 3 + 1;
    return(random_move);
}

int game_menu() {
    int players_choice;
    char want_to_continue;

    printf("\nWelcome to rock, paper scissors game\n");
        printf("\nPlease make a choice!\n");
        printf("1: Stone, 2: Paper, 3: Scissors\n");
        scanf(" %d", &players_choice);
        result_display(players_choice, random_choice_generator());
    while(1) {
        printf("Do you want to play again? (Y/N): ");
        scanf(" %c", &want_to_continue);
        switch(want_to_continue) {
            case 'Y':
                printf("\nPlease make a choice!\n");
                printf("1: Stone, 2: Paper, 3: Scissors\n");
        }
    }
}

int main() {
    game_menu();
    return(0);
}