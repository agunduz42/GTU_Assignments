#include <stdio.h>

int menu() {
    int menu_choice, temp_value;
    double answer;

    while(1) {
        printf("\n\n1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Quit\n");
        printf("choice: ");
        scanf(" %d", &menu_choice);
        switch(menu_choice) {
            case 1:
                printf("Please enter a temperature to convert Fahrenheit: ");
                scanf(" %d", &temp_value);
                if(temp_value < -273) {
                    printf("celcius value can NOT be less than -273 degree!\n");
                    return(0);
                }
                answer = (temp_value+0.0) * (9.0/5.0) + 32;
                printf("%d celsius is %.2lf fahreinheit", temp_value, answer);
                break;

            case 2:
                printf("Please enter a temperature to convert Celcius: ");
                scanf(" %d", &temp_value);
                if(temp_value < 0) {
                    printf("Fahreinheit value can NOT be less than zero!\n");
                    return(0);
                }
                answer = (5.0/9.0) * (temp_value - 32);
                printf("%d celsius is %.2lf fahreinheit", temp_value, answer);
                break;

            case 3:
                printf("Exiting from the program\n");
                return(0);

            default:
                printf("You have entered an INVALID choice\n");
                printf("Please enter a VALID choice below\n");
                break;
        }
    }
}

int main() {
    menu();
}