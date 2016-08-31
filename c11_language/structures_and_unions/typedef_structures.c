#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF 20

// Nuovo tipo di dato 'Book'
typedef struct {
    char title[MAX_BUF];            // 20 byte +
    char sub_title[MAX_BUF];        // 20 byte +
    char author_name[MAX_BUF];      // 20 byte +
    char author_surname[MAX_BUF];   // 20 byte +
    unsigned short year;            //  4 byte +
    unsigned int ID;                //  4 byte +
} Book;                             //  2 byte per l'allineamento corretto)
                                    // tot. 88 byte
// Alias al tipo di dato
typedef Book book;

int main(void) {
    // Istruzioni equivalenti
    Book scifi;
    book horror;

    printf("sizeof Book = %d byte\n", sizeof(scifi));
    printf("sizeof book = %d byte\n", sizeof(horror));

    return(EXIT_SUCCESS);
}
