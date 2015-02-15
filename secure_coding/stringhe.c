#include <stdio.h>
#include <stdlib.h>

int len_array(const char a[], int l);

int main(int argc, char *argv[]) {
    const char str1[10] = "roma";
    const char str2[] = "napoli";

    int len = len_array(str1, 10);
    int lun = len_array(str2, 10);

    printf("len: %d\nlun: %d\n", len, lun);

/*
    for (i=0; i<10; i++) {
        if (str1[i] == '\0')
            break;
        len++;
    }

    for (j=0; j<10; j++) {
        if (str2[j] == '\0')
            break;
        lun++;
    }
*/

    return(EXIT_SUCCESS);
}

int len_array(const char a[], int l) {
    int i;
    int lun = 0;

    for (i=0; i<l; i++) {
        if (a[i] == '\0')
            break;
        lun++;
    }

    return lun;
}

