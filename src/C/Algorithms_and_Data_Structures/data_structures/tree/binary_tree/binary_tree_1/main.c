#include "tree.h"

int main(void)
{
   BTREE   t;
   DATA    a[]  = "GDIBFHJACE";
   int     size = 10;                                   /* size of a[] */

   t = create_tree(a, 0, size);
   printf("%s",
      "---\n"
      "Inorder binary tree traversal: ");
   inorder(t);
   printf("\n\n%s",
      "---\n"
      "Preorder binary tree traversal: ");
   preorder(t);
   printf("\n\n%s",
      "---\n"
      "Postorder binary tree traversal: ");
   postorder(t);
   printf("\n\n");
   return 0;
}
