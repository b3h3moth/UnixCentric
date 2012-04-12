#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    char *host_name = "www.lwn.com";

    int dominio = AF_INET;
    in_addr_t indirizzo = 0;
    int porta = 80;

    struct hostent *host_info = gethostbyname(host_name);

    indirizzo = *((in_addr_t *)host_info->h_addr_list[0]);

    struct sockaddr_in ind_trasporto;

    ind_trasporto.sin_family = dominio;
    ind_trasporto.sin_addr.s_addr = indirizzo;
    ind_trasporto.sin_port = htons(porta);

    return(EXIT_SUCCESS);
}
