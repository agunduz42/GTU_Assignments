#include <stdio.h>
#include <math.h>

/* __________PART_1__________ */

#define NUMBER_OF_LETTERS 26

int is_character(int c);
void print_counts(char counts[]);
void to_lowercase(int *c);
void letter_counter(FILE *fp, char counts[]);
int part_1();
// function prototypes

int is_character(int c) // if alphabetic chr return 1
{
    return(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

void print_counts(char counts[])
{
    printf("Letter Frequency:\n");
    for(int i = 0; i < NUMBER_OF_LETTERS; i++)
        printf("%c: %d\n", i+'A', counts[i]);
}

void to_lowercase(int *c) // if upper change it to lower
{
    if('A' <= *c && *c <= 'Z')
        *c += 32;
}

void letter_counter(FILE *fp, char counts[])
{
    int c;
    int *ptr = &c;

    while((c = fgetc(fp)) != EOF)
    {
        if(is_character(c)) // I used function to make it more readable
        {
            to_lowercase(ptr);
            counts[c - 'a']++; // 
        }
    }
}

int part_1()
{
    char file_name[50];
    char counts[NUMBER_OF_LETTERS] = {0};  // to count letter occurrences

    printf("Enter the file name: ");
    scanf(" %s", file_name);

    FILE *fp = fopen(file_name, "r");

    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return(1);
    }

    letter_counter(fp, counts);
    print_counts(counts);
    fclose(fp);
    return(0);
}

/* __________PART_2__________ */

enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE
};

double colors[5][3] = {
    {1.0, 0.0, 0.0},    // RED
    {0.0, 1.0, 0.0},    // GREEN
    {0.0, 0.0, 1.0},    // BLUE
    {0.5, 0.5, 0.0},    // YELLOW
    {0.5, 0.4, 0.2}     // ORANGE
};

double euclideanDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

void part_2() // I couldn't finish part_2 
{
    char first_color;

    printf("Enter Color 1 (r,g,b,y,o): "); // ask the user for first color
    scanf(" %c", &first_color);
    switch (first_color)
    {
        case 'r':
    }
}

/* __________PART_3__________ */

int win_check(char game_map[3][3])
{
    int result, row, col;

    // Check for win condition in rows
    for(row = 0; row < 3; row++)
    {
        if(game_map[row][0] == game_map[row][1] && game_map[row][1] == game_map[row][2] && game_map[row][0] != '_')
        {
            if(game_map[row][0] == 'X')
                result = 1;
            else
                result = 2;
            return(result);
        }
    }

    // Check for win condition in columns
    for(col = 0; col < 3; col++)
    {
        if(game_map[0][col] == game_map[1][col] && game_map[1][col] == game_map[2][col] && game_map[0][col] != '_')
        {
            if(game_map[0][col] == 'X')
                result = 1;
            else
                result = 2;
            return(result);
        }
    }

    // Check for win condition in diagonals
    if(game_map[0][0] == game_map[1][1] && game_map[1][1] == game_map[2][2] && game_map[0][0] != '_')
    {
        if(game_map[0][0] == 'X')
            result = 1;
        else
            result = 2;
        return(result);
    }

    if(game_map[0][2] == game_map[1][1] && game_map[1][1] == game_map[2][0] && game_map[0][2] != '_')
    {
        if(game_map[0][2] == 'X')
            result = 1;
        else
            result = 2;
        return(result);
    }

    return 0;
}

void make_move(char game_map[3][3], int row, int col, char x_o)
{
    game_map[row][col] = x_o;
}

void print_map(char game_map[3][3])
{
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
            printf("%c ", game_map[row][col]);
        printf("\n");
    }
}

void want_to_continue();

void part_3()
{
    char game_map[3][3];
    int row_move, col_move;

    printf("\nWelcome to the Tic-Tac-Toe game\n");
    int winner;

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            game_map[i][j] = '_';

    while(1)
    {
        do {
            printf("Player 1 (X), enter your move (row, col): ");
            scanf(" %d %d", &row_move, &col_move);
        }while(game_map[row_move][col_move] != '_'); // keep asking for valid input

        make_move(game_map, row_move, col_move, 'X');
        print_map(game_map);

        winner = win_check(game_map);
        if(winner)
        {
            if(winner == 1)
            {
                printf("Player 1 (X) wins!\n");
                break;
            }
            else
            {
                printf("Player 2 (O) wins!\n");
                break;
            }
        }

        do {
            printf("Player 2 (O), enter your move (row, col): ");
            scanf(" %d %d", &row_move, &col_move);
        }while(game_map[row_move][col_move] != '_');

        make_move(game_map, row_move, col_move, 'O');
        print_map(game_map);

        winner = win_check(game_map);
        if(winner)
        {
            if(winner == 1)
            {
                printf("Player 1 (X) wins!\n");
                break;
            }
            else
            {
                printf("Player 2 (O) wins!\n");
                break;
            }
        }
    }
    want_to_continue();
}

void want_to_continue()
{
    char want_to;

    printf("Do you want to continue (Y/N): ");
    scanf(" %c", &want_to);

    if(want_to == 'Y')
        part_3();
    else
        printf("Take care!\n");
}

int main()
{
    part_1();
    //part_2();
    part_3();
}