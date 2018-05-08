#include "gtree.h"

int main(void)
{
   char    c;
   int     i;
   DATA    *d;
   GTREE   *t;
   PAIR    *edges;

   int     n  = 8;                                  /* number of nodes */


   /*
   // We need n data items that correspond to the n nodes.
   // But because we want to count from 1, not 0, we need
   // space for n + 1 data items.
   */
   d = (DATA *) calloc(n + 1, sizeof(DATA));
   assert(d != NULL);
   /*
   // Next, we make the following assignments:
   //
   //    d[1] = 'a'; d[2] = 'b'; ..., d[8] = 'h';
   */
   for (i = 1, c = 'a'; i <= n; ++i, ++c)
      d[i] = c;
   /*
   // Create space for an array of n + 1 gtrees.
   */
   t = (GTREE *) calloc(n + 1, sizeof(GTREE));
   assert(t != NULL);
   /*
   // We need n - 1 edges that connect the n nodes.  But
   // because we want to count from 1, not 0, we need
   // space for n edges.
   */
   edges = (PAIR *) calloc(n, sizeof(PAIR));
   assert(edges != NULL);
   /*
   // We need n - 1 edges that connect the n nodes.
   // See the picture on page 480 of "A Book on C," 4/e.
   */
   edges[0].out = 1;
   edges[0].in = 2;
   edges[1].out = 2;
   edges[1].in = 3;
   edges[2].out = 2;
   edges[2].in = 4;
   edges[3].out = 2;
   edges[3].in = 5;
   edges[4].out = 1;
   edges[4].in = 6;
   edges[5].out = 6;
   edges[5].in = 7;
   edges[6].out = 1;
   edges[6].in = 8;
   /*
   // Use buildtree() to build the tree.
   */
   buildtree(edges, d, n, t);
   /*
   // Traverse the tree and write on the screen.
   */
   wrt_header("Preorder");
   preorder_g(t, 0);
   wrt_header("Postorder");
   postorder_g(t, 0);
   printf("\n%s\n",
      "---\n"
      "WHOOPS: More work is needed!\n");
   return 0;
}
