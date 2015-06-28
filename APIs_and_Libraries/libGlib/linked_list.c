#include <stdio.h>
#include <stdlib.h>
#include <glib-2.0/glib.h>

GList *list;

int main(int argc, char *argv[]) {
    list = g_list_append(list, "first");
    list = g_list_append(list, "second");
    list = g_list_append(list, "third");

    while (list != NULL) {
        printf("%s\n", (char *)list->data);
        list = list->next;
    }

    g_list_free(list);

    return(EXIT_SUCCESS);
}
