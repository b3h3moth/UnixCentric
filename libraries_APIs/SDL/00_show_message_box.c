#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

// Lo scopo del programma e' di visualizzare un semplice 'message box'

int main(void) {
    // Inizializzazione della libreria SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "Cannot initialize SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "SDL", "Windows", NULL);

    return(EXIT_SUCCESS);
}
