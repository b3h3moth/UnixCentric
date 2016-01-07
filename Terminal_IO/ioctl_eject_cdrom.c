#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/cdrom.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);

    return(EXIT_SUCCESS);
}
