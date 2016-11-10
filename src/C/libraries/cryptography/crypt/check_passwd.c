#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    long login_max = 0;

    // Get the maximum size of a username on the host
    login_max = sysconf(_SC_LOGIN_NAME_MAX);

#ifdef _DEBUG_SYSCONF
printf("%ld\n", login_max);
#endif

    return(EXIT_SUCCESS);
}
