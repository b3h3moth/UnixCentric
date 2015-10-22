#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE    20

int get_strlen(const char str[], int size);

int main(int argc, char *argv[]) {
    const char basket_team[STR_SIZE] = "Los Angeles Lakers";
    const char football_team[]       = "Juventus";

    int len_bteam = get_strlen(basket_team, STR_SIZE);
    int len_fteam = get_strlen(football_team, STR_SIZE);

    printf("%20s (%2d byte)\n", basket_team, len_bteam);
    printf("%20s (%2d byte)\n", football_team, len_fteam);

    return(EXIT_SUCCESS);
}

// Calcola la str_len_teamghezza della stringa 'str'
int get_strlen(const char str[], int size) {
    int str_size = 0;

    for (int i=0; i<size; i++) {
        if (str[i] == '\0')
            break;
        str_size++;
    }

    return str_size;
}
