#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "user_group_convertions.h"

int main(void) {
    uid_t uid = getuid();
    char *my_user_name = username_from_userid(uid);
    uid_t my_uid = userid_from_username(my_user_name);
    char *my_group_name = groupname_from_groupid(uid);
    
    printf("My user name is: %s\n", my_user_name);
    printf("My user ID is: %d\n", my_uid);
    printf("My group name is: %s\n", my_group_name);

    return(EXIT_SUCCESS);
}
