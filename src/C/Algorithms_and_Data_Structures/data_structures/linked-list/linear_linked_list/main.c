#include <stdio.h>
#include <stdlib.h>
#include "linlinklst.h"

int main(void) {
    char *myfile = "lll.txt";
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
    addNode(&llst, 100);
    addNode(&llst, 1000);
    addNode(&llst, 10000);
    writeNodeF(myfile, llst);
    /* $ cat lll.txt */


    return(EXIT_SUCCESS);
}
