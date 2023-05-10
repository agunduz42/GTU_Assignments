#include "util.h"
#include <stdio.h>
#include <string.h>

int main()
{
    char dict[1002][MAX_WORD_SIZE];
    char words[150000][MAX_SIZE_WORD_IN_TEXT];
    char input[MAX_SIZE_WORD_IN_TEXT];

    printf("Please enter a word(s): ");
    scanf("%[^\n]s", input);

    // Count the number of spaces in the input to determine if it contains just one word or multiple words
    int num_spaces = 0;
    for (int i = 0; input[i] != '\0'; i++) 
        if (input[i] == ' ') 
            num_spaces++;

    if(num_spaces == 0)
    {
        // Input contains just one word
        int temp;
        if(temp = count_occurrences_in_file("input.txt", input))
            printf("\"%s\" appears in \"input.txt\" %d times.", input, temp);
        else
        {
            char buffer[MAX_SIZE_WORD_IN_TEXT];
            double diss = dissimilarity(input, buffer, dict, 1.0);
            if(diss)
                printf("\"%s\" does't appear in \"input.txt\" but \"%s\" appears %d times", input, buffer, count_occurrences_in_file("input.txt", buffer));
            else
                printf("\"%s\" doesn't appear in \"input.txt\".", input);
        }
    }
    else
    {
        //Input contains multiple words
        char *word = strtok(input, " ");
        while(word != NULL)
        {
            int temp;
            if(temp = count_occurrences_in_file("input.txt", word))
                printf("\"%s\" appears in \"input.txt\" %d times.", word, temp);
            else
            {
                char buffer[MAX_SIZE_WORD_IN_TEXT];
                double diss = dissimilarity(input, buffer, dict, 1.0);
                if(diss)
                {
                    printf("I couldn't finish this part\n");
                }
                else
                    printf("\"%s\" doesn't appear in \"input.txt\".", word);
            }
        }
    }
}