#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

/*
Lo standard POSIX.1 prevede una specifica interfaccia per la lettura delle
directory, denominata "directory stream"; una directory puo' essere lette da
chiunque abbia i permessi di lettura su di essa, ma per preservare la coerenza e
prevenire l'inconsisenza del file system solo il kernel puo' scrivervi.
--------------------------------------------------------------------------------
HEADER    : <dirent.h>
PROTOTYPE : DIR *opendir(const char *pathname); 
SEMANTICS : Apre il directory stream 'pathname'
RETURNS   : Un puntatore al directory stream in caso di successo, NULL in caso
            di errore

La struttura DIR e' una struttura interna utilizzata dalle funzioni per la 
gestione delle directory, contiene inoltre specifiche informazioni sulle
directory stesse; la funzione opendir() peraltro posiziona lo stream sulla prima
voce di directory, permettendo in tal modo alla readdir() di poter leggerla.

Formato e contenuto di una directory sono dipendenti dal sistema, le sole 3
funzioni che invece sono indipendenti dal sistema sono la stessa opendir(),
readdir() e closedir(), mediante le quali si riesce ad ottenere numero di inode
e nome della directory.

La struttura dirent e' definita nell'header dirent.h; da notare che una 
directory consiste generalmente di due soli elementi, il suo nome ed il numero
di inode, ossia 'd_name' e 'd_ino' della struttura dirent:

struct dirent
{
    __ino_t		d_ino;
    __off_t		d_off;
    unsigned short int	d_reclen;
    unsigned char	d_type;
    char 		d_name[256];
};

--------------------------------------------------------------------------------
HEADER    : <dirent.h>
PROTOTYPE : struct dirent *readdir(DIR *dp);
SEMANTICS : Legge 
RETURNS   : Un puntatore al directory stream in caso di successo, NULL in caso
            di errore
--------------------------------------------------------------------------------
*/

int main(int argc, char *argv[]) {
   DIR *dfd;
   struct dirent *dp;

   if (argc < 2) {
      fprintf(stderr, "Uso: %s <dirname>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   if ((dfd = opendir(argv[1])) == NULL) {
      fprintf(stderr, "Err.:(%d) - %s on dir: %s\n", errno, strerror(errno), argv[1]);
      exit(EXIT_SUCCESS);
   }

   while ((dp = readdir(dfd)) != NULL) {
      if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
      	 continue;
      else
      	 printf("%s\n", dp->d_name);
   }
   
   closedir(dfd);

   exit(EXIT_SUCCESS);
}
