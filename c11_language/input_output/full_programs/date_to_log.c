#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>


#define LOG_FILE "./log_file"

void write_date_to_log(void);

int main(void) {
    write_date_to_log();
    
    return(EXIT_SUCCESS);
}

void write_date_to_log(void) {
    char *username;
    time_t t;
    int fd;
    char s[1000];
    char *time_string;

    username = getenv("USER");
    t = time(0);

    fd = open(LOG_FILE, O_APPEND | O_SYNC | O_CREAT | O_WRONLY, 0666);

    if (fd < 0) {
        fprintf(stderr, "Can't write log file %s\n", LOG_FILE);
    }

    time_string = asctime(localtime(&t));
  
    sprintf(s, "%-10s %s", username, time_string); 
    write(fd, s, strlen(s));
    
    close(fd);
}
