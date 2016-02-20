#include <stdio.h>
#include <stdlib.h>

/* Lo standard C11 ha inrodotto le 'anonymous structures and unions', mediante
le quali e' lecito definire strutture e unioni prive sia di tag sia di 
variabili, dotate del solo specificatore 'struct' o 'union'.

c11 standard definition:
"A structure or union is defined without any named members".
*/

typedef struct {
    union {
        struct {
            int x;
            int y;
            int z;
        };
        int a[2];
    };
} vec_t;

int main(void) {

    return(EXIT_SUCCESS);
}
