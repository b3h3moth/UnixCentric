#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	DIR		*dp;
	struct dirent	*dirp;

	if ( (dp = opendir("/etc/init.d")) != NULL) {
	      while ((dirp = readdir(dp)) != NULL) {
	      	 printf("%s\n", dirp->d_name);
	      }
	}

	closedir(dp);

	exit(EXIT_SUCCESS);
}
