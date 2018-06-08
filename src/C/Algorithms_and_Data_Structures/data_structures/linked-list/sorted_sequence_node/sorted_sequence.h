#ifndef SORTED_SEQUENCE_H
#define SORTED_SEQUENCE_H

typedef struct sorted_Sequence_Node sorted_Sequence_Node;
typedef struct sorted_Sequence sorted_Sequence;

struct sorted_Sequence_Node {
    int data;
    sorted_Sequence_Node *next;
};

struct sorted_Sequence {
    sorted_Sequence_Node *head;
};

sorted_Sequence *init(void);
void ins_First(sorted_Sequence *s, int val);

#endif
