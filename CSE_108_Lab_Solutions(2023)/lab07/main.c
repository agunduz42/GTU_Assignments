#include <stdio.h>
#include <string.h>

int part_1(char *str)
{
    int arr_len = strlen(str);
    int i = 0, same_chr = 0, count = 0;

    while (i < arr_len) 
    {
        same_chr = i + 1;
        while (same_chr < arr_len && str[same_chr] == str[i])
        {
            same_chr++;
        }
        count += 1;
        i = same_chr;
    }
    if(count == 1)
        return(1);
    else
        return (count-1);
}

void sort_arr(int size, int arr[])
{
    int i = 0;
    while(i < size-1) 
    {
        int j = 0;
        while(j < size-i-1) 
        {
            if (arr[j] > arr[j+1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            j++;
        }
        i++;
    }
}

void part_3()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter %d integers:\n", size);
    int i = 0;

    while(i < size) 
    {
        scanf("%d", &arr[i]);
        i++;
    }

    sort_arr(size, arr);
    printf("\nmin value is %d\n", arr[0]);
    printf("max value is %d\n", arr[size-1]);
}


int main()
{
    char arr[] = "aabcccccaaa";
    printf("The number of move is %d\n", part_1(arr));
    part_3();
}