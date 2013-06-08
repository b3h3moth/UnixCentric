#include "list.h"

int main(void)
{
   char   line[MAXLINE];
   LINK   hp;                /* hp = head pointer */
   LINK   p;

   printf("%s",
      "---\n"
      "Type in a line of text: ");
   assert(fgets(line, MAXLINE, stdin) != NULL);
   hp = string_to_list(line);
   printf("%s%s%s",
      "\n"
      "Here is the line you type in:\n"
      "\n"
      "   ", line,
      "\n"
      "and here is what we get running down the linked list:\n"
      "\n"
      "   ");
   for (p = hp; p != NULL; p = p -> next)
      putchar(p -> d);
   printf("\n");
   return 0;
}
