#ifndef USER_GROUP_CONVERTIONS
#define USER_GROUP_CONVERTIONS

#include <sys/types.h>

char *username_from_userid(uid_t uid);
uid_t userid_from_username(const char *username);
char *groupname_from_groupid(gid_t gid);

#endif
