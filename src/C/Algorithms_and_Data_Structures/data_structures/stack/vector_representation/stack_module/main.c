#include "stack.h"

// Testing the stack implementation by reversing a string

int main(void) {
    char    str[] = "Take a walk on the wild side";
    int     i;

    // New stack
    stack   s;
    
    // Initialize the stack
    reset(&s);
    
    printf("Default string: %s\n", str);
    
    for (i = 0; str[i] != '\0'; ++i)
        if (!full(&s))
            // push a char on the stack
            push(str[i], &s);
   
    printf("From the stack: ");
   
    while (!empty(&s))
      // pop a char off the stack
      putchar(pop(&s));
   
    putchar('\n');
   
    return(EXIT_SUCCESS);
}
