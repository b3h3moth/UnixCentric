/*
// List creation using recursion.
*/

#include "list.h"

LINK string_to_list(char s[])
{
   LINK   head;

   if (s[0] == '\0')     /* base case */
      return NULL;
   else {
      head = malloc(sizeof(ELEMENT));
      head -> d = s[0];
      head -> next = string_to_list(s + 1);
      return head;
   }
}
