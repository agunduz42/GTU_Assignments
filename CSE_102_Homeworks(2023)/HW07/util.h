#ifndef UTIL_H
#define UTIL_H

#ifndef MAX_WORD_COUNT
#define MAX_WORD_COUNT 100
#endif

#ifndef MAX_SIZE_WORD_IN_TEXT
#define MAX_SIZE_WORD_IN_TEXT 30
#endif

#ifndef MAX_WORD_SIZE
#define MAX_WORD_SIZE 12
#endif

int read_text(const char *text_file, const char *ignore_file, char words[][MAX_SIZE_WORD_IN_TEXT]);

int read_dict(const char * file_name, char dict[][MAX_WORD_SIZE]);

int is_same_string(char *s1, char *s2);

double dissimilarity(char * w1, char * w2, char dict[][MAX_WORD_SIZE], float threshold);

int histogram(const char words[][MAX_WORD_SIZE], const int occurrences[], const char  hist[][MAX_WORD_SIZE+5+20]);

int count_occurrences_in_file(const char *filename, char *the_word);

#endif