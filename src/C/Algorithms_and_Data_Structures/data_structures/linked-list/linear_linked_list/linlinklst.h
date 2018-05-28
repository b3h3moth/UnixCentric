#ifndef LINLINKLST_H
#define LINLINKLST_H

struct elemList {
    int data;
    struct elemList *next;
};

typedef struct elemList nodeList;
typedef nodeList *pList;

#endif
