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

void   concatenate(LINK a, LINK b);
int    count(LINK head);
int    count_it(LINK head);
void   delete_list(LINK head);
void   print_list(LINK head);
LINK   string_to_list(char s[]);
void   wrt_list(LINK hp);
