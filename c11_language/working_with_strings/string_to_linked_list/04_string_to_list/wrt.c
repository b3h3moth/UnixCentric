#include "list.h"

void wrt_list(LINK hp)
{
   LINK   p;

   for (p = hp; p != NULL; p = p -> next)
      putchar(p -> d);
}
