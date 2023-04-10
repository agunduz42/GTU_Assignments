#include <stdio.h>
#include <math.h>

void decimal_to_binary(int decimal);
void decimal_to_octal(int decimal);
void decimal_to_hexadecimal(int decimal);

void decimal_to_binary(int decimal) {
    int i = 1, binary_num = 0;
    while(decimal) {
        binary_num += (decimal % 2) * i;
        decimal /= 2;
        i *= 10;
    }
    printf("Binary equivalent: %d\n", binary_num);
}

void decimal_to_octal(int decimal) {
    int i = 0, octal_num = 0;

    while(decimal) {
        octal_num += (decimal % 8) * i;
        decimal /= 8;
        i *= 10;
    }
    printf("Octal equivalent: %d\n", octal_num);
}

void decimal_to_hexadecimal(int decimal) {
    int i = 0, temp = 0;
    
    while (decimal) {
        temp = decimal % 16;
        if(temp < 10) {
            printf("%d", temp);
            i++;
        }
        else {
            printf("%c", temp + 55);
            i++;
        }
        decimal /= 16;
    }
}

int menu() {
    int menu_choice, number;
    
    while(1) {
        printf("\n\n1. Convert a number to decimal, binary, octal, and hexadecimal\n");
        printf("2. Quit\n");
        printf("enter your choice: ");
        scanf(" %d", &menu_choice);
        switch(menu_choice) {
            case 1:
                printf("Enter a number: ");
                scanf(" %d", &number);
                printf("Decimal equivalent: %d\n", number);
                decimal_to_binary(number);
                decimal_to_octal(number);
                printf("Hexadecimal equivalent: ");
                decimal_to_hexadecimal(number);
                break;

            case 2:
                printf("Exiting\n");
                return(0);

            default:
                printf("You have entered an INVALID menu choice!\n");
                return(0);
        }
    }
}

int main() {
    menu();
}