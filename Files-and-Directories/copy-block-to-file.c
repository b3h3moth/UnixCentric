#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUF 1024

int main()
{
    char block[MAX_BUF]; 
    int in, out; 
    int nread;

    in = open("/etc/passwd", O_RDONLY); 
    out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    
	while((nread = read(in,block,sizeof(block))) > 0)
        write(out,block,nread);

    exit(EXIT_SUCCESS);
}

