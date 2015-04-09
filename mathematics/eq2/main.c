#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>


int main(int argc, char *argv[]) {
    double a,b,c, x1, x2 = 0;
    double delta = 0;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <a><b><c>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((a = strtol(argv[1], NULL, 10)) == 0 ) {
        fprintf(stderr, "Err.: a argument %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((b = strtol(argv[2], NULL, 10)) == 0 ) {
        fprintf(stderr, "Err.: b argument %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if ((c = strtol(argv[3], NULL, 10)) == 0 ) {
        fprintf(stderr, "Err.: c argument %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf ("a: %f\nb: %f\nc: %f\n", a,b,c);
    delta =  (pow(b, 2) - 4 * a * c);
    printf("delta (b^2 -4ac) : %f\n", delta);

    x1 = (-b + sqrt(delta)) / (2 * a * c);
    x2 = (-b - sqrt(delta)) / (2 * a * c);

    printf("x1: %f\nx2: %f\n", x1, x2);
    return(EXIT_SUCCESS);
}
