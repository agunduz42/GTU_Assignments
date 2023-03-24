#include <stdio.h>

int main()
{
    int num1, num2, num3;
    printf("Enter 3 integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if(num1 > num2)
    {
        if(num1 > num3)
        {
            if(num2 > num3)
                printf("Median number is %d\n", num2);
            else
                printf("Median number is %d\n", num3);
        }
        else
            printf("Median number is %d\n", num1);
    }
    else if(num3 > num2)
    {
        if(num3 > num1)
        {
            if(num2 > num1)
                printf("Median number is %d\n", num2);
            else
                printf("Median number is %d\n", num1);
        }
        else
            printf("Median number is %d\n", num3);
    }
    else
    {
        if(num1 > num3)
            printf("Median number is %d\n", num1);
        else
            printf("Median number is %d\n", num3);
    }
}