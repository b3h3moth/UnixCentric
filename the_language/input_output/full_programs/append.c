#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define LEN 21

// Function prototypes
char *get_string(char *str, int num);

int main(void) {
    FILE *fin, *fout;
    int nfiles = 0, ch;
    char in_filename[LEN];
    char out_filename[LEN];

    puts("Name of files to append");
    get_string(out_filename, LEN);
    printf("\n\n%s\n\n", out_filename);
    
    return(EXIT_SUCCESS);
}

// Processa il nome dei file, new line compresa
char *get_string(char *str, int num) {
    char *ret_val, *find;

    if ((ret_val = fgets(str, num, stdin)) != NULL) {
        if ((find = strchr(str, '\n')) != NULL)
            find = '\0';
        else {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}
