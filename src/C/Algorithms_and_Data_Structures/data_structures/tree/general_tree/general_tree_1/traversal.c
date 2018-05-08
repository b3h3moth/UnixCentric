#include "gtree.h"

/*
// Preorder traversal of general trees.
*/

void preorder_g(GTREE *t, int ind)
{
   GTREE   tmp;                      /* tmp traverses the sibling list */

   tmp = t[ind];                            /* t[ind] is the root node */
   while (tmp != NULL) {
      printf("%5c%5d\n", tmp -> d, tmp -> child_no);
      preorder_g(t, tmp -> child_no);
      tmp = tmp -> sib;
   }
}

/*
// Postorder traversal of general trees.
*/

void postorder_g(GTREE *t, int ind)
{
   GTREE   tmp;                      /* tmp traverses the sibling list */

   tmp = t[ind];                            /* t[ind] is the root node */
   while (tmp != NULL) {
      postorder_g(t, tmp -> child_no);
      printf("%5c%5d\n", tmp -> d, tmp -> child_no);
      tmp = tmp -> sib;
   }
}
