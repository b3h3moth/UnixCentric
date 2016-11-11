#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <grp.h>

/* Lo scopo del programma e' di scrivere nel file 'file_grp' i campi di 
ciascun gruppo. */

int main(int argc, char *argv[]) {
   struct group *grp;
   char **tmp_memb;
   FILE *fp;
   char file_grp[] = "group_db.txt";

   if ((fp = fopen(file_grp, "w+")) == NULL) {
      fprintf(stderr, "Err.(%s): %s\n", strerror(errno), file_grp);
      exit(EXIT_FAILURE);
   }

   while ((grp = getgrent()) != NULL) {
      fprintf(fp, "%30s | ", grp->gr_name);
      fprintf(fp, "%s | ", grp->gr_passwd);
      fprintf(fp, "%5d | ", grp->gr_gid);
      
      tmp_memb = grp->gr_mem;

      while (*tmp_memb != NULL) {
      	 fprintf(fp, "%s, ", *tmp_memb);
         tmp_memb++;
      }
      fprintf(fp, "\n");
   }

   printf("User Group file \'%s\' written.\n", file_grp);

   endgrent();
   fclose(fp);
   free(*tmp_memb);

   return(EXIT_SUCCESS);
}
