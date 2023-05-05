#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

typedef struct
{
    double arr[3][3];
    double determinant;
} matrix;

typedef struct 
{
    double x;
    double y;
    double z;
} vector;

void print_matrix(matrix intial_matrix)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%.4lf", intial_matrix.arr[i][j]);
            printf("\t");
        }
        printf("\n");
    }

    printf("\n");
}

void inverse_matrix(matrix* initial_matrix, matrix* inverted_matrix)
{
    double det = initial_matrix->determinant;
    inverted_matrix->arr[0][0] = (initial_matrix->arr[1][1] * initial_matrix->arr[2][2] - initial_matrix->arr[2][1] * initial_matrix->arr[1][2]);
    inverted_matrix->arr[0][1] = (initial_matrix->arr[0][2] * initial_matrix->arr[2][1] - initial_matrix->arr[2][2] * initial_matrix->arr[0][1]);
    inverted_matrix->arr[0][2] = (initial_matrix->arr[0][1] * initial_matrix->arr[1][2] - initial_matrix->arr[1][1] * initial_matrix->arr[0][2]);
    inverted_matrix->arr[1][0] = (initial_matrix->arr[1][2] * initial_matrix->arr[2][0] - initial_matrix->arr[2][2] * initial_matrix->arr[1][0]);
    inverted_matrix->arr[1][1] = (initial_matrix->arr[0][0] * initial_matrix->arr[2][2] - initial_matrix->arr[2][0] * initial_matrix->arr[0][2]);
    inverted_matrix->arr[1][2] = (initial_matrix->arr[0][2] * initial_matrix->arr[1][0] - initial_matrix->arr[1][2] * initial_matrix->arr[0][0]);
    inverted_matrix->arr[2][0] = (initial_matrix->arr[1][0] * initial_matrix->arr[2][1] - initial_matrix->arr[2][0] * initial_matrix->arr[1][1]);
    inverted_matrix->arr[2][1] = (initial_matrix->arr[0][1] * initial_matrix->arr[2][0] - initial_matrix->arr[2][1] * initial_matrix->arr[0][0]);
    inverted_matrix->arr[2][2] = (initial_matrix->arr[0][0] * initial_matrix->arr[1][1] - initial_matrix->arr[1][0] * initial_matrix->arr[0][1]);
}

void determinant_of_matrix(matrix* initial_matrix)
{
    double det = 0;
    det += initial_matrix->arr[0][0] * (initial_matrix->arr[1][1] * initial_matrix->arr[2][2] - initial_matrix->arr[1][2] * initial_matrix->arr[2][1]);
    det -= initial_matrix->arr[0][1] * (initial_matrix->arr[1][0] * initial_matrix->arr[2][2] - initial_matrix->arr[1][2] * initial_matrix->arr[2][0]);
    det += initial_matrix->arr[0][2] * (initial_matrix->arr[1][0] * initial_matrix->arr[2][1] - initial_matrix->arr[1][1] * initial_matrix->arr[2][0]);
}


double find_orthogonal(vector my_vector1, vector my_vector2, vector* result_vector) 
{
  vector cross_product = 
  {
    .x = my_vector1.y * my_vector2.z - my_vector1.z * my_vector2.y,
    .y = my_vector1.z * my_vector2.x - my_vector1.x * my_vector2.z,
    .z = my_vector1.x * my_vector2.y - my_vector1.y * my_vector2.x
  };
  
  double cross_product_magnitude = sqrt(cross_product.x * cross_product.x
                                        + cross_product.y * cross_product.y
                                        + cross_product.z * cross_product.z);
  
  double dot_product = my_vector1.x * my_vector2.x + my_vector1.y * my_vector2.y + my_vector1.z * my_vector2.z;
  double angle = acos(dot_product / (sqrt(my_vector1.x * my_vector1.x + my_vector1.y * my_vector1.y + my_vector1.z * my_vector1.z)
                                     * sqrt(my_vector2.x * my_vector2.x + my_vector2.y * my_vector2.y + my_vector2.z * my_vector2.z)));
  
  angle = angle * 180 / M_PI;
  
  result_vector->x = cross_product.x / cross_product_magnitude;
  result_vector->y = cross_product.y / cross_product_magnitude;
  result_vector->z = cross_product.z / cross_product_magnitude;
  
  // return the angle between my_vector1 and my_vector2
  return angle;
}

int main()
{
    double radius = 5.0;
    double area = M_PI * radius * radius;

    matrix my_matrix = {
        { {1.0000, 0.9134, 0.2785},
          {0.9058, 0.6324, 0.5469},
          {0.1270, 0.0975, 0.9575} }
    };

    vector my_vector1 = {1.0, -2.0, 1.0};
    vector my_vector2 = {3.0, 1.0, -1.0};
    vector result_vector;

    matrix copy_matrix = {0};

    // part 1
    print_matrix(my_matrix);
    determinant_of_matrix(&my_matrix);
    inverse_matrix(&my_matrix, &copy_matrix);
    print_matrix(copy_matrix);

    // part 2
    printf("%.4lf", find_orthogonal(my_vector1, my_vector2, &result_vector));
}