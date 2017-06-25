#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

enum {CMD_SZ=200, BUF_SZ=1024};

int main(int argc, char *argv[]) {
    int fd, n_blks;
    char cmd[CMD_SZ];   /* Comando da eseguire via shell */
    char buf[BUF_SZ];   /* Random byte da scrivere nel file */



    exit(EXIT_SUCCESS);
}
