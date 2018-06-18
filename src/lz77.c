#include <stdio.h>
#include "lz77.h"
#include <locale.h>

void lz77(FILE *text, FILE *out_text, char *buff, char *dict) {

    int math_long = 0;
    element object;
    int l = 0, f = 0;

    while (buff[0] != EOF) {

        if (f == 0) {

        for (math_long = 0; math_long <= 14; math_long++) {

            if (dict[math_long] == buff[0]) {
                object.match_length = math_long;
                l = math_long + 1;
                f = 1;
                while (dict[l] == buff[f]) {
                    l++;
                    object.distance = f + 1;
                    f++;
                    object.symbol = buff[f];
                }
            }
        }
        for (l = 0; l < 14; l++)
            dict[l] = dict[l + 1];
        dict[14] = buff[0];
        for (l = 0; l < 7; l++)
            buff[l] = buff[l + 1];
        buff[7] = fgetc(text);
        fprintf(out_text, "%d %d '%c'|", object.match_length, object.distance, object.symbol);

        } else {
            for (l = 0; l < 14; l++)
                dict[l] = dict[l + 1];
            dict[14] = buff[0];
            for (l = 0; l < 7; l++)
                buff[l] = buff[l + 1];
            buff[7] = fgetc(text);
            f--;
        }
    }
}
