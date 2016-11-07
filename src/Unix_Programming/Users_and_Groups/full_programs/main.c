#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "user_group_convertions.h"

int main(void) {
    uid_t uid = getuid();
    char *my_uid = user_name_from_id(uid);
    printf("My username is: %s\n", my_uid);

    return(EXIT_SUCCESS);
}
