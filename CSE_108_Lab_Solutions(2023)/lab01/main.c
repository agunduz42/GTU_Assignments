#include <stdio.h>
int fizzbuzz(void)
{
    //PART 1
    printf("__PART 1__\n\n");
    int num;

    num = 0;
    while (!(num <= 100 && num >= 1))
    {
       printf("please enter a number between 1-100: ");
       scanf("%d", &num);
    }
    while(num <= 50 && num >= 5 && num % 3 == 0)
    {
            printf("FizzBuzz");
            return(0);
    }
    while(num <= 50 && num >= 5)
    {
            printf("Buzz");
            return(0);
    }
    while(num % 3 == 0)
    {
            printf("Fizz");
            return(0);
    }
}

int main()
{
    printf("____________________________________________________\n\n");
    fizzbuzz();
    printf("\n____________________________________________________");
    // PART 2
    printf("\n\n__PART 2__\n\n");
    double x;
    double y;
    double sum;
    double max;

    printf("Enter two decimal number to calculate following equation\n");
    printf("x/y + max(x,y)/x+y\n\n");
    printf("Please enter x: ");
    scanf("%lf", &x);
    printf("Please enter y: ");
    scanf("%lf", &y);

    if(x > y)
        max = x;
    else
        max = y;

    sum = (x/y) + max/(x+y);
    printf("the answer is: %lf", sum);
    printf("\n____________________________________________________");

    // PART 3
    printf("\n\n__PART 3__\n");
    struct employee
    {
        int age;
        int experience;
        int salary;
    }emp1;

    printf("enter the age of the employee: ");
    scanf("%d", &emp1.age);
    printf("enter the experience of the employee: ");
    scanf("%d", &emp1.experience);
    if(emp1.age < 20)
    {
        if(emp1.experience > 10)
            emp1.salary = -1;
        else
            emp1.salary = 10000;
    }

    if(emp1.age > 20 && emp1.age < 50)
    {
        if(emp1.experience > 10)
            emp1.salary = 20000;
        else
            emp1.salary = 15000;
    }

    if(emp1.age > 50)
    {
        if(emp1.experience > 10)
            emp1.salary = 25000;
        else
            emp1.salary = 20000;
    }
    printf("The salary of the employee is : %d", emp1.salary);

    printf("\n____________________________________________________");
}