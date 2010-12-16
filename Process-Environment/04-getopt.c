#include <stdio.h>
#include <unistd.h>

/* Studio della funzione getopt()
 *******************************************************************************
 * Header da includere: <unistd.h> che a sua volta include il file header
 * <getopt.h>
 *
 * Ciò che maggiormente interessa dell'header sono alcune variabili ed una 
 * funzione:
 *
 * extern char *optarg;
 * --------------------
 * Il puntatore optarg referenzia l'indirizzo all'interno del quale e' collocato
 * il parametro relativo all'ozione in fase di elaborazione.
 *
 * extern int opitnd;
 * ------------------
 * La funzione getopt() incrementa il valore di optind di volta in volta che
 * sono elaborate tutte le opzioni presenti nelle successive chiamate; di
 * default optind assume il valore di 1, per cui il primo parametro ad essere
 * sara' argv[1], dopodiche', elaborate tutte le restanti opzioni, optind 
 * conterra' l'indice del prossimo parametro.
 *
 * extern int opterr;
 * ------------------
 * La variabile esterna opterr assume anch'essa il valore di default 1 (true),
 * essa e' utilizzata come dato di input per la funzione getopt(). Se opterr e'
 * uguale a true sara' elaborato il carattere di opzione non valido e la
 * funzione getopt() fara' stampare su stderr un messaggio con l'opzione
 * corretta. Se invcece la variabile opterr risulta falsa, ossia impostata a 0,
 * non ci saranno messaggi di errore, pur avendo elaborato un'opzione non
 * valida. In tal modo si puo' controllare in maniera molto efficiente se
 * inserire un messaggio di errore e su quale stream inviarlo, per cui
 * impostando opterr a 0 non saranno inviato messaggi d'errore.
 *
 * extern intr optopt;
 * -------------------
 * La variabile esterna optopt setta un carattere, riferibile ad un'opzione non
 * riconosciuta.
 *
 *
 * extern int getopt(int argc, char *const *argv, const char *shortopts);
 * ----------------------------------------------------------------------
 * Il primo parametro argc contiene il numero totale dei parametri conenuti
 * nell'array argv[]; il secondo parametro argv e' un array di puntatori a
 * stringa, contiene le opzioni ed i parametri inseriti; il terzo ed ultimo
 * parametro shortopts, e' un puntatore a stringa, che in un certo senso
 * gestisce l'intera operazione della getopt(), poiche' determina quali sono le
 * opzioni valide e quali accettano parametri propri. Semplificando si potrebbe
 * affermare che shortopts contiene l'interfaccia del programma.
 */

int main(int argc,char **argv) {
    int optch;
    static char optstring[] = "gW:c";

    while ( (optch = getopt(argc,argv,optstring)) != -1 )
        switch ( optch ) {
        case 'c' :
            puts("-c processed.");
            break;
        case 'g' :
            puts("-g processed.");
            break;
        case 'W' :'
            printf("-W '%s' processed.\n",optarg);
            break;
        default :
            puts("Unknown option!");
        }

    for ( ; optind < argc; ++optind )
        printf("argv[%d] = '%s'\n", optind, argv[optind]);

    return 0;
}
