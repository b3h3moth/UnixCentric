#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAXBUF		256
#define AUTHOR		"Luca Suriano"
#define MAIL_AUTHOR	"luka@linux.it"

int main(int argc, char *argv[])
{
   char *cp;
   char buf[MAXBUF];
   FILE *p = popen(cp="ps f","r");

   if (!p) {
      fprintf(stderr, "%s: Opening pipe(%s) for read\n", strerror(errno), cp);
      return 13;
   }

   /* read the output of tyhe pipe */
   while ( fgets(buf, sizeof buf, p) != 0) 
      fputs(buf, stdout);
   pause(10);

   if (pclose(p)) {
      fprintf(stderr, "%s: pclose()\n", strerror(errno));
      return 13;
   }


   return(EXIT_SUCCESS);
}
