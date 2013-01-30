#include <stdio.h>
#include <stdlib.h>
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
- Uno scalare, se e' inserito tra doppi apici sara' una stringa, 
               altrimenti sara' trattato come un intero a 64 bit, 
               un floating-point o un boolean;


- Un array,    se e' inserito tra parentesi quadre con ciascun elemento 
               separato da una virgola;

- Un gruppo,   consiste in una collezione di settings;

- Una lista,   sequenza di valori di qualunque tipo, inserita tra parentesi e
               ciascun elemento separato da una virgola.

Settings
nome = valore ;
nome : valore;

Gruppi
{settings ... }

Array
[valore, valore ... ]

Liste
(valore, valore ...)

---------- 8< ---------- 
business = 1.0;

negozio =
{
    libreria =
    {
        libri =
        {
            titolo = "Libconfig programming tutorial";
            autore = "B3h3m0th";
            anno   = 2013;
        };
    };

    pizzeria =
    {
        pizze_da_asporto =
        (
            { nome = "margherita";
              prezzo = 4.00; },
            { nome = "capricciosa";
              prezzo = 4.50; },
            { nome = "4 stagioni";
              prezzo = 5.00; }
        );
    };
};
---------- 8< ---------- 

Un path identifica ciascun setting, ed e' espresso dalla sequenza dei nomi
iniziando dall'alto fino a raggiungere il corrispondente; ad esempio il path di 
autore e' "negozio.libreria.libri.autore", se invece un setting e' privo di nome
perche' e' un elemento di una lista o di un array, si utilizza il relaivo indice
tra parentesi quadre, ad esempio "negozio.pizzeria.pizze_da_asporto.[2].nome" 
indica il terzo elemento, ossia la pizza "4 stagioni".

Libconfig prevede tre tipi di commenti:
- In stile C,       * / ....  / * 
- In stile C++,     //
- Stile classico,   #

*/

int main(int argc, char *argv[]) {
    config_t cfg;
    config_setting_t *setting;
    const char *base = NULL, *str1, *str2;
    int count, n, boolean_value;
    double ker;
    char *config_file_name = "test.cfg";

    /* Inizializzazione */
    config_init(&cfg);

    if (!config_read_file(&cfg, config_file_name)) {
        fprintf(stderr, "%d - %s\n",
                config_error_line(&cfg),
                config_error_text(&cfg));

        config_destroy(&cfg);

        return(EXIT_FAILURE);
    }

    /* Si verifica l'esistenza di un un valore booleano */
    if (config_lookup_bool(&cfg, "prova", &boolean_value))
            printf("valore booleano: %s\n", boolean_value ? "Yes" : "No");
    else
        printf("boolean_value is non defined\n");

    /* Ricezione di una stringa */
    if (config_lookup_string(&cfg, "filename", &str1))
        printf("   Tipo di file: %s\n", str1);
    else
        printf("No filename setting config file\n");

    setting = config_lookup(&cfg, "rete");

    if (setting != NULL) {
        /* Legge  stringa */
        if (config_setting_lookup_string(setting, "host", &str2))
            printf("           Host: %s\n", str2);
        else
            printf("No host\n");

        if (config_setting_lookup_string(setting, "arch", &str2))
            printf("   Architettura: %s\n", str2);
        else
            printf("No arch\n");
        
        if (config_setting_lookup_float(setting, "kernel", &ker))
            printf(" Kernel version: %f\n", ker);
        else
            printf("No kernel\n");
    }

    setting = config_lookup(&cfg, "negozio.libri");
    if (setting != NULL) {
        /* Legge  stringa */
        if (config_setting_lookup_string(setting, "titolo", &str2))
            printf("         Titolo: %s\n", str2);
        else
            printf("Niene pizza oggi\n");
    }

    // Quando si lavora con liste o con array si utilizza l'indicizzazione */
    setting = config_lookup(&cfg, "negozio.pizzeria.pizze_da_asporto.[1]");
    if (setting != NULL) {
        /* Legge  stringa */
        if (config_setting_lookup_string(setting, "nome", &str2))
            printf("          Pizza: %s\n", str2);
        else
            printf("NO PARAMMMM\n");
    }


    return(EXIT_SUCCESS);
}
