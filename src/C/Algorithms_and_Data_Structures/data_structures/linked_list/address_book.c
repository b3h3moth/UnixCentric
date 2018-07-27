#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct AddressBook AddressBook;

struct AddressBook {
    char *mail;
    char *alias;
    uint32_t id;
    AddressBook *next;
};

// Prototipi
AddressBook *new_item(char *mail, char *alias, uint32_t id);
AddressBook *add_front(AddressBook *list_p, AddressBook *new_node);
AddressBook *add_end(AddressBook *list_p, AddressBook *new_node);
void apply(AddressBook *list_p, void (*func)(AddressBook*, void*), void *arg);
// Prototipi a supporto della funzione apply()
void print_values(AddressBook *list_p, void *arg);
void count_elements(AddressBook *list_p, void *arg);

int main(void) {
    AddressBook *myabook;

    myabook = new_item("bar@foo.com", "foo", 1);

    /* Con la chiamata alla funzione add_front(), il nuovo elemento andra'
    in testa alla lista */
    myabook = add_front(myabook, new_item("foo@bar.com", "bar", 2));

    /* Con la chiamata alla funzione add_end(), il nuovo elemento andra'
    in coda alla lista */
    myabook = add_end(myabook, new_item("baz@bar.com", "baz", 3));

    // Stampa ciascun elemento della rubrica
    apply(myabook, print_values, "%d: <%s> \'%s\'\n");

    // Quanti elementi contiene la rubrica
    int n = 0;
    apply(myabook, count_elements, &n);
    printf("AddressBook has \'%d\' elements\n", n);

    return(EXIT_SUCCESS);
}

// Inizializza un nuovo nodo della lista
AddressBook *new_item(char *mail, char *alias, uint32_t id) {
    AddressBook *temp;

    temp = malloc(sizeof(AddressBook));
    temp->mail = mail;
    temp->alias = alias;
    temp->id = id;
    temp->next = NULL;

    return temp;
}

// Aggiunge un nuovo nodo in testa alla lista
AddressBook *add_front(AddressBook *list_p, AddressBook *new_node) {
    new_node->next = list_p;
    return new_node;
}

// Aggiunge un nuovo nodo in coda alla lista
AddressBook *add_end(AddressBook *list_p, AddressBook *new_node) {
    AddressBook *temp;

    // Nel caso in cui la lista contenesse solo un nodo
    if (list_p == NULL)
        return list_p;

    // Si scorre dall'inizio alla fine
    for (temp = list_p; temp->next != NULL; temp = temp->next)
        ;

    temp->next = new_node;

    return list_p;
}

/* apply() utilizza un'altra funzione come parametro, mediante la quale
possono essere eseguite diverse operazioni sulla lista */
void apply(AddressBook *list_p, void (*func)(AddressBook*, void*), void *arg) {
    for (; list_p != NULL; list_p = list_p->next)
        (*func)(list_p, arg); // La funzione viene invocata
}

// Funzione chamata da apply; stampa ciascun elemento della lista
void print_values(AddressBook *list_p, void *arg) {
    char *fmt;
    fmt = (char *)arg;
    printf(fmt, list_p->id, list_p->mail, list_p->alias);
}

// Funzione chamata da apply; restituisce il numero degli elementi (nodi)
void count_elements(AddressBook *list_p, void *arg) {
    int *elem;
    elem = (int *) arg;
    (*elem)++;
}

