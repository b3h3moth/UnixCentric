#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_strfunc.h"

int main(void) {
    char *src = "Take a walk on the wild side";
    char *dest = malloc(sizeof(src)+1);
    char skill_list[] = "C, C+,+ AWK, Perl, Networking, SysAdministration, ";
    char update_skill[] = "Network Security, Secure Coding.";
    
    my_strncpy(dest, src,  strlen(src)+1);
    my_strncat(skill_list, update_skill,  strlen(update_skill)+1);
    
    printf(" src: %s\n", src);
    printf("dest: %s\n", dest);

    printf("%s\n", skill_list);

    return(EXIT_SUCCESS);
}
