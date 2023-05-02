#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "util.h"

/*_____PART_1_MENU_____*/

int menu()
{
    int menu_choice;
    
    int store_pID;
    int *pID = &store_pID;
    get_pID(pID);

    while(1)
    {
        printf("\nPlease select an option to continue:\n");
        printf("1- File Operations\n2- Query products\n3- Check stock status\n");
        printf("4- Stock control by brand\n5- Export report\nYour option: ");
        scanf(" %d", &menu_choice);
        getchar();

        switch (menu_choice)
        {
            case 1:
                display_file_operations_menu(pID);
                break;
            
            case 2:
                display_query_menu();
                break;

            case 3:
                display_stock_status_menu();
                break;

            case 4:
                brand_stock_control();
                break;
            
            case 5:
                //export_report();
                return(0);

            default:
                printf("\nYou have entered an INVALID option!\n");
        }
    }
}

int get_pID(int *pID)
{
    FILE *product_file = fopen("products.txt", "r");

    if(!product_file)
        return(-1);

    while(fscanf(product_file, "%d,%*c,%*s,%*s,%*f", pID) == 1);
    
    fclose(product_file);
    return(0);
}

int count_line(const char *filename)
{
    FILE *fp = fopen(filename, "r");
    if(fp == NULL)
        return(-1);

    char ch;
    int num_of_line = 1;

    while((ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
            num_of_line++;        
    }
    fclose(fp);
    return(num_of_line);
}

void locate_f_stream(FILE *fp, int desired_line)
{
    char ch;
    int line_counter = 1;

    while(line_counter != desired_line && (ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
            line_counter++;
    }

    if(line_counter < desired_line)
        printf("Desired line not found.\n"); // case where the desired line number is greater than the total number of lines in the file
}

int is_equal(const char *s1, const char *s2)
{
    while (*s1 && *s2) 
    {
        if (*s1 != *s2)
            return 0;
        s1++;
        s2++;
    }
    return (1);
}

/*_____PART_2_FILE_OPERATIONS_____*/

int display_file_operations_menu(int *pID)
{
    int menu_choice;

    while(1)
    {
        printf("\nHere are the options:\n");
        printf("1. Add new product\n2. Delete a product\n3. Update a product\n4. Add feature to products\n5. Add a new stock entry\n");
        printf("6. Add a new stock entry\n7. Delete a stock entry\n8. Update a stock entry\n9. Back to main menu\nYour option: ");
        scanf(" %d", &menu_choice);
        getchar();

        switch(menu_choice)
        {
            case 1:
                add_new_product(pID);
                break;

            case 2:
                int line;
                printf("say line to delete");
                scanf("%d", &line);
                delete_line("products.txt", line);
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8: 
                break;

            case 9: 
                return(0);  // back to main menu

            default:
                printf("You have entered an INVALID option!\n");
        }
    }
}
void delete_line(char *filename, int desired_line) 
{
    FILE *fp = fopen(filename, "r+");
    int line_counter = 1;
    char ch;
    
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    // skip until reach the desired line
    while(line_counter != desired_line && (ch = fgetc(fp)) != EOF)
    {
        if(ch == '\n')
            line_counter++;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        int rotate = ftell(fp)-1; // istenen satirin adresi alindi
        while((ch = fgetc(fp)) != '\n' && ch != EOF); // o satiri atladik

        char str[100];
        int i = 0;
        while((ch = fgetc(fp)) != '\n' && ch != EOF)
        {
            str[i] = ch;
            i++;
        }
        fseek(fp, rotate, SEEK_SET); // kopyalanacak konuma ayarlandi
        print_str_to_file(str, fp); // bir ust satira kopyalandi
        while((ch = fgetc(fp)) != '\n' && ch != EOF);
        if(ch == EOF)
            break;
    }
    fclose(fp);
}

void print_str_to_file(char *str, FILE *fp)
{
    int i = -1;
    while(str[++i])
    {
        if(str[i] == '\n' || str[i] == '\r')
            continue;

        fprintf(fp, "%c", str[i]);
    }
}

int add_new_product(int *pID)
{
    char name[15], brand[15], type;
    double price;

    printf("\nTo add a new product enter the type, name, brand and price with commas between them\n");
    printf("New product: ");
    scanf("%c,%[^,],%[^,],%lf", &type, name, brand, &price);
    getchar();

    FILE *product_file = fopen("products.txt", "a");
    
    if(!product_file)
        return(-1);

    fprintf(product_file, "\n%d,%c,%s,%s,%.1lf", *pID+1, type, name, brand, price);
    
    fclose(product_file);
    return(0);
}

/*_____PART_3_SEARCH_PRODUCT_____*/

int display_stock_status_menu()
{
    int menu_choice;

    while(1)
    {
        printf("\n1. List all products\n");
        printf("2. Filter products by brand, type, price, or a user-defined feature\n");
        printf("3. Back to main menu\nYour option: ");
        scanf(" %d", &menu_choice);
        getchar();
        
        switch(menu_choice)
        {
            case 1:
                //display_products();
                break;

            case 2:
                //filter_products();
                break;

            case 3: // back to main menu
                return(0);

            default:
                printf("You have entered an INVALID option!\n");
        }
    }
}

int display_products()
{
    FILE *product_file = fopen("products.txt", "r");

    if(!product_file)
        return(-1);

    char product_name[15];
    int i = 1;

    printf("\n");
    while((fscanf(product_file, "%*d,%*c,%[^,],%*[^,],%*f", product_name)) == 1)
    {
        printf("%d.%s\n", i, product_name);
        i++;
    }

    fclose(product_file);
    return(0);
}

/*_____PART_4_CHECK_STOCK_STATUS_____*/

int display_query_menu()
{
    printf("\n1. Query the stock\n");
    printf("2. List the stock of all products\n");
    printf("3. List the out of stock products\n");
    printf("4. Back to main menu\n");
    printf("Your choice: ");
    int menu_choice;
    scanf(" %d", &menu_choice);
    getchar();

    switch(menu_choice)
    {
        case 1:
            query_stock();
            break;

        case 2:
            list_stock();
            break;

        case 3:
            list_out_of_stock();
            break;

        case 4:
            return(0); // back to main menu
    }
    return(0);
}

void query_stock()
{
    FILE *stock_file = fopen("stocks.txt", "r");
    char branch_name[100] = "";
    int pID;

    printf("pID  Branch Name\n");
    while(fscanf(stock_file, "%*d,%d,%[^,],%*d", &pID, branch_name) == 2 && !feof(stock_file))
    {
        printf("%d,   %s\n", pID, branch_name);
    }
    fclose(stock_file);
}

void list_stock()
{
    FILE *stock_file = fopen("stocks.txt", "r");
    char specific_branch[20] = "";
    char branch_name[20] = "";
    int stock_amount;

    printf("enter branch: ");
    scanf("%s", specific_branch);
    getchar();
    printf("\nBranch name  Stock Amount\n");

    while(fscanf(stock_file, "%*d,%*d,%[^,],%d", branch_name, &stock_amount) == 2 && !feof(stock_file))
    {
        if(is_equal(specific_branch, branch_name))
            printf("%s              %d\n", specific_branch, stock_amount);
        else
        {
            printf("branch could NOT found!\n");
            break;
        }
    }
    fclose(stock_file);
}

void list_out_of_stock()
{
    FILE *stock_file = fopen("stocks.txt", "r");
    char line[100];
    char branch_name[20] = "";
    char specific_branch[20] = "";
    int stock_amount;
    int pID;

    printf("Enter a branch name to list out-of-stock products: ");
    scanf("%s", specific_branch);

    while(fgets(line, sizeof(line), stock_file))
    {
        if(sscanf(line, "%*d,%d,%[^,],%d", &pID, branch_name, &stock_amount) == 3)
        {
            if(is_equal(specific_branch, branch_name))
            {
                if(stock_amount == 0)
                    print_product_by_pID(pID);
                else
                    printf("There is no out-of-stock products\n");
            }
        }
    }
    fclose(stock_file);
}

void print_product_by_pID(int pID)
{
    FILE *product_file = fopen("products.txt", "r");
    int find_ID;
    char line[100];

    while(fgets(line, sizeof(line), product_file))
    {
        sscanf(line, "%d,%*c,%*[^,],%*[^,]%*f", &find_ID);
        if(pID == find_ID)
        {
            printf("pID: %d is out-of-stock\n", pID);
            break;
        }
    }
    fclose(product_file);
}

/*_____PART_5_BRAND_STOCK_CONTROL_____*/

void brand_stock_control()
{
    FILE *stock_file = fopen("stocks.txt", "r");
    int pID;
    char spesific_brand[20];
    char current_brand[20];
    char line[100];
    int stock_amount;
    double products[count_line("products.txt")][3];

    printf("Enter a brand name to list products: ");
    scanf("%s", spesific_brand);

    while(fgets(line, sizeof(line), stock_file))
    {
        if(sscanf(line, "%*d,%d,%[^,],%d", &pID, current_brand, &stock_amount) == 3)
        {
           if(is_equal(spesific_brand, current_brand))
           {
                products[pID][0] = pID;
                products[pID][1] = find_product_price(pID);
                products[pID][2] = stock_amount;
           }
        }
    }
    
    fclose(stock_file);
}

double find_product_price(int pID)
{
    FILE *product_file = fopen("products.txt", "r");
    int find_ID;
    double price;
    char line[100];

    while(fgets(line, sizeof(line), product_file))
    {
        sscanf(line, "%d,%*c,%*[^,],%*[^,]%lf", &find_ID, &price);
        if(pID == find_ID)
            return(price);
    }
    fclose(product_file);
}