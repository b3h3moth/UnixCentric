#ifndef CDECLAR_H
#define CDECLAR_H

#define MAX_TOKENS       100
#define MAX_TOKENS_SIZE  64

enum type_tag { IDENTIFIER, QUALIFIER, DATATYPE };

struct token {
    char type;
    char string[MAX_TOKENS_SIZE];
};

typedef struct token Token;

// Function Prototypes
enum type_tag check_string(void);
void get_token(void);
void read_first_id(void);
void deal_with_arrays(void);
void deal_with_functions(void);
void deal_with_pointers(void);
void deal_with_declarator(void);

#endif
