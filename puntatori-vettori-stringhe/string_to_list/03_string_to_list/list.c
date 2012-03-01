#include "list.h"

/* ---
// Count a list recursively.
*/

int count(LINK head)
{
   if (head == NULL)
      return 0;
   else
      return (1 + count(head -> next));
}

/* ---
// Count a list iteratively.
*/

int count_it(LINK head)
{
   int   cnt = 0;

   for ( ; head != NULL; head = head -> next)
      ++cnt;
   return cnt;
}

/* ---
// Print a list recursively.
*/

void print_list(LINK head)
{
   if (head == NULL)
      printf("NULL");
   else {
      printf("%c --> ", head -> d);
      print_list(head -> next);
   }
}
