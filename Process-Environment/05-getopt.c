#include <stdio.h>
#include <getopt.h>

int main(int argc,char **argv) {
    int optch;
    static char optstring[] = "gW:c";

    while ( (optch = getopt(argc,argv,optstring)) != -1 )
        switch ( optch ) {
        case 'c' :
            puts("-c processed.");
            break;
        case 'g' :
            puts("-g processed.");
            break;
        case 'W' :
            printf("-W '%s' processed.\n",optarg);
            break;
        default :
            puts("Unknown option!");
        }

    for ( ; optind < argc; ++optind )
        printf("argv[%d] = '%s'\n", optind, argv[optind]);

    return 0;
}
