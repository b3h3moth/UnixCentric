#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *buf;
    int in_fd, out_fd, nread;
    off_t in_offst, out_offst;
    size_t in_size, out_size;

    if (argc != 7) {
        fprintf(stderr, "Usage: %s dd <input_file> <input_offset> <input size>"
                " <output file> <output offset> <output size>", argv[0]);
        exit(EXIT_FAILURE);
    }

    in_fd = open(argv[1], O_RDONLY);
    if (in_fd < 0) {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    return(EXIT_SUCCESS);
}
