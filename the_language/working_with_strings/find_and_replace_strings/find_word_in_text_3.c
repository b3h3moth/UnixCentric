#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_SINGLE_LINE 120

int main () {
  const char fileOrig[32] = "/etc/passwd";
  const char fileRepl[32] = "output.txt";
  const char text2find[80] = "b3h3m0th";
  const char text2repl[80] = "NOBODY USER";

  char buffer[MAX_LEN_SINGLE_LINE + 2];
  char *buff_ptr, *find_ptr;
  FILE *fp1, *fp2;
  size_t find_len = strlen (text2find);

  fp1 = fopen (fileOrig, "r");
  fp2 = fopen (fileRepl, "w");

  while (fgets (buffer, MAX_LEN_SINGLE_LINE + 2, fp1)) {
      buff_ptr = buffer;
      
      while ((find_ptr = strstr (buff_ptr, text2find))) {
      	  while (buff_ptr < find_ptr)
	      fputc ((int) *buff_ptr++, fp2);
	  
	  fputs (text2repl, fp2);
	  buff_ptr += find_len;
      }
      
      fputs (buff_ptr, fp2);
  }

  fclose (fp2);
  fclose (fp1);

  return(EXIT_SUCCESS);
}
