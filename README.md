# INTRODUZIONE AL PROGETTO LEARNING-'PL'


Il progetto Learning-'Programming Language' mira a realizzare un manuale 
code oriented su alcuni dei linguaggi di programmazione maggiormente 
utilizzati sui sistemi operativi UNIX, in particolare con kernel Linux e BSD.

Per code oriented si intende anzitutto immediata operativita', nel senso che
non ci saranno pagine da sfogliare ma solo e soprattutto righe di codice da
leggere ed interpretare, commenti mirati inoltre saranno inseriti all'interno
del codice stesso laddove ce ne fosse bisogno.

I libri talvolta si perdono in inutili dettagli, tralasciando troppo spesso
il codice, L-'PL' invece si pone l'obiettivo di fare il lavoro opposto, e
rendere al codice la giusta collocazione che merita, ossia di primo attore
indiscusso.

Oltre alle regole fondamentali di ciascun linguaggio di programmazione, 
indipendentemente dal paradigma utilizzato, si prestera' particolare 
attenzione alle tecniche per scrivere codice di qualita' e sicuro.

Al momento della stesura di questo documento sono stati scelti due paradigmi
di programmazione e due linguaggi specifici; il paradigma Object Oriented 
con il linguaggio C++ e il paradigma procedurale con il linguaggio C-ANSI.

Infine un ulteriore repository sara' dedicato alla programmazione di sistema
su sistemi operativi UNIX con kernel Linux.

Per cio' che concerne la programmazione su sistemi UNIX, si cerchera' di
rendere il codice conforme a SUSv3 (Single Unix Specification) e POSIX.1-2001,
con riferimenti al nuovo SUSv4 e POSIX.1-2008.


## LEARNING-'Linux Programming' - Programmazione di sistema (GNU/Linux)

Il presente repository riguarda la programmazione di sistema su sistemi
operativi UNIX con kernel Linux, pertanto è stato contrassegnato come L-LP.

Ciascun sorgente potra' essere compilato mediante GCC e clang

`$ gcc main.c -o main`
`$ clang main.c -o main`

Tuttavia, se si volesse compilare con maggiore accortezza, sia per l'eventuale
debug sia per avere a disposizione maggiori informazioni in caso di errore ma
anche e sopratutto per l'ottimizzazione del codice, si possono utilizzare i 
seguenti parametri:

`$ gcc   -g main.c -Wall -W -D_GNU_SOURCE -pedantic`
`$ clang -g main.c -Wall -W -D_GNU_SOURCE -pedantic`

### Le versioni dei compilatori adoperati:

* gcc (Debian 4.4.5-2)  4.4.5 (old)     PPC  32bit
* gcc (Debian 4.4.5-8)  4.4.5 (old)     PPC  32bit
* gcc (Debian 4.6.3-14) 4.6.3           PPC  32bit
* gcc (Debian 4.9.0-7)  4.9.0 (old)     i386 32bit
* gcc (Debian 4.9.3-2)  4.9.3           i386 32bit

* clang version 3.0-6.2                 PPC  32bit
* clang version 3.5.2-1                 i386 32bit

Allorquando si iniziera' a lavorare con progetti di medie dimensioni si
utilizzeranno ulteriori tecniche e soprattutto nuovi tool per la compilazione, 
come ad esempio gli autotools.

I nomi delle directory sono stati denominati seguendo i capitoli dello _Stevens_
"_Advanced Programming in the UNIX Environment 2nd_", tuttavia sia il codice 
sorgente sia il testo e' stato critto da zero, totalmente nuovo, non mancano 
tuttavia continui riferimenti allo Stevens, la si consideri come una dedica 
verso uno dei piu' illustri informatici del XX secolo, UNIX guru inimitabile.

Ottobre 2011: E' venuto a mancare uno dei padri del sistema operativo UNIX, 
nonche' co-autore del linguaggio C, Dennis Ritchie.

Dedico questo modesto lavoro, con un senso di profonda gratitudine per tutto 
cio' che ci hanno lasciato, a Richard Stevens e Dennis Ritchie.

## Biblio


## INFO
Per commenti, info e quant'altro: `behemoth _at_ autistici _dot_ org`

Qualora si volesse comunicare mediante crittografia a chiave pubblica:

`KeyID = 0xE83F9FBB` 

La chiave pubblica e' reperibile in uno dei server adibiti alla gestione delle
chiavi pubbliche, ad esempio pgp.mit.edu

`Luca Suriano a.k.a. behemoth`
