#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "user_group_convertions.h"

int main(void) {
    uid_t uid = getuid();
    char *my_uid = username_from_userid(uid);
    printf("My username is: %s\n", my_uid);

    return(EXIT_SUCCESS);
}
