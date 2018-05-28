#include <stdio.h>
#include <stdlib.h>
#include "linlinklst.h"

int main(void) {
    typeList llst = NULL;
    addNode(&llst, 3);
    addNode(&llst, 2);
    addNode(&llst, 1);

    return(EXIT_SUCCESS);
}
