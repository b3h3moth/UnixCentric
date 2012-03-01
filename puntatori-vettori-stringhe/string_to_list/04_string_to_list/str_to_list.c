/*
// List creation using recursion,
// but replace each newline with
// a blank space.
*/

#include "list.h"

LINK string_to_list(char s[])
{
   DATA   d;
   LINK   head;

   if (s[0] == '\0')     /* base case */
      return NULL;
   else {
      head = malloc(sizeof(ELEMENT));
      d = (s[0] == '\n') ? ' ' : s[0];
      head -> d = d;
      head -> next = string_to_list(s + 1);
      return head;
   }
}
