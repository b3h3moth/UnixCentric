#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>

int main(void)
{
	struct passwd *pd;
	uid_t uid = getuid();
	
	if ( (pd = getpwuid(uid)) < 0) 
		exit(EXIT_FAILURE);
	else {
		printf("The user name: %s\n", pd->pw_name);
		printf("The user ID: %u\n", pd->pw_uid);
		printf("The Group ID: %u\n", pd->pw_gid);
		printf("The initial directory: %s\n", pd->pw_dir);
		printf("The initial user program: %s\n", pd->pw_shell);
	}
	
	return(EXIT_SUCCESS);
}
