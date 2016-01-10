#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/resource.h>

int main(void) {
    struct rlimit res_limit;

    // Get the current CPU limits
    if (getrlimit(RLIMIT_CPU, &res_limit) != 0) {
        fprintf(stderr, "Err. getrlimit(): %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Set a CPU limit
    res_limit.rlim_cur = 1;

    return(EXIT_SUCCESS);
}
