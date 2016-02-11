#include <stdio.h>
#include <stdlib.h>
#include "readline.h"
#include "hardware_components.h"

int main(void) {
    char code;

    for (;;) {
        printf("[i]nsert [u]pdate [s]earch] [p]rint [q]uit: ");
        scanf(" %c", &code);

        /* Salta a fine riga, consentendo una interazione col menu'
        pulita e ben formattata */
        while (fgetc(stdin) != '\n')
            ;

        switch (code) {
            case 'i': 
                insert(); 
                break;
            case 'u': 
                update(); 
                break;
            case 's': 
                search(); 
                break;
            case 'p': 
                print(); 
                break;
            case 'q': 
                return(EXIT_SUCCESS);
            default: 
                printf("\nLegal codes are [i] [u] [s] [p] [q]\n");
        }
    }

    return(EXIT_SUCCESS);
}
