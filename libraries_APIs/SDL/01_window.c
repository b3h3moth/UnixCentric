#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

// Lo scopo del programma e' di creare una finestra di base

int main(int argc, char *argv[]) {
    const int scr_width = 320;
    const int scr_height = 400;
    // La finestra
    SDL_Window *window = NULL;
    
    // Inizializzazione della libreria SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Err. Cannot initialize SDL: %s\n", SDL_GetError());
    } else {
        /* Creazione della finestra con specifici parametri
        - titolo della finestra;
        - la posizione x della finestra;
        - la posizione y della finestra;
        - la lunghezza della finestra;
        - l'altezza della finestra;
        - flags a disposizione della finestra, in questo caso indica che la
          finestra sia visibile */
        window = SDL_CreateWindow("Take a Walk on The Wild Side", \
                0, 0, scr_width, scr_height, SDL_WINDOW_SHOWN);

        if (window == NULL)
            fprintf(stderr, "Err. Could not create window: %s\n", SDL_GetError());
    }

    // Close the library
    SDL_Quit();
    
    return(EXIT_SUCCESS);
}
