#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>
#include <ImageMagick-6/wand/MagickWand.h>

int main(int argc, char *argv[]) {
    int width, height;
    MagickWand *mw = NULL;

    MagickWandGenesis();
    mw = NewMagickWand();

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Apprend the "rsz-" prefix to each resized image
    char *default_image = basename(argv[1]);
    char *resized_image = malloc(strlen(argv[1]) + 4);
    strcpy(resized_image, "rsz-");
    strcat(resized_image, default_image);

    // Read the image
    MagickReadImage(mw, argv[1]);
   
    // Get original image width/height
    width = MagickGetImageWidth(mw);
    height = MagickGetImageWidth(mw);

    // Check underflow if the dimensions of the image is too much small
    if ((width /= 2) < 1)
        width = 1;

    if ((height /= 2) < 1)
        height = 1;

    // Resize the image
    MagickResizeImage(mw, width, height, LanczosFilter, 1);

    // Set the compression quality
    MagickSetImageCompressionQuality(mw, 95);

    // Write the new image
    MagickWriteImage(mw, resized_image);

    // Clean up
    if (mw)
       mw = DestroyMagickWand(mw);

    MagickWandTerminus();

    return(EXIT_SUCCESS);
}
