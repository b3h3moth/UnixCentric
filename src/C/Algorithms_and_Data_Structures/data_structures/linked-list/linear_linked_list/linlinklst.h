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
#endif
