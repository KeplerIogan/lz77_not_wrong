#include <stdio.h>
#include "lz77.h"
#include <locale.h>

int main() {

    FILE *text, *out_text;
    char buff[8];
    char dict[15];
    int f;

    if (!(text = fopen("file.txt", "r"))) {  //открываем текст, который хотим сжать
        return 1;
    }

    if (!(out_text = fopen("file.lz77", "w"))) { //создаём файл, в котором будут храниться сжатые данные
        return 1;
    }
    for (f = 0; f <= 7; f++) {
        buff[f] = fgetc(text);
    }
    printf("1");
    lz77(text, out_text, buff, dict);
    fclose(text);
    fclose(out_text);
    return 0;
}
