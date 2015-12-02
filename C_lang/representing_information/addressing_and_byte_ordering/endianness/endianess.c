#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    FILE *fp;

    struct {
        char one[4];
        int two;
        char three[4];
    } data;

    strcpy(data.one, "foo");
    data.two = 0x01234567;
    strcpy(data.three, "bar");

    if ((fp = fopen("data.txt", "wb"))) {
        fwrite(&data, sizeof(data), 1, fp);
        fclose(fp);
    }

    return(EXIT_SUCCESS);
}
