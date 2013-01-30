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
settings (in italiano combinazioni o impostazioni, il termine in inglese 
tuttavia rende l'idea perfettamente) gerarchici e strutturati, con coppie 
"nome = valore". 

Il valore puo' essere uno dei seguenti tipi di dato:
- Uno scalare;
- Un array;
- Un gruppo, che consiste in una collezione di impostazioni;
- Una lista, ossia una sequenza di valori di ciascun tipo.

Esempio (negozio, libreria, libri, etc, sono le impostazioni):

---------- 8< ---------- 

business = 1.0;

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
---------- 8< ---------- 

Un path identifica ciascun setting, ed e' espresso dalla sequenza dei nomi
iniziando dall'alto fino a raggiungere il corrispondente; ad esempio il path di 
autore e' "negozio.libreria.libri.autore", se invece un setting e' privo di nome
perche' e' un elemento di una lista o di un array, si utilizza il relaivo indice
tra parentesi quadre, ad esempio "negozio.pizzeria.pizze_da_asporto.[2].nome" 
indica il terzo elemento, ossia la pizza "4 stagioni".

*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
