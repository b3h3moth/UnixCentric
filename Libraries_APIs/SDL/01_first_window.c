#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

int main(int argc, char *argv[]) {
    // Image
    SDL_Surface *image = NULL;
    SDL_Surface *screen = NULL;

    // Start SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    // Setup screen
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

    // Load image
    image = SDL_LoadBMP("hello.bmp");

    // Apply image to screen
    SDL_BlitSurface(image, NULL, screen, NULL);

    // Update screen
    SDL_Flip(screen);

    // Pause
    SDL_Delay(2000);

    // Free loaded image
    SDL_FreeSurface(image);

    // Quit SDL
    SDL_Quit();
    
    return(EXIT_SUCCESS);
}
