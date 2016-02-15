#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void) {
    struct rlimit res_lim;
    pid_t pid;

    // Get the current CPU limits
    if (getrlimit(RLIMIT_CPU, &res_lim) != 0) {
        fprintf(stderr, "Err. getrlimit(): %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Err.(%d) - fork - %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        
        if (prlimit(pid, RLIMIT_CPU, NULL, &res_lim) == -1) {
            fprintf(stderr, "Err. prlimit(): %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
        
        printf("Limits: soft=%d; hard=%d\n", res_lim.rlim_cur, 
                res_lim.rlim_max);
    } else {

        if (prlimit(pid, RLIMIT_CPU, NULL, &res_lim) == -1) {
            fprintf(stderr, "Err. prlimit(): %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        printf("Limits: soft=%d; hard=%d\n", res_lim.rlim_cur, 
                res_lim.rlim_max);
    }

    return(EXIT_SUCCESS);
}
