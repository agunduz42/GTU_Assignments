#include <stdio.h>
#define MAX_SIZE 50 // I don't know the amount of integer.

int take_and_store_integers(int numbers[]);
void sign_assign(int numbers[], char signs[], int size);
void print_result(int numbers[], char signs[], int size);
// function prototypes

int take_and_store_integers(int numbers[])
{
    int temp_number, i = 0;

    printf("Please enter the list of integers:\n");
    while(1) // infinite loop until a negative integers is entered
    {
        scanf(" %d", &temp_number);
        if(temp_number < 0)
            break;

        numbers[i] = temp_number;
        i++;
    }
    return(i);
}

void sign_assign(int numbers[], char signs[], int size)
{
    int i = 0;
    
    while(i < size)
    {
        if(numbers[i] % 2 == 0)
            signs[i] = 'e';
        else
            signs[i] = 'o';
        i++;
    }
}

void print_result(int numbers[], char signs[], int size) 
{
    int i = 0;

    while(i < size)
    {
        printf("%d %c\n", numbers[i], signs[i]);
        i++;
    }
}

int main()
{
    int size;
    int numbers[MAX_SIZE];
    char signs[MAX_SIZE];

    size = take_and_store_integers(numbers);
    sign_assign(numbers, signs, size);
    print_result(numbers, signs, size);
}