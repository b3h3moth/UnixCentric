#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "user_group_convertions.h"

int main(void) {
    uid_t uid = getuid();
    char *my_user_name = username_from_userid(uid);
    uid_t my_uid = userid_from_username(my_user_name);
    char *my_group_name = groupname_from_groupid(111);
    gid_t my_gid = groupid_from_groupname(my_group_name);
    
    printf("My user name is: %s\n", my_user_name);
    printf("My user ID is: %d\n", my_uid);
    printf("My group name is: %s\n", my_group_name);
    printf("My group ID is: %d\n", my_gid);

    return(EXIT_SUCCESS);
}
