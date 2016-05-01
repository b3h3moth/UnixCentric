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

    return(EXIT_FAILURE);
}
