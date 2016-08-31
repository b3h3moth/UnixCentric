#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *pattern, char *replacement, char *original);

int main(void) {
    char string[] = "ANSI C language programming on win$ system";
    printf("%s\n", replace("win$", "unix", string));

    return(EXIT_SUCCESS);
}

char *replace(char *pattern, char *replacement, char *original) {
    char *p_temp = original;
    
    if(strlen(replacement) > strlen(pattern)) {
        fprintf(stderr, "Failed, strings are not equals\n");
        exit(EXIT_FAILURE);
    }
    
    while ((p_temp = strstr(p_temp, pattern))) {
    	memcpy(p_temp, replacement, strlen(replacement));
	memmove(p_temp + strlen(replacement), 
		p_temp + strlen(pattern), 
		strlen(p_temp+strlen(pattern))+1);
    }

    return original;
}
