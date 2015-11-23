#include <stdio.h>
#include <stdlib.h>

/* Con una word di 32 bit, il compilatore allochera' 32 bit, su architettura
Big-endian i bit saranno allineati da destra a sinistra, per cui il bit piu'
significativo sara' a sinistra, che corrispondera' al primo bit del campo
'day */
struct date {
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 7;
}; 

union int_date {
    unsigned short i;
    struct date fd;
};

void print_date(unsigned short n);

int main(void) {              // 5 bit 4 bit 7 bit
    unsigned short x = 48627; // 10111 1011  1110011
                              // 23    11    2015 
                              // 23/Nov/2015
    print_date(x);

    return(EXIT_SUCCESS);
}
void print_date(unsigned short n) {
    union int_date u;
    u.i = n;

    printf("%d\t%d\t%d\n", u.fd.day, u.fd.month, u.fd.year+1900);
}
