#include <stdio.h>
#define SIZE 100
int main()
{
    FILE *fp;
    int number_rows, i = 0, age[SIZE];
    char job[SIZE], team[SIZE], selected_team;
    float salary[SIZE], total_salary = 0, average_salary;

    fp = fopen("table.txt", "r");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return(0);
    }

    fscanf(fp, "%d", &number_rows); // taking row value

    for(i = 0; i < number_rows; i++)
        fscanf(fp, "%d %c %f %c", &age[i], &job[i], &salary[i], &team[i]); // taking the rest of the values

    fclose(fp);

    printf("Select a team: ");
    scanf(" %c", &selected_team);

    for(i = 0; i < number_rows; i++)
    {
        if(selected_team == team[i])
            total_salary += salary[i];
    }

    if(total_salary == 0)
        printf("There are no fans of %c in the database!", selected_team);  /*  if total salary is zero
                                                                                which means there are no
                                                                                fans of the selected team  */
    else
    {
        average_salary = total_salary / number_rows;
        printf("Average salaries of fans of %c: %.2f", selected_team, average_salary);
    }
    
    return(0);
}