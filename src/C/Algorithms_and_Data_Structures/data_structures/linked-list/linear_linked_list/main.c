#include <stdio.h>
#include <stdlib.h>
#include "linklinstruct.h"

int main(void) {
    char *myfile = "test.txt", *myfile2 = "test2.txt";
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
    printf("Find an element within the LLS:\n");
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
    printf("build a new Linked Linear Structure with n nodes\n");
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
    printf("LLS has : %d elements\n",lengthList(lls_cpy));
    writeNode(lls_cpy);
    printf("Delete LLS\n");
    deleteLLS(&ls);
    printf("Return a pointer to the node in n position\n");
    typeList newlls = NULL;
    typeList reslls = NULL;
    for (i=0; i<10; i++)
        addNode(&newlls, i);
    writeNode(newlls);
    findPosLLS(newlls, 3, &reslls);
    writeNode(reslls);
    printf("LLS points to node with int: %d\n", reslls->data);
    printf("Add a node in the position 'n'\n");
    addPosLLS(&newlls, 6, 100);
    writeNode(newlls);
    printf("Remove the node in the position 'n'\n");
    delPosLLS(&newlls, 6);
    writeNode(newlls);
    printf("Print each element of the list (iterative form)\n");
    writeLLS(newlls);
    printf("\nFind element (iterative form)\n");
    for (i=0; i<=10; i++)
        printf("find %.2d: %d\n", i, find_in_LLS(newlls, i));
    printf("LLS has: %d elements (iterative form)\n", length_LLS(newlls));

    return(EXIT_SUCCESS);
}
