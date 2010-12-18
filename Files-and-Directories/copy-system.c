#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char c; 
    int in, out;

    in = open("/etc/passwd", O_RDONLY); 
    out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    while(read(in,&c,1) == 1)
        write(out,&c,1);

    exit(EXIT_SUCCESS);
}

