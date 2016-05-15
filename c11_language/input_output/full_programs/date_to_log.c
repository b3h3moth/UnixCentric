#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define LOG_FILE "./log.txt"

void write_date_to_log(void);

int main(void) {
    write_date_to_log();
    
    return(EXIT_SUCCESS);
}

void write_date_to_log(void) {
    char *username;
    time_t t;
    FILE *fp;
    char s[1000];
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
  
    sprintf(s, "%-10s %s", username, time_string); 
    fwrite(s, sizeof(char), strlen(s), fp);
    
    fclose(fp);
}
