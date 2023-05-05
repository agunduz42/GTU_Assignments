#include "util.h"
#include <stdio.h>

int read_dict(const char * file_name, char dict[][MAX_WORD_SIZE])
{
    FILE *dictionary = fopen("dictionary.txt", "r");

    if(dictionary == NULL)
        return(-1);

    
        
}

int  read_text(const char *text_file, const char *ignore_file, char words[][MAX_WORD_SIZE])
{

}