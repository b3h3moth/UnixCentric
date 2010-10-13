#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
   
   uid_t user_uid;
   gid_t user_gid;
   char *user_login;

   user_uid = getuid();
   user_gid = getgid();
   user_login = getlogin();

   printf("------------------------------\n");
   printf(" INFORMAZIONI SU USER/UID/GID\n");
   printf("------------------------------\n");
   printf("    User: %s\n", user_login);
   printf("User uid: %d\n", user_uid);
   printf("User gid: %d\n", user_gid);

   return(EXIT_SUCCESS);
}
