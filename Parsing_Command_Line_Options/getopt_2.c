#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int opt;
    int nsecs, tfnd, flags; 
    nsecs = tfnd = flags = 0; 

    while ((opt = getopt(argc, argv, "nm:")) != -1) {
        switch (opt) {
            case 'n':
                flags = 1;
                break;
	        case 'm':
	            nsecs = atoi(optarg);
	            tfnd = 1;
	            break;
	        default:
                fprintf(stderr, "Usage: %s [-n nsecs] [-m] name\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    printf("flags=%d; tfnd=%d; optind=%d\n", flags, tfnd, optind);

    if (optind >= argc) {
        fprintf(stderr, "Expected argument after options\n");
        exit(EXIT_FAILURE);
    }
    
    printf("name argument = %s\n", argv[optind]);

    exit(EXIT_SUCCESS);
}

// from getopt() 3 man pages
