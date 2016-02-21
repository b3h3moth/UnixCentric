#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// The program's purpose is to redirect standard I/O stream to file

int main(void) {
    time_c sec;
    char fname[] = "data.txt";

    fputs("Before freopen()", stdout);

    if (freopen(fname, "w", stdout) == NULL) {
        fprintf(stderr, "Unable to redirect stdout stream.\n");
    } else 
        printf("I'm writing inside a file\n");
    
    return(EXIT_SUCCESS);
}
