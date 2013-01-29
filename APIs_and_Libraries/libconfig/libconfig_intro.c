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

File di configurazione
----------------------
Il file di configurazione per la lettura e la scrittura consiste in gruppi di 
impostazioni (settings) gerarchici e strutturati, nei quali si 
associano coppie nome/valore. 

Il valore puo' essere uno dei seguenti tipi di dato:
- Uno scalare;
- Un array;
- Un gruppo, che consiste in una collezione di impostazioni;
- Una lista, ossia una sequenza di valori di ciascun tipo.

Esempio (negozio, libreria, libri, etc, sono le impostazioni):

negozio
{
    libreria
    {
        libri 
        {
            titolo = "Libconfig programming tutorial";
            autore = "B3h3m0th";
            anno   = 2013;
        };
    };

    pizzeria
    {
        pizze_da_asporto
        {
            { nome = "margherita";
              prezzo = 4.00; }
            { nome = "capricciosa";
              prezzo = 4.50; }
            { nome = "4 stagioni";
              prezzo = 5.00; }
        };
    };
};
-------------------------------------------------------------------------------

Un path identifica ciascuna impostazione, e' espresso dalla sequenza dei nomi
iniziando dall'alto; ad esempio il path di autore e' :
negozio.libreria.libri.autore

*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
