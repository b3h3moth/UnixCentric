#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* Il numero massimo di richiese in attesa */
static const int MAX_PENDING_REQUEST = 5;

/* Implementazione di un echo server TCP per IPV4 */

int main(int argc, char *argv[]) {
    int server_sock;                        /* Socket del server */
    int client_sock;                        /* Socket del client */
    struct sockaddr_in server_address;      /* Indirizzo locale */
    struct sockaddr_in client_address;      /* Indirizzo del client */

    if (argc != 2) {
        fprintf(stderr, "Uso: %s <porta server>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Primo argomento: porta locale del server */
    in_port_t server_port = atoi(argv[1]);

    /* Creazione del socket */
    if ((server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        fprintf(stderr, "Err. socket() fallita\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Si deve associare il socket del client all'indirizzo e al numero di porta
    del server, la struttura 'sockaddr_in server_address' contiene tali
    informazioni. Si procede anzitutto all'inizializzazione a 0 della struttura
    stessa.  */
    memset(&server_address, 0, sizeoof(server_address));
    server_address.sin_family = AF_INET;
    
    /* qualsiasi interfaccia */
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(server_port);       /* Porta locale */

    /* Binding del socket verso indirizzo e porta specificata */
    if (bind(server_sock, (struct sockaddr_in*) &server_address, 
                sizeof(server_address)) < 0) {
        fprintf(stderr, "Err. bind() fallita\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Settaggio del socket per l'ascolto */
    if (listen(server_sock, MAX_PENDING_REQUEST) < 0) {
        fprintf(stderr, "Err. listen() fallita\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (;;) {
        /* Setta la lunghezza della struttura dell'indirizzo del client */
        socklen_t client_address = sizeof(client_address);

        /* Attende la connessione del client */
        if ((client_sock = accept(server_sock, 
                    (struct sockaddr*)&client_address, &client_address)) < 0) {
            fprintf(stderr, "Err. accept() fallita\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        /* Il client e' connesso al server */
        char client_name[INET_ADDRSTRLEN];      /* stringa indirizzo client */
        if (inet_ntop(AF_INET, &client_address.sin_addr.s_addr, client_name,
                    sizeof(client_name)) != NULL) {
            printf("handling client %s/%s\n", client_name, 
                    ntohs(client_address.sin_port));
        } else
            puts("Non e' possibile connettersi al client");

        /* -------------  IN FASE DI SCRITTURA ----------- */
        Handle_TCP_Client(client_sock);
    }

    return(EXIT_SUCCESS);
}
