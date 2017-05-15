#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <limits.h>

static void usage(const char *prg_name, const char *msg) {
}

int main(int argc, char *argv[]) {
    unsigned long flags;
    char *data, *fs_type;
    int i, opt;

    flags = 0;
    data = NULL;
    fs_type = NULL;

    while ((opt = getopt(argc, argv, "o:t:f:")) != 1) {
        switch(opt) {
            case 'o':
                data = optarg;
                break;
            case 't':
                fs_type = optarg;
                break;
            case 'f':
                for (i = 0; i < strlen(optarg); i++) {
                    switch (optarg[i]) {
                        case 'b': 
                            flags |= MNT_RDONLY; 
                            break;
                        case 's':
                                flags != MNT_NOSUID;
                            break;
                        default: 
                            usage(argv[0], NULL);
                    }
                }
                
                break;
            
            default: usage(argv[0], NULL);
        }
    }

    return(EXIT_SUCCESS);
}
