#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h> /* getprotobyname() */

int main(int argc, char *argv[])
{
	/* Per il dominio si possono utilizzare talune costanti definite in 
	 * sys/socket.h:
	 *
	 * AF_UNIX	dominio UNIX, comunicazioni locali
	 * AF_INET	internet, per comunicazioni con protocollo ipv4
	 * AF_INET6	internet versione 6, per comunicazioni con protocollo ipv6
	 *
	 * Per il tipo/trasferimento si possono utilizzare talune costanti anch'esse
	 * definite in sys/socket.h:
	 *
	 * SOCK_STREAM	per socket byte-stream
	 * SOCK_DGRAM	per socket datagram
	 * SOCK_RAW		per l'accesso a funzionalita' di basso livello
	 */
	int dominio = AF_INET;
	int tipo = SOCK_DGRAM;
	int protocollo = 0;

	/* La socket */
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

	/* Creazione della socket */
	skt = socket(dominio, tipo, protocollo);

	if (skt < 0) {
		perror("socket");
		return -1;
	}
	
	
	return(EXIT_SUCCESS);
}
