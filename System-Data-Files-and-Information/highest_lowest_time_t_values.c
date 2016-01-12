#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>

// How to get the highest and lowest value of time_t variable in hex.
int main(void) {
    time_t highest_value = 0x7FFFFFFF;
    time_t  lowest_value = 0xFFFFFFFF;
    
    char *str_h = ctime(&highest_value);
    char *str_l = ctime(&lowest_value);

    if ((str_h == NULL) || (str_l == NULL)) {
        fprintf(stderr, "Err. ctime() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    printf("Highest value: %s\n", str_time);


    return(EXIT_SUCCESS);
}
