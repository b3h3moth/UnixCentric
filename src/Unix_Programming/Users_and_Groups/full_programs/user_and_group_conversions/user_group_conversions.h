#ifndef USER_GROUP_CONVERSIONS
#define USER_GROUP_CONVERSIONS

#include <sys/types.h>

char *username_from_userid(uid_t uid);
uid_t userid_from_username(const char *username);
char *groupname_from_groupid(gid_t gid);
gid_t groupid_from_groupname(const char *groupname);

#endif
