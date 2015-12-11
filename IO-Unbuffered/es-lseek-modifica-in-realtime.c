
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h>
#include <string.h>

#define MAXFILE	16
#define MAXSTR	256
#define PERMS	0755

/* Il programma riceve una stringa in input, tale stringa viene salvata in un 
file anch'esso definito dall'utente, dopodiche' la stringa viene proposta in 
output ed eventualmente modificata mediante lseek() inserendo la posizione del
byte dal quale modificare e la grandezza della nuova stringa da inserire.  */

int main(int argc, char *argv[]) {
    int fd1, i;
    char str_input[MAXFILE];
    char str_default[MAXSTR];
    char *str_temp;
    long offset;
    int len_newstr;
    int n = 0;
    char str_new[MAXSTR];
    
    printf("Please, write a default string: \n");
    
    /* Si acsuisisce in input la stringa 'str_default' con cui lavorare */
    fgets(str_default, MAXSTR, stdin);
    
    /* Il nome del file all'interno del quale salvare la stringa iniziale */
    printf("Please, the filename to store string: ");
    scanf("%s", str_input);
    
    /* Si salva il file pocanzi inserito in input */
    if ( (fd1 = open(str_input, O_RDWR | O_CREAT, PERMS)) == -1) {
        fprintf(stderr, "Err. when opening file %s\n", str_input);
        exit(EXIT_FAILURE);
    }
    
    /* Scrittura della stringa 'str_default' nel file */
    write(fd1, str_default, strlen(str_default));

   /* Si e' conclusa la prima parte del programma, ho il file
    * registrato e la frase, ora non mi resta che verificare la 
    * correttezza della frase ed eventualmente modificarla; per
    * far cio' e' necessario vedere la frase carattere per carattere;
    * il ciclo seguente pertanto presentera' sul terminale l'intera
    * frase compresa del riferimento ad ogni byte, nonche' del
    * numero complessivo dei byte stessi.
    */

   system("tput reset");
   for (i=0; i< (strlen(str_default)-1); i++)
      printf("byte %2d %c\n", i, str_default[i]);
   printf("Tot. byte: %d\n\n", (strlen(str_default)-1) );

   printf("- Indicare il byte da cui si deve modificare: ");
   scanf("%ld", &offset);
   printf("- Indicare da quanti byte e' composta la nuova parola: ");
   scanf("%d", &len_newstr);
   printf("- Inserire la nuova parola: ");
   scanf("%s", str_new);

   /* Alloco lo spazio necessario per contenere la stringa originale,
    * dopodiche' la copio e per finire si aggiunge la modifica */
   str_temp = calloc(strlen(str_default), sizeof(char));
   strcpy(str_temp, str_default);

   for (i=offset; i<strlen(str_default)-1; i++)
   {
      str_temp[i] = str_new[n];
      n++;
   }

   /* Si modifica il descrittore di riferimento f1 */
   lseek(fd1, offset, SEEK_SET);

   /* Si scrive partendo dal punto definito dal lseek precedendte */
   write(fd1, str_new, len_newstr);
   close(fd1);

   printf("[originale]: %s\n", str_default);
   printf("[ modifica]: %s\n", str_temp);

   return(EXIT_SUCCESS);
}
