#ifndef LINLINKLST_H
#define LINLINKLST_H

struct elemList {
    int data;
    struct elemList *next;
};

typedef struct elemList typeNodeList;
typedef typeNodeList *typeList;


/* 
 * Basic Operations:
 * ================= 
 * Operations that involve a single node, the first.
 */

/* Add a node at the first position of the list */
void addNode(typeList *lis, int n);

/* Remove the first node of the list */
void delNode(typeList *lis);

/*
 * Recursive Visits
 * ================
 * Part I - Operations that don't modify the list.
 */

/* Check if the list is empty */
int emptyList(typeList lis);

/* Write the node data type (integer) on the standard output */
void writeDataType(int data);

/* Write the node data type through a file */
void writeDataTypeF(FILE *f, int data);

/* Write 'typeList' each node on the screen */
void writeNode(typeList lis);

/* Write each 'typeList' node on a file */
void writeNodeF(char *infile, typeList lis);

/* Recursive version of writeNodeF() */
void writeNodeF_r(FILE *outfile, typeList lis);

/* Find the integer 'val' within the list. It returns: 
   1 (true) if it exists;
   0 if doesn't exists or it is empty.
*/
int findinList(typeList lis, int val);

/* Find a node that contains the integer val inside. It returns:
   a pointer to the node (true);
   NULL otherwise.
*/
void findList(typeList lis, int val, typeList *res);

/* Compute how many nodes there are in list */
int lengthList(typeList lis);

/* Compute how many occurences of the integer 'val' there are within the list */
int occurenceElemList(typeList lis, int val);

/*
 * Recursive Visits
 * ================
 * Part II - Functions that change the contents of the Linear Structure List
 *           (They modify the integer field 'data')
 */

/* Find and replace the first occurence of the integer 'val' with 'new_val' */
void substElemList(typeList lis, int val, int new_val);

/* Find and replace all the occurences of the integer 'val' with 'new_val' */
void substAllElemList(typeList lis, int val, int new_val);

#endif
