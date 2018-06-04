#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "linklinstruct.h"

/* Add a node at the first position of the LLS */
void addNode(typeList *lis, int n) {
    typeList temp = *lis;
    *lis = (typeList)malloc(sizeof(typeNodeList));
    (*lis)->data = n;
    (*lis)->next = temp;
}

/* Remove the first node of the LLS */
void delNode(typeList *lis) {
    typeList temp = *lis;
    *lis = (*lis)->next;
    free(temp);
}

/* Check if the LLS is empty */
int emptyList(typeList lis) {
    return lis == NULL;
}

/* Write the node data type (integer) on the standard output */
void writeDataType(int data) {
    printf("%d ", data);
}

/* Write node data type (integer) through a file */
void writeDataTypeF(FILE *f, int data) {
    fprintf(f, "%d ", data);
}

/* Read the node data type (integer) from standard input */
int readDataType(int *data) {
    return scanf("%d ", data);
}

/* Read the node data type (integer) through a file */
int readDataTypeF(FILE *f, int *data) {
    return fscanf(f, "%d ", data);
}

/* Write the LLS on the screen */
void writeNode(typeList lis) {
    if (emptyList(lis))
        printf("\n");
    else {
        writeDataType(lis->data);
        writeNode(lis->next);
    }
}

/* Write the LLS on a file */
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

/* Read LLS from each node */
void readNode(typeList *lis) {
    int temp;
    if (readDataType(&temp) == EOF)
        *lis = NULL;
    else {
        *lis = (typeList)malloc(sizeof(typeNodeList));
        (*lis)->data = temp;
        readNode(&((*lis)->next));
    }
}

/*  Find the integer 'val' within the LLS */
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

/* Compute how many nodes there are in the LLS */
int lengthList(typeList lis) {
    if (emptyList(lis))
        return 0;
    else
        return 1 + lengthList(lis->next);
}

/* Compute how many occurences of the integer 'val' there are within the LLS */
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

/* Build a new LLS of 'n' nodes */
void buildLS(typeList *lis, int n, int val) {
    if (n == 0)
        *lis = NULL;
    else {
        *lis = (typeList)malloc(sizeof(typeNodeList));
        (*lis)->data = val;
        buildLS(&((*lis)->next), n-1, val);
    }
}

/* Read and add all the elements (integers) */
void readAdd(typeList *lis) {
    int temp;
    if (readDataType(&temp) == EOF)
        *lis = NULL;
    else {
        readAdd(lis);
        addNode(lis, temp);
    }
}

/* Recursive version of readNodeF() */
void readNodeF_r(FILE *infile, int *val, typeList *lis) {
    int temp;
    if (readDataTypeF(infile, &temp) == EOF)
        *lis = NULL;
    else {
        (*val)++;     /* Initialized to 0 within readNodeF() */
        *lis = (typeList)malloc(sizeof(typeNodeList));
        (*lis)->data = temp;
        readNodeF_r(infile, val, &(*lis)->next);
    }
}

 /* Read node by node from a file */
void readNodeF(char *nfile, int *val, typeList *lis) {
    FILE *dfile;
    dfile = fopen(nfile, "r");
    *val = 0;
    if (dfile == NULL) {
        fprintf(stdout, "Err. read file %s\n", strerror(errno));
        lis = NULL;
    } else {
        readNodeF_r(dfile, val, lis);
        fclose(dfile);
    }
}

/* Copy LLS from source 'lis_src' to destination 'lis_dst */
void copyList(typeList lis_src, typeList *lis_dst) {
    if (emptyList(lis_src))
        *lis_dst = NULL;
    else {
       *lis_dst = (typeList)malloc(sizeof(typeNodeList));
      (*lis_dst)->data = lis_src->data;
      copyList(lis_src->next, &(*lis_dst)->next);
    }
}

/* Delete LLS. It frees all the memory */
void deleteLLS(typeList *lis) {
    if (*lis != NULL) {
        typeList temp = *lis;
        deleteLLS(&(*lis)->next);
        free(temp);
    }
}

/* Find the position 'pos' and return the pointer to that node position */
void findPosLLS(typeList lis, int pos, typeList *res) {
    if (pos == 0)
        *res = lis;
    else
        findPosLLS(lis->next, pos-1, res);
}

/* Find the position 'pos' and add a node to that position */
void addPosLLS(typeList *lis, int pos, int val) {
    if (pos == 0) {   /* new node in the first position of the LLS */
        typeList temp = *lis;
        *lis = (typeList)malloc(sizeof(typeNodeList));
        (*lis)->data = val;
        (*lis)->next = temp;
    } else
        addPosLLS(&(*lis)->next, pos-1, val);
}

/* Find the position 'pos' and remove the node to that position */
void delPosLLS(typeList *lis, int pos) {
    if (lis == NULL)
        return;
    else if (pos == 0) {
        typeList temp = *lis;
        *lis = (*lis)->next;
        free(temp);         /* Now the node is actually removed */
    } else
        delPosLLS(&(*lis)->next, pos-1);
}

/* Write the LLS on the screen (iterative) */
void writeLLS(typeList lis) {
    while (!emptyList(lis)) {
        printf("%d ", lis->data);
        lis = lis->next;
    }
}

/* Find the integer 'val' within the LLS (iterative) */
int find_in_LLS(typeList lis, int val) {
    int found = 0;
    while(!emptyList(lis) && !found) {
        if (lis->data == val)
            return 1;
        else
            lis = lis->next;
    }
    return found;
}
