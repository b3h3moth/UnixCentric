#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *unix_skills[] = { "C99 lang", "C11 lang", "C++11 lang", "Perl lang", 
                            "Awk lang", "Python lang", "Bash scripting",
                            "Zsh scripting", "System Administration", 
                            "Newtork Administration" };

    int size = (sizeof(unix_skills) / sizeof(unix_skills[0]));

    for (int i=0; i<size-1; i++)
        // Indica la la lunghezza del dato
        printf("%.*s\n", strlen(unix_skills[i]), unix_skills[i]);

    return(EXIT_SUCCESS);
}
