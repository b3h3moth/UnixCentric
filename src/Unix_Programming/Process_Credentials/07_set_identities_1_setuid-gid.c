#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Lo scopo del programma e' di ridurre inizialmente i privilegi di 'root' - 
- superuser -, dopodiche' rendere definitivo il nuovo settaggio. */

int main(void) {
    printf("Permessi originari:\n");
    printf("RUID: %d\n", getuid());
    printf("EUID: %d\n", geteuid());
    printf("RGID: %d\n", getgid());
    printf("EGID: %d\n", getegid());

    /* 
    Si testi il programma dopo aver apportato le seguenti modifiche al file 
    binario:
    $ sudo chown root.root a.out && sudo chmod +s a.out

    Se si esegue il programma con i normali privilegi, le funzioni, ovviamente,
    non apporteranno nessuna modifica, impostando invece il bit suid ed
    aggiornando i privilegi sul file, si otterra' il risultato desiderato.
    */

    printf("\nAbbassamento permessi: setuid(1000) setgid(1000)\n");
    setuid(1000);
    setgid(1000);
    printf("RUID: %d\n", getuid());
    printf("EUID: %d\n", geteuid());
    printf("RGID: %d\n", getgid());
    printf("EGID: %d\n", getegid());

    printf("\nRipristino permessi: setuid(0) setgid(0)\n");
    setuid(0);
    setgid(0);
    printf("RUID: %d\n", getuid());
    printf("EUID: %d\n", geteuid());
    printf("RGID: %d\n", getgid());
    printf("EGID: %d\n", getegid());

    return(EXIT_SUCCESS);
}
