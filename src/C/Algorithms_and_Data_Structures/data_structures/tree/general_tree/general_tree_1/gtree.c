/* Create a new node. */

#include "gtree.h"

GTREE new_gnode(void)
{
   return (malloc(sizeof(NODE)));
}

GTREE init_gnode(DATA d, int num, GTREE sib)
{
   GTREE   tmp;

   tmp = new_gnode();
   tmp -> d = d;
   tmp -> child_no = num;
   tmp -> sib = sib;
   return tmp;
}
