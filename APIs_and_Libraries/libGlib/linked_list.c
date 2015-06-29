#include <stdio.h>
#include <stdlib.h>
#include <glib-2.0/glib.h>

GList *list;

int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    /* Add an element to list */
    list = g_list_append(list, argv[1]);

    list = g_list_append(list, "second");
    list = g_list_append(list, "third");

    while (list != NULL) {
        printf("%s\n", (char *)list->data);
        list = list->next;
    }

    g_list_free(list);

    return(EXIT_SUCCESS);
}
