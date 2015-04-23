#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

int main(int argc, char *argv[]) {
    // Start SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    
    // Quit SDL
    SDL_Quit();
    
    return(EXIT_SUCCESS);
}
