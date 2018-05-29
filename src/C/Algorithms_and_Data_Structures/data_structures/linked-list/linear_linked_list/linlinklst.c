#include <stdio.h>
#include <stdlib.h>
#include "linlinklst.h"

/* Add a node in the first position of the list */
void addNode(typeList *lis, int n) {
    typeList temp = *lis;
    *lis = (typeList)malloc(sizeof(typeNodeList));
    (*lis)->data = n;
    (*lis)->next = temp;
}

/* Remove the first node of the list */
void delNode(typeList *lis) {
    typeList temp = *lis;
    *lis = (*lis)->next;
    free(temp);
}

/* Return true if the list is empty */
int emptyList(typeList lis) {
    return lis == NULL;
}

/* Write node data information on the standard output */
void writeDataType(int data) {
    printf("%d ", data);
}

/* Write node data information through a file */
void writeDataTypeF(FILE *f, int data) {
    fprintf(f, "%d ", data);
}
