#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_BUF 1024

/* Scrive una stringa accettata in input su un file, con l'orario preciso in cui
 * la stringa stessa e' sata inserita */

int main(int argc, char **argv, char **envp) {
   FILE *f_lavoro;
   char buf[MAX_BUF];
   char *database = "test.txt";

   time_t tempo_e_data;		/* time and date */
   time(&tempo_e_data);		/* get current date */
   char *output_data;		/* pointer to char */

   output_data = ctime(&tempo_e_data);

  f_lavoro = fopen(database, "a");
  fprintf(f_lavoro,"%s", output_data);
  fgets(buf, MAX_BUF, stdin);
  fputs(buf, f_lavoro);
  fprintf(f_lavoro,"\n");

  fclose(f_lavoro);

  return(EXIT_SUCCESS);
}
