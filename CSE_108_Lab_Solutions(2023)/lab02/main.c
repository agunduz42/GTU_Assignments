#include <stdio.h>
#include <math.h>
#define PI 3.14
void part1()
{
    //CUBE
    int edge;
    double surface_area, volume;
    printf("\nEnter the edge length for cube: ");
    scanf("%d", &edge);
    surface_area = 6*pow(edge,2);
    volume = pow(edge,3);
    printf("\nSurface Area = %.2lf, Volume = %.2lf", surface_area, volume);

    //RECTANGULAR PRISM
    double side_lenght, side_width, side_height;
    printf("\n\nEnter side length for rectangular prism: ");
    scanf("%lf", &side_lenght);
    printf("\nEnter side width: ");
    scanf("%lf", &side_width);
    printf("\nEnter side height: ");
    scanf("%lf", &side_height);
    surface_area = 2*(side_lenght*side_width + side_width*side_height + side_lenght*side_height);
    volume = side_lenght*side_width*side_height;
    printf("\nSurface Area = %.2lf, Volume = %.2lf", surface_area, volume);

    //SPHERE
    double radius;
    printf("\n\nEnter the radius for sphere: ");
    scanf("%lf", &radius);
    surface_area = 4*PI*pow(radius,2);
    volume = 4*(PI*pow(radius,3)/3);
    printf("\nSurface Area = %.2lf, Volume = %.2lf", surface_area, volume);


    //CONE
    double height;
    printf("\n\nEnter the radius for cone: ");
    scanf("%lf", &radius);
    printf("\nEnter the height: ");
    scanf("%lf", &height);
    surface_area = PI*radius*(radius+sqrt(pow(radius,2)+pow(height,2)));
    volume = (PI*pow(radius,2)*height)/3;
    printf("\nSurface Area = %.2lf, Volume = %.2lf", surface_area, volume);
}

void part2()
{
    double weight, height, BMI;
    printf("\n\n_____PART2_____");
    printf("\nPlesae enter your weight: ");
    scanf("%lf", &weight);
    printf("\nPlease enter your height as meters: ");
    scanf("%lf", &height);
    BMI = weight/(pow(height,2));
    printf("\nYour BMI is : %.1lf", BMI);
    if(BMI < 18.5)
        printf("\nYou are underweight");
    else if(BMI >= 18.5 && BMI <= 24.9)
        printf("\nYou are average weight");
    else if(BMI >= 25 && BMI <= 29.9)
        printf("\nYou are overweight be carefull what you eat");
    else if(BMI >= 30)
        printf("\nYou are obese you should eat more healthy food");
}

int main()
{
    part1();
    part2();
    return(0);
}