#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <ctype.h>
#include <errno.h>
#include "user_group_convertions.h"

// Converte user ID in user name
char *user_name_from_id(uid_t uid) {
    struct passwd *pwd;

    pwd = getpwuid(uid);
    if (pwd == NULL) {
        if (errno == 0) {
            fprintf(stderr, "Account Not Found.\n");
            return NULL;
        } else {
            fprintf(stderr, "Err. getpwuid() Failed.\n");
            return NULL;
        }
    } else
        return pwd->pw_name;
}
