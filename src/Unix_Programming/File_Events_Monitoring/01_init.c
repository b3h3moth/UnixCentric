#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>

int main(int argc, char *argv[]) {
    int intf_fd;

    intf_fd = inotify_init();

    return(EXIT_SUCCESS);
}
