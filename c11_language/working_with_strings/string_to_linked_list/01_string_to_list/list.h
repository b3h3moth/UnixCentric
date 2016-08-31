#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define   MAXLINE   100

typedef   char   DATA;           /* will use char in examples */

struct linked_list {
   DATA                 d;
   struct linked_list   *next;
};

typedef   struct linked_list   ELEMENT;
typedef   ELEMENT *            LINK;

LINK   string_to_list(char s[]);
