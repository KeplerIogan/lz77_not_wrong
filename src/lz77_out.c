#include <stdio.h>
#include "lz77.h"

void lz77_out(FILE *text, FILE *out_text) {

    element object;
    char copy[15];
    int symb;
    symb = fgetc(out_text);
    while (symb != EOF) {

        object.match_length = symb;
        fseek(out_text, 1, SEEK_CUR);
        object.distance = fgetc(out_text);
        fseek(out_text, 2, SEEK_CUR);
        object.symbol = fgetc(out_text);
        fseek(out_text, 2, SEEK_CUR);
        symb = fgetc(out_text);

        if (object.match_length != 0) {
            
        }
    }
}

