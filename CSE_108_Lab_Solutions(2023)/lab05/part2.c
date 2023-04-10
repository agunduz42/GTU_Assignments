#include <stdio.h>

int main() {
    int num_of_digits = 0, number, reversed_number = 0;

    printf("enter a number that contains 4,5 or 6 digits to reverse it: ");
    scanf(" %d", &number);
    int temp = number;
    while(temp) {
        temp /= 10;
        num_of_digits++;
    }

    while(num_of_digits != 4 && num_of_digits != 5 && num_of_digits != 6) {
        printf("you have entered an INVALID number!\n");
        printf("Pleasse enter a valid number that contains 4,5 or 6 digits: ");
        scanf(" %d", &number);

        num_of_digits = 0;
        temp = number;
        while(temp) {
            temp /= 10;
            num_of_digits++;
        }
    }

    while(number) {
        int digit = number % 10;
        reversed_number = reversed_number * 10 + digit;
        number /= 10;
    }
    printf("reversed number is %d\n", reversed_number);
}