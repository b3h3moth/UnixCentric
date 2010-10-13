#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_filename(char *url);

int main(int argc, char *argv[])
{
   char str[] = "http://github.com/index.html";
   printf("%s %d\n", str, strlen(str));
   remove_filename(str);
   printf("%s %d\n", str, strlen(str));

   return(EXIT_SUCCESS);
}

/*
 * spezza la stringa url all'ultimo slash,
 * praticamente elimina, in questo caso, index.html
 */
void remove_filename(char *url)
{
   int i = 0;
   int len_str = strlen(url);

   for (i=len_str;  ; i--)
   {
      if (url[i] == 47)
      {
      	 url[i] = '\0';
	 break;
      }
   }
      
}
