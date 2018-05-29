#ifndef LINLINKLST_H
#define LINLINKLST_H

struct elemList {
    int data;
    struct elemList *next;
};

typedef struct elemList typeNodeList;
typedef typeNodeList *typeList;


/* 
 * Basic operations:
 * ================= 
 * Operations that involve a single node, the first.
 */

/* Add a node in the first position of the list */
void addNode(typeList *lis, int n);

/* Remove the first of the list */
void delNode(typeList *lis);


/*
 * Recursive visits
 * ================
 * 1. Operations that don't modify the list.
 */

/* Check if the list is empty */
int emptyList(typeList lis);

/* Write node data type on the standard output (supporrt function) */
void writeDataType(int data);

/* Write node data type through a file (supporrt function) */
void writeDataTypeF(FILE *f, int data);

/* Write typeList each node on the screen */
void writeNode(typeList lis);

/* Write each typeList node on a file */
void writeNodeF(char *infile, typeList lis);

/* Recursive version of writeNodeF() */
void writeNodeF_r(FILE *outfile, typeList lis);

/* Find the integer val within the list. It returns: 
   1 (true) if exist;
   0 if the list is empty.
*/
int findinList(typeList lis, int val);

/* Find a node that contains the integer val inside. It returns:
   a pointer to the node (true);
   NULL otherwise.
*/
void findList(typeList lis, int val, typeList *res);

/* Count the length of the list */
int lengthList(typeList lis);

/* Count how many occurences of the integer val there are within the list  */
int occurenceElemList(typeList lis, int val);

/* Functions that change the contents of the Linear Structure List */
#endif
