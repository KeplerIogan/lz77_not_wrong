#include <stddef.h>

typedef struct{
    int match_length;
    int distance;
    char symbol;
} element;

void lz77(FILE *text, FILE *out_text, char *buff, char *dict);