/* Test the two-stack Polish evaluation algorithm. */

#include "polish.h"

int main(void)
{
   char    str[] = "13, 4, -, 2, 3, *, +";
   stack   polish;
  
   printf("\n%s%s\n\n",
      "Polish expression: ", str);
   fill(&polish, str);              /* fill stack from the string */
   wrt_stack(&polish);              /* wrt the stack on the screen */
   printf("\n%s%d\n\n",
      "Polish evaluation: ", evaluate(&polish));
   return 0;
}
