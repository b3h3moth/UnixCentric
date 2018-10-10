#include "list.h"

int main(void)
{
   LINK   hp;         /* hp = head pointer */

   hp = string_to_list("ABC");
   printf("The resulting list is\n");
   print_list(hp);
   printf("\nThis list has %d elements.\n", count(hp));
   return 0;
}
