#include <stdio.h>
#include <stdlib.h>
#include <ImageMagick-6/wand/MagickWand.h>

int main(void) {
    int width, height;
    MagickWand *mw = NULL;

    MagickWandGenesis();
    mw = NewMagickWand();

    // Read the image
    MagickReadImage(mw, "image.jpg");
   
    // Get original image width/height
    width = MagickGetImageWidth(mw);
    height = MagickGetImageWidth(mw);

    if ((width /= 2) < 1)
        width = 1;

    if ((height /= 2) < 1)
        height = 1;

    // Resize the image
    MagickResizeImage(mw, width, height, LanczosFilter, 1);

    // Set the compression quality
    MagickSetImageCompressionQuality(mw, 95);


    return(EXIT_SUCCESS);
}
