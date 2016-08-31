#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>

char *string_replace(char *original, char *pattern, char *replacement);

int main(int argc, char *argv[]) {
    
    printf("%s\n", string_replace("Hello ciao", "ciao", "world"));

    return(EXIT_SUCCESS);
}

char *string_replace(char *original, char *pattern, char *replacement)
{
  static char buffer[4096];
  char *p_tmp;

  /* Se non vi sono corrispondenze sara' ritornata la stringa originale */
  if(!(p_tmp = strstr(original, pattern)))  
    return original;

  strncpy(buffer, original, p_tmp-original); 
  buffer[p_tmp-original] = '\0';

  sprintf(buffer+(p_tmp-original), "%s%s", replacement, p_tmp+strlen(pattern));

  return buffer;
}
