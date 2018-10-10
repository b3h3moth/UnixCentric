#include <stdio.h>
#include <stdlib.h>

int main(void) {
    float f = -317.125;
    int i = -1013018624;

    printf("valore di f: %f\nValore di i: %d\n", f, i);
    printf("Indirizzo di f: %p\nIndirizzo di i: %p\n", (void *)&f, (void *)&i);

    if (i == f)
        printf("i and f are equals\n");
    else
        printf("i and f are not equals\n");

    float *pf = &f;
    int *pi = &i;

    printf("*pf = %p\n*pi = %p\n", (void *)pf, (void *)pi);

    if (*pi == *pf)
        printf("*pi and *ipf are equals\n");
    else
        printf("*pi and *pf are not equals\n");

    void *vpf = &f;
    void *vpi = &f;
    printf("*vpf = %p\n*vpi = %p\n", vpf, vpi);

    // void * non può essere usato nelle espressioni

    // Cast esplicito con void *
    unsigned int *ipf = (unsigned int *)vpf;
    unsigned int *ipi = (unsigned int *)vpi;

    if (*ipi == *ipf) {
        printf("*ipi and *ipf are equals\n");
        printf("valore di *ipf: %u\nValore di *ipi: %u\n", *ipf, *ipi);
        printf("valore di *ipf: %08x (hex)\nValore di *ipi: %08x (hex)\n",
                *ipf, *ipi);
        /* Medesima sequenza di bit in memoria */
    } else
        printf("*ipi and *ipf are not equals\n");

    return(EXIT_SUCCESS);
}
