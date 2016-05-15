#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

static const char * const LOG_FILE = "./log.txt";
enum { MAX_BUF = 500 };

void write_date_to_log(void);

int main(void) {
    write_date_to_log();

    printf("log \'%s\' written\n", LOG_FILE);
    
    return(EXIT_SUCCESS);
}

void write_date_to_log(void) {
    char *username;
    time_t t;
    FILE *fp;
    char buf[MAX_BUF];
    char *time_string;

    username = getenv("USER");
    t = time(0);

    fp = fopen(LOG_FILE, "a+");

    if (fp == NULL) {
        fprintf(stderr, "Can't write log file: \'%s\'\n", LOG_FILE);
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    time_string = asctime(localtime(&t));
  
    sprintf(buf, "%-10s %s", username, time_string); 
    fwrite(buf, sizeof(char), strlen(buf), fp);
    
    fclose(fp);
}
