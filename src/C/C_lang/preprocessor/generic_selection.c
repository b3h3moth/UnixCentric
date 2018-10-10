#include <stdio.h>
#include <stdlib.h>

// macro parametrica che si espande in un'espressione generica che a seconda
// del tipo di dato ritorna un determinato specificatore di formato
#define gen_fmt(f) _Generic((f),\
char: "%c",                     \
short: "%hd",                   \
int: "%d",                      \
long:"%ld",                     \
long long: "%lld",              \
float:"%f",                     \
double: "%f",                   \
long double: "%Lf")             \

// macro parametrica che stampa un valore di qualsiasi tipo di dato mediante
// la funzione printf()
#define gen_print(p) printf(gen_fmt(p), p)

#define NL printf("\n")

int main(void) {
    char c = 'H';   
    gen_print(c); NL;   
    
    int i = 100;
    gen_print(i); NL;
    
    float f = 12.5f;
    gen_print(f); NL;
    
    double d = 20.1234;
    gen_print(d); NL;    

    return (EXIT_SUCCESS);
}
