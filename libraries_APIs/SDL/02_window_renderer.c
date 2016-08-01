#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

enum { SCR_WIDTH = 640, SCR_HEIGHT = 480};

/* Lo scopo del programma e' di creare un finestra con il relativo redendering,
in modo tale che possa essere visualizzata sullo schermo. */

int main(int argc, char *argv[]) {
    SDL_Window   *window = NULL;
    SDL_Renderer *renderer = NULL;
    
    // Inizializzazione della libreria SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "Err. Cannot initialize SDL: %s\n", SDL_GetError());
        return(1);
    } else {
        window = SDL_CreateWindow("Take a Walk on The Wild Side",   \
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,     \
                scr_width, scr_height, SDL_WINDOW_SHOWN);

        if (window == NULL) {
            fprintf(stderr, "Err. Could not create window: %s\n", SDL_GetError());
            return 1;
        } else 
            renderer = SDL_CreateRenderer(window, -1, 0);
    }
        
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    // Pausa di 5000 millisecondi (5 secondi)
    SDL_Delay(5000);

    // Distrugge il rendering
    SDL_DestroyRenderer(renderer);

    // Distrugge la finestra
    SDL_DestroyWindow(window);

    // Chiusura della libreria
    SDL_Quit();
    
    return(EXIT_SUCCESS);
}
