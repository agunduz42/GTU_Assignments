#include <stdio.h>
#include <math.h>
#include "util.h"

void first_part() {
    //INPUT PART
    int first_integer, second_integer, less, bigger, remainder;

    printf("\n\n___PART-1___\n");
    printf("Please enter two integer to calculate gcd\n");
    printf("1st integer: ");
    scanf("%d", &first_integer);
    //if the input less than or equals to zero program will keep asking
    while(first_integer <= 0)
    {
        printf("please enter a number greater than zero: ");
        scanf("%d", &first_integer);
    }

    printf("2nd integer: ");
    scanf("%d", &second_integer);
    while(second_integer <= 0)
    {
        printf("please enter a number greater than zero: ");
        scanf("%d", &second_integer);
    }
    //fındıng the bigger number
    if(first_integer > second_integer)
    {
        bigger = first_integer;
        less = second_integer;
    }
    else
    {
        bigger = second_integer;
        less = first_integer;
    }    
    //Finding the gcd using the Euclidean algorithm
    while(remainder != 0) {
        remainder = bigger % less;
        bigger = less;
        less = remainder;
    }
    printf("The gcd of %d and %d is: %d\n", first_integer, second_integer, bigger);
}

void second_part() {
    int num_1;
    int num_2;

    //INPUT TAKING PART
    printf("\n\n___PART-2___\n");
    printf("\nPlease enter two number to find the sum of two integer: \n");
    printf("1nd number: ");
    scanf("%d", &num_1);
    printf("2nd number: ");
    scanf("%d", &num_2);

    //CALCULATION - PRINTING PART
    printf("\nFirst number : %d\n", num_1);
    printf("Second number: %d\n", num_2);
    printf("Result:\n");
    printf("%13d\n", num_1);
    printf("%13d\n", num_2);
    printf("       +\n");
    printf("       ------");
    printf("\n%13d\n", num_1+num_2);
}

void third_part() {
    int sayi_1, sayi_2, num_of_digits = 0, temp, digit, result = 0;

    //INPUT PART
    printf("\n\n___PART-3___\n");
    printf("Please enter two integer to calculate their product\n");
    printf("1st number: ");
    scanf("%d", &sayi_1);
    printf("2nd number: ");
    scanf("%d", &sayi_2);

    //PRINTING
    printf("\nFirst number : %d\n",sayi_1);
    printf("Second number: %d\n", sayi_2);
    printf("Result:\n");
    printf("%17d\n", sayi_1);
    printf("%17d\n", sayi_2);
    printf("         *\n");
    printf("         --------\n");

    //CALCULATION AND NUMBER SHIFTING
    temp = sayi_2;
    while(temp)
    {
        digit = temp % 10;
        temp /= 10;
        num_of_digits++;
        result += sayi_1 * digit * pow(10, num_of_digits-1);
        printf("%*d\n", 18-num_of_digits, digit*sayi_1);
    }
    printf("         +\n");
    printf("         --------\n");
    printf("%17d\n", result);
}

void fourth_part() {
    int first_input;

    printf("\n\n___PART-4___\n");
    printf("\nPlease enter integer between 1 - 10: ");
    scanf("%d", &first_input);
    if(first_input > 10 || first_input < 1)
        printf("Invalid Input\n");
    else if(first_input <= 5)
        printf("The integer you entered is less than or equal to 5\n");
    else if(first_input > 5)
        printf("The integer you entered is grater than 5\n");
}