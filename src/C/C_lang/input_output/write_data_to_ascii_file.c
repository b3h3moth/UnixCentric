#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/utsname.h>

#define UTSNAME_MEMBER_SIZE    5

/* Lo scopo del programma e' di scrivere talune informazioni circa il kernel
in uso all'interno del file ascii 'filename', dopodiche' leggere dal file
stesso e stampare in output il risultato. */

void set_hostname_info(char *arg, char **vec);

int main(void) {
    struct utsname buf;
    char *hostinfo[UTSNAME_MEMBER_SIZE];
    char fname[] = "db.txt";
    FILE *fin, *fout;
    int ch;

    if ((fout = fopen(fname, "w")) == NULL) {
        fprintf(stderr, "Err.writing file, fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (uname(&buf) == -1) {
        fprintf(stderr, "Err. uname(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
                                                   // Equivalente a:
    set_hostname_info(buf.sysname,  &hostinfo[0]); //   *(&hostinfo)
    set_hostname_info(buf.nodename, &hostinfo[1]); //   *(&hostinfo)+1
    set_hostname_info(buf.release,  &hostinfo[2]); //   *(&hostinfo)+2
    set_hostname_info(buf.version,  &hostinfo[3]); //   *(&hostinfo)+3
    set_hostname_info(buf.machine,  &hostinfo[4]); //   *(&hostinfo)+4

    for (int i=0; i<UTSNAME_MEMBER_SIZE; i++) {
        fprintf(fout, "%s\n", hostinfo[i]);
        //fprintf(stdout, "%s\n", hostinfo[i]);
    }

    fclose(fout);

    fprintf(stdout, "(Reading from filename: \'%s\')\n", fname);

    if ((fin = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Err.reading file fopen(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fin)) != EOF) 
        fputc(ch, stdout);

    fclose(fin);

    return(EXIT_SUCCESS);
}

/* Alloca la memoria necessaria per una stringa, dopodiche' scrive la stringa 
stessa all'interno dell'array di puntatori 'vec' */
void set_hostname_info(char *arg, char **vec) {
    if ((*vec = malloc(strlen(arg))) == NULL) {
        fprintf(stderr, "Err. malloc(), %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* On OpenBSD there is the function strlcpy() */
    strncpy(*vec, arg, strlen(arg));
}
