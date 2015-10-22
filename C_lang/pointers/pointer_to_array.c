#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *football_team[] = { "Juventus", "Manchester United", "Chelsea",
        "Manchester City", "Milan", "Real Madrid", "Barcellona" };

    char *ptr = football_team[0];
    char **ptr_to_ptr = &ptr;

    printf("       address of:\n");
    printf("              ptr: %p\n", ptr);
    printf(" football_team[0]: %p\n", (void *)football_team[0]);
    printf("       ptr_to_ptr: %p\n", (void *)*ptr_to_ptr);

    printf("      Indirection:\n");
    printf("              ptr: %s\n", ptr);
    printf("       ptr_to_ptr: %s\n", *ptr_to_ptr);

    return(EXIT_SUCCESS);
}
