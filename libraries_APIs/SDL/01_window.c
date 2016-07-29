#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

// Lo scopo del programma e' di creare una finestra di base

int main(int argc, char *argv[]) {
    const int scr_width = 320;
    const int scr_height = 400;
    // La finestra
    SDL_Window *window = NULL;
    SDL_Surface *surface = NULL;
    
    // Inizializzazione della libreria SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Cannot initialize SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    // Close the library
    SDL_Quit();
    
    return(EXIT_SUCCESS);
}
