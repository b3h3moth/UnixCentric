#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE    20

size_t get_strlen(const char str[]);

int main(int argc, char *argv[]) {
    const char basket_team[STR_SIZE] = "Los Angeles Lakers";
    const char football_team[]       = "Juventus";
    const char *song                 = "No Woman No cry";

    size_t len_bteam = get_strlen(basket_team);
    size_t len_fteam = get_strlen(football_team);
    size_t len_song  = get_strlen(song);

    printf("%20s (%2d byte)\n", basket_team, len_bteam);
    printf("%20s (%2d byte)\n", football_team, len_fteam);
    printf("%20s (%2d byte)\n", song, len_song);

    return(EXIT_SUCCESS);
}

// Calcola la lunghezza della stringa 'str'
size_t get_strlen(const char str[]) {
    /*
    int str_size = 0;
    for (int i=0; i<strlen(str); i++) {
        if (str[i] == '\0')
            break;
        str_size++;
    }
    */

    size_t len;

    for (len=0; *str++ != '\0'; len++)
        ;

    return len;
}
