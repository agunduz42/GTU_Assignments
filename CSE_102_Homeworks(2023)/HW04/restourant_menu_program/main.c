#include <stdio.h>
#include <time.h>

float print_menu_item();
void take_order();
int make_receipt();
void show_menu();
// function prototypes

float print_menu_item(int product_number)
{
    FILE *menu, *receipt;
    char ch;
    int current_line = 1;
    float temp_cost;
  
    menu = fopen("menu.txt", "r");
    receipt = fopen("receipt.txt", "a");

    if(menu == NULL)
    {
        printf("Error opening file\n");
        return(0);
    }

    if(receipt == NULL)
    {
        printf("Error opening file\n");
        return(0);
    }

    while(!feof(menu))
    {
        fscanf(menu, "%c", &ch);
        if(current_line == product_number)
        {
            while(ch != ' ' && ch != '\t' && ch != EOF && ch != '\n')
                fprintf(receipt, "%c", ch);
            fscanf(menu, "%f", &temp_cost);
            break;
        }
        else
        {
            while(ch != '\n')
            {
                if(fscanf(menu, "%c", &ch) == EOF)
                    break;
            }
            fprintf(receipt, "\n");
            current_line++;
        }
    }
    fclose(menu);
    fclose(receipt);
    return(temp_cost);
}

int make_receipt(int product_number, int servings_number)
{
    FILE *receipt;
    char ch;
    int current_line = 0;
    float temp_cost;
  
    receipt = fopen("receipt.txt", "a");

    if(receipt == NULL)
    {
        printf("Error opening file!\n");
        return(1);
    }

    time_t t;
    time(&t);
    fprintf(receipt, "%s", ctime(&t)); // printing the current time
  
    fprintf(receipt, "------------------------------------\n");
    fprintf(receipt, "Product       Price (TL)\n");
    fprintf(receipt, "------------------------------------\n");

    temp_cost = print_menu_item(product_number);
    fprintf(receipt, "%.2f", temp_cost);
    fprintf(receipt, "\n");
}

void take_order()
{
    int product_number = 1, servings_number, temp_cost;
    char is_student;

    while(1)
    {
        printf("\nPlease choose a product (1-10), or enter zero to finish: ");
        scanf(" %d", &product_number);

        if(product_number == 0)
            break;

        while(product_number < 0 || product_number > 10)
        {
            printf("Please enter a VALID option: ");
            scanf(" %d", &product_number);
            getchar();
        }

        if(product_number == 0)
            break;
        
        printf("How many servings do you want? ");
        scanf(" %d", &servings_number);
        getchar();

        while(servings_number < 0)
        {
            printf("Please enter a VALID amount of servings! ");
            scanf(" %d", &servings_number);
            getchar();
        }

        make_receipt(product_number, servings_number);
    }
        printf("Are you a student(Y/N): ");
        scanf(" %c", &is_student);
        getchar();
}

void show_menu()
{
    FILE *menu;
    char ch;
    int counter = 1;

    menu = fopen("menu.txt", "r");
    
    printf("Yemek Listesi: \n");
    printf("%d. ", counter);

    while((ch = fgetc(menu))!= '\n')
        continue;
    
    while(!feof(menu))
    {
        fscanf(menu, "%c", &ch);
        if(ch == '\n')
        {
          printf("\n");
          printf("%d. ", ++counter);
        }
        else if('a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z')
          printf("%c", ch);
    }
    printf("\n");
    fclose(menu);
}

int main()
{
    show_menu();
    take_order();
}