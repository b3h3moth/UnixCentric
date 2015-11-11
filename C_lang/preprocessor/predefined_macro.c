#include <stdio.h>
#include <stdlib.h>

int main(void) {
   printf("Compiled (%s) at (%s)\n", __DATE__, __TIME__);
   printf("Line (%d) file (%s)\n", __LINE__, __FILE__);
   printf("Standard C version: %ld\n", __STDC_VERSION__);

   /* Queste macro sono probabilmente le piu' conosciute, ma ce ne sono tante
   altre aggiunte  sia nello standard c99 sia nello standard c11 */
  
   return(EXIT_SUCCESS);
}
