#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

/* Quando un socket e' creato mediante la funzione socket() non ancora gli
viene assegnato un indirizzo, tale compito e' cura della funzione bind(),
l'associazione tra socket ed indirizzo prende il nome di binding.

HEADER    : <sys/socket.h>
PROTOTYPE : int bind(int sockfd, const struct sockaddr *addr, socklen_t len);
SEMANTICS : La funzione bind() assegna l'indirizzo 'addr' al socket 'sockfd',
            'len' definisce la lunghezza dell'indirizzo puntato da 'addr'.
RETURNS   : 0 in caso di successo, -1 in caso di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
    return(EXIT_SUCCESS);
}
