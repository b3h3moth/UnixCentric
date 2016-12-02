#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <assert.h>
#include <limits.h>

#define SGRP_SZ (NGROUPS_MAX + 1)

/* Lo scopo del programma e' di stampare le credenziali di un processo, nello
specifico, oltre al PID e PPID, i 'Real' e 'Effective' ID. */

int main(void) {
    uid_t uid;
    gid_t gid, sup_grps[SGRP_SZ];
    struct passwd *pwd;
    struct group *grp;
    int i, num_grps;
    
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

    gid = getegid();
    assert(grp = getgrgid(gid));
    printf("Effective Group-ID: %ld - %s\n", (long)gid, grp->gr_name);

    num_grps = getgroups(SGRP_SZ, sup_grps);
    if (num_grps == -1) {
        fprintf(stderr, "Err. getgroups() failed.\n");
        exit(EXIT_FAILURE);
    }

   return(EXIT_SUCCESS);
}
