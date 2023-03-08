#include <stdio.h>
#include "util.h"

int main() {

    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A second fractional number: 13/11 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("\n\n\n");
    printf("Enter two numerator and two denominator to calculate \nthe sum, difference, product and division of two fractional numbers\n\n");
    printf("enter the 1st numerator: ");
    scanf("%d", &num1);
    printf("enter the 1st denominator: ");
    scanf("%d", &den1);

    while(den1 == 0) {
        printf("\nDenominator can not be 'zero'\n");
        printf("Please enter a valid denominator");
        scanf("%d", &den1);
    }

    printf("enter the 2nd numerator: ");
    scanf("%d", &num2);
    printf("enter the 2nd denominator: ");
    scanf("%d", &den2);

    while (den2 == 0) {
        printf("\nDenominator can not be 'zero'\n");
        printf("Please enter a valid denominator: ");
        scanf("%d", &den2);
    }

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");
    return (0);
}