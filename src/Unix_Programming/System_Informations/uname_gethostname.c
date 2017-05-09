#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/utsname.h>

#define MAX_BUF 64

/*
I sistemi UNIX comprendono diverse funzioni il cui scopo e' di fornire le piu'
disparate informazioni circa la natura del sistema stesso, tra queste uname() e
gethostname() sono, anche dal punto di vista storico, molto importanti.

La funzione gethostname() e' concettualmente molto semplice da usare, fornisce
il nome host della macchina; la funzione uname() invece sfrutta la struttura
'utsname' definita in <sys/utsname>, consente di ottenere talune informazioni
sul sistema (kernel) in uso:

struct utsname
{
	char sysname[];
	char nodename[];
	char release[];
	char version[];
	char machine[];

#ifdef _GNU_SOURCE
    char domainname[];
#endif
};

HEADER    : <sys/utsname.h> || <linux/utsname.h>
PROTOTYPE : int uname(struct utsname *name);
SEMANTICS : La funzione uname() ottiene informazioni sul sistema in uso mediante
            il puntatore alla struttura utsname 'name';
RETURNS   : 0 In caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
HEADER    : <unistd.h>
PROTOTYPE : int gethostname(char *name, int namelen);
SEMANTICS : La funzione gethostname() fornisce l'host della macchina in uso,
            collocandolo in 'name' di grandezza 'namelen'.
RETURNS   : 0 In caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    char my_host[MAX_BUF];
    struct utsname my_kernel;

    if(gethostname(my_host, MAX_BUF) < 0) {
        fprintf(stderr, "Err.(%s) getting hostname\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (uname(&my_kernel) < 0) {
        fprintf(stderr, "Err.(%s) getting kernel info\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("    host: %s (gethostname)\n", my_host);
    printf(" sysname: %s\n", my_kernel.sysname);
    printf("nodename: %s\n", my_kernel.nodename);
    printf(" release: %s\n", my_kernel.release);
    printf(" version: %s\n", my_kernel.version);
    printf(" machine: %s\n", my_kernel.machine);

#ifdef _GNU_SOURCE
    printf("  domain: %s\n", my_kernel.domainname);
#endif

    return(EXIT_SUCCESS);
}
