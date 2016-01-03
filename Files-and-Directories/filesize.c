#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int main(){
    struct stat infobuf;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if (stat("/etc/passwd", &infobuf) == -1 ) {
        fprintf(stderr, "Err. stat(): %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    } else
        printf("The size of /etc/passwd is %ld\n", infobuf.st_size );
}
