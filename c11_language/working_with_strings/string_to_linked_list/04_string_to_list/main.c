#include "list.h"

int main(void)
{
   char   line[MAXLINE];
   LINK   hp = NULL;                /* hp = head pointer */
   LINK   p;

   printf("%s\n",
      "---\n"
      "This program will do the following repeatedly and\n"
      "then delete the linked list before exiting:\n"
      "\n"
      "   1  create a linked list from a line of text\n"
      "   2  concatinate the list to what we already have\n"
      "   3  print the data in the linked list\n");
   for ( ; ; ) {
      printf("\n%s",
         "---\n"
         "Type in a line of text: ");
      assert(fgets(line, MAXLINE, stdin) != NULL);
      if (*line == '\n')
         break;
      p = string_to_list(line);
      if (hp == NULL)
         hp = p;
      else
         concatenate(hp, p);
      putchar('\n');
      wrt_list(hp);
      putchar('\n');
   }
   delete_list(hp);
   printf("\nBye!\n\n");
   return 0;
}
