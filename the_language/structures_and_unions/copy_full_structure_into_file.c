#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 8

struct {
    char str1[MAX_STR];
    int  value;
    char str2[MAX_STR];
} data;

int main(void) {
    FILE *fp;
    char *filename = "data.txt";
    unsigned int data_size = sizeof(data);

    strcpy(data.str1, "xxxxxxx");
    data.value = 0x12ABCDEF;
    strcpy(data.str2, "yyyyyyy");

    // Copia ciascun membro della struttura 'data' nel file
    if ((fp = fopen(filename, "wb"))) {
        fwrite(&data, sizeof(data), 1, fp);
        fclose(fp);
    }

    printf("struct 'data'(%d byte) written into: '%s'\n", data_size, filename);

    return(EXIT_SUCCESS);
}
