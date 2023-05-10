#include "util.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

int read_dict(const char * file_name, char dict[][MAX_WORD_SIZE])
{
    FILE *dict_file = fopen(file_name, "r");

    if(dict_file == NULL)
        return(-1);

    char ch;
    unsigned int word_counter = 0;

    while((ch = fgetc(dict_file)) != EOF && ch != '\n'); // pass first line

    while(fscanf(dict_file, "%[^ ]", dict[word_counter]) == 1 && !feof(dict_file))
    {
        while((ch = fgetc(dict_file)) != EOF && ch != '\n'); // pass the rest
        word_counter++;
    }
    dict[word_counter][0] = '-';

    fclose(dict_file);
    return word_counter;
}

void copy_string(char *src, char *dst)  // copies the string until it reaches \0
{
    while(*dst)
    {
        *src = *dst;
        src++;
        dst++;
    }
    *src = '\0';
}

int is_same_string(char *s1, char *s2)
{
    while(*s1 && *s2)
    {
        if(*s1 != *s2)
            return(0);
        
        s1++;
        s2++;
    }   // if any difference is found then they are different

    return 1;
}

int read_text(const char *text_file, const char *ignore_file, char words[][MAX_SIZE_WORD_IN_TEXT]) 
{
    FILE *txt_file = fopen(text_file, "r");
    FILE *ignr_file = fopen(ignore_file, "r");

    char ignored_words[100][MAX_SIZE_WORD_IN_TEXT];
    unsigned int i = 0;

    char ch;
    int j;
    while ((ch = fgetc(ignr_file)) != EOF) 
    {
        j = 0;
        while (ch != '\n' && ch != EOF) 
        {
            ignored_words[i][j] = ch;
            j++;
            ch = fgetc(ignr_file);
        }
        ignored_words[i][j] = '\0';
        i++;
    } // i had to add \0 character at the end of every word to compare

    fclose(ignr_file);

    unsigned int number_of_ignore = i, is_ignored;
    unsigned int word_counter = 0;
    char buffer[MAX_SIZE_WORD_IN_TEXT];

    while(fscanf(txt_file, "%[a-zA-Z'0-9?!-]", buffer) == 1 && !feof(txt_file))
    {
        is_ignored = 0;
        for(int j = 0; j < number_of_ignore; j++)
        {
            if(is_same_string(buffer, ignored_words[j]))
            {
                is_ignored = 1;
            }
        }
        
        if(!is_ignored)
        {
            copy_string(buffer, words[word_counter]);
            word_counter++;
        }

        fscanf(txt_file, "%*[^a-zA-Z'0-9?!-]");
    }

    words[word_counter][0] = '\0';

    fclose(txt_file);
    return word_counter;
}

double dissimilarity(char * w1, char * w2, char dict[][MAX_WORD_SIZE], float threshold)
{
    FILE *dict_file = fopen("dictionary.txt", "r");
    char buffer[MAX_SIZE_WORD_IN_TEXT];

    if(dict_file == NULL)
    {
        printf("Error opening file!");
        return(-1);
    }

    char ch;
    do {
        ch = fgetc(dict_file);
    } while (ch != '\n' && ch != EOF); // pass first line

    double vectors[2][200];

    while(fscanf(dict_file, "%s", buffer) == 1 && !feof(dict_file))
    {
        if(is_same_string(buffer, w1))
        {
            for(int i = 0; i < 200; i++)
                fscanf(dict_file, "%lf", &vectors[0][i]);
            break;
        }
        do {
            ch = fgetc(dict_file);
        } while (ch != '\n' && ch != EOF);
    } 
    // I have stored the vectors that I need to compare with other ones

    fseek(dict_file, 0, SEEK_SET); // set the cursor at the beginning of the file
    do {
        ch = fgetc(dict_file);
    } while (ch != '\n' && ch != EOF);


    double diss;
    double min_diss = 1e9;
    while(fscanf(dict_file, "%s", buffer) && !feof(dict_file))
    {
        for(int i = 0; i < 200; i++)
            fscanf(dict_file, "%lf", &vectors[1][i]);

        diss = 0.0;
        for(int i = 0; i < 200; i++)
        {
            double diff = vectors[0][i] - vectors[1][i];
            diss += diff * diff;
            diss = sqrt(diss);
        }

        if(diss < min_diss)
        {
            copy_string(w2, buffer);
            min_diss = diss;
        }
    }
    fclose(dict_file);
    return min_diss; // that means there is no similar word
}

int histogram(const char words[][MAX_WORD_SIZE], const int occurrences[], const char hist[][MAX_WORD_SIZE+5+20])
{
    // I couldn't finish
}

int count_occurrences_in_file(const char *filename, char *the_word)
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL) 
    {
        printf("Error opening file!");
        return(-1);
    }

    char buffer[MAX_SIZE_WORD_IN_TEXT];
    unsigned int number_of_occurence = 0;

    while(fscanf(fp, "%[a-zA-Z'0-9?!-]", buffer) == 1 && !feof(fp))
    {
        if(is_same_string(buffer, the_word))
            number_of_occurence++;

        fscanf(fp, "%*[^a-zA-Z'0-9?!-]");
    }
    fclose(fp);
    return number_of_occurence;
}