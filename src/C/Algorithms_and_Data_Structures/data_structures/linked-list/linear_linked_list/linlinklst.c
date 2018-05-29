#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "linlinklst.h"

/* Add a node at the first position of the list */
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

/* Check if the list is empty */
int emptyList(typeList lis) {
    return lis == NULL;
}

/* Write the node data type (integer) on the standard output */
void writeDataType(int data) {
    printf("%d ", data);
}

/* Write node data type through a file (support function) */
void writeDataTypeF(FILE *f, int data) {
    fprintf(f, "%d ", data);
}

/* Write each 'typeList' node on the screen */
void writeNode(typeList lis) {
    if (emptyList(lis))
        printf("\n");
    else {
        writeDataType(lis->data);
        writeNode(lis->next);
    }
}

/* Write each 'typeList' node on a file */
void writeNodeF(char *infile, typeList lis) {
    FILE *datafile;
    datafile = fopen(infile, "w");
    if (datafile == NULL) {
        fprintf(stdout, "Err.: open file. %s\n", strerror(errno));
        lis = NULL;
    } else {
        writeNodeF_r(datafile, lis);
        fclose(datafile);
    }
}

/* Recursive version of writeNodeF() */
void writeNodeF_r(FILE *outfile, typeList lis) {
    if (!emptyList(lis)) {
        writeDataTypeF(outfile, lis->data);
        writeNodeF_r(outfile, lis->next);
    }
}

/*  Find the integer 'val' within the list */
int findinList(typeList lis, int val) {
    if (emptyList(lis))
        return 0;
    else if (lis->data == val)
        return 1;
    else
        return findinList(lis->next, val);
}

 /* Find a node that contains the integer 'val' inside */
void findList(typeList lis, int val, typeList *res) {
    if (emptyList(lis))
        *res = NULL;
    else if (lis->data == val)
        *res = lis;
    else
        findList(lis->next, val, res);
}

/* Compute how many nodes there are in the list */
int lengthList(typeList lis) {
    if (emptyList(lis))
        return 0;
    else
        return 1 + lengthList(lis->next);
}

/* Compute how many occurences of the integer 'val' there are within the list */
int occurenceElemList(typeList lis, int val) {
    if (emptyList(lis))
        return 0;
    else if (lis->data == val)
        return 1 + occurenceElemList(lis->next, val);
    else 
        return 0 + occurenceElemList(lis->next, val);
}

/* Find and replace the first occurence of the integer 'val' with 'new_val' */
void substElemList(typeList lis, int val, int new_val) {
    if (!emptyList(lis)) {
        if (lis->data == val)
            lis->data = new_val;
        else
            substElemList(lis->next, val, new_val);
    }
}

/* Find and replace all the occurences of the integer 'val' with 'new_val' */
void substAllElemList(typeList lis, int val, int new_val) {
    if (!emptyList(lis)) {
        if (lis->data == val)
            lis->data = new_val;
        substAllElemList(lis->next, val, new_val);
    }
}
