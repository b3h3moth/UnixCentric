#include <stdio.h>
#include <stdlib.h>

// definisce una macro parametrica che si espande in un'espressione generica che a seconda
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

// definisce una macro parametrica che consente di stampare con printf 
// un valore di qualsiasi tipo di dato
#define g_print(p) printf(gen_fmt(p), p)

#define NL printf("\n")

int main(void) {
    char c = 'A';   
    g_print(c); NL;   
    
    int i = 10;
    g_print(i); NL;
    
    float f = 10.3f;
    g_print(f); NL;
    
    double d = 10.3344;
    g_print(d); NL;    

    return (EXIT_SUCCESS);
}
