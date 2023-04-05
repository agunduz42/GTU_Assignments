#include <stdio.h>
#include <math.h>
#include "util.h"

void part_one() {
    int year;
    printf("\n\n___PART-1___\n");
    printf("**************************\n");
    printf("Please enter a year: ");
    scanf("%d", &year);
    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        printf("%d is a leap year\n", year);
    else
        printf("%d is NOT a leap year\n", year);
    printf("**************************\n");
}

double calculation(char operation) {
    double nb1, nb2;
    printf("Enter the 1st operand: ");
    scanf(" %lf", &nb1);
    getchar();
    switch(operation) {
        case '+': {
            printf("\nEnter the 2nd operand: ");
            scanf(" %lf", &nb2);
            getchar();
            return(nb1 + nb2);
        }
        
        case '-': {
            printf("\nEnter the 2nd operand: ");
            scanf(" %lf", &nb2);
            return(nb1 - nb2);
        }

        case '/': {
            printf("\nEnter the 2nd operand: ");
            scanf(" %lf", &nb2);
            return(nb1 / nb2);
        }

        case '*': {
            printf("\nEnter the 2nd operand: ");
            scanf(" %lf", &nb2);
            return(nb1 * nb2);
        }

        case '%': {
            printf("\nEnter the 2nd operand: ");
            scanf(" %lf", &nb2);
            return(fmod(nb1, nb2));
        }

        case '!': {
            int i, result = 1;
            for(i = 1; i <= nb1; i++)
                result *= i;
            return(result);
        }
    }
}

void part_two() {
    char format, operation;
    int m,n, operand;

    printf("\n\n___PART-2___\n");
    printf("**************************\n");
    printf("Enter the format of output (S or I): ");
    scanf(" %c", &format);
    getchar();
    while(format != 'S' && format != 'I')
    {
        printf("Invalid format!\n");
        printf("Please enter a valid format (S or I): ");
        scanf(" %c", &format);
    }

    printf("Enter m and n values: ");
    scanf(" %d %d", &m, &n);
    getchar();
    if(n > m) {
        printf("m value can NOT be greater than n value\n");
        return;
    }
    printf("Enter the operation(+,-,/,*,%%,!): ");
    scanf(" %c", &operation);
    getchar();
    double result = calculation(operation);
    if(format == 'I')
        printf("result: %0.lf\n", result);
    else
        printf("result: %0*.*e\n", m+5, n, result);
}

void part_three() {
    int exam_1, exam_2, exam_3, asg_1, asg_2;
    double final;
    printf("\n\n___PART-3___\n");
    printf("**************************\n");
    printf("Enter 3 exam grades of student: ");
    scanf("%d %d %d", &exam_1, &exam_2, &exam_3);
    printf("Enter 2 assignment grades of student: ");
    scanf("%d %d", &asg_1, &asg_2);
    final = (exam_1+exam_2+exam_3)/3.0 *0.6 + (asg_1+asg_2)/2.0 *0.4;
    if(final > 60)
        printf("Final grade: %.1lf Passed!\n", final);
    else
        printf("Final grade: %.1lf Failed!\n", final);
}