#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <glib-2.0/glib.h>

#define MAX_BUF 25

GList *list;

void get_new_list_element(char new_elem[], int len);

int main(int argc, char *argv[]) {
    char new_element[MAX_BUF];
    char new_elem[MAX_BUF];
    int i=0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char test[MAX_BUF];
    get_new_list_element(test, MAX_BUF);

    /* Add a new element on the end of the list */
    list = g_list_append(list, argv[1]);

    /* Add a new element on the start of the list */
    list = g_list_prepend(list, new_element);

    /* Add a new element into the list at the given position */
    list = g_list_insert(list, test, 1);

    /* Print out every element of the list */
    while (list != NULL) {
        static int position = 1;
        printf("%s\n", (char *)list->data);
        list = list->next;
        position++;
    }

    /* Free GList memory */
    g_list_free(list);

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
