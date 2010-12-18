#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {
   time_t tempo_e_data;		/* time and date */
   time(&tempo_e_data);		/* get current date */
   char *output_data;		/* pointer to char */
   size_t lunghezza_stringa;

   output_data = ctime(&tempo_e_data);
   lunghezza_stringa = strlen(output_data);

   printf("%s", output_data);
   printf("%d\n", lunghezza_stringa);

   return(EXIT_SUCCESS);
}
