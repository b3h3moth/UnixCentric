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
 * "Those operations that involve a single node, the first" 
 */

/* Add a node in the first position of the list */
void addNode(typeList *lis, int n);
#endif
