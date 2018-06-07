#ifndef SORTED_SEQUENCE_H
#define SORTED_SEQUENCE_H

struct sorted_Sequence {
    struct sorted_Sequence_Node *head;
};

struct sorted_Sequence_Node {
    int data;
    struct sorted_Sequence_Node *next;
};

#endif
