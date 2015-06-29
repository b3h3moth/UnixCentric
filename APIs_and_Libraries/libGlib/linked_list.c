#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <glib-2.0/glib.h>

#define MAX_BUF 25

/* Singly-Linked Lists
 * Linked lists that can be iterated in one direction */

/* Function prototypes */
void get_new_list_element(char new_elem[], int len);

GSList *list;

int main(int argc, char *argv[]) {
    char list_element_a[MAX_BUF];
    char list_element_b[MAX_BUF];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Add a new element on the end of the list */
    list = g_slist_append(list, argv[1]);

    get_new_list_element(list_element_a, MAX_BUF);
    /* Add a new element on the start of the list */
    list = g_slist_prepend(list, list_element_a);

    get_new_list_element(list_element_b, MAX_BUF);
    /* Add a new element into the list at the given position */
    list = g_slist_insert(list, list_element_b, 1);

    /* Print out every element of the list */
    while (list != NULL) {
        static int position = 1;
        printf("%d: %s\n", position, (char *)list->data);
        list = list->next;
        position++;
    }

    /* Free GList memory */
    g_slist_free(list);

    return(EXIT_SUCCESS);
}

void get_new_list_element(char new_elem[], int len) {
    int i = 0;

    printf("Please give new element for list: ");

    if ( (fgets(new_elem, MAX_BUF+1, stdin)) == NULL) {
        fprintf(stderr, "Err. getting string %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Check for newline and remove it from the string */
    for (i=0; i<strlen(new_elem); i++) {
        if (new_elem[i] == '\n')
            new_elem[i] = '\0';
    }
}
/* 
How to compile the program:
gcc -Wall linked_list.c $(pkg-config --cflags --libs glib-2.0)

pkg-config is essential to get the right informations about library
*/
