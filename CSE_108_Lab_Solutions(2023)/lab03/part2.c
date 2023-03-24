#include <stdio.h>

int main()
{
    int ex1, ex2, ex3, flag = 1;
    char grade, plus;
    double average;

    printf("Enter your 3 scores: ");
    scanf("%d %d %d", &ex1, &ex2, &ex3);
    getchar();
    average = (ex1+ex2+ex3)/3.0;
    plus = '\0';
    grade = '!';
    switch(ex1/10)
    {
        case 10:
        case 9:
            grade = 'A';
            plus = '+';
            break;
        case 8:
            grade = 'A';
            break;
        case 7:
            grade = 'B';
            plus = '+';
            break;
        case 6:
            grade = 'B';
            break;
        case 5:
            grade = 'C';
            break;
        case 4:
            grade = 'D';
            break;
        case 3:
        case 2:
        case 1:
        case 0:
            grade = 'F';
            break;
        default:
            printf("\nYou have entered a grade out of borders!\n");
            flag = 0;
    }
    if(flag)
        printf("Your letter grades are %c%c, ", grade, plus);
    plus = '\0';
    grade = '!';
    switch(ex2/10)
    {
        case 10:
        case 9:
            grade = 'A';
            plus = '+';
            break;
        case 8:
            grade = 'A';
            break;
        case 7:
            grade = 'B';
            plus = '+';
            break;
        case 6:
            grade = 'B';
            break;
        case 5:
            grade = 'C';
            break;
        case 4:
            grade = 'D';
            break;
        case 3:
        case 2:
        case 1:
        case 0:
            grade = 'F';
            break;
        default:
            printf("\nYou have entered a grade out of borders!\n");
            flag = 0;
    }
    if(flag)
        printf("%c%c and ", grade, plus);
    plus = '\0';
    grade = '!';

    switch(ex3/10)
    {
        case 10:
        case 9:
            grade = 'A';
            plus = '+';
            break;
        case 8:
            grade = 'A';
            break;
        case 7:
            grade = 'B';
            plus = '+';
            break;
        case 6:
            grade = 'B';
            break;
        case 5:
            grade = 'C';
            break;
        case 4:
            grade = 'D';
            break;
        case 3:
        case 2:
        case 1:
        case 0:
            grade = 'F';
            break;
        default:
            printf("\nYou have entered a grade out of borders!\n");
            flag = 0;
    }
    if(flag)
        printf("%c%c with an %.1lf average\n", grade, plus, average);
}