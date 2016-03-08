#include <stdio.h>
#include <stdlib.h>

struct db {
    int id;
    char gender;
};

struct db init(struct db val);
void print_data(struct db val);

int main(void) {
    struct db data = init((struct db){1, 'm'});
    print_data(data);

    return(EXIT_SUCCESS);
}

struct db init(struct db val) {
    struct db temp = val;
    return temp;
}

void print_data(struct db val) {
    printf(" id: %d\ngender: %c", val.id, val.gender);
}
