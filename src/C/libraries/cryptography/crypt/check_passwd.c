#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pwd.h>
#include <shadow.h>

int main(void) {
    char *username = NULL;
    long login_max = 0;
    size_t len = 0;
    struct passwd *pwd;
    struct spwd *shpw;

    if (getuid() != 0) {
        fprintf(stderr, "Sorry, you're not root. Login as root please.\n");
        exit(EXIT_FAILURE);
    }

    /* Salva la grandezza massima per lo username nell'host corrente 
    (tipicamente 256) */
    login_max = sysconf(_SC_LOGIN_NAME_MAX);
    if (login_max < 0)
        login_max = 256;

    username = malloc(login_max);
    if (username == NULL) {
        fprintf(stderr, "Err. malloc() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Salva lo username fornito dall'utente per la verifica della password,
    non prima di aver pulito lo stream */
    printf("Username: ");
    fflush(stdout);
    if (fgets(username, login_max, stdin) == NULL) {
        fprintf(stderr, "Err. fgets() failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Calcolo della lunghezza della stringa relativa all'username e, in caso
    di bisogno, rimozione del carattare di 'new-line' in favore del 
    'null-terminator character' di fine stringa */
    len = strlen(username);
    if (username[len - 1] == '\n')
        username[len - 1] = '\0';

    // Verifica la presenza di 'username' nel file /etc/passwd
    pwd = getpwnam(username);
    if (pwd == NULL) {
        if (errno == 0) {
            fprintf(stderr, "Account Not Found.\n");
            exit(EXIT_FAILURE);
        } else {
            fprintf(stderr, "Err. getpwnam() failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Verifica la presenza di 'username' nel file /etc/passwd
    shpw = getspnam(username);
    if (shpw == NULL) {
        if (errno == 0 && errno) {
            fprintf(stderr, "Account Not Found.\n");
            exit(EXIT_FAILURE);
        } else {
            fprintf(stderr, "Err. getspnam() failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    return(EXIT_SUCCESS);
}
