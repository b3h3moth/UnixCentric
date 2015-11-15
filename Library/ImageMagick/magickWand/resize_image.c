#include <stdio.h>
#include <stdlib.h>
#include <ImageMagick-6/wand/MagickWand.h>

int main(void) {
    int width, height;
    MagickWand *mw; = NULL;

    MagickWandGenesis();
    mw = NewMagickWand();

    // Read the image
    MagickReadImage(mw, "image.jpg");
    
    return(EXIT_SUCCESS);
}
