/* 
 * Si riceve una stringa in input, tale stringa viene
 * salvata in un file, anch'esso definito dall'utente;
 * dopodiche', la stringa viene proposta in output
 * ed eventualmente modificata via lseek.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h>
#include <string.h>

#define MAXFILE	16
#define MAXSTR	256
#define PERMS	0755

int main(int argc, char *argv[], char *envp[])
{
   int fd1, i;
   char f_input[MAXFILE];
   char s_frase[MAXSTR];
   char *s_temp;
   long offset;
   int n_nuova_parola;
   int n = 0;
   char s_nuova_parola[MAXSTR];

   printf("Inserire la frase con cui si deve lavorare: \n");
 
   /* Ricevo in input e salvo il risultato 
    * nell'array di caratteri s_frase */
   fgets(s_frase, MAXSTR, stdin);

   printf("Nome del file su cui salvare in prima battuta: ");
   scanf("%s", f_input);

   if ( (fd1 = open(f_input, O_RDWR | O_CREAT, PERMS)) == -1)
   {
      printf("Errore nell'apertura del file %s\n", f_input);
      exit(1);
   }

   /* Scrivo s_frase in fd1 */
   write(fd1, s_frase, strlen(s_frase));

   /* Si e' conclusa la prima parte del programma, ho il file
    * registrato e la frase, ora non mi resta che verificare la 
    * correttezza della frase ed eventualmente modificarla; per
    * far cio' e' necessario vedere la frase carattere per carattere;
    * il ciclo seguente pertanto presentera' sul terminale l'intera
    * frase compresa del riferimento ad ogni byte, nonche' del
    * numero complessivo dei byte stessi.
    */

   system("clear");
   for (i=0; i< (strlen(s_frase)-1); i++)
      printf("byte %2d %c\n", i, s_frase[i]);
   printf("Tot. byte: %d\n\n", (strlen(s_frase)-1) );

   printf("- Indicare il byte da cui si deve modificare: ");
   scanf("%ld", &offset);
   printf("- Indicare da quanti byte e' composta la nuova parola: ");
   scanf("%d", &n_nuova_parola);
   printf("- Inserire la nuova parola: ");
   scanf("%s", s_nuova_parola);

   /* Alloco lo spazio necessario per contenere la stringa originale,
    * dopodiche' la copio e per finire si aggiunge la modifica */
   s_temp = calloc(strlen(s_frase), sizeof(char));
   strcpy(s_temp, s_frase);

   for (i=offset; i<strlen(s_frase)-1; i++)
   {
      s_temp[i] = s_nuova_parola[n];
      n++;
   }

   /* Si modifica il descrittore di riferimento f1 */
   lseek(fd1, offset, SEEK_SET);

   /* Si scrive partendo dal punto definito dal lseek precedendte */
   write(fd1, s_nuova_parola, n_nuova_parola);
   close(fd1);

   printf("[originale]: %s\n", s_frase);
   printf("[ modifica]: %s\n", s_temp);

   return(EXIT_SUCCESS);
}
