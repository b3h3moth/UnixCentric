#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_HASH      10
#define MULTIPLIER  31

typedef struct AddressBook AddressBook;

struct AddressBook {
    char        *email;
    char        *alias;
    AddressBook *next;
};

AddressBook *abook[N_HASH];

// Prototipi
unsigned int hash(char *str);
AddressBook *new_item(char *email, char *alias);
AddressBook *lookup(char *email, char *alias, int create);
void get_item(AddressBook *p, char *email);


int main(void) {
    AddressBook *my_abook;

    my_abook = lookup("baz@baz.org", "baz", 1);
    
    my_abook = new_item("foo@foo.com", "foo");

    my_abook = new_item("bar@bar.com", "bar");
    get_item(my_abook, "foo@foo.com");
    get_item(my_abook, "baz@baz.org");


    return(EXIT_SUCCESS);
}


// Funzione hash
unsigned int hash(char *str) {
    unsigned int h = 0;
    unsigned char *p;

    for (p = (unsigned char *) str; *p != '\0'; p++)
        h = MULTIPLIER * h + *p;

    return h % N_HASH;
}

AddressBook *new_item(char *email, char *alias) {
    AddressBook *temp;
    int h = hash(email);

    temp = malloc(sizeof(AddressBook));
    temp->email = email;
    temp->alias = alias;
    temp->next = abook[h];
    abook[h] = temp;

    return temp;
}

/* La funzione lookup() ricerca nella tabella hash un elemento:
- se lo trovera' lo restituira':
- se non lo trovera' e il flag 'create' sara' attivato, lo aggiungera' alla 
  tabella */
AddressBook *lookup(char *email, char *alias, int create) {
    int index;
    AddressBook *ab;

    index = hash(email);

#ifdef DEBUG
    printf("hash() value: %d\n", h);
#endif
    
    for (ab = abook[index]; ab != NULL; ab = ab->next)
        if (strcmp(email, ab->email) == 0)
            return ab;

    if (create) {
        ab = (AddressBook *) malloc(sizeof(AddressBook));
        ab->email = email;
        ab->alias = alias;
        ab->next = abook[index];
        abook[index] = ab;
    }

    return ab;
}

// Stampa l'elemnto richiesto (email; nickname) dell'hash table AddressBook
void get_item(AddressBook *p, char *email) {
    int index = hash(email);
    
    for (p = abook[index]; p != NULL; p = p->next)
        if (strcmp(p->email, email) == 0)
            printf("%s <%s>\n", p->alias, p->email);
}
