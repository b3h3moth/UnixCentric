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

struct pair {                   /* a pair represents an edge in a tree */
   int   out;
   int   in;
};

typedef   struct pair   PAIR;
typedef   struct node   NODE;
typedef   NODE *        GTREE;

/*
// Function prototypes.
*/

void    buildtree(PAIR edges[], DATA d[], int n, GTREE t[]);
GTREE   init_gnode(DATA d, int num, GTREE sibs);
GTREE   new_gnode(void);
void    preorder_g(GTREE *t, int ind);
void    postorder_g(GTREE *t, int ind);
void    wrt_header(cchr *s);
