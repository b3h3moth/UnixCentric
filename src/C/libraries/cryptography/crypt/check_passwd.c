#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    long login_max = 0;

    // Get the maximum size of a username on the host (tipically 256)
    login_max = sysconf(_SC_LOGIN_NAME_MAX);
    if (login_max < 0)
        login_max = 256;

    return(EXIT_SUCCESS);
}
