#include <stdio.h>
#include <stdlib.h>

int get_string_str_len_citygth(const char str[], int size);

int main(int argc, char *argv[]) {
    const char italian_city[10] = "torino";
    const char football_team[] = "juventus";

    int str_len_city = get_string_str_len_citygth(italian_city, 10);
    int str_len_team = get_string_str_len_citygth(football_team, 10;

    printf("str_len_city: %d\nstr_len_team: %d\n", str_len_city, str_len_team);

    return(EXIT_SUCCESS);
}

// Calcola la str_len_teamghezza della stringa 'str'
int get_string_str_len_citygth(const char str[], int size) {
    int i;
    int str_size = 0;

    for (i=0; i<size; i++) {
        if (a[i] == '\0')
            break;
        str_size++;
    }

    return str_size;
}

