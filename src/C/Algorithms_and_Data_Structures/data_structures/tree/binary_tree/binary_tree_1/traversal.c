#include "tree.h"

/*
// Inorder binary tree traversal.
*/

void inorder(BTREE root)
{
   if (root != NULL) {
      inorder(root -> left);                             /* recur left */
      printf("%c ", root -> d);
      inorder(root -> right);                           /* recur right */
   }
}

/*
// Preorder binary tree traversal.
*/

void preorder(BTREE root)
{
   if (root != NULL) {
      printf("%c ", root -> d);
      preorder(root -> left);
      preorder(root -> right);
   }
}

/*
// Postorder binary tree traversal.
*/

void postorder(BTREE root)
{
   if (root != NULL) {
      postorder(root -> left);
      postorder(root -> right);
      printf("%c ", root -> d);
   }
}
