#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h> /* getprotobyname() */

/* Il programma riceve un parametro da utilizzare con getprotobyname(), se tale
 * parametro corrisponde ad un protocollo valido saranno restituite alcune
 * informazioni specifiche relative al protocollo stesso.
 */

int main(int argc, char *argv[])
{
	int dominio = AF_INET;
	int tipo = SOCK_DGRAM;
	int protocollo = 0;

	/* la socket */
	int skt;
	/* Informazioni sul protocollo */
	struct protoent *proto_info;

	if (argc < 2) {
		fprintf(stderr, "Uso: %s <protocollo>\n", argv[0]);
		return -1;
	}

	/* getprotobyname() restituisce un puntatore ad una struttura protoent
	 * contenente campi con informazioni inerenti il protocollo */
	proto_info = getprotobyname(argv[1]);

	if (proto_info == NULL) {
		perror("getprotobyname:");
		return -1;
	}

	printf("Informazioni circa il protocollo:\n");
	printf("nome: %s\nalias %s\nnumero protocollo %d\n", 
			proto_info->p_name, *proto_info->p_aliases, proto_info->p_proto);

	protocollo = proto_info->p_proto;

	/* Creazione della socket */
	skt = socket(dominio, tipo, protocollo);

	if (skt < 0) {
		perror("socket");
		return -1;
	}
	
	return(EXIT_SUCCESS);
}
