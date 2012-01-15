#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h> /* getprotobyname() */

int main(int argc, char *argv[])
{
	/* int socket(int dominio, int tipo, int protocollo);
	 * header da includere: <sys/socket.h>
	 *
	 * La creazione di un socket è gestita mediante la funzione socket(), che
	 * restituisce un file descriptor mediante il quale e' possibile far 
	 * riferimento al socket stesso; i parametri della funzione socket sono tre,
	 * dominio, tipo e protocollo.
	 *
	 * 1 - Dominio:
	 * definisce il dominio del socket, ossia la famiglia di protocolli
	 * utilizzati, si possono adoperare alcune costanti tra cui:
	 *
	 * AF_UNIX	dominio UNIX, comunicazioni locali
	 * AF_INET	internet, per comunicazioni con protocollo ipv4
	 * AF_INET6	internet versione 6, per comunicazioni con protocollo ipv6
	 *
	 * AF sta per Address Family, ossia il formato degli indirizzi utilizzati
	 * da quel dominio.
	 *
	 * 2 - Tipo: 
	 * definisce il tipo di comunicazione, anche in questo caso si possono 
	 * utilizzare alcune costanti, tra cui:
	 *
	 * SOCK_STREAM		socket byte-stream
	 * SOCK_DGRAM		socket datagram
	 * SOCK_RAW			accesso a funzionalita' di basso livello
	 * SOCK_SEQPACKET	canale di comunicazione affidabile, bidirezionale
	 *
	 * 3 - Protocollo
	 * indica il protocollo, solitamente e' impostato a 0.
	 *
	 */
	int dominio = AF_INET;
	int tipo = SOCK_DGRAM;
	int protocollo = 0;

	/* Il socket */
	int skt;
	/* Informazioni sul protocollo */
	struct protoent *proto_info;

	proto_info = getprotobyname("udp");

	if (proto_info == NULL) {
		perror("getprotobyname");
		return -1;
	}

	/* Si utilizza il campo della struttura protoent p_proto per ricavare il
	 * parametro relativo al numero del protocollo */
	protocollo = proto_info->p_proto;

	/* Si apre il socket */
	skt = socket(dominio, tipo, protocollo);

	if (skt < 0) {
		perror("socket");
		return -1;
	}
	
	return(EXIT_SUCCESS);
}
