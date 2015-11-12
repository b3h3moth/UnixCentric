## INTRODUZIONE AL PROGETTO LEARNING-\<Programming Language\>

Il progetto Learning-<Programming Language> mira a realizzare un manuale 
code oriented su alcuni dei linguaggi di programmazione maggiormente 
utilizzati sui sistemi operativi UNIX con kernel Linux.

Per code oriented si intende anzitutto immediata operativita', nel senso che
non ci saranno pagine da sfogliare ma solo e soprattutto righe di codice da
leggere ed interpretare, commenti mirati inoltre saranno inseriti all'interno
del codice stesso laddove ce ne fosse bisogno.

I libri talvolta si perdono in inutili dettagli, tralasciando troppo spesso
il codice, L-<PL> invece si pone l'obiettivo di fare il lavoro opposto, e
rendere al codice la giusta collocazione che merita, ossia di primo attore
indiscusso.

Oltre alle regole fondamentali di ciascun linguaggio di programmazione, 
indipendentemente dal paradigma utilizzato, si prestera' particolare 
attenzione alle tecniche per scrivere codice di qualita' e sicuro.

Al momento della stesura di questo documento sono stati scelti due paradigmi
di programmazione e due linguaggi specifici; il paradigma Object Oriented 
con il linguaggio C++ e il paradigma procedurale con il linguaggio C.

Infine un ulteriore repository sara' dedicato alla programmazione di sistema
su sistemi operativi unix-like con kernel Linux e un altro ancora interamente 
incentrato sul magnifico linguaggio Perl, che nei sistemi operativi unix-like 
trova il suo habitat ideale.

### LEARNING-<C> - Paradigma procedurale (imperativo), Linguaggio C (c99, C11)

Il presente repository riguarda il paradigma procedurale, presentato mediante
il linguaggio di programmazione C-ANSI (c99, c11);  è stato contrassegnato
come L-C.

I programmi saranno tutti compilati utilizzando i seguenti standard:
- iso9899:1999, -std=c99 
- iso9899:2011, -std=c11 (sperimentale e incompleto in GCC, dalla versione 4.7)

Saranno utilizzate diverse architetture per testare gli esempi: 
- PPC 32 bit (big endian)
- x86 32 bit (little endian)
- x86 64 bit (little endian)

Ciascun sorgente potra' essere compilato sia mediante il compilatore GCC sia
con il comilatore Clang (LLVM);
$ `gcc   main.c -o main`
$ `clang main.c -o main`

Oppure, se si vuole maggiore dettaglio:
$ `gcc   -o main main.c -g -Wall -pedantic -std=c90 | c99 | c11`
$ `clang -o main main.c -g -Wall -pedantic -std=c90 | c99 | c11`

Nota: L'opzione -ansi e' equivalente a -std=c90 per il C ed a -std=c++98 per il
      C++. Inoltre -std=c90 e' equivalente a -std=c89.

Allorquando si iniziera' a lavorare con progetti di medie dimensioni si
utilizzeranno ulteriori tecniche e soprattutto nuovi tool per la compilazione, 
come ad esempio gli autotools.

``<behemoth _at_ autistici _dot_ org>``
``https://keybase.io/behemoth``
