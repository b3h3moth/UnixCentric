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


/* Sorted Sequence Node (alias SSN)
- A pointer to sorted_Sequence_Node 'head' is a pointer to the generator node:
- The generator node is the ever first SSN but it is not part of it, it only
  serves to manage the SSN. */

/* SSN initialization. It contains only the generator node. */
sorted_Sequence *init(void);

/* Add a node in the first position of the SSN */
void ins_First(sorted_Sequence *s, int val);

/* Add a node in the sorted sequence */
void ins_Sort(sorted_Sequence *s, int val);
#endif
