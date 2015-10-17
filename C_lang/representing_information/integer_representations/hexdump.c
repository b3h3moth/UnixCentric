#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_BUF 20

int main (int argc, char* argv[]) {
    unsigned char buffer[MAX_BUF];
    size_t offset = 0;
    size_t bytes_read;
    int i, fd;
    
    if (argc == 1) {
        fprintf(stderr,"Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the file for reading
    if ((fd = open (argv[1], O_RDONLY)) == -1) {
        fprintf(stderr, "Err. open: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    do {
        bytes_read = read (fd, buffer, sizeof (buffer));
        
        /* Print the offset in the file. */
        printf ("0x%06x : ", offset);
        
        for (i = 0; i < bytes_read; ++i)
            printf ("%02x ", buffer[i]);
        printf ("\n");
        
        /* Keep count of our position in the file.  */
        offset += bytes_read;
    } while (bytes_read == sizeof (buffer));
    
    close (fd);
    
    return(EXIT_SUCCESS);
}
