#include <stdio.h>
#include <stdlib.h>

int main(void) {
   printf("Compiled (%s) at (%s)\n", __DATE__, __TIME__);
   printf("Line (%d) file (%s)\n", __LINE__, __FILE__);
   printf("Standard C version: %ld\n", __STDC_VERSION__);

   return(EXIT_SUCCESS);
}
