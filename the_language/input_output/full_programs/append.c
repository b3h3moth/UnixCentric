#include <stdio.h>
#include <stdlib.h>

#define LEN 21

// Function prototypes
char *get_string(char *str, int num);

int main(void) {
    FILE *fin, *fout;
    int nfiles = 0, ch;
    char in_filename[LEN];
    char out_filename[LEN];

    puts("Name of files to append");
    
    return(EXIT_SUCCESS);
}

char *get_string(char *str, int num) {
    char *ret_val, *find;

    if ((ret_val = fgets(str, num, stdin)) == NULL) {
        fprintf(stderr, "Err. get string with fgets(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
