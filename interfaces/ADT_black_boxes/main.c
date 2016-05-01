#include <stdio.h>
#include <stdlib.h>
#include "addresslist.h"

char name[MAX_ADDR][NAME_LEN] = {
    "luca",
    "maria",
    "giovanna",
    "carla",
    "francesa"
};
char address[MAX_ADDR][ADDR_LEN] = {
    "1111111111",
    "2222222222",
    "3333333333",
    "4444444444",
    "5555555555",
};

char mail[MAX_ADDR][MAIL_LEN] = {
    "luca@mail.org",
    "maria#mail.org",
    "giovanna@mail.org",
    "carla@mail.org",
    "francesa@mail.org"
};

int main(void) {
    return(EXIT_SUCCESS);
}
