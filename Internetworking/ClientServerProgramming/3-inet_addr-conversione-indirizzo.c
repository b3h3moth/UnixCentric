#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>	/* in_addr_t */
#include <arpa/inet.h>	/* inet_addr */


int main(int argc, char *argv[])
{
	/* Indirizzo da convertire, nella forma decimale puntato */
	char *ind_dp = "74.125.232.114";

	/* I sistemi operativi che utilizzano lo standard POSIX conservano gli
	 * indirizzi in una variabile di tipo in_addr_t */
	in_addr_t ind;

	/* Converte ind_dp da indirizzo decimale puntato a numero IP in formato
	 * di rete */
	ind = inet_addr(ind_dp);

	/* INADDR_NONE e' una costante che indica indirizzo errato */
	if (ind == INADDR_NONE) {
		perror("inet_addr");
		return -1;
	}

	/* Essendo in_addr_t un unsigned long int, si fornisce alla printf %u */
	printf("Indirizzo IP formato di rete 32bit: %u\n", ind);

	return(EXIT_SUCCESS);
}
