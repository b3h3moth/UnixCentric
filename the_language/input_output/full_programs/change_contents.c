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

int main(void) {
    return(EXIT_SUCCESS);
}

Record *get_record(Record *rec) {
