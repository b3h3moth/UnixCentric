#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXLEN  256

typedef struct {
    uint32_t id;
    char name[MAXLEN];
    char email[MAXLEN];
} Record;

static const char *filename = "data.bin";

// Function Prototypes
Record *get_record(Record *rec);
void get_name(char *name, size_t size);

int main(void) {
    return(EXIT_SUCCESS);
}

Record *get_record(Record *rec) {
    fputs("Enter name (%d max characters): ", MAXLEN);

}

void get_name(char *name, size_t size) {
    fflush(stdout);
    fgets(name, size);
    size_t len = strlen(name);

    if (name[len-1] == '\n')
        name[len-1] = '\0';
}
