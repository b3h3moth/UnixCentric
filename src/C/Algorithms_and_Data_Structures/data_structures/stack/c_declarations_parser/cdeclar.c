#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cdeclar.h"

// Testa dello stack
static int top = -1;

Token stack[MAX_TOKENS];
Token this;

// Verifica il tipo di identificatore
enum type_tag check_string(void) {
    char *str = this.string;

    if(!strcmp(str, "const")) {
        strcpy(str, "read-only");
        return QUALIFIER;
    }

    if (!strcmp(str, "volatile")) return QUALIFIER;
    if (!strcmp(str, "void")) return DATATYPE;
    if (!strcmp(str, "char")) return DATATYPE;
    if (!strcmp(str, "signed")) return DATATYPE;
    if (!strcmp(str, "unsigned")) return DATATYPE;
    if (!strcmp(str, "short")) return DATATYPE;
    if (!strcmp(str, "int")) return DATATYPE;
    if (!strcmp(str, "long")) return DATATYPE;
    if (!strcmp(str, "float")) return DATATYPE;
    if (!strcmp(str, "double")) return DATATYPE;
    if (!strcmp(str, "struct")) return DATATYPE;
    if (!strcmp(str, "union")) return DATATYPE;
    if (!strcmp(str, "enum")) return DATATYPE;

    return IDENTIFIER;
}

// Legge il token successivo all'interno di this
void get_token(void) {
    char *ptr = this.string;

    // Legge oltre gli spazi
    while ((*ptr = getchar()) == ' ') 
        ;

    if (isalnum(*ptr)) {
        // Legge i caratteri alfanumerici nell'identificatore
        while (isalnum(*++ptr = getchar()))
            ;
        ungetc(*ptr, stdin);
        *ptr = '\0';
        this.type = check_string();
    }

    if (*ptr == '*') {
        strcpy(this.string, "pointer to ");
        this.type = '*';
    }

    this.string[1] = '\0';
    this.type = *ptr;
}

// Prende il primo token e inizia a processarlo
void read_first_id(void) {
    get_token();

    while(this.type != IDENTIFIER) {
        // push
        stack[++top] = this;
        get_token();
    }

    printf("%s is ", this.string);
    get_token();
}

// Verifica se il token in esame e' un array
void deal_with_arrays(void) {
    while (this.type == '[') {
        printf("array ");
        
        // Verifica la chiusura dell'operatore subscript ']' oppure un numero
        get_token();

        if (isdigit(this.string[0])) {
            printf("0..%d ", atoi(this.string)-1);
            // Legge la parentesi quadra di chiusura ']'
            get_token();
        }

        // Legge il carattere successivo alla eventuale parentesi quadra ']'
        get_token();
        printf("of ");
    }
}

// Verifica se il token in esame e' un funzione
void deal_with_functions(void) {
    while (this.type != ')') {
        get_token();
    }

    get_token();

    printf("Function returning ");
}

// Verifica se il token in esame e' un puntatore
void deal_with_pointers(void) {
    while (stack[top].type == '*') {
        printf("%s ", stack[top--].string);
    }
}

// Verifica se il token in esame e' una dichiarazione
void deal_with_declarator(void) {

    switch (this.type) {
        case '[': 
            deal_with_arrays();
            break;
        case '(': 
            deal_with_functions();
    }

    deal_with_pointers();

    while (top >= 0) {
        if (stack[top].type == '(') {
            //pop;
            stack[top--];
            get_token();
            deal_with_declarator();
        } else {
            printf("%s ", stack[top--].string);
        }
    }
}
