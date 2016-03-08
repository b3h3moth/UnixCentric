#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 20

struct db {
    int id;
    char gender;
    char name[MAX_LEN];
};

struct db init(struct db val);
void print_data(struct db val);

int main(void) {
    struct db data = init((struct db){0,'m', "behemoth"});
    print_data(data);

    return(EXIT_SUCCESS);
}

struct db init(struct db val) {
    struct db temp = val;
    temp.id = 1;

    return temp;
}

void print_data(struct db val) {
    printf(" id: %d\ngender: %c\tname: %s", val.id, val.gender, val.name);
}
