#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <libconfig.h>

/* La libreria "libconfig" serve per leggere e scrivere file di configurazione
strutturati, per essere utilizzata in C dev'essere inserito l'header 
<libconfig.h>.

Alcune caratteristiche della libreria:
- Fully reentrant;
- POSIX compilant;
- C/C++ binding;
- Non e' thread-safe;
- Non e' async-safe.

Compilazione con GCC e pkg-config
---------------------------------
L'utility pkg-config puo' essere utilizzata per ottenere automaticamente le
informazioni necessarie per compilare programmi che includono, in questo caso, 
la libreria libconfig; un esempio tipico e' il seguente:

$ gcc main.c $(pkg-config --cflags --libs libconfig) -o main

$ gcc main.c `pkg-config --cflags --libs libconfig` -o main
                                          
"pkg-config" e' una utility unix molto potente, ma soprattutto utile e semplice
da usare.


*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
