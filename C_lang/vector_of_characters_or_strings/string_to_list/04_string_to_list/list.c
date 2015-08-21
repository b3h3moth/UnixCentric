#include "list.h"

/* ---
// Concatenate list a and b with a as head.
*/

void concatenate(LINK a, LINK b)
{
   assert(a != NULL);
   if (a -> next == NULL)
      a -> next = b;
   else
      concatenate(a -> next, b);
}

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
// Recursive deletion of a list.
*/

void delete_list(LINK head)
{
   if (head != NULL) {
      delete_list(head -> next);
      free(head);                  /* release storage */
   }
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
