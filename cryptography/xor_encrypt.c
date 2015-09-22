#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY_BASE '%'

int main(void) {
    int original_char, new_char;

    while((original_char = getchar()) != EOF) {
        new_char = original_char ^ KEY_BASE;

        if (isprint(original_char) && isprint(new_char))
            //putchar(new_char);
            printf("%c", new_char);
        else
            //putchar(original_char);
            printf("%c", original_char);
    }

    return(EXIT_SUCCESS);
}

/* 
Encrypt file.txt:
$ ./a.out < file.txt > new_file.txt

Decrypt new_file.txt:
$ ./a.out  < new_file.txt
*/
