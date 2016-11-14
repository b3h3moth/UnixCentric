#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <assert.h>

/* Lo scopo del programma e' di stampare le credenziali di un processo, nello
specifico, oltre al PID e PPID, i 'Real' e 'Effective' ID. */

int main(void) {
    uid_t uid;
    gid_t gid;
    struct passwd *pwd;
    struct group *grp;
    
    printf("Process-ID (PID): %ld\n", (long)getpid());
    printf("Parent Process-ID (PPID): %ld \n", (long)getppid());
    
    uid = getuid();
    assert(pwd = getpwuid(uid));
    printf("Real User-ID: %ld - %s\n", (long)uid, pwd->pw_name);
   
    uid = geteuid();
    assert(pwd = getpwuid(uid));
    printf("Effective User-ID: %ld - %s\n", (long)uid, pwd->pw_name);

    gid = getgid();
    assert(grp = getgrgid(gid));
    printf("Real Group-ID: %ld - %s\n", (long)gid, grp->gr_name);

    printf("Effective Group-ID (effective-GID): %d\n", getegid());

   return(EXIT_SUCCESS);
}
