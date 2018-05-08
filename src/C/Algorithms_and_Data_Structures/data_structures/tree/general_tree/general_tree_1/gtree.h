#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef   const char   cchr;
typedef   char         DATA;

struct node {
   int           child_no;
   DATA          d;
   struct node   *sib;
};

typedef   struct node   NODE;
typedef   NODE          *GTREE;

/*
// Function prototypes.
*/

GTREE   init_gnode(DATA d, int num, GTREE sibs);
GTREE   new_gnode(void);
void    preorder_g(GTREE *t, int ind);
void    postorder_g(GTREE *t, int ind);
void    wrt_header(cchr *s);
