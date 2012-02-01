#include <stdio.h>
#include <stdlib.h>

/*
Nota: la libreria Standard I/O e' stata  scritta nel 1975 dal compianto Dennis 
Ritchie, venuto a mancare nell'ottobre del 2011.

Nella sezione "IO-Unbuffered" si e' discusso della gestione dell'I/O mediante le
primitive di basso livello fornite dal sistema operativo, che interagiscono
direttamente con il kernel, ora invece si affronta l'I/O bufferizzato gestito 
con le funzioni della libreria ISO C standard, implementate peraltro proprio
sopra le primitive di basso livello.

Allorquando si apre un file in lettura o in scrittura utilizzando la libreria 
I/O standard associamo ad esso uno stream, la cui orientazione determina se la 
lettura o scrittura dei caratteri sul file e' single-byte oppure multi-byte
(wide).

La funzione fopen() apre uno stream e ritorna un puntatore ad un oggetto FILE,
ovvero una struttura al cui interno vi sono svariate informazioni che consentono
la gestione dello stream, tra cui:
- Posizione corrente all'interno del file;
- Indicatore di errore;
- Indicatori di stato (lettura, scrittura o entrambi);
- La grandezza del buffer;
- Fine del file (EOF);

Nota: Il programmatore non ha alcuna necessita' di interagire direttamente con i
vari campi della struttura FILE, poiche' ciascuna operazione di I/O potra'
gestirla mediante un puntatore alla struttura stessa, definita in <stdio.h>.

Come accennato in IO-unbuffered, ogni processo dispone di 3 stream predefiniti, o file descriptor, nella sostanza sono gli stessi:
- standard input  = stdin  - POSIX(STDIN_LINENO);
- standard output = stdout - POSIX(STDOUT_LINENO;
- standard error  = stderr - POSIX(STDERR_LINENO).

Cosa si intende per I/O bufferizzato? I caratteri scritti su uno stream sono 
conservati in un buffer, essi tuttavia saranno trasmessi in blocco solo quando 
il buffer risultera' essere pieno (la bufferizzazione e' gestita automaticamente
dalla standard library); da notare inoltre che il lavoro di bufferizzazione e di
trasmissione dei dati in blocco e' svolto in modalita' asincrona, per cui e' 
possibile che, qualora due processi accedano contemporaneamente ad un file,
possano sorgere delle incongruenze.

Vi sono 3 tipi di buffering (modalita' di bufferizzazione):
- Fully Buffered, I caratteri sono trasmessi non appena il buffer e' pieno;
- Line buffered , I caratteri sono trasmessi non appena si incontra un '\n';
- Unbuffered    , I caratteri sono trasmessi non appena e' possibile.


HEADER    : <stdio.h>
PROTOTYPE : FILE *fopen(const char *path, const char *mode); 
SEMANTICS : La funzione fopen() apre il file puntato da 'path', secondo i 
            permessi 'mode'
RETURNS   : Il file puntato in caso di successo, NULL in caso di errore
--------------------------------------------------------------------------------
HEADER    : <stdio.h>
PROTOTYPE : FILE *freopen(const char *path, const char *mode); 
SEMANTICS : La funzione fopen() apre il file puntato da 'path', secondo i 
            permessi 'mode'
RETURNS   : Il file puntato in caso di successo, NULL in caso di errore
--------------------------------------------------------------------------------
HEADER    : <stdio.h>
PROTOTYPE : FILE *fdopen(const char *path, const char *mode); 
SEMANTICS : La funzione fopen() apre il file puntato da 'path', secondo i 
            permessi 'mode'
RETURNS   : Il file puntato in caso di successo, NULL in caso di errore
--------------------------------------------------------------------------------
*/
int main(int argc, char *argv[]) {
   return(EXIT_SUCCESS);
}
