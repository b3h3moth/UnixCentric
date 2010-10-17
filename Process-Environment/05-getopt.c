#include <stdio.h>
#include <getopt.h>

int main(int argc,char **argv) {
    int optch;
    static char optstring[] = "gW:c";

    while ( (optch = getopt(argc,argv,optstring)) != -1 )
        switch ( optch ) {
        case 'c' :
            printf("-c processed ___%d___.\n", optind);
            break;
        case 'g' :
            printf("-g processed ___%d___.\n", optind);
            break;
        case 'W' :
            printf("-W '%s' processed ___%d___\n",optarg, optind);
            break;
        default :
            puts("Unknown option!\n");
        }

    for ( ; optind < argc; ++optind )
        printf("argv[%d] = '%s'\n", optind, argv[optind]);

    return 0;
}
