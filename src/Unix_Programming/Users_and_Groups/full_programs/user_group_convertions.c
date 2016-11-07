#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <ctype.h>
#include <errno.h>
#include "user_group_convertions.h"

// Converte user ID in user name
char *username_from_userid(uid_t uid) {
    struct passwd *pwd;

    pwd = getpwuid(uid);
    if (pwd == NULL) {
        if (errno == 0) {
            fprintf(stderr, "Account Not Found.\n");
            return -1;
        } else {
            fprintf(stderr, "Err. getpwuid() Failed.\n");
            return -1;
        }
    } else
        return pwd->pw_name;
}

// Converte user name in user ID
uid_t userid_from_username(const char *username) {
    struct passwd *pwd;
    uid_t uid;

    if (username == NULL || username == '\0')
        return -1;

    pwd = getpwnam(username);
    if (pwd == NULL) {
        if (errno == 0) {
            fprintf(stderr, "Account Not Found.\n");
            return -1;
        } else {
            fprintf(stderr, "Err. getpwnam() Failed.\n");
            return -1;
        }
    } else
        return pwd->pw_uid;
}
