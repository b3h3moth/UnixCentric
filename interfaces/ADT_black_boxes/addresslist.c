#include <stdio.h>
#include <stdlib.h>
#include "addresslist.h"

static char name[MAX_ADDR][NAME_LEN];
static char address[MAX_ADDR][ADDR_LEN];
static char mail[MAX_ADDR][MAIL_LEN];

static int find_entry(char const *str) {
    int entry;

    for (entry=0; entry<MAX_ADDR; entry++)
        if (strcmp(str, name[entry]) == 0)
            return entry;

    return(-1);
}

char const *lookup_addr(char const *name) {
    int entry;

    entry = find_entry(name);

    if (entry == -1)
        return NULL;
    else
        return address[entry];
}
