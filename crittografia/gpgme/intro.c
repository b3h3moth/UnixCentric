#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <gpgme.h>

/* GPGME GnuPG Made Easy */

int main(int argc, char *argv[]) {
    /* Inizializza l'ambiente locale */
    setlocale(LC_ALL, "");
    gpgme_check_version(NULL);
    gpgme_set_locale(NULL, LC_CTYPE, setlocale(LC_CTYPE, NULL));

    printf("%s\n", test);

    return(EXIT_SUCCESS);
}
