#include <stdio.h>
#include <stdlib.h>
#include "addresslist.h"

char name[MAX_ADDR][NAME_LEN] = {
    "luca",
    "maria",
    "giovanna",
    "carla",
    "francesca"
};
char address[MAX_ADDR][ADDR_LEN] = {
    "luca's address",
    "maria's address",
    "giovanna's address",
    "carla's address",
    "francesca's address"
};

char mail[MAX_ADDR][MAIL_LEN] = {
    "luca@mail.org",
    "maria#mail.org",
    "giovanna@mail.org",
    "carla@mail.org",
    "francesa@mail.org"
};

int main(void) {
    char const *res1 = lookup_addr("giovanna");
    char const *res2 = lookup_addr("giovanni");

    if (res1 != NULL) {
        printf("%s\n", res1);
        printf("%s\n", lookup_mail("giovanna"));
    } else
        puts("Not found");

    if (res2 == NULL)
        puts("Not found");

    return(EXIT_SUCCESS);
}
