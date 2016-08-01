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
        return (1);
    } else {
        window = SDL_CreateWindow("Window Renderer",   \
                SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,     \
                SCR_WIDTH, SCR_HEIGHT, SDL_WINDOW_SHOWN);

        if (window == NULL) {
            fprintf(stderr, "Err. Could not create window: %s\n", SDL_GetError());
            return (1);
        } else {
            /* Ora e' necessario il renderer 2D della finestra, altrimenti non
            si vedrebbe alcunche'. Il puntatore a SDL_Window 'window' lo si 
            passa alla funzione per la creazione del renderering della finestra.
            I parametri della funzione sono:
            - Il puntatore a SDL_Window dove sara' attuato il rendering;
            - rendering driver o -1 per inizializzare il primo disponibile;
            - 0 o uno o piu' rendering flags. */
            renderer = SDL_CreateRenderer(window, -1, 0);
        }
    }

    /* Impostazione del colore per disegnare la finestra, ovvero il grigio.
    I parametro della funzione sono:
    - il puntatore a SDL_Renderer;
    - red value di RGBA;
    - green value di RGBA;
    - blue value di RGBA;
    - alpha value di RGBA. */
    SDL_SetRenderDrawColor(renderer, 127, 127, 127, 0);

    /* Cancella il target di rendering corrente dello schermo con il colore 
    selezionato precedentemente, altrimenti si vedrebbe una finestra nera. */
    SDL_RenderClear(renderer);

    // Visualizza la finestra di colore grigio, settato in precedenza.
    SDL_RenderPresent(renderer);

    // Pausa di 5000 millisecondi (5 secondi)
    SDL_Delay(5000);

    // Chiusura e pulizia della libreria
    SDL_Quit();
    
    return(EXIT_SUCCESS);
}
