/*
// List creation using iteration.
*/

#include "list.h"

LINK s_to_l(char s[])
{
   LINK    head = NULL, tail;
   int     i;

   if (s[0] != '\0') {                          /* first element */
      head = malloc(sizeof(ELEMENT));
      head -> d = s[0];
      tail = head;
      for (i = 1; s[i] != '\0'; ++i) {          /* add to tail */
       tail -> next = malloc(sizeof(ELEMENT));
       tail = tail -> next;
       tail -> d = s[i];
      }
      tail -> next = NULL;                      /* end of list */
   }
   return head;
}
