#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void) {
    char *username;
    long login_max = 0;

    // Get the maximum size of a username on the host (tipically 256)
    login_max = sysconf(_SC_LOGIN_NAME_MAX);
    if (login_max < 0)
        login_max = 256;

    username = malloc(login_max);
    if (username == NULL) {
        fprintf(stderr, "Err.malloc() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
