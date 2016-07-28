#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

/* Lo scopo del programma e' di inizializzare la libreria SDL */

int main(int argc, char *argv[]) {
    
    // Inizializzazione della libreria SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "Cannot initialize SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    puts("Success");

    // Close the library
    SDL_Quit();
    
    return(EXIT_SUCCESS);
}
