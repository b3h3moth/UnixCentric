#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#define MB (1024 * 1024)
int main(void)
{
	struct statvfs hdd;
	double disk_size, disk_free, disk_used;

	if (statvfs("/", &hdd) != -1) {
		disk_size = (double)(hdd.f_bsize * hdd.f_blocks)/MB;
		disk_free = (double)(hdd.f_bsize * hdd.f_bfree)/MB;
		disk_used = (double)(disk_size - disk_free);
		
		printf("Disk size: %.5g MB\n", disk_size);
		printf("Disk free: %.5g MB\n", disk_free);
		printf("Disk used: %.5g MB\n", disk_used);
	}
	
	return(EXIT_SUCCESS);
}
