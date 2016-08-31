#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
   char *str = "I Love C";

   /* strcmp() returns 0 if the strings are identicals, but it could be
   a problem because when the comparision is part of a conditional statement
   a zero result indicates false. */

   if (strcmp(str, "I Love C"))
       fputs("ops!", stdout);

   // The solution is simple, we have to negate it to get what we want
   if (!strcmp(str, "I Love C"))
       fputs("The strings are indenticals\n", stdout); 

   // or we have to compare strcmp() instruction to zero
   if (strcmp(str, "I Love C") == 0)
       fputs("The strings are equals\n", stdout); 

   return(EXIT_SUCCESS);
}
