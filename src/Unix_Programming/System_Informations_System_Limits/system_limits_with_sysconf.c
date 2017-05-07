#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>

static void pr_sysconf(char *msg, int name);

/* Lo scopo del programma e' di fornire diverse informazioni circa le
"limitazioni" del sistema in uso. Da notare le costanti passate alle funzioni,
quelle che iniziano con _SC sono processate da sysconf(). */

int main(void) {

    pr_sysconf("ARG_MAX                   =", _SC_ARG_MAX);
    pr_sysconf("CHILD_MAX                 =", _SC_CHILD_MAX);
    pr_sysconf("clock ticks/second        =", _SC_CLK_TCK);

    pr_sysconf("NGROUPS_MAX               =", _SC_NGROUPS_MAX);
    pr_sysconf("OPEN_MAX                  =", _SC_OPEN_MAX);
    pr_sysconf("LOGIN_NAME_MAX            =", _SC_LOGIN_NAME_MAX);
#ifdef	_SC_STREAM_MAX
    pr_sysconf("STREAM_MAX                =", _SC_STREAM_MAX);
#endif
#ifdef	_SC_TZNAME_MAX
    pr_sysconf("TZNAME_MAX                =", _SC_TZNAME_MAX);
#endif
    pr_sysconf("_POSIX_JOB_CONTROL        =", _SC_JOB_CONTROL);
    pr_sysconf("_POSIX_SAVED_IDS          =", _SC_SAVED_IDS);
    pr_sysconf("_POSIX_VERSION            =", _SC_VERSION);

    exit(EXIT_SUCCESS);
}

static void pr_sysconf(char *msg, int name) {
    long val;
    fputs (msg, stdout);
    errno = 0;

    if ((val = sysconf (name)) < 0) {
    	if (errno != 0) {
	        perror("sysconf error");
	        exit(EXIT_FAILURE);
	    }

        fputs(" (not defined)\n", stdout);
    } else
    	printf(" %ld\n", val);
}
