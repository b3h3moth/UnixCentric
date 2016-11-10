#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void) {
    char *username;
    long login_max = 0;

    /* Salva la grandezza massima per lo username nell'host corrente 
    (tipicamente 256) */
    login_max = sysconf(_SC_LOGIN_NAME_MAX);
    if (login_max < 0)
        login_max = 256;

    username = malloc(login_max);
    if (username == NULL) {
        fprintf(stderr, "Err.malloc() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Salva lo username fornito dall'utente per la verifica della password
    printf("Username: ");
    fflush(stdout);
    fgets(

    return(EXIT_SUCCESS);
}
