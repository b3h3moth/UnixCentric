#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    printf("Permessi originari:\n");
    printf("EUID: %d\n", geteuid());
    printf("EGID: %d\n", getegid());

    /* 
    Si testi il programma dopo aver apportato le seguenti modifiche al file 
    binario:
    $ sudo chown root.root a.out && sudo chmod +s a.out

    Se si esegue il programma con i normali privilegi, le funzioni, ovviamente,
    non apporteranno nessuna modifica, impostando invece il bit suid ed
    aggiornando i privilegi sul file, si otterra' il risultato desiderato.
    */
    
    printf("Permessi modificati:\n");
    seteuid(500);
    setegid(1000);
    printf("EUID: %d\n", geteuid());
    printf("EGID: %d\n", getegid());

    return(EXIT_SUCCESS);
}
