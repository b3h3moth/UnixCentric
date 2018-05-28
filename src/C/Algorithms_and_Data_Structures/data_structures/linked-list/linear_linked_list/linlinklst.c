#include "linlinklst.h"

/* Add a node in the first position of the list */
void addNode(typeList *lis, int n) {
    typeList temp = *lis;
    *lis = (typeList*)malloc(sizeof(typeNodeList));
    (*lis)->data = n;
    (*lis)->next = temp;
}    
