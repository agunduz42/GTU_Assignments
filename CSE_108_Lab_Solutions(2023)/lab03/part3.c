#include <stdio.h>

int main()
{
    int num1, num2;
    char operation;
    double real_result, user_result;
    printf("Please enter an arithmetic operation (+, -, *. /): ");
    scanf("%c", &operation);
    getchar();
    printf("\nEnter 2 numbers: ");
    scanf("%d %d", &num1, &num2);
    switch(operation)
    {
        case '+':
            real_result = num1 + num2;
            printf("Result: ");
            scanf("%lf", &user_result);
            if(real_result == user_result)
                printf("Bravo, correct answer!\n");
            else
                printf("Wrong answer, try again.\n");
            break;
        case '-':
            real_result = num1 - num2;
            printf("Result: ");
            scanf("%lf", &user_result);
            if(real_result == user_result)
                printf("Bravo, correct answer!\n");
            else
                printf("Wrong answer, try again.\n");
            break;
        case '*':
            real_result = num1 * num2;
            printf("Result: ");
            scanf("%lf", &user_result);
            if(real_result == user_result)
                printf("Bravo, correct answer!\n");
            else
                printf("Wrong answer, try again.\n");
            break;
        case '/':
            if(num2 == 0)
            {
                printf("Second number can not be 0(zero)");
                break;
            }
            real_result = num1 / num2 / 1.0;
            printf("Result: ");
            scanf("%lf", &user_result);
            if(real_result == user_result)
                printf("Bravo, correct answer!\n");
            else
                printf("Wrong answer, try again.\n");
            break;
        default:
            printf("\nYou have entered invalid operation!\n");
    }
}