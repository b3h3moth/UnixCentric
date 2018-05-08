#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef   char   DATA;

struct node {
   DATA          d;
   struct node   *left;
   struct node   *right;
};

typedef   struct node   NODE;
typedef   NODE          *BTREE;

/*
// Function prototypes.
*/

BTREE   create_tree(DATA a[], int i, int size);
BTREE   init_node(DATA d1, BTREE p1, BTREE p2);
BTREE   new_node(void);

void    inorder(BTREE root);
void    preorder(BTREE root);
void    postorder(BTREE root);
