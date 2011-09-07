#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main(void)
{
	struct statvfs hdd;
	unsigned long long ul_bfree;

	if (statvfs("/home/luca", &hdd) < 0)
		exit(EXIT_FAILURE);
	else
	{
		printf("       File System block size 'f_bsize': %10llu\n", (unsigned long long)hdd.f_bsize);
		printf("               Fragment size 'f_frsize': %10llu\n", (unsigned long long)hdd.f_frsize);
		printf("                  Size of FS 'f_blocks': %10llu\n", (unsigned long long)hdd.f_blocks);
		printf("                  Free blocks 'f_bfree': %10llu\n", (unsigned long long)hdd.f_bfree);
		printf("  Free blocks unprivil. users 'f_bvail': %10llu\n", (unsigned long long)hdd.f_bavail);
		printf("                       Inodes 'f_files': %10llu\n", (unsigned long long)hdd.f_files);
		printf("                  Free Inodes 'f_ffree': %10llu\n", (unsigned long long)hdd.f_ffree);
		printf(" Free inodes unprivil. users 'f_favail': %10llu\n", (unsigned long long)hdd.f_favail);
		printf("                File system ID 'f_fsid': %10llu\n", (unsigned long long)hdd.f_fsid);
		printf("                   Mount flags 'f_flag': %10llu\n", (unsigned long long)hdd.f_flag);
		printf("    Maximume filename flags 'f_namemax': %10llu\n", (unsigned long long)hdd.f_namemax);
	}

	
	return(EXIT_SUCCESS);
}
