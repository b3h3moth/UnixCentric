#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LEN 255

int main() {
   char sistema[MAX_LEN];

   gethostname(sistema, MAX_LEN);
   printf("%s\n", sistema);

   return(EXIT_SUCCESS);
}
