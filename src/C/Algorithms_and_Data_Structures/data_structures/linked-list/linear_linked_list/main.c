#include <stdio.h>
#include <stdlib.h>
#include "linklinstruct.h"

int main(void) {
    char *myfile = "l.txt", *myfile2 = "lll.txt";
    int i, n = 5;
    typeList llst = NULL;

    addNode(&llst, 3);
    addNode(&llst, 2);
    addNode(&llst, 1);
    writeNode(llst);
    delNode(&llst);
    delNode(&llst);
    if (emptyList(llst))
        fprintf(stdout, "A. The list is empty\n");
    else
        fprintf(stdout, "A. The list is not empty\n");
    delNode(&llst);
    if (emptyList(llst))
        fprintf(stdout, "B. The list is empty\n");
    addNode(&llst, 10);
    addNode(&llst, 1);
    addNode(&llst, 9);
    addNode(&llst, 7);
    writeNodeF(myfile, llst);
    /* $ cat lll.txt */
    printf("Count elements of list:\n");
    for (i=0; i<=10; i++) 
        printf("find %.2d: %d\n", i, findinList(llst, i));
    typeList res;
    findList(llst, 9, &res);
    writeNode(res);
    printf("%d\n", res->data);
    printf("List A: %d\nList B: %d\n", lengthList(llst), lengthList(res));
    printf("Count occurence of the integers within the list:\n");
    for (i=0; i<=10; i++) 
        printf("find %.2d: %d\n", i, occurenceElemList(llst, i));
    writeNode(llst);
    printf("find and replace the first occurence of %d\n", 4);
    substElemList(llst, 10, 4);
    writeNode(llst);
    writeNodeF(myfile, llst);
    addNode(&llst, 9);
    addNode(&llst, 9);
    addNode(&llst, 9);
    writeNode(llst);
    printf("find and replace all the occurences of %d with %d\n", 9, 3);
    substAllElemList(llst, 9, 3);
    writeNode(llst);
    printf("build a new Linear Structure with n nodes\n");
    typeList ls = NULL;
    buildLS(&ls, 3, 7);
    writeNode(ls);
    /*
    Function to testing stdin, stdout, FILE 
    readNode(&ls);
    readAdd(&llst);
    writeNode(llst);
    writeNode(ls);
    printf("List llst: %d\nList ls: %d\n", lengthList(llst), lengthList(ls));
    readNodeF(myfile2, &n, &ls);
    writeNode(ls);
    */
    printf("Copy LLS from source to destination\n");
    typeList lls_cpy = NULL;
    copyList(ls, &lls_cpy);
    printf("lls_cpy has : %d elements\n",lengthList(lls_cpy));
    writeNode(lls_cpy);
    printf("Delete LLS\n");
    deleteLLS(&ls);
    return(EXIT_SUCCESS);
}
