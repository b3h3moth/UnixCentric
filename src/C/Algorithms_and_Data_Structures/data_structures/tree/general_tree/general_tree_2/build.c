/*
// Function buildtree creates a tree from an array of edges.
*/

#include "gtree.h"

void buildtree(PAIR edges[], DATA d[], int n, GTREE t[])
{
   int   i;
   int   x, y;                                       /* points of edge */

   t[0] = init_gnode(d[1], 1, NULL);      /* t[0] takes node 1 as root */
   for (i = 1; i <= n; ++i)
      t[i] = NULL;
   for (i = 0; i < n - 1; ++i) {
      x = edges[i].out;
      y = edges[i].in;
      t[x] = init_gnode(d[y], y, t[x]);
   }
}
