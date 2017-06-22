#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define TIME_STRING_BUF 50

char *timeString(time_t t, char * buf);
int fileStats(const char * file);

/* Il programma fornisce informazioni riguardo al file recevuto come argomento,
tali informazioni saranno processate mediante la funzione lstat(). */

int main(int argc, char *argv[]) {
    int i;
    int rc = 0;

    /* Sara' invocata la funzione fileStats() per ciascun argomento,
    presumibilmente un filename */
    for (i=1; i<argc; i++) {
        rc |= fileStats(argv[i]);
        
        if ((argc - i) > 1) 
            printf("\n");
    }
    return rc;
}

char *timeString(time_t t, char * buf) {
    struct tm * local;
    
    local = localtime(&t);
    strftime(buf, TIME_STRING_BUF, "%c", local);
    return buf;
}


int fileStats(const char * file) {
    struct stat statbuf;
    char timeBuf[TIME_STRING_BUF];

    if (lstat(file, &statbuf)) {
        fprintf(stderr, "Err. lstat() %s: %s\n", file, strerror(errno));
         return(EXIT_FAILURE);
    }

    printf("Filename : %s\n", file);
    printf("On device: major %d/minor %d    Inode number: %ld\n",
            major(statbuf.st_dev), minor(statbuf.st_dev),
            (long int)statbuf.st_ino);
    printf("Size     : %-10ld         Type: %07o       "
            "Permissions: %05o\n", (long int)statbuf.st_size,
            statbuf.st_mode & S_IFMT, statbuf.st_mode & ~(S_IFMT));
    printf("Owner    : %d                Group: %d"
            "          Number of links: %d\n",
            statbuf.st_uid, statbuf.st_gid, statbuf.st_nlink);
    printf("Creation time: %s\n",
            timeString(statbuf.st_ctime, timeBuf));
    printf("Modified time: %s\n",
            timeString(statbuf.st_mtime, timeBuf));
    printf("Access time  : %s\n",
            timeString(statbuf.st_atime, timeBuf));

    return 0;
}

