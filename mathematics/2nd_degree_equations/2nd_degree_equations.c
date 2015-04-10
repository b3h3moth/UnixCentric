#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>


/* how to solve 2nd degree equation (it's also called quadratic equation) */

int main(int argc, char *argv[]) {
    double a,b,c, x1, x2 = 0;
    double delta, sum, product = 0;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <+/-num1><+/-num2><+/-num3>\n", argv[0]);
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

    printf("Equation is:\n\t((%.0lfx²) + (%.0lfx) + (%.0lf) = 0)\n", a,b,c);
    delta = (pow(b, 2) - (4 * a * c));
    printf("Delta (discriminant):\n\t%.0lf\n", delta);

    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
    } else if (delta = 0)
        x1 = x2 = -b / (2*a);
    else {
        fprintf(stderr, "(delta < 0) Equation is irrisolvible. Bye!\n");
        exit(EXIT_FAILURE);
    }

    printf("Solutions are:\n\tx1: %.0lf\n\tx2: %.0lf\n", x1, x2);

    sum = -b / a;
    product = c / a;

    printf("Sum (x1+x2):\n\t%.0lf\nProduct (x1*x2):\n\t%.0lf\n", sum, product);



    return(EXIT_SUCCESS);
}
