#include <stdio.h>
#include <stdlib.h>

char *get_day(int);
void help(char *str);

int main(int argc, char *argv[]) {
    int nday;
    char *day_of_week = NULL;

    help("Please, type");
    scanf("%1d", &nday);

    if (nday < 1 || nday > 7) {
        help("Error, it was");
        exit(EXIT_FAILURE);
    }

    day_of_week = get_day(nday);

    printf("%s\n", day_of_week);

    return(EXIT_SUCCESS);
}

char *get_day(int d) {
    char *days[7] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    if (d >= 1 && d <= 7)
        return days[d-1];
}

void help(char *str) {
    printf("%s a number from 1 and 7\n", str);
}
